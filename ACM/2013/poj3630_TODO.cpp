#define DEBUG  
	
#include "cstdio"  
#include "cstring"
#include "algorithm"
#include "ctime"
  
using namespace std;  

#define MAXN 10000 + 10

typedef struct _Trie{
	int ch[MAXN][11];
	int val[MAXN];    // 附加信息
	int sz;           // 结点总数
	_Trie() { sz = 1; memset(ch[0],0,sizeof(ch[0]));}
	// int idx(char c) { return c - 'a'; }
	int idx(char c) { return c - '0'; }

	bool insert(char *s, int v){
		int u=0;
		int n = strlen(s);
		for (int i=0; i<n; i++){
			int c = idx(s[i]);
			if(!ch[u][c])
			{
				memset(ch[sz], 0, sizeof(ch[sz]));
				val[sz] = 0;
				ch[u][c] = sz++;
			}
			if(val[u] != 0)
				return false;
			u = ch[u][c];
		}
		if (!val[u])
			val[u] = v;
		else
			return false;
		return true;
	}

	int search(char *s){
		int u=0;
		int n = strlen(s);

		for (int i=0; i<n; i++){
			int c = idx(s[i]);
			if(!ch[u][c])
				return -1;
			else
				u = ch[u][c];
		}
		return val[u];
	}
}Trie;

Trie trie;
	
int main(void){

#ifdef DEBUG    
	freopen("poj3630_in.txt","r",stdin);  
	freopen("poj3630_out.txt","w",stdout);   
#endif    
	
	int cases;
	char str[11];
	int n;
	bool flag = true;
	
	scanf("%d", &cases);
	while(cases --){
		scanf("%d", &n);
		
		memset(str,'\0',sizeof(str));
		for(int i=0; i<n; i++){	
			scanf("%s", str);
			if(!trie.insert(str,i+1))
			{
				flag = false;
				break;
			}
		}
		if (flag)
			printf("YES\n");
		else
			printf("NO\n");

	}	
	

#ifdef DEBUG  
	printf("Time used = %.9lf", (double)clock() / CLOCKS_PER_SEC);	
#endif 

	return 0;  
}  