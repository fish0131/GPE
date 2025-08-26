#include<bits/stdc++.h>
using namespace std;

//第一輪用n瓶空罐換n/3可樂
//第二輪再用n/3可樂產生n/3空瓶，換n/3的可樂
//依此類推
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
