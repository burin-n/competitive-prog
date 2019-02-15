#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> ii;

#define mp make_pair
#define pb push_back
const double PI = 3.141592653589793238462643383279502884197;

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int N,M,L;
	int a,b,c,d;
	cin >> N >> M >> L;
	int farm[101][101];
	for(int i=0;i<101;i++){
		for(int j=0;j<101;j++)
			farm[i][j]=0;
	}	
	for(int i=0;i<L;i++){
		cin >> a >> b >> c >> d;
		for(int j=a;j<=c;j++)
			for(int k=b; k<=d; k++)
				farm[j][k] = 1;
	}
	int ans =0;
	for(int i=0;i<100;i++)
		for(int j=0;j<100;j++)
			ans += farm[i][j];
	cout << ans << '\n';	
	return 0;
}
