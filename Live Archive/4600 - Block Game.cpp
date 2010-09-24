#include <iostream>
#include <cstring>
#include <string>
#include <queue>
#include <set>

using namespace std;

struct node{
    int dist;
    string M[6];
    
    node(){}
    
    bool canWin(char s){
    	for(int i = 0;i<6;++i) for(int j = 0;j<6;++j){
    	    if(M[i][j]==s){
    	        for(int k = j+1;k<6;++k)
    	            if(M[i][k]!=s && M[i][k]!='.')
    	            	return false;
    	        return true;
    	    }
    	}
    	
    	return false; // nunca llega
    }
    
    string getString(){
    	string ret;
    	for(int i = 0;i<6;++i) ret += M[i];
    	return ret;
    }
    
    void print(){
    	for(int i = 0;i<6;++i) cout<<M[i]<<endl;
    	cout<<endl;
    }
}aux,aux2;

set<string> visited;

int solve(char s){
    visited.clear();
    
    for(int i = 0;i<6;++i) cin>>aux.M[i];
    aux.dist = 0;
    if(aux.canWin(s)) return 1;
    
    queue<node> Q;
    Q.push(aux);
    visited.insert(aux.getString());
    
    bool used[26];
    
    while(!Q.empty()){
    	aux = Q.front();
    	Q.pop();
    	//aux.print();
    	
    	memset(used,false,sizeof(used));
    	
    	// mover piezas horizontales
    	
    	for(int r = 0;r<6;++r) for(int c = 0;c<6;++c){
    	    if(aux.M[r][c]!='.' && !used[aux.M[r][c]-'A']){
    	    	char cur = aux.M[r][c];
    	    	int l = 0;
    	    	
    	    	for(int c2 = c;c2<6;++c2)
    	    	    if(aux.M[r][c2]==cur) ++l;
    	    	
    	    	if(l==1) continue;
    	    	used[aux.M[r][c]-'A'] = true;
    	    	
    	    	for(int c2 = c+l;c2<6;++c2){
    	    	    if(aux.M[r][c2]=='.'){
    	    	        aux2 = aux;
    	    	        aux2.dist = aux.dist+1;
    	    	        for(int i = 0;i<l;++i) aux2.M[r][c+i] = '.';
    	    	        for(int i = 0;i<l;++i) aux2.M[r][c2-i] = cur;
    	    	        
    	    	        if(visited.find(aux2.getString())==visited.end()){
    	    	            Q.push(aux2);
    	    	            visited.insert(aux2.getString());
    	    	        }
    	    	    }else break;
    	    	}
    	    	
    	    	for(int c2 = c-1;c2>=0;--c2){
                    if(aux.M[r][c2]=='.'){
                        aux2 = aux;
                        aux2.dist = aux.dist+1;
                        for(int i = 0;i<l;++i) aux2.M[r][c+i] = '.';
                        for(int i = 0;i<l;++i) aux2.M[r][c2+i] = cur;
                        
                        if(visited.find(aux2.getString())==visited.end()){
                            Q.push(aux2);
                            visited.insert(aux2.getString());
                        }
                    }else break;
                }
    	    }
    	}
    	
    	// mover piezas verticales
    	
    	for(int r = 0;r<6;++r) for(int c = 0;c<6;++c){
            if(aux.M[r][c]!='.' && !used[aux.M[r][c]-'A']){
                char cur = aux.M[r][c];
                int l = 0;
                
                for(int r2 = r;r2<6;++r2)
                    if(aux.M[r2][c]==cur) ++l;
                
                if(l==1) continue;
                used[aux.M[r][c]-'A'] = true;
                
                for(int r2 = r+l;r2<6;++r2){
                    if(aux.M[r2][c]=='.'){
                        aux2 = aux;
                        aux2.dist = aux.dist+1;
                        for(int i = 0;i<l;++i) aux2.M[r+i][c] = '.';
                        for(int i = 0;i<l;++i) aux2.M[r2-i][c] = cur;
                        
                        if(visited.find(aux2.getString())==visited.end()){
                            Q.push(aux2);
                            visited.insert(aux2.getString());
                            if(aux2.canWin(s)) return 1+aux2.dist;
                        }
                    }else break;
                }
                
                for(int r2 = r-1;r2>=0;--r2){
                    if(aux.M[r2][c]=='.'){
                        aux2 = aux;
                        aux2.dist = aux.dist+1;
                        for(int i = 0;i<l;++i) aux2.M[r+i][c] = '.';
                        for(int i = 0;i<l;++i) aux2.M[r2+i][c] = cur;
                        
                        if(visited.find(aux2.getString())==visited.end()){
                            Q.push(aux2);
                            visited.insert(aux2.getString());
                            if(aux2.canWin(s)) return 1+aux2.dist;
                        }
                    }else break;
                }
            }
        }
    }
    
    return -1;
}

int main(){
    char s;
    
    while(true){
    	cin>>s;
    	if(s=='*') break;
    	cout<<solve(s)<<endl;
    }
    
    return 0;
}
