#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main(){
    int T,n,R,C,dist,aux;
    vector<int> v;
    int pos[11][2];
    
    cin>>T;
    
    for(int caso=1;caso<=T;caso++){
        cin>>R>>C;
        cin>>pos[0][0]>>pos[0][1];
        
        cin>>n;
        
        for(int i=1;i<=n;i++) cin>>pos[i][0]>>pos[i][1];
        
        v.clear();
        
        for(int i=1;i<=n;i++) v.push_back(i);
        
        dist=INT_MAX;
        
        do{            
            aux=abs(pos[v[0]][0]-pos[0][0])+abs(pos[v[0]][1]-pos[0][1]);
            
            for(int i=0;i<n-1;i++) aux+=abs(pos[v[i+1]][0]-pos[v[i]][0])+abs(pos[v[i+1]][1]-pos[v[i]][1]);
            
            aux+=abs(pos[v[n-1]][0]-pos[0][0])+abs(pos[v[n-1]][1]-pos[0][1]);
            
            dist=min(dist,aux);
        }while(next_permutation(v.begin(),v.end()));
        
        cout<<"The shortest path has length "<<dist<<endl;
    }
    
    return 0;
}
