#include<iostream>
#include<vector>
using namespace std;
struct record
{
	string id;
	int kaoshi;
	int zuowei;
	record(string id1,int kaoshi1,int zuowei1) :id(id1),kaoshi(kaoshi1),zuowei(zuowei1){}
};
int main()
{
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	int rnum, cnum;
	vector<record> r;
	scanf("%d", &rnum);
	while (rnum--)
	{
		string s;
		s.resize(16);
		int a, b;
		scanf("%s %d %d", &s[0], &a, &b);//想用scanf读取string使用&s[0]时一定要记住先resize。
		r.push_back(record(s, a, b));
	}
	scanf("%d", &cnum);
	int flag = 1;
	while (cnum--)
	{
		int n;
		scanf("%d", &n);
		for (auto re : r)
		{
			if (re.kaoshi == n)
			{
				if (!flag)
					printf("\n");
				else
					flag = 0;
				printf("%s %d", re.id.c_str(), re.zuowei);
				break;
			}
		}
	}
}