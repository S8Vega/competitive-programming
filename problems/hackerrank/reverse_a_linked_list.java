import java.io.*;
import java.util.ArrayList;
import java.util.List;
import java.util.stream.IntStream;

public class reverse_a_linked_list {


    static class SinglyLinkedListNode {
        public int data;
        public SinglyLinkedListNode next;

        public SinglyLinkedListNode(int nodeData) {
            this.data = nodeData;
            this.next = null;
        }
    }

    static class SinglyLinkedList {
        public SinglyLinkedListNode head;
        public SinglyLinkedListNode tail;

        public SinglyLinkedList() {
            this.head = null;
            this.tail = null;
        }

        public void insertNode(int nodeData) {
            SinglyLinkedListNode node = new SinglyLinkedListNode(nodeData);

            if (this.head == null) {
                this.head = node;
            } else {
                this.tail.next = node;
            }

            this.tail = node;
        }
    }

    class SinglyLinkedListPrintHelper {
        public static void printList(SinglyLinkedListNode node, String sep, BufferedWriter bufferedWriter) throws IOException {
            while (node != null) {
                bufferedWriter.write(String.valueOf(node.data));

                node = node.next;

                if (node != null) {
                    bufferedWriter.write(sep);
                }
            }
        }
    }

    class Result {

        /*
         * Complete the 'reverse' function below.
         *
         * The function is expected to return an INTEGER_SINGLY_LINKED_LIST.
         * The function accepts INTEGER_SINGLY_LINKED_LIST llist as parameter.
         */

        /*
         * For your reference:
         *
         * SinglyLinkedListNode {
         *     int data;
         *     SinglyLinkedListNode next;
         * }
         *
         */

        public static SinglyLinkedListNode reverse(SinglyLinkedListNode llist) {
            List<SinglyLinkedListNode> lista = new ArrayList<>();
            while (llist != null) {
                lista.add(llist);
                llist = llist.next;
            }
            for (int i = 1; i < lista.size(); i++) {
                lista.get(i).next = lista.get(i - 1);
            }
            lista.get(0).next = null;
            return lista.get(lista.size() - 1);
        }

    }

    public class Solution {
        public static void main(String[] args) throws IOException {
            BufferedReader bufferedReader = new BufferedReader(new InputStreamReader(System.in));
            BufferedWriter bufferedWriter = new BufferedWriter(new FileWriter(System.getenv("OUTPUT_PATH")));

            int tests = Integer.parseInt(bufferedReader.readLine().trim());

            IntStream.range(0, tests).forEach(testsItr -> {
                try {
                    SinglyLinkedList llist = new SinglyLinkedList();

                    int llistCount = Integer.parseInt(bufferedReader.readLine().trim());

                    IntStream.range(0, llistCount).forEach(i -> {
                        try {
                            int llistItem = Integer.parseInt(bufferedReader.readLine().trim());

                            llist.insertNode(llistItem);
                        } catch (IOException ex) {
                            throw new RuntimeException(ex);
                        }
                    });

                    SinglyLinkedListNode llist1 = Result.reverse(llist.head);

                    SinglyLinkedListPrintHelper.printList(llist1, " ", bufferedWriter);
                    bufferedWriter.newLine();
                } catch (IOException ex) {
                    throw new RuntimeException(ex);
                }
            });

            bufferedReader.close();
            bufferedWriter.close();
        }
    }

}
