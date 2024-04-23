#include <iostream>
#include <string>

using namespace std;

class ChainLink {
private:
    string color;

public:
    ChainLink(string color) {
        this->color = color;
    }

    string get_color() {
        return this->color;
    }
};

class Node {
public:
    ChainLink* data_ptr;
    Node* next_node_ptr;

    Node(ChainLink* data, Node* next_node = nullptr) {
        data_ptr = data;
        next_node_ptr = next_node;
    }

    ChainLink data() {
        return *data_ptr;
    }

    Node* next() {
        return next_node_ptr;
    }
};

class LinkedList {
private:
    Node* head;

public:
    LinkedList() {
        head = nullptr;
    }

    void append(ChainLink* new_link) {
        if (head == nullptr) {
            head = new Node(new_link);
        } else {
            Node* current = head;
            while (current->next() != nullptr) {
                current = current->next();
            }
            current->next_node_ptr = new Node(new_link);
        }
    }

    ChainLink getLinkAtIndex(int index) {
        Node* current = head;
        int count = 0;
        while (current != nullptr) {
            if (count == index) {
                return current->data();
            }
            current = current->next();
            count++;
        }
        //return an empty chainlink if index is out of bounds
        return ChainLink("");
    }
};

int main() {
    LinkedList linkedList;

    ChainLink link_one = ChainLink("red");
    linkedList.append(&link_one);

    ChainLink link_two = ChainLink("blue");
    linkedList.append(&link_two);

    ChainLink link_three = ChainLink("green");
    linkedList.append(&link_three);

    //return second chainlink 
    ChainLink retrieved_link = linkedList.getLinkAtIndex(1);
    cout << "Color of the second ChainLink: " << retrieved_link.get_color() << endl;

    // returns third chainlink
    ChainLink another_retrieved_link = linkedList.getLinkAtIndex(2);
    cout << "Color of the third ChainLink: " << another_retrieved_link.get_color() << endl;

    return 0;
}
