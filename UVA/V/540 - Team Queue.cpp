#include<iostream>
#include<vector>
#include<set>

using namespace std;

struct nodo{
    int num,orden,pos;
    
    nodo(int a, int b, int c){
        num=a;
        orden=b;
        pos=c;
    }
    
    bool operator < (nodo X)const{
        if(orden!=X.orden) return orden<X.orden;
        return pos<X.pos;
    }
};

int main(){
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
    
    set<nodo> team_queue;
    int t,n,a,cont,caso=1;
    string command;
    
    vector<int> N(1000000);
    int cont_team[1000];
    int team[1000];
    int pos[1000];
    
    set<nodo> :: iterator it;
    
    while(cin>>t){
        if(t==0) break;
    
        cout<<"Scenario #"<<caso<<endl;
        caso++;
    
        for(int i=0;i<t;i++){
            scanf("%d",&n);
            for(int j=0;j<n;j++){
                cin>>a;
                N[a]=i;
            }
        }
        
        fill(team,team+t,0);
        fill(cont_team,cont_team+t,0);
        
        cont=0;
        
        team_queue.clear();
        
        while(cin>>command){
            if(command[0]=='S') break;
            else if(command[0]=='D'){
                it=team_queue.begin();
                printf("%d\n",(*it).num);
                cont_team[N[(*it).num]]--;
                team_queue.erase(*it);                
            }else{
                scanf("%d",&a);
                if(cont_team[N[a]]==0){
                    cont_team[N[a]]=1;
                    team[N[a]]++;
                    team_queue.insert(nodo(a,cont,1));
                    pos[N[a]]=cont;
                    cont++;
                }else{
                    cont_team[N[a]]++;
                    team[N[a]]++;
                    team_queue.insert(nodo(a,pos[N[a]],team[N[a]]));
                }
            }
        }
        cout<<endl;
    }
    
    return 0;
}
