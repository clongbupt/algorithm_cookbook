#define DEBUG  
	
#include "cstdio"  
#include "cstring"
#include "algorithm"
#include "ctime"
#include "queue"
#include "vector"
#include "utility" 
  
using namespace std;  

#define MAXN 100 + 10
#define MAXM 5000 + 10

typedef struct _edge{
	int u;
	int v;
	int w;
}Edge;

// int u[MAXM],v[MAXM],w[MAXM],r[MAXM];
Edge edge[MAXM];
int p[MAXN];

// sort  ascending
// call : sort(r,r+m,cmp);
int cmp(const Edge i, const Edge j) { return i.w < j.w; }

int find(int x) { return p[x] == x ? x : p[x] = find(p[x]); }

long long Kruskal(int n, int m) {
	long long ans = 0;
	for (int i=0; i<n; i++)	p[i] = i;
	sort(edge,edge+m,cmp);
	for(int i=0; i<m; i++){
		Edge e = edge[i];
		int x = find(e.u);
		int y = find(e.v);

		if (x != y){
			ans += e.w;
			p[x] = y;
		}
	}

	return ans;
}


int main(void){

#ifdef DEBUG    
	freopen("poj1258_in.txt","r",stdin);  
	freopen("poj1258_out.txt","w",stdout);   
#endif    
	
	int n,e,w;

	while(scanf("%d", &n) != EOF && n >= 3){
		e = 0;
		for(int i=0; i<n; i++)
			for(int j=0; j<n; j++)
			{
				scanf("%d", &w);
				if(j>i)
					edge[e++] = (Edge){i,j,w};
			}	
				

		printf("%lld\n", Kruskal(n,e));
	}


#ifdef DEBUG  
	printf("Time used = %.9lf", (double)clock() / CLOCKS_PER_SEC);	
#endif 

	return 0;  
}  