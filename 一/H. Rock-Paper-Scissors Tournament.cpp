/*使用win、lose数组记录每一名选手胜负状态，每次重置数组后巧妙利用scanf提取出选手号和手势，判胜负*/
#include<bits/stdc++.h>
using namespace std;
int n, k;
const int N = 110;
int win[N],lose[N];
int tag = 0;
int main(){
    while(scanf("%d", &n) && n){
        //每一轮进行数组重置
        memset(win, 0, sizeof(win));
        memset(lose, 0, sizeof(lose));
        cin >> k;
        int cnt = k*n*(n-1)/2;
        int p1, p2;
        char s1[11], s2[11];
        while(cnt--){
            //scanf使用小技巧，可以忽略空格换行tab等提取数字或数组
            scanf("%d%s%d%s",&p1, s1, &p2, s2);
            if(s1[0] == 'r' && s2[0] == 'p' || s1[0] == 'p' && s2[0] == 's' || s1[0] == 's' && s2[0] == 'r')    
                lose[p1]++,win[p2]++;
            else if(s2[0] == 'r' && s1[0] == 'p' || s2[0] == 'p' && s1[0] == 's' || s2[0] == 's' && s1[0] == 'r')
                lose[p2]++,win[p1]++;
        }
        for(int i = 1; i <= n; i++){
            //进行比分计算时把分母强转成double，不然会报0
            double res = (double)win[i]/(win[i] + lose[i]);
            printf("%.3lf\n", res);
        }
        printf("\n");
    }
    
}