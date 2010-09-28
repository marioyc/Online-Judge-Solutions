#include<iostream>
#include<string>

using namespace std;

int main(){
    string URL,s;
    int n;
    int a,b,x,y;
    bool port,path;
    
    cin>>n;
    
    for(int caso=1;caso<=n;caso++){
        cout<<"URL #"<<caso<<endl;
        
        cin>>URL;
        
        a=0;
        b=URL.find("://");
        s=URL.substr(a,b);        
        cout<<"Protocol = "<<s<<endl;
        
        port=path=true;
        
        a=b+3;
        b=URL.find(":",a);
        
        if(b==-1){
            port=false;
            b=URL.find("/",a);
            
            if(b==-1){
                path=false;
                b=URL.size();
            }
        }else{
            x=URL.find("/",a);
            if(x==-1) path=false;
            else b=min(b,x);
        }
        
        s=URL.substr(a,b-a);
        cout<<"Host     = "<<s<<endl;
        
        cout<<"Port     = ";
        
        if(port){
            x=URL.find(":",b);
            y=URL.find("/",b);
            
            if(x!=-1 && y!=-1 && y<x) port=false;
        }
        
        if(port){
            a=b+1;
            b=URL.find("/",a);
            
            if(b==-1){
                path=false;
                b=URL.size();
            }
            
            s=URL.substr(a,b-a);
            cout<<s<<endl;
        }else cout<<"<default>"<<endl;
        
        cout<<"Path     = ";
        
        if(path){
            a=b+1;
            s=URL.substr(a,s.size()-a);
            cout<<s<<endl;
        }else cout<<"<default>"<<endl;
        
        cout<<endl;
    }
    
    return 0;
}
