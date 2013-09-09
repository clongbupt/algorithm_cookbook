#define DEBUG  
	
#include "cstdio"  
#include "cstring"
#include "algorithm"
#include "ctime"
  
using namespace std;  

#define MAXN 1000000 + 10
#define MAXM 10000 + 10
char T[MAXN];
char P[MAXM];

int fail[MAXN];

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
	int m = strlen(s);
	fail[0] = fail[1] = 0;
	for(int j=1; j<m; j++){
		int k = fail[j];
		while(k && s[j]!=s[k]) k = fail[k];
		fail[j+1] = s[j] == s[k] ? k+1:0;   // 为什么是0x
	}
}

int kmp(char *t, char *p){
	int n = strlen(t);
	int m = strlen(p);
	getFail(p);
	int j=0;
	int ans = 0;
	for(int i=0; i<n; i++){
		while(j>0&&t[i]!=p[j])   
			j = fail[j];
		if(t[i] == p[j])
			j++;
		if(j==m)
			ans++;
	}
	return ans;
}
	
int main(void){

#ifdef DEBUG    
	freopen("poj3461_in.txt","r",stdin);  
	freopen("poj3461_out.txt","w",stdout);   
#endif    
	int cases;
	scanf("%d", &cases);
	while(cases --){
		
		scanf("%s",P);
		scanf("%s",T);

		printf("%d\n", kmp(T,P));

	}
	

#ifdef DEBUG  
	printf("Time used = %.9lf", (double)clock() / CLOCKS_PER_SEC);	
#endif 

	return 0;  
}  