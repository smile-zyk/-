#include<iostream>
#include<string>
#include<set>
using namespace std;
int main()
{
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	set<int,greater<int>> m;
	int hash[10] = { 0 };
	string num;
	cin >> num;
	for (auto i : num)
		m.insert(i - '0');
	int r = 0;
	printf("int[] arr = new int[]{");
	for (auto i : m)
	{
		if (r != 0)cout << ",";
		cout << i;
		hash[i] = r;
		r++;
	}
	printf("};\n");
	printf("int[] index = new int[]{");
	for (int i = 0; i < num.size(); i++)
	{
		if (i != 0)cout << ",";
		cout << hash[num[i] - '0'];
	}
	printf("};");
}