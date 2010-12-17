import java.util.Scanner;
import java.math.BigInteger;

public class tju1855 {
    public static void main(String args[]){
        BigInteger count0[] = new BigInteger[1001];
        BigInteger count1[] = new BigInteger[1001];

        count0[0] = count1[0] = BigInteger.ZERO;

        for(int i = 1;i<=1000;++i){
            count0[i] = count1[i] = count0[i-1].add(count1[i-1]);
            if(i%2==0) count0[i] = count0[i].add(BigInteger.ONE);
        }

        Scanner in = new Scanner(System.in);

        while(in.hasNextInt()){
            int n = in.nextInt();
            System.out.println(count0[n]);
        }
    }
}
