#include "iostream"
#include <set>
using namespace std;


int main() {
    int N;
    cin >> N;
    set<int> st;
    while (N--) {
        int i;
        cin >> i;
        if (st.count(i - 1)) {
            st.erase(i - 1);
            st.insert(i);
        }
        else {
            st.insert(i);
        }
    }
    cout <<st.size() << "\n";
}
