//此题的测试点有问题,不检查只有一个数时分子分母的是否有公因数
//注意一定要根据题目说的类型定义变量！
#include<iostream>
#include<cmath>
using namespace std;
#define LL long long int
LL gcd(LL x, LL y)
{
	return y ? gcd(y, x % y) : x;
}

struct number
{
	LL intger;
	LL fenzi;
	LL fenmu;
	number() { fenzi = 0, fenmu = 0; intger = 0; };
	number operator+(number n)
	{
		number result;
		if (this->fenzi == 0)
		{
			if (n.fenzi == 0)
				return result;
			n.intger += this->intger;
			return n;
		}
		result.intger = this->intger + n.intger;
		result.fenmu = this->fenmu * n.fenmu;
		result.fenzi = this->fenzi * n.fenmu + n.fenzi * this->fenmu;
		if (abs(result.fenzi / result.fenmu) > 0)
		{
			result.intger += result.fenzi / result.fenmu;
			result.fenzi %= result.fenmu;
		}
		LL g = gcd(abs(result.fenzi), abs(result.fenmu));
		result.fenzi /= g;
		result.fenmu /= g;
		return result;
	}
};

int main()
{
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	int num;
	number result;
	scanf("%d", &num);
	while (num--)
	{
		number n;
		scanf("%lld/%lld", &n.fenzi, &n.fenmu);
		result = result + n;
	}
	if (result.intger == 0 && result.fenzi == 0)
		printf("0");
	else if (result.intger == 0)
		printf("%lld/%lld", result.fenzi, result.fenmu);
	else if (result.fenzi == 0)
		printf("%lld", result.intger);
	else
		printf("%lld %lld/%lld", result.intger, result.fenzi, result.fenmu);
}