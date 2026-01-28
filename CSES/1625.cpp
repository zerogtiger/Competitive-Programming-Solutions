#include "iostream"
#include "vector"
using namespace std;

bool visited[9][9];
vector<string> paths;
vector<pair<pair<int, int>, char>> delta = {
    {{1, 0}, 'D'}, {{-1, 0}, 'U'}, {{0, 1}, 'R'}, {{0, -1}, 'L'}};

void fun(int row, int col, string path)
{
    // cout << row << " " << col << "\n";
    if (row == 6 && col == 0) {
        if (path.size() != 48) {
            return;
        }
        paths.push_back(path);
        cout << path << endl;
    }
    else {
        visited[row][col] = true;
        for (auto& p : delta) {
            if (visited[row + p.first.first][col + p.first.second] || row + p.first.first < 0 || row + p.first.first > 6 || col + p.first.second < 0 ||
                col + p.first.second > 6) {
                continue;
            }
            path.push_back(p.second);
            fun(row + p.first.first, col + p.first.second, path);
        }
        visited[row][col] = false;
    }
}

int main() {
    fun(0, 0, "");
    cout << ": " << paths.size();
}
