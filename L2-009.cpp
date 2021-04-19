#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

struct peo
{
	int id;
	float money;
	int num = 0;
};
peo p[10005];

int cmp(peo a, peo b)
{
	if (a.money != b.money)
		return a.money > b.money;
	else
		return a.num > b.num;
}

int main()
{
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		p[i].id = i;
		int k;
		cin >> k;
		while (k--)
		{
			int m;
			float in;
			scanf("%d %f", &m, &in);
			p[i].money -= in;
			p[m].money += in;
			p[m].num++;
		}
	}
	sort(p+1, p + n+1, cmp);
	for (int i = 1; i <= n; i++)
	{
		printf("%d %.2f\n", p[i].id, p[i].money / 100);
	}
}