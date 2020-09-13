#include<iostream>
#include<string>
using namespace std;
int main()
{
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	string data;
	int result[10] = { 0 };
	getline(cin, data);
	for (auto c : data)
		result[c - '0']++;
	int i = 0;
	for (auto n : result)
	{
		if (n != 0)
			printf("%d:%d\n",i,n);
		i++;
	}
}