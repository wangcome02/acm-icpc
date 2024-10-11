/*输入若干行，最后一行为0，表示结束
每行表示有k个好人和k个坏人，约瑟夫环中总人数就是2k
为了保证所有好人活下来，所有坏人都被淘汰，要选出一个最小的m，使得好人全部活下来
*/
#include<bits/stdc++.h>
using namespace std;
int k;
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
    cout << "helloworld" << endl;
    /*fill(q, q + 2*k, 1);
    for(int i = 0; i < 2*k; i++){
        cout << q[i] << endl;
    }
    int m = k, idx = 0, cnt = 0;
        while(1){
            cout << idx << endl;
            if(q[(++idx) % 2*k] == 0){
                ++idx;
            }else{
                if(++cnt == m){
                    idx %= 2*k;
                    q[idx] = 0;
                }
            }
            if(jdg())   break;
            else    m++;
        }*/
    //cout << m << endl;
    /*while(cin >> k){
        if(k == 0)  break;
        fill(q, q + 2*k, 1);
        int m = k, idx = 0, cnt = 0;
        while(1){
            cout << idx << endl;
            if(q[(++idx) % 2*k] == 0){
                ++idx;
            }else{
                if(++cnt == m){
                    idx %= 2*k;
                    q[idx] = 0;
                }
            }
            if(jdg())   break;
            else    m++;
        }
        cout << m << endl;
    }*/
    return 0;
}