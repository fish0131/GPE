#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    while (cin >> n, n) {  // Stop when n == 0
        vector<int> nums(n);
        for (int i = 0; i < n; i++) {
            cin >> nums[i];
        }
        sort(nums.begin(), nums.end()); // Sort the numbers
		
		// To ensure that the indices of the numbers are distinct, a,b,c,d are all distinct numbers from the given set.
        vector<pair<int, pair<int, int>>> sumList; // Store (sum, (i, j))

        // Step 1: Compute all pairwise sums (a + b) and store them with indices
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                sumList.push_back({nums[i] + nums[j], {i, j}});
            }
        }

        unordered_map<int, vector<pair<int, int>>> sumMap;
        for (auto &p : sumList) {
            sumMap[p.first].push_back(p.second);
        }

        int maxD = INT_MIN;
        bool found = false;

        // Step 2: Iterate backward through `d` (largest first)
        for (int d = n - 1; d >= 0; d--) {
            for (int c = 0; c < n; c++) {
                if (c == d) continue; // d and c must be different

                int requiredSum = nums[d] - nums[c];

                if (sumMap.find(requiredSum) != sumMap.end()) {
                    for (auto &p : sumMap[requiredSum]) {
                        int a = p.first, b = p.second;
                        if (a != c && b != c && a != d && b != d) {  // All indices must be distinct
                            maxD = max(maxD, nums[d]);
                            found = true;
                        }
                    }
                }
            }
        }

        if (found)
            cout << maxD << "\n";
        else
            cout << "no solution\n";
    }
    return 0;
}
