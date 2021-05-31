import java.io.*;
import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;
import java.util.stream.IntStream;
import java.util.stream.Stream;

import static java.util.stream.Collectors.joining;
import static java.util.stream.Collectors.toList;

public class dynamic_array {

    public static void main(String[] args) throws IOException {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt(), q = sc.nextInt();
        List<Integer> arr[] = new List[n];
        for (int i = 0; i < n; i++) {
            arr[i] = new ArrayList<>();
        }
        int lastAnswer = 0, idx;
        while (q-- > 0) {
            int op = sc.nextInt(), x = sc.nextInt(), y = sc.nextInt();
            idx = (x ^ lastAnswer) % n;
            if (op == 1)
                arr[idx].add(y);
            else {
                lastAnswer = arr[idx].get(y % arr[idx].size());
                System.out.println(lastAnswer);
            }
        }
    }
}
