#include<iostream>

using namespace std;

int main(){
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
    
    int W[100][100];
    int row[100];
    int column[100];
    
    int T,R,C;
    int VIP;
    
    scanf("%d",&T);
    
    for(int caso=0;caso<T;caso++){
        scanf("%d %d",&R,&C);
        
        for(int i=0;i<R;i++) row[i]=0;
        
        for(int i=0;i<C;i++) column[i]=0;
        
        for(int i=0;i<R;i++){     
            for(int j=0;j<C;j++){
                scanf("%d",&W[i][j]);
                
                row[i]=max(row[i],W[i][j]);
                column[j]=max(column[j],W[i][j]);
            }
        }
        
        VIP=0;
        
        for(int i=0;i<R;i++)
            for(int j=0;j<C;j++)
                if(W[i][j]==row[i] && W[i][j]==column[j]) VIP++;
        
        printf("%d\n",VIP);
    }
    
    return 0;
}
