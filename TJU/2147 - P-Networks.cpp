#include<iostream>
#include<cstdio>
#include<vector>

using namespace std;

int main(){    
    int N,aux;
    int pos[20];
    int num_in_pos[20];
    bool no_existe;
    int strokes[190];
    int cont;
    
    while(1){
        scanf("%d",&N);
        if(N==0) break;
        
        no_existe=false;
        fill(pos,pos+N,-1);
        
        for(int i=0;i<N;i++){
            scanf("%d",&aux);
            if(pos[aux-1]!=-1) no_existe=true;
            pos[aux-1]=i;
            num_in_pos[i]=aux-1;
        }
        
        if(no_existe){
            printf("No solution\n");
            continue;
        }
        
        cont=0;
        
        for(int i=0;i<N;i++){
            while(pos[i]!=i){
                aux=num_in_pos[pos[i]-1];
                strokes[cont++]=pos[i];
                
                swap(num_in_pos[pos[i]],num_in_pos[pos[i]-1]);
                swap(pos[i],pos[aux]);
            }
        }
        
        printf("%d",cont);
        for(int i=0;i<cont;i++) printf(" %d",strokes[i]);
        printf("\n");
    }
    
    return 0;
}
