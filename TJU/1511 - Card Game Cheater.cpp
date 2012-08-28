#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

int val1(char c){
    if(c >= '2' && c <= '9') return c - '0';
    if(c == 'T') return 10;
    if(c == 'J') return 11;
    if(c == 'Q') return 12;
    if(c == 'K') return 13;
    return 14;
}

int val2(char c){
    if(c == 'H') return 3;
    if(c == 'S') return 2;
    if(c == 'D') return 1;
    return 0;
}

int main(){
    int T,n,a[26],b[26];
    char s[3];
    
    scanf("%d",&T);
    
    while(T--){
        scanf("%d",&n);
        
        for(int i = 0;i < n;++i){
            scanf("%s",s);
            a[i] = 4 * val1(s[0]) + val2(s[1]);
        }
        
        for(int i = 0;i < n;++i){
            scanf("%s",s);
            b[i] = 4 * val1(s[0]) + val2(s[1]);
        }
        
        sort(a,a + n);
        sort(b,b + n);
        
        int ans = 0;
        
        for(int i = 0,j = 0;i < n && j < n;++i){
            while(j < n && a[i] > b[j]) ++j;
            
            if(j < n){
                ++ans;
                ++j;
            }
        }
        
        printf("%d\n",ans);
    }
    
    return 0;
}
