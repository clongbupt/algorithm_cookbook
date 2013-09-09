/**
 * The 3n+1 problem （3n+1 问题）  
 * PC/UVa IDs: 110101/100
 */


#include<iostream>
#include<cstdio>
#include<cstdlib>

using namespace std;

int get_length(long int num)
{
	if (num == 1)
		return 1;
	else if (!(num & 1))   //判断是否为偶数
	//else if (num | 0)
		num >>= 1;
	else
		//num += (num<<1) + 1;
		num += (num << 1) + 1;
		
	return 1 + get_length(num);
}

int get_result(long int min, long int max)
{
	int max_length = 0;
	int length;
	for (long int i=min; i<=max; i++)
	{
		length = get_length(i);
		//printf("%d %d\n",i,length);
		if (max_length < length)
			max_length = length;
	}
	
	return max_length;
}

int main()
{
	long int a,b;
	
	while (scanf("%ld %ld", &a,&b) != EOF)
	{
		long int min = a > b ? b : a;
		long int max = a > b ? a : b;
		//printf("%d %d\n", min,max);
		printf("%d %d %d\n",a,b,get_result(min,max));
	}
	
	return 0;
}
