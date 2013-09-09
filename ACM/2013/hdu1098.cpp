#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>

using namespace std;

const int MAXN = 45 + 1;

long long f[MAXN];

int main(int argc, char const *argv[])
{
	
	int n;
	while(scanf("%d", &n) == 1){
		f[1] = f[2] = 2;
		for(int i=3; i<=45; i++)
			f[i] = f[i-1] + f[i-2];
		// for(int i=1;i<=45; i++)
		// 	printf("%I64d ", f[n]);

		printf("%lld\n", f[n]);
	}
	return 0;
}


/*

另外一种算法

#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

typedef long long LL;

LL f[50][3];
int N;

int main() {
	int i, j, k, l;
	scanf("%d", &N);
	f[1][0]=f[1][1]=f[2][0]=f[2][1]=1;
	for (i = 3; i <= N; ++i)
		for (j = 0; j < 2; ++j)
			f[i][j] = f[i-1][!j]+f[i-2][!j];
	printf("%lld\n", f[N][0]+f[N][1]);
	return 0;
}
 */


/*
带debug的代码

// #define DEBUG  
  
#include <fstream>  
#include <stdio.h>  
#define MAX 50  
using namespace std;  
  
int main(void)  
{  
#ifdef DEBUG    
  freopen("C:/Users/neo/Desktop/stdin.txt","r",stdin);  
  freopen("C:/Users/neo/Desktop/stdout.txt","w",stdout);   
#endif    
  long long num[MAX];  
  num[1]=num[2]=2ll;  
  for (int i=3;i<MAX;++i)  
    num[i]=num[i-1]+num[i-2];  
    int n;  
    scanf("%d",&n);  
    printf("%lld\n",num[n]);  
  
  return 0;  
}  
 */