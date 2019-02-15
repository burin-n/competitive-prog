#include <bits/stdc++.h>
using namespace std;

string s;

int find(char target, int p, int dir){
    int stop = -1;
    if(dir == 1) stop = s.length();
    while(p != stop && s[p] != target) p+=dir;
    return p;
}

int main(){
    cin >> s;
    int l=0, r=s.length()-1; 
    bool can = true;
    
    l = find('[', 0, 1);
    if(l > s.length()-4){
        cout << -1 << endl;
        return 0;
    }
        
    
    r = find(']', s.length()-1, -1);
    if(r < 3){
        cout << -1 << endl;
        return 0;
    }

    int cl = find(':', l+1, 1);
    int cr = find(':', r-1, -1);
    
    if(cl < cr){
        int cnt = 0;
        for(int i=cl+1; i<cr; i++)
            if(s[i] == '|') cnt++;
        cout << 4+cnt << endl;
    }
    else{
        cout << -1 << endl;
    }
    
    
    return 0;
}
