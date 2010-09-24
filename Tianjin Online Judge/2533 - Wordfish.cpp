#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int f(string s){
    int aux=INT_MAX;
    for(int i=0;i+1<s.size();i++) aux=min(aux,abs(s[i+1]-s[i]));
    return aux;
}

struct pass{
    string s;
    int d;
    
    pass(){
    }
    
    pass(string _s){
        s=_s;
        d=f(s);
    }
    
    bool operator < (pass X) const{
        if(d!=X.d) return d>X.d;
        return s<X.s;
    }
};

int main(){
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
    
    string s,aux;
    pass L[21];
    
    while(cin>>s){
        L[0]=pass(s);
        
        aux=s;
        for(int i=1;i<11;i++){
            prev_permutation(aux.begin(),aux.end());
            L[i]=pass(aux);
        }
        
        aux=s;
        for(int i=11;i<21;i++){
            next_permutation(aux.begin(),aux.end());
            L[i]=pass(aux);
        }
        
        sort(L,L+21);
        
        cout<<L[0].s<<L[0].d<<endl;
    }
    
    return 0;
}
