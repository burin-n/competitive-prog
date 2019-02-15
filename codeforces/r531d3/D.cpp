#include <bits/stdc++.h>
using namespace std;

int N, cnt[4];
char str[int(3e5+10)];

int main(){

    scanf("%d",&N);
    scanf("%s", str);


    for(int i=0;i<N;i++){
        cnt[str[i] - '0']++;       
    }

    for(int i=0;i<N && cnt[0]<N/3; i++){
        if(str[i] != '0' && cnt[str[i]-'0'] > N/3){
            cnt[str[i]-'0']--;
            str[i] = '0';
            cnt[0]++;
        }
    }

    for(int i=N-1;i>=0 && cnt[2] < N/3;i--){
        if(str[i] != '2' && cnt[str[i]-'0'] > N/3){
            cnt[2]++;
            cnt[str[i]-'0']--;
            str[i] = '2';

        }
    }

    int j=0;
    while(cnt[1] < N/3 && cnt[2] > N/3){
        if(str[j] == '2'){
            str[j] = '1';
            cnt[1]++;
            cnt[2]--;
        }
        j++;
    }

    j=N-1;
    while(cnt[1] < N/3 && cnt[0] > N/3){
        if(str[j] == '0'){
            str[j] = '1';
            cnt[1]++;
            cnt[0]--;
        }
        j--;
    }

    printf("%s\n", str);
    return 0;
}
