#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

string add(string a, string b){
    int L1 = a.size(),L2 = b.size();
    int L = max(L1,L2),c = 0;
    
    a = string(L-L1,'0')+a;
    b = string(L-L2,'0')+b;
    
    string ret;
    
    for(int i = L-1;i>=0;--i){
        int s = (a[i]-'0')+(b[i]-'0')+c;
        c = s/10;
        s %= 10;
        ret += (char)(s+'0');
    }
    
    if(c!=0) ret += (char)(c+'0');
    reverse(ret.begin(),ret.end());
    
    return ret;
}

string reverse(string a){
    reverse(a.begin(),a.end());
    int L = a.size(),cont = 0;
    
    for(int i = 0;i<L-1;++i)
        if(a[i]=='0') ++cont;
        else break;
    
    return a.substr(cont,L-cont);
}

int main(){
    ios::sync_with_stdio(false);
    
    int T;
    cin>>T;
    
    string n1,n2;
    
    while(T--){
        cin>>n1>>n2;
        cout<<reverse(add(reverse(n1),reverse(n2)))<<endl;
    }
    
    return 0;
}
