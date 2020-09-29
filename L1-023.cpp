#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
int main()
{
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	int g = 0, p = 0, l = 0, t = 0;
	string s;
	cin >> s;
	g = count(s.begin(), s.end(), 'g') + count(s.begin(), s.end(), 'G');
	p = count(s.begin(), s.end(), 'p') + count(s.begin(), s.end(), 'P');
	l = count(s.begin(), s.end(), 'l') + count(s.begin(), s.end(), 'L');
	t = count(s.begin(), s.end(), 't') + count(s.begin(), s.end(), 'T');
	while (g>0 || p>0 || l>0 || t>0)
	{
		if ((g--)>0)cout << 'G';
		if ((p--)>0)cout << 'P';
		if ((l--)>0)cout << 'L';
		if ((t--)>0)cout << 'T';
	}
}