#include<bits/stdc++.h>
using namespace std;

int n;
double x;

int main() {
	while(cin >> n && n) {
		int a[n], sum = 0;
		for(int i=0; i<n; i++) {
			cin >> x;
			a[i] = (int)round(x*100);
			sum += a[i];
		}
		sort(a, a+n);
		int avg = sum / n;
		int remain = sum % n;
		// �]���n�̤p�ƥ洫���B�A�]���O���ǥ��ӴN�I�̦h�� r �ӤH�̫�]�h��I 1 ����
		double ans = 0.0;
		for (int i=n-1; i>=n-remain; i--){
            ans += abs(a[i] - avg - 1);
        }
        for (int i=n-remain-1; i>=0; i--){
            ans += abs(a[i] - avg);
        }
        cout << "$" << fixed << setprecision(2) << ans / 200 << '\n';
	}
}
