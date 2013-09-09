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
		
		int n = 1 << D;
		
		int i, j;
		for (i = 0; i < I; i ++)
		{
			for (j = 1; j <= n; j ++)
			{
				flag[j] = !flag[j];
				j = flag[j] ? j * 2 : (j * 2 + 1);
			}
		}
		printf("%d", j/2);
	}
	
	return 0;
}
