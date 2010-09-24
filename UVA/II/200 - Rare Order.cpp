#include<iostream>
#include<vector>
#include<string>

using namespace std;

int main(){
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
    
    vector<string> index;
    string s;
    int cont;    
    bool M[26][26];
    bool present[26];
    char order[26];
    
    while(1){
        cin>>s;
        if(s[0]=='#') break;
        
        index.push_back(s);
    }
    
    int n=index.size();
    
    memset(M,false,sizeof(M));
    memset(present,false,sizeof(present));
    
    for(int i=0;i<n-1;i++){
        for(int j=0;j<min(index[i].size(),index[i+1].size());j++){
            if(index[i][j]!=index[i+1][j]){
                M[index[i][j]-'A'][index[i+1][j]-'A']=1;
                present[index[i][j]-'A']=present[index[i+1][j]-'A']=1;
                
                break;
            }
        }
    }
    
    for(int k=0;k<26;k++)
        for(int i=0;i<26;i++)
            for(int j=0;j<26;j++)
                M[i][j]|=(M[i][k] && M[k][j]);
    
    n=0;
    for(int i=0;i<26;i++){
        if(present[i]){
            n++;            
            cont=0;
            
            for(int j=0;j<26;j++)
                if(M[i][j]) cont++;
            
            order[cont]='A'+i;
        }
    }
    
    for(int i=n-1;i>=0;i--) cout<<order[i];
    cout<<endl;
    
    return 0;
}
