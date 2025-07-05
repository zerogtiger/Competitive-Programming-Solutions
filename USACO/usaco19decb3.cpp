// 2 solutions
#include "iostream"
#include "vector"
#include "map"
#include <cstdio>
#include <set>
#include <algorithm>
using namespace std;

int main()
{
    freopen("lineup.in", "r", stdin);
    freopen("lineup.out", "w", stdout);
    int N;
    cin >> N;
    vector<string> V = {"Bessie", "Buttercup", "Belinda", "Beatrice",
                        "Bella",  "Blue",      "Betsy",   "Sue"};
    sort(V.begin(), V.end());
    map<string, vector<string>> M;
    string tmp;
    getline(cin, tmp);
    for (int i =0; i < N; ++i) {
        getline(cin, tmp);
        string k = tmp.substr(0, tmp.find(" "));
        string v = tmp.substr(tmp.rfind(" ") + 1);
        M[k].push_back(v);
        M[v].push_back(k);
    }
    vector<string> single;
    for (auto &s : V) {
        if (M[s].size() == 0 || M[s].size() == 1) {
            single.push_back(s);
        }
    }
    sort(single.begin(), single.end());
    set<string> done;
    for (auto &s : single) {
        if (done.count(s)) {
            continue;
        }
        cout << s << "\n";
        done.insert(s);
        if (M[s].size() == 0) {
            continue;
        }
        string curr = M[s][0];
        string last = s;
        if (!done.count(curr)) {
            cout << curr << "\n";
        }
        done.insert(curr);
        while (M[curr].size() > 1) {
            for (auto &ss : M[curr]) {
                if (ss != last && !done.count(ss)) {
                    cout << ss << "\n";
                    done.insert(ss);
                    last = curr;
                    curr = ss;
                    break;
                }
            }
        }
    }
}
// #include "iostream"
// #include <algorithm>
// #include <string>
// #include <vector>
// using namespace std;
//
// int main()
// {
//     freopen("lineup.in", "r", stdin);
//     freopen("lineup.out", "w", stdout);
//     int N;
//     cin >> N;
//     vector<string> V = {"Bessie", "Buttercup", "Belinda", "Beatrice",
//                         "Bella",  "Blue",      "Betsy",   "Sue"};
//     sort(V.begin(), V.end());
//     vector<pair<string, string>> C(N);
//     string tmp;
//     getline(cin, tmp);
//     for (auto& p : C) {
//         getline(cin, tmp);
//         p.first = tmp.substr(0, tmp.find(" "));
//         // cout << "> " << p.first << "\n";
//         p.second = tmp.substr(tmp.rfind(" ") + 1);
//         // cout << ">> " << p.second << "\n";
//     }
//
//     do {
//         for (auto& p : C) {
//             for (int i = 0; i < 8; ++i) {
//                 if (V[i] == p.first && i > 0 && i < 7 && V[i - 1] != p.second &&
//                     V[i + 1] != p.second) {
//                     goto end;
//                 }
//                 else if (V[i] == p.first && i == 0 && V[i + 1] != p.second) {
//                     goto end;
//                 }
//                 else if (V[i] == p.first && i == 7 && V[i - 1] != p.second) {
//                     goto end;
//                 }
//             }
//         }
//         for (auto& c : V) {
//             cout << c << "\n";
//         }
//         return 0;
//     end:
//         continue;
//     } while (next_permutation(V.begin(), V.end()));
// }
