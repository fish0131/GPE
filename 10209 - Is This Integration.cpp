#include<bits/stdc++.h>
using namespace std;

//��l���n�G�����(ABCD)-2*1/12��(AED�BBCE)-���T����(ABE)�C

//�I�I���n�G�����(ABCD)-1/4��(ABD)-2*��l���n�C

//�׽u���n�G�����(ABCD)-4*�Ӥl���n-4�I�I���n�C

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
