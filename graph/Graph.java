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
  private HashMap<T, Integer> _incomingEdges;

  Graph() {
    _adjacencyMap = new HashMap<T, HashSet<T>>();
    _incomingEdges = new HashMap<T, Integer>();
  }

  // Connecting two nodes is as easy as inserting one in the others adjacent
  // set.
  void connect(T u, T v) {
    _adjacencyMap.putIfAbsent(u, new HashSet<T>());
    _adjacencyMap.get(u).add(v);
    _incomingEdges.putIfAbsent(u, 0);
    _incomingEdges.putIfAbsent(v, 0);
    _incomingEdges.put(v, _incomingEdges.get(v) + 1);
  }

  // Disconnect u from v.
  void disconnect(T u, T v) {
    _adjacencyMap.getOrDefault(u, new HashSet<T>()).remove(v);
    if (_incomingEdges.containsKey(v)) {
      _incomingEdges.put(v, _incomingEdges.get(v) - 1);
    }
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

  // Alternative version of topological sort that uses a breadth-first search
  // and a map which keeps track of incoming edges for each vertex.
  ArrayList<T> topoSort2() {
    ArrayList<T> topoSorted = new ArrayList<T>();
    Queue<T> q = new LinkedList<T>();

    for (Map.Entry<T, Integer> entry : _incomingEdges.entrySet()) {
      if (entry.getValue().intValue() == 0) {
        q.add(entry.getKey());
      }
    }

    while (!q.isEmpty()) {
      T front = q.poll();
      topoSorted.add(front);

      ArrayList<T> toBeDeleted = new ArrayList<T>();
      for (T neighb : adjacentTo(front)) {
        toBeDeleted.add(neighb);
        if (_incomingEdges.get(neighb).intValue() == 1) {
          q.add(neighb);
        }
      }

      for (T u : toBeDeleted) {
        disconnect(front, u);
      }
    }

    return topoSorted;
  }
}
