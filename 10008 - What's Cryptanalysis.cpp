#include<bits/stdc++.h>
using namespace std;

// �����C�Ӧr���O�_���^��r���A�Q��toupper�N�r�����ܬ��j�g�s��b�}�C���Alen�ΨӺ��`�r����

int main() {
	int n, len = 0;
	int count[100] = {0};
	cin >> n;
	cin.ignore();
	while(n--) {
		string s;
		getline(cin, s);
		for(int i=0; i<s.length(); i++) {
			if((s[i]>='a' && s[i]<='z') || (s[i]>='A' && s[i]<='Z')){
                len++;
                count[toupper(s[i])]++;
            }
		}
	}
	for(int j=len; j>=1; j--) {
		for(char c='A'; c<='Z'; c++) {
			if(count[c] == j) cout << c << " " << count[c] << endl;
		}
	}
}
