#include "iostream"
#include "vector"
#include <semaphore>
using namespace std;

int main() {
    string S;
    cin >> S;
    int N = S.size();
    vector<char> ret(N);
    vector<int> freq(26);
    for (auto &s : S) {
        freq[s - 'A'] ++;
    }
    for (auto &i : freq) {
        if (i >= (N + 1) / 2 + 1) {
            cout << "-1\n";
            return 0;
        }
    }
    
    for (int i = 0; i < N; ++i ) {
        for (int j =0; j < 26; ++j) {
            if (freq[j] >= (N - i)/2 + 1) {
                ret[i] = j + 'A';
                freq[j] --;
                goto end;
            }
        }
        for (int j =0; j < 26; ++j) {
            if (freq[j] > 0 && (i == 0 || j + 'A' != ret[i - 1])) {
                ret[i] = j + 'A';
                freq[j]--;
                goto end;
            }
        }
end:
        continue;
    }
    for (auto &c : ret) {
        cout << c;
    }
    cout << "\n";


}
