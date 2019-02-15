#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    int n,a[int(1e5)+10];
    cin >> n;
    for(int i=0;i<n;i++){
        cin >> a[i];
    }
    sort(a, a+n);
    cout << min(a[n-1] - a[1], a[n-2] - a[0]) << endl;

    return 0;
}

