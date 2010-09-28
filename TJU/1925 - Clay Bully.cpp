#include <vector>
#include <string>
#include <iostream>

using namespace std;

int main(){
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);

    int n;
    vector<string> v;
    vector<int> vol;
    string s;
    int ax1,ax2,prom,a,b;
    
    while(1){
        cin>>n;
        if(n==-1) break;
        
        v.clear();vol.clear();
        
        prom=0;
        
        for(int i=0;i<n;i++){
            ax2=1;
            cin>>ax1;ax2*=ax1;
            cin>>ax1;ax2*=ax1;
            cin>>ax1;ax2*=ax1;
            vol.push_back(ax2);
            prom+=ax2;
            
            cin>>s;
            v.push_back(s);
        }
        
        prom/=n;
        
        for(int i=0;i<n;i++){
            if(vol[i]<prom) a=i;
            else if(vol[i]>prom) b=i;
        }
        
        cout<<v[b]<<" took clay from "<<v[a]<<"."<<endl;
    }

    return 0;
}
