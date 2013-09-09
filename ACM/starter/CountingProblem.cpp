#include<iostream>

using namespace std;

#define MAX(a, b) a >= b ? a : b
#define MIN(a, b) a <= b ? a : b

int calc_num (long num)
{
	if (!(num / 10))    //个位数
		if (num == 1)
			return 1;
		else
			return 0;
	else                //非个位数
		if (num % 10 == 1)
			return 1 + calc_num (num / 10);
		else
			return calc_num(num / 10);
}

long counting (long min, long max)
{
	int num = 0;
	for (int i = min; i <= max; i ++)
		num += calc_num(i);
	
	return num;
}

int main()
{
	long first, second;
	
	//同时输入0为结束
	while (cin >> first >> second, first && second)
	{
		long max = MAX(first, second);
		long min = MIN(first, second);
		
		cout << counting(min, max) << endl;
	}
	return 0;
}