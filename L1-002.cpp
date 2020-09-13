#include<iostream>
#include<cmath>
using namespace std;
int main()
{
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	int num;
	char c;
	scanf("%d %c", &num, &c);
	int i = 0;
	while (2 * pow(i, 2) - 1 < num)
		i++;
	if (2 * pow(i, 2) - 1 != num)i--;
	int tmp = i;
	while (i)
	{
		int n = 2 * i - 1;
		int m = tmp - i;
		while (m--)printf(" ");
		while (n--)printf("%c", c);
		printf("\n");
		i--;
	}
	i += 2;
	while (i != tmp + 1)
	{
		int m = tmp - i;
		int n = 2 * i - 1;
		while (m--)printf(" ");
		while (n--)printf("%c", c);
		printf("\n");
		i++;
	}
	//printf("%d", num - (2 * pow(tmp, 2) - 1));
	//上面这种写法不能得出真确的答案，注意这里输出时使用了pow函数，该函数返回的是一个double型的浮点数，会导致该表达式的值转换为double，而printf的格式符为%d，识别为32位的int，于是只读前32位。‘
	//使用printf时，要注意格式符和表达式的值一定要对应！
	printf("%d", num - (2 * tmp * tmp - 1));
}