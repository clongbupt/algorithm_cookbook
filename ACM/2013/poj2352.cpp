#define DEBUG  
	
#include "cstdio"  
#include "cstring"
  
using namespace std;  

#define lowbit(i) (i&(-i))
#define MAXN 32000 + 10
int c[MAXN],level[MAXN];
	
int sum(int i){
	int s = 0;
	while(i > 0)
	{
		s += c[i];
		i -= lowbit(i);
	}
	return s;
}

void update(int i, int val){
	while(i < MAXN){
		c[i] += val;
		i += lowbit(i);
	}
}

int main(void)  
{  
#ifdef DEBUG    
	freopen("poj2352_in.txt","r",stdin);  
	freopen("poj2352_out.txt","w",stdout);   
#endif    
	
	int N;
	int x, y;

	memset(c,0,sizeof(c));
	memset(level,0,sizeof(level));
	scanf("%d", &N);
	for(int i=0; i<N; i++){
		scanf("%d %d", &x, &y);
		x++;
		level[sum(x)]++;
		update(x,1);
	}
	
	for(int i=0;i<N;i++){
		printf("%d\n",level[i]);
	}
	return 0;  
}  