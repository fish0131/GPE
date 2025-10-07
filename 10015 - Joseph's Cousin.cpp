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
//int prime[3501];        // �s���
//bool visit[MAXN] = {0}; // �ΨӰ��z�k
//
//// �u�ݭn�z�@�����
//void sieve() {
//    int size = 0;
//    for (int i = 2; i < MAXN; i++) {
//        if (!visit[i]) {
//            prime[size++] = i; // �s�U���
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
//    sieve(); // �����ͽ�ƪ�
//
//    int n;
//    while (cin >> n && n) {
//        int ans = 0;
//        // Josephus recurrence:
//        // J(m, k) = (J(m-1, k) + k) % m
//        // �o�̥� prime[n-i] �@�� k
//        for (int i = 2; i <= n; i++) {
//            ans = (ans + prime[n - i]) % i;
//        }
//        cout << ans + 1 << "\n"; // �ন 1-based index
//    }
//    return 0;
//}
