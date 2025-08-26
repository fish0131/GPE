#include<bits/stdc++.h>
using namespace std;
const int maxn = 10000+5;
int prime[maxn] = {0};  // 0 means prime, 1 means not prime
vector <int> v;

int main() {
	// ios::sync_with_stdio(0),cin.tie(0);
    
    for (int i = 2; i * i <= maxn; i++) {
        if (prime[i] == 0) {  // If i is prime
            for (int j = i * i; j <= maxn; j += i) {
                prime[j] = 1;  // Mark as non-prime
            }
        }
    }
    
     // Collect all primes into v
    for (int i = 2; i < maxn; i++) {
        if (prime[i] == 0) v.push_back(i);
    }
    
	int n;
	while(cin >> n && n) {
		int count = 0;
		for (int i = 0; v[i] <= n; i++){    // �T�|�u�_�l��ơv
            int sum = 0;
            for (int j = i; sum < n; j++){  // �q�_�l��Ʃ���[
                sum += v[j];
                if (sum == n) {
                    count++;
                    break;
                }
            }
        }
        cout << count << endl;
	}
	return 0;
} 
