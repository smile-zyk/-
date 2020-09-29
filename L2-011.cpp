#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#define it vector<int>::iterator
using namespace std;
typedef struct BTree
{
	int data;
	BTree* lchild, * rchild;
	BTree() :data(0), lchild(NULL), rchild(NULL) {}
}*btree;

btree RebuildTree(it PreL, it PreR, it InL, it InR, btree t)
{
	t = new BTree();
	t->data = *PreL;
	int LeftLen = find(InL, InR, *PreL)-InL;
	int RightLen = InR - find(InL, InR, *PreL) - 1;
	if (LeftLen > 0)
		t->lchild = RebuildTree(PreL + 1, PreL + 1 + LeftLen, InL, InL + LeftLen,t->lchild);
	if (RightLen > 0)
		t->rchild = RebuildTree(PreR - RightLen, PreR, InR - RightLen, InR, t->rchild);
	return t;
}

void ReverseTree(btree &t)
{
	if (!t) return;
	else
	{
		ReverseTree(t->lchild);
		ReverseTree(t->rchild);
		btree tmp = t->lchild;
		t->lchild = t->rchild;
		t->rchild = tmp;
	}
}

void LevelOrderTravesral(btree t)
{
	if (!t) return;
	else
	{
		queue<btree> qu;
		qu.push(t);
		int flag = 1;
		while (!qu.empty())
		{
			btree tmp = qu.front();
			qu.pop();
			if (flag)
			{
				flag = 0;
				cout << tmp->data;
			}
			else
				cout << " " << tmp->data;
			if (tmp->lchild)qu.push(tmp->lchild);
			if (tmp->rchild)qu.push(tmp->rchild);
		}
	}
}

int main()
{
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	vector<int> Pre, In;
	int num;
	cin >> num;
	int temp = num;
	while (num--)
	{
		int n;
		cin >> n;
		In.push_back(n);
	}
	while (temp--)
	{
		int n;
		cin >> n;
		Pre.push_back(n);
	}
	btree t = NULL;
	t = RebuildTree(Pre.begin(), Pre.end(), In.begin(), In.end(), t);
	ReverseTree(t);
	LevelOrderTravesral(t);
}