class Solution {
public:
	bool wordBreak(string s, unordered_set<string>& wordDict) {
		int n = s.size();
		bool dp[n + 1];
		for (int i = 0; i <= n; ++i) {
			dp[i] = false;
		}
		dp[0] = true;
		for (int i = 1; i <= n; ++i) {
			for (int j = 0; j < i; ++j) {
				if (dp[j] && wordDict.find(s.substr(j, i - j)) != wordDict.end()) {
					dp[i] = true;
					break;
				}
			}
		}
		return dp[n];
	}
};
