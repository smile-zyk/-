#include<iostream>
#include<algorithm>
#define MAXN 10005
using namespace std;
struct message
{
	int id, fa, ma, child[6];
	double area, num;
}member[1005];

struct family
{
	int id, people;
	double num, area;
	bool flag;
}ans[MAXN];

int father[MAXN];
bool visited[MAXN];

void init()
{
	for (int i = 0; i < MAXN; i++)
		father[i] = i;
}


int find(int x)
{
	while (x != father[x])
		x = father[x];
	return x;
}

void _union(int x,int y)
{
	int root1 = find(x);
	int root2 = find(y);
	if (root1 < root2)
		father[root2] = root1;
	else
		father[root1] = root2;
}

bool cmp(family x, family y)
{
	if (x.area != y.area)
		return x.area > y.area;
	else
		return x.id < y.id;
}

int main()
{
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	init();
	int N;
	scanf("%d", &N);
	for(int i=0;i<N;i++)
	{
		int num;
		scanf("%d %d %d %d", &member[i].id, &member[i].fa, &member[i].ma, &num);
		visited[member[i].id] = true;
		if (member[i].fa != -1)
		{
			visited[member[i].fa] = true;
			_union(member[i].id, member[i].fa);
		}
		if (member[i].ma != -1)
		{
			visited[member[i].ma] = true;
			_union(member[i].id, member[i].ma);
		}
		for (int j = 0; j < num; j++)
		{
			scanf("%d", &member[i].child[j]);
			visited[member[i].child[j]] = true;
			_union(member[i].id, member[i].child[j]);
		}
		scanf("%lf %lf", &member[i].num, &member[i].area);
	}
	for (int i = 0; i < N; i++)
	{
		int root = find(member[i].id);
		ans[root].id = root;
		ans[root].num += member[i].num;
		ans[root].area += member[i].area;
		ans[root].flag = true;
	}
	int cnt = 0;
	for (int i = 0; i < MAXN; i++)
	{
		if (visited[i])
			ans[find(i)].people++;
		if (ans[i].flag)
			cnt++;
	}
	for (int i = 0; i < MAXN; i++)
	{
		if (ans[i].flag)
		{
			ans[i].num = ans[i].num  / ans[i].people;
			ans[i].area = ans[i].area  / ans[i].people;
		}
	}
	sort(ans, ans + MAXN, cmp);
	printf("%d\n", cnt);
	for (int i = 0; i < cnt; i++)
	{
		printf("%04d %d %.3f %.3f\n", ans[i].id, ans[i].people, ans[i].num, ans[i].area);
	}
}

//#include<iostream>
//#include<vector>
//#include<algorithm>
//using namespace std;
//struct family
//{
//	int HouseNum;
//	double HouseSpace;
//	int flag;
//	int minindex;
//	int parent;
//};
//family p[10005];
//
//void init()
//{
//	for (int i=1;i<10000;i++)
//	{
//		p[i].minindex = i;
//		p[i].parent = -1;
//	}
//}
//
//bool cmp(int index1, int index2)
//{
//	double i1 = p[index1].HouseSpace / (-p[index1].parent);
//	double i2 = p[index2].HouseSpace / (-p[index2].parent);
//	if (i1 != i2)
//		return i1 > i2;
//	else
//		return p[index1].minindex < p[index2].minindex;
//}
//
//void union_each(int index1, int index2)
//{
//	p[index2].flag = 1;
//	int root1 = index1, root2 = index2;
//	while (p[root1].parent > 0)root1 = p[root1].parent;
//	while (p[root2].parent > 0)root2 = p[root2].parent;
//	if (root1 != root2)
//	{
//		if (p[root1].parent <= p[root2].parent)
//		{
//			p[root1].parent += p[root2].parent;
//			p[root1].HouseNum += p[root2].HouseNum;
//			p[root1].HouseSpace += p[root2].HouseSpace;
//			p[root2].parent = root1;
//			p[root1].minindex = min(p[root1].minindex, p[root2].minindex);
//		}
//		else
//		{
//			p[root2].parent += p[root1].parent;
//			p[root2].HouseNum += p[root1].HouseNum;
//			p[root2].HouseSpace += p[root1].HouseSpace;
//			p[root1].parent = root2;
//			p[root2].minindex = min(p[root1].minindex, p[root2].minindex);
//		}
//	}
//	else
//	{
//		p[root2].minindex = min(p[root1].minindex, p[root2].minindex);
//	}
//}
//
//int main()
//{
//	freopen("in.txt", "r", stdin);
//	freopen("out.txt", "w", stdout);
//	init();
//	int N;
//	scanf("%d", &N);
//	while (N--)
//	{
//		int a, b, c, pn, s,n;
//		scanf("%d %d %d %d", &a, &b, &c, &pn);
//		p[a].flag = 1;
//		int root = a;
//		if (b != -1)
//			root = union_each(a, b);
//		if (c != -1)
//			root = union_each(a, c);
//		while (pn--)
//		{
//			int n;
//			scanf("%d", &n);
//			root=union_each(a, n);
//		}
//		scanf("%d %d", &n, &s);
//		p[root].HouseNum += n;
//		p[root].HouseSpace += s;
//	}
//	vector<int> root_list;
//	for (int i = 0; i < 10000; i++)
//	{
//		if (p[i].flag && p[i].parent < 0)
//			root_list.push_back(i);
//	}
//	sort(root_list.begin(), root_list.end(), cmp);
//	cout << root_list.size()<<endl;
//	for (auto i : root_list)
//	{
//		printf("%04d %d %.3f %.3f\n", p[i].minindex, -p[i].parent, (float)p[i].HouseNum / (-p[i].parent), p[i].HouseSpace / (-p[i].parent));
//	}
//}