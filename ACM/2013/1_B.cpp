#include<iostream>
using namespace std;
int main() {
	
	int t;
	cin >> t;
	for(int i = 0; i < t; i++) {
		long long n;
		cin >> n;
		if(n == 2) 
			cout << "No" << endl;
		else if(n % 2 == 0)
			cout << "Yes" << endl;
		else 
			cout << "No" << endl;
		
	}
	return 0;
}