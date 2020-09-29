#include<iostream>
#include<string>
using namespace std;
int main()
{
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	string a, b;
	getline(cin, a);
	getline(cin, b);
	int flag = 1;
	for (auto c : a)
	{
		flag = 1;
		for (auto d : b)
		{
			if (c == d)
			{
				flag = 0;
				break;
			}
		}
		if (flag)
			cout << c;
	}
}