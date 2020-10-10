#include<iostream>
#include<algorithm>
#include<map>
#include<string>
using namespace std;
map<int, int> t;
struct message
{
	string name;
	int p;
	float s;
}mess[105];
bool cmp(message a, message b)
{
	if (a.p != b.p)
		return a.p > b.p;
	else
		return a.s < b.s;
}

int main()
{
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	int N;
	cin >> N;
	for (int m = 0; m < N; m++)
	{
		t.clear();
		int n;
		cin >> mess[m].name >> n;
		while (n--)
		{
			int m;
			cin >> m;
			if (t.find(m) == t.end())
				t.insert({ m,1 });
			else
				t[m]++;
		}
		for (auto i : t)
		{
			mess[m].p++;
			mess[m].s += i.second;
		}
		mess[m].s /= mess[m].p;
	}
	sort(mess, mess + 105, cmp);
	for (int i = 0; i < 3; i++)
	{
		if (i != 0)cout << " ";
		if (mess[i].name.length() == 0)
			cout << "-";
		else cout << mess[i].name;
	}
}