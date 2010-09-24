#include <cstdio>
#include <cstring>

using namespace std;

int main(){
    char s[201];
    int n,aux,ans;
    
    while(1){
        scanf("%s",s);
        if(s[0]=='*') break;
        
        n=strlen(s);
        ans=0;
        
        for(int i=1;i<n;i++){
            aux=0;
            while(1){
                if(s[i]=='/') break;
                if(s[i]=='W') aux+=64;
                if(s[i]=='H') aux+=32;
                if(s[i]=='Q') aux+=16;
                if(s[i]=='E') aux+=8;
                if(s[i]=='S') aux+=4;
                if(s[i]=='T') aux+=2;
                if(s[i]=='X') aux+=1;
                i++;
            }
            if(aux==64) ans++;
        }
        
        printf("%d\n",ans);
    }
    
    return 0;
}
