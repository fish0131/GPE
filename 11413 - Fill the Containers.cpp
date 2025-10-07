#include <bits/stdc++.h>
using namespace std;

// �g�� + �G���j�M

int n, m;
int c[1001];

int container(int size, int value) {
	int sum = 0, cnt = 1;
	for(int i=0; i<n; i++) {
		if(c[i] > value) return size;
		else if(sum + c[i] > value) {
			sum = c[i];
			cnt++;
		}
		else sum += c[i];
	}
	return cnt;
}

int main() {
    while(cin >> n >> m) {
    	int sum = 0, maxn = 0;
    	for(int i=0; i<n; i++) cin >> c[i];
    	for(int i=0; i<n; i++) {
    		sum += c[i];
    		if(c[i] > maxn) maxn = c[i];
		}
		
		int l = maxn, r = sum, mid = 0;
		while(l < r) {
			mid = (l + r) / 2;
			if(container(n, mid) <= m) r = mid; // �� container_size(...) <= m �ɡA�N��e�q mid �����A�i�������p�d��C
			else l = mid + 1;                   // �_�h�A�e�q���� �� ���k���C
		}
		cout << l << '\n';
	}
}
