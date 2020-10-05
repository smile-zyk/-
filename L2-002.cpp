#include<iostream>
#include<cmath>
#include<algorithm>
#include<vector>
using namespace std;
struct node
{
	int data;
	unsigned int next;
};
node list[100005];
vector<int> abs_list;
int main()
{
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	unsigned int head = 0;
	int len = 0;
	scanf("%u %d", &head, &len);
	while (len--)
	{
		unsigned adr = 0, next = 0;
		int data = 0;
		scanf("%u %d %u", &adr, &data, &next);
		list[adr].data = data;
		list[adr].next = next;
	}
	unsigned n = head;
	unsigned last = -1;
	unsigned deln = -1;
	unsigned delhead = -1;
	while (n != -1)
	{
		unsigned tmp = list[n].next;
		if (find(abs_list.begin(), abs_list.end(), abs(list[n].data)) == abs_list.end())
		{
			last = n;
			abs_list.push_back(abs(list[n].data));
		}
		else
		{
			list[last].next = tmp;
			list[n].next = -1;
			if (delhead == -1)
			{
				delhead = n;
				deln = delhead;
			}
			else
			{
				list[deln].next = n;
				deln = n;
			}
		}
		n = tmp;
	}
	n = head;
	while (n != -1)
	{
		printf("%05d %d ",n,list[n].data);
		if (list[n].next == -1)
			printf("-1\n");
		else
			printf("%05d\n", list[n].next);
		n = list[n].next;
	}
	deln = delhead;
	while (deln != -1)
	{
		printf("%05d %d ", deln, list[deln].data);
		if (list[deln].next == -1)
			printf("-1\n");
		else
			printf("%05d\n", list[deln].next);
		deln = list[deln].next;
	}
}