import java.io.*;
import java.util.HashMap;
import java.util.Map;
import java.util.Scanner;

public class frequency_queries {

    static Map<Integer, Integer> repetitionsOfKeys, repetitionsOfValues;

    public static void main(String[] args) {
        Scanner in = new Scanner(new BufferedReader(new InputStreamReader(System.in)));
        PrintWriter out = new PrintWriter(new BufferedWriter(new OutputStreamWriter(System.out)));
        int queries = in.nextInt();
        repetitionsOfKeys = new HashMap<>();
        repetitionsOfValues = new HashMap<>();
        while (queries-- > 0) {
            int operation = in.nextInt();
            int value = in.nextInt();
            if (operation == 1) insert(value);
            else if (operation == 2) delete(value);
            else out.println(check(value));
            // System.out.println(repetitions);
        }
        out.close();
    }

    static void insert(int key) {
        int value = 1;
        if (repetitionsOfKeys.containsKey(key)) {
            value += repetitionsOfKeys.get(key);
        }
        repetitionsOfKeys.put(key, value);
        deleteValue(value - 1);
        insertValue(value);
    }

    private static void insertValue(int value) {
        int key = 1;
        if (repetitionsOfValues.containsKey(value)) {
            key += repetitionsOfValues.get(value);
        }
        repetitionsOfValues.put(value, key);
    }

    static void delete(int key) {
        if (repetitionsOfKeys.containsKey(key)) {
            int value = repetitionsOfKeys.get(key);
            deleteValue(value);
            if (value == 1) repetitionsOfKeys.remove(key);
            else repetitionsOfKeys.put(key, value - 1);
        }
    }

    static void deleteValue(int value) {
        if (repetitionsOfValues.containsKey(value)) {
            int oldValue = repetitionsOfValues.get(value);
            if (oldValue == 1) repetitionsOfValues.remove(value);
            else repetitionsOfValues.put(value, oldValue - 1);
        }
    }

    static int check(int value) {
        return repetitionsOfValues.containsKey(value) ? 1 : 0;
    }
}
