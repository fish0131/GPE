#include<bits/stdc++.h>
using namespace std;

// �P�_�O�_������@�ӦX�k��L�A�ϱoS1�MS2���i�H��Love�����C��Y
// S1 �O L �����ơC
// S2 �O L �����ơC
// L �O S1 �M S2 �����]�ơC

// �Q������۰��k�p��S1 �M S2 ���̤j���]�ơA�p�G�j�� 1 (�u���@�Ӧ줸���r�ꤣ�X�k)�A��ܦ��ѡC

int GCD(int a, int b){
    return b == 0 ? a : GCD(b, a % b);
}

int main() {
	int n, cnt = 1;
	cin >> n;
	while(n--) {
		string s1, s2;
		int n1 = 0, n2 = 0;
		cin >> s1 >> s2;
		for(int i=0; i<s1.length(); i++) {
			n1 *= 2;
			n1 += s1[i] - '0';
		}
		for(int i=0; i<s2.length(); i++) {
			n2 *= 2;
			n2 += s2[i] - '0';
		}
		if(GCD(n1, n2) != 1) cout << "Pair #" << cnt << ": All you need is love!" << endl;
		else cout << "Pair #" << cnt << ": Love is not all you need!" << endl;
		cnt ++;
	}
}
