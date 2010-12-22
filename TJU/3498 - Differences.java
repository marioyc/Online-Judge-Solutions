import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.StringTokenizer;
import java.math.BigInteger;

public class Main {
    public static void main(String args[]) throws Exception{
        BufferedReader in = new BufferedReader(new InputStreamReader(System.in));

        int T = Integer.parseInt(in.readLine());

        for(int tc = 1;tc<=T;++tc){
            int N = Integer.parseInt(in.readLine());
            StringTokenizer st = new StringTokenizer(in.readLine());

            String first = st.nextToken();
            BigInteger min = new BigInteger(first);
            BigInteger max = new BigInteger(first);

            for(int i = 1;i<N;++i){
                BigInteger x = new BigInteger(st.nextToken());
                min = min.min(x);
                max = max.max(x);
            }

            System.out.println(max.subtract(min));
        }
    }
}

