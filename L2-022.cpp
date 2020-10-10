#include<iostream>
#include<algorithm>
using namespace std;
struct node
{
	int data;
	int next;
}linklist[100000],reverselist[100000],newlist[100000];
int main()
{
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	int head, len;
	cin >> head >> len;
	for (int i = 0; i < len; i++)
	{
		int a;
		cin >> a;
		cin >> linklist[a].data >> linklist[a].next;
		reverselist[a].data = linklist[a].data;
		reverselist[a].next = linklist[a].next;
		newlist[a].data = linklist[a].data;
		newlist[a].next = linklist[a].next;
	}
	int first = head;
	int n = 0;
	while (first != -1)
	{
		first = linklist[first].next;
		n++;
	}
	len = n;
	int old = -1;
	int _new = head;
	int next = reverselist[head].next;
	while (_new != -1)
	{
		reverselist[_new].next = old;
		old = _new;
		_new = next;
		if (_new != -1)
			next = reverselist[_new].next;
	}
	int reversehead = old;
	int rp = reversehead;
	int p = head;
	int newhead = -1;
	int last = -1;
	for (int i = 0; i < len / 2; i++)
	{
		if (newhead == -1)
			newhead = rp;
		else
			newlist[last].next = rp;
		newlist[rp].next = p;
		last = p;
		p = linklist[p].next;
		rp = reverselist[rp].next;
	}
	if (len % 2 != 0)
	{
		newlist[last].next = rp;
		last = rp;
	}
	newlist[last].next = -1;
	int np = newhead;
	while (np != -1)
	{
		printf("%05d %d ", np, newlist[np].data);
		if (newlist[np].next != -1)printf("%05d\n", newlist[np].next);
		else printf("-1\n");
		np = newlist[np].next;
	}
}