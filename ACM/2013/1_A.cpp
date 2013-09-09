#define DEBUG

#include "cstring"
#include "cstdio"
#include "ctime"
#include "cmath"
#include "algorithm"
#include "iostream"

using namespace std;

#define MAXN 100 + 10
#define MAXLEN 100 + 10

int s[MAXN];

int vis[MAXLEN];

int T;
int N;

int main(void)
{

#ifdef DEBUG
	freopen("1_A_in.txt","r",stdin);
	freopen("1_A_out.txt","w",stdout);
#endif

	scanf("%d", &T);
	while(T--){

		memset(vis,0,sizeof(vis));

		scanf("%d", &N);

		if(N <= 0){
			printf("0\n");
			continue;	
		} 

		for(int i=0; i<N; i++)
			scanf("%d", &s[i]);

		sort(s,s+N);

		int cnt = 0;
		for(int i=0; i<N-2; i++)
			if(!vis[s[i]] && s[i] == s[i+2]){
				cnt++;
				vis[s[i]] = 1;
			}

		printf ("%d\n", cnt);

	}

	return 0;
}