#include <bits/stdc++.h>
using namespace std;

long long a[55];

void parsing(const string &s) {
    int sign = 1, m = 0;
    char pos = 0;
    int i = 1;

    // �ѪR�e�����Ʀr (�i�঳�t��)
    if (s[i] == '-') {
        sign = -1;
        i++;
    }
    for (; i < (int)s.size(); i++) {
        if (isdigit(s[i])) {
            m = m * 10 + (s[i] - '0');
        } else {
            pos = s[i]; // �O���B��Ÿ�
            break;
        }
    }
    m *= sign;

    if (pos == '+') {
        parsing(s.substr(i + 1)); // ���j�B�z��b�q
        long long d = a[0];
        a[0] = m;
        for (int j = 1; j < 50; j++) {
            long long t = a[j];
            a[j] = a[j - 1] + d;
            d = t;
        }
    } 
	else if (pos == '*') {
        parsing(s.substr(i + 1));
        a[0] *= m;
        for (int j = 1; j < 50; j++)
            a[j] = a[j] * a[j - 1];
    } 
	else {
        for (int j = 0; j < 50; j++)
            a[j] = m;
    }
}

int main() {
    //ios::sync_with_stdio(0), cin.tie(0);

    string s;
    int n;
    while (cin >> s >> n) {
        memset(a, 0, sizeof(a));
        parsing(s);
        for (int i = 0; i < n; i++) {
            cout << a[i];
            if (i < n - 1) cout << " ";
        }
        cout << '\n';
    }
    return 0;
}
