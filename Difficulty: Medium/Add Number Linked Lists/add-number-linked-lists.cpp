/*
class Node {
  public:
    int data;
    Node* next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};
*/

class Solution {
  public:
  //Jay
    Node* reverse(Node* head) {
        Node* prev = NULL;
        Node* curr = head;
        while (curr) {
            Node* nxt = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nxt;
        }
        return prev;
    }

    Node* addTwoLists(Node* head1, Node* head2) {

        head1 = reverse(head1);
        head2 = reverse(head2);

        int carry = 0;
        Node* dummy = new Node(-1);
        Node* temp = dummy;

        while (head1 || head2 || carry) {

            int sum = carry;

            if (head1) { sum += head1->data; head1 = head1->next; }
            if (head2) { sum += head2->data; head2 = head2->next; }

            temp->next = new Node(sum % 10);
            carry = sum / 10;
            temp = temp->next;
        }

        Node* result = reverse(dummy->next);

        while (result && result->data == 0) result = result->next;

        return result ? result : new Node(0);
    }
};