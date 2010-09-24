/*
ID:zion_ba1
LANG:C++
TASK:calfflac
*/

#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main(){
    freopen("calfflac.in","r",stdin);
    freopen("calfflac.out","w",stdout);
    
    string s,x;
    bool end[20000];
    fill(end,end+20000,false);
    
    while(getline(cin,x)){
        s=s+x;
        end[s.size()-1]=true;
    }
    
    int L=s.size();
    
    char aux[20001];
    int ind[20000],sz=0;
    
    for(int i=0;i<L;i++){
        if(s[i]>='a' && s[i]<='z'){
            aux[sz]=s[i];
            ind[sz]=i;
            sz++;
        }else if(s[i]>='A' && s[i]<='Z'){
            aux[sz]=s[i]-'A'+'a';
            ind[sz]=i;
            sz++;
        }
    }
    
    int ans=0,u,v,l,st,e;
    
    for(int i=0;i<sz;i++){
        u=i-1;
        v=i+1;
        l=1;
        
        while(u>=0 && v<sz && aux[u]==aux[v]){
            u--;
            v++;
            l+=2;
        }
        
        if(ans<l || (ans==l && u<st)){
            ans=l;
            st=u+1;
            e=v-1;
        }
    }
    
    for(int i=1;i<sz;i++){
        u=i-1;
        v=i;
        l=0;
        
        while(u>=0 && v<sz && aux[u]==aux[v]){
            u--;
            v++;
            l+=2;
        }
        
        if(ans<l || (ans==l && u<st)){
            ans=l;
            st=u+1;
            e=v-1;
        }
    }
    
    printf("%d\n",ans);
    
    for(int i=ind[st];i<=ind[e];i++){
        printf("%c",s[i]);
        if(end[i]) printf("\n");
    }
    if(!end[ind[e]]) printf("\n");
    
    return 0;
}
