#include <iostream>
#include <vector>
#include <string>

using namespace std;

bool solve(vector<string> v, int s){
    int ans=0;
    
    for(int i=5,k=1;i>=0;i--,k*=10){
        if(v[0][i]=='|') ans+=5*k;
        
        for(int j=3;j<8;j++)
            if(v[j][i]=='|'){
                ans+=(j-3)*k;
                break;
            }
    }
    
    return (ans==s);
}

int main(){    
    int T,x,y,s;
    vector<string> v(8);
    
    cin>>T;
    
    for(int i=0;i<T;i++){
        cin>>x>>y;
        
        s=y*(y+1)/2-(x-1)*x/2;
        
        for(int i=0;i<8;i++) cin>>v[i];
        
        if(solve(v,s)) cout<<"No mistake"<<endl;
        else cout<<"Mistake"<<endl;
    }
    
    return 0;
}
