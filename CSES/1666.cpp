#include "iostream"
#include "set"
using namespace std;

const int MM = 1e5 + 3;
int dsu[MM];

int find(int i) {
    if (dsu[i] == i) {
        return i;
    }
    return dsu[i] = find(dsu[i]);
}

int main()
{
    int N, M;
    cin >> N >> M;
    for (int i = 1; i <= N; ++i) {
        dsu[i] = i;
    }
    while (M--) {
        int a, b;
        cin >> a >> b;
        int p = find(dsu[max(a, b)]);
        int q = find(dsu[min(a, b)]);
        dsu[p] = q;
    }
    set<int> st;
    for (int i = 1; i <= N; ++i) {
        st.insert(find(i));
    }
    cout << st.size() - 1 << "\n";
    int curr =  0;
    for (auto &i : st) {
        if (curr != 0) {
            cout << curr << " " << i << "\n";
        }
        curr = i;
    }
}
