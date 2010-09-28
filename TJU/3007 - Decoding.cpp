#include<iostream>
#include<string>

using namespace std;

int a,b,ax;

void rotar(){
    ax=b;
    b=-a;
    a=ax;
}

int main(){
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);

    char M[27];

    M[0]=' ';
    for(int i=0;i<26;i++) M[i+1]='A'+i;

    int N,R,C;
    int r,c,sum,pos;
    string binary,message;
    bool code[22][22];
    bool visited[22][22];

    cin>>N;
    
    for(int caso=1;caso<=N;caso++){
        cin>>R>>C;
        
        cin>>binary;
        
        memset(code,0,sizeof(code));
        
        for(int i=0;i<R;i++)
            for(int j=0;j<C;j++)
                if(binary[C*i+j]=='1') code[i][j]=1;
        
        r=0;c=0;
        a=0;b=1;
        pos=0;
        sum=0;
        message="";
        memset(visited,0,sizeof(visited));
        
        for(int i=0;i<R*C;i++){
            if(i<2*R+2*C-5){
                if(i==C-1) rotar();
                if(i==C+R-2) rotar();
                if(i==2*C+R-3) rotar();
            }else if(visited[r+a][c+b]) rotar();
            
            if(code[r][c]==1) sum+=(1<<(4-pos));
            pos++;
            
            if(pos==5){
                message+=M[sum];
                sum=0;
                pos=0;
            }
            
            visited[r][c]=1;
            r+=a;
            c+=b;
        }
        
        while(message[message.size()-1]==' ') message.erase(message.size()-1,1);
        
        cout<<caso<<" "<<message<<endl;
    }
    
    return 0;
}
