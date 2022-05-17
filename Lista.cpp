

#include <iostream>
using namespace std;

struct Node
{
    int val;
    Node* next;
};

class lista {

public:
    Node* Head = NULL;

    bool isEmpty()
    {
        return Head == NULL;
    }
    //8531
    void AddFront(int _val)
    {
        Node* nowy = new Node;
        nowy->val = _val;
        nowy->next = Head;
        Head = nowy;
    }

    void wyswietl()
    {
        for (Node* i = Head; i != NULL; i = i->next)
            {
                cout << i->val;
            }
    }
    //1358
    void AddBack(int _val)
    {
        Node* nowy = new Node;
        nowy->val = _val;
        nowy->next = NULL;

        if (isEmpty())
        {
            Head = nowy;
        }

        Node* temp = Head;
        while (temp->next != NULL)
        {
            temp = temp->next;
            
        }

        temp->next = nowy;

    }
    //85317 --> 5317
    void DeleteFront()
    {
        if (!isEmpty())
        {

            Node* temp = Head;
            Head = temp->next;
            delete temp;
        }
        
    }
   // -->
    //85317 --> 8531
    void DeleteBack()
    {
        if (!isEmpty())
        {
            Node* temp = Head;

            if (temp->next == NULL)
            {
                delete temp;
                return;
            }

            while (temp->next->next != NULL) //1
            {
                temp = temp->next; // 7
            }
            delete temp->next;
            temp->next = NULL;
              
        }
    }

    int Wyszukiwanie(int _val)
    {
        Node* temp = Head;

        while (temp != NULL && temp->val != _val)
        {
            temp = temp->next;
        }
        if(temp != NULL)
        return temp->val;

        return 0;
    }
};

int main()
{
    lista* pierwszy = new lista;

    if (pierwszy->isEmpty())
    {
        cout << "Pusta" << endl;
    }

    pierwszy->AddFront(1);
    pierwszy->AddFront(3);
    pierwszy->AddFront(5);
    pierwszy->AddFront(8);
    pierwszy->AddBack(7);
    pierwszy->wyswietl();
    cout << endl;
    pierwszy->DeleteFront();
    pierwszy->wyswietl();
    pierwszy->DeleteBack();
    cout << endl;
    pierwszy-> wyswietl();
    cout << endl;
    cout << pierwszy->Wyszukiwanie(3);
    return 0;
}

