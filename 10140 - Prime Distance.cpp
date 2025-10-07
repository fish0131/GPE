#include<bits/stdc++.h>
using namespace std;

const int maxn = 1000000+5;
int prime[maxn] = {0};
vector<int> v;

long long L, U;

vector<long long> segmentedSieve(long long L, long long U) {
    vector<char> isPrime(U - L + 1, 0);
    if (L == 1) isPrime[0] = 1;

    for (int p : v) {
        if (1LL * p * p > U) break;
        long long start = max(1LL * p * p, ((L + p - 1) / p) * 1LL * p);
        for (long long j = start; j <= U; j += p) {
            isPrime[j - L] = 1;
        }
    }

    vector<long long> primes;
    for (long long i = L; i <= U; i++) {
        if (!isPrime[i - L]) primes.push_back(i);
    }
    return primes;
}

int main() {
	for(int i=2; i*i <= maxn; i++) {
		if(prime[i] == 0) {
			for(int j=i*i; j<=maxn; j+=i) {
				prime[j] = 1;
			}
		}
	}
	
	for(int i=2; i<maxn; i++) {
		if(prime[i] == 0) v.push_back(i);
	}
	
	while(cin >> L >> U) {
		
		vector<long long> primes = segmentedSieve(L, U);
        if (primes.size() < 2) {
            cout << "There are no adjacent primes.\n";
            continue;
        }
        
        int min_d = INT_MAX, max_d = 0;
        int c1, c2, d1, d2;
        
        for (int i = 0; i < (int)primes.size()-1; i++) {
            long long a = primes[i];
            long long b = primes[i + 1];
            long long diff = b - a;
            if (diff < min_d) {
                min_d = diff;
                c1 = a; 
				c2 = b;
            }
            if (diff > max_d) {
                max_d = diff;
                d1 = a; 
				d2 = b;
            }
        }

        cout << c1 << "," << c2 << " are closest, " << d1 << "," << d2 << " are most distant.\n";
	}
}
