#include <bits/stdc++.h>
using namespace std;

int main(){
    string s;
    int n, step=0;

    cin >> n;
    cin >> s;
    for(int i=0; i<n; i+=step){
        step ++;
        cout << s[i] ;
    }
    cout << '\n';
    return 0;
}
