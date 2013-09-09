#define DEBUG  
	
#include "cstdio"  
#include "cstring"
#include "algorithm"
#include "ctime"
  
using namespace std;  

int a[10][4] = {{0},
				{1},
				{6,2,4,8},
				{1,3,9,7},
				{6,4},
				{5},
				{6},
				{1,7,9,3},
				{6,8,4,2},
				{1,9}};
	
int main(void)  
{  
#ifdef DEBUG    
	freopen("hdu1061_in.txt","r",stdin);  
	freopen("hdu1061_out.txt","w",stdout);   
#endif    
	
	int n;
	scanf("%d", &n);
	while(n--){
		int num;
		scanf("%d",&num);
		int d = num % 10;
		switch(d){
			case 0:
			case 1:
			case 5:
			case 6:
				printf("%d\n",d);break;
			case 4:
			case 9:
				printf("%d\n",a[d][num%2]);break;
			case 2:
			case 3:
			case 7:
			case 8:
				printf("%d\n",a[d][num%4]);break;
		}
	}

#ifdef DEBUG  
	printf("Time used = %.9lf", (double)clock() / CLOCKS_PER_SEC);	
#endif 

	return 0;  
}  