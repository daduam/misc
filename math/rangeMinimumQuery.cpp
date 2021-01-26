#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> sparseTable(const vector<int>& A) {
	int n = A.size();
	vector<vector<int>> ST(__builtin_popcount(n), vector<int>(n));
	ST[0] = A;
	for (int len = 1; len < (int)ST.size(); ++len) {
		for (int i = 0; i < n - (1 << len) + 1; ++i) {
			ST[len][i] = min(ST[len - 1][i], ST[len - 1][i + (1 << (len - 1))]);
		}
	}
	return ST;
}

int rangeMinimum(const vector<vector<int>>& table, int L, int R) {
	// logarithmic complexity
	// for functions without inverses or idempotency
	// int len = R - L;
	// int res = std::numeric_limits<int>::max();
	// for (int i = table.size() - 1; i >= 0; --i) {
	// 	if (len & (1 << i)) {
	// 		res = min(res, table[i][L]);
	// 		L += 1 << i;
	// 	}
	// }
	// return res;

	// constant time, since min is idempotent
	int k = 31 - __builtin_clz(R - L);
	return min(table[k][L], table[k][R - (1 << k)]);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	vector<int> a = {1, 2, 3, 4, 5, 6, 7};
	auto table = sparseTable(a);
	cout << rangeMinimum(table, 5, 7);
}
