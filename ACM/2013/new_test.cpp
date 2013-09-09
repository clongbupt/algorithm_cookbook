#include "cstdio"
#include "cstring"
#include "iostream"

using namespace std;

// void Test(char * str) {  
// 	cout <<sizeof(str) << endl;
// } 

// void Test2(char str[]) {  
// 	cout <<sizeof(str) << endl;
// } 

class A{
};

class A2{
};

class B : public A{};

class C : public virtual B{};

class D : public A, public A2{};


class E { float f;};
class E1 { float f;char p;};
class E2 { float f;char p; int d[3];};


class E4 { bool a;int d; bool b;};
class E5 { bool a;};
class E6 { bool a; short s; short s2;};
class E7 { bool a;int d; };

class E8 { bool a;bool b; int d;};
class E9 { int d;bool a;bool b; };

int test (){
	// return "microsoft" == "microsoft";
		char *str = "microsoft";
		return str == "microsoft";
}

int main() {


	// char s[100];
	// printf("%d\n",sizeof(s));
	// memset(s, '\0', sizeof(s));

	// char str[1000];
	// cout << sizeof(str) << endl;

	// Test(str);
	// Test2(str);
	 
	// cout << sizeof(A) << endl;
	// cout << sizeof(B) << endl;
	// cout << sizeof(C) << endl;
	// cout << sizeof(D) << endl;

	// cout << sizeof(E) << endl;
	// cout << sizeof(E1) << endl;
	// cout << sizeof(E2) << endl;

	// cout << sizeof(E4) << endl;
	// cout << sizeof(E5) << endl;
	// cout << sizeof(E6) << endl;
	// cout << sizeof(E7) << endl;

	// cout << sizeof(E8) << endl;
	// cout << sizeof(E9) << endl;

	// int v[2][10] = {{1,2,3,4,5,6,7,8,9,10},
	// 			{11,12,13,14,15,16,17,18,19,20}};
	// int (*a)[10] = v;

	// cout << **a << endl;
	// cout << **(a+1) << endl;
	// cout << *(*a+1) << endl;
	// cout << *(a[0] + 1) << endl;
	// cout << *(a[1]) << endl;

	// int b[3] = {1,5,4};

	// cout << *b << endl;
	// // cout << * << endl;

	// cout << *b+1 << endl;
	// cout << *(b+1) << endl;

	// int *ptr = (int *)(&b + 1);
	// cout << *(ptr - 1) << endl;

	// int x = 10;
	// int y = 10;
	// int z = 10;
	// x = x++;
	// y = ++y;
	// cout << z++ << endl;
	// cout << x << endl;
	// cout << y << endl;

	cout << test() << endl;
	return 0;  
}