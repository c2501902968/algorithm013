import java.util.Deque;
import java.util.LinkedList;

// addFirst
public class Main {
    public static void main(String[] args) {
        Deque<String> deque = new LinkedList<>();

        deque.addFirst("a");
        deque.addFirst("b");
        deque.addFirst("c");
        System.out.println(deque);

        String str = deque.peek();
        System.out.println(str);
        System.out.println(deque);

        while (deque.size() > 0){
            System.out.println(deque.pop());
        }
        System.out.println(deque);
    }
}
// addLast
public class Main {
    public static void main(String[] args) {
        Deque<String> deque = new LinkedList<>();

        deque.addLast("c");
        deque.addLast("b");
        deque.addLast("a");
        System.out.println(deque);

        String str = deque.peek();
        System.out.println(str);
        System.out.println(deque);

        while (deque.size() > 0){
            System.out.println(deque.pop());
        }
        System.out.println(deque);
    }
}