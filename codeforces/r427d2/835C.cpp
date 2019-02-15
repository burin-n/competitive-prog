#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

#define mp make_pair
#define endl '\n'

const double PI =  3.141592653589793238;

int bright[101][101][11];
int dp[101][101][11];
bool star[101][101];

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	memset(star,0,sizeof(star));

	int n,q,c,x,y,s,x1,x2,y1,y2,t;

	cin >> n >> q >> c; 	

	for(int i=0;i<n;i++){
		cin >> x >> y >> s;
		for(int k=0;k<=c;k++){
			bright[x][y][k] += (s+k)%(c+1);
		}
		star[x][y] = true;
	}

	for(int k=0;k<=c;k++){
		for(int i=1;i<=100;i++){
			for(int j=1;j<=100;j++){
				dp[i][j][k] = bright[i][j][k] - dp[i-1][j-1][k] + dp[i-1][j][k] + dp[i][j-1][k]; 
			}
		}
	}

	for(int l=0; l<q; l++){
		cin >> t >> x1 >> y1 >> x2 >> y2;
		t = t%(c+1);
		int sum = dp[x2][y2][t] - dp[x1-1][y2][t] - dp[x2][y1-1][t] + dp[x1-1][y1-1][t];
		cout << sum << endl;
	}

	return 0;
}
