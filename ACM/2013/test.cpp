#define DEBUG  
#include "cstdio" 
#include "algorithm"
#include "iostream"

using namespace std;

int main(int argc, char const *argv[])
{

	char unData[100];

	for(int i=0; i<100; i++)
		unData[i] = i;

	printf("0x%x\n", *unData);
	printf("0x%x\n", *((int*)unData));
	printf("0x%x\n", *(short *)unData);
	printf("0x%x\n", *((short *)((int*)unData+1)));
  
	return 0;

}