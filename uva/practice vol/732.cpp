#include <iostream>
#include <string>
#include <stack>
#include <algorithm>
using namespace std;
int n;
string s1,s2,order;
stack<char>s;
int j,k;

void f(int l,int in,int out){
	if( l == 2*n ){
		cout<<order[0];
		for(int i=1;i<(int)order.size();i++)
			cout<<" "<<order[i];	
		cout<<endl;
	}		
	else{
		if(in){
			order[l]='i';
			s.push(s1[j]);
			j++;
			f(l+1,in-1,out);
			j--;
			s.pop();
		}
		if(out){
			if(!s.empty() && s.top() == s2[k]){		
				s.pop();
				order[l]='o';
				k++;
				f(l+1,in,out-1);	
				k--;	
				s.push(s2[k]);
			}
		}
	}
}

int main(){
	while( (cin>>s1) ){
		j=k=0;
		while(!s.empty()) s.pop();
		cin>>s2;
		cout<<"["<<endl;
		order="";
		n = (int)s1.size();
		for(int i=0;i<2*n;i++) order+='i';;
		if(s1.size() == s2.size()){
			f(0,n,n);
		}
		cout<<"]"<<endl;
	}
	return 0;
}
