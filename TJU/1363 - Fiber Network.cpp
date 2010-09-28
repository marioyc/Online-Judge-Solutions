#include <cstdio>
#include <cstring>

using namespace std;

int main(){
    int n,u,v,mask,M[200][200];
    char s[27];
    
    while(true){
        scanf("%d",&n);
        if(n==0) break;
        
        for(int i=0;i<n;++i) for(int j=0;j<n;++j) M[i][j] = 0;
        
        while(true){
            scanf("%d %d",&u,&v);
            if(u==0) break;
            --u; --v;
            scanf("%s",s);
            
            mask = 0;
            for(int i=strlen(s)-1;i>=0;--i) mask |= (1<<(s[i]-'a'));
            M[u][v] = mask;
        }
        
        for(int k=0;k<n;++k) for(int i=0;i<n;++i) for(int j=0;j<n;++j)
            M[i][j] |= (M[i][k] & M[k][j]);
        
        while(true){
            scanf("%d %d",&u,&v);
            if(u==0) break;
            --u; --v;
            
            if(M[u][v]==0) printf("-\n");
            else{
                for(int i=0;i<26;++i) if(M[u][v] & (1<<i)) printf("%c",'a'+i);
                printf("\n");
            }
        }
        
        printf("\n");
    }
    
    return 0;
}
