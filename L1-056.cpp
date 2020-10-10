#include<iostream>
#include<string>
#include<cmath>
using namespace std;
struct mess
{
	string s;
	double n = 0;
}m[10000];

int main()
{
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	int N;
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		cin >> m[i].s;
		cin >> m[i].n;
	}
	double avg = 0;
	for (int i = 0; i < N; i++)
	{
		avg += m[i].n;
	}
	avg /= 2 * N;

	double mingap=105;
	int minindex = 0;
	for (int i = 0; i < N; i++)
	{
		double gap = fabs(m[i].n - avg);
		if (gap < mingap)
		{
			mingap = gap;
			minindex = i;
		}
	}
	cout << (int)avg << " " << m[minindex].s;
}