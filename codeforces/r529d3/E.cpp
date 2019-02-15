#include <bits/stdc++.h>
using namespace std;
#define endl '\n'

string str;
int nleft[int(1e6+10)], nright[int(1e6+10)];

int main(){
    ios_base::sync_with_stdio(false);
    int n;
    cin >> n;
    cin >> str;

    bool bad = false, valid=true;

    for(int i=0;i<n;i++){
        if(str[i] == '(') nleft[i+1] = nleft[i] + 1, nright[i+1] = nright[i];
        else nleft[i+1] = nleft[i], nright[i+1] = nright[i] + 1;
        if(nright[i+1] - nleft[i+1] > 2) bad = true;
        if(nright[i+1] > nleft[i+1]) valid = false;
    }

    if(valid && nright[n] != nleft[n]){
        valid = false;
    }

    if(abs(nright[n] - nleft[n]) > 2 ) bad = true;
    if(str[0] == ')' && str[n-1] == '(') bad = true;

    if(bad || valid || n%2==1) cout << 0 << endl;
    else if((str[0] == ')') || (str[n-1] == '(') ) cout << 1 << endl;
    else if(nright[n] > nleft[n]){
        int ans=0;
        for(int i=1; i<n-1; i++){
            if(str[i] == ')')
               if(nright[i+1]-nleft[i+1] <2) ans++;
        }
        cout << ans << endl;
        //if(ans == 1 && n ==1000000) cout << "SO" << ' ' << nright[n] << ' ' << nleft[n];
    }
    else{
        int ans=0;
        for(int i=1; i<n-1; i++){
            if(str[i] == '(')
               if( (nleft[i+1] - nright[i+1] >= 2) )ans++;
        }
        cout << ans << endl;
        //if(ans == 1 && n ==1000000) cout << "SAD";

    }
    //for(int i=1;i<=n;i++)
    //    cout << nleft[i] << ' ';
    //cout << endl;
    //for(int i=1;i<=n;i++)
    //    cout << nright[i] << ' ';
    //cout << endl;

    return 0;
}
