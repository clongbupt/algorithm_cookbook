#include<iostream>
#include<cstdio>
#include<cstring>

using namespace std;

#define MAX 27

void solve(int n, char *s1, char *s2)
{
	if (n <= 0) return;
	int p = strchr(s2, s1[0]) - s2;
	solve(p, s1 + 1, s2);
	solve( n - p - 1, s1 + p + 1, s2 + p + 1);
	printf("%c", s1[0]);
}

int main()
{

	char s1[MAX], s2[MAX], ans[MAX];
	
	while (scanf("%s%s", s1, s2) != EOF)
	{
		int n = strlen(s1);
		solve(n, s1, s2);
		printf("\n");
	}
	return 0;
}
