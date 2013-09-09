#define DEBUG  
	
#include "cstdio"  
#include "cstring"
#include "algorithm"
#include "ctime"
  
using namespace std;  

#define lson l,m,rt<<1
#define rson m+1,r,rt<<1|1
#define mid l + ((r-l)>>1)
#define MAXN 200000 + 10
int maxnum[MAXN<<2];
char c[100];

void pushup(int rt){
	maxnum[rt] = max(maxnum[rt<<1],maxnum[rt<<1|1]);
}


void build(int l, int r, int rt){
	if(l == r){
		scanf("%d", &maxnum[rt]);
		return;
	}
	int m = mid;
	build(lson);
	build(rson);
	pushup(rt);
}

void update(int p, int val, int l, int r, int rt){
	if(l == r){
		maxnum[rt] = val;
		return;
	}
	int m = mid;
	if(p <= m) update(p,val,lson);
	else update(p,val,rson);
	pushup(rt);
}

int query(int ql, int qr, int l, int r, int rt){
	if(ql <= l && qr >= r) return maxnum[rt];
	int m = mid;
	int res = 0;
	if(ql<=m) res = max(res,query(ql,qr,lson));   
	if(qr>m) res = max(res,query(ql,qr,rson));
	return res;
}


int main(void){

#ifdef DEBUG    
	freopen("hdu1754_in.txt","r",stdin);  
	freopen("hdu1754_out.txt","w",stdout);   
#endif    
	
	int N,M;

	while(scanf("%d%d", &N,&M) != EOF){
		build(1,N,1);

		char c[2];
		int a,b;
		for(int i=0;i<M;i++){
			// getchar();
			scanf("%s%d%d",c,&a,&b);
			if(c[0] == 'Q')
				printf("%d\n",query(a,b,1,N,1));
			else
				update(a,b,1,N,1);
		}
	}

#ifdef DEBUG  
	printf("Time used = %.9lf", (double)clock() / CLOCKS_PER_SEC);	
#endif 

	return 0;  
}  