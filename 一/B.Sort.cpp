#include<bits/stdc++.h>
using namespace std;
int n,m;
const int N = 1e6+10, M = 5e5;
//手写哈希表，将数值映射到数组下标
int ha[N];

int main(){
    cin >> n >> m;
    int tmp;
    for(int i = 0; i < n; i++){
        cin >> tmp;
        ha[tmp + M]++;
    }
    for(int i = M; i >= -M ; i--){
        if(ha[i + M]){
            cout << i << ' ';
            m--;
            //如果m=0，说明已经输出了m个数，结束循环
            if(!m)  break;
            //输出一个数后，将该数的个数减一，同时将i+1的个数加一
            ha[i + M]--;
            i++;
        }
    }
    return 0;
}