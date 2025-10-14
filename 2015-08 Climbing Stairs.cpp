//#include <bits/stdc++.h>
//using namespace std;
//
//int n, f[105];
//
//int main() {
//	f[0] = 1;
//	f[1] = 2;
//	for(int i=2; i<100; i++) {
//		f[i] = f[i-1] + f[i-2];
//	}
//	while(cin >> n) {
//		cout << f[n-1] << '\n';
//	}
//}


#include <bits/stdc++.h>
using namespace std;

int n;

int f(int x) {
	if (x == 1) return 1;
    int a = 1, b = 2;
    for (int i = 3; i <= x; i++) {
        int c = a + b;
        a = b;
        b = c;
    }
    return b;
}

int main() {
	while(cin >> n) {
		cout << f(n) << '\n'; 
	}
}
