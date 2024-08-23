#include<iostream>
#include<cstring>
#include<algorithm>
#include<vector>
#include<queue>
#include<functional>
using namespace std;
typedef pair<int,int> PII;
int main() {
    int n,m;
    cin >> n >> m;
    vector<vector<PII>> g(n + 1);
    while(m--) {
        int a, b, c;
        cin >> a >> b >> c;
        g[a].emplace_back(b,c);
    }
    function<int()> spfa = [&]() -> int {
        vector<int> dist(n + 1,0x3f);
        vector<bool> vis(n + 1,false);
        dist[1] = 0;
        queue<int> q;
        q.push(1);
        vis[1] = true;
        while(!q.empty()) {
            auto u = q.front();
            q.pop();
            vis[u] = false;
            for(const auto& [v,w] : g[u]) {
                if(dist[v] > dist[u] + w ) {
                    dist[v] = dist[u] + w;
                    if(!vis[v]){
                        q.push(v);
                        vis[v] = true;
                    }
                }
            }
        }
        return dist[n] == 0x3f3f3f3f ? -1 : dist[n];
    };
    cout << spfa() << '\n';
    return 0;
}