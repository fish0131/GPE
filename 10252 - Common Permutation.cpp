//#include<bits/stdc++.h>
//using namespace std;
//
//int main() {
//	string a, b;
//	array<int, 26> cnta = {0}, cntb = {0};
//	while(cin >> a >> b) {
//		for(int i=0; i<a.length(); i++) {
//			cnta[a[i]-'a']++;
//		}
//		for(int i=0; i<b.length(); i++) {
//			cntb[b[i]-'a']++;
//		}
//		for (int i = 0; i < 26; i++) {
//		    for (int j = min(cnta[i], cntb[i]); j > 0; j--) {
//		        cout << (char)('a' + i);
//		    }
//		}
//	}
//	return 0;
//}

#include<bits/stdc++.h>
using namespace std;

int main() {
    string a, b;
    while (cin >> a >> b) {
        array<int, 26> cnta = {0}, cntb = {0};
        for (char c : a) cnta[c - 'a']++;
        for (char c : b) cntb[c - 'a']++;
        for (int i = 0; i < 26; i++) {
            cout << string(min(cnta[i], cntb[i]), 'a' + i);
        }
        cout << "\n";
    }
}
