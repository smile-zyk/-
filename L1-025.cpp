#include<iostream>
#include<cctype>
#include<sstream>
#include<string>
using namespace std;

int check_num(string n)
{
	int size = n.size();
	if ( size> 4)return 0;
	else
	{
		if (size == 4)
		{
			if (n == "1000")return 1000;
			else return 0;
		}
		else {
			for (auto i : n)if (!isdigit(i))return 0;
			return atoi(n.c_str());
		}
	}
}

int main()
{
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	string a, b;
	cin >> a;
	getchar();
	getline(cin, b);
	int ra=check_num(a), rb=check_num(b);
	if (ra && rb)
	{
		printf("%d + %d = %d", ra, rb, ra + rb);
	}
	else
	{
		printf("%s + %s = ?", ra ? a.c_str() : "?", rb ? b.c_str() : "?");
	}
}