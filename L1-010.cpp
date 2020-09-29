#include<iostream>
#include<algorithm>

using namespace std;
int main()
{
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	int data[3] = {0};
	scanf("%d %d %d", &data[0], &data[1], &data[2]);
	sort(data,data+3);
	printf("%d", data[0]);
	for (int i = 1; i < 3; i++)
	{
		printf("->%d", data[i]);
	}
}