//������ʱ��������Ҫ��ѭ�������������������ԵĻ����������Ѿ�ʹ�ù��ġ�
#include<iostream>
#include<algorithm>
#include<vector>
#include<set>
using namespace std;
int main()
{
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	vector<set<int>> vs(55);
	int N;
	scanf("%d", &N);
	for (int i = 0; i < N; i++)
	{
		int M;
		scanf("%d", &M);
		while (M--)
		{
			int n;
			scanf("%d", &n);
			vs[i].insert(n);
		}
	}
	int C;
	scanf("%d", &C);
	while (C--)
	{
		int a, b;
		scanf("%d %d", &a, &b);
		int nt = 0;
		for (auto i : vs[a - 1])
		{
			if (vs[b - 1].find(i) != vs[b - 1].end())//һ��ʼ���ѭ����������������set��Ȼ�������Ӧ�±������copy���ܲ��ң���ʱ�ˣ�
				nt++;
		}
		printf("%.2f%%\n", (double)nt / (vs[a - 1].size() + vs[b - 1].size() - nt) * 100);
	}
}