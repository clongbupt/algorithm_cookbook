#define DEBUG  
	
#include "cstdio"  
#include "cstring"
#include "algorithm"
#include "ctime"
  
using namespace std;  

#define MAXN 1000 + 10
//int dl[MAXN],rs[MAXN];  // dl:deadline rs:reduced score

// homework
typedef struct _homework{
	int dl;   // deadline 
	int rs;   // reduced score

}hw;

hw h[MAXN];

int flag[MAXN];

// 升序
int cmp(const void *x, const void *y){
	if((*(hw *)x).rs != (*(hw *)y).rs) return (*(hw *)x).rs > (*(hw *)y).rs?-1:1;  // 降序
	else return (*(hw *)x).dl > (*(hw *)y).dl?1:-1;   // 升序
}
	
int main(void){

#ifdef DEBUG    
	freopen("hdu1789_in.txt","r",stdin);  
	freopen("hdu1789_out.txt","w",stdout);   
#endif    
	
	int cases;
	scanf("%d", &cases);
	while(cases--){
		int sum = 0;
		memset(flag,0,sizeof(flag));
		
		int N;
		scanf("%d", &N);
		for(int i=0; i<N; i++)
			scanf("%d", &h[i].dl);
		// getchar();
		for(int i=0; i<N; i++)
			scanf("%d", &h[i].rs);

		qsort(h,N,sizeof(h[0]),cmp);

		for(int i=0; i<N; i++)
			for(int j=h[i].dl;j>0;j--){
				if(!flag[j])
				{
					flag[j] = 1;
					break;
				}
				if(j == 1)
					sum += h[j].rs;
			}
		printf("%d\n", sum);
	}
	

#ifdef DEBUG  
	printf("Time used = %.9lf", (double)clock() / CLOCKS_PER_SEC);	
#endif 

	return 0;  
}  