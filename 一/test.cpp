/*输入若干行，最后一行为0，表示结束
每行表示有k个好人和k个坏人，约瑟夫环中总人数就是2k
为了保证所有好人活下来，所有坏人都被淘汰，要选出一个最小的m，使得好人全部活下来
*/
#include<bits/stdc++.h>
using namespace std;
int k,n;
int q[30];
bool jdg(){
    int tag = 1;
    for(int i = 0; i < k; i++){
        tag &= q[i];
    }
    if(tag) return true;
    else{
        int tag1 = 0;
        for(int i = k; i < 2*k; i++){
            tag1 |= q[i];
        }
        if(!tag1)   return true;
        else    return false;   
    }
}
int main(){
    while(scanf("%d", &k) && k){
        if(k == 0)  break;
        fill(q, q + 2*k, 1);
        n = 0;
        int m = k + 1, idx = 0, cnt = 0;
        while(1){
            //cout << "idx: " <<idx  << " cnt: " << cnt << endl;
            if(q[idx]){
                if(++cnt == m){
                    q[idx] = 0;
                    cnt = 0;
                    n++;
                    //3cout << "n: " << n << endl;
                }
            }
            idx = ++idx % (2*k);
            /*for(int i = 0; i < 2*k; i++){
                cout << q[i] << ' ';
            }
            cout << endl;*/
            if(n == k){
                //cout << "jdg:" << jdg() << endl;
                if(!jdg()){
                    m++;
                    idx = 0, cnt = 0;
                    fill(q, q + 2*k, 1);
                    n = 0;
                }else break;
            }
               
        }
        printf("%d\n", m);
    }
    return 0;
}