#include<bits/stdc++.h>
using namespace std;
class Node {
public:
    int val;
    Node* next;
    Node() {
        val = 0;
        next = nullptr;
    }
    Node(int x) {
        val = x;
        next = nullptr;
    }
    Node(int x, Node *ptr) {
        val = x;
        next = ptr;
    }
};

class List{
private:
    Node *head, *tail;
public:
    
    List() {
        head = nullptr;
        tail = nullptr;
    }
    void push_back(int x) {                                 // O(1)
        if(head == nullptr) {
            Node *newNode = new Node(x);
            head = newNode;
            tail = newNode;
            return;
        }
        tail->next = new Node(x);
        tail = tail->next;
    }
    void push_front(int x) {                                // O(1)
        Node *newNode = new Node(x, head);
        head = newNode;
        if(tail == nullptr) tail = newNode;
    }
    void insert(int pos, int val) {                         // O(n)
        if(pos < 0 || !head) {
            cout << "Invalid Position\n";
            return;
        }
        Node *temp = head;
        for(int i = 0; i < pos - 1; i++) {
            if(temp->next == nullptr) {
                cout << "Invalid Position\n";
                return;
            }
            temp = temp->next;
        }
        temp->next = new Node(val, temp->next);
        if(temp == tail) tail = temp->next;
    }
    void pop_back() {                                       // O(n)        
        if(tail == nullptr) {
            cout << "Invalid Operation\n";
            return;
        }

        if(head == tail) {
            free(head);
            head = tail = nullptr;
            return;
        }
        Node *temp = head;
        while(temp->next != tail) {
            temp = temp->next;
        }
        temp->next = nullptr;
        free(tail);
        tail = temp;
    }
    void pop_front() {                                      // O(1)
        if(head == nullptr) {
            cout << "Invalid Operation\n";
            return;
        }
        if(head == tail) {
            free(head);
            head = tail = nullptr;
            return;
        }
        Node *temp = head;
        head = head->next;
        free(temp);
    }
    void print() {                                          // O(n)
        Node *temp = head;
        while(temp) {
            cout << temp->val << ' ';
            temp = temp->next;
        }
        cout << '\n';
    }
    int find(int x) {                                      // O(n)      
        int pos = -1;
        Node *temp = head;
        while(temp) {
            pos++;
            if(temp->val == x) return pos;
            temp = temp->next;
        }
        return -1;
    }
};

int main() {
    List arr = List();
    arr.push_back(23);
    arr.push_back(121);
    arr.push_front(1);
    arr.print();
    cout << arr.find(23) << '\n';
    arr.insert(1, 234);
    arr.print();
    cout << arr.find(23) << '\n';
    arr.pop_back();
    arr.pop_back();
    arr.pop_back();
    arr.pop_front();
    arr.pop_front();
    arr.pop_back();
}