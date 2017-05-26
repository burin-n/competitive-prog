#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
int n,arr[20];
bool prime[100],av[20];
bool isValid(int i,int num){
	if(i==n-1) return prime[ num+arr[i-1] ] && prime[num+1];
	return prime[ num+arr[i-1] ] ;
}

void f(int index){
	if(index==n){
		printf("%d",arr[0]);
		for(int i=1;i<n;i++)
			printf(" %d",arr[i]);
		printf("\n");
	}
	else{
		for(int i=2;i<=n;i++){
			if( av[i] && isValid(index,i) ){
				av[i] = false;
				arr[index]=i;
				f(index+1);
				av[i]=true;
			}
		}
	}
}

int main(){
    int c=1;
	memset(prime,true,sizeof prime);
	memset(av,true, sizeof av);
	av[1] = false;
	prime[0]=prime[1]=false;
	for(int i=2;i<100;i++){
		for(int j=2;i*j<=100;j++)
			prime[i*j] = false;
	}
    while(scanf("%d",&n)>0){
		if(c>1) printf("\n");
		arr[0] = 1;
		printf("Case %d:\n",c++);
       	f(1);
    }
}
