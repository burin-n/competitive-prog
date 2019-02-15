#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

template <typename T>
using pql = priority_queue<T, vector<T>, greater<T> >; 
template <typename T>
using pqm = priority_queue<T>;

#define mp make_pair
#define pb push_back
#define PI 3.141592653589793238
#define endl '\n'

int digit[100000+10];
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	ll k,sum = 0LL;
	string n;
	cin >> k >> n;
	for(int i=0;i<n.size();i++){
		digit[i] = (ll)(n[i] -'0');	
		sum += digit[i];
	}
	if(sum >= k) cout << 0 << endl;
	else{
		sort(digit,digit + n.size());
		int diff=0;
		for(int i=0;i<n.size();i++){
			sum -= digit[i];
			sum += 9;
			diff++;
			if(sum >= k) break;	
		}
		cout << diff << endl;
	} 	
	return 0;
}
