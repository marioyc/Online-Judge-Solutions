#include <iostream>
#include <string>
#include <set>

using namespace std;

int main(){    
    int N;
    
    cin>>N;
    
    int dp1[250];
    int dp2[250];
    
    string s;
    getline(cin,s);    
    
    int n;
    int ans,cont;    
    
    
    for(int tc=1;tc<=N;tc++){
        getline(cin,s);
                
        set<char> S;
        
        for(int i=s.size()-1;i>=0;i--) if(isupper(s[i])) S.insert(s[i]);
        
        set<char> :: iterator it;
        
        s.clear();
        
        for(it=S.begin();it!=S.end();it++) s+=(*it);
        
        n=s.size();
        
        ans=0;
        cont=1;
        
        for(int i=0;i<n;i++){
            dp1[i]=dp2[i]=1;
            
            for(int j=0;j<i;j++){
                if(5*(s[j]-'A'+1)<=4*(s[i]-'A'+1)){
                    if(dp1[j]+1>dp1[i]){
                        dp1[i]=dp1[j]+1;
                        dp2[i]=dp2[j];
                    }else if(dp1[j]+1==dp1[i]) dp2[i]+=dp2[j];
                }
            }
            
            if(dp1[i]>ans){
                ans=dp1[i];
                cont=dp2[i];
            }else if(dp1[i]==ans) cont+=dp2[i];
        }
        
        cout<<ans<<" "<<cont<<endl;
    }
    
    return 0;
}
