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
			for(int n: lists[i]) x ^= n;  // XOR 的性質： 相同的數會抵銷 (a ^ a = 0)，只剩下那個少掉的數
			for(int n: lists[i+1]) x ^= n;
			cout << x << '\n';
		}
	}
}
