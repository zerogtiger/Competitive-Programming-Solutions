// #include "iostream"
// #include <queue>
// using namespace std;
//
// int main()
// {
//     int T;
//     cin >> T;
//     while (T--) {
//         int N, K;
//         cin >> N >> K;
//         priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>,
//                        greater<tuple<int, int, int>>>
//             pq;
//         vector<int> V(N);
//         for (auto& i : V)
//             cin >> i;
//         sort(V.begin(), V.end());
//         for (int i = 0; i < K; ++i) {
//             int a, b, c;
//             cin >> a >> b >> c;
//             pq.push({a, b, c});
//         }
//         pair<int, int> curr = {-0x3f3f3f3f, -0x3f3f3f3f};
//         while (!pq.empty()) {
//             auto top = pq.top();
//             if (get<0>(top) < curr.second) {
//                 get<2>(top) -= 
//             }
//         }
//     }
// }
