class Solution {
public:
	int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
		int n = gas.size(), sum = 0, total = 0, idx = 0;
		for (int i = 0; i < n; ++i) {
			total += gas[i] - sum[i];
			if (sum < 0) {
				sum = 0;
				idx = i;
			}
			sum += gas[i] - sum[i];
		}
		return total > 0 ? idx : -1;
	}
};
