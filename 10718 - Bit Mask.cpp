#include <bits/stdc++.h>
using namespace std;

unsigned int N , L ,U;

int main() {
	//ios::sync_with_stdio(0), cin.tie(0);
    while(cin >> N >> L >> U) {
    	unsigned int ans = 0;
    	// �q�̰��� (bit 31) ��̧C�� (bit 0) �@�Ӥ@�ӨM�w ans ���C�� bit
    	// �n�����G N OR ans �̤j �� �����] 1 �N�ɶq�] 1�C
    	for(int i=31; i>=0; i--) {
    		if ((ans | (1<<i)) > U ) continue;
	        if ((ans | (1<<i)) <= L || !(N & (1 << i))){
	            ans |= (1 << i);
	        }
		}
		cout << ans << '\n';
	}
}
