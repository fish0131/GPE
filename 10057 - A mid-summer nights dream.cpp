#include<bits/stdc++.h>
using namespace std;

int main() {
	int t;
	while(cin >> t) {
		int a[t];
		for(int i=0; i<t; i++) cin >> a[i];
		sort(a, a+t);
		
		// t琌案计い计Τㄢ
		// t琌计い计Τ
		int mid1 = a[(t-1)/2];
        int mid2 = a[t/2];
        int ans = 0;
		
		for (int i=0; i<t; i++){
            if (a[i] == mid1 || a[i] == mid2) ans++;
        }
		
		cout << mid1 << " " << ans << " " << mid2 - mid1 + 1 << endl;
	}
	return 0;
}
