#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <tuple>
#include <string>
#include <algorithm>

using namespace std;

using ll = long long;
using vb = vector<bool>;
using vvb = vector<vb>;
using vi = vector<int>;
using vvi = vector<vi>;
using vl = vector<ll>;
using vvl = vector<vl>;
using pii = pair<int, int>;
using vii = vector<pii>;
using pll = pair<ll, ll>;
using vll = vector<pll>;

int n, m;
vi root;

int getRoot(int x) {
	if (x == root[x]) {
		return x;
	}

	return root[x] = getRoot(root[x]);
}

void updateRoot(int x, int y) {
	const auto rx = getRoot(x);
	const auto ry = getRoot(y);

	root[ry] = root[rx];
}

int main() {
	ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	cin >> n >> m;

	root = vi(n);
	for (auto i = 0; i < n; ++i) {
		root[i] = i;
	}

	auto turn = int{ 1 };
	while (0 < (m--)) {
		int a, b;
		cin >> a >> b;

		const auto ra = getRoot(a);
		const auto rb = getRoot(b);

		if (ra == rb) {
			cout << turn;
			return 0;
		}

		updateRoot(a, b);

		++turn;
	}

	cout << 0;

	return 0;
}