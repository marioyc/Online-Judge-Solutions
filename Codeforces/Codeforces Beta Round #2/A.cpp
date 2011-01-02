#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main(){
    int N;
    cin>>N;
    
    string name[N];
    int score[N];
    
    for(int i = 0;i<N;++i)
        cin>>name[i]>>score[i];    
    
    int best = -1000*1000-1;
    vector<string> winners;
    
    for(int i = 0;i<N;++i){
        bool rep = false;
        
        for(int j = i+1;j<N;++j)
            rep = (rep || name[j]==name[i]);
        
        if(!rep){
            int aux = 0;
            
            for(int j = 0;j<=i;++j)
                aux += (name[j]==name[i]? score[j] : 0);
            
            if(aux>best){
                best = aux;
                winners.clear();
                winners.push_back(name[i]);
            }else if(aux==best) winners.push_back(name[i]);
        }
    }
    
    int M = winners.size();
    vector<int> pos(M,0);
    
    for(int i = 0;i<M;++i){
        int sc = 0;
        
        for(int j = 0;j<N;++j){
            if(name[j]==winners[i]){
                sc += score[j];
                if(sc>=best){
                    pos[i] = j;
                    break;
                }
            }
        }
    }
    
    int ind = 0;
    
    for(int i = 0;i<M;++i)
        if(pos[i]<pos[ind])
            ind = i;
    
    cout<<winners[ind]<<'\n';
    
    return 0;
}
