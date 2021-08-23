import java.io.*;
import java.util.HashMap;
import java.util.Map;
import java.util.Scanner;

public class SparseArrays {

    private static final int N = 1010;

    public static void main(String[] args) {
        int n;
        int q;
        String[] strings = new String[N];
        String[] queries = new String[N];
        Scanner in = new Scanner(new BufferedReader(new InputStreamReader(System.in)));
        PrintWriter out = new PrintWriter(new BufferedWriter(new OutputStreamWriter(System.out)));
        Map<String, Integer> repetitions = new HashMap<>();
        n = in.nextInt();
        int valor;
        for (int i = 0; i < n; i++) {
            strings[i] = in.next();
            valor = repetitions.containsKey(strings[i]) ? repetitions.get(strings[i]) + 1 : 1;
            repetitions.put(strings[i], valor);
        }
        q = in.nextInt();
        for (int i = 0; i < q; i++) {
            queries[i] = in.next();
            out.println(repetitions.getOrDefault(queries[i], 0));
        }
        out.close();
    }
}