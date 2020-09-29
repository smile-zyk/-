#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
typedef struct BTree
{
	int data;
	BTree* lchild, *rchild;
	BTree() :data(0), lchild(NULL), rchild(NULL) {}
}*btree;
vector<int> res;
bool IsBinarySearch1(vector<int> Pre,int first,int end)
{
	int root = Pre[first],mid;
	for (mid = first+1; mid <= end; mid++)
	{
		if (Pre[mid] >= root)
			break;
	}
	for (int m = first+1; m < mid; m++)
	{
		if (Pre[m] >= root)return false;
	}
	for (int n = mid; n < end; n++)
	{
		if (Pre[n] < root)return false;
	}
	if (first + 2 >= mid && mid + 1 >= end)return true;
	return  IsBinarySearch1(Pre, first + 1, mid) && IsBinarySearch1(Pre, mid, end);
}

bool IsBinarySearch2(vector<int> Pre, int first, int end)
{
	int root = Pre[first], mid;
	for (mid = first + 1; mid <= end; mid++)
	{
		if (Pre[mid] < root)
			break;
	}
	for (int m = first + 1; m < mid; m++)
	{
		if (Pre[m] < root)return false;
	}
	for (int n = mid; n < end; n++)
	{
		if (Pre[n] >= root)return false;
	}
	if (mid-first-1<=1&&end-mid<=1)return true;
	return  IsBinarySearch2(Pre, first + 1, mid) && IsBinarySearch2(Pre, mid, end);
}

btree Rebuild1(vector<int>::iterator PreL, vector<int>::iterator PreR, vector<int>::iterator InL, vector<int>::iterator InR, btree t)
{
	int root = *PreL;
	t = new BTree();
	t->data = root;
	int LeftLen = find(InL, InR, root) - InL;
	int RightLen = InR - find(InL, InR, root) - 1;
	if (LeftLen > 0)
		t->lchild = Rebuild1(PreL + 1, PreL + 1 + LeftLen, InL, InL + LeftLen, t->lchild);
	if (RightLen > 0)
		t->rchild = Rebuild1(PreR - RightLen, PreR, InR - RightLen, InR, t->rchild);
	return t;
}

btree Rebuild2(vector<int>::iterator PreL, vector<int>::iterator PreR, vector<int>::iterator InL, vector<int>::iterator InR, btree t)
{
	int root = *PreL;
	t = new BTree();
	t->data = root;
	int LeftLen = find_end(InL, InR, PreL,PreL+1) - InL;
	int RightLen = InR - find_end(InL, InR, PreL, PreL + 1) - 1;
	if (LeftLen > 0)
		t->lchild = Rebuild2(PreL + 1, PreL + 1 + LeftLen, InL, InL + LeftLen, t->lchild);
	if (RightLen > 0)
		t->rchild = Rebuild2(PreR - RightLen, PreR, InR - RightLen, InR, t->rchild);
	return t;
}

void ReverseBinaryTree(btree &t)
{
	if (t == NULL) return;
	ReverseBinaryTree(t->lchild);
	ReverseBinaryTree(t->rchild);
	btree tmp = t->lchild;
	t->lchild = t->rchild;
	t->rchild = tmp;
}

void PostOrder(btree root)
{
	if (root == NULL)return;
	PostOrder(root->lchild);
	PostOrder(root->rchild);
	res.push_back(root->data);
}

bool cmp(int a, int b)
{
	return a > b;
}

int main()
{
	//freopen("in.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);
	int num;
	cin >> num;
	vector<int> Pre;
	int temp = num;
	while (num--)
	{
		int n;
		cin >> n;
		Pre.push_back(n);
	}
	bool orgin = IsBinarySearch1(Pre, 0, Pre.size());
	bool reverse = IsBinarySearch2(Pre, 0, Pre.size());
	if ( orgin || reverse )
	{
		cout << "YES"<<endl;
		btree root = NULL;
		vector<int> In = Pre;
		if (orgin)
		{
			sort(In.begin(), In.end());
			root = Rebuild1(Pre.begin(), Pre.end(), In.begin(), In.end(), root);
		}
		else
		{
			sort(In.begin(), In.end(), cmp);
			root = Rebuild2(Pre.begin(), Pre.end(), In.begin(), In.end(), root);
		}
		PostOrder(root);
		int flag = 1;
		for (auto i : res)
		{
			if (flag)
			{
				cout << i;
				flag = 0;
			}
			else
			{
				cout << " " << i;
			}
		}
	}
	else
		cout << "NO";
}