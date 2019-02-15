#include <bits/stdc++.h>

#define fi first
#define se second

using namespace std;
typedef pair<int,int> ii;

int T, N, l, r;
vector< pair<int, ii> > vl(int(2e5)+10, make_pair(0,ii(0,0)));

vector<int> ans(int(2e5)+10, 0);

int main(){
    ios_base::sync_with_stdio(false);
    cin >> T;

    while(T--){
        cin >> N;

        for(int i=0;i<N;i++){
            cin >> l >> r;
            vl[i] = make_pair(l,ii(r,i));
        }

        sort(vl.begin(), vl.begin()+N);


        int rightmost = 0;
        int group = 1;
        ans[vl[0].second.second] = 1;
        rightmost = vl[0].se.fi;

        for(int i=1;i<N;i++){
            if(vl[i].first > rightmost) group=2;
            rightmost = max(rightmost, vl[i].se.fi);
            ans[vl[i].second.second] = group; 
        }


        if(group == 2){
            for(int i=0; i<N-1; i++) 
                cout << ans[i] << ' ';
            cout << ans[N-1] << '\n';
        }
        else cout << -1 << '\n';
        
    }
    return 0;
}
