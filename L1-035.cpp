#include<iostream>
#include<vector>
#include<string>
using namespace std;
vector<string> v;
int main()
{
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	string s;
	while (1)
	{
		cin >> s;
		if (s == ".") break;
		v.push_back(s);
	}
	if (v.size() >= 14)
	{
		cout << v[1] << " and " << v[13] << " are inviting you to dinner...";
	}
	else
	{
		if (v.size() >= 2)
		{
			cout << v[1] << " is the only one for you...";
		}
		else
		{
			cout << "Momo... No one is for you ...";
		}
	}
}