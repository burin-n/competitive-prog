#include <bits/stdc++.h>
using namespace std;

int main(){
    int q, l, r, d;
    cin >> q;
    while(q--){
        cin >> l >> r >> d;
        if(d < l) cout << d << '\n';
        else{
            int k = r/d;
            while( k*d <= r ) k++;
            cout << k*d << '\n';
        }
        
    }
    return 0;
}
