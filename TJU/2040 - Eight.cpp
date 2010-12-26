#include <iostream>
#include <cstdio>
#include <string>
#include <queue>
#include <map>

using namespace std;

struct state{
    int M[3][3],r,c,dist;
    string path;
    
    state(){}
    
    int getVal(){
        int ret = 0;
        
        for(int i = 0;i<3;++i)
            for(int j = (i>0? 0 : 1);j<3;++j)
                ret = ret*10+M[i][j];
        
        return ret;
    }
}aux,aux2;

map<int, string> visited;

void bfs(){
    for(int i = 0;i<8;++i)
        aux.M[i/3][i%3] = i+1;
    
    aux.M[2][2] = 0;
    aux.dist = 0;
    aux.r = aux.c = 2;
    aux.path = string();
    
    queue<state> Q;
    
    Q.push(aux);
    visited[23456780] = string();
    
    while(!Q.empty()){
        aux = Q.front();
        Q.pop();
        
        if(aux.dist==999) break;
        
        int r = aux.r,c = aux.c;
        
        if(r>0){
            aux2 = aux;
            
            swap(aux2.M[r][c],aux2.M[r-1][c]);
            ++aux2.dist;
            --aux2.r;
            
            aux2.path += 'd';
            
            int val = aux2.getVal();
            
            if(visited.find(val)==visited.end()){
                visited[val] = aux2.path;
                Q.push(aux2);
            }
        }
        
        if(r<2){
            aux2 = aux;
            
            swap(aux2.M[r][c],aux2.M[r+1][c]);
            ++aux2.dist;
            ++aux2.r;
            
            aux2.path += 'u';
            
            int val = aux2.getVal();
            
            if(visited.find(val)==visited.end()){
                visited[val] = aux2.path;
                Q.push(aux2);
            }
        }
        
        if(c>0){
            aux2 = aux;
            
            swap(aux2.M[r][c],aux2.M[r][c-1]);
            ++aux2.dist;
            --aux2.c;
            
            aux2.path += 'r';
            
            int val = aux2.getVal();
            
            if(visited.find(val)==visited.end()){
                visited[val] = aux2.path;
                Q.push(aux2);
            }
        }
        
        if(c<2){
            aux2 = aux;
            
            swap(aux2.M[r][c],aux2.M[r][c+1]);
            ++aux2.dist;
            ++aux2.c;
            
            aux2.path += 'l';
            
            int val = aux2.getVal();
            
            if(visited.find(val)==visited.end()){
                visited[val] = aux2.path;
                Q.push(aux2);
            }
        }
    }
}

int main(){
    bfs();    
    
    char c;
    
    while(cin>>c){
        int val = 0;
        
        for(int i = 0;i<8;++i){
            cin>>c;
            if(c=='x') val *= 10;
            else val = val*10+(c-'0');
        }
        
        if(visited.find(val)!=visited.end()){
            string s = visited[val];
            
            for(int i = s.size()-1;i>=0;--i)
                putchar(s[i]);
            putchar('\n');
        }else cout<<"unsolvable\n";
    }
    
    return 0;
}
