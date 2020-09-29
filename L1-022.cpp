#include<iostream>
using namespace std;
int main()
{
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	int N;
	int ji = 0, ou = 0;
	cin >> N;
	while (N--)
	{
		int n;
		cin >> n;
		if (n % 2 == 0)ou++;
		else ji++;
	}
	printf("%d %d", ji, ou);
}