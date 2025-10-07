#include <bits/stdc++.h>
using namespace std;

string s;

int evaluatePrefix(string s) {
    stack<int> st;
    vector<string> tokens;
    stringstream ss(s);
    string tok;
    while (ss >> tok) tokens.push_back(tok);

    for (int i = tokens.size() - 1; i >= 0; i--) {
        string t = tokens[i];
        if (isdigit(t[0]) || (t.size() > 1 && isdigit(t[1]))) st.push(stoi(t));
		else {
            // 遇到運算子，必須至少有兩個數字
            if (st.size() < 2) {
                cout << "illegal" << '\n';
        		return 0;
            }
            int o1 = st.top(); st.pop();
            int o2 = st.top(); st.pop();
            if (t == "+") st.push(o1 + o2);
            else if (t == "-") st.push(o1 - o2);
            else if (t == "*") st.push(o1 * o2);
            else if (t == "/") st.push(o1 / o2);
            else if (t == "%") st.push(o1 % o2);
            else {
                cout << "illegal" << '\n';
        		return 0;
            }
        }
    }

    // 結果必須只剩一個值
    if (st.size() != 1) {
        cout << "illegal" << '\n';
        return 0;
    }
    return st.top();
}

int main() {
    while (getline(cin, s) && s != ".") {
        try {
            cout << evaluatePrefix(s) << '\n';
        }
		catch (...) {
            cout << "illegal" << '\n';
        }
    }
    return 0;
}
