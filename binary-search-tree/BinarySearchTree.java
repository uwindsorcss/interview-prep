import java.util.*;

// An implementation of a Binary Search Tree.

// Given the values [5, 2, 4, 10, 7 8] inserted in that order, the resulting
// binary search tree would look like this:
//
//          5
//       /     \
//      2      10
//       \    /
//        4  7
//            \
//             8

public class BinarySearchTree<T extends Comparable<T>> {
  private Node<T> root = null;

  public BinarySearchTree() {
    root = null;
  }

  private int compare(T a, T b) {
    return a.compareTo(b);
  }

  /*
   * These methods insert a new node into the tree with the following
   * guidelines:
   *   - If |datum| is already in the tree, we do not add it again.
   *   - If |datum| is less than the root node's datum, it is inserted into the
   *     right subtree.
   *   - If |datum| is greater than the root node's datum, it is inerted into
   *     the right subtree.
   */
  public void insert(T datum) {
    root = insert(root, datum);
  }

  private Node<T> insert(Node<T> root, T datum) {
    if (root == null) {
      return new Node<T>(datum);
    }

    if (compare(datum, root.datum) < 0) {
      root.left = insert(root.left, datum);
    } else if (compare(datum, root.datum) > 0){
      root.right = insert(root.right, datum);
    }

    return root;
  }

  // These methods return whether or not |datum| is already in the tree.
  public boolean contains(T datum) {
    return contains(root, datum);
  }

  private boolean contains(Node<T> root, T datum) {
    if (root == null) {
      return false;
    }

    if (compare(datum, root.datum) == 0) {
      return true;
    } else if (compare(datum, root.datum) < 0) {
      return contains(root.left, datum);
    } else {
      return contains(root.right, datum);
    }
  }

  // Print the contents of the tree using the inorder traversal method.
  public void printInOrder() {
    printInOrder(root);
  }

  private void printInOrder(Node<T> root) {
    if (root == null) {
      return;
    }
    printInOrder(root.left);
    System.out.println(root.datum);
    printInOrder(root.right);
  }

  // Print the contents of the tree using the preorder traversal method.
  public void printPreOrder() {
    printPreOrder(root);
  }

  private void printPreOrder(Node<T> root) {
    if (root == null) {
      return;
    }
    System.out.println(root.datum);
    printPreOrder(root.left);
    printPreOrder(root.right);
  }

  // Print the contents of the tree using the postorder traversal method.
  public void printPostOrder() {
    printPostOrder(root);
  }

  private void printPostOrder(Node<T> root) {
    if (root == null) {
      return;
    }
    printPostOrder(root.left);
    printPostOrder(root.right);
    System.out.println(root.datum);
  }

  private class Node<T> {
    private Node<T> left;
    private Node<T> right;
    private T datum;

    public Node (T datum) {
      left = null;
      right = null;
      this.datum = datum;
    }
  }

  public static void main(String[] args) {
    BinarySearchTree<Integer> my_tree = new BinarySearchTree<Integer>();
    my_tree.insert(5);
    my_tree.insert(2);
    my_tree.insert(4);
    my_tree.insert(10);
    my_tree.insert(10);  // Repeat insert.
    my_tree.insert(7);
    my_tree.insert(8);
    System.out.println("In Order:");
    my_tree.printInOrder();
    System.out.println("Pre Order:");
    my_tree.printPreOrder();
    System.out.println("Post Order:");
    my_tree.printPostOrder();

    System.out.println(my_tree.contains(7));  // Should return true.
    System.out.println(my_tree.contains(3));  // Should return false.
  }
}
