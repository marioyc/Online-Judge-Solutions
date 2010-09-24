#include<cstdio>
#include<vector>

using namespace std;

int main(){
    char a,b;
    int L[26][26];
    int gr[26];
    bool candle[26];
    bool end=false;
    bool escape=true;
    int k,pos1,pos2,aux,ax;
    
    while(1){
        memset(gr,0,sizeof(gr));
        
        while(1){
            scanf("%c",&a);
            if(a=='#') goto label1;
            
            scanf("%c",&b);
            
            while(1){
                scanf("%c",&b);
                if(b==';') break;
                else if(b=='.') goto label2;
                else L[a-'A'][gr[a-'A']++]=b-'A';
            }
        }
        
        label2:
        
        scanf(" %c %c %d\n",&a,&b,&k);
        pos2=a-'A';
        pos1=b-'A';
        
        memset(candle,false,sizeof(candle));
        
        aux=0;
        
        while(1){
            escape=false;
            ax=pos2;            
            
            for(int i=0;i<gr[pos2];i++)
                if(!candle[L[pos2][i]] && L[pos2][i]!=pos1){
                    escape=true;
                    pos2=L[pos2][i];
                    break;
                }
            
            if(!escape){
                printf("/%c\n",'A'+pos2);
                break;
            }
            
            pos1=ax;
            aux=(aux+1)%k;
            if(aux==0){
                candle[pos1]=true;
                printf("%c ",'A'+pos1);
            }
        }
    }
    
    label1:
    
    return 0;
}
