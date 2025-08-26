#include<bits/stdc++.h>
using namespace std;

//ち传Ω计 n 计计
	//n 计埃 1 ㎝ n ぇ
	//璝ㄤウ计 p玥ゲΤ计 n / p
	//璝 n Чキよ计玥 p = n / p计计ヘ计 (筿縊獹帝)
	//玥计计ヘ案计 (筿縊穞帝)

int main() {
	int n;
	while(cin >> n && n) {
		int factor = sqrt(n);
		if(factor*factor==n) cout << "yes" << endl;
		else cout << "no" << endl;
	}
	return 0;
}
