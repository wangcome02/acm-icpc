/*1960年计算器为4位，最大表示数字为15，而3！=6，4！=24，因此评级为3
故此题根据年份y计算出计算机位数：y1=(y-1960)/10 + 2位，故最大表示无符号数为2^y1-1,
此时找出最大n！<= 2^y1-1即 <2^y1的n
取对数计算以降低时空复杂度*/
#include<bits/stdc++.h>
using namespace std;
int y;
int main(){
    while(cin >> y && y){
        double y1 = (y - 1960)/10 + 2;
        double res = 0, ans = 1;
        while(res < pow(2, y1)){
            res += log2f(ans++);
            //cout << "res:"<< res << endl;
        }
        //当ans达到目标值之后，由于后++的缘故此时变为ans+1
        //另外由于此时res仍然满足条件，故在下一轮循环中变成ans+2
        cout << ans - 2 << endl;
    }
}