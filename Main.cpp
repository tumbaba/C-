// �޸� ����
// 1. ����
// 2. ������
// 3. ��
// 4. ROM(�ڵ�)

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


	// ���ڿ� �̾� ���̱�
	wcscat_s();

	return 0;
}