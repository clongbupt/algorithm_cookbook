#define DEBUG  
	
#include "cstdio"  
#include "cstring"
#include "algorithm"
#include "ctime"
#include "queue"
#include "vector"
#include "utility" 
  
using namespace std;  

#define MAXN 27 + 10
#define MAXM 75 + 10

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

int Kruskal(int n, int m) {
	int ans = 0;
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
	freopen("poj1251_in.txt","r",stdin);  
	freopen("poj1251_out.txt","w",stdout);   
#endif    
	
	int n;
	while(scanf("%d",&n) != EOF && n){
		int k,e;
		int pv,w;
		char s[2];
		e = 0;
		for(int pu=0; pu<n-1; pu++){
			scanf("%s",s);
			scanf("%d", &k);
			for(int j=0; j<k; j++){
				scanf("%s",s);
				scanf("%d", &w);
				pv = s[0] - 'A';
				edge[e] = (Edge){pu,pv,w};
				e++;
			}
		}

		printf("%d\n", Kruskal(n,e));
	}

#ifdef DEBUG  
	printf("Time used = %.9lf", (double)clock() / CLOCKS_PER_SEC);	
#endif 

	return 0;  
}  