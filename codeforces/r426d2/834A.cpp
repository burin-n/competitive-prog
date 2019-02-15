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
	char start,end;	
	int t;
	map<char,int> mmap;
	mmap['^'] = 0;
	mmap['>'] = 1;
	mmap['v'] = 2;
	mmap['<'] = 3;

	cin >> start >> end;
	cin >> t;
 	t%=4;
	if(t%2==0) cout << "undefined\n";
	else{
		if((mmap[start] + t)%4 == mmap[end]) cout << "cw\n";
		else cout << "ccw\n";
	}
	return 0;
}
