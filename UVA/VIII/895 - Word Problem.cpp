#include <cstdio>
#include <cstring>

using namespace std;

int main(){
    int n,m,ans;
    char W[1001][11],c;
    int cont1[26],cont2[1000][26];
    bool ok;
    
    n=0;
    while(1){
        scanf("%s\n",W[n]);
        if(W[n][0]=='#') break;
        n++;
    }
    
    for(int i=n-1;i>=0;i--){
        for(int j=0;j<26;j++) cont2[i][j]=0;
        for(int j=strlen(W[i])-1;j>=0;j--) cont2[i][W[i][j]-'a']++;
    }
    
    m=0;
    while(1){
        scanf("%c",&c);
        if(c=='#') break;
        
        for(int i=0;i<26;i++) cont1[i]=0;
        cont1[c-'a']++;
        
        while(1){
            scanf("%c",&c);
            if(c==' ') continue;
            if(c=='\n') break;
            cont1[c-'a']++;
        }
        
        ans=0;
        
        for(int i=0;i<n;i++){
            ok=true;
            for(int j=0;j<26;j++) ok&=(cont2[i][j]<=cont1[j]);
            if(ok) ans++;
        }
        
        printf("%d\n",ans);
    }
    
    return 0;
}
