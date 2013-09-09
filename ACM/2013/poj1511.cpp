#define DEBUG  
	
#include "cstdio"  
#include "cstring"
#include "algorithm"
#include "ctime"
#include "queue"
#include "vector"
#include "utility" 
  
using namespace std;  


// INF > 1000000000
//#define INF 1<<30
//#define INF 0xffffffff
#define INF 0x3f3f3f3f
#define MAXN 1000000 + 10
#define MAXM 1000000 + 10
#define DIR 2
int first[DIR][MAXN];
int w[MAXM],u[DIR][MAXM],v[DIR][MAXM],next[DIR][MAXM];
long long d[DIR][MAXM];

// 求单源最短路径 
void dijkstra(int n, int m, int dir){
	bool done[MAXN];

	typedef pair<int, int> pii;
	priority_queue<pii, vector<pii>, greater<pii> > q;

	for(int i=1; i<=n; i++) d[dir][i] = (i==1)?0:INF;
	memset(done,false,sizeof(done));
	
	q.push(make_pair(d[dir][1],1));
	while(!q.empty()){
		pii u = q.top(); q.pop();
		int x = u.second;
		if(done[x]) continue;
		done[x] = true;

		for(int e=first[dir][x];e!=-1;e=next[dir][e])
			if(d[dir][v[dir][e]] > (d[dir][x] + w[e]))
			{
				d[dir][v[dir][e]] = d[dir][x] + w[e];
				q.push(make_pair(d[dir][v[dir][e]], v[dir][e]));
			}
	}
}

int main(void){

#ifdef DEBUG    
	freopen("poj1511_in.txt","r",stdin);  
	freopen("poj1511_out.txt","w",stdout);   
#endif    
	
	int N,P,Q;
	scanf("%d",&N);   // cases
	while(N--){
		scanf("%d%d", &P, &Q);   // P => Point   Q => Edge
		memset(first,-1,sizeof(first));
		for(int i=1; i<=Q; i++){
			scanf("%d%d%d", &u[0][i],&v[0][i],&w[i]);
			next[0][i] = first[0][u[0][i]];
			first[0][u[0][i]] = i;

			u[1][i] = v[0][i];
			v[1][i] = u[0][i];
			next[1][i] = first[1][u[1][i]];
			first[1][u[1][i]] = i;
		}

		dijkstra(P,Q,0);
		dijkstra(P,Q,1);

		long long ans = 0;
		for(int dir=0;dir<2;dir++)
			for(int i=1; i<=P; i++)
				ans += d[dir][i];

		printf("%lld\n", ans);
	}

#ifdef DEBUG  
	printf("Time used = %.9lf", (double)clock() / CLOCKS_PER_SEC);	
#endif 

	return 0;  
}  