#include <cstdio>
#include <algorithm>
using namespace std;
int main(){
	int n,k,a[1000];
	scanf("%d %d",&n,&k);

	for(int i=0;i<n;i++){
		scanf("%d",&a[i]);
	}
	int ans=0,need=k-a[0];
	for(int i=1;i<n;i++){
		ans+=max(need-a[i],0);
		a[i]+=max(need-a[i],0);
		need=max(0,k-a[i]);
	}
	printf("%d\n",ans);
	for(int i=0;i<n;i++)
		printf("%d ",a[i]);
}
