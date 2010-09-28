#include<cstdio>

using namespace std;

int min(int &a, int b){
    if(a<b) return a;
    return b;
}

int main(){    
    int t,a,b,n;
    int M[20][20];
    
    t=1;
    
    while(scanf("%d",&a)==1){
        for(int i=0;i<20;i++)
            for(int j=0;j<20;j++) M[i][j]=50;
        
        for(int i=0;i<a;i++){
            scanf("%d",&b);
            M[0][b-1]=1;
            M[b-1][0]=1;
        }
        
        for(int i=1;i<19;i++){
            scanf("%d",&a);
            for(int j=0;j<a;j++){
                scanf("%d",&b);
                M[i][b-1]=1;
                M[b-1][i]=1;
            }
        }
        
        for(int k=0;k<20;k++)
            for(int i=0;i<20;i++)
                for(int j=0;j<20;j++)
                    M[i][j]=min(M[i][j],M[i][k]+M[k][j]);
        
        scanf("%d",&n);
        
        printf("Test Set #%d\n",t);
        t++;
        
        for(int i=0;i<n;i++){
            scanf("%d %d",&a,&b);
            
            printf("%d to %d: %d\n",a,b,M[a-1][b-1]);
        }
        printf("\n");
    }
    
    return 0;
}
