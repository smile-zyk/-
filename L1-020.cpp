#include<iostream>
#include<string>
#include<set>
#include<algorithm>
using namespace std;
int main()
{
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	set<string> data;//直接使用一个set读取，否则会超时！
	int num;
	scanf("%d", &num);
	while (num--)
	{
		int n;
		scanf("%d", &n);
		if (n > 1)
		{
			while (n--)
			{
				string s;
				cin >> s;
				data.insert(s);
			}
		}
		else//虽然要忽略n==1的情况但是，读取还是需要的
		{
			string s;
			cin >> s;
		}
	}
	int m;
	scanf("%d", &m);
	set<string> check;
	int print_flag = 1;
	int no_handsome_flag = 1;
	while (m--)
	{
		string s;
		cin >> s;
		if (data.find(s) == data.end()&&check.find(s)==check.end())
		{
			check.insert(s);
			no_handsome_flag = 0;
			if (print_flag)
			{
				print_flag = 0;
				cout << s;
			}
			else
				cout << " " << s;
		}
	}
	if (no_handsome_flag) printf("No one is handsome");
}
