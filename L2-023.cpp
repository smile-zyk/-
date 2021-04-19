#include<iostream>
#include<vector>
#include<set>
#define MAX 505
using namespace std;
int main()
{
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	int v, e, k;
	vector<int> map[MAX];
	cin >> v >> e >> k;
	for (int i = 0; i < e; i++)
	{
		int b, e;
		cin >> b >> e;
		map[b].push_back(e);
	}
	int n;
	cin >> n;
	int color[MAX] = { 0 };
	set<int> unique;
	while (n--)
	{
		unique.clear();
		for (int i = 1; i <= v; i++)
		{
			int clr;
			cin >> clr;
			unique.insert(clr);
			color[i] = clr;
		}
		if (unique.size() != k)
			printf("No\n");
		else
		{
			int flag = 0;
			for (int i = 1; i <= v; i++)
			{
				for (int j = 0; j < map[i].size(); j++)
				{
					if (color[i] == color[map[i][j]])
					{
						flag = 1;
						break;
					}
				}
				if (flag) break;
			}
			if (flag)printf("No\n");
			else printf("Yes\n");
		}
	}
}
