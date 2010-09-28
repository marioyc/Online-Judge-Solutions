#include<cstdio>

using namespace std;

int main(){    
    int n,m;
    
    while(1){
        scanf("%d",&n);
        if(n==0) break;
        
        printf("Printing order for %d pages:\n",n);
        
        if(n==1){
            printf("Sheet 1, front: Blank, 1\n");
            continue;
        }
        
        m=(n+3)/4;
        
        for(int i=1;i<=m;i++){
            printf("Sheet %d, front:",i);
            
            if(4*m-2*i+2>n) printf(" Blank,");
            else printf(" %d,",4*m-2*i+2);
            printf(" %d\n",2*i-1);            
            
            printf("Sheet %d, back :",i);
            
            printf(" %d,",2*i);
            if(4*m-2*i+1>n) printf(" Blank\n");
            else printf(" %d\n",4*m-2*i+1);
        }
    }
    
    return 0;
}
