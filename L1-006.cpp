#include<iostream>
#include<cmath>
using namespace std;

bool IsPrime(int v)
{
	for (int i = 2; i < sqrt(v); i++)
	{
		if (v % i == 0)
			return false;
	}
	return true;
}
int main()
{
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	int data;
	scanf("%d", &data);
	int start = 2, length = 0, result = 1;
	int maxlength = 0, maxstart = 0;
	if (!IsPrime(data))
	{
		for(;start<sqrt(data);start++)
		{
			length = 0;
			result = data;
			for(int j=start;j<sqrt(data);j++)
			{
				if (result % j == 0)
				{
					length++;
					result /= j;
				}
				else
				{
					if (length > maxlength)
					{
						maxlength = length;
						maxstart = start;
					}
					break;
				}
			}
		}
		printf("%d\n%d", maxlength,maxstart);
		for (int i = 1; i < maxlength; i++)
			printf("*%d", maxstart + i);
	}
	else
		printf("1\n%d",data);
}


//#include<iostream>
//#include<cmath>
//using namespace std;
//
//bool IsPrime(int v)
//{
//	for (int i = 2; i < v; i++)
//	{
//		if (v % i == 0)
//			return false;
//	}
//	return true;
//}
//int main()
//{
//	//freopen("in.txt", "r", stdin);
//	//freopen("out.txt", "w", stdout);
//	int data;
//	scanf("%d", &data);
//	int start = 2, length = 0, result = 1;
//	int maxlength = 0, maxstart = 0;
//	if (!IsPrime(data))
//	{
//		for (; start < sqrt(data); start++)
//		{
//			while (start + length < sqrt(data) + 1)
//			{
//				result *= (start + length);
//				if (data % result == 0)
//					length++;
//				else
//				{
//					if (length > maxlength)
//					{
//						maxlength = length;
//						maxstart = start;
//					}
//					length = 0;
//					result = 1;
//					break;
//				}
//			}
//		}
//		printf("%d\n%d", maxlength, maxstart);
//		for (int i = 1; i < maxlength; i++)
//			printf("*%d", maxstart + i);
//	}
//	else
//		printf("1\n%d", data);
//}