#include <cstdio>
#include <string>
#include <algorithm>

using namespace std;

string f[251];

string add(string &a, string &b){
    string ret;
    int la = a.size(),lb = b.size();
    
    for(int i = 0,c = 0;i < la || i < lb || c > 0;++i){
        if(i < la) c += a[i] - '0';
        if(i < lb) c += b[i] - '0';
        ret += '0' + c % 10;
        c /= 10;
    }
    
    return ret;
}

int main(){
    f[0] = f[1] = "1";
    
    for(int i = 2;i <= 250;++i){
        f[i] = "0";
        f[i] = add(f[i],f[i - 1]);
        f[i] = add(f[i],f[i - 2]);
        f[i] = add(f[i],f[i - 2]);
    }
    
    for(int i = 0;i <= 250;++i)
        reverse(f[i].begin(),f[i].end());
    
    int n;
    
    while(scanf("%d",&n) == 1)
        puts(f[n].c_str());
    
    return 0;
}
