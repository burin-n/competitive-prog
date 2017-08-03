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
	int n,num=0;

	cin >> n;
	string s,ans="";
	cin >> s;	

	for(char c : s){
		if(c == '1') num++;
		else ans+=to_string(num), num=0;
	}	
	
	cout << ans + to_string(num) << endl;

	return 0;
}
