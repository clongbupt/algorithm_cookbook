#include<iostream>

using namespace std;

void move (int n, char x, char y)
{
	cout << "move " << n << " from " << x << " to " << y << endl;
}

void Hannoi (int n, char a, char b, char c)
{
	if (n == 1)
		move (n, a, c);
	else
	{
		Hannoi(n - 1, a, c, b);
		move(n, a, c);
		Hannoi(n - 1, b, a, c);
	}
}

int main ()
{
	
	int n;
	cin >> n;
	Hannoi (n, 'a', 'b', 'c');
	
	return 0;
}