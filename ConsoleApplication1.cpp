#include <iostream>
using namespace std;

struct Node
{
    int val;
    Node* next;
};

class Stos
{
    Node* H = NULL;
public:

    bool isEmpty()
    {
        return H == NULL;
    }

    void Push(int _val)
    {
        Node* temp = new Node;
        temp->val = _val;
        temp->next = H;
        H = temp;
    }

    int Pop()
    {
        if (H != NULL)
        {
            Node* temp = H;
            H = H->next;
            int i = temp->val;
            delete temp;
            return i;
        }
    }

    int Top()
    {
        if (!isEmpty())
        {
            return H->val;
        }
    }
    
    void wyswietl()
    {
        
        for (Node* temp = H; temp != NULL; temp = temp->next)
        {
            cout << temp->val << endl;
        }
    }
};

class Kolejka
{
    Node* O = NULL;
    Node* P = NULL;
public:
    bool isEmpty()
    {
        return P == NULL;
    }

    void Enqueue(int _val)
    {
        Node* temp = new Node;
        temp->val = _val;
        temp->next = NULL;

        if (P == NULL)
        {
            P = temp;
            O = temp;
        }
        else
        {
            O->next = temp;
            O = temp;
        }
        
    }
    
    int Dequeue()
    {
        int temp = P->val;

        delete ;
        return 



    }

    void wyswietl()
    {
        cout << endl << "kolejka: " << endl;
        for (Node* temp = P; temp != NULL; temp = temp->next)
        {
            cout << temp->val << endl;
        }
    }



};


int main()
{
    Stos* pierwszystos = new Stos;
    pierwszystos->Push(10);
    pierwszystos->wyswietl();
    pierwszystos->Push(3);
    pierwszystos->wyswietl();
    pierwszystos->Push(2);
    pierwszystos->wyswietl();
    int temp = pierwszystos->Pop();
    cout << temp << endl;

    cout << "========KOlEJKA==========" << endl;
    
    Kolejka* pierwszakolejka = new Kolejka;
    pierwszakolejka->Enqueue(2);
    pierwszakolejka->Enqueue(9);
    pierwszakolejka->Enqueue(7);
    pierwszakolejka->Enqueue(5);
    pierwszakolejka->wyswietl();

        return 0;
}