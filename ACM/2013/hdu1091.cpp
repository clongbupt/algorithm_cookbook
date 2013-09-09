#include<iostream>
#include<algorithm>
#include<cstdio>

using namespace std;

int main(int argc, char const *argv[])
{
	int a,b;
	while(scanf("%d %d", &a, &b) != -1 && (a || b)){
		printf("%d\n", a + b);
	}
	return 0;
}
