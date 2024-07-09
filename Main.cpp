// 메모리 영역
// 1. 스택
// 2. 데이터
// 3. 힙
// 4. ROM(코드)

unsigned int GetLength(const wchar_t* _pStr)
{

	int i = 0;
	while (0 != _pStr[i])
	{
		
		++i;
	}
	return i;
}

int main()
{
	wchar_t szName[10] = L"Raimond";

	//int iLen - wcslen(szName);
	int iLen = GetLength(szName);


	// 문자열 이어 붙이기
	wcscat_s();

	return 0;
}