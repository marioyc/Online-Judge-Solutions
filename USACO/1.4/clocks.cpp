/*
ID:zion_ba1
LANG:C++
TASK:clocks
*/

#include <cstdio>
#include <queue>
#include <vector>

using namespace std;

struct clocks{
    int t[9];
    vector<int> L;
    
    clocks(){
    }
};

void inc(clocks &x, int pos){
    x.t[pos]=(x.t[pos]+1)&3;
}

void dec(clocks &x, int pos){
    x.t[pos]=(x.t[pos]+3)&3;
}

int main(){
    freopen("clocks.in","r",stdin);
    freopen("clocks.out","w",stdout);
    
    int t[9];
    
    for(int i=0;i<9;i++) scanf("%d",&t[i]);
    for(int i=0;i<9;i++) t[i]=(t[i]/3-1);
    
    queue<clocks> Q;
    
    clocks aux;
    
    for(int i=0;i<9;i++) aux.t[i]=t[i];
    aux.L.clear();
    Q.push(aux);
    
    bool visited[4][4][4][4][4][4][4][4][4];
    for(int i1=0;i1<4;i1++)
        for(int i2=0;i2<4;i2++)
            for(int i3=0;i3<4;i3++)
                for(int i4=0;i4<4;i4++)
                    for(int i5=0;i5<4;i5++)
                        for(int i6=0;i6<4;i6++)
                            for(int i7=0;i7<4;i7++)
                                for(int i8=0;i8<4;i8++)
                                    for(int i9=0;i9<4;i9++)
                                        visited[i1][i2][i3][i4][i5][i6][i7][i8][i9]=false;
    visited[t[0]][t[1]][t[2]][t[3]][t[4]][t[5]][t[6]][t[7]][t[8]]=true;
    
    bool solved=false;
    
    while(!Q.empty()){
        aux=Q.front();
        Q.pop();
        
        solved=true;
        for(int i=0;i<9;i++) if(aux.t[i]!=3) solved=false;
        if(solved){
            for(int i=0;i<aux.L.size();i++){
                if(i!=0) printf(" ");
                printf("%d",aux.L[i]);
            }
            printf("\n");
            break;
        }
        
        aux.L.push_back(1);
        inc(aux,0); inc(aux,1); inc(aux,3); inc(aux,4);
        if(!visited[aux.t[0]][aux.t[1]][aux.t[2]][aux.t[3]][aux.t[4]][aux.t[5]][aux.t[6]][aux.t[7]][aux.t[8]]){
            visited[aux.t[0]][aux.t[1]][aux.t[2]][aux.t[3]][aux.t[4]][aux.t[5]][aux.t[6]][aux.t[7]][aux.t[8]]=true;
            Q.push(aux);
        }
        dec(aux,0); dec(aux,1); dec(aux,3); dec(aux,4);
        
        int pos=aux.L.size()-1;
        
        inc(aux,0); inc(aux,1); inc(aux,2);
        if(!visited[aux.t[0]][aux.t[1]][aux.t[2]][aux.t[3]][aux.t[4]][aux.t[5]][aux.t[6]][aux.t[7]][aux.t[8]]){
            visited[aux.t[0]][aux.t[1]][aux.t[2]][aux.t[3]][aux.t[4]][aux.t[5]][aux.t[6]][aux.t[7]][aux.t[8]]=true;
            aux.L[pos]=2;
            Q.push(aux);
        }
        dec(aux,0); dec(aux,1); dec(aux,2);
        
        inc(aux,1); inc(aux,2); inc(aux,4); inc(aux,5);
        if(!visited[aux.t[0]][aux.t[1]][aux.t[2]][aux.t[3]][aux.t[4]][aux.t[5]][aux.t[6]][aux.t[7]][aux.t[8]]){
            visited[aux.t[0]][aux.t[1]][aux.t[2]][aux.t[3]][aux.t[4]][aux.t[5]][aux.t[6]][aux.t[7]][aux.t[8]]=true;
            aux.L[pos]=3;
            Q.push(aux);
        }
        dec(aux,1); dec(aux,2); dec(aux,4); dec(aux,5);
        
        inc(aux,0); inc(aux,3); inc(aux,6);
        if(!visited[aux.t[0]][aux.t[1]][aux.t[2]][aux.t[3]][aux.t[4]][aux.t[5]][aux.t[6]][aux.t[7]][aux.t[8]]){
            visited[aux.t[0]][aux.t[1]][aux.t[2]][aux.t[3]][aux.t[4]][aux.t[5]][aux.t[6]][aux.t[7]][aux.t[8]]=true;
            aux.L[pos]=4;
            Q.push(aux);
        }
        dec(aux,0); dec(aux,3); dec(aux,6);
        
        inc(aux,1); inc(aux,3); inc(aux,4); inc(aux,5); inc(aux,7);
        if(!visited[aux.t[0]][aux.t[1]][aux.t[2]][aux.t[3]][aux.t[4]][aux.t[5]][aux.t[6]][aux.t[7]][aux.t[8]]){
            visited[aux.t[0]][aux.t[1]][aux.t[2]][aux.t[3]][aux.t[4]][aux.t[5]][aux.t[6]][aux.t[7]][aux.t[8]]=true;
            aux.L[pos]=5;
            Q.push(aux);
        }
        dec(aux,1); dec(aux,3); dec(aux,4); dec(aux,5); dec(aux,7);
        
        inc(aux,2); inc(aux,5); inc(aux,8);
        if(!visited[aux.t[0]][aux.t[1]][aux.t[2]][aux.t[3]][aux.t[4]][aux.t[5]][aux.t[6]][aux.t[7]][aux.t[8]]){
            visited[aux.t[0]][aux.t[1]][aux.t[2]][aux.t[3]][aux.t[4]][aux.t[5]][aux.t[6]][aux.t[7]][aux.t[8]]=true;
            aux.L[pos]=6;
            Q.push(aux);
        }
        dec(aux,2); dec(aux,5); dec(aux,8);
        
        inc(aux,3); inc(aux,4); inc(aux,6); inc(aux,7);
        if(!visited[aux.t[0]][aux.t[1]][aux.t[2]][aux.t[3]][aux.t[4]][aux.t[5]][aux.t[6]][aux.t[7]][aux.t[8]]){
            visited[aux.t[0]][aux.t[1]][aux.t[2]][aux.t[3]][aux.t[4]][aux.t[5]][aux.t[6]][aux.t[7]][aux.t[8]]=true;
            aux.L[pos]=7;
            Q.push(aux);
        }
        dec(aux,3); dec(aux,4); dec(aux,6); dec(aux,7);
        
        inc(aux,6); inc(aux,7); inc(aux,8);
        if(!visited[aux.t[0]][aux.t[1]][aux.t[2]][aux.t[3]][aux.t[4]][aux.t[5]][aux.t[6]][aux.t[7]][aux.t[8]]){
            visited[aux.t[0]][aux.t[1]][aux.t[2]][aux.t[3]][aux.t[4]][aux.t[5]][aux.t[6]][aux.t[7]][aux.t[8]]=true;
            aux.L[pos]=8;
            Q.push(aux);
        }
        dec(aux,6); dec(aux,7); dec(aux,8);
        
        inc(aux,4); inc(aux,5); inc(aux,7); inc(aux,8);
        if(!visited[aux.t[0]][aux.t[1]][aux.t[2]][aux.t[3]][aux.t[4]][aux.t[5]][aux.t[6]][aux.t[7]][aux.t[8]]){
            visited[aux.t[0]][aux.t[1]][aux.t[2]][aux.t[3]][aux.t[4]][aux.t[5]][aux.t[6]][aux.t[7]][aux.t[8]]=true;
            aux.L[pos]=9;
            Q.push(aux);
        }
        dec(aux,4); dec(aux,5); dec(aux,7); dec(aux,8);
    }
    
    return 0;
}
