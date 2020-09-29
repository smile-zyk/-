#include<iostream>
#include<string>
using namespace std;
int main()
{
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	float p = 1, result = 0;
	string data;
	cin >> data;
	if (data[0] == '-')
	{
		p *= 1.5;
		data.erase(data.begin());
	}
	if ((data.back() - '0') % 2 == 0)
		p *= 2;
	for (auto c : data)
	{
		if (c == '2')
			result += (float)1 / data.size();
	}
	printf("%.2lf%%", (double)p * result * 100);
}