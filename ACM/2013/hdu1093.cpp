#include<cstdio>

using namespace std;

int main(int argc, char const *argv[])
{
	int n;
	scanf("%d", &n);
	while( n -- ) {
		int num;
		scanf("%d", &num);
		int temp,sum = 0;
		for (int i = 0; i < num; i ++)
		{
			scanf("%d", &temp);
			sum += temp;
		}
		printf("%d\n", sum);
	}
	return 0;
}
