#include <iostream>
#include <string>
#include <vector>
#include <cstring>
#include <cstdio>
using namespace std;
vector<int>adj[30];
int node[30],n;
bool chk;

void f(int l,string ans){
	if(l==n){
		printf("%c",ans[0]-'0'+'A');
		for(int i=1;i<ans.size();i++){
			printf(" %c",ans[i]-'0'+'A');
		}
		printf("\n");

		chk = true;
	}
	else{
		for(int i=0;i<26;i++){
			if( node[i] == 0 ){
				node[i]--;
				for(int e : adj[i] ){
					node[e]--;
				}
				f(l+1,ans+to_string(i));
				for(int e : adj[i] ){
					node[e]++;
				}
				node[i]++;
			}
		}
	}
}

int main(){
	int T;
	cin>>T;
	string str;
	scanf(" ");

	while(T--){
		n=0;
		for(int i=0;i<30;i++) node[i]=-1;

		getline(cin,str);

		for(char e : str){
			if(e == ' ') continue;
			node[e-'A'] = 0;	
			n++;
		}			
		getline(cin,str);
		for(int i=0;i<str.size();i+=4){
			if(str[i]==' ') i++;
			cout<<str[i]<<" "<<str[i+2]<<endl;
			adj[(int)(str[i]-'A')].push_back((int)(str[i+2]-'A'));	
			node[str[i+2]-'A']++;
		}
		chk = false;
		f(0,"");
		if(!chk) printf("NO\n");
	}	
	return 0;
}
