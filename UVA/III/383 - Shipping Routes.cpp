#include<iostream>
#include<map>
#include<string>

using namespace std;

int main(){
    int T,M,N,P,size,start,end;
    int dist[30][30];
    map<string, int> index;
    string id1,id2;
    
    cin>>T;
    
    cout<<"SHIPPING ROUTES OUTPUT"<<endl;
    
    for(int caso=1;caso<=T;caso++){
        cout<<endl<<"DATA SET  "<<caso<<endl<<endl;
        
        cin>>M>>N>>P;
        index.clear();
        
        for(int i=0;i<M;i++){
            cin>>id1;
            index[id1]=i;
        }
        
        for(int i=0;i<M;i++) fill(dist[i],dist[i]+M,500);
        
        for(int i=0;i<M;i++) dist[i][i]=0;
        
        for(int i=0;i<N;i++){
            cin>>id1>>id2;
            start=index[id1]; end=index[id2];
            dist[start][end]=dist[end][start]=1;
        }
        
        for(int k=0;k<M;k++)
            for(int i=0;i<M;i++)
                for(int j=0;j<M;j++)
                    dist[i][j]=min(dist[i][j],dist[i][k]+dist[k][j]);
        
        for(int i=0;i<P;i++){
            cin>>size>>id1>>id2;
            start=index[id1]; end=index[id2];
            if(dist[start][end]==500) cout<<"NO SHIPMENT POSSIBLE"<<endl;
            else cout<<"$"<<size*dist[start][end]*100<<endl;
        }
    }
    
    cout<<endl<<"END OF OUTPUT"<<endl;
    
    return 0;
}
