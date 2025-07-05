#include "iostream"
#include <algorithm>
#include <cstring>
#include <string>
#include <vector>
#include <set>
using namespace std;

bool final[103];
bool curr[103];
int cnt[103];

int main()
{
    freopen("tracing.in", "r", stdin);
    freopen("tracing.out", "w", stdout);
    int N, T;
    cin >> N >> T;
    for (int i = 0; i < N; ++i) {
        char c;
        cin >> c;
        final[i] = c - '0';
    }
    vector<pair<int, pair<int, int>>> V(T);
    for (auto& p : V) {
        cin >> p.first >> p.second.first >> p.second.second;
        p.second.first --;
        p.second.second --;
    }
    sort(V.begin(), V.end());
    pair<int, int> K = {0x3f3f3f3f, 0};
    set<int> p0;
    for (int i = 0; i < N; ++i) {
        if (final[i]) {
            for (int k = 0; k <= T + 1; ++k) {
                memset(curr, 0, sizeof(curr));
                memset(cnt, 0, sizeof(curr));
                curr[i] = true;
                for (auto& p : V) {
                    if (curr[p.second.first] && cnt[p.second.first] < k) {
                        if (curr[p.second.second])
                            cnt[p.second.second]++;
                        curr[p.second.second] = 1;
                        cnt[p.second.first]++;
                    }
                    else if (curr[p.second.second] && cnt[p.second.second] < k) {
                        curr[p.second.first] = 1;
                        cnt[p.second.second]++;
                    }
                }
                bool flag = true;
                for (int i = 0; i < N; ++i) {
                    flag = flag && (curr[i] == final[i]);
                }
                if (flag) {
                    p0.insert(i);
                    K = {min(K.first, k), max(K.second, k)};
                }
            }
        }
    }
    cout << p0.size() << " " << K.first << " " << (K.second == T + 1? "Infinity" : to_string(K.second));
}
