#include<iostream>
#include<cstring>
#include<vector>
#include<algorithm>
#define MAXN 505
using namespace std;
int N, M, S, D;
int jiuyuan[MAXN];
int team[MAXN];
int road[MAXN][MAXN];
int collect[MAXN];
int dist[MAXN];
int path[MAXN];
int num[MAXN];
int FindMin()
{
	int min=0x3f3f3f3f;
	int minindex = -1;
	for (int i = 0; i < N; i++)
	{
		if (!collect[i])
		{
			if (dist[i] < min) {
				min = dist[i];
				minindex = i;
			}
		}
	}
	return minindex;
}

int main()
{
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	cin >> N >> M >> S >> D;
	for (int i = 0; i < N; i++)
		scanf("%d", &jiuyuan[i]);
	for (int i = 0; i < M; i++)
	{
		int s, d, l;
		scanf("%d %d %d", &s, &d, &l);
		road[s][d] = l;
		road[d][s] = l;
	}
	memset(dist, 0x3f, sizeof(dist));
	dist[S] = 0;  team[S] = jiuyuan[S]; num[S] = 1;
	while (1)
	{
		int n = FindMin();
		if (n == -1)break;
		collect[n] = 1;
		for (int i = 0; i < N; i++)
		{
			if (road[n][i] != 0)
			{
				if (dist[n] + road[n][i] < dist[i])
				{
					num[i] = num[n];
					team[i] = team[n] + jiuyuan[i];
					dist[i] = dist[n] + road[n][i];
					path[i] = n;
				}
				else if (dist[n] + road[n][i] == dist[i])
				{
					num[i] += num[n];
					if (team[n] + jiuyuan[i] > team[i])
					{
						team[i] = team[n] + jiuyuan[i];
						path[i] = n;
					}
				}
			}
		}
	}
	vector<int> res;
	int n = D;
	while (n != S)
	{
		res.push_back(n);
		n = path[n];
	}
	res.push_back(S);
	reverse(res.begin(), res.end());
	printf("%d %d\n", num[D],team[D]);
	int flag = 1;
	for (auto i : res)
	{
		if (flag)
		{
			printf("%d", i);
			flag = 0;
		}
		else
			printf(" %d", i);
	}
}