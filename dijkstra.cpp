#include<iostream>
#include<algorithm>
#include<string>
#include<functional>
using namespace std;
const int N = 510;
int g[N][N];
bool vis[N];
int dist[N];
int n,m;
int main() {
    cin >> n >> m;
    memset(g,0x3f,sizeof(g));
    memset(vis,false,sizeof(vis));
    while(m--) {
        int a,b,c;
        cin >> a >> b >> c;
        g[a][b] = min(g[a][b],c);
    }
    function<int()> dijkstra = [&]() -> int {
        memset(dist,0x3f,sizeof(dist));
        dist[1] = 0;
        for(int i = 0 ; i < n ; i++) {
            int t = -1;
            for(int j = 1; j<=n ; j ++) {
                if(!vis[j]&&(t == -1 || dist[t]> dist[j]))
                    t = j;
            }
            vis[t] = true;
            for(int j = 1; j<= n; j++) {
                dist[j] = min(dist[j],dist[t] + g[t][j]);
            }
        }
        return dist[n] == 0x3f ? -1 : dist[n];
    };
    cout << dijkstra() << '\n';
    return 0;
}
