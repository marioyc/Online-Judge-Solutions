#include<algorithm>
#include<cstdio>

using namespace std;

int main(){    
    int score[6];
    bool end;
    int sum;
    
    while(1){
        sum=0;
        for(int i=0;i<6;i++){
            scanf("%d",&score[i]);
            sum+=score[i];
        }
        
        end=true;
        for(int i=0;i<6;i++)
            if(score[i]!=0) end=false;
        
        if(end) break;
        
        sort(score,score+6);
        
        sum-=score[0]+score[5];                
        
        printf("%d",sum/4);
        
        if(sum%4==0) printf("\n");
        else if(sum%4==1) printf(".25\n");
        else if(sum%4==2) printf(".5\n");
        else printf(".75\n");
    }
}
