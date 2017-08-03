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
	string tb[10];
	for(int i=0;i<10;i++)
		cin >> tb[i];

	bool isWin = false;
	
	for(int i=0;i<10;i++){
		for(int j=0;j<10;j++){
			if(tb[i][j] == '.'){
				int c, t1,t2;
				// horizontal
				c = 1;
				t1 = t2 = j;
				while(--t1>=0 && tb[i][t1] == 'X') c++;
				while(++t2<10 && tb[i][t2] == 'X') c++;
				if(c>=5) isWin = true;
				// vertical 
				c = 1;
				t1 = t2 = i;
				while(--t1>=0 && tb[t1][j] == 'X') c++;
				while(++t2<10 && tb[t2][j] == 'X') c++;
				if(c>=5) isWin = true;
				// diagonal right
				c = 1;
				t1 = t2 = 1;
				while(i-t1>=0 && j+t1<10 && tb[i-t1][j+t1] == 'X') c++,t1++;
				while(i+t2<10 && j-t2>=0 && tb[i+t2][j-t2] == 'X') c++,t2++;
				if(c>=5) isWin = true;
				// diagonal left
				c = 1;
				t1 = t2 = 1;
				while(i-t1>=0 && j-t1>=0 && tb[i-t1][j-t1] == 'X') c++,t1++;
				while(i+t2<10 && j+t2<10 && tb[i+t2][j+t2] == 'X') c++,t2++;
				if(c>=5) isWin = true;

			}
		}
	}

	if(isWin) cout << "YES" << endl;
	else cout << "NO" << endl;
	return 0;
}
