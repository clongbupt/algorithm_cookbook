#include<iostream>
#include<cmath>
#include<algorithm>
#include<iomanip>
using namespace std;
struct point{
	double x;
	double y;
}Point[100];
bool operator<(const point& a, const point& b) {
	double x1 = a.x - Point[0].x;
	double y1 = a.y - Point[0].y;
	double x2 = b.x - Point[0].x;
	double y2 = b.y - Point[0].y;
	
	double r = x1*y2 - x2*y1;
	return r > 0;
}
double areaofp(int n) {
	if(n < 3)  return 0;
	double s = Point[0].y * (Point[n-1].x - Point[1].x);
	for(int i = 1; i < n; i++) {
		s += Point[i].y * (Point[i-1].x - Point[(i+1)%n].x);
	}
	return s/2;
}
int main() {
	int n;
	while(cin >> n) {
		for(int i = 0; i < n; i++) {
			cin >> Point[i].x >> Point[i].y;
		}
		sort(Point, Point+n);
		double result = areaofp(n);
		cout <<fixed  <<setprecision(1) << result << endl;
	}
}