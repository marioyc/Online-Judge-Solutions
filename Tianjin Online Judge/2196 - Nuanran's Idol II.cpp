#include<iostream>
#include<queue>

using namespace std;

struct card{
    int score;
    
    card(int a){
        score=a;
    }
    
    bool operator < (card X) const{
        return score>X.score;
    }
};

int main(){
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
    
    int n,score;
    char c;
    card aux=card(0);
    
    while(1){
        scanf("%d",&n);
        if(n==0) break;
        
        priority_queue<card> Q;
        
        for(int i=0;i<n;i++){
            cin>>c;
            
            if(c=='B'){
                scanf("%d",&score);
                Q.push(card(score));
            }else{
                aux=Q.top();
                Q.pop();
                
                printf("%d\n",aux.score);
            }
        }
    }
    
    return 0;
}
