#include<iostream>
#include<cmath>
using namespace std;
int main()
{
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	int num;
	char c;
	scanf("%d %c", &num, &c);
	int i = 0;
	while (2 * pow(i, 2) - 1 < num)
		i++;
	if (2 * pow(i, 2) - 1 != num)i--;
	int tmp = i;
	while (i)
	{
		int n = 2 * i - 1;
		int m = tmp - i;
		while (m--)printf(" ");
		while (n--)printf("%c", c);
		printf("\n");
		i--;
	}
	i += 2;
	while (i != tmp + 1)
	{
		int m = tmp - i;
		int n = 2 * i - 1;
		while (m--)printf(" ");
		while (n--)printf("%c", c);
		printf("\n");
		i++;
	}
	//printf("%d", num - (2 * pow(tmp, 2) - 1));
	//��������д�����ܵó���ȷ�Ĵ𰸣�ע���������ʱʹ����pow�������ú������ص���һ��double�͵ĸ��������ᵼ�¸ñ��ʽ��ֵת��Ϊdouble����printf�ĸ�ʽ��Ϊ%d��ʶ��Ϊ32λ��int������ֻ��ǰ32λ����
	//ʹ��printfʱ��Ҫע���ʽ���ͱ��ʽ��ֵһ��Ҫ��Ӧ��
	printf("%d", num - (2 * tmp * tmp - 1));
}