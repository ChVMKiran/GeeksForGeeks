class Solution {
public:
    Node* reverse(Node* head) {
        Node* curr = head;
        Node* pre = nullptr;
        Node* next = nullptr;

        while (curr != nullptr) {
            next = curr->next;
            curr->next = pre;

            pre = curr;
            curr = next;
        }
        return pre;
    }

    void reorderList(Node* &head) {
        if (head == nullptr || head->next == nullptr || head->next->next == nullptr) return;

        Node* slow = head;
        Node* fast = head;
        while (fast->next != nullptr && fast->next->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;
        }

        Node* next = slow->next;
        slow->next = nullptr;
        next = reverse(next);

        Node* dummy = new Node(1);
        Node* curr = dummy;
        Node* temp = head;
        while (temp != nullptr || next != nullptr) {
            if (temp != nullptr) {
                curr->next = temp;
                curr = temp;
                temp = temp->next;
            }
            if (next != nullptr) {
                curr->next = next;
                curr = next;
                next = next->next;
            }
        }
        head = dummy->next;
    }
};