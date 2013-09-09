#define DEBUG  
	
#include "cstdio"  
#include "cstring"
#include "algorithm"
#include "ctime"
  
using namespace std;  

//#define INF 1<<30
#define INF 0x3f3f3f3f
#define MAXN 100 + 10
#define MAXE 10000 + 10
int d[MAXN];
int u[MAXE],v[MAXE];
int w[MAXE];

int bellman(int n, int m, int s, int e){
	for(int i=1; i<=n; i++) d[i] = INF;
	d[s] = 0;
	for(int k=1; k<=n; k++)
		for(int i=1; i<=m;i++){   // 每条边
			int x = u[i], y = v[i];
			if(d[x] < INF) d[y] = min(d[y],d[x]+w[i]);
		}
	if(d[e] == INF) return -1;
	else return d[e];
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

	int e = 0;
	for(i=1; i<=N; i++){
		scanf("%d", &K);
		for(int k=0; k<K; k++){
			scanf("%d", &j);
			u[e+1] = i;
			v[e+1] = j;
			if(!k) w[++e] = 0;
			else w[++e] = 1;
		}
	}

	printf("%d\n", bellman(N,e,A,B));

#ifdef DEBUG  
	printf("Time used = %.9lf", (double)clock() / CLOCKS_PER_SEC);	
#endif 

	return 0;  
}  