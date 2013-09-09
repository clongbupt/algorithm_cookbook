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

int u[MAXM],v[MAXM],w[MAXM],r[MAXM];
int p[MAXN];

// sort  ascending
// call : sort(r,r+m,cmp);
int cmp(const int i, const int j) { return w[i] < w[j]; }

int find(int x) { return p[x] == x ? x : p[x] = find(p[x]); }

int Kruskal(int n, int m) {
	int ans = 0;
	for (int i=0; i<n; i++)	p[i] = i;
	for (int i=0; i<m; i++) r[i] = i;
	sort(r,r+m,cmp);
	for(int i=0; i<m; i++){
		int e = r[i];
		int x = find(u[e]);
		int y = find(v[e]);

		if (x != y){
			ans += w[e];
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
		int pv;
		char s[2];
		e = 0;
		for(int pu=0; pu<n-1; pu++){
			scanf("%s",s);
			scanf("%d", &k);
			for(int j=0; j<k; j++){
				scanf("%s",s);
				pv = s[0] - 'A';
				u[e] = pu;
				v[e] = pv;
				scanf("%d", &w[e]);
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