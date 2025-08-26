#include <bits/stdc++.h>
using namespace std;

double vt ,v0;

int main() {
	ios::sync_with_stdio(0), cin.tie(0);
    while (cin >> vt >> v0 && vt && v0){
    	int best = 0;
		double maxlen = 0;
		bool same = false;       // 是否有相同最大值
		
        for(int i=1; i<=vt; i++) {
        	double v = vt / i;
        	if(v <= v0) break;
        	
        	double d = 0.3 * sqrt(v - v0);
        	double len = d * i;
        	
        	if (fabs(len - maxlen) <= 1e-9) { // 有兩個相同最大值
                same = true;
            }
			else if (len > maxlen) {
                maxlen = len;
                best = i;
                same = false;
            }
		}
		if(same) cout << 0 << '\n';
		else cout << best << '\n'; 
    }
}
