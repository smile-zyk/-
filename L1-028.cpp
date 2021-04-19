#include<iostream>
using namespace std;
int n;
bool is_prime(int x)
{
    if (x == 1)return false;
    else
    {
        for (long i = 2; i * i <= x; i++)//int*int会导致越界。或者使用sqrt函数
        {
            if (x % i == 0)return false;
        }
        return true;
    }
}
int main()
{
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    cin >> n;
    while (n--)
    {
        int a;
        cin >> a;
        if (is_prime(a))cout << "Yes" << endl;
        else cout << "No" << endl;
    }
}