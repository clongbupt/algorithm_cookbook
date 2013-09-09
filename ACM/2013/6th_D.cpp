#define DEBUG

#include "cstring"
#include "cstdio"
#include "ctime"
#include "cmath"
#include "algorithm"
#include "iostream"

using namespace std;

#define MAXK 1440 + 10
#define MAXN 1000 + 10
int k[MAXN][MAXK];

int p[MAXN];

int T,N,K;
int h,m;

int result[MAXN];
int sum;

int x,y;

bool cmp (const int a, const int b){
	return a < b;
}

int find(int x) {
	return p[x] == x ? x : p[x] = find(p[x]);
}

bool findCommon(int a, int b){

	for(int i=0; k[a][i] != -1; i++)
		for(int j=0; k[b][j] != -1; j++)
			if(k[a][i] == k[b][j])
				return true;

	return false;
}

int main(void)
{

#ifdef DEBUG
	freopen("6th_D_in.txt","r",stdin);
	freopen("6th_D_out.txt","w",stdout);
#endif

	scanf("%d", &T);
	while(T--){

		memset(k,-1,sizeof(k));
		memset(p,-1,sizeof(p));

		scanf("%d",&N);
		for(int i=0; i<N; i++)
		{
			scanf("%d", &K);
			for(int j=0; j<K; j++)
			{
				scanf("%d:%d",&h,&m);
				if((h*60 + m) != 1440) k[i][j] = h*60 + m;
				else k[i][j] = 0;
			}

			sort(k[i],k[i]+K,cmp);
		}

		for(int i=0; i<N; i++) p[i] = i;

		for(int i=0; i<N-1; i++)
			for(int j=i+1;j<N;j++)
			{
				x = find(i);
				y = find(j);
				if(x != y && findCommon(i,j)){
					//p[x] = y;
					p[y] = x;
				}
			}

		memset(result,0,sizeof(result));
		for(int i=0; i<N; i++)
		{
			if(p[i] != -1)
				result[p[i]] ++;
		}

		sum = 0;
		for(int i=0; i<N; i++)
			if(result[i] !=0)
				sum ++;
		printf("%d\n", sum);

		sort(result,result+N,cmp);

		bool flag = true;
		for(int i=0; i<N; i++)
			if(result[i] != 0){
				if (flag){
					printf("%d",result[i]);
					flag = false;
				}
				else printf(" %d", result[i]);
			}
				// if(result[i+1]!=0)
				// 	printf("%d ",result[i]);
				// else{
				// 	printf("%d\n",result[i]);
				// 	break;
				// }
			// }
		puts("");
	}

	return 0;
}