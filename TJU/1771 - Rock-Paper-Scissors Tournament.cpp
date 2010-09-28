#include<iostream>
#include<string>
#include<vector>
#include<iomanip>

using namespace std;

int main(){
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
    
    string s1,s2;
    int n,k,ax,a,b;
    cin>>n;
    while(true){
        cin>>k;
        
        ax=n*(n-1)/2*k;
        
        vector<int> w(n,0);
        vector<int> l(n,0);
        
        for(int i=0;i<ax;i++){
            cin>>a>>s1>>b>>s2;
            
            if(s1==s2) ;
            else if((s1=="paper"&&s2=="rock")||(s1=="scissors"&&s2=="paper") ||(s1=="rock"&&s2=="scissors")){
                w[a-1]++;
                l[b-1]++;
            }else{
                w[b-1]++;
                l[a-1]++;
            }
        }
        
        for(int i=0;i<n;i++){
            if(w[i]+l[i]==0) cout<<"-"<<endl;
            else cout<<fixed<<setprecision(3)<<w[i]*1.0/(w[i]+l[i])<<endl;
        }
        
        cin>>n;
        if(n==0) break;
        else cout<<endl;
    }
}
