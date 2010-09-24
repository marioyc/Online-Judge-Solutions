#include<cstdio>
#include<algorithm>

using namespace std;

int main(){    
    int M,minimum,dist;
    char square[100][100];
    int pos1[10000][2];
    int pos3[10000][2];
    int cont1;
    int cont3;
    
    while(scanf("%d\n",&M)==1){
        for(int i=0;i<M;i++) scanf("%s\n",square[i]);        
        
        cont1=0;
        cont3=0;
        
        for(int i=0;i<M;i++)
            for(int j=0;j<M;j++)
                if(square[i][j]=='1'){
                    pos1[cont1][0]=i;
                    pos1[cont1][1]=j;
                    cont1++;
                }else if(square[i][j]=='3'){
                    pos3[cont3][0]=i;
                    pos3[cont3][1]=j;
                    cont3++;
                }
                
        minimum=-1;
        
        for(int i=0;i<cont1;i++){
            dist=(1<<30);
            
            for(int j=0;j<cont3;j++)
                dist=min(dist,abs(pos1[i][0]-pos3[j][0])+abs(pos1[i][1]-pos3[j][1]));
            
            minimum=max(minimum,dist);
        }
        
        printf("%d\n",minimum);
    }
    
    return 0;
}
