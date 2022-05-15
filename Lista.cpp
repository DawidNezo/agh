#include <iostream>

using namespace std;

struct Node
{
    int data;
    Node* next;
};

class List {
public:
    Node* head = NULL;

    void addFront(int d)
    {
        Node* h = new Node;
        h->data = d;

        h->next = head;
        head = h;
    }

    void addBack(int d)
    {
        Node* h = new Node;
        h->data = d;
        h->next = NULL;

        if (!head)
        {
            head = h;
        }
        
        Node* pom = head;
        while (pom->next)
        {
            pom = pom->next;
        }

        pom->next = h;
    }

    void display()
    {
        Node* pom = head;
        cout << endl;
        while (pom != NULL)
        {
            cout << "->" << pom->data;
            pom = pom->next;
        }
        cout << endl;
    }

    Node* find(int target)
    {
        Node* pom = head;
        while (pom && pom->data != target)
        {
            pom = pom->next;
        }

        return pom;
    }

    void addAfter(int d, int position)
    {
        Node* h = new Node;
        h->data = d;
        h->next = NULL;

        if (!head)
        {
            head = h;
        }

        Node* pom = head;
        int i = 0;
        while (pom->next && i <= position)
        {
            pom = pom->next;
            i++;
        }

        if (i >= position)
        {
            h->next = pom->next;
            pom->next = h;
        }
    }

    void deleteFront()
    {
        if (head)
        {
            Node* pom = head;
            head = pom->next;
            delete pom;
        }
    }

    void deleteBack()
    {
        Node* pom = head;
        if (pom == NULL) {
            return;
        }
        if (pom->next == NULL)
        {
            delete pom;
            return;
        }
        while (pom->next->next)
        {
            pom = pom->next;
        }
        delete pom->next;
        pom->next = NULL;
    }

    void deleteVal(int target)
    {
        Node* pom = head;

        if (!pom->next) {
            if (pom->data == target) {
                delete pom;
            }
            return;
        }

        while (pom->next && pom->next->data != target)
        {
            pom = pom->next;
        }
        
        if (pom->next) {
            Node* toDelete = pom->next;
            pom->next = pom->next->next;
            delete toDelete;
        }
        return;
    }
};

void cutList(List*& list_1, List*& list_2)
{
    Node* slow = list_1->head;
    Node* fast = list_1->head->next;

    if (slow->next == NULL) {
        slow = NULL;
        return;
    }

    if (fast->next->next == NULL) {
        fast = fast->next;
        return;
    }

    while (fast && fast->next)
    {
        slow = slow->next;
        fast = fast->next->next;
    }

    Node* pom = slow;
    list_2->head = pom->next;
    slow->next = NULL;
}

int main()
{
    List* list = new List;
    list->addFront(1);
    list->addFront(2);
    list->addFront(3);
    list->addFront(4);
    list->addBack(6);
    list->addBack(7);
    list->addBack(8);
    list->addBack(9);

    list->display();

    Node* existingNode = list->find(4);
    if (existingNode)
    {
        cout << endl << "znaleziono";
    }
    else {
        cout << endl << "nie znaleziono";
    }

    Node* missingNode = list->find(10);
    if (missingNode)
    {
        cout << endl << "znaleziono";
    }
    else {
        cout << endl << "nie znaleziono";
    }

    list->addAfter(20, 3);
    list->addAfter(20, 20);

    list->display();

    list->deleteFront();
    list->deleteBack();

    list->display();

    list->deleteVal(20);

    list->display();

    cout << "cut";

    List* secondList = new List;
    cutList(list, secondList);

    list->display();
    secondList->display();

    return 0;
}