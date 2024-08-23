#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

typedef tuple<int, int, int> Edge; // 使用 tuple 存储边的信息

int main() {
    int n, m, k;
    cin >> n >> m >> k;

    vector<Edge> edges;  // 用于存储所有的边
    while (m--) {
        int a, b, c;
        cin >> a >> b >> c;
        edges.push_back(make_tuple(a, b, c));
    }

    vector<int> dist(n + 1, 0x3f3f3f3f);
    dist[1] = 0;  // 起点1到自己的距离为0

    for (int i = 0; i < k; i++) {
        vector<int> backup = dist;  // 备份当前的距离数组
        for (const auto& edge : edges) {
            int a, b, c;
            tie(a, b, c) = edge; // 解包 tuple
            if (backup[a] != 0x3f3f3f3f) {
                dist[b] = min(dist[b], backup[a] + c);
            }
        }
    }

    if (dist[n] > 0x3f3f3f3f / 2) {
        cout << -1 << '\n';  // 如果目标节点n不可达，输出-1
    } else {
        cout << dist[n] << '\n';  // 输出从起点1到终点n的最短路径
    }

    return 0;
}