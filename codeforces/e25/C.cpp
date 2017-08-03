#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> ii;

#define mp make_pair
#define pb push_back
#define endl '\n'

const int INF = 1e9;
const double PI = 3.141592653589793238462643383279502884197;

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n, outside=0;
	double k,a[1000];
	cin >> n >> k;
	for(int i=0;i<n;i++){
		cin >> a[i];
	}
	sort(a,a+n);
	for(int i=0;i<n;){
		if( k >= a[i]/2.0 ) k = max(k,a[i]), i++;
		else outside++, k*=2.0;
	}
	cout << outside << endl;
	return 0;
}
