#include <bits/stdc++.h>
using namespace std;

typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

template <typename T>
using pql = priority_queue<T, vector<T>, greater<T> >; 
template <typename T>
using pqm = priority_queue<T>;

#define mp make_pair
#define pb push_back
#define endl '\n'

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int s,v1,v2,t1,t2;
	cin >> s >> v1 >> v2 >> t1 >> t2;
	int ft = 2*t1 + s*v1;
	int st = 2*t2 + s*v2;
	if(ft < st) cout << "First" << endl;
	else if(st < ft) cout << "Second" << endl;
	else cout << "Friendship" << endl;
	return 0;
}
