#include <bits/stdc++.h>
using namespace std;

int main(){
    long long n, v[1001], min_v=1e9;
    long long s, total=0;
    cin >> n >> s;
    for(int i=0;i<n;i++){
        cin >> v[i];
        min_v = min(min_v, v[i]);
        total += v[i];
    }
    
    if(total < s){
        cout << -1;
        return 0;
    }
    
    long long abundant = 0;
    for(int i=0;i<n;i++)
        abundant += v[i] - min_v;

    if( abundant >= s){
        cout << min_v;
        return 0;
    }

    s -= abundant;
    cout << min_v - (long long)(ceil(double(s)/n)) << '\n';

    return 0;
}
