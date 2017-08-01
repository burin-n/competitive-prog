#include <iostream>
#include <algorithm>
using namespace std;

int main(){
	int a,b,c,d;
	cin>>a>>b>>c>>d;
	int t = min(min(a,c),d);	
	a-=t; c-=t; d-=t;
	int w = min(a,b);
	cout<< 256*t + 32*w <<endl;
	return 0;
}
