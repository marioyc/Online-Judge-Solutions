#include <cstdio>

using namespace std;

int L,pref[2500],i,pos;
char s[2501],c;

int main(){
    bool first = true;    
    
    while(scanf("%d\n",&L)!=EOF){
        fgets(s,2501,stdin);
        pref[0] = 0;
        
        i = 1;
        
        while(i<L){
            pos = pref[i-1];
            
            while(pos>0 && s[i]!=s[pos]) pos = pref[pos-1];
            if(s[i]==s[pos]) ++pos;
            
            pref[i] = pos;
            ++i;
        }
        
        pos = i = 0;
        
        if(!first) puts("");
        first = false;
        
        while((c = getchar())!=EOF && c!='\n'){
            while(pos>0 && c!=s[pos]) pos = pref[pos-1];
            if(c==s[pos]) ++pos;
            
            if(pos==L){
                printf("%d\n",i+1-L);
                pos = pref[L-1];
            }
            
            ++i;
        }
    }
    
    return 0;
}
