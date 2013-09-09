#include<iostream>
#include<algorithm>
#include<cstdio>

using namespace std;

int main(int argc, char const *argv[])
{
	int n;
	while(scanf("%d", &n) != -1 && n ) {
		int temp,sum = 0;
		for (int i = 0; i < n; i ++)
		{
			scanf("%d", &temp);
			sum += temp;
		}
		printf("%d\n", sum);
	}
	return 0;
}
