#include<iostream>
using namespace std;
int main()
{
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	int a = 0, b = 0;
	scanf("%d %d", &a, &b);
	int sum = 0;
	for (int i = 0; i < b - a + 1; i++)
	{
		if ( i != 0&&i % 5 == 0)
		{
			printf("\n");
		}
		sum += (a + i);
		printf("%5d", a + i);
	}
	printf("\nSum = %d", sum);
}