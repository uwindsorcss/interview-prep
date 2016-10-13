import java.util.*;

// An implementation of a singly linked list.

public class LinkedList<T> {
  private Node<T> head = null;

  public LinkedList() {}

  public void append(T datum) {
    Node<T> new_node = new Node<T>(datum);
    if (head == null) {
      head = new_node;
    } else {
      Node<T> tmp = head;
      while (tmp.next != null) {
        tmp = tmp.next;
      }
      tmp.next = new_node;
    }
  }

  public void printList() {
    Node<T> tmp = head;
    while (tmp != null) {
      System.out.println(tmp.datum);
      tmp = tmp.next;
    }
  }

  private class Node<T> {
    Node<T> next;
    T datum;

    public Node(T datum) {
      this.datum = datum;
      next = null;
    }
  }

  public static void main(String[] args) {
    LinkedList<Integer> my_list = new LinkedList<Integer>();
    my_list.append(5);
    my_list.append(10);
    my_list.append(1);
    my_list.printList();
  }
}
