#define DEBUG  
	
#include "cstdio"  
#include "cstring"
#include "algorithm"
#include "ctime"
  
using namespace std;  

//#define max(a,b) (a>b?a:b)
#define MAXN 100 + 10
int a[MAXN][MAXN], d[MAXN][MAXN];
int n;

int maxNum (int i, int j){
	
	if (d[i][j] >= 0)  return d[i][j];

	return d[i][j] = a[i][j] + (i == n ? 0:max(maxNum(i+1,j),maxNum(i+1,j+1)));

}
	
int main(void)  
{  
#ifdef DEBUG    
	freopen("poj1163_in.txt","r",stdin);  
	freopen("poj1163_out.txt","w",stdout);   
#endif    
	
	memset(d,-1,sizeof(d));
	scanf("%d", &n);
	//while(scanf("%d", &n) != EOF){
		for(int i=1; i<=n; i++){
			for(int j=1; j<=i;j++)
				scanf("%d", &a[i][j]);
			getchar();
		}
	//}
	
	for (int i=0; i<(1<<30); i++) ;

	printf("%d\n", maxNum(1,1));
	printf("Time used = %.9lf", (double)clock() / CLOCKS_PER_SEC);	
	return 0;  
}  



/*
方法二和方法三
int main(void){  
#ifdef DEBUG    
	freopen("poj1163_in.txt","r",stdin);  
	freopen("poj1163_out.txt","w",stdout);   
#endif    
	
	scanf("%d", &n);
	for(int i=1; i<=n; i++){
		for(int j=1; j<=i;j++)
			scanf("%d", &a[i][j]);
		getchar();
	}

	// for(int j=1;j<=n;j++) d[n][j] = a[n][j];
	// for(int i=n-1;i>=1;i--)
	// 	for(int j=1;j<=i;j++)
	// 		d[i][j] = a[i][j] + max(d[i+1][j],d[i+1][j+1]);
	// printf("%d\n",d[1][1]);
	
	for(int i=n-1;i>=1;i--)
		for(int j=1;j<=i;j++)
			a[i][j] += max(a[i+1][j],a[i+1][j+1]);
	printf("%d\n", a[1][1]);
	return 0;
}
*/