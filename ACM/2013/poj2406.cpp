#define DEBUG  
	
#include "cstdio"  
#include "cstring"
#include "algorithm"
#include "ctime"
  
using namespace std;  

#define MAXN 1000000 + 10
char s[MAXN];

int fail[MAXN];
int n;

/**
 * j 的递增略有不解   会计算next[n] 此时s[j] = '\0' 
 */
// void getFail(char *s){
// 	fail[0] = -1;
// 	int k = -1;
// 	int j = 0;
// 	while(s[j] != '\0'){
// 		if(k>-1 && s[k] != s[j])
// 			k = fail[k];
// 		j++;
// 		k++;
// 		if(s[k] == s[j])
// 			fail[j] = fail[k];
// 		else
// 			fail[j] = k;
// 	}
// }

// 刘汝佳书的标准代码   gdb调试过 fail[n] 为循环节
void getFail(char *s){
	int k=0;
	for(int j=1; j<=n; j++){
		if(s[j] == s[k])
			fail[j] = fail[k];
		else
			fail[j] = k;
		while(k>0&&fail[j]!=fail[k])
			k = fail[k];
		k++;
	}
}
	
int main(void){

#ifdef DEBUG    
	freopen("poj2406_in.txt","r",stdin);  
	freopen("poj2406_out.txt","w",stdout);   
#endif    
	memset(s,'\0',sizeof(s));
	memset(fail,-1,sizeof(fail));
	while(scanf("%s", s) != EOF && s[0] != '.'){
		n = strlen(s);
		getFail(s);


		// 下面的不太明白   n - fail[n]  循环节
		// n % (n-fail[n])
		int ans;
		//if(n == 1 || s[fail[n-1]] != s[n-1]) ans = 1;
		if (n == 1) ans = 1;
		else if(n%(n-fail[n]) == 0)  ans = n / (n-fail[n]);
		else ans = 1;


		printf("%d\n", ans);

	}
	

#ifdef DEBUG  
	printf("Time used = %.9lf", (double)clock() / CLOCKS_PER_SEC);	
#endif 

	return 0;  
}  