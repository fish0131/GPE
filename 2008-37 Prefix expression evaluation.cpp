#include<bits/stdc++.h>
using namespace std;

string s;

bool evaluatePrefix(string s, long long &res) {
	stack<int> st;
    vector<string> tokens;
    stringstream ss(s);
    string tok;
    while (ss >> tok) tokens.push_back(tok);
    
    for(int i = tokens.size() - 1; i >= 0; i--) {
    	string t = tokens[i];
    	if(isdigit(t[0]) || (t[0] == '-' && t.size() > 1 && isdigit(t[1]))) st.push(stoi(t));
    	else {
    		if(st.size() < 2) {
    			return false;
			}
			int o1 = st.top();
			st.pop();
			int o2 = st.top();
			st.pop();
			if(t == "+") st.push(o1 + o2);
			else if(t == "-") st.push(o1 - o2);
			else if(t == "*") st.push(o1 * o2);
			else if(t == "/") {
				if (o2 == 0) return false; // °£¥H¹s
                st.push(o1 / o2);
			} 
			else if(t == "%") {
				if (o2 == 0) return false; // ¨úmod¹s
                st.push(o1 % o2);
			}
			else {
				return false;
			}
		}
	}
	
	if(st.size() != 1) {
		return false;
	}
	res = st.top();
    return true;
}

int main() {
	while(getline(cin, s) && s != ".") {
		long long res;
		if(evaluatePrefix(s, res)) {
			cout << res << '\n';
		}
		else {
			cout << "illegal" << '\n';
		}
	}
}
