#include <iostream>
#include <cstring>

using namespace std;

int head,tail;
bool visited[100][100][101];

struct node{
    int posB,posO,nxt,dist;
    
    node(){}
    
    node(int _posB, int _posO, int _nxt, int _dist){
        posB = _posB; posO = _posO; nxt = _nxt; dist = _dist;
    }
}Q[1010000],aux;

int main(){
    int T,N,pos[100];
    int dr[] = {-1,0,1};
    char robot[100];
    
    cin >> T;
    
    for(int tc = 1;tc <= T;++tc){
        cin >> N;
        
        for(int i = 0;i < N;++i){
            cin >> robot[i] >> pos[i];
            --pos[i];
        }
        
        memset(visited,false,sizeof(visited));
        
        head = tail = 0;
        visited[0][0][0] = 0;
        Q[tail++] = node(0,0,0,0);
        
        while(head < tail){
            aux = Q[head++];
            
            if(aux.nxt == N){
                cout << "Case #" << tc << ": " << aux.dist << endl;
                break;
            }
            
            for(int i = 0;i < 3;++i){
                int posB2 = aux.posB + dr[i];
                
                if(posB2 >= 0 && posB2 < 100){
                    for(int j = 0;j < 3;++j){
                        int posO2 = aux.posO + dr[j];
                        
                        if(posO2 >= 0 && posO2 < 100 && !visited[posB2][posO2][aux.nxt]){
                            visited[posB2][posO2][aux.nxt] = true;
                            Q[tail++] = node(posB2, posO2, aux.nxt, aux.dist + 1);
                        }
                    }
                    
                    if(robot[aux.nxt] == 'O' && pos[aux.nxt] == aux.posO && !visited[posB2][aux.posO][aux.nxt + 1]){
                        visited[posB2][aux.posO][aux.nxt + 1] = true;
                        Q[tail++] = node(posB2, aux.posO, aux.nxt + 1, aux.dist + 1);
                    }
                }
            }
            
            if(robot[aux.nxt] == 'B' && pos[aux.nxt] == aux.posB){
                for(int j = 0;j < 3;++j){
                    int posO2 = aux.posO + dr[j];
                    
                    if(posO2 >= 0 && posO2 < 100 && !visited[aux.posB][posO2][aux.nxt + 1]){
                        visited[aux.posB][posO2][aux.nxt + 1] = true;
                        Q[tail++] = node(aux.posB, posO2, aux.nxt + 1, aux.dist + 1);
                    }
                }
            }
        }
    }
    
    return 0;
}
