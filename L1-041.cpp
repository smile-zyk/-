#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main()
{
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	vector<int> v;
	int n;
	while (~scanf("%d", &n))
		v.push_back(n);
	printf("%d", find(v.begin(), v.end(), 250) - v.begin() + 1);
}