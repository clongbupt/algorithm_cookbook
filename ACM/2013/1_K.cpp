#define DEBUG

#include "cstring"
#include "cstdio"
#include "ctime"
#include "cmath"
#include "algorithm"
#include "utility"
#include "queue"
#include "iostream"

using namespace std;

struct Node {
	long long y;
	int gy;
	bool operator < (const Node& n) const {
		if(gy != n.gy) return gy < n.gy;
		else return y<n.y;
	}
};

priority_queue<Node> pq;

int f(long long num){
	if(num < 10)
		return num;

	int result = num%10;
	while(num>=10){
		num /= 10; 
		result ^= num%10;
		
	}
	return result;
}

int g(long long  num){

	if(num < 10)
		return num;

	int result = num%10;
	while(num>=10){
		num /= 10;
		result += num%10;
	}
	return result;
}


int main(void)
{

#ifdef DEBUG
	freopen("1_K_in.txt","r",stdin);
	freopen("1_K_out.txt","w",stdout);
#endif

	int T;

	long long x;

	scanf("%d", &T);
	while(T--){

		while(!pq.empty())
			pq.pop();

		scanf("%lld", &x);

		if(x == 1) {printf("0\n"); continue;}

		long long fx = f(x);
		for(long long i=x-1; i>0; i--){
			if(f(i) <= fx){
				Node n = (Node){i,g(i)};
				pq.push(n);
			}
		}
		if(!pq.size()) printf("0\n");
		else printf("%lld\n", pq.top());

	}

	return 0;
}