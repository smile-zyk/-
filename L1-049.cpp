#include<iostream>
#include<vector>
using namespace std;
int pn[101];
vector<vector<int>> v;
int main()
{
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	int N;
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		cin >> pn[i];
		pn[i] *= 10;
	}
	int j = 0;
	v.resize(N);
	int last = 1;
	while (1)
	{
		int flag = 1;
		for (int i = 0; i < N; i++)
		{
			if (pn[i] != 0)
			{
				flag = 0;
				break;
			}
		}
		if (flag) break;
		for (int i = 0; i < N; i++)
		{
			if (pn[i] != 0)
			{
				if (last == i)
				{
					j += 2;
					v[i].push_back(j);
				}
				else
					v[i].push_back(++j);
				pn[i]--;
				last = i;
			}
		}
	}
	for (int i = 0; i < N; i++)
	{
		printf("#%d\n", i + 1);
		int m = 0;
		for (auto n : v[i])
		{
			m++;
			if (m % 10 != 1)cout << " ";
			cout << n;
			if (m % 10 == 0)cout << "\n";
		}
	}
}