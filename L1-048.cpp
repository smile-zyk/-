#include<iostream>
#include<vector>
using namespace std;
struct matrix
{
	int r, c;
	vector<vector<int>> data;
};
int main()
{
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	matrix m;
	cin >> m.r >> m.c;
	m.data.resize(m.r);
	for (auto &i : m.data)
		i.resize(m.c);
	for (int i = 0; i < m.r; i++)
		for (int j = 0; j < m.c; j++)
			cin >> m.data[i][j];
	matrix n;
	cin >> n.r >> n.c;
	n.data.resize(n.r);
	for (auto &i : n.data)
		i.resize(n.c);
	for (int i = 0; i < n.r; i++)
		for (int j = 0; j < n.c; j++)
			cin >> n.data[i][j];
	if (m.c != n.r)printf("Error: %d != %d", m.c, n.r);
	else
	{
		cout << m.r << " " << n.c << "\n";
		for (int i = 0; i < m.r; i++)
		{
			if (i != 0)cout << "\n";
			for (int j = 0; j < n.c; j++)
			{
				if (j != 0)cout << " ";
				int res = 0;
				for (int k = 0; k < m.c; k++)
				{
					res += m.data[i][k] * n.data[k][j];
				}
				cout << res;
			}
		}
	}
}