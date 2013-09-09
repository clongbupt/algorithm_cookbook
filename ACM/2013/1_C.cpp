#define DEBUG

#include "cstring"
#include "cstdio"
#include "ctime"
#include "cmath"
#include "algorithm"
#include "iostream"

using namespace std;

#define MAXN 50 + 10

char s[MAXN];
int neg[MAXN];

int c2i(char c) { return c-'0'; }

int is_num(char c){
	if(c == '+' || c == '*' || c == '/') return 0;
	return 1;
}

int is_sub(char c){ 
	if(c == '-') return 1;
	else return 0;
}

int calc (int a, int b, char c){
	int result;
	switch(c){
		case '+':
			result = a+b;
			break;
		case '-':
			result = a-b;
			break;
		case '*':
			result = a*b;
			break;
		case '/':
			result = a/b;
			break;
	}
	return result;
}

int main(void)
{

#ifdef DEBUG
	freopen("1_C_in.txt","r",stdin);
	freopen("1_C_out.txt","w",stdout);
#endif

	while(scanf("%s", s) != EOF){

		int len = strlen(s);

		// if (len == 0) {printf("0\n"); continue;}
		
		if (len == 1 && is_num(s[0])) {printf("%c\n", s[0]); continue;}
		
		if(len == 2 && is_sub(s[0])) {printf("-%c\n", s[1]); continue;}

		// if(!is_num(s[0])) {printf("0\n"); continue;}
		 
		memset(neg,0,sizeof(neg));

		if(is_sub(s[0])) neg[0] = 1;

		for(int i=1; i<len-2;i++)
			if(!is_num(s[i]) && is_sub(s[i+1]))
				neg[i+1] = 1;

		int index = 0;
		int a, b;
		char exp;
		if(neg[index]){
			index ++;
			a = -c2i(s[index]);
			index ++;
		}else{
			a = c2i(s[index]);
			index ++;
		}

		exp = s[index];
		index ++;
		
		if(neg[index]){
			index ++;
			b = -c2i(s[index]);
			index ++;
		}else{
			b = c2i(s[index]);
			index ++;
		}

		int result = calc(a, b, exp);

		if(index == len) {printf("%d\n", result); continue;}

		for(int i=index; i<len-1; i++){
			if(neg[i+1]){
				result = calc(result, -c2i(s[i+2]), s[i]);
				i+=2;
			}
			else{
				result = calc(result, c2i(s[i+1]), s[i]);
				i++;
			}
		}

		printf("%d\n", result);
	}


	return 0;
}