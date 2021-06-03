import java.util.HashSet;
import java.util.Scanner;
import java.util.Set;

public class two_strings {
    static String s1, s2;

    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int t = in.nextInt();
        while (t-- > 0) {
            s1 = in.next();
            s2 = in.next();
            twoStrings();
        }
    }

    static void twoStrings() {
        Set<Integer> characters = new HashSet<>();
        s1.chars().forEach(characters::add);
        if (s2.chars().anyMatch(characters::contains)){
            System.out.println("YES");
        } else {
            System.out.println("NO");
        }
    }
}
