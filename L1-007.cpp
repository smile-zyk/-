#include<iostream>
#include<string>
using namespace std;
int main()
{
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	const char* str[] = { "ling","yi","er","san","si","wu","liu","qi","ba","jiu" };
	int data;
	scanf("%d", &data);
	string result = to_string(data);
	int flag = 1;
	for (auto c : result)
	{
		if (c == '-')
		{
			printf("fu");
			flag = 0;
		}
		else
		{
			if (flag)
			{
				printf("%s", str[c - '0']);
				flag = 0;
			}
			else
				printf(" %s", str[c - '0']);
		}
	}
}