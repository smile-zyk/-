#include<iostream>
using namespace std;
int main()
{
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	int h, m;
	scanf("%d:%d", &h, &m);
	if (h < 12 || (h == 12 && m == 0))
	{
		printf("Only %02d:%02d.  Too early to Dang.",h,m);
	}
	else
	{
		int num;
		if (m == 0)num = h - 12;
		else num = h - 11;
		while (num--)
		{
			printf("Dang");
		}
	}
}