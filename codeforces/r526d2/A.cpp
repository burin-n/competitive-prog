#include <bits/stdc++.h>
using namespace std;
int main(){
    int n, a[101];
    cin >> n;
    for(int i=0;i<n;i++)
        cin >> a[i];

    int min_cost = 1e9;
    for(int i=0;i<n;i++){
        int cost = 0;
        for(int j=0;j<n;j++) 
            cost += 2*a[j]*(abs(i-j) + j + i);
        min_cost = min(min_cost, cost);
    }
    cout << min_cost;
    return 0;
}
