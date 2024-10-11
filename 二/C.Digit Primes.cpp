#include<bits/stdc++.h>
using namespace std;
#define MAXN 1000010
int cnt, sum_cnt[MAXN], notprime[MAXN];
int sum_digit(int x){
    int res = 0;
    while(x)    res += x % 10, x /= 10;
    return res;
}

void prepare( ){
    notprime[0] = 1, notprime[1] = 1;
    for(int i = 0; i < MAXN; i++){
        //printf("i : %d, cnt : %d\n", i, cnt);
        sum_cnt[i] = cnt;
        if(notprime[i]) continue;
        if(!notprime[sum_digit(i)]) cnt++, sum_cnt[i]++;
        //printf("i : %d, cnt : %d\n", i, cnt);
        for(int j = 2*i; j < MAXN; j += i){
            notprime[j] = 1;
        }       
    }
    /*for(int i = 0; i < 100; i++){
        cout << sum_cnt[i] << ' ';
    }*/
}
int main(){
    prepare();
    int n, a, b;
    cin >> n;
    for(int i = 0; i < n; i++){
        scanf("%d %d", &a, &b);
        printf("%d\n", sum_cnt[b] - sum_cnt[a - 1]);
    }
    return 0;
}
