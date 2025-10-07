#include <bits/stdc++.h>
using namespace std;

int n;
int prime[3501], visit[35000] = {0};

int main() {
    while(cin >> n && n) {
    	int size = 0;
    	for(int i=2; i<35000; i++) {
    		if(visit[i] == 0) {
    			prime[size++] = i;
    			for(int j=i*i; j<35000; j+=i) visit[j] = 1;
			}
		}
		int ans = 0;
		for(int i=2; i<=n; i++)  {
			ans = (ans + prime[n-i]) % i;
		}
		cout << ans+1 << '\n';
	}
}


//#include <bits/stdc++.h>
//using namespace std;
//
//const int MAXN = 35000;
//int prime[3501];        // 存質數
//bool visit[MAXN] = {0}; // 用來做篩法
//
//// 只需要篩一次質數
//void sieve() {
//    int size = 0;
//    for (int i = 2; i < MAXN; i++) {
//        if (!visit[i]) {
//            prime[size++] = i; // 存下質數
//            for (long long j = 1LL * i * i; j < MAXN; j += i) {
//                visit[j] = true;
//            }
//        }
//    }
//}
//
//int main() {
//    ios::sync_with_stdio(false);
//    cin.tie(nullptr);
//
//    sieve(); // 先產生質數表
//
//    int n;
//    while (cin >> n && n) {
//        int ans = 0;
//        // Josephus recurrence:
//        // J(m, k) = (J(m-1, k) + k) % m
//        // 這裡用 prime[n-i] 作為 k
//        for (int i = 2; i <= n; i++) {
//            ans = (ans + prime[n - i]) % i;
//        }
//        cout << ans + 1 << "\n"; // 轉成 1-based index
//    }
//    return 0;
//}
