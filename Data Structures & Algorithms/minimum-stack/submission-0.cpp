class MinStack {
public:
    class Node {
    public:
        int val;
        int min_val;
        Node* prev = nullptr;

        Node() {}
        Node(int val, int min_val) : val(val), min_val(min_val) {}
    };

    Node* node = nullptr;

    MinStack() {
        
    }
    
    void push(int val) {
        if (node == nullptr) {
            node = new Node(val, val);
        } else {
            Node* next = new Node(val, min(node->min_val, val));
            next->prev = node;
            node = next;
        }
    }
    
    void pop() {
        Node* to_remove = node;
        node = node->prev;

        delete to_remove;
    }
    
    int top() {
        return node->val;
    }
    
    int getMin() {
        return node->min_val;
    }
};
