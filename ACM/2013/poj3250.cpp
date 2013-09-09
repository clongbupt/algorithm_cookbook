#define DEBUG  
	
#include "cstdio"  
#include "cstring"
#include "algorithm"
#include "ctime"
#include "queue"
#include "vector"
#include "utility" 
#include "stack"
  
using namespace std;  

stack<int> s;

int main(int argc, char const *argv[])
{


#ifdef DEBUG    
	freopen("poj3250_in.txt","r",stdin);  
	freopen("poj3250_out.txt","w",stdout);   
#endif    
	
	int N,h;
	long long ans = 0;
	scanf("%d", &N);
	for(int i=0; i<N; i++){
		scanf("%d", &h);
		while(!s.empty() && s.top() <= h){   // Attention little equal, not little
			s.pop();
		}
		s.push(h);
		ans += s.size() - 1;
	}	

	printf("%lld\n", ans);


#ifdef DEBUG  
	printf("Time used = %.9lf", (double)clock() / CLOCKS_PER_SEC);	
#endif 

	return 0;  
}  