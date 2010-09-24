#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main(){
    
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
    
    int T,n,cont;
    
    cin>>T;
    
    for(int i=0;i<T;i++){
        cin>>n;
        
        vector<int> v(n);
        
        for(int j=0;j<n;j++) cin>>v[j];
        
        cont=0;
        
        for(int j=0;j<n;j++){
            for(int k=j+1;k<n;k++){
                if(v[j]>v[k]){
                    cont++;
                    swap(v[j],v[k]);
                }
            }            
        }
        
        cout<<"Optimal train swapping takes "<<cont<<" swaps."<<endl;

    }
    
    return 0;
}
