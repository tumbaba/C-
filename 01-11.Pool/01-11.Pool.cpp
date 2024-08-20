// 01-11.Pool.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//
#include "Pool.h"

int main()
{
	// new
	{
		FClass* ClassInstance = new FClass;
		delete ClassInstance;
	}

	// malloc: 메모리 공간만 할당
	{
		FClass* Memory = (FClass*)malloc(sizeof(FClass));

		// placement new: 이미 할당된 메모리 블록에
		// 객체(인스턴스)를 만들어준다(생성자 호출)
		new(Memory)FClass();
		Memory->~FClass();

		free(Memory);
	}

	// 메모리풀: 큰 사이즈의 메모리 블록을 할당하고
	// 요청할때 마다 미리 할당해둔 블록의 일부를 전달한다
	// 요청이 만료되면 다시 풀에 환원된다.

	// 메모리 할당이란: 커널에 요청하는 명령(system call)중 하나이다
	// (OS가 최정화를 해놔서 매번 커널에 요청하는 것은 아닐 수 있다)
	// 왜 커널에 요청하는가? 메모리는 공유 자산(내 프로그램만 쓰는 것이 아니다)
	// 이러한 공유자원을 사용하는 요청은 동기화 처리가 되어야 할 것이다.
	// (동기화란, 여러 프로그램이 동시에 요청할때 순서대로 하나씩 처리되어 함)

	// 위와 같은 상황의 경우 최대한 커널 영역에 있는 시간을 줄여야 (OS입장에서)
	// 프로그램이 더 빠르게 동작한다고 할 수 있겠습니다.
	// 메모리 할당 및 해제를 빈번하게 하는 경우 메모리 풀을 만들어서 사용하면
	// 커널에 있는 시간을 많이 줄일 수 있다.

	// 메모리 풀을 사용했을 때 장점
	// - 속도가 빠르다(구현을 못하면 더 느리다; 어중간하게 구현하면 new delete하는 것 만 못하다)
	//		-> 결국 성능을 측정해야 한다
	//		- 미리 적은 횟수의 시스템 콜로 메모리 블록을 크게 할당하고 그것을 유저영역에서 사용하기 때문에 빠르다
	//		- (메모리 단편화 문제 해결) 큰 블록을 할당해두고 이를 유저가 쪼개서 사용하기 때문에 캐시 미스가 적다
	// 고정 사이즈 메모리 풀
	//		- 예산(메모리)을 정해서 그 예산 안에서 사용하게 제한을 할 수 있다
	//			- 예를 들면 메모리풀 크기를 10으로 고정해두고 이를 사용하면 최대 동시에 10개까지만 만들수 있다.


	// new, delete 성능 측정
	{
		int** Arr = new int*[MaxCount];
		std::chrono::steady_clock::time_point Start{ std::chrono::steady_clock::now() };

		{
			for (size_t i = 0; i < MaxCount; ++i)
			{
				int* Test = new int(i);
				Arr[i] = Test;
			}

			for (size_t i = 0; i < MaxCount; ++i)
			{
				delete Arr[i];
			}
		}
		auto End{ std::chrono::steady_clock::now() };
		auto Diff{ End - Start };

		delete[] Arr;
		// 1sec == 1000ms
		// 1ms == 1000ns
		double DiffCount = std::chrono::duration<double, std::milli>(Diff).count();
#if _DEBUG
		std::cout << std::format("Debug: ");
#else
		std::cout << std::format("Release: ");
#endif
		std::cout << std::format("[int] new, delete: {}ms\n", DiffCount);
	}
	// malloc, free 성능 측정
	{
		FClass** Arr = new FClass * [MaxCount];
		std::chrono::steady_clock::time_point Start{ std::chrono::steady_clock::now() };

		{
			for (size_t i = 0; i < MaxCount; ++i)
			{
				FClass* Test = (FClass*)malloc(sizeof(FClass));
				Arr[i] = Test;
			}

			for (size_t i = 0; i < MaxCount; ++i)
			{
				free(Arr[i]);
			}
		}
		auto End{ std::chrono::steady_clock::now() };
		auto Diff{ End - Start };

		delete[] Arr;
		// 1sec == 1000ms
		// 1ms == 1000ns
		double DiffCount = std::chrono::duration<double, std::milli>(Diff).count();
#if _DEBUG
		std::cout << std::format("Debug: ");
#else
		std::cout << std::format("Release: ");
#endif
		std::cout << std::format("[FClass] malloc, free: {}ms\n", DiffCount);
	}
	// 직접 구현한 고정 사이즈 Memory Pool
	{
		int** Arr = new int* [MaxCount];
		FMemoryPool MemoryPool = FMemoryPool(sizeof(int), MaxCount);
		std::chrono::steady_clock::time_point Start{ std::chrono::steady_clock::now() };

		{
			for (size_t i = 0; i < MaxCount; ++i)
			{
				int* Test = (int*)MemoryPool.malloc();
				Arr[i] = Test;
			}

			for (size_t i = 0; i < MaxCount; ++i)
			{
				MemoryPool.free(Arr[i]);
			}
		}
		auto End{ std::chrono::steady_clock::now() };
		auto Diff{ End - Start };

		delete[] Arr;
		// 1sec == 1000ms
		// 1ms == 1000ns
		double DiffCount = std::chrono::duration<double, std::milli>(Diff).count();
#if _DEBUG
		std::cout << std::format("Debug: ");
#else
		std::cout << std::format("Release: ");
#endif
		std::cout << std::format("[int] Custom MemoryPool: {}ms\n", DiffCount);
	}
	// 직접 구현한 고정 사이즈 Memory Pool
	{
		FClass** Arr = new FClass * [MaxCount];
		FMemoryPool MemoryPool = FMemoryPool(sizeof(FClass), MaxCount);
		
		std::chrono::steady_clock::time_point Start{ std::chrono::steady_clock::now() };
		{
			for (size_t i = 0; i < MaxCount; ++i)
			{
				FClass* Test = (FClass*)MemoryPool.malloc();
				Arr[i] = Test;
			}

			for (size_t i = 0; i < MaxCount; ++i)
			{
				MemoryPool.free(Arr[i]);
			}
		}
		auto End{ std::chrono::steady_clock::now() };
		auto Diff{ End - Start };

		delete[] Arr;
		// 1sec == 1000ms
		// 1ms == 1000ns
		double DiffCount = std::chrono::duration<double, std::milli>(Diff).count();
#if _DEBUG
		std::cout << std::format("Debug: ");
#else
		std::cout << std::format("Release: ");
#endif
		std::cout << std::format("[FClass] Custom MemoryPool: {}ms\n", DiffCount);
	}

	{
		FClass** Arr = new FClass * [MaxCount];

		boost::pool<> MemoryPool(sizeof(FClass), MaxCount);
		int* TryAlloc = (int*)MemoryPool.malloc();
		MemoryPool.free(TryAlloc);

		std::chrono::steady_clock::time_point Start{ std::chrono::steady_clock::now() };
		{
			for (size_t i = 0; i < MaxCount; ++i)
			{
				FClass* Test = (FClass*)MemoryPool.malloc();
				Arr[i] = Test;
			}

			for (size_t i = 0; i < MaxCount; ++i)
			{
				MemoryPool.free(Arr[i]);
			}
		}
		auto End{ std::chrono::steady_clock::now() };
		auto Diff{ End - Start };

		delete[] Arr;
		// 1sec == 1000ms
		// 1ms == 1000ns
		double DiffCount = std::chrono::duration<double, std::milli>(Diff).count();
#if _DEBUG
		std::cout << std::format("Debug: ");
#else
		std::cout << std::format("Release: ");
#endif
		std::cout << std::format("[FClass] boost MemoryPool: {}ms\n", DiffCount);
	}

	// 오브젝트 풀: 메모리풀은 순수하게 메모리 블럭만 할당,
	//				오브젝트풀은 placement new를 사용해서 object를 만들어주는 기능이 추가됨
	{
		// new, delete 성능 측정
		{
			FClass** Arr = new FClass * [MaxCount];
			std::chrono::steady_clock::time_point Start{ std::chrono::steady_clock::now() };

			{
				for (size_t i = 0; i < MaxCount; ++i)
				{
					FClass* Test = new FClass();
					Arr[i] = Test;
				}

				for (size_t i = 0; i < MaxCount; ++i)
				{
					delete Arr[i];
				}
			}
			auto End{ std::chrono::steady_clock::now() };
			auto Diff{ End - Start };

			delete[] Arr;
			// 1sec == 1000ms
			// 1ms == 1000ns
			double DiffCount = std::chrono::duration<double, std::milli>(Diff).count();
#if _DEBUG
			std::cout << std::format("Debug: ");
#else
			std::cout << std::format("Release: ");
#endif
			std::cout << std::format("[FClass] new, delete: {}ms\n", DiffCount);
		}
		{
			FClass** Arr = new FClass * [MaxCount];
			boost::object_pool<FClass> Objectpool{ MaxCount };
			Objectpool.free(Objectpool.malloc());

			std::chrono::steady_clock::time_point Start{ std::chrono::steady_clock::now() };

			{
				for (size_t i = 0; i < MaxCount; ++i)
				{
					FClass* Test = (FClass*)Objectpool.construct();
					Arr[i] = Test;
					Objectpool.destroy(Arr[i]);
				}

				// 엄청 느린 이슈 때문에 수정
				/*for (size_t i = 0; i < MaxCount; ++i)
				{
					Objectpool.destroy(Arr[i]);
				}*/
			}
			auto End{ std::chrono::steady_clock::now() };
			auto Diff{ End - Start };

			delete[] Arr;
			double DiffCount = std::chrono::duration<double, std::milli>(Diff).count();
#if _DEBUG
			std::cout << std::format("Debug: ");
#else
			std::cout << std::format("Release: ");
#endif
			std::cout << std::format("[FClass] boost ObjectPool: {}ms\n", DiffCount);
		}
		{
			FClass** Arr = new FClass * [MaxCount];
			boost::object_pool_custom<FClass> Objectpool{ MaxCount };
			Objectpool.free(Objectpool.malloc());

			std::chrono::steady_clock::time_point Start{ std::chrono::steady_clock::now() };

			{
				for (size_t i = 0; i < MaxCount; ++i)
				{
					FClass* Test = (FClass*)Objectpool.construct(i);
					Arr[i] = Test;
				}

				for (size_t i = 0; i < MaxCount; ++i)
				{
					Objectpool.destroy(Arr[i]);
				}
			}
			auto End{ std::chrono::steady_clock::now() };
			auto Diff{ End - Start };

			delete[] Arr;
			double DiffCount = std::chrono::duration<double, std::milli>(Diff).count();
#if _DEBUG
			std::cout << std::format("Debug: ");
#else
			std::cout << std::format("Release: ");
#endif
			std::cout << std::format("[FClass] boost ObjectPool custom: {}ms\n", DiffCount);
		}
		{
			FClass** Arr = new FClass * [MaxCount];
			FObjectPool<FClass> Objectpool{ MaxCount };
			Objectpool.free(Objectpool.malloc());

			std::chrono::steady_clock::time_point Start{ std::chrono::steady_clock::now() };

			{
				for (size_t i = 0; i < MaxCount; ++i)
				{
					FClass* Test = (FClass*)Objectpool.construct(i);
					Arr[i] = Test;
				}

				for (size_t i = 0; i < MaxCount; ++i)
				{
					Objectpool.destroy(Arr[i]);
				}
			}
			auto End{ std::chrono::steady_clock::now() };
			auto Diff{ End - Start };

			delete[] Arr;
			double DiffCount = std::chrono::duration<double, std::milli>(Diff).count();
#if _DEBUG
			std::cout << std::format("Debug: ");
#else
			std::cout << std::format("Release: ");
#endif
			std::cout << std::format("[FClass] My custom ObjectPool: {}ms\n", DiffCount);
		}

		{
			FObjectPool<FClass> Objectpool{ MaxCount };
			Objectpool.free(Objectpool.malloc());
			std::vector<std::shared_ptr<FClass>> Vector;
			Vector.reserve(MaxCount);

			std::chrono::steady_clock::time_point Start{ std::chrono::steady_clock::now() };

			{
				for (size_t i = 0; i < MaxCount; ++i)
				{
					std::shared_ptr<FClass> Instance = Objectpool.construct_shared(i);
					Vector.push_back(Instance);
				}
			}

			Vector.clear();

			auto End{ std::chrono::steady_clock::now() };
			auto Diff{ End - Start };
			double DiffCount = std::chrono::duration<double, std::milli>(Diff).count();
#if _DEBUG
			std::cout << std::format("Debug: ");
#else
			std::cout << std::format("Release: ");
#endif
			std::cout << std::format("[FClass] My custom ObjectPool shared_ptr: {}ms\n", DiffCount);
		}

		{
			boost::object_pool_custom<FClass> Objectpool{ MaxCount };
			Objectpool.free(Objectpool.malloc());
			std::vector<std::shared_ptr<FClass>> Vector;
			Vector.reserve(MaxCount);

			std::chrono::steady_clock::time_point Start{ std::chrono::steady_clock::now() };

			{
				for (size_t i = 0; i < MaxCount; ++i)
				{
					std::shared_ptr<FClass> Instance = Objectpool.construct_shared(i);
					Vector.push_back(Instance);
				}
			}

			Vector.clear();

			auto End{ std::chrono::steady_clock::now() };
			auto Diff{ End - Start };

			double DiffCount = std::chrono::duration<double, std::milli>(Diff).count();
#if _DEBUG
			std::cout << std::format("Debug: ");
#else
			std::cout << std::format("Release: ");
#endif
			std::cout << std::format("[FClass] boost ObjectPool custom shared_ptr: {}ms\n", DiffCount);
		}

		{
			std::vector<std::shared_ptr<FClass>> Vector;
			Vector.reserve(MaxCount);
			auto Start{ std::chrono::steady_clock::now() };
			{
				for (size_t i = 0; i < MaxCount; ++i)
				{
					std::shared_ptr<FClass> Instance = std::make_shared<FClass>(i);
					Vector.push_back(Instance);
				}
			}

			Vector.clear();

			auto End{ std::chrono::steady_clock::now() };
			auto Diff{ End - Start };
			double DiffCount = std::chrono::duration<double, std::milli>(Diff).count();
#if _DEBUG
			std::cout << std::format("Debug: ");
#else
			std::cout << std::format("Release: ");
#endif
			std::cout << std::format("[FClass] shared_ptr: {}ms\n", DiffCount);
		}
		{
			FAllocator<FClass> Allocator;
			std::shared_ptr<FClass> Init = std::allocate_shared<FClass>(Allocator);
			Init = nullptr;
			std::vector<std::shared_ptr<FClass>> Vector;
			Vector.reserve(MaxCount);
			auto Start{ std::chrono::steady_clock::now() };
			{
				//std::allocator<FClass> Allocator;
				for (size_t i = 0; i < MaxCount; ++i)
				{
					std::shared_ptr<FClass> Instance = std::allocate_shared<FClass>(Allocator);
					Vector.push_back(Instance);
				}
			}

			Vector.clear();

			auto End{ std::chrono::steady_clock::now() };
			auto Diff{ End - Start };
			double DiffCount = std::chrono::duration<double, std::milli>(Diff).count();
#if _DEBUG
			std::cout << std::format("Debug: ");
#else
			std::cout << std::format("Release: ");
#endif
			std::cout << std::format("[FClass] custom allocator shared_ptr: {}ms\n", DiffCount);
		}
	}

	// Memory Header
	{
		//  r(MemoryHeader)		 r(16byte), FClass3*
		//  [                    |                            ]
		FMemoryPool MemoryPool{ sizeof(FMemoryHeader) + sizeof(FClass3), MaxCount };
		void* Pointer = MemoryPool.malloc();
		FMemoryHeader* MemoryHeader = static_cast<FMemoryHeader*>(Pointer);
		new(MemoryHeader) FMemoryHeader();
		MemoryHeader->Pool = &MemoryPool;
		MemoryHeader->Flag2 = 1234;

		FClass3* Class = reinterpret_cast<FClass3*>(MemoryHeader + 1);
		new(Class)FClass3();

		FMemoryHeader* MemoryHeaderPos = reinterpret_cast<FMemoryHeader*>(Class) - 1;
		//MemoryHeaderPos->Pool->free(Class);
		MemoryHeaderPos->Pool->free2((void**)& Class);
	}
	// Unreal 스타일
	{
		FObjectInitializer ObjectInitializer;
		ObjectInitializer.Flag = 1234;
		ObjectInitializer.Flag2 = 123;
		FObject* Object = FObject::NewObject<FObject>(ObjectInitializer);
		ObjectInitializer.Flag = 333;
		Object->Delete();
		FObject* Object2 = FObject::NewObject<FObject>(ObjectInitializer);
		Object2->Delete();
		AActor* Actor = FObject::NewObject<AActor>(ObjectInitializer);
	}
}