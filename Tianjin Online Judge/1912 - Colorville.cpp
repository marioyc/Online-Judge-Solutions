#include<iostream>
#include<vector>
#include<string>

using namespace std;

int main(){
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);

    int N,board,cards,enc;
    int pos[4];
    vector<string> v;
    bool ok;
    
    string s,ax;
    
    while(1){
        scanf("%d %d %d",&N,&board,&cards);
        if(N==0) break;
        
        cin>>s;
        
        v.clear();
        
        for(int i=0;i<cards;i++){
            cin>>ax;
            v.push_back(ax);
        }        
        
        ok=false;        
        for(int i=0;i<N;i++) pos[i]=-1;
        
        for(int i=0;i<cards;i++){
            enc=s.find(v[i][0],pos[i%N]+1);
            if(enc==-1){
                cout<<"Player "<<i%N+1<<" won after "<<i+1<<" cards."<<endl;
                ok=true;
                break;
            }
            
            if(v[i].size()==2) enc=s.find(v[i][0],enc+1);
            
            if(enc==-1 || enc==board-1){
                cout<<"Player "<<i%N+1<<" won after "<<i+1<<" cards."<<endl;
                ok=true;
                break;
            }else pos[i%N]=enc;
        }
        
        if(!ok) cout<<"No player won after "<<cards<<" cards."<<endl;
    }

    return 0;
}
