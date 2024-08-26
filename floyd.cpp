#include<iostream>
#include<algorithm>
#include<cstring>
#include<vector>
#include<functional>
using namespace std;
int main() {
    int n,m,Q;
    cin >> n >> m >> Q;
    vector<vector<int>> g(n + 1, vector<int>(n + 1, 0x3f3f3f3f));
    for(int i = 1; i <= n; i++ ) {
        g[i][i] = 0;
    }
    while(m--) {
        int a,b,c;
        cin >> a >> b >> c;
        g[a][b] = min(g[a][b],c);
    }
    auto floyd = [&]() {
        for(int k = 1; k <= n ; k++) {
            for(int i = 1; i <= n ; i++) {
                for(int j = 1; j <= n; j ++) {
                    g[i][j] = min(g[i][j],g[i][k] + g[k][j]);
                }
            }
        }
    };
    floyd();
    while(Q--) {
        int x,y;
        cin >> x >> y;
        if(g[x][y] > 0x3f3f3f3f / 2) puts("impossible");
        else cout << g[x][y] << '\n';
    }
    return 0;
}
