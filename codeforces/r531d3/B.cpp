#include <bits/stdc++.h>
using namespace std;

set<int> s[5000+5];
int n,k,x;
int findex = 1;
int num[5000+5], a[5000+5];

int main(){
    ios_base::sync_with_stdio(false);
    bool can = true;
    cin >> n >> k;

    for(int i=0;i<n;i++){
        cin >> a[i];
        num[a[i]]++;
        if(num[a[i]] > k) can = false;
    }
    
    if(!can){
        cout << "NO\n";
        return 0;
    }
    cout << "YES\n";
    for(int i=0;i<n;i++){
        if(findex <= k){
            s[findex].insert(a[i]);
            cout << findex << ' ';
            findex ++;

        }
        else{
            for(int j=1;j<=k;j++){
                if(s[j].find(a[i]) == s[j].end()){
                    s[j].insert(a[i]);
                    cout << j << ' ';
                    break;
                }
            }
        }
    }
    return 0;
}
