#include<iostream>
#include<string>
using namespace std;
struct Heap
{
	int data[1005];
	int size;
}H;

void init()
{
	H.data[0] = -10001;
	H.size = 0;
}

void Insert(int data)
{
	int child = ++H.size;
	for (; data < H.data[child / 2]; child /= 2)
	{
		H.data[child] = H.data[child / 2];
	}
	H.data[child] = data;
}

int find(int x)
{
	for (int i = 1; i <= H.size; i++)
	{
		if (H.data[i] == x)
			return i;
	}
	return -1;
}

int main()
{
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	init();
	int N, M;
	scanf("%d %d", &N, &M);
	while (N--)
	{
		int n;
		scanf("%d", &n);
		Insert(n);
	}
	while (M--)
	{
		int n;
		scanf("%d", &n);
		string s;
		cin >> s;
		if (s == "and")
		{
			int m;
			scanf("%d", &m);
			cin >> s;
			cin >> s;
			int i1 = find(n);
			int i2 = find(m);
			if ((i1 % 2 == 0 && i2 == i1 + 1) || (i1 % 2 != 0 && i2 == i1 - 1))
				cout << "T\n";
			else
				cout << "F\n";
		}
		else
		{
			string s1;
			cin >> s1;
			if (s1 == "a")
			{
				cin >> s1;
				cin >> s1;
				int m;
				scanf("%d", &m);
				int i1 = find(n);
				int i2 = find(m);
				if (i1 / 2 == i2)cout << "T\n";
				else cout << "F\n";
			}
			else
			{
				string s2;
				cin >> s2;
				if (s2 == "root")
				{
					int i = find(n);
					if (i == 1)cout << "T\n";
					else cout << "F\n";
				}
				else
				{
					cin >> s2;
					int m;
					scanf("%d", &m);
					int i1 = find(n);
					int i2 = find(m);
					if (i2 / 2 == i1)cout << "T\n";
					else cout << "F\n";
				}
			}
		}
	}
}