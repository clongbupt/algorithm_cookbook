#include<iostream>
#include<cstdio>
#include<cstring>

using namespace std;

#define MAX 1<<20    //2^20 - 1
int flag[MAX];

int main()
{

	int D, I;
	while (scanf("%d%d", &D, &I) != EOF)
	{
		memset(flag, 0, sizeof(flag));
		
		int n = (1 << D) - 1;
		//printf("%d\n\n", n);
		
		int i, j;
		for (i = 0; i < I; i ++)
		{
			j = 1;
			while (j <= n)
			{
				flag[j] = !flag[j];
				j = flag[j] ? j * 2 : (j * 2 + 1);
			}
		}
		printf("%d\n", j/2);
	}
	
	return 0;
}
