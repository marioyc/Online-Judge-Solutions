import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.IOException;
import java.util.StringTokenizer;

class MaxFlow{
    int V,E,f;
    int flow[] = new int[250];
    int cap[] = new int[250];
    int to[] = new int[250];
    int next[] = new int[250];
    int last[] = new int[27];
    int fromParent[] = new int[27];
    int Q[] = new int[27], head, tail, aux;

    void init(int V){
        this.V = V;
        E = 0;
        for(int i=0;i<V;i++) last[i] = -1;
    }

    void insertEdge(int u, int v, int c){
        next[E] = last[u];
        last[u] = E;
        to[E] = v;
        cap[E] = c;
        E++;
    }

    boolean augment(){
        Q[0] = 0; head = 0; tail = 1;

        while(head != tail){
            aux = Q[head++];

            for(int pos=last[aux],v;pos!=-1;pos=next[pos]){
                v = to[pos];
                if(fromParent[v]==-1 && flow[pos]<cap[pos]){
                    fromParent[v] = pos;
                    Q[tail++] = v;
                }
            }
        }

        if(fromParent[V-1]==-1) return false;

        int cur = fromParent[V-1];

        while(cur!=-2){
            flow[cur]++;
            flow[cur ^ 1]--;
            cur = fromParent[to[cur ^ 1]];
        }

        f++;

        return true;
    }

    int maxFlow(){
        for(int i=0;i<E;i++) flow[i] = 0;
        
        f = 0;

        do{
            fromParent[0] = -2;
            for(int i=1;i<V;i++) fromParent[i] = -1;
        }while(augment());

        return f;
    }
}

public class Main{
    public static int ind(char c){
        if(c=='S') return 0;
        if(c=='M') return 1;
        if(c=='L') return 2;
        if(c=='X') return 3;
        return 4;
    }

    public static void main(String args[]) throws IOException{
        BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st;
        String line,preferences;
        int N,lo,hi,num[] = new int[5];
        MaxFlow myFlow = new MaxFlow();

        while(true){
            line = in.readLine();
            if(line.charAt(0) == 'E') break;

            st = new StringTokenizer(line);
            st.nextToken();
            N = Integer.parseInt(st.nextToken());

            myFlow.init(N+7);

            for(int i=1;i<=N;i++){
                myFlow.insertEdge(0,i,1);
                myFlow.insertEdge(i,0,0);
            }

            line = in.readLine();
            st = new StringTokenizer(line);

            for(int i=1;i<=N;i++){
                preferences = st.nextToken();
                lo = ind(preferences.charAt(0));
                hi = ind(preferences.charAt(1));
                
                for(int j=lo;j<=hi;j++){
                    myFlow.insertEdge(i,N+1+j,1);
                    myFlow.insertEdge(N+1+j,i,0);
                }
            }

            line = in.readLine();
            st = new StringTokenizer(line);

            for(int i=0;i<5;i++) num[i] = Integer.parseInt(st.nextToken());

            in.readLine();

            for(int i=N+1;i<=N+5;i++){
                myFlow.insertEdge(i,N+6,num[i-N-1]);
                myFlow.insertEdge(N+6,i,0);
            }

            if(myFlow.maxFlow() == N) System.out.println("T-shirts rock!");
            else System.out.println("I'd rather not wear a shirt anyway...");
        }
    }
}
