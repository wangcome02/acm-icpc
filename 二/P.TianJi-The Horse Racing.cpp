/*
核心思想是将两人的马匹战力从大到小排序，使用贪心思想和双指针让田忌尽可能多地获胜（找出最大让tj[i]获胜的king[j]），并对使用过的king[j]
打一个标记表示已经用过了(st[j] = 1)
当j遍历完时说明已经达到最大胜场，此时统计平局数量eql = pos >= i ? pos - i + 1 : 0;
最终用胜场 - 负场进行结算
*/
#include<bits/stdc++.h>
using namespace std;
int n;
int main(){
    while(scanf("%d", &n) && n){
        vector<int> tj(n);
        vector<int> king(n);
        vector<int> st(n , 0);
        for(int i = 0; i < n; i++){
            scanf("%d", &tj[i]);
        }
        for(int i = 0; i < n; i++){
            scanf("%d ", &king[i]);
        }
        sort(tj.begin(), tj.end(), greater<int>());
        sort(king.begin(), king.end(), greater<int>());
        /*for(auto x : tj)    cout << x << ' ';
        cout << endl;
        for(auto x : king)    cout << x << ' ';
        cout << endl;*/
        // int lft = 0,rht = 0, win = 0, loss = 0;
        // for(; lft < n && rht < n; lft++){
        //     //cout << "left:" << lft << ' ' << "right:" << rht << endl;
        //     while(tj[lft] < king[rht]){
        //         ++ rht;
        //         break;
        //         loss ++;   
        //     }
        //     if(rht < n){
        //         win++;a
        //         rht++;
        //     }
        //     //cout << "win:" << win <<endl;
        // }

        int i = 0, j = 0, win = 0, eql = 0, pos = n-1;
        for(; i < n; i++){
            while(tj[i] <= king[j] && j < n) j++;
            if(j >= n){
                //统计平局个数
                while(st[pos]) pos--;
                break;
            }
            win++;
            st[j++] = 1;
        }
        cout << pos << ' ' << i << endl;
        eql = pos < i ? 0 : pos - i + 1;
        cout<<win<<" "<<eql<<endl;

        cout << (win - (n - win - eql)) * 200 << endl;
    }
}