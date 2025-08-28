#include<bits/stdc++.h>
using namespace std;

int n, m;
string s;

int main() {
	int cnt = 1;
	while(cin >> n && n) {
		string ans, team;
		getline(cin, s);
		while(n--) {
			getline(cin, s);
			ans += s;
		}
		
		cin >> m;
		getline(cin, s);
		while(m--) {
			getline(cin, s);
			team += s;
		}
		
		cout << "Run #" << cnt << ": ";
		
		string ans_nums, team_nums;
		
		if(ans == team) cout << "Accepted" << '\n';
		else {
			for(int i=0; i<ans.length(); i++) {
				if(ans[i] >= '0' && ans[i] <= '9') ans_nums += ans[i];
			}
			for(int i=0; i<team.length(); i++) {
				if(team[i] >= '0' && team[i] <= '9') team_nums += team[i];
			}
			
			if(ans_nums == team_nums) cout << "Presentation Error" << '\n';
			else cout << "Wrong Answer" << '\n';
		}
		cnt++;
	}
} 
