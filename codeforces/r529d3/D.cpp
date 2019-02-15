#include <bits/stdc++.h>
using namespace std;

int adj[int(2e5)+10][2];

int main(){
    ios_base::sync_with_stdio(false);
    int n, a, b;
    cin >> n;
    for(int i=1; i<=n; i++){
        cin >> a >> b;
        adj[i][0] = a;
        adj[i][1] = b;
    }

    int index = 1, count=0;

    while(count < n){
        cout << index << ' ';
        count++;
//        cout << '#' << count << '#' << ' ';
        if(count >= n ) break;
        a = adj[index][0];
        b = adj[index][1];

        if(adj[a][0] == b || adj[a][1] == b){
            cout << a << ' ';
            index = b;
            count ++;
        }
        else{
            cout << b << ' ';
            index = a;
            count ++;
        }
    }

    return 0;
}


