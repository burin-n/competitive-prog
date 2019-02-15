#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long ll;

const int N = int(2e5)+10;

struct Node{
    int number;
    ll cost;
} node[N];

struct Path{
    int from,to;
    ll cost;
} offer[N];


bool comparePath(const Path &left, const Path &right){
    return left.cost < right.cost;
}

bool compareNode(const Node &left, const Node &right){
    return left.cost < right.cost;
}

int head[N],high[N];

int getHead(int x){
    if( head[x] == x ) return x;
    else return getHead(head[x]);
}

bool merge(int a, int b){
    int heada = getHead(a);
    int headb = getHead(b);
    if( heada == headb ) return false;
    if(high[heada] > high[headb]) head[headb] = heada;
    else if(high[headb] > high[heada]) head[heada] = headb;
    else{
        head[heada] = headb;
        high[headb]++;
    }
    return true;
}

int main(){
    ios_base::sync_with_stdio(false);

    int n,m;
    ll c;
    cin >> n >> m;

    for(int i=0;i<n;i++) head[i] = i, high[i]=0;

    for(int i=0;i<n;i++){
        cin >> c;
        node[i].number = i;
        node[i].cost = c;
    }

    int x,y;
    ll w;
    for(int i=0;i<m;i++){
        cin >> x >> y >> w;
        offer[i].from = x-1;
        offer[i].to = y-1;
        offer[i].cost = w; 
    }

    sort(node,node+n, compareNode);
    sort(offer, offer+m, comparePath);
    
    int node_index = 1;
    int offer_index = 0;
    ll sum_cost = 0;

    while(node_index < n || offer_index < m){
        ll cost_node = 3e12;
        ll cost_offer = 3e12;

        if(node_index < n)
            cost_node = node[node_index].cost + node[0].cost;

        if(offer_index < m)
            cost_offer = offer[offer_index].cost;

        if(cost_node < cost_offer){
            if(merge(node[node_index].number, node[0].number))
                sum_cost += cost_node;
            node_index++;
        }
        else{
            if(merge(offer[offer_index].from, offer[offer_index].to))
                sum_cost += cost_offer;
            offer_index++;
        }
    }

    cout << sum_cost << endl;

    return 0;
}
