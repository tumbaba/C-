#include <iostream>
#include <vector>
using namespace std;


int N;
vector<char> tree[26];
bool check[26][4];



void front(char root)
{
	
	cout << root;
	
	if (!check[root - 65][1])
	{
		front(tree[root - 65][1]);
	}
	if (!check[root - 65][2])
	{
		front(tree[root - 65][2]);
	}
	
	//front(tree[root - 65][2]);
}



void mid(char root)
{



	if (!check[root - 65][1])
	{
		mid(tree[root - 65][1]);
	}
	/*if (!check[root - 65][1])
	{
		cout << tree[root - 65][1];
	}*/
	cout << root;
	if (!check[root - 65][2])
	{
		mid(tree[root - 65][2]);
	}
	/*if (!check[root - 65][2])
	{
	//	cout << tree[root - 65][2];
	//}*/
	
	
}

void perv(char root)
{
	if (!check[root - 65][1])
	{
		perv(tree[root - 65][1]);
	}
	/*if (!check[root - 65][1])
	{
		cout << tree[root - 65][1];
	}*/
	if (!check[root - 65][2])
	{
		perv(tree[root - 65][2]);
	}
	cout << root;
	
	/*if (!check[root - 65][2])
	{
		cout << tree[root - 65][2];
	}*/
}




int main()
{
	cin >> N;

	for (int i = 0; i < N; i++)
	{
		char a, b, c;
		cin >> a >> b >> c;
		tree[a - 65].push_back(a);
		tree[a - 65].push_back(b);
		if (b == '.')
		{
			check[a - 65][1] = true;
		}
		tree[a - 65].push_back(c);
		if (c == '.')
		{
			check[a - 65][2] = true;
		}
	}
	
	front('A');
	cout << endl;
	mid('A');
	cout << endl;
	perv('A');





	return 0;
}