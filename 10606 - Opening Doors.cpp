//#include<bits/stdc++.h>
//using namespace std;
//
//const int N = 10105;
//int sqrt_num[N] = {0};
//int n;
//
//int main() {
//	for(int i=0; i<N; i++) {
//		int res = sqrt(i);
//		if(res * res == i) sqrt_num[i] = 1;
//	}
//	while(cin >> n && n) {
//		for(int i=n; i>=0; i--) {
//			if(sqrt_num[i] == 1) {
//				cout << i << '\n';
//				break;
//			}
//		}
//	}
//} 

#include <bits/stdc++.h>
using namespace std;

int main() {

    int n;
    while (cin >> n && n) {
        int r = sqrt(n);     // 最大整數平方根
        cout << r * r << '\n';
    }
}
