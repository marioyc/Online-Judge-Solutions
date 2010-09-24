#include<iostream>
#include<sstream>
#include<string>
#include<vector>

using namespace std;

int main(){
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
    
    vector<string> v1,v2;
    string s1,s2;
    int mx;
    
    int M[102][102];
    int N[102];
    int n;
    
    while(getline(cin,s1)){
        
        v1.clear(); v2.clear();
        
        if(s1!="#"){
            istringstream is(s1);
            while(is>>s2) v1.push_back(s2);
            
            while(getline(cin,s1)){
                if(s1=="#") break;
                istringstream is(s1);
                while(is>>s2) v1.push_back(s2);
            }
        }
        
        while(getline(cin,s1)){
            if(s1=="#") break;
            istringstream is(s1);
            
            while(is>>s2) v2.push_back(s2);
        }
        
        memset(M,0,sizeof(M));
        
        for(int i=v1.size()-1;i>=0;i--){
            for(int j=v2.size()-1;j>=0;j--)
                if(v1[i]==v2[j]) M[i][j]=1+M[i+1][j+1];
                else M[i][j]=max(M[i+1][j],M[i][j+1]);
        }
        
        mx=-1;
        
        for(int i=0;i<v1.size();i++)
            for(int j=0;j<v2.size();j++)
                mx=max(mx,M[i][j]);
        
        memset(N,-1,sizeof(N));
        
        n=v2.size();
        
        for(int i=0;i<v1.size();i++){
            for(int j=0;j<n;j++){
                if(v1[i]==v2[j] && M[i][j]==mx){
                    mx--;
                    cout<<v1[i];
                    if(mx==0) cout<<endl;
                    else cout<<" ";
                    break;
                }
            }
        }
    }
    
    return 0;
}
