#include "cstring"
#include "cstdio"
#include "iostream"

using namespace std;

int main(int argc, char const *argv[])
{
	
	char s[] = "aabbcc";

	printf("%s\n", s);
	memmove(s+2, s, 4);
	printf("%s\n", s);
	return 0;
}