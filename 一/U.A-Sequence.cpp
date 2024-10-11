#include<bits/stdc++.h>
using namespace std;
const int D = 31, N = 31000;
int n, sum, case_n;
int cnt[N],a[D];
int main(){
    while(scanf("%d", &n) != EOF){
        ++case_n;   //记录样例个数
        bool tag = true;
        sum = 0;    //记录元素和
        for(int i = 0; i < n; i++){
            cin >> a[i];
            sum += a[i];
        }
        //由于第一个元素要求>=1,且数组必须升序，因此判断该数组是否为A序列的可能序列
        if(a[0] < 1) tag = false;
        for(int i = 0; i < n-1; i++){
            if(a[i] > a[i + 1])    tag = false;
        }     
        //如果为A序列判定的整体思路：遍历数组中所有变量，使用cnt数组表示数字是否可计算
        //如果可计算，则直接跳出循环，tag为false，否则更新cnt数组
        if(tag){
            memset(cnt, 0, sizeof(cnt));    //cnt数组表示以idx为索引的数字是否可以由该序列前若干个数字求和得出
            cnt[0] = 1;                     //数字0初始化为可计算
            for(int i = 0; i < n; i++){
                if(cnt[a[i]]){              
                    tag = false;
                    break;
                }
                //此时判断数组中元素a[i]是否可计算，从后向前遍历cnt数组
                //如果采用从前向后遍历，会导致cnt中索引小的元素先更新，用更新完的数更新cnt中将要更新的索引较大的数字
                for(int j = sum - a[i]; j >= 0; j--){
                    //如果发现j是可计算的，那么j + a[i]显然可计算（背包思想）
                    if(cnt[j])  cnt[j + a[i]] = 1;
                }
            }
        }
        cout << "Case #" << case_n << ": ";
        for(int i = 0; i < n; i++){
            cout << a[i] << (i == n-1 ? "\n" : " ");
        }
        if(tag) cout << "This is an A-sequence." << endl;
        else    cout << "This is not an A-sequence." << endl;


        // printf("Case #%d: ", ++cnt_n);
        // for(int i = 0; i < n; i ++)     cout << a[i] << (i == n-1 ? "\n" : " ");
        // if(flag)    cout << "This is an A-sequence.\n";
        // else cout << "This is not an A-sequence.\n";      
    }
    return 0;
}

