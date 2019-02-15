#include <bits/stdc++.h>
using namespace std;

const int N = int(5e5)+10;
int main(){
    ios_base::sync_with_stdio(false);
    int n, x, y;
    cin >> n;
    int mx=0, my=0; 
    char q;

    for(int i=0;i<n;i++){
        cin >> q >> x >> y;
        if(y > x) swap(x,y);
        if(q == '+'){
            mx = max(mx, x);
            my = max(my, y);                       
        }
        else{
            if(mx <= x && my <= y) cout <<"YES\n";
            else cout <<"NO\n";
        }
    }

    return 0;
}