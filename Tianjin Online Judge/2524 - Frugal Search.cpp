#include <cstdio>
#include <cstring>
#include <string>
#include <vector>
#include <algorithm>

#include <iostream>

using namespace std;

vector<string> W,uns,pos,neg;

string solve(){
    for(int i=W.size()-1;i>=0;--i){
        for(int j=uns.size()-1;j>=0;--j){
            bool found = false;
            
            for(int k=uns[j].size()-1;k>=0;--k){
                for(int p=W[i].size()-1;p>=0;--p)
                    if(W[i][p]==uns[j][k])
                        found = true;
            }
            
            if(!found) continue;
            found = true;
            
            for(int k=pos[j].size()-1;k>=0;--k){
                if(W[i].find(pos[j][k])==string::npos)
                    found = false;
            }
            
            if(!found) continue;
            found = false;
            
            for(int k=neg[j].size()-1;k>=0;--k){
                if(W[i].find(neg[j][k])!=string::npos)
                    found = true;
            }
            
            if(found) continue;
            return  W[i];
        }
    }    
    
    return "NONE";
}

int main(){
    char s[80];    
    
    while(true){
        W.clear();
        
        scanf("%s",s);
        if(s[0]=='#') break;
        
        W.push_back(string(s));
        
        while(true){
            scanf("%s",s);
            if(s[0]=='*') break;
            W.push_back(string(s));
        }
        
        sort(W.rbegin(),W.rend());
        
        while(true){
            scanf("%s",s);
            if(s[0]=='*') break;
            
            string aux(s);
            aux += '|';
            
            int cur = 0,L = aux.size();
            uns.clear(); pos.clear(); neg.clear();
            
            while(cur<L){
                int nxt = aux.find('|',cur);
                string u,p,n;
                
                for(int i=cur;i<nxt;++i){
                    if(aux[i]=='+' || aux[i]=='-'){
                        if(aux[i]=='+') p += aux[i+1];
                        else n += aux[i+1];
                        ++i;
                    }else u += aux[i];
                }
                
                uns.push_back(u);
                pos.push_back(p);
                neg.push_back(n);
                cur = nxt+1;
            }
            
            printf("%s\n",solve().c_str());
        }
        
        printf("$\n");
    }
    
    return 0;
}
