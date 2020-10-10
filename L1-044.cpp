#include<iostream>
#include<string>
#include<map>
using namespace std;
map<string, string> m = { {"JianDao","ChuiZi"},{"ChuiZi","Bu"},{"Bu","JianDao"} };
int main()
{
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	int n;
	cin >> n;
	string s;
	int i = 0;
	while (cin >> s)
	{
		i++;
		if (s == "End")
			break;
		else
		{
			if (i % (n + 1) == 0)
				cout << s << "\n";
			else
				cout << m[s] << "\n";
		}
	}
}