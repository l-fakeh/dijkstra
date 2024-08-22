#include<iostream>
#include<algorithm>
#include<string>
#include<queue>
#include<functional>
#include<vector>
using namespace std;
typedef pair<int,int> PII;
int main() {
    int n,m;
    cin >> n >> m;
    vector<vector<PII>> g(m + 1);
    vector<int> dist(n + 1,INT_MAX);
    dist[1] = 0;
    while(m--) {
        int u,v,w;
        cin >> u >> v >> w;
        g[u].emplace_back(v,w);
    }
    function<int()> dijkstra = [&]() {
        priority_queue<PII,vector<PII>,greater<>> heap;
        heap.emplace(0,1);
        while(!heap.empty()) {
            auto [d,u] = heap.top();
            heap.pop();
            if(d > dist[u]) continue;
            for(const auto& [v,w] : g[u]) {
                if(dist[v] > dist[u] + w) {
                    dist[v] = dist[u] + w;
                    heap.emplace(dist[v],v);
                }
            }
        }
        return dist[n] == INT_MAX ? -1 : dist[n];
    };
    cout << dijkstra() << '\n';
    return 0;
}
