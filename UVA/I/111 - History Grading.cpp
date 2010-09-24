#include<cstdio>
#include<algorithm>

using namespace std;

int main(){
    int n,c[20],r[20],lcs[21][21],x;
    
    scanf("%d\n",&n);
    
    for(int i=0;i<n;i++){
        scanf("%d",&x);
        c[x-1]=i;
    }
    
    while(scanf("%d",&x)==1){
        r[x-1]=0;
        for(int i=1;i<n;i++){
            scanf("%d",&x);
            r[x-1]=i;
        }
        
        for(int i=n;i>=0;i--)
            for(int j=n;j>=0;j--){
                if(i==n || j==n){
                    lcs[i][j]=0;
                    continue;
                }
                
                if(c[i]==r[j]) lcs[i][j]=1+lcs[i+1][j+1];
                else lcs[i][j]=max(lcs[i][j+1],lcs[i+1][j]);
            }
        
        printf("%d\n",lcs[0][0]);
    }
    
    return 0;
}
