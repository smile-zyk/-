#include<iostream>
#include<string>
using namespace std;
const int N = 60;
int sex[N],flag[N];
string name[N];
int n;
int main()
{
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> sex[i] >> name[i];
	}
	for (int i = 0; i < n / 2; i++)
	{
		for (int j = n - 1; j >= n / 2; j--)
		{
			if (!flag[j] && sex[i] != sex[j])
			{
				cout << name[i] << " " << name[j] << endl;
				flag[j] = true;
				break;
			}
		}
	}
}