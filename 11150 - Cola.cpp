#include<bits/stdc++.h>
using namespace std;

//�Ĥ@����n�~������n/3�i��
//�ĤG���A��n/3�i�ֲ���n/3�Ų~�A��n/3���i��
//�̦�����
//N = n + (n/3) + (n/9) +...
//N = n * (1/3 + 1/9 + 1/27 +...) 
//N = n * (1 / (1-1/3)) = n * 1.5

int main() {
	int n;
	while(cin >> n) {
		cout << int(n*1.5) << endl;
	}
	return 0;
}
