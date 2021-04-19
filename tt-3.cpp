#include<iostream>
using namespace std;
int na;
int nb;
int main()
{
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	int a, b;
	cin >> a >> b;
	int N;
	cin >> N;
	int flag = 1;
	while (N--) {
		int ah, ae, bh, be;
		cin >> ah >> ae >> bh >> be;
		if (ae == (ah + bh)&&be!=(ah+bh))
		{
			if (++na > a)
			{
				flag = 0;
				break;
			}
		}
		else if (be == (ah + bh) && ae != (ah + bh))
		{
			if (++nb > b)break;
		}
	}
	if (flag) printf("B\n%d", na);
	else printf("A\n%d", nb);
}