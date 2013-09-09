/**
 * Jolly Jumper （快乐的跳跃者）  
 * UVa IDs: 10038
 */


#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<cstring>

using namespace std;

int main()
{
	int num;
	
	int array[3005];
	bool appear[3005];
	printf("Hello World\n");
	while (scanf("%d", &num) != EOF)
	{
		if (num == 1){
			int tmp;
			scanf("%d",&tmp);
			if (tmp == 1)
				printf("Jolly\n");
			else
				printf("Not jolly\n");
		}else if (num == 2){
			int tmp1,tmp2;
			scanf("%d %d",&tmp1,&tmp2);
			if (abs(tmp1 - tmp2) == 1)
				printf("Jolly\n");
			else
				printf("Not jolly\n");
		}else{
			for (int i=0;i<num; i++)
				scanf("%d", &array[i]);
				
			memset(appear,false,sizeof(appear));
			
			for (int i=0; i<num-1; i++)
			{
				int tmp = abs(array[i] - array[i+1]);
				if (!appear[tmp])
					appear[tmp] = true;
			}
			bool flag = true;
			for (int i=1; i<num; i++)
				if (!appear[i])
					flag = false;
				
			if (flag)
				printf("Jolly\n");
			else
				printf("Not jolly\n");
		}
	}
	return 0;
}
