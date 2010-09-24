#include <cstdio>

using namespace std;

int main(){    
    int t,n;
    bool check;
    int M[200][200];
    
    scanf("%d",&t);
    
    for(int tc=1;tc<=t;tc++){
        scanf("%d",&n);
        
        for(int i=0;i<n;i++)
            for(int j=0;j<n;j++) scanf("%d",&M[i][j]);
        
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                check=false;
                
                for(int k=0;k<n;k++) if(k!=i && k!=j && M[i][k]+M[k][j]==M[i][j]) check=true;
                
                if(!check) printf("%d %d\n",i+1,j+1);
            }
        }
    }
    
    return 0;
}
