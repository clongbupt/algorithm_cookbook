#define DEBUG  
	
#include "cstdio"  
#include "cstring"
#include "algorithm"
#include "ctime"
  
using namespace std;  

#define MAXN 16000000 + 10
bool hash[MAXN];
char str[MAXN];
int name[260];
	
int main(void)  
{  
#ifdef DEBUG    
	freopen("poj1200_in.txt","r",stdin);  
	freopen("poj1200_out.txt","w",stdout);   
#endif    
	
	int N, NC;

	memset(hash,0,sizeof(hash));
	memset(str,'\0',sizeof(str));
	memset(name,0,sizeof(name));

	scanf("%d %d", &N, &NC);
	scanf("%s", str);

	int radix = 0;
	int len = strlen(str);
	for(int i=0; i<len && radix <= NC; i++)
		if(!name[str[i]])
			name[str[i]] = ++radix;

	int ans = 0;
	for(int i=0; i<=len-N; i++){
		int sum = 0;
		for(int j=0; j<N; j++)
			sum = sum*NC + name[str[i+j]] -1;
		if(!hash[sum])
		{
			hash[sum] = true;
			ans++;
		}
	}

	printf("%d\n", ans);

#ifdef DEBUG  
	printf("Time used = %.9lf", (double)clock() / CLOCKS_PER_SEC);	
#endif 

	return 0;  
}  