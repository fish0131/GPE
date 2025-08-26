#include<bits/stdc++.h>
using namespace std;

int t, h, m, hh, mm;
char ch;

int main() {
	//ios::sync_with_stdio(0), cin.tie(0);
	cin >> t;
	while(t--) {
		cin >> h >> ch >> m;
		int minutes = 60 * h + m;
		while(1) {
			minutes++;
			if(minutes >= 1440) minutes = 0;
			hh = minutes / 60;
			mm = minutes % 60;
			if(hh == 0) {
				if(mm < 10 || (mm / 10 == mm % 10)) break;
			}
			else if(hh < 10) {
				if(hh == mm % 10) break;
			}
			else {
				if((hh % 10) * 10 + (hh / 10) == mm) break;
			}
		}
		cout << setw(2) << setfill('0') << hh << ":" << setw(2) << setfill('0') << mm << '\n';
	}
}
