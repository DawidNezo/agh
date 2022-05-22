#include <iostream>
using namespace std;

struct Node
{
    int val;
    int priority;
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
        return 0;
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
        cout << endl;
        for (Node* temp = head; temp != NULL; temp = temp->next)
        {
            cout << temp->val;
        }
        cout << endl;
    }
};

class Queue
{
    Node* head = NULL;
public:
    bool isEmpty()
    {
        return head == NULL;
    }

    void enqueue(int _val, int _priority)
    {
        Node* temp = new Node;
        temp->val = _val;
        temp->priority = _priority;
        temp->next = NULL;

        if (head == NULL)
        {
            head = temp;
        }
        else if(head->next == NULL)
        {
            if(head->priority >= temp->priority)
            {
                temp->next = head;
                head = temp;
            }
            else {
                head->next = temp;
            }
        }
        else
        {
            Node* i = head;
            
            while(i->next && i->next->priority <= temp->priority) {
                i = i->next;
            }
            
            temp->next = i->next;
            i->next = temp;
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
        return 0;
    }

    int frontValue()
    {
        if (!isEmpty())
        {
            return head->val;
        }
        return 0;
    }

    void show()
    {
        cout << endl;
        for (Node* temp = head; temp != NULL; temp = temp->next)
        {
            cout << temp->val << "[" << temp->priority << "]->";
        }
        cout << endl;
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
    cout << "Pop:" << endl << temp << endl;

    cout << "========KOlEJKA==========" << endl;

    Queue* firstQueue = new Queue;
    firstQueue->enqueue(1, 9);
    firstQueue->enqueue(2, 1);
    firstQueue->enqueue(3, 8);
    firstQueue->enqueue(4, 2);
    firstQueue->enqueue(5, 7);
    firstQueue->enqueue(6, 3);
    firstQueue->show();
    cout << "Dequeue:" << endl << firstQueue->dequeue() << endl;
    cout << "Front:" << endl << firstQueue->frontValue() << endl;

    return 0;
}