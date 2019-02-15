#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

const ll mod = 998244353;

ll dp[int(2e5)+2][102];

int main(){
    int n,k,len;
    scanf("%d  %d %d", &n, &k, &len);
    ll a;

    dp[0][1] = 1;
    for(int i=1;i<=n;i++){
        scanf("%lld", &a);
        ll sum = 0; 
        for(int j=1;j<=k;j++) sum += dp[i-1][j];

        if( a == -1 ){
            for(int j=1;j<=k;j++){
                if(i > len) dp[i][j] = sum + 1 - dp[i-len+1][j]; 
                else dp[i][j] = sum + 1;
            }
        }
        else {
            if(i>len) dp[i][a] = sum - dp[i-len+1][a];
            else dp[i][a] = sum;
        }
    }

    for(int i=1;i<=n;i++){
        for(int j=1;j<=k;j++)
            printf("%lld ",dp[i][j]);
        printf("\n");
    }

    ll ans = 0;
    for(int j=1;j<=k;j++) ans += dp[n][j];
    printf("%lld\n", ans);
    return 0;
}
