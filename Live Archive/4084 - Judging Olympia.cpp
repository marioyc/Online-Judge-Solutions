#include<iostream>
#include<algorithm>
#include<cstdio>

using namespace std;

int main(){
    int score[6];
    bool end;
    double sum;
    
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
        
        cout<<sum-score[0]-score[5])/4<<endl;
    }
}
