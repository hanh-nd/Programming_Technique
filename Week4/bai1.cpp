#include <iostream> 
using namespace std;
struct Node { 
    int data; 
    Node* next;

    Node(int data) {
        this->data = data;
        next = NULL;
    }
};

// push a new element to the beginning of the list
Node* prepend(Node* head, int data) {
    Node* q = new Node(data);
    if (head == NULL) {
    	return q;
	} 
    q->next = head;
    head = q;
    return head;
}

// print the list content on a line
void print(Node* head) {
    if (head == NULL) {
    	return;
	}
	Node* p = head;
	while(p != NULL) {
		cout << p -> data << " ";
		p = p -> next;
	}
}

// return the new head of the reversed list
Node* reverse(Node* head) {
    if (head == NULL) {
    	return NULL;
	}
	
	Node* current = head;
	Node* prev = NULL;
	Node* next = NULL;
	
	while (current != NULL) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
	}
	head = prev;
	return head;
}
  
int main() {
	cout << "Ngo Dang Hanh" << endl;
    int n, u;
    cin >> n;
    Node* head = NULL;
    for (int i = 0; i < n; ++i){
        cin >> u;
        head = prepend(head, u);
    } 
    cout << "Original list: ";
    print(head);
    head = reverse(head);
    cout << "\nReversed list: ";
    print(head);
    return 0; 
}