#include<iostream>
#include<string>

using namespace std;

int main(){
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    
    string s1,s2;
    int n,m;
    
    int M[210][210];
    
    while(cin>>s1>>s2){    
        
        n=s1.size();
        m=s2.size();
        
        memset(M,0,sizeof(M));
        
        int j=0;
        
        for(int i=n-1;i>=0;i--){
            for(int j=m-1;j>=0;j--){
                if(s1[i]==s2[j]) M[i][j]=M[i+1][j+1]+1;
                else M[i][j]=max(M[i][j+1],M[i+1][j]);
            }
        }
        
        int ans=-1;
        for(int i=0;i<n;i++)
            for(int j=0;j<m;j++)
                ans=max(ans,M[i][j]);
                
        cout<<ans<<endl;
    }
}
