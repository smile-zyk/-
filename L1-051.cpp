#include<iostream>
using namespace std;
int main()
{
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	int p, a;
	cin >> p >> a;
	double b = (float)a / 10;
	printf("%.2f", (double)p * b);
}