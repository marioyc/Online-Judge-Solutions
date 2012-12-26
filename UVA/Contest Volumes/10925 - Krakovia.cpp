#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

string add(string a, string b){
    int La = a.size(),Lb = b.size();
    string ret;
    
    for(int i = 0,c = 0;i < La || i < Lb || c > 0;++i,c /= 10){
        if(i < La) c += a[i] - '0';
        if(i < Lb) c += b[i] - '0';
        
        ret += (char)('0' + c % 10);
    }
    
    return ret;
}

string div(string a, int b){
    int La = a.size(),x = 0;
    string ret;
    
    for(int i = 0;i < La;++i){
        x = x * 10 + a[i] - '0';
        ret += (char)('0' + x / b);
        x %= b;
    }
    
    while(ret.size() > 1 && ret[0] == '0')
        ret = ret.substr(1,ret.size() - 1);
    
    return ret;
}

int main(){
    ios::sync_with_stdio(0);
    int tc = 1,N,F;
    
    while(true){
        cin >> N >> F;
        if(N == 0) break;
        
        string sum = "0",x;
        
        for(int i = 0;i < N;++i){
            cin >> x;
            reverse(x.begin(),x.end());
            sum = add(sum,x);
        }
        
        reverse(sum.begin(),sum.end());
        
        cout << "Bill #" << tc++ << " costs " << sum << ": each friend should pay " << div(sum,F) << "\n\n";
    }
    
    return 0;
}
