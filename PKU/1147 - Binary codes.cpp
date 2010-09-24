#include<cstdio>

using namespace std;

int main(){    
    int N,cont=0;
    int last_col[3000];
    int first_col[3000];
    int  next[3000];
    
    scanf("%d",&N);
    
    for(int i=0;i<N;i++){
        scanf("%d",&last_col[i]);
        if(last_col[i]==0) cont++;
    }
    
    for(int i=0;i<cont;i++) first_col[i]=0;
    for(int i=0;i<N-cont;i++) first_col[cont+i]=1;
    
    for(int i=0,j=0,k=cont;i<N;i++)
        if(last_col[i]==0) next[j++]=i;
        else next[k++]=i;
    
    for(int i=0,j=0;i<N;i++){
        printf("%d",first_col[j]);
        j=next[j];
        
        if(i!=N-1) printf(" ");
    }
    
    printf("\n");
    
    return 0;
}
