#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
struct mooncake
{
	double num;
	double oneprice;
	mooncake():num(0),oneprice(0){}
};

bool cmp(mooncake a, mooncake b)
{
	return a.oneprice > b.oneprice;
}

int main()
{
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	int N, M;
	cin >> N;
	cin >> M;
	int tmp = N;
	double res = 0;
	vector<mooncake> m;
	while (N--)
	{
		mooncake n;
		cin >> n.num;
		m.push_back(n);
	}
	for (auto &i : m)
	{
		double price;
		cin >> price;
		i.oneprice = price / i.num;
	}
	sort(m.begin(), m.end(), cmp);
	while (M--)
	{
		for (auto &i : m)
		{
			if (i.num != 0)
			{
				res += i.oneprice;
				i.num--;
				break;
			}
		}
	}
	printf("%.2f", res);
}