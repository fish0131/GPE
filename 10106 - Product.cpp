#include<bits/stdc++.h>
using namespace std;

string a, b;

int main() {
	while(getline(cin, a)) {
		getline(cin, b);
		
		int A[250] = {0}, B[250] = {0};
		for(int i=0; i<a.length(); i++) A[i] = a[a.length()-i-1] - '0';
		for(int i=0; i<b.length(); i++) B[i] = b[b.length()-i-1] - '0';
		
		int ans[501] = {0};
		
		// 逐位相乘並累加
        for (int i = 0; i < a.length(); i++) {
            for (int j = 0; j < b.length(); j++) {
                ans[i+j] += A[i] * B[j];
            }
        }
        
        int len = a.length() + b.length();
        
        // 處理進位
        for (int i = 0; i < len-1; i++) {
            if (ans[i] >= 10) {
                ans[i+1] += ans[i] / 10;
                ans[i] %= 10;
            }
        }
        
        // 輸出有可能都是0 
        while(len > 0 && ans[len] == 0) len--;
        
        // 特判 0
        if (len == 0 && ans[0] == 0) {
            cout << 0 << '\n';
            continue;
        }
        
		bool key = false;
		for(int i=len; i>=0; i--) {
			if(ans[i] != 0) key = true;
			if(key) cout << ans[i];
		}
		cout << '\n';
	}
} 
