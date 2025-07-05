#include "iostream"
#include <map>
using namespace std;

int main()
{
    map<string, int> Z = {
        {"Ox", 0},   {"Tiger", 1},  {"Rabbit", 2},  {"Dragon", 3}, {"Snake", 4}, {"Horse", 5},
        {"Goat", 6}, {"Monkey", 7}, {"Rooster", 8}, {"Dog", 9},    {"Pig", 10},  {"Rat", 11},
    };
    int N;
    cin >> N;
    map<string, pair<int, string>> mp = {{"Bessie", {0, "Ox"}}};
    while (N--) {
        string curr, tmp, delta, sign, orig;
        cin >> curr;
        cin >> tmp;
        cin >> tmp;
        cin >> delta;
        cin >> sign;
        cin >> tmp;
        cin >> tmp;
        cin >> orig;
        auto p = mp[orig];
        int ans = 0;
        if (delta == "next") {
            ans += (Z[sign] - Z[p.second] + 12)%12;
            if (sign == p.second) 
                ans += 12;
        }
        else {
            ans -= (Z[p.second] - Z[sign] + 12)%12;
            if (sign == p.second) 
                ans -= 12;
        }
        mp[curr] = {ans + p.first, sign};
    }
    // for (auto &p : mp) {
    //     cout << p.first << p.second.first << p.second.second << "\n";
    // }
    cout << abs(mp["Elsie"].first) << "\n";

}
