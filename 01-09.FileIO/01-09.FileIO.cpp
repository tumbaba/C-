// 01-09.FileIO.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <fstream>
#include <string>
#include <format>
#include <vector>
#include "ThirdParty/IniParser/inicpp.h"
#include <rapidjson/document.h>
#include <rapidjson/writer.h>
#include <rapidjson/stringbuffer.h>

int main()
{
	// 1. 기본 C++ File Input Output
	// 2. ini파일 IO
	// 3. json파일 IO

	// 절대 경로: 특정 드라이브를 기준으로 (C:\...) 시작하는 경로 (D:\Dir\Test.txt)
	// 상대 경로: 특정 기준 폴더로 부터 시작하는 경로 ("Dir\Test.txt", "Dir/Test.txt")
	
	// 1. 기본 C++ File IO(Input Output)
	{
		/*
		* 텍스트 모드
		* - 기본적으로 파일을 텍스트 모드로 열면, 운영 체제에 따라 줄바꿈 문자가 추가된다.
		* - 예를 들면, Windows에서는 엔터(\n)를 텍스트 파일에 치면 \r\n 으로 변환됩니다.
		* - 텍스트 모드에서는 파일의 끝을 나타내는 문자가 있을 때 읽기가 중단될 수 있습니다.
		* 
		* 바이너리 모드
		* - 데이터가 변환 없이 그대로 읽고 써집니다.
		* - 줄바꿈 문자나 파일의 끝을 나타내는 문자가 변환되지 않습니다.
		* - 사용 예시) 이미지, 음악파일 등 처리
		* 
		*/

		// File Write (Text)
		// output file stream: ofstream
		{
			std::ofstream OutputStream = std::ofstream("Test.txt", std::ios::out);
			if (OutputStream.is_open())
			{
				std::string String = "Hello File! Hello~~~\n";
				const size_t WriteSize = String.size();
				OutputStream.write((const char*)&WriteSize, sizeof(size_t));
				OutputStream.write(String.c_str(), String.size());

				int Int = 65;
				OutputStream.write(reinterpret_cast<char*>(&Int), sizeof(int));
				OutputStream.close(); // 파일 닫기
			}
		}
		// File Read (Text)
		{
			std::ifstream InputStream = std::ifstream("Test.txt", std::ios::in);
			if (InputStream.is_open())
			{
				size_t ReadSize = 0;
				InputStream.read(reinterpret_cast<char*>(&ReadSize), sizeof(size_t));
				std::string String;
				String.resize(ReadSize);
				InputStream.read(String.data(), String.size());
				//InputStream >> String;

				int Int = 0;
				InputStream.read(reinterpret_cast<char*>(&Int), sizeof(int));

				InputStream.close();
			}
		}

		// File Write (Binary)
		{
			std::ofstream OutputStream = std::ofstream("TestBinary.txt", std::ios::out | std::ios::binary);
			if (OutputStream.is_open())
			{
				std::string String = "Hello File! Hello~~~\n";
				const size_t WriteSize = String.size();
				OutputStream.write((const char*)&WriteSize, sizeof(size_t));
				OutputStream.write(String.c_str(), String.size());

				int Int = 65;
				OutputStream.write(reinterpret_cast<char*>(&Int), sizeof(int));
				OutputStream.close(); // 파일 닫기
			}
		}
		// File Read (Binary)
		{
			std::ifstream InputStream = std::ifstream("TestBinary.txt", std::ios::in | std::ios::binary);
			if (InputStream.is_open())
			{
				size_t ReadSize = 0;
				InputStream.read(reinterpret_cast<char*>(&ReadSize), sizeof(size_t));
				std::string String;
				String.resize(ReadSize);
				InputStream.read(String.data(), String.size());
				//InputStream >> String;

				int Int = 0;
				InputStream.read(reinterpret_cast<char*>(&Int), sizeof(int));

				InputStream.close();
			}
		}
	}

	// 2. ini 파일 IO
	{
		{
			ini::IniFile File;
			File["A Section"]["FieldKey1"] = 0;
			File["A Section"]["FieldKey2"] = 1;
			File["A Section"]["FieldKey3"] = 2;
			File["B Section2"]["FieldKey1"] = 3;
			File["B Section2"]["FieldKey2"] = 4;
			File["B Section2"]["FieldKey3"] = 5;

			File["C Graphics"]["Width"] = 1920;
			File["C Graphics"]["Height"] = 1080;
			File["C Graphics"]["Test"] = "Hello";

			File.save("IniFile.ini");
		}
		{
			ini::IniFile File("IniFile.ini");
			ini::IniField& Field = File["C Graphics"]["Test"];
			std::string String = Field.as<std::string>();
			std::string String2 = File["C Graphics"]["Test"].as<std::string>();

			int IntVar2 = File["A Section"]["FieldKey2"].as<int>();

			std::vector<int> Result;
			for (int i = 0; i < 3; ++i)
			{
				const std::string KeyName = "FieldKey" + std::to_string(i + 1);
				int Value = File["A Section"][KeyName].as<int>();
				Result.push_back(Value);
			}
			int Width = File["C Graphics"]["Width"].as<int>();
			int Height = File["C Graphics"]["Height"].as<int>();

			ini::IniSection Section = File["B Section2"];
			for (auto It : Section)
			{
				std::cout << std::format("Key: {}, Value: {}\n", It.first, It.second.as<std::string>());
			}
		}
	}
	
	// 3. json 파일 IO
	{
		// https://rapidjson.org/

		struct FPlayer
		{
			FPlayer() = default;
			FPlayer(const FPlayer&) = default;
			FPlayer(std::string_view InName, const int InLevel, const int InExp) noexcept
				: Name(InName), Level(InLevel), Exp(InExp) {}
			~FPlayer() = default;

			void Save(rapidjson::Value& InOutValue, rapidjson::Document::AllocatorType& InAllocator)
			{
				// 다국어 처리를 하고 싶으면 UTF-8로 변환이 필요할 수 있다.
				/*std::wstring_convert<std::codecvt_utf8<wchar_t>> myconv;
				std::string UTF8 = myconv.to_bytes(Name);*/

				if (Name.empty())
				{
					_ASSERT(false);
				}

				rapidjson::Value PlayerNameString(rapidjson::kStringType);
				PlayerNameString.SetString(Name.c_str(), InAllocator);

				InOutValue.AddMember("PlayerName", PlayerNameString, InAllocator);
				InOutValue.AddMember("Level", Level, InAllocator);
				InOutValue.AddMember("Exp", Exp, InAllocator);
			}

			void Load(const rapidjson::Value& InValue)
			{
				if (InValue.HasMember("PlayerName"))
				{
					const char* String = InValue["PlayerName"].GetString();
					Name = String;
				}
				else
				{
					_ASSERT(false);
					Name = "DefaultName";
				}

				if (InValue.HasMember("Level"))
				{
					Level = InValue["Level"].GetInt();
				}
				if (InValue.HasMember("Exp"))
				{
					Exp = InValue["Exp"].GetInt();
				}
			}

		private:
			std::string Name;
			int Level = 0;
			int Exp = 0;
		};

		using uint = unsigned int;
		constexpr uint PlayerNumbers = 20;

		// Save
		{
			std::vector<FPlayer> Players;
			Players.reserve(PlayerNumbers);

			for (uint i = 0; i < PlayerNumbers; ++i)
			{
				std::string Name = "Player" + std::to_string(i);
				Players.emplace_back(Name, i, i + 100);
			}

			rapidjson::Document Doc(rapidjson::kObjectType);

			rapidjson::Value Array(rapidjson::kArrayType);
			for (FPlayer& It : Players)
			{
				rapidjson::Value PlayerValue(rapidjson::kObjectType);
				It.Save(PlayerValue, Doc.GetAllocator());

				Array.PushBack(PlayerValue, Doc.GetAllocator());
			}

			Doc.AddMember("PlayerInfo", Array, Doc.GetAllocator());

			rapidjson::StringBuffer Buffer;
			rapidjson::Writer<rapidjson::StringBuffer> Writer(Buffer);
			Doc.Accept(Writer);
			std::string Json(Buffer.GetString(), Buffer.GetSize());

			std::ofstream File("TestJson.json");
			File << Json;
		}

		// Load
		{
			std::vector<FPlayer> Players;

			std::ifstream File("TestJson.json");
			std::string Json;
			std::string TempLine;
			while (std::getline(File, TempLine))
			{
				Json += TempLine;
			}
			//File >> Json;

			rapidjson::Document Doc(rapidjson::kObjectType);
			Doc.Parse(Json.data());

			bool bPlayerInfo = Doc.HasMember("PlayerInfo");
			_ASSERT(bPlayerInfo);
			if (bPlayerInfo)
			{
				rapidjson::Value& Array = Doc["PlayerInfo"];
				_ASSERT(Array.IsArray());
				if (Array.IsArray())
				{
					const rapidjson::SizeType Size = Array.Size();
					for (rapidjson::SizeType i = 0; i < Size; ++i)
					{
						FPlayer NewPlayer;
						rapidjson::Value& Value = Array[i];
						NewPlayer.Load(Value);

						Players.emplace_back(NewPlayer);
					}
				}
			}
		}
	}
}