#include<iostream>
#include<algorithm>
#include<cstdio>

using namespace std;

int main(int argc, char const *argv[])
{
	int a,b;
	int n;
	scanf("%d", &n);
	while(n --){
		scanf("%d %d", &a, &b);
		printf("%d\n", a + b);
	}
	return 0;
}
