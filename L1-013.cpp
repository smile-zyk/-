#include<iostream>
using namespace std;

int fac(int x)
{
	int result = 1;
	for (int i = 2; i <= x; i++)
	{
		result *= i;
	}
	return result;
}

int main()
{
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	int a=0,result=0;
	scanf("%d", &a);
	for(int i=1;i<=a;i++)
	{
		result += fac(i);
	}
	printf("%d", result);
}