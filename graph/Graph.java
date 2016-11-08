import java.util.*;

// An unweighted graph implementation.  Instead of using an adjacency list
// (which doesn't work particularly well for generic node types) this
// implementation uses an adjacency map.  That is, each node is mapped to a set
// of adjacent nodes.
//
// The following undirected graph:
//          d
//         /
//    b - c
//   /    |
// a      |
//  \ e - f
//
// Would be represented as:
// {
//  a : {b, e},
//  b : {a, c},
//  e : {a, f},
//  c : {b, d, f},
//  f : {e, c},
//  d : {c}
// }
public class Graph<T> {
  private HashMap<T, HashSet<T>> _adjacencyMap;

  Graph() {
    _adjacencyMap = new HashMap<T, HashSet<T>>();
  }
  // Connecting two nodes is as easy as inserting one in the others adjacent
  // set.
  void connect(T u, T v) {
    _adjacencyMap.putIfAbsent(u, new HashSet<T>());
    _adjacencyMap.get(u).add(v);
  }

  // Disconnect u from v.
  void disconnect(T u, T v) {
    _adjacencyMap.getOrDefault(u, new HashSet<T>()).remove(v);
  }

  // Connect u to v and v to u.
  void connectBidirectional(T u, T v) {
    connect(u, v);
    connect(v, u);
  }

  // Get all nodes adjacent to u.  If u is not present in the graph, an empty
  // set will be returned.
  HashSet<T> adjacentTo(T u) {
    return _adjacencyMap.getOrDefault(u, new HashSet<T>());
  }

  // Returns a topological ordering of the current graph.
  ArrayList<T> topoSort() {
    Stack<T> stk = new Stack<T>();
    HashSet<T> marked = new HashSet<T>();

    for (Map.Entry<T, HashSet<T>> entry : _adjacencyMap.entrySet()) {
      if (!marked.contains(entry.getKey())) {
        visit(entry.getKey(), marked, stk);
      }
    }

    ArrayList<T> topoSorted = new ArrayList<T>();
    while (!stk.empty()) {
      topoSorted.add(stk.pop());
    }

    return topoSorted;
  }

  // Does a post order traversal of the graph, adding visited
  // elements to a stack used to find the topological ordering.
  private void visit(T u, HashSet<T> marked, Stack<T> stk) {
    if (!marked.contains(u)) {
      for (T neighb : adjacentTo(u)) {
        visit(neighb, marked, stk);
      }
      marked.add(u);
      stk.push(u);
    }
  }
}
