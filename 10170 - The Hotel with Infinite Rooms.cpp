#include<bits/stdc++.h>
using namespace std;

int main() {
	int S;
	long int D, day, people;
	while(cin >> S >> D) {
		people = S;
		day = 1;
		while(D >= day) {
			day += people;
			people++;
		}
		people--;
		cout << people << endl;
	}
	return 0;
}
