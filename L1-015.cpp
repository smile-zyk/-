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
	for (int i = 0; i < round(a / 2); i++)//ע��:�����a/2��Ҫת��Ϊ������,������Զ�ת��Ϊ����,��������ȡround�ǵò�����ȷ�𰸵ġ�
	{
		for (int j = 0; j < a; j++)
			printf("%c", c);
		printf("\n");
	}
}