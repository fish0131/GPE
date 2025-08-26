#include<bits/stdc++.h>
using namespace std;

//格子面積：正方形(ABCD)-2*1/12圓(AED、BCE)-正三角形(ABE)。

//點點面積：正方形(ABCD)-1/4圓(ABD)-2*格子面積。

//斜線面積：正方形(ABCD)-4*個子面積-4點點面積。

int main() {
	double r;
	double PI = acos(-1);
	while(cin >> r) {
		double A = r*r - (r*r*PI)/6.0 - (r*(sqrt(3.0)/2.0*r)/2.0);
		double B = r*r - (r*r*PI)/4.0 - 2*A;
		double C = r*r - 4*A - 4*B;
		cout << fixed << setprecision(3) << C << " " << 4*B << " " << 4*A << endl;
	}
	return 0;
}
