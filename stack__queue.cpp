#include <iostream>
using namespace std;

struct Node
{
    int val;
    Node* next;
};

class Stack
{
    Node* head = NULL;
public:

    bool isEmpty()
    {
        return head == NULL;
    }

    void push(int _val)
    {
        Node* temp = new Node;
        temp->val = _val;
        temp->next = head;
        head = temp;
    }

    int pop()
    {
        if (head != NULL)
        {
            Node* temp = head;
            head = head->next;
            int i = temp->val;
            delete temp;
            return i;
        }
        return NULL;
    }

    int top()
    {
        if (!isEmpty())
        {
            return head->val;
        }
    }

    void show()
    {

        for (Node* temp = head; temp != NULL; temp = temp->next)
        {
            cout << temp->val << endl;
        }
    }
};

class Queue
{
    Node* tail = NULL;
    Node* head = NULL;
public:
    bool isEmpty()
    {
        return head == NULL;
    }

    void enqueue(int _val)
    {
        Node* temp = new Node;
        temp->val = _val;
        temp->next = NULL;

        if (head == NULL)
        {
            head = temp;
            tail = temp;
        }
        else
        {
            tail->next = temp;
            tail = temp;
        }

    }

    int dequeue()
    {
        if (!isEmpty())
        {
            int val = head->val;
            Node* temp = head;
            head = head->next;
            delete temp;
            return val;
        }
        return NULL;
    }

    int frontValue()
    {
        if (!isEmpty())
        {
            return head->val;
        }
        return NULL;
    }

    void show()
    {
        for (Node* temp = head; temp != NULL; temp = temp->next)
        {
            cout << temp->val << endl;
        }
    }



};


int main()
{
    cout << "========STOS==========" << endl;

    Stack* firstStack = new Stack;
    firstStack->push(10);
    firstStack->push(3);
    firstStack->push(2);
    firstStack->show();
    int temp = firstStack->pop();
    cout << temp << endl;

    cout << "========KOlEJKA==========" << endl;

    Queue* firstQueue = new Queue;
    firstQueue->enqueue(2);
    firstQueue->enqueue(9);
    firstQueue->enqueue(7);
    firstQueue->enqueue(5);
    firstQueue->show();
    cout << "Dequeue";
    cout << firstQueue->dequeue();
    cout << firstQueue->frontValue();

    return 0;
}