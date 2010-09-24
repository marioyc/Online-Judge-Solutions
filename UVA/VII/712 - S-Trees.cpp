#include<cstdio>
#include<cstring>

using namespace std;

int main(){
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
    
    int n,m,x,caso=1;
    int pos[7];
    char terminal[129];
    char VVA[8];
    char aux[3];
    
    while(1){
        scanf("%d",&n);
        if(n==0) break;
        
        printf("S-Tree #%d:\n",caso);
        caso++;
        
        for(int i=0;i<n;i++){
            scanf("%s",aux);
            pos[i]=aux[1]-'0'-1;
        }        
        
        scanf("%s",terminal);
        
        scanf("%d",&m);
        
        for(int i=0;i<m;i++){
            scanf("%s",VVA);
            
            x=0;
            
            for(int j=0;j<n;j++){
                if(VVA[pos[j]]=='0') x=2*x;
                else x=2*x+1;
            }
            
            printf("%c",terminal[x]);
        }
        
        printf("\n\n");
    }
    
        
    return 0;
}
