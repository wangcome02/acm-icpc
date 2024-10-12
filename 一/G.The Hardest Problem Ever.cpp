/*读入字符串，将字符串中的字符沿字母表左移5位*/
#include<bits/stdc++.h>
using namespace std;
string str;
int main(){
    while(cin >> str){
        if(str == "START"){
            continue;
        }    
        if(str == "END"){
            printf("\n");
            continue;
        }    
        if(str == "ENDOFINPUT")    break;
        for(auto &x : str){
            //cout << "str:" << str << "调用"  << endl;
            if(x >= 'A' && x <= 'Z'){
                //cout << 1 << endl;
                int pos = (x - 'A' - 5 + 26) % 26;
                //cout << pos << ' ';
                x = 'A' + pos;
            }
        }
        cout << str << ' ';
    }
}