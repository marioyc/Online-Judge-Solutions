#include<cstdio>
#include<vector>

using namespace std;

int main(){
    int A,B,C,S;
    bool visited[65536];
    int mask1,mask2;
    bool used[16];
    
    while(1){
        scanf("%d",&A);
        if(A==0) break;
        scanf("%d %d %d",&B,&C,&S);
        
        memset(visited,false,sizeof(visited));
        
        mask1=(1<<16)-1;
        mask2=0;
        
        while(!visited[S]){
            visited[S]=true;
            
            mask1&=S;
            mask2|=S;
            
            S=(A*S+B)%C;
        }
        
        for(int i=15;i>=0;i--){
            if((mask2&(1<<i))==0) printf("0");
            else if((mask1&(1<<i))!=0) printf("1");
            else printf("?");
        }
        printf("\n");
    }
    
    return 0;
}
