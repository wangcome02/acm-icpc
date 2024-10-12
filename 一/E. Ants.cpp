/*这道题的本质在于将蚂蚁转向进行忽略，意识到蚂蚁还是走到了原本行走方向的头，因为蚂蚁转向无非是由碰到的蚂蚁代替自己将原来应该继续行走的
路途走下去而已
左端蚂蚁（arr[i] <= len/2）从左侧掉下去最快存入minlen，从右侧最慢存入maxlen
右端蚂蚁从右侧掉下去最快存入minlen，从左侧最慢存入maxlen
因为要保证所有蚂蚁都掉下去了，故需要取两个数组中的最长掉落时间（排序后的末项）*/
#include<bits/stdc++.h>
using namespace std;
int nca, len, n;
int main(){
    cin >> nca;
    while(nca--){
        scanf("%d %d",&len,&n);
        vector<int> arr(n, 0);
        for(int i = 0; i < n; i++)  scanf("%d", &arr[i]);
        vector<int> maxlen,minlen;
        for(int i = 0; i < n; i++){
            maxlen.push_back(2 * arr[i] <= len ? len - arr[i] : arr[i]);
            minlen.push_back(2 * arr[i] <= len ? arr[i] : len - arr[i]);
        }
        sort(maxlen.begin(), maxlen.end());
        sort(minlen.begin(), minlen.end());
        printf("%d %d\n", minlen.back(), maxlen.back());
    }
}