#include<iostream>
using namespace std;
int main()
{
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	int n;
	cin >> n;
	int res = (n + 2) % 7;
	printf("%d", res ? res : 7);
}