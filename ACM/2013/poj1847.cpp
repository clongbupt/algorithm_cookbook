#define DEBUG  
	
#include "cstdio"  
#include "cstring"
#include "algorithm"
#include "ctime"
  
using namespace std;  

//#define INF 1<<30
#define INF 0x3f3f3f3f
#define MAXN 100 + 10
int d[MAXN],vis[MAXN];
int w[MAXN][MAXN];

int dijkstra(int n, int s, int e){
	memset(vis,0,sizeof(vis));
	for(int i=1; i<=n; i++) d[i] = (i == s) ? 0:INF;

	for (int i=1; i<=n; i++){
		int x, m = INF;
		for(int y=1; y<=n; y++) if(!vis[y] && d[y] < m) m = d[x=y];
		vis[x] = 1;
		// for(int y=1; y<=n; y++) if(d[y] > d[x] + w[x][y]) d[y] = d[x] + w[x][y];
		for(int y=1; y<=n; y++) d[y] = min(d[y], d[x]+w[x][y]);
	}
	
	if (d[e] != INF ) return d[e];
	else return -1;	
}

int main(void){

#ifdef DEBUG    
	freopen("poj1847_in.txt","r",stdin);  
	freopen("poj1847_out.txt","w",stdout);   
#endif    
	
	int N,A,B,K;
	int i,j;
	scanf("%d%d%d", &N, &A, &B);

	memset(w,INF,sizeof(w));

	for(i=1; i<=N; i++){
		scanf("%d", &K);
		for(int k=0; k<K; k++){
			scanf("%d", &j);
			if(!k) w[i][j] = 0;
			else w[i][j] = 1;
		}
	}

	printf("%d\n", dijkstra(N,A,B));

#ifdef DEBUG  
	printf("Time used = %.9lf", (double)clock() / CLOCKS_PER_SEC);	
#endif 

	return 0;  
}  