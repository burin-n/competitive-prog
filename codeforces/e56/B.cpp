#include <bits/stdc++.h>
using namespace std;

int main(){
    int t;
    string str;

    cin >> t;
    while(t--){
        cin >> str;
        bool is_palindrome = true;
        int N = str.length();
        int s_pos = 0;

        for(int i=0;i<N/2;i++){
            if(str[i] != str[N-i-1])
                is_palindrome = false;
            if(str[i] !=  str[0])
                s_pos = i;
        }
        if(is_palindrome){
            if(s_pos == 0){
                if(str[N/2] != str[0])
                    swap(str[0], str[N/2]);

                else{
                    cout << -1 << '\n';
                    continue;
                }
            }
            else
                swap(str[0], str[s_pos]);
        }
        cout << str << '\n';
    }
}
