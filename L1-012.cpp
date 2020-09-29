#include<iostream>
#include<cmath>
using namespace std;
int main()
{
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	int a;
	cin >> a;
	cout << "2 ^ " << a << " = " << pow(2, a);
}