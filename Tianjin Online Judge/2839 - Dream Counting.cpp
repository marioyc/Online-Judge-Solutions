#include<iostream>

using namespace std;

int main(){
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
    
    int N,M,ax;
    int cont[10];
    
    scanf("%d %d",&M,&N);
    
    memset(cont,0,sizeof(cont));
    
    for(int i=M;i<=N;i++){
        ax=i;
        
        while(ax!=0){
            cont[ax%10]++;
            ax/=10;
        }
    }
    
    printf("%d %d %d %d %d %d %d %d %d %d\n",cont[0],cont[1],cont[2],cont[3],cont[4],cont[5],cont[6],cont[7],cont[8],cont[9]);
    
    return 0;
}
