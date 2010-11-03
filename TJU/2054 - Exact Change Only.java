import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.IOException;
import java.util.StringTokenizer;

public class Main{
    public static void main(String args[]) throws IOException{
        BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st;
        String line;
        int N,B,C,D,E,x,y,z,w,x2,y2,z2,w2,coins;

        while(true){
            line = in.readLine();
            if(line.isEmpty() == true) break;

            st = new StringTokenizer(line);

            N = (int)(Double.parseDouble(st.nextToken()) * 100);
            B = Integer.parseInt(st.nextToken());
            C = Integer.parseInt(st.nextToken());
            D = Integer.parseInt(st.nextToken());
            E = Integer.parseInt(st.nextToken());

            coins = -1;
            x = y = z = w = 0;

            for(y2 = Math.min(N/10,C);y2>=0;y2--){
                int M = N-10*y2;

                x2 = Math.min(M/25,B);
                M-=25*x2;

                z2 = Math.min(M/5,D);
                M-=5*z2;

                w2=M;

                if(w2<=E && (coins == -1 || x2+y2+z2+w2<coins)){
                    coins = x2+y2+z2+w2;
                    x = x2; y = y2; z = z2; w = w2;
                }
            }

            if(coins == -1) System.out.println("NO EXACT CHANGE");
            else System.out.println(x + " " + y + " " + z + " " + w);
        }
    }
}
