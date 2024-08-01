#include <iostream>
#include <vector>
#include <stack>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);


	/*string A;
	cin >> A;
	vector<char> Arr;
	for (size_t i = 0; i < A.size(); i++)
	{
		Arr.push_back(A[i]);
	}
	for (int i = 0; i < Arr.size(); ++i)
	{
		if (i + 1 < Arr.size())
		{
			if (Arr[i] == '(' && Arr[i + 1] == ')')
			{
				auto it =Arr[i] = 'x';
				Arr.erase(Arr.begin() + i+1);
			}
		}
		
	}
	
	
	int result = 0;
	while (true)
	{
		for (int i = 0; i < Arr.size(); i++)
		{
			if (Arr[i] == '(' && (Arr[i + 1] == 'x' || Arr[i+1] == 'y'))
			{
				int j = i+1;
				int count = 0;
				for (j ; j < Arr.size(); j++)
				{
					
					if (Arr[j] == '(')
					{
						break;
					}
					else if (Arr[j] == 'x')
					{
						count++;
					}
					else if (Arr[j] == ')')
					{
						result += (count + 1);
						Arr[j] = 'y';
						Arr[i] = 'y';
						break;
					}
					
				}
			}
		}
		int hi = 0;
		for (int i = 0; i < Arr.size(); i++)
		{
			if (Arr[i] == '(')
			{
				hi++;
				break;
			}
		}
		if (hi == 0)
		{
			break;
		}
	}
	cout << result;*/
	string s;
	int ans = 0;

	
	cin >> s;
	stack<char> st;
	for (int i = 0; i < s.length(); i++) {
		if (s[i] == '(') st.push(s[i]);
		else { //')'
			if (s[i - 1] == '(') { //레이저인 경우
				st.pop();
				ans += st.size();
			}
			else { //막대의 끝인 경우
				st.pop();
				ans++;
			}
		}
	}
	cout << ans;

	return 0;
}