#include<cstdio>
#include<algorithm>

using namespace std;

int conv(char &c){
    if(c>='A' && c<='Z') return (c-'A');
    return (c-'a'+26);
}

int main(){    
    int M[52][52];
    int N,ans,a,b,dist;
    char c1,c2;
    
    while(scanf("%d\n",&N)==1){
        for(int i=0;i<52;i++) fill(M[i],M[i]+52,-1);
        
        for(int i=0;i<N;i++){
            scanf("%c %c %d\n",&c1,&c2,&dist);
            
            a=conv(c1);
            b=conv(c2);
            
            if(M[a][b]==-1) M[a][b]=dist;
            else M[a][b]=min(M[a][b],dist);
            M[b][a]=M[a][b];
        }
                
        for(int k=0;k<52;k++)
            for(int i=0;i<52;i++)
                for(int j=0;j<52;j++)
                    if(M[i][k]!=-1 && M[k][j]!=-1){
                        if(M[i][j]==-1) M[i][j]=M[i][k]+M[k][j];
                        else M[i][j]=min(M[i][j],M[i][k]+M[k][j]);
                    }
        
        ans=INT_MAX;
        
        for(int i=0;i<25;i++)
            if(M[i][25]!=-1 && M[i][25]<ans){
                ans=M[i][25];
                a=i;
            }
        
        printf("%c %d\n",a+'A',ans);
    }
    
    return 0;
}
