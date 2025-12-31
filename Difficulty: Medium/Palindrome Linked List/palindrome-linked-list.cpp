/*
class Node {
  public:
    int data;
    Node *next;

    Node(int x) {
       data = x;
       next = NULL;
    }
};
*/

class Solution {
  public:
  //Jay
     bool isPalindrome(Node *head) {
        if (!head || !head->next) return true;

        Node *slow = head, *fast = head;
        while (fast->next && fast->next->next) {
            slow = slow->next;
            fast = fast->next->next;
        }

        Node *prev = NULL, *curr = slow->next;
        while (curr) {
            Node *nextNode = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nextNode;
        }

        Node *first = head;
        Node *second = prev;
        while (second) {
            if (first->data != second->data) return false;
            first = first->next;
            second = second->next;
        }

        return true;
    }
};