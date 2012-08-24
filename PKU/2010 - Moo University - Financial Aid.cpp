#include <cstdio>
#include <algorithm>
#include <queue>

using namespace std;

int main(){
    int N,C,F;
    
    scanf("%d %d %d",&N,&C,&F);
    
    pair<int,int> P[C];
    
    for(int i = 0;i < C;++i)
        scanf("%d %d",&P[i].first,&P[i].second);
    
    sort(P,P + C);
    
    int bestL[C],bestR[C];
    priority_queue<int> Ql,Qr;
    int sum = 0;
    
    for(int i = 0;i < C;++i){
        bestL[i] = sum;
        
        Ql.push(P[i].second);
        sum += P[i].second;
        
        if(i + 1 > N / 2){
            int x = Ql.top();
            sum -= x;
            Ql.pop();
        }
    }
    
    sum = 0;
    
    for(int i = C - 1;i >= 0;--i){
        bestR[i] = sum;
        
        Qr.push(P[i].second);
        sum += P[i].second;
        
        if(C - i > N / 2){
            int x = Qr.top();
            sum -= x;
            Qr.pop();
        }
    }
    
    int ans = -1;
    
    for(int i = N / 2;C - 1 - i >= N / 2;++i)
        if(bestL[i] + bestR[i] + P[i].second <= F)
            ans = P[i].first;
    
    printf("%d\n",ans);
    
    return 0;
}
