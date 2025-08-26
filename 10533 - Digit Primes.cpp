#include<bits/stdc++.h>
using namespace std;

int bitNum(int n) {
	int sum = 0;
	while(n > 0) {
		sum += n % 10;
		n /= 10;
	}
	return sum;
}

// Tooooooooo slow
//bool isPrime(int n) {
//	if(n==0 || n==1) return false;
//    for (int i = 2; i<int(sqrt(n)+1); i++) {
//        if (n % i == 0) return false;
//    }
//    return true;
//}

const int MAX = 1000000;
int prime[MAX + 1] = {0};  // 0 means prime, 1 means not prime
int digit_prime_count[MAX + 1] = {0};  // Prefix sum of digit primes

// Sieve of Eratosthenes to mark prime numbers
void sieve() {
    prime[0] = prime[1] = 1;  // 0 and 1 are not prime
    for (int i = 2; i * i <= MAX; i++) {
        if (prime[i] == 0) {  // If i is prime
            for (int j = i * i; j <= MAX; j += i) {
                prime[j] = 1;  // Mark as non-prime
            }
        }
    }
}

// Precompute the count of digit primes
void preprocess_digit_primes() {
    sieve();
    for (int i = 1; i <= MAX; i++) {
        digit_prime_count[i] = digit_prime_count[i - 1];  // Carry forward the previous count
        if (prime[i] == 0 && prime[bitNum(i)] == 0) {  // Check if both i and digit sum are prime
            digit_prime_count[i]++;
        }
    }
}

int main() {
	preprocess_digit_primes();  // Precompute prime numbers and digit primes
	
	int T;
	long int t1, t2;
	cin >> T;
	while(T--) {
		cin >> t1 >> t2;
		cout << digit_prime_count[t2] - digit_prime_count[t1-1] << endl; 
	}
	return 0;
}
