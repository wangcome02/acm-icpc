#include<bits/stdc++.h>
using namespace std;
/*核心算法是由于gcd(a,b) = gcd(b, a) = gcd(a, b mod a) = gcd(b mod a, a) = gcd(b, x * b + a)
此时找出小于m的所有互质的数字后（共n个为1组），求第k个和m互质的数字可以使用如下公式：
i = k / n, j = k % n, res = i * m + pri[j - 1],注意j为0时应当还是在上一组中，需要i * m - 1*/
int gcd(int a, int b){
    return b == 0 ? a : gcd(b , a % b);
}
long long m,k;  //这里开int也没事
int main(){
    while(cin >> m >> k){
        vector<int> prime;
        for(int i = 1; i < m; i++){
            if(gcd(m, i) == 1)  prime.push_back(i);
        }
        // for(auto x : prime){
        //     cout << x << ' ';
        // }
        // cout << endl;
        int j = k % prime.size();
        cout << prime.size() << endl;
        //cout << (k / prime.size()) * m + prime[j - 1] << endl;
        if(j != 0)
            cout << k / prime.size() * m + prime[j - 1] << endl;
        else
            //当j为0表示某一组的最后一个
            cout << (k / prime.size() - 1) * m + prime.back() << endl;
    }
}