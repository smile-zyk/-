#include<iostream>
using namespace std;
int main()
{
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	int y, m, d;
	scanf("%d-%d-%d", &m, &d, &y);
	printf("%d-%02d-%02d", y, m, d);
}