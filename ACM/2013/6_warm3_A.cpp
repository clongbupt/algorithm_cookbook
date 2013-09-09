#define DEBUG

#include "cstring"
#include "cstdio"
#include "ctime"
#include "cmath"
#include "algorithm"
#include "iostream"

using namespace std;

#define MAXN 100000
int sum[MAXN];
int F[MAXN];

int Fa[MAXN];

int GetFa(int x)
{
    if (Fa[x]==x)
       return x;
    return Fa[x]=GetFa(Fa[x]);
}
void Merge(int x,int y)
{
     Fa[GetFa(x)]=Fa[GetFa(y)];
}

int getDivisorSum(int num){
	int sumdiv = 1;
	for(int j=2; j<=num/2;j++){
		if(num%j == 0) sumdiv += num/j;
		if(sumdiv > num) return 0;
	}
	return sumdiv;
}

int getTransferCnt(int num,int cnt){
	if(F[num] != -1) return F[num] +1;

	if(num == 1)
		return cnt + 1;

	int res = getDivisorSum(num);
	if (res == num) return 0;
	if (res > num) return 0;
	getTransferCnt(res,cnt+1);

}

int main(void)
{

#ifdef DEBUG
	freopen("6_warm3_A_in.txt","r",stdin);
	freopen("6_warm3_A_out.txt","w",stdout);
#endif

	int T, N;
	int maxCnt;
	int sumdiv;

	memset(F,-1,sizeof(F));

	for(int i=1; i<=MAXN; i++){
		Fa[i] = i;
		F[i] = 1;
		sum[i] = getDivisorSum(i);
	}


	scanf("%d", &T);
	while(T --){
		scanf("%d", &N);

		maxCnt = 0;
		for(int i=N;i>=1;i--)
		{
			if(F[i] == -1){
				F[i] = getTransferCnt(i,0);
			}
			if(F[i] > maxCnt){
				maxCnt = F[i];
			}
			
		}
		printf("%d\n", maxCnt);
	}

#ifdef DEBUG  
	printf("Time used = %.9lf", (double)clock() / CLOCKS_PER_SEC);	
#endif 

	return 0;
}