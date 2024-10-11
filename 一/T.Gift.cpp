#include<bits/stdc++.h>
using namespace std;
int n,m;
#define N 1e6+10

int main(){
    while(cin >> n >> m){
        if(n == 0 && m == 0)    break;  
        bool tag = false;
        function<bool(int, int)> dfs = [&] (int pos, int i) -> bool{
            
            if(pos <= 0 || pos >= n + 1)  return false;
            if(pos == m)    return true;
            return dfs(pos + 2 * i - 1, i + 1) || dfs(pos - ( 2 * i - 1 ), i + 1);
        };
        if(n >= 50 || dfs(1, 2))   cout << "Let me try!" << endl;
        else    cout << "Don't make fun of me!" << endl;
    }
    return 0;
}