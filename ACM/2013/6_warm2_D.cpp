#define DEBUG

#include "cstring"
#include "cstdio"
#include "ctime"
#include "cmath"
#include "algorithm"
#include "iostream"

using namespace std;

#define MAXN 1000 + 10

char s[MAXN];
int f[MAXN];

int c2i(char c){
	return c-'0';
}

int main(void)
{

#ifdef DEBUG
	freopen("6_warm2_D_in.txt","r",stdin);
	freopen("6_warm2_D_out.txt","w",stdout);
#endif

	int cases;

	int len;

	scanf("%d", &cases);
	while(cases --){

		memset(f,0,sizeof(f));

		scanf("%s", s);
		len = strlen(s);

		f[len-1] = 1;

		if(len == 1){
			printf("%d\n", f[len-1]);
			continue;
		}


		if(c2i(s[len-2]) == 0) f[len-2] = 1;
		else f[len-2] = 2;

		if(len == 2){
			printf("%d\n", f[len-2]);
			continue;
		}

		if (c2i(s[len-3]) == 0) f[len-3] = f[len-2];
		else if(c2i(s[len-3]) > 2) f[len-3] = f[len-2] + f[len-1];
		else if(c2i(s[len-3]) == 2 && c2i(s[len-2]) > 5) f[len-3] = f[len-2] + f[len-1];
		else if (c2i(s[len-3]) == 2 && c2i(s[len-2]) == 5 && c2i(s[len-1]) > 5) f[len-3] = f[len-2] + f[len-1];
		else f[len-3] = f[len-2] + f[len-1] + 1;

		if(len == 3){
			printf("%d\n", f[len-3]);
			continue;
		}

		int flag1, flag2;
		for(int i=len-4; i>=0; i--)
		{
			flag1 = flag2 = 1;

			if(c2i(s[i]) == 0 || c2i(s[i]) > 2) flag1 = 0;
			else if (c2i(s[i]) == 2 && c2i(s[i+1]) > 5) flag1 = 0;
			else if (c2i(s[i]) == 2 && c2i(s[i+1]) == 5 && c2i(s[i+2]) > 5) flag1 = 0;

			if(c2i(s[i]) == 0 && c2i(s[i+1]) == 0) flag2 = 0;

			f[i] = flag1*f[i+3] + flag2*f[i+2] + f[i+1];
		}

		printf("%d\n", f[0]);
	}

	return 0;
}