#include<iostream>
#include<vector>
#include<cmath>
using namespace std;
int main()
{
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	vector<int> res;
	int L;
	cin >> L;
	int num = pow(26, L);
	int n;
	cin >> n;
	int pos = num - n;
	while (pos)
	{
		res.push_back(pos % 26);
		pos /= 26;
	}
	if (res.size() != L)
	{
		for (int i = 0; i < L - res.size(); i++)
			printf("a");
	}
	for (int i = res.size() - 1; i >= 0; i--)
	{
		printf("%c", res[i] + 'a');
	}
}