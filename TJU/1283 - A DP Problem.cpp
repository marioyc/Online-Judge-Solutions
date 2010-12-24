#include <iostream>
#include <cstdio>
#include <cmath>
#include <string>
#include <map>

using namespace std;

pair<int, int> parse(string s){
    pair<int, int> ret = make_pair(0,0);
    int L = s.size(),pos = 0;
    
    while(pos<L){
        int sign = 1;
        
        if(s[pos]=='-' || s[pos]=='+'){
            if(s[pos]=='-') sign = -1;
            ++pos;
        }
        
        bool found = false;
        int val = 0;
        
        while(pos<L && s[pos]>='0' && s[pos]<='9'){
            val = val*10+s[pos]-'0';
            found = true;
            ++pos;
        }
        
        if(!found) val = 1;
        
        bool var = false;
        
        if(pos<L && s[pos]=='x'){
            var = true;
            ++pos;
        }
        
        if(var) ret.first += sign*val;
        else ret.second += sign*val;
    }
    
    return ret;
}

int main(){
    int T;
    string s;
    
    cin>>T;
    
    while(T--){
        cin>>s;
        int ind = s.find('=');
        
        pair<int, int> ret1 = parse(s.substr(0,ind));
        pair<int, int> ret2 = parse(s.substr(ind+1,s.size()-ind-1));
        
        int a = ret1.first-ret2.first,b = ret2.second-ret1.second;
        
        if(a<0){
            a = -a;
            b = -b;
        }
        
        if(a!=0){
            if(b>=0 && b<a) printf("0\n");
            else printf("%.0f\n",floor((double)b/a));
        }else{
            if(b==0) puts("IDENTITY");
            else puts("IMPOSSIBLE");
        }
    }
    
    return 0;
}
