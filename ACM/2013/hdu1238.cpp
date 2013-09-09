#define DEBUG

#include "cstdio"
#include "cstring"
#include "cstdlib"
#include "ctime"
#include "iostream"
#include "algorithm"

using namespace std;

#define MAXN 100
char s[MAXN][MAXN];

char sub[MAXN],subrev[MAXN];

void reverse(){
	int i=0,j=strlen(sub)-1;
	while(i<=j){
		subrev[i++] = sub[j--];
	}
	subrev[i] = '\0';
}

int main(int argc, char const *argv[])
{
	
#ifdef DEBUG    
	freopen("hdu1238_in.txt","r",stdin);  
	freopen("hdu1238_out.txt","w",stdout);   
#endif  

	int cases,n,minindex, minlen=200;

	scanf("%d", &cases);
	while(cases --){
		scanf("%d", &n);
		for(int i=0; i<n; i++){
			scanf("%s", s[i]);
			if(strlen(s[i]) < minlen){
				minindex = i;
				minlen = strlen(s[i]);
			}
		}

		// 从最长的子串开始找
		bool flag;
		int maxsub = 0;
		int i,j;
		for(i=0; i<=minlen-1; i++)
		{
			
			for(j=minlen-1; j>=i; j--)
			{
				memset(sub,'\0',sizeof(sub));
				memset(subrev,'\0',sizeof(subrev));
				int subindex = 0;
				for(int k=i;k<=j;k++) 
					sub[subindex++] = s[minindex][k];

				reverse();
				// strcpy(subrev,sub);
				// strrev(subrev);

				flag = true;
				for(int k=0; k<n; k++) if(k!=minindex)
				{
					if(strstr(s[k],sub) == NULL && strstr(s[k],subrev) == NULL){	
						flag = false;
						break;
					}
				}

				if(flag && maxsub < strlen(sub)){
					maxsub = strlen(sub);
				}
			}
		}

		printf("%d\n", maxsub);

	}


	
#ifdef DEBUG  
	printf("Time used = %.9lf", (double)clock() / CLOCKS_PER_SEC);	
#endif

	return 0;
}