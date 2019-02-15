#include <bits/stdc++.h>
using namespace std;

int main(){
	int n,k,a;
	cin >> n >> k;
	map<int,int> s;
	for(int i=0;i<n;i++){
		cin >> a;
		s[a] = i+1;
	}
	if(s.size() >= k){
		printf("YES\n");
		for(pair<int,int> e : s){
			if(k<=0){
				break;
			}
			else{
				printf("%d ",e.second);
				k--;
			}
		}
	}
	else{
		printf("NO\n");
	}
}
