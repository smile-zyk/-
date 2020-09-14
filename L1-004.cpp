#include<iostream>
using namespace std;
int main()
{
	//freopen("in.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);
	int data;
	scanf("%d", &data);
	printf("Celsius = %d", (int)5 * (data - 32) / 9);
}