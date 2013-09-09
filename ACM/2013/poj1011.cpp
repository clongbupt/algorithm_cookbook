#define DEBUG  
	
#include "cstdio"  
#include "cstring"
#include "algorithm"
#include "ctime"
  
using namespace std;  

#define MAXN 64
int s[MAXN];
int flag[MAXN];

int num,group,sum;

bool comp(const int a, const int b){
	return a>b;
}

int dfs(int cur, int curgroup, int curlen){
	
	if(curlen == 0){
		if (curgroup == group -1) return true;
		for (cur=0; flag[cur]; cur++) ;
		flag[cur] = 1;
		if(dfs(cur+1,curgroup+1,sum/group - s[cur]))
			return true;
		flag[cur] = 0;
		return false;
	} else {
		if(cur > num) return false;
		for(int i=cur; i<num;i++){
			if(flag[i])
				continue;
			if(s[i] > curlen)
				continue;
			if(s[i] == s[i-1] && flag[i-1] == 0)
				continue;
			flag[i] = 1;
			if(dfs(i+1, curgroup, curlen-s[i]))
				return true;
			flag[i] = 0;
		}
		return false;
	}
	

}
	
int main(void)  
{  
#ifdef DEBUG    
	freopen("poj1011_in.txt","r",stdin);  
	freopen("poj1011_out.txt","w",stdout);   
#endif    
	
	memset(s,0,sizeof(s));

	while(scanf("%d", &num) != EOF && num){
		
		sum = 0;
		for(int i=0; i<num; i++){
			scanf("%d", &s[i]);
			sum += s[i];
		}

		memset(flag,0,sizeof(flag));

		sort(s,s+num,comp);
		bool end = false;
		for(int i=s[0]; i<=sum/2; i++) if(sum%i == 0){
			group = sum / i;
			flag[0] = 1;
			if(dfs(1,0,i-s[0])){
				printf("%d\n",i);
				end = true;
				break;
			}
			flag[0] = 0;
		}

		if(!end)
			printf("%d\n", sum);
	}

#ifdef DEBUG  
	printf("Time used = %.9lf", (double)clock() / CLOCKS_PER_SEC);	
#endif 
	return 0;  
}  
