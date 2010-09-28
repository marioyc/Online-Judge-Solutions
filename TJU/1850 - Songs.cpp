#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct song{
    int id, L;
    double f;
    
    song(){}
    
    song(int _id, int _L, double _f){
        id = _id; L = _L; f = _f;
    }
    
    bool operator < (song X) const{
        return (f/L>X.f/X.L);
    }
};

int main(){
    int n,S,id,L;
    double f;
    
    while(cin>>n){
        vector<song> a;
        
        for(int i=0;i<n;++i){
            cin>>id>>L>>f;
            a.push_back(song(id,L,f));
        }
        
        cin>>S;
        
        sort(a.begin(),a.end());
        
        cout<<a[S-1].id<<endl;
    }
    
    return 0;
}
