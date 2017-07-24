#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef vector<int> vi;
typedef pair<int,int> ii;

#define mp make_pair
#define pb push_back

const ll INF = 1e9;
const double PI = 3.14159265358979323846264338327950;

ll a[1000010];

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int n;
	cin >> n;
	for(int i=0;i<n;i++)
		scanf("%lld",&a[i]);

	ll sump=0LL, ansp = 0LL;
	ll sumn=0LL, ansn = 0LL, temp=0LL;

	for(int i=0;i<n;i++){

		sump = max(sump+a[i],a[i]);	
		ansp = max(ansp,sump);

		temp += a[i];
		sumn = min(sumn-a[i],-a[i]);
		ansn = min(ansn,sumn);
	}	
	
	cout << max(ansp,temp+ansn) << '\n';

	return 0;
}
