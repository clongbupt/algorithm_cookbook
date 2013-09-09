#define DEBUG  
	
#include "cstdio"  
#include "cstring"
#include "algorithm"
#include "ctime"
  
using namespace std;  

#define MAXN 200 + 10
int g[MAXN][MAXN];
int flag[MAXN];
	
int main(void){

#ifdef DEBUG    
	freopen("hdu1789_in.txt","r",stdin);  
	freopen("hdu1789_out.txt","w",stdout);   
#endif    
	
	int cases;
	scanf("%d", &cases);
	while(cases--){
		int N,M;
		scanf("%d%d", &N,&M);

		int Si;
		int temp;
		for(int i=0; i<N; i++)
		{
			scanf("%d", &Si);
			for(int j=0; j<Si; j++)
			{
				scanf("%d", &temp);
				a[i][temp-1] = 1;
			}	
		}
	}
	

#ifdef DEBUG  
	printf("Time used = %.9lf", (double)clock() / CLOCKS_PER_SEC);	
#endif 

	return 0;  
}  