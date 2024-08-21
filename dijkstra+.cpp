#include<iostream>
#include<algorithm>
#include<string>
#include<functional>
#include<queue>
using namespace std;
const int N = 100010;
typedef pair<int,int> PII;
int dist[N];
bool vis[N];
int h[N],e[N],ne[N],w[N],idx;
void add(int a,int b,int c) {
    e[idx] = b,ne[idx] = h[a],w[idx] = c,h[a] = idx++;
}
int main() {
    int n,m;
    cin >> n >> m;
    memset(vis,false,sizeof(vis));
    memset(dist,0x3f,sizeof(dist));
    memset(h,-1,sizeof(h));
    while(m--) {
        int a,b,c;
        cin >> a >> b >> c;
        add(a,b,c);
    }
    function<int()> dijkstra = [&]() -> int{
        priority_queue<PII,vector<PII>,greater<PII>> heap;
        heap.push({0,1});
        while(heap.size()) {
            auto t = heap.top();
            heap.pop();
            int cnt = t.second,dis = t.first;
            if(vis[cnt]) continue;
            vis[cnt] = true;
            for(int i = h[cnt];i != -1; i = ne[i]) {
                int j = e[i];
                dist[j] = min(dist[j],dis + w[i]);
                heap.push({dist[j],j});
            }
        }
        return dist[n] == 0x3f3f3f3f ? -1 : dist[n];
    };
    cout << dijkstra() << '\n';
    return 0;
}

