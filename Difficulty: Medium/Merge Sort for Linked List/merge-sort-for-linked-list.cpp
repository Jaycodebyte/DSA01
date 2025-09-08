/*
class Node {
public:
    int data;
    Node* next;

    Node(int x){
        data = x;
        next = NULL;
    }
};
*/
class Solution {
  public:
    Node* merge(Node* left, Node* right) {
        if (!left) return right;
        if (!right) return left;

        Node* result = nullptr;
        if (left->data <= right->data) {
            result = left;
            result->next = merge(left->next, right);
        } else {
            result = right;
            result->next = merge(left, right->next);
        }
        return result;
    }

    Node* getMiddle(Node* head) {
        if (!head || !head->next) return head;

        Node* slow = head;
        Node* fast = head->next;
        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }

    Node* mergeSort(Node* head) {
        if (!head || !head->next) return head;

        Node* mid = getMiddle(head);
        Node* midNext = mid->next;
        mid->next = nullptr;

        Node* left = mergeSort(head);
        Node* right = mergeSort(midNext);

        return merge(left, right);
    }
};