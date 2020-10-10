#include<iostream>
#include<vector>
using namespace std;
int main()
{
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	int n;
	cin >> n;
	int j = 1;
	while (1)
	{
		int m = 0;
		for (int i = 0; i < j; i++)
			m = ((m * 10) % n + 1 % n) % n;
		if (m == 0)break;
		j++;
	}
	vector<int> res;
	int yv = 0;
	int flag = 0;
	for (int i = 0; i < j; i++)
	{
		int tmp = (yv * 10 + 1) / n;
		yv = (yv * 10 + 1) % n;
		if (tmp != 0)flag = 1;
		if (flag)res.push_back(tmp);
	}
	for (auto i : res)
	{
		cout << i;
	}
	printf(" %d", j);
}