#include <iostream>
#include <vector>

using namespace std;

int main() {
	int l, m, u, v;
	cin >> l >> m;
	vector<int> tree(l + 1, 1);
	for (int i = 0; i < m; i++) {
		cin >> u >> v;
		for (int j = u; j <= v; j++) tree[j] = 0;
	}
	
	int ans = 0;
	for (auto p = tree.begin(); p != tree.end(); p++)
		ans += *p;
	cout << ans;
	return 0;
}
