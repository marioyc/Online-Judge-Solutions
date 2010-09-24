#include<cstdio>
#include<vector>
#include<queue>

using namespace std;

struct card{
    int rank,suit;
    
    card(){
    }
    
    card(int a, int b){
        rank=a;
        suit=b;
    }
    
    bool operator < (card X) const{
        if(rank!=X.rank) return rank<X.rank;
        return suit<X.suit;
    }
};

int main(){    
    int P,M,N;
    char c;
    int rank,suit,ind;
    card discard;
    int player, next, dir;
    
    while(1){
        scanf("%d %d %d\n",&P,&M,&N);
        if(P==0 && M==0 && N==0) break;
        
        vector< vector<card> > v(P);
        queue<card> stock;
        
        for(int i=0;i<N;i++){
            scanf("%d %c\n",&rank,&c);
            
            if(c=='C') suit=0;
            else if(c=='D') suit=1;
            else if(c=='H') suit=2;
            else suit=3;
            
            if(i<M*P) v[i/M].push_back(card(rank,suit));
            else if(i==M*P) discard=card(rank,suit);
            else stock.push(card(rank,suit));
        }
        
        dir=1;
        player=-1;
        next=0;
        
        if(discard.rank==12) dir*=-1;
        else if(discard.rank==7){
            v[next].push_back(stock.front());
            stock.pop();
            v[next].push_back(stock.front());
            stock.pop();
            next=(player+2*dir+2*P)%P;
        }else if(discard.rank==1){
            v[next].push_back(stock.front());
            stock.pop();
            next=(player+2*dir+2*P)%P;
        }else if(discard.rank==11) next=(player+2*dir+2*P)%P;
        
        player=next;
        
        while(1){
            next=(player+dir+2*P)%P;
            ind=-1;
            
            for(int i=0;i<v[player].size();i++)
                if(discard.rank==v[player][i].rank || discard.suit==v[player][i].suit)
                    if(ind==-1 || v[player][ind]<v[player][i]) ind=i;
            
            if(ind==-1){
                if(stock.front().rank==discard.rank || stock.front().suit==discard.suit){
                    discard=stock.front();
                    ind=-2;
                }else v[player].push_back(stock.front());
                
                 stock.pop();
            }
            
            if(ind!=-1){
                if(ind!=-2){
                    discard=v[player][ind];
                    v[player].erase(v[player].begin()+ind,v[player].begin()+ind+1);
                }
                
                if(discard.rank==12){
                    dir*=-1;
                    next=(player+dir+2*P)%P;
                }else if(discard.rank==7){
                    v[next].push_back(stock.front());
                    stock.pop();
                    v[next].push_back(stock.front());
                    stock.pop();
                    next=(player+2*dir+2*P)%P;
                }else if(discard.rank==1){
                    v[next].push_back(stock.front());
                    stock.pop();
                    next=(player+2*dir+2*P)%P;
                }else if(discard.rank==11) next=(player+2*dir+2*P)%P;
            }
            
            if(v[player].size()==0){
                printf("%d\n",player+1);
                break;
            }
            
            player=next;
        }
    }
    
    return 0;
}
