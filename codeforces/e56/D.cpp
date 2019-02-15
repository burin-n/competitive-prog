#include <bits/stdc++.h>
using namespace std;
const long long mod = 998244353;
const int N = int(3e5) + 10;

vector<int> adj[N];
int state[N];
int a, b;
bool bad = false;
long long power[N];

void dfs(int node, int parent){
    //cout << node << ' ' << parent << endl;
    //cout << state[node] << ' ' << state[parent] << endl << endl;

    if(state[node] == state[parent]){
        state[node] = -1;
        bad = true;
        return;
    }

    if(state[node] != 0) return;

    if(state[parent] == 1) state[node] = 2, a++;      
    else state[node] = 1, b++;

    for(int v : adj[node]){
        if(v == parent) continue;
        dfs(v, node);
    }
}



int main(){
    ios_base::sync_with_stdio(false);

    power[0] = 1;
    for(int i=1;i<N;i++)
        power[i] = (2*power[i-1])%mod;

    int t;
    cin >> t;
    while(t--){
        int n,m,u,v;
        bad = false;
        cin >> n >> m;
        for(int i=0;i<=n;i++) adj[i].clear(), state[i]=0;
        for(int i=0;i<m;i++){
            cin >> u >> v;
            adj[u].emplace_back(v);
            adj[v].emplace_back(u);
        } 

        state[0] = 10;

        long long ans = 1LL;
        for(int i=1;i<=n;i++){
            if(state[i] != 0) continue;
            a = b = 0;
            dfs(i, 0);
            ans = (ans * (power[a] + power[b]) )%mod;
        }
        if(bad) cout << 0 << '\n';
        else cout << ans << '\n';
    }
    
    return 0;
}
