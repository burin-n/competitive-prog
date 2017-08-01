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

int pos[1000000+10];

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n,k;
	int start[26],end[26];
	string guest;
	cin >> n >> k;
	cin >> guest; 
	for(int i=0;i<26;i++)
		start[i]=end[i]=-1;

	for(int i=0;i<n;i++){
		int g = guest[i] - 'A';
		if(start[g] == -1)
			start[g] = i;
		end[g]=i+1;
	}
	
	for(int i=0;i<26;i++){
		if(start[i]>-1){
			pos[start[i]]++;
			pos[end[i]]--;
		}	
	}
	int need = 0;	
	int ans = 0;
	for(int t=0;t<=n;t++){
		need += pos[t];	
		ans = max(need,ans);
	}
	

	if(ans>k) cout<<"YES"<<endl;
	else cout<<"NO"<<endl;
		
	return 0;
}
