#include<iostream>
#include<string>
#include<vector>

using namespace std;

int main(){    
    int T,M,N,I;
    vector<string> v(200);
    int r,c,x;
    string dir;
    
    T=1;
    
    while(1){
        cin>>M>>N>>I;
        if(M==0 && N==0 && I==0) break;
        
        cout<<"Scenario #"<<T<<":"<<endl;
        T++;
        
        for(int i=0;i<M;i++) v[i]=string(N,'.');
        
        r=0; c=0;
        
        for(int i=0;i<I;i++){
            cin>>dir>>x;
            
            if(dir[0]=='S'){
                v[r][c]='+';
                for(int j=1;j<x;j++)
                    if(v[r+j][c]!='.') v[r+j][c]='+';
                    else v[r+j][c]='|';
                v[r+x][c]='+';
                r=r+x;
            }else if(dir[0]=='N'){
                v[r][c]='+';
                for(int j=1;j<x;j++)
                    if(v[r-j][c]!='.') v[r-j][c]='+';
                    else v[r-j][c]='|';
                v[r-x][c]='+';
                r=r-x;
            }else if(dir[0]=='E'){
                v[r][c]='+';
                for(int j=1;j<x;j++)
                    if(v[r][c+j]!='.') v[r][c+j]='+';
                    else v[r][c+j]='-';
                v[r][c+x]='+';
                c=c+x;
            }else{
                v[r][c]='+';
                for(int j=1;j<x;j++)
                    if(v[r][c-j]!='.') v[r][c-j]='+';
                    else v[r][c-j]='-';
                v[r][c-x]='+';
                c=c-x;
            }
        }
        
        for(int i=0;i<M;i++) cout<<v[i]<<endl;        
    }
    
    return 0;
}
