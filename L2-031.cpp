#include<iostream>
#include<vector>
using namespace std;
const int N = 100010;
vector<int> h[N];
int n, root = 1;
int max_id, max_depth = -1;
bool has_father[N];
void dfs(int u,int depth)
{
	if (!h[u].size()&&max_depth<depth)
	{
		max_depth = depth;
		max_id = u;
		return;
	}
	for (auto& i : h[u])
	{
		dfs(i, depth + 1);
	}
}

int main()
{
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	cin >> n;
	int k, a;
	for (int i = 1; i <= n; i++)
	{
		cin >> k;
		while (k--)
		{
			cin >> a;
			h[i].push_back(a);
			has_father[a] = true;
		}
	}
	while (has_father[root])root++;
	dfs(root, 0);
	cout << max_id;
}