#include <bits/stdc++.h>
using namespace std;

int main(){
    int n,x,y,a, nleq=0;
    cin >> n >> x >> y;

    for(int i=0;i<n;i++){
        cin >> a;
        if(a <= x) nleq++; 
    }
    if( x > y ) cout << n << endl;
    else cout << (nleq+1)/2 << endl;
    return 0;
}
