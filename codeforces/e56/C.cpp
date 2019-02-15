#include<bits/stdc++.h>
using namespace std;

long long len, b, a[200000+1];

int main(){
    ios_base::sync_with_stdio(false);
    cin >> len;
    long long out = 0;
    a[0] = 2e18;
    for(int i=1;i<=len/2;i++){
        cin >> b;
        b -= out;

        if( b <= a[i-1] ){
            a[i] = b;
        }
        else{
            out += b-a[i-1];
            a[i] = a[i-1];
        }
        cout << out << ' ';
    } 
       
    for(int i=len/2;i>0;i--)
        cout << a[i] << ' ';
    cout << endl;
    return 0;
}
