#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> ii;

#define mp make_pair
#define pb push_back
#define endl '\n'

const double PI = 3.14159265358979323846264338327950;


int main(){
	int n;
	ll a,b,r;

	cin >> n;
	
	while(n--){
		scanf("%llu %llu",&a,&b);
		r = pow(a*b,1.0/3.0) + 0.5;
		if( r*r*r == a*b && a%r == 0 && b%r == 0 ) printf("Yes\n");
		else printf("No\n");
	}	
	return 0;
}
