#define DEBUG  
	
#include "cstdio"  
#include "cstring"
#include "algorithm"
#include "ctime"
  
using namespace std;  

#define lson l,m,rt<<1
#define rson m+1,r,rt<<1|1
#define mid l + ((r-l)>>1)
#define MAXN 50000 + 10
int sum[MAXN<<2];
char c[100];

void pushup(int rt){
	sum[rt] = sum[rt<<1] + sum[rt<<1|1];
}


void build(int l, int r, int rt){
	if(l == r){
		scanf("%d", &sum[rt]);
		return;
	}
	int m = mid;
	build(lson);
	build(rson);
	pushup(rt);
}

void update(int p, int val, int l, int r, int rt){
	if(l == r){
		sum[rt] += val;
		return;
	}
	int m = mid;
	if(p <= m) update(p,val,lson);
	else update(p,val,rson);
	pushup(rt);
}

int query(int ql, int qr, int l, int r, int rt){
	if(ql <= l && qr >= r) return sum[rt];
	int m = mid;
	int res = 0;
	if(ql<=m) res += query(ql,qr,lson);   
	if(qr>m) res+= query(ql,qr,rson);
	return res;
}


int main(void){

#ifdef DEBUG    
	freopen("hdu1166_in.txt","r",stdin);  
	freopen("hdu1166_out.txt","w",stdout);   
#endif    
	
	int T;
	scanf("%d", &T);
	int cases = 0;
	while(T--){
		printf("Case %d:\n", ++cases);
		int N;
		scanf("%d", &N);
		build(1,N,1);
		int i,j;
		while(scanf("%s",c) && c[0] != 'E'){
			scanf("%d %d",&i,&j);
			switch(c[0]){
				case 'Q':
					printf("%d\n",query(i,j,1,N,1));
					break;
				case 'A':
					update(i,j,1,N,1);
					break;
				case 'S':
					update(i,-j,1,N,1);
					break;
			}
		}
	}

#ifdef DEBUG  
	printf("Time used = %.9lf", (double)clock() / CLOCKS_PER_SEC);	
#endif 

	return 0;  
}  