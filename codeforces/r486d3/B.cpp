#include <bits/stdc++.h>
using namespace std;
#define endl '\n'

// is a be substr of b
bool issubstr(string a, string b){
	if( a.length() > b.length() ) return false;
	for(int i = 0; i <= b.length() - a.length(); i++ ){
		if( b.compare(i, a.length(), a) == 0 )
			return true;
	}	
	return false;
}

int main(){
	ios_base::sync_with_stdio(false);
	int n;
	cin >> n;
	string str[101];
	for(int i=0;i<n;i++)
		cin >> str[i];
	sort(str,str+n, [](string a,string b) -> bool {
				return a.length() < b.length();
			});
	bool ans = true;
	for(int i=0;i<n-1;i++){
		if(!issubstr(str[i],str[i+1]))
			ans = false;
	}
	if(ans){
		cout << "YES\n";
		for(int i=0; i<n; i++)
			cout << str[i] << endl;
	}
	else cout << "NO\n";
	return 0;
}
