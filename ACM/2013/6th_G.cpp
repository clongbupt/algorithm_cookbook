#define DEBUG

#include "cstring"
#include "cstdio"
#include "ctime"
#include "cmath"
#include "algorithm"
#include "iostream"

using namespace std;

#define MAXN 36 + 5
int sum[MAXN];

double total = pow(6.0,7);

void dp(){

	int i,j,k;

	memset(sum,0,sizeof(sum));

	for(i=1; i<=6; i++) sum[i] = 1;

	for(i = 2; i<= 7; i++)
	{
		for(j = i*6; j>=i;j--)
		{
			sum[j] = 0;
			for(k=1; k<=6 && j >= k; k++) sum[j] += sum[j-k];
		}
		for(j=i-1; j >= 0; j--) sum[j] = 0;
	}
}

int main(void)
{

#ifdef DEBUG
	freopen("6th_G_in.txt","r",stdin);
	freopen("6th_G_out.txt","w",stdout);
#endif

	dp();


	int num;
	while(scanf("%d", &num) != EOF){
		if(num < 7 || num > 6*7) printf("0.0000\n");
		else printf("%.4lf\n", sum[num] / total);
	}


#ifdef DEBUG
	printf("Time used = %.9lf", (double)clock() / CLOCKS_PER_SEC);
#endif

	return 0;
}