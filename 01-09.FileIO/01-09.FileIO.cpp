// 01-09.FileIO.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <fstream>
#include <string>
#include <format>
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

	}
}