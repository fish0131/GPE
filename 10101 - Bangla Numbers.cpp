#include<bits/stdc++.h>
using namespace std;

void num(long long n) {
	if(n>=10000000){
        num(n/10000000);
        cout<<" kuti";
        n%=10000000;
    }
    if(n>=100000){
        num(n/100000);
        cout<<" lakh";
        n%=100000;
    }
    if(n>=1000){
        num(n/1000);
        cout<<" hajar";
        n%=1000;
    }
    if(n>=100){
        num(n/100);
        cout<<" shata";
        n%=100;
    }
    if(n){
        cout<<" "<<n;
    }
}

int main() {
	long long int n, count = 1;
	while(cin >> n) {
		// setw(4)為將寬度設為4
		cout << setw(4) << count++ <<".";
        if(n){
            num(n);
        }
        else{
            cout << " 0";
        }
        cout << endl;
	}
	return 0;
}
