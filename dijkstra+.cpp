#include<iostream>
#include<algorithm>
#include<string>
#include<functional>
#include<queue>
using namespace std;
const int N = 100010;
typedef pair<int,int> PII;
int dist[N],e[N],ne[N],w[N],h[N];
int idx;
bool vis[N];
void add(int a ,int b, int c) {
    e[idx] = b,ne[idx] = h[a],w[idx] = c,h[a] = idx ++;
}
int main() {
    int n,m;
    cin >> n >> m;
    memset(vis,0,sizeof(vis));
    memset(h,-1,sizeof(h));
    memset(dist,0x3f,sizeof(dist));
    while(m--) {
        int a,b,c;
        cin >> a >> b >> c;
        add(a,b,c);
    }
    function<int()> dijkstra = [&]() -> int {
        priority_queue<PII,vector<PII>,greater<PII>> heap;
        heap.push({1,0});
        while(!heap.empty()) {
            auto t = heap.top();
            heap.pop();
            int cnt = t.first,dis = t.second;
            if(vis[cnt]) continue;
            vis[cnt] = true;
            for(int i = h[cnt];i != -1; i = ne[i]){
                int j = e[i];
                dist[j] = min(dist[j],dis + w[i]);
                heap.push({j,dist[j]});
            }
        }
        return dist[n] == 0x3f3f3f3f ? -1 : dist[n];
    };
    cout << dijkstra() << '\n';
    return 0;
}