#include <iostream>
#include <cstdio>
#include <string>

using namespace std;

#define MAX_L 150001

string P;
int L,f[MAX_L];

void prefixFunction(){
    L = P.size();
    int k = 0;
    f[0] = 0;
    
    for(int i = 1;i<L;++i){
        while(k>0 && P[k]!=P[i]) k = f[k-1];
        if(P[k]==P[i]) ++k;
        f[i] = k;
    }
}

int main(){
    string s1,s2;
    cin>>s1>>s2;
    P = s1+"*"+s2;
    
    prefixFunction();
    
    int L1 = s1.size(),L2 = s2.size();
    int s[75000],sz = 0,pos = L2-1;
    
    while(f[L1+1+pos]>0){
        pos -= f[L1+1+pos];
        s[sz] = pos+1;
        ++sz;
    }
    
    if(pos!=-1) printf("Yes\n");
    else{
        printf("No\n");
        
        for(int i = sz-1;i>0;--i){
            for(int j = s[i];j<s[i-1];++j)
                putchar(s2[j]);
            putchar(' ');
        }
        
        for(int i = s[0];i<L2;++i)
            putchar(s2[i]);
        
        printf("\n");
    }
    
    return 0;
}
