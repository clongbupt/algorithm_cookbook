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

typedef struct _edge{
	int from;
	int to;
	int dist;
}Edge;

typedef struct _heapNode{
	int d;
	int u;
	bool operator < (const _heapNode & rhs) const{
		return d > rhs.d;
	}
}HeapNode;

// 单源最短路
struct Dijkstra{
	int n,m;
	vector<Edge> edges;
	vector<int> G[MAXN];     // 临接表
	bool done[MAXN];
	// int d[MAXN];
	long long d[MAXN];
	int p[MAXN];

	void init(int n){
		this->n = n;
		for(int i=0; i<n; i++) G[i].clear();
		edges.clear();
	}

	void addEdge(int from, int to, int dist){
		edges.push_back((Edge){from,to,dist});
		m = edges.size();
		G[from].push_back(m-1);
	}

	void dijkstra(int s){
		priority_queue<HeapNode> q;
		memset(done,false,sizeof(done));

		for(int i=1; i<=n; i++) d[i] = INF;
		d[s] = 0;
		q.push((HeapNode){d[s],s});
		while(!q.empty()){
			HeapNode x = q.top(); q.pop();
			int u = x.u;
			if(done[u]) continue;
			done[u] = true;
			for(int i=0; i<G[u].size(); i++){
				Edge &e = edges[G[u][i]];
				if(d[e.to] > d[u] + e.dist)
				{
					d[e.to] = d[u] + e.dist;
					p[e.to] = G[u][i];
					q.push((HeapNode){d[e.to],e.to});
				}
			}
		}

	}
};

int main(void){

#ifdef DEBUG    
	freopen("poj1511_in.txt","r",stdin);  
	freopen("poj1511_out.txt","w",stdout);   
#endif    
	
	int N,P,Q;
	Dijkstra dijkstra;
	scanf("%d",&N);   // cases
	while(N--){
		scanf("%d%d", &P, &Q);   // P => Point   Q => Edge
		dijkstra.init(P);
		for(int i=1; i<=Q; i++){
			int u,v,w;
			scanf("%d%d%d", &u, &v, &w);
			dijkstra.addEdge(u,v,w);
		}

		dijkstra.dijkstra(1);

		long long ans = 0;
		for(int i=1; i<=P; i++)
			ans += dijkstra.d[i];

		printf("%lld\n", ans);
	}

#ifdef DEBUG  
	printf("Time used = %.9lf", (double)clock() / CLOCKS_PER_SEC);	
#endif 

	return 0;  
}  