#include <bits/stdc++.h>
using namespace std;
#define endl '\n';

class edge{
    public:
        int to, cost;
        edge(int u, int c){
           to = u;
           cost = c;
        } 
};

vector <edge> edges[300000+5];

int n;
bool visit[300000+5];
long long dp[300000+5];
long long w[300000+5];  

void debug(long long s,long long t,long long c){
    cout << "from " << s << " to " << t << " cost " << c << endl;
}
void debug(long long s,long long c){
    cout << "at " << s << " gas " << c << endl;
}

long long dfs(int node, int from, long long gas){
    debug(node,gas);
    if(gas < 0)
        return 0;
    
    if(from != -1 && gas < w[node]){
        return gas + dp[node];
    }

    gas += w[node];

    long long remaining_gas=0, best_gas = gas, second_best = 0;
    for (edge adj : edges[node]){
        if(adj.to != from){
            remaining_gas = dfs(adj.to, node, gas - adj.cost);
            debug(node,adj.to, remaining_gas);
            if(remaining_gas > best_gas)
                best_gas = remaining_gas;
            else if(remaining_gas > second_best)
                second_best = remaining_gas;
        }
    }

    if(from == -1 && second_best > 0)
        dp[node] = best_gas + second_best - w[node];
    else
        dp[node] = best_gas;
    best_gas = dp[node];

    cout << "node "<< node<<" fbest " << best_gas << " sbest " << second_best << endl;

    return best_gas;
}

int main(){
    ios_base::sync_with_stdio(false);

    cin >> n;
    for(int i=1;i<=n;i++){
        cin >> w[i];
        dp[i] = w[i];
    }

    int u,v,c;
    for(int i=1;i<n;i++){
        cin >> u >> v >> c;
        edges[u].push_back( edge(v,c) );
        edges[v].push_back( edge(u,c) );
    }

    long long ans = 0; 
    for(int i=1;i<=n;i++){
        cout << '\n';
        dfs(i,-1, 0);

        cout << endl;
        for(int i=1;i<=n;i++)
            cout << dp[i] << ' ';
        cout << endl;
    }

    for(int i=1;i<=n;i++)
        ans = max(ans, dp[i]);
    cout << ans << '\n';

   //
//    cout << endl;
//    for(int i=1;i<=n;i++)
//        cout << visit[i] << ' ';
//    cout << endl;
//
    return 0;
}
