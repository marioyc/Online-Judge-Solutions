#include <cstdio>
#include <cstring>

using namespace std;

int main(){
    char s1[10001],s2[10001];
    
    scanf("%s",s1);
    
    int L = strlen(s1);
    
    for(int i = 0;i < L;++i) s2[L-1-i] = s1[i];
    
    int pref[10001];
    
    pref[0] = 0;
    
    for(int i = 1,k = 0;i < L;++i){
        while(k > 0 && s2[k] != s2[i]) k = pref[k - 1];
        if(s2[k] == s2[i]) ++k;
        pref[i] = k;
    }
    
    int k = 0;
    
    for(int i = 0;i < L;++i){
        while(k > 0 && s1[i] != s2[k]) k = pref[k - 1];
        if(s1[i] == s2[k]) ++k;
        if(k == L) k = pref[k - 1];
    }
    
    printf("%s",s1);
    for(int i = k;i < L;++i) putchar(s2[i]);
    putchar('\n');
    
    return 0;
}
