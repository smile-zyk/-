#include<iostream>
using namespace std;
int main()
{
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	int m, n;
	scanf("%d %d", &m, &n);
	int num;
	scanf("%d", &num);
	int temp_m = m, temp_n = n;
	while (num--)
	{
		int a, b, c, d;
		scanf("%d %d %d %d", &a, &b, &c, &d);
		if (!(b == a + c && d == a + c))
		{
			if (b == a + c)m--;
			if (d == a + c)n--;
		}
		if (m < 0 || n < 0)break;
	}
	if (m < 0)
	{
		printf("A\n%d",temp_n-n);
	}
	else
	{
		printf("B\n%d", temp_m - m);
	}
}
//#include<iostream>
//using namespace std;
//int na;
//int nb;
//int main()
//{
//	freopen("in.txt", "r", stdin);
//	freopen("out.txt", "w", stdout);
//	int a, b;
//	cin >> a >> b;
//	int N;
//	cin >> N;
//	int flag = 1;
//	while (N--) {
//		int ah, ae, bh, be;
//		cin >> ah >> ae >> bh >> be;
//		if (ae == (ah + bh) && be != (ah + bh))
//		{
//			if (++na > a)
//			{
//				flag = 0;
//				break;
//			}
//		}
//		else if (be == (ah + bh) && ae != (ah + bh))
//		{
//			if (++nb > b)break;
//		}
//	}
//	if (flag) printf("B\n%d", na);
//	else printf("A\n%d", nb);
//}