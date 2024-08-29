#include "Player.h"

void FPlayer::Save(rapidjson::Value& OutValue, rapidjson::Document::AllocatorType& InAllocator)
{
	OutValue.AddMember("AccountName", rapidjson::StringRef(AccountName.c_str()), InAllocator);
	OutValue.AddMember("Name", rapidjson::StringRef(Name.c_str()), InAllocator);

	OutValue.AddMember("Level", Level, InAllocator);
}

bool FPlayer::Load(const rapidjson::Value& InValue)
{
	const bool bAccountName = InValue.HasMember("AccountName");
	const bool bName = InValue.HasMember("Name");
	if (!bAccountName || !bName)
	{
		return false;
	}
	
	{
		const char* String = InValue["AccountName"].GetString();
		AccountName = String;
	}
	{
		const char* String = InValue["Name"].GetString();
		Name = String;
	}
	const bool bLevel = InValue.HasMember("Level");
	if (bLevel)
	{
		Level = InValue["Level"].GetInt();
	}
	else
	{
		_ASSERT(false);
		Level = 0;
	}

	return true;
}
