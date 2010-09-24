#include<iostream>
#include<string>

using namespace std;

int main(){
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    
    int num[80];
    int cycle[80][80];
    int size[80];
    int pos[80][2];
    bool visited[80];
    int n,m,aux,cont_cycle;
    string s;
    
    while(1){
        cin>>n>>m;
        if(n==0 && m==0) break;
        for(int i=0;i<n;i++){
            cin>>aux;
            num[aux-1]=i;
        }
        getline(cin,s);
        getline(cin,s);
        
        memset(visited,0,sizeof(visited));
        memset(size,0,sizeof(size));
        cont_cycle=0;
        
        for(int i=0,j=i;i<n;i++){
            if(visited[i]) continue;
            
            visited[i]=1;
            pos[i][0]=cont_cycle; pos[i][1]=0;
            size[cont_cycle]=1;
            cycle[cont_cycle][0]=i;
            j=num[i];
            
            while(j!=i){
                pos[j][0]=cont_cycle; pos[j][1]=size[cont_cycle];
                visited[j]=1;
                cycle[cont_cycle][size[cont_cycle]++]=j;
                
                j=num[j];
            }
            
            cont_cycle++;
        }
        
        string ans(n,' ');
        
        for(int i=0;i<n;i++) ans[i]=s[cycle[pos[i][0]][(pos[i][1]+m)%size[pos[i][0]]]];
        
        cout<<ans<<endl;
    }
    
    return 0;
}
