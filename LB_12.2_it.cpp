#include <iostream>

struct Node {
    int data;
    Node* next;
};

Node* createNode(int data) {
    Node* newNode = new Node();
    if (!newNode) {
        std::cout << "Memory error\n";
        return nullptr;
    }
    newNode->data = data;
    newNode->next = nullptr;
    return newNode;
}

Node* insertNode(Node* head, int data) {
    if (head == nullptr) {
        head = createNode(data);
    }
    else {
        Node* temp = head;
        while (temp->next != nullptr) {
            temp = temp->next;
        }
        temp->next = createNode(data);
    }
    return head;
}

void printList(Node* head) {
    Node* temp = head;
    while (temp != nullptr) {
        std::cout << temp->data << " ";
        temp = temp->next;
    }
    std::cout << "\n";
}

int sumPositiveValues(Node* head) {
    int sum = 0;
    Node* temp = head;
    while (temp != nullptr) {
        if (temp->data > 0) {
            sum += temp->data;
        }
        temp = temp->next;
    }
    return sum;
}

int main() {
    Node* head = nullptr;
    head = insertNode(head, 1);
    head = insertNode(head, -2);
    head = insertNode(head, 3);
    head = insertNode(head, 4);
    head = insertNode(head, -5);

    std::cout << "List: ";
    printList(head);

    int sum = sumPositiveValues(head);
    std::cout << "Sum Positive Values: " << sum << "\n";

    return 0;
}
