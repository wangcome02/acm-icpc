#include<bits/stdc++.h>
using namespace std;
#define MAXN 1299710
int lft[MAXN], rht[MAXN], notprime[MAXN];
//素数筛
void prepare(){
    notprime[0] = notprime[1] = 1;
    for(int i = 0; i < MAXN; i++){
        if(notprime[i]) continue;
        for(int j = 2 * i; j < MAXN; j += i){
            notprime[j] = 1;    //主义这里是j
        }
    }
}
//使用类似于前缀后缀和的思想
void init(){
    lft[0] = lft[1] = 2;
    rht[MAXN] = rht[MAXN - 1] = 1299709;
    for(int i = 2; i < MAXN-1; i++){
        if(!notprime[i]){
            lft[i] = i;
        } 
        else{
            lft[i] = lft[i-1];
        }
    }
    for(int i = MAXN - 2; i >= 0; i--){
        if(!notprime[i]){
            rht[i] = i;
        } 
        else{
            rht[i] = rht[i+1];
        }
    }
}
int main(){
    prepare();
    init();
    // for(int i = 0; i < 100; i++){
    //     cout << lft[i] << ' ';
    // }
    // cout << endl;
    // for(int i = 0; i < 100; i++){
    //     cout << rht[i] << ' ';
    // }
    int k;
    while(scanf("%d", &k) && k){
        printf("%d\n", rht[k] - lft[k]);
    }
    return 0;
}