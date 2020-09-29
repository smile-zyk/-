#include<iostream>
using namespace std;
int main()
{
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	int weight[17] = { 7,9,10,5,8,4,2,1,6,3,7,9,10,5,8,4,2 };
	char mod[11] = { '1','0', 'X','9','8','7','6','5','4','3','2' };
	char id[19];//用char[]容纳字符串要多申请一位！错误名称Stack around the variable 'id' was corrupted.
	int N;
	scanf("%d", &N);
	int flag = 1,result=0;
	int all_flag = 1;
	while (N--)
	{
		flag = 1;
		result = 0;
		scanf("%s", id);
		for(int i=0;i<17;i++)
		{
			if (!(id[i] >= '0' && id[i] <= '9'))
			{
				flag = 0;
				break;
			}
			result += (id[i]-'0') * weight[i];
		}
		if (!flag || mod[result % 11] != id[17])
		{
			printf("%s\n", id), all_flag = 0;
		};
	}
	if (all_flag)printf("All passed");
}