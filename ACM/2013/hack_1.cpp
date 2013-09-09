#define DEBUG  
#include "cstdio" 
#include "algorithm"
#include "iostream"
#include "string"

#include "cstring" 
#include "iomanip"
#include "vector"
using namespace std; 

#define MAXN 9999
#define MAXSIZE 10
#define DLEN 4

string fun(int x, int y, int m)  
{ 
	vector <bool> flag; 
	flag.assign(y,false); 
	string left="";
	string ret="";
	int a =x%y;  
	while( a != 0 && !flag[a])  
	{ 
	left += a+'0';
	flag[a] = true; 
	a *= 10; 
	ret += a/y+'0'; 
	a = a%y; 
	if(ret.length() > m)
		return ret;
	} 
	if(a == 0) return "0"; 
	char ch = a + '0';            
	int site = left.find_first_of(ch);   
	ret = ret.substr(site); 

	return ret; 
} 


int gcd (int a, int b){
	int t;
	if(!b) 
		return a;

	while(t = a%b){
		a=b;
		b=t;
	}
	return b;
}

void simplify(int *a, int *b){
	int t;
	if( t=gcd(*a,*b)){
		*a /= t;
		*b /= t;
	}
	else{
		*b = 1;
	}
}

int main(int argc, char const *argv[])
{

#ifdef DEBUG    
	freopen("hack_1.txt","r",stdin);  
	freopen("hack_1_out.txt","w",stdout);   
#endif    

	int cases;

	int A,B,M,N;
	int len;
	long long num;
	long long result;
	long long pos;

	scanf("%d", &cases);
	while(cases --){
		scanf("%d %d %d %d", &A, &B, &M, &N);
		// printf("A, B : %d %d \n", A, B);
		while(A>B){
			A -= B;
		}
		// printf("gcd(A,B) : %d\n", gcd(A,B));
		simplify(&A, &B);
		// printf("A, B : %d %d \n", A, B);
		
		string s = fun(A,B,M);
		// cout << "string:" << s << endl;

		len = s.size();
		// printf("len : %d\n", len);
		
		pos = s.find_first_of('0'+N);
		// printf("pos : %d\n", pos);

		if( pos == s.npos){
			printf("0\n");
		}else{
			M--;
			while(s.find_first_of('0'+N,pos+1) != s.npos && M){
				pos = s.find_first_of('0'+N,pos+1);
				M--;
			}
			num = M*len;
			// M %= len;
			// printf("%d\n", M);
			result = num + pos + 1;
			printf("%lld\n", result);
		}

	}

	return 0;

}