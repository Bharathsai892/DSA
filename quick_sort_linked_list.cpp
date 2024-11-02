#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node* next;

    Node(int val) : data(val), next(nullptr) {}
};


class LinkedList {
private:
    Node* head;

public:
    
    LinkedList() : head(nullptr) {}

    void append(int data) {
        Node* newNode = new Node(data);

        if (head == nullptr) {
            head = newNode; 
            return;
        }

        Node* temp = head;
        while (temp->next != nullptr) {
            temp = temp->next;
        }
        temp->next = newNode;
    }

    Node* getHead() {
        return head;
    }
};
Node*gettail(Node*cur)
{
    while(cur!=nullptr && cur->next!=nullptr)
    {
        cur=cur->next;
    }
    return cur;
}
Node*partition(Node*head,Node*end)
{
    Node*pivot=head;
    Node*prev=head;
    Node*cur=head->next;
    while(cur!=end->next)
    {
        if(pivot->data>cur->data)
        {
            swap(prev->next->data,cur->data);
            prev=prev->next;
        }
        cur=cur->next;
    }
    swap(pivot->data,prev->data);
    return prev;
}
Node*quickrec(Node*head,Node*end)
{
    if(!head || head==end)
    {
        return head;
    }
    Node*pivot=partition(head,end);
    Node*newhead=head;
    Node*newend=end;
    if(newhead->next!=pivot)
    {
        Node*temp=newhead;
        while(temp->next!=pivot)
        {
            temp=temp->next;
        }
        temp->next=nullptr;
        newhead=quickrec(head,temp);
        temp=gettail(newhead);
        temp->next=pivot;
    }
    pivot->next=quickrec(pivot->next,newend);
    return newhead;

}

Node*quicksort(Node*head)
{
    return quickrec(head,gettail(head));
}

void display(Node*head)
{
    Node* temp = head;
        while (temp != nullptr) {
            cout << temp->data << " -> ";
            temp = temp->next;
        }
        cout << "nullptr" << endl;
}

int main() {
    LinkedList list;
    
    list.append(11);
    list.append(7);
    list.append(4);
    list.append(6);
    
    Node* head = list.getHead();
    head=quicksort(head);
    display(head);
    return 0;
}
