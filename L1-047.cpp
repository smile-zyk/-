#include<iostream>
#include<vector>
#include<string>
using namespace std;
struct message
{
	string name;
	int hu;
	int mai;
};
vector<message> m;
int main()
{
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	int n;
	cin >> n;
	while (n--)
	{
		message tmp;
		cin >> tmp.name >> tmp.hu >> tmp.mai;
		if (tmp.hu < 15 || tmp.hu>20 || tmp.mai < 50 || tmp.mai>70)cout << tmp.name << endl;
	}
}