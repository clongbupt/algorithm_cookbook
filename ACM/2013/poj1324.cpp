#define DEBUG  
	
#include "cstdio"  
#include "cstring"
#include "algorithm"
#include "ctime"
  
using namespace std;  

#define MAXN 20
int g[MAXN][MAXN];
int n,m,L;

	
int main(void)  
{  
#ifdef DEBUG    
	freopen("poj1324_in.txt","r",stdin);  
	freopen("poj1324_out.txt","w",stdout);   
#endif    
	
	int x,y;
	while(scanf("%d%d%d", &n, &m, &L) && (!n || !m || !L)){
		memset(g,0,sizeof(g));
		for(int i=0; i<m; i++){
			scanf("%d%d",&x,&y);
			g[x][y] = 1;
		}
	}


#ifdef DEBUG  
	printf("Time used = %.9lf", (double)clock() / CLOCKS_PER_SEC);	
#endif 
	return 0;  
}  
