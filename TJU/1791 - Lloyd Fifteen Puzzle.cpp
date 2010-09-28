#include<cstdio>
#include<vector>

using namespace std;

int main(){
    int numbers[100][1000];
    int T,R,S,n,I,J;
    
    scanf("%d",&T);
    
    for(int caso=1;caso<=T;caso++){
        printf("Skladacka cislo %d:\n",caso);
        
        scanf("%d %d",&R,&S);
        
        for(int i=0;i<R;i++){
            for(int j=0;j<S;j++){
                scanf("%d",&numbers[i][j]);
                if(numbers[i][j]==0){
                    I=i;
                    J=j;
                }
            }
        }
        
        while(1){
            scanf("%d",&n);
            if(n==0) break;
            
            if(I>0 && numbers[I-1][J]==n){
                printf("Kamen %d presunut dolu.\n",n);
                swap(numbers[I][J],numbers[I-1][J]);
                I--;
            }else if(I<R-1 && numbers[I+1][J]==n){
                printf("Kamen %d presunut nahoru.\n",n);
                swap(numbers[I][J],numbers[I+1][J]);
                I++;
            }else if(J>0 && numbers[I][J-1]==n){
                printf("Kamen %d presunut doprava.\n",n);
                swap(numbers[I][J],numbers[I][J-1]);
                J--;
            }else if(J<S-1 && numbers[I][J+1]==n){
                printf("Kamen %d presunut doleva.\n",n);
                swap(numbers[I][J],numbers[I][J+1]);
                J++;
            }else printf("Neplatny tah kamenem %d.\n",n);        
        }
        
        for(int i=0;i<R;i++){
                for(int j=0;j<S;j++){
                    printf("%d",numbers[i][j]);             
                    if(j!=S-1) printf(" ");
                }
                printf("\n");
            }
        printf("\n");
    }
    
    return 0;
}
