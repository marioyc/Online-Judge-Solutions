#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

int main(){
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
    
    int n,cont=0,L;
    char M[2][256];
    
    scanf("%d",&n);
    scanf("%s",M[0]);
    
    cont+=strlen(M[0]);
    
    for(int i=1,j=1;i<n;i++,j=1-j){
        scanf("%s",M[j]);
        cont+=strlen(M[j]);
        
        L=min(strlen(M[0]),strlen(M[1]));
        
        for(int x=0;x<=L;x++)
            if(x==L) cont-=L-1;
            else if(M[0][x]!=M[1][x]){
                cont-=x-1;
                break;
            }
    }
    
    printf("%d\n",cont);
    
    return 0;
}
