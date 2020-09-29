#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
using namespace std;
#define it vector<int>::iterator
typedef struct BTree
{
	int data;
	BTree* lchild, * rchild;
	BTree() :data(0), lchild(NULL), rchild(NULL) {}
}*btree;

btree RebuildTree(it PostL,it PostR,it InL,it InR,btree t)
{
	t = new BTree();
	t->data = *(PostR - 1);
	int LeftLen = find(InL, InR, *(PostR - 1))-InL;
	int RightLen = InR - find(InL, InR, *(PostR - 1)) - 1;
	if (LeftLen > 0)
		t->lchild=RebuildTree(PostL,PostL+LeftLen,InL,InL+LeftLen,t->lchild);
	if (RightLen > 0)
		t->rchild=RebuildTree(PostR-1-RightLen,PostR-1,InR-RightLen,InR,t->rchild);
	return t;
}

void LevelOrderTravesral(btree t)
{
	if (!t)return;
	else
	{
		int flag = 1;
		queue<btree> qu;
		qu.push(t);
		while (!qu.empty())
		{
			btree tmp = qu.front();
			qu.pop();
			if (flag)
			{
				cout << tmp->data;
				flag = 0;
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
	int num;
	cin >> num;
	int temp = num;
	vector<int> In, Post;
	while (num--)
	{
		int n;
		cin >> n;
		Post.push_back(n);
	}
	while (temp--)
	{
		int n;
		cin >> n;
		In.push_back(n);
	}
	btree t = NULL;
	t = RebuildTree(Post.begin(), Post.end(), In.begin(), In.end(), t);
	LevelOrderTravesral(t);
}