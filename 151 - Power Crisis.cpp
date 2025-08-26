#include<bits/stdc++.h>
using namespace std;

////////////////////////////////
//////  Josephus problem  //////
////////////////////////////////

// ����
// J(1, m) = 0
// J(k, m) = (J(k-1, m) + m) % k 

int n, m;

int main() {
	//ios::sync_with_stdio(0), cin.tie(0);
	while(cin >> n && n) {
		n--;
		for(m=1; m<n; m++) {
			int survivor = 0;
			for(int j=1; j<=n; j++) {
				survivor = (survivor + m) % j;
			}
			if (survivor == 11) break;
		}
		cout << m << '\n';
	}
}



// Josephus �C������
//void simulate(int n, int m) {
//    vector<int> circle;
//    for (int i = 1; i <= n; i++) circle.push_back(i);
//
//    int idx = 0; // �_�l��m
//    cout << "��l: ";
//    for (int x : circle) cout << x << " ";
//    cout << "\n";
//
//    while (circle.size() > 1) {
//        idx = (idx + m - 1) % circle.size(); // �n�R�����H
//        cout << "�R�� " << circle[idx] << " -> ";
//        circle.erase(circle.begin() + idx);
//
//        for (int x : circle) cout << x << " ";
//        cout << "\n";
//    }
//
//    cout << "�̫�s����: " << circle[0] << "\n";
//}
//
//int main() {
//    int n = 17, m = 5;
//    cout << "=== ���� n=17, m=5 ===\n";
//    simulate(n, m);
//
//    return 0;
//}

