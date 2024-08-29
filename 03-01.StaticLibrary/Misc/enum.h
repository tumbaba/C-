#pragma once
#include <iostream>

enum EErrorCode : uint8_t
{
	ESuccessed,
	EUnknown,
	EEmptyAccount,
	EDuplicateAccount,
	ECanNotFoundAccount,
	EAccountNotValid,

	ENoLogin,
	EDuplicatePlayerName,
	EPlayerNotValid, // 해당 플레이어 정보가 없다
};