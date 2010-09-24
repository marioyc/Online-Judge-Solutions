#include<iostream>
#include<string>
#include<map>
#include<cstdio>

using namespace std;

int main(){
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);

    map<char, int> M;

    M[' ']=0;
    for(int i=0;i<26;i++) M['A'+i]=i+1;

    int N,R,C;
    int cont_letra,cont_pos;
    string message;
    char aux;
    bool code[21][21];

    cin>>N;
    
    for(int caso=1;caso<=N;caso++){
        cin>>R>>C;
        
        scanf("%c",&aux);
        message="";
        
        while(scanf("%c",&aux)==1){            
            if(aux=='\n') break;            
            message+=aux;
        }
        
        cont_letra=0;
        cont_pos=0;
        
        memset(code,0,sizeof(code));
                        
        for(int i=0;i<R/2 && cont_letra<message.size();i++){
            for(int j=i;j<C-i && cont_letra<message.size();j++){
                if((M[message[cont_letra]] & (1<<(4-cont_pos)))!=0) code[i][j]=1;
                
                if(cont_pos==4) cont_letra++;
                cont_pos=(cont_pos+1)%5;
            }
            
            for(int j=i+1;j<R-i && cont_letra<message.size();j++){
                if((M[message[cont_letra]] & (1<<(4-cont_pos)))!=0) code[j][C-i-1]=1;
                
                if(cont_pos==4) cont_letra++;
                cont_pos=(cont_pos+1)%5;
            }
            
            for(int j=C-i-2;j>=i && cont_letra<message.size();j--){
                if((M[message[cont_letra]] & (1<<(4-cont_pos)))!=0) code[R-i-1][j]=1;
                
                if(cont_pos==4) cont_letra++;
                cont_pos=(cont_pos+1)%5;
            }
            
            for(int j=R-i-2;j>=i+1 && cont_letra<message.size();j--){
                if((M[message[cont_letra]] & (1<<(4-cont_pos)))!=0) code[j][i]=1;
                
                if(cont_pos==4) cont_letra++;
                cont_pos=(cont_pos+1)%5;
            }
        }
        
        if(R%2==1){
            for(int j=R/2;j<C-R/2 && cont_letra<message.size();j++){
                if((M[message[cont_letra]] & (1<<(4-cont_pos)))!=0) code[R/2][j]=1;
                
                if(cont_pos==4) cont_letra++;
                cont_pos=(cont_pos+1)%5;
            }
        }
        
        cout<<caso<<" ";
        
        for(int i=0;i<R;i++)
            for(int j=0;j<C;j++)
                cout<<code[i][j];
        
        cout<<endl;
    }

    return 0;
}
