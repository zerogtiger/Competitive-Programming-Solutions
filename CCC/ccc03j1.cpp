// Solution by zerogtiger on Github

#include <bits/stdc++.h>

using namespace std;
int t, s, h;
int main() {
    cin >> t >> s >> h;
    for (int i = 0; i < t ; i++){
        cout << "*"; 
        for (int j = 0; j < s; j++) {
            cout << " ";
        }
        cout << "*"; 
        for (int j = 0; j < s; j++) {
            cout << " ";
        }
        cout << "*" << endl;
    }
    for (int i = 0; i < 3+2*s ; i++){
        cout << "*";
    } 
    cout << endl;
    for (int i = 0; i < h ; i++){
        for (int j = 0; j < 1+s ; j++){
            cout << " ";
        }
        cout << "*" << endl;
    }
}