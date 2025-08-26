#include<bits/stdc++.h>
using namespace std;

int a, b;

// �X�i�ڴX���o�t��k
// �^�� gcd(a,b)�A�óz�L x,y �p��X a*x + b*y = gcd(a,b)
int ExtendedGCD(int a, int b, int &x, int &y) {
    if (b == 0) {
        x = 1;  // a*1 + b*0 = a
        y = 0;
        return a;
    }
    int x1, y1;
    int d = ExtendedGCD(b, a % b, x1, y1);
    x = y1;
    y = x1 - (a / b) * y1;
    return d;
}

int main() {
	//ios::sync_with_stdio(0), cin.tie(0);
	
	while(cin >> a >> b) {
		int x, y;
        int r = ExtendedGCD(a, b, x, y);
        cout << x << " " << y << " " << r << '\n';
	}
}

