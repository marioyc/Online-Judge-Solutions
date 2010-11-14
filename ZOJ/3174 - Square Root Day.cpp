#include <cstdio>

using namespace std;

int solve(int s, int e){
    int meses[]={31,0,31,30,31,30,31,31,30,31,30,31};
    int cont=0;
    
    for(int i=s;i<=e;i++){
        if(i%4==0){
            if(i%100==0){
                if(i%400==0) meses[1]=29;
                else meses[1]=28;
            }else meses[1]=29;
        }else meses[1]=28;
        
        for(int j=1;j<=12;j++){
            for(int k=1;k<=meses[j-1];k++){
                if((k*k==i%100 || k*k==i%1000) && (j*j==i%100 || j*j==i%1000)) cont++;
            }
        }
    }
    
    return cont;
}

int main(){    
    int T;
    scanf("%d",&T);
    
    int s,e;
    
    for(int i=0;i<T;i++){
        scanf("%d %d",&s,&e);
        printf("%d\n",solve(s,e));
    }
    
    return 0;
}
