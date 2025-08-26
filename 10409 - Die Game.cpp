#include<bits/stdc++.h>
using namespace std;

int main() {
	int n;
	while(cin >> n && n) {
		map <string, int> mp;
        mp["top"] = 1;
        mp["north"] = 2;
        mp["west"] = 3;
        mp["east"] = 4;
        mp["south"] = 5;
        mp["bottom"] = 6;
		
		while(n--) {
			string s;
			cin >> s;
			
			if(s == "north") {
				int tmp = mp["north"];
				mp["north"] = mp["top"];
				mp["top"] = mp["south"];
				mp["south"] = mp["bottom"];
				mp["bottom"] = tmp;
			}
			else if(s == "south") {
				int tmp = mp["south"];
				mp["south"] = mp["top"];
				mp["top"] = mp["north"];
				mp["north"] = mp["bottom"];
				mp["bottom"] = tmp;
			}
			else if(s == "east") {
				int tmp = mp["east"];
				mp["east"] = mp["top"];
				mp["top"] = mp["west"];
				mp["west"] = mp["bottom"];
				mp["bottom"] = tmp;
			}
			else if(s == "west") {
				int tmp = mp["west"];
				mp["west"] = mp["top"];
				mp["top"] = mp["east"];
				mp["east"] = mp["bottom"];
				mp["bottom"] = tmp;
			}
		}
		cout << mp["top"] << endl;
	}
	return 0;
}
