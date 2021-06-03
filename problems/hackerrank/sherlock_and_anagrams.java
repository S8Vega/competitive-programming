import java.util.HashMap;
import java.util.Map;
import java.util.Scanner;

public class sherlock_and_anagrams {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int t = in.nextInt();
        while (t-- > 0) {
            System.out.println(countAnagrams(in.next()));
        }
    }

    static long countAnagrams(String s) {
        Map<String, Integer> repetitions = new HashMap<>();
        for (int i = 0; i < s.length(); i++) {
            for (int j = i + 1; j <= s.length(); j++) {
                String anagram = s.substring(i, j);
                anagram = anagram.chars().sorted().collect(StringBuilder::new, StringBuilder::appendCodePoint, StringBuilder::append).toString();
                Integer rep = repetitions.get(anagram);
                rep = rep == null ? 1 : rep + 1;
                repetitions.put(anagram, rep);
            }
        }
        return repetitions.values().stream().mapToLong(x -> (long) x * (x - 1) / 2).sum();
    }
}
