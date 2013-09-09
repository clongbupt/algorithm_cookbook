#include "stdio.h"
#include "stdlib.h"
#include "string.h"

char * reverse(char *s)
{
	// 将q指向字符串的最后一个字符
	char *q = s;
	while (*q++) ;
	q -=2;

	// c++
	//char *p = new char[sizeof(char)*(q-s+2)];
	// c
	char *p = (char *)malloc(sizeof(char)*(q-s+2));
	memset(p,0,sizeof(char));


	char *r = p;
 
	while (q >= s)
		*p++ = *q--;
	*p = '\0';

	return r;
}

char* reverse2(char* s)
{
    // p指向字符串头部
    char* p = s ;

    // q指向字符串尾部
    char* q = s ;
    while( *q )
        ++q ;
    q -- ;

    // 交换并移动指针，直到p和q交叉
    while(q > p)
    {
        char t = *p ;
        *p++ = *q ;
        *q-- = t ;
    }

    // 原地逆序
    // while(q > p)
    // {
    // 	*p = *p ^ *s;
    // 	*s = *p ^ *s;
    // 	*p = *p-- ^ s ++;
    // }

    return s ;
}


char a[100] = "abcd";

int main(int argc, char const *argv[])
{
	
	printf("%s\n",reverse(a));

	printf("%s\n", reverse2(a));

	return 0;
}