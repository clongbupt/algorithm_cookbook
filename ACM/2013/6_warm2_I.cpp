#define DEBUG

#include "cstring"
#include "cstdio"
#include "ctime"
#include "cmath"
#include "algorithm"
#include "iostream"

using namespace std;


int main(void)
{

#ifdef DEBUG
	freopen("6_warm2_I_in.txt","r",stdin);
	freopen("6_warm2_I_out.txt","w",stdout);
#endif

	long long N;
	while(scanf("%lld", &N) != EOF){
		
		for(int i=sqrt(N+0.5); i>=1; i--){
			if(N%(i*i) == 0){
				printf("%lld\n", N/(i*i)*(i+1)*(i+1));
				break;
			}
		}

	}

#ifdef DEBUG  
	printf("Time used = %.9lf", (double)clock() / CLOCKS_PER_SEC);	
#endif 

	return 0;
}