#include<iostream>
#include<string>
using namespace std;
int main()
{
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	string s;
	int maxlen = 0;
	getline(cin, s);
	auto b = s.begin();
	auto e = s.begin();
	for (; b < s.end(); b++)
	{
		e = b;
		for (; e < s.end(); e++)
		{
			int len = 0;
			auto nb = b;
			auto ne = e;
			while ( nb <= ne && *nb == *ne)
			{
				if (nb == ne)
				{
					nb++;
					len++;
				}
				else
				{
					len += 2;
					nb++;
					ne--;
				}
			}
			if (nb > ne && len > maxlen)
			{
				maxlen = len;
			}
		}
	}
	cout << maxlen;
}