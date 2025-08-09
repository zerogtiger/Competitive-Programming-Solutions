#include "iostream"
#include "vector"
using namespace std;

int main() {
	int N, X;
	cin >> N >> X;
	vector<pair<int, int>> V;
	for (int i = 1; i <= N; i++) {
		int tmp; cin >> tmp;
		V.push_back({tmp, i});
	}
	sort(begin(V), end(V));
	for (int i = 0; i < N; i++) {
		int l, r;
		l = 0;
		r = N - 1;
		while (l != r) {
			int target;
			target = X - V[i].first;
			if (l != i && r != i && V[l].first + V[r].first == target) {
				cout << V[i].second << " " << V[l].second << " " << V[r].second << "\n";
				return 0;
			}
			if (V[l].first + V[r].first < target) {
				l++;
			} else {
				r--;
			}
		}
	}
	cout << "IMPOSSIBLE" << "\n";
}
