#include<iostream>
#include<cmath>
using namespace std;
int main()
{
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	int a = 0;
	char c;
	scanf("%d %c", &a, &c);
	for (int i = 0; i < round(a / 2); i++)//注意:这里的a/2需要转换为浮点型,否则会自动转换为整数,对整数再取round是得不到正确答案的。
	{
		for (int j = 0; j < a; j++)
			printf("%c", c);
		printf("\n");
	}
}