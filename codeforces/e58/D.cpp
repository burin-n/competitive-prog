#include <bits/stdc++.h>
using namespace std;
const int N = int(2e5)+10;
int n, s, t, a;
vector<int> adj[N], prime;
vector<bool> visit(N, false);
set<int> frac[N];
map<int, int> gcd, root_depth[N], root_ans[N];
vector<bool> isprime(N, true);
int ans = 0;


void dfs(int node, list<int> parent, int depth){
    bool pass = false; 
    int p = parent.back();
   
    //printf("node %d depth %d: ",node, depth);
    map<int, int> copy_gcd;
    list<int> copy_parent;
    copy_gcd.insert(gcd.begin(), gcd.end());
    copy_parent.assign(parent.begin(), parent.end());

    visit[node] = true;
    
    if(!frac[node].empty()){
        for(const int& k: frac[node]){           
            if( gcd.find(k) != gcd.end()) gcd[k]++;
            else gcd[k] = 1;

    //        printf("%d(%d) ",k, gcd[k]);
            if(depth == gcd[k])
                pass = true;
        }
    }
    //printf("\n");

    while(!pass && !parent.empty()){
        depth -= 1;
        int head = parent.front();
        
        for(const int &k: frac[head]){
            gcd[k]--;
            if(root_depth[head].find(k) != root_depth[head].end())
                root_depth[head][k] = max(root_depth[head][k], gcd[k]);
            else
                root_depth[head][k] = gcd[k];
        }            

        parent.pop_front();

        for(const int &k: frac[node])
            if(gcd[k] == depth) 
                pass = true;
    }
    
    parent.push_back(node);

    
    for(int to : adj[node]){
        if(to == p) continue;
        root_depth[node].clear();
    //    printf("before dfs %d: ", node);
    //    for(int k : frac[node]){
    //        printf("%d(%d) ", k, gcd[k]);
    //    }
     //   printf("\n");

        dfs(to, parent, depth+1);
        for(const int &k : frac[node]){
    //        printf("%d(%d), ",k, root_depth[node][k]);
            root_ans[node][k] += root_depth[node][k]-1;
        }
    //        printf("\n"); 
    }

    while(!parent.empty()){
        int head = parent.front();
        
        for(const int &k: frac[head]){
            if(root_depth[head].find(k) != root_depth[head].end())
                root_depth[head][k] = max(root_depth[head][k], gcd[k]--);
            else
                root_depth[head][k] = gcd[k]--;
        }            

        parent.pop_front();
    }

    gcd.clear();
    gcd.insert(copy_gcd.begin(), copy_gcd.end());
    parent.clear();
    parent.assign(copy_parent.begin(), copy_parent.end());
}

int main(){
    ios_base::sync_with_stdio(false);

    isprime[1] = false;
    for(int i=2; i<=sqrt(N); i++){
        if(isprime[i]){
            for(int j=2; i*j<N; j++)
                isprime[i*j] = false;
        }
    }

    for(int i=2; i<N; i++)
        if(isprime[i]){
            prime.emplace_back(i);
        }


    scanf("%d",&n);
    
    for(int i=1;i<=n;i++){
        scanf("%d",&a);

        for(int j=0; j<prime.size(); j++){
            if(prime[j] > a) break;
            if(a%prime[j] == 0) frac[i].insert(prime[j]);
        }
    }

    for(int i=0;i<n-1;i++){
        scanf("%d %d", &s, &t);
        adj[s].emplace_back(t);
        adj[t].emplace_back(s);
    }

    for(int i=1;i<=n;i++)
        if(!visit[i])
        dfs(i, list<int>(), 1); 
    
    for(int i=1;i<=n;i++)
        for(const int &k: frac[i])
            ans = max(ans, root_ans[i][k]+1);
    
    printf("%d\n",ans);

    return 0;
}
