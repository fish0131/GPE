#include<bits/stdc++.h>
using namespace std;

int M, N;

int main(){
    while(cin >> M >> N) {
    	
    	vector<vector<int>> lists(M);
    	
    	for(int i=0; i<M; i++) {
    		lists[i].resize(N-i);
    		for(int j=0; j<N-i; j++) {
    			cin >> lists[i][j];
			}
		}
		
		for(int i=0; i<M-1; i++) {
			int x = 0;
			for(int n: lists[i]) x ^= n;  // XOR ���ʽ�G �ۦP���Ʒ|��P (a ^ a = 0)�A�u�ѤU���Ӥֱ�����
			for(int n: lists[i+1]) x ^= n;
			cout << x << '\n';
		}
	}
}
