#include "cstdio"

using namespace std;

int main(int argc, char const *argv[])
{
	int arr[] = {6,7,8,9};
	int * ptr = arr;

	*(ptr++) += 123;   // ptr++
	printf("%d%d\n", *ptr, *(++ptr));


	int i = 1;
	int INF = 2147480000;
	double d = 1.0f;

	float f = 1.0f;

	// printf("%f\n",f);
	// printf("%f\n", -f);
	// printf("%f\n", -(-f));

	printf("%d\n", (int)(float)i);
	printf("%d\n", (int)(float)INF);

	int temp =  (int)d;
	printf("%d\n", temp);

	return 0;
}