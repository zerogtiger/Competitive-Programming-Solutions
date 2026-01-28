#include "iostream"
#include "vector"

using namespace std;

int main()
{
    int N, M;
    cin >> N >> M;
    for (int i = 0; i < N; ++i) {
        string S;
        cin >> S;
        for (int j = 0; j < M; ++j) {
            if ((i + j) % 2 == 0) {
                if (S[j] == 'A')
                    cout << "C";
                else
                    cout << "A";
            }
            else if (S[j] == 'B')
                cout << "D";
            else
                cout << "B";
        }
        cout << "\n";
    }
}
