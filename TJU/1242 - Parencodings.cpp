#include <cstdio>

using namespace std;

int main(){    
    int t,n,P[20],L,cont,cont2;
    char s[41];
    bool used[40];
    
    scanf("%d",&t);
    
    for(int tc=1;tc<=t;tc++){
        scanf("%d",&n);
        
        for(int i=0;i<n;i++) scanf("%d",&P[i]);
        
        for(int i=0;i<2*n;i++) used[i]=false;
        
        L=0; cont=0;
        
        for(int i=0;i<n;i++){
            while(cont!=P[i]){
                s[L++]='(';
                cont++;
            }
            
            s[L++]=')';
            
            cont2=0;
            
            for(int j=L-1;;j--){
                if(!used[j] && s[j]=='('){
                    used[j]=true;
                    break;
                }
                if(s[j]==')') cont2++;
            }
            
            printf("%d",cont2);
            if(i==n-1) printf("\n");
            else printf(" ");
        }
        
        
    }
    
    return 0;
}
