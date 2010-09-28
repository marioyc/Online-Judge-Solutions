#include<iostream>

using namespace std;

int main(){
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
    
    int N,M;
    int m1,m2;
    int aux;
    int points[10001];    
    
    while(1){
        scanf("%d %d",&N,&M);
        if(N==0 && M==0) break;
        
        fill(points,points+10001,0);
        
        for(int i=0;i<N;i++){
            for(int j=0;j<M;j++){
                scanf("%d",&aux);
                points[aux]++;
            }
        }
        
        m1=m2=-1;
        
        for(int i=1;i<10001;i++){
            if(points[i]>m1){
                m2=m1;
                m1=points[i];
            }else if(points[i]<m1) m2=max(m2,points[i]);
        }
        
        for(int i=1;i<10001;i++)
            if(points[i]==m2) printf("%d ",i);
        
        printf("\n");
    }
    
    return 0;
}
