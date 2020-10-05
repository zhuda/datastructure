//
//  main.cpp
//  datastructure - single list for LRU
//
//  Created by DannyZhu on 2020/10/5.
//

#include <iostream>
#include <memory>

struct Node
{
    Node* next = 0;
    size_t value = 0;
};

Node* CreateSingleList()
{
    Node* head = new Node {nullptr, 0};
    Node* current = head;
    for (size_t i = 1; i < 5; i ++) {
        Node* tmp = new Node{nullptr, i};
        current->next = tmp;
        current = tmp;
    }
    
    current->next = nullptr;
    return head;
}

void DeleteSingleList(Node* head)
{
    Node* current = head;
    while (current != nullptr) {
        Node* tmp = current;
        current = current->next;
        delete tmp;
    }
}

// Least recent usage strategy, the list head is most recent used, the tail is most least used.
// If finds in the list, move it to head
// If not find in the list
// 1. If the list is not full, add to tail.
// 2. If the list is full, remove the tail and add to tail.
Node* LRU(Node*head, size_t value)
{
    Node* current = head;
    Node* previous = head;
    while (current != nullptr)
    {
        if (current->value == value)
        {
            if (current == head)
            {
                return current;
            }
            else
            {
                previous->next = current->next;
                current->next = head;
                return current;
            }
        }
        previous = current;
        current = current->next;
    }
    
    // we suppose the node is full.
    previous->value = value;
    
    return head;
}

int main(int argc, const char * argv[]) {
    
    Node* head = CreateSingleList();
    
    head = LRU(head, 0);
    
    head = LRU(head, 3);
    
    head = LRU(head, 5);
    
    head = LRU(head, 6);
    
    
    DeleteSingleList(head);
    
    std::cout << "Hello, World!\n";
    return 0;
}
