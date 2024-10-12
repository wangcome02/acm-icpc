/*尼姆博弈，对堆数进行异或求和，为0时为平衡态，先手必败，否则必胜*/
#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    while(scanf("%d", &n) != EOF){  //这里用cin会超时
        vector<int> arr(n);
        for(int i = 0; i < n; i++)  scanf("%d", &arr[i]);
        for(int i = 1; i < n; i++){
            arr[0] ^= arr[i];
        }
        if(arr[0])  printf("Yes\n");
        else    printf("No\n");
    }
}
