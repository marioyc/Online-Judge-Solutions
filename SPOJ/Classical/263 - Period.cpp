#include <cstdio>

using namespace std;

char s[1000001];
int L,pref[1000000];

int main(){
    int T;
    scanf("%d",&T);
    
    for(int tc = 1;tc<=T;++tc){
        scanf("%d %s",&L,s);
        pref[0] = 0;
        
        printf("Test case #%d\n",tc);
        
        for(int i = 1,pos = 0;i<L;++i){
            pos = pref[i-1];
            
            while(pos>0 && s[pos]!=s[i]) pos = pref[pos-1];
            if(s[pos]==s[i]) ++pos;
            pref[i] = pos;
            
            if(pos>0 && (i+1)%(i+1-pos)==0)
                printf("%d %d\n",i+1,(i+1)/(i+1-pos));
        }
        
        puts("");
    }
    
    return 0;
}
