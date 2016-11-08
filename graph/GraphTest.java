import java.util.*;

public class GraphTest {
  public static void main(String[] args) {
    Graph<Integer> g = new Graph<Integer>();

    g.connect(5, 11);
    g.connect(7, 11);
    g.connect(7, 8);
    g.connect(3, 8);
    g.connect(3, 10);
    g.connect(11, 2);
    g.connect(11, 9);
    g.connect(11, 10);
    g.connect(8, 9);

    ArrayList<Integer> topoSorted = g.topoSort2();

    for (Integer i : topoSorted) {
      System.out.println(i);
    }
  }
}
