#include<iostream>

using namespace std;

int main(){
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
    
    int x,y,n,cont;
    int T;
    
    int a[10000];
    
    int M[100][100];
    
    while(1){
        scanf("%d %d",&x,&y);
        
        if(x==0 && y==0) break;
        
        scanf("%d %d %d",&a[0],&a[1],&n);
        
        memset(M,-1,sizeof(M));
        
        cont=1;
        
        M[a[0]][a[1]]=0;
        
        for(int i=2;;i++){
            a[i]=(x*a[i-1]+y*a[i-2])%100;            
            if(M[a[i-1]][a[i]]!=-1){
                T=i-1-M[a[i-1]][a[i]];                
                break;
            }else{
                cont++;
                M[a[i-1]][a[i]]=i-1;
            }
        }
        
        while(n>=cont) n-=T;
        
        if(a[n]>=0 && a[n]<10) printf("0");
        printf("%d\n",a[n]);
    }
    
    return 0;
}
