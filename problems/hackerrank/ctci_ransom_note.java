import java.util.HashMap;
import java.util.Map;
import java.util.Scanner;

public class ctci_ransom_note {
    static int n, m;
    static String[] notes;
    static Map<String, Integer> magazines;

    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        n = in.nextInt();
        m = in.nextInt();
        magazines = new HashMap<>();
        notes = new String[m];
        for (int i = 0; i < n; i++) {
            String magazine = in.next();
            Integer value = magazines.get(magazine);
            magazines.put(magazine, (value == null ? 1 : value + 1));
        }
        for (int i = 0; i < m; i++) {
            notes[i] = in.next();
        }
        if (cumple()) {
            System.out.println("Yes");
        } else {
            System.out.println("No");
        }
    }

    static Boolean cumple() {
        for (String note : notes) {
            if (magazines.containsKey(note)) {
                magazines.put(note, magazines.get(note) - 1);
                if (magazines.get(note) == 0) {
                    magazines.remove(note);
                }
            } else return false;
        }
        return true;
    }
}
