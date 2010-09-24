#include<iostream>
#include<vector>
#include<set>

using namespace std;

int main(){
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
    
    int L,N,M,aux;
    
    scanf("%d %d %d",&L,&N,&M);
    
    set<int> S;
    vector<int> rocks;
    
    for(int i=0;i<N;i++){
         scanf("%d",&aux);
         S.insert(aux);
    }
    
    set<int> :: iterator it;
    
    rocks.push_back(0);
    for(it=S.begin();it!=S.end();it++) rocks.push_back((*it));
    rocks.push_back(L);
    
    int ind;
    int smallest;
    
    for(int i=0;i<M;i++){
        smallest=1000000001;
        
        for(int j=0;j<N+1-i;j++){
            if(rocks[j+1]-rocks[j]<smallest){
                ind=j;
                smallest=rocks[j+1]-rocks[j];
            }
        }
        
        if(ind==0) rocks.erase(rocks.begin()+1);
        else if(ind+1==N+1-i) rocks.erase(rocks.begin()+ind);
        else{
            if(rocks[ind]-rocks[ind-1]<rocks[ind+2]-rocks[ind+1]) rocks.erase(rocks.begin()+ind);
            else rocks.erase(rocks.begin()+ind+1);
        }
    }
    
    smallest=1000000001;
    for(int i=0;i<N+1-M;i++) smallest=min(smallest,rocks[i+1]-rocks[i]);
    
    cout<<smallest<<endl;
    
    return 0;
}
