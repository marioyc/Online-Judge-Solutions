#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main(){
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
    
    int T,L,N;
    
    cin>>T;
    
    int l;
    string s;
    
    for(int tc=1;tc<=T;tc++){
        cin>>L>>N;
        L*=100;
        
        vector<int> left;
        vector<int> right;
        
        for(int i=0;i<N;i++){
            cin>>l>>s;
            
            if(l>L) continue;
            
            if(s[0]=='l') left.push_back(l);
            else right.push_back(l);;
        }
        
        int n=left.size()-1, m=right.size()-1, cont=0, side=0;
        
        while(n>=0 || m>=0){
            cont++;
            
            if(side==0){
                if(n>=0){
                    int aux=0;                    
                    for(;n>=0 && aux+left[n]<=L;n--) aux+=left[n];
                }
            }else{
                if(m>=0){
                    int aux=0;
                    for(;m>=0 && aux+right[m]<=L;m--) aux+=right[m];
                }
            }
            
            side=1-side;
        }
        
        cout<<cont<<endl;
    }
    
    return 0;
}
