#include<iostream>
using namespace std;
int main()
{
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	string s = "I Love GPLT";
	for (auto &i : s)
	{
		cout << i << endl;
	}
}