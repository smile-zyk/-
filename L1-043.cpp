#include<iostream>
#include<cmath>
using namespace std;
int bookdata[1001];
int flag[1001];
int now_time = 0;
int avgtime = 0;
int tim = 0;
int bn, h, m;
char c;
void init()
{
	tim = 0;
	avgtime = 0;
	for (int i = 1; i <= 1000; i++)
	{
		flag[i] = 0;
		bookdata[i] = 0;
	}
}
int main()
{
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	int N;
	cin >> N;
	while(~scanf("%d %c %d:%d", &bn, &c, &h, &m))
	{	
		now_time = h * 60 + m;
		if (bn!=0)
		{
			if (c == 'S')
			{
				flag[bn] = 1;
				bookdata[bn] = now_time;
			}
			if (c == 'E' && flag[bn] == 1)
			{
				flag[bn]--;
				tim++;
				avgtime += (now_time - bookdata[bn]);
				bookdata[bn] = 0;
			}
		}
		else
		{
			printf("%d %d\n", tim, tim ? (int)((double)avgtime / tim + 0.5) : 0);
			init();
		}
	}
}