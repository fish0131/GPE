#include<bits/stdc++.h>
using namespace std;

bool cmp(string x, string y){
    string a = x + y;
    string b = y + x;
    return a > b; //�j��:�j�ƨ�p
}
 
int main(){
    int n;
    while(cin >> n){
    	string a[n];
        if(n == 0) break;
        for(int i=0; i<n; i++) cin >> a[i];
        sort(a, a+n, cmp);
        for(int i=0; i<n; i++) cout << a[i];
        cout << '\n';
    }
    return 0;
}
