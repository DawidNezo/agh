

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
    //8531
    void AddMid(int _val, int _val2)
    {
        Node* i = Head;
        Node* temp = new Node;
        temp->val = _val2;
        

        while (i != NULL && i->val != _val)
        {
            i = i->next;
        }
        if (i != NULL) {
            // wartosc i = 5
            // i wskazuje na 3
            // temp nie wskazuje na nic
            // temp ma wartosc 4
            temp->next = i->next;
            // temp wskazuje na 3
            i->next = temp;
            // 5 wskazuje na 4 a 4 wskazuje na 3
            // dodalismy 4 pomiedzy 5 a 3
        }
    }

    void sort(int _val)
    {
        if (Head == NULL)
        {
            AddFront(_val);
        }
        else {
            
            if (_val < Head->val)
            {
                Node* temp = new Node;
                temp->val = _val;
                temp->next = Head;
                Head = temp;
            }
            else
            {
                Node* temp = Head;

                while (temp->next != NULL && _val > temp->next->val)
                {
                    temp = temp->next;
                }
                
                Node* temp2 = new Node;
                temp2->val = _val;
                temp2->next = temp->next;
                temp->next = temp2;
            }

        }
    }

    void sort2(int _val)
    {
        if (Head == NULL)
        {
            AddFront(_val);
        }
        else {
            Node* prev = NULL;
            Node* temp = Head;
            while(temp->val < _val)
            {
                prev = temp;
                temp = temp->next;

                if (temp->next->val < _val)
                    break;
            }
                

            Node* toInsert = new Node();
            toInsert->val = _val;
            toInsert->next = temp;
            if(prev != NULL)
                prev->next = toInsert;
            else
                toInsert = Head;
        }
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
    cout << endl;
    pierwszy->AddMid(3,4);

    lista* druga = new lista;

    druga->AddFront(8);
    druga->AddFront(7);
    druga->AddFront(5);
    druga->AddFront(4);
    druga->AddFront(3);

    druga->sort(6);
    cout << "druga:" << endl;
    druga->wyswietl();
    cout << endl;
    pierwszy->wyswietl();
    cout << endl;
    pierwszy->sort(6);
    pierwszy->wyswietl();
    cout << "P_:" << endl;
    druga->sort2(6);
    cout << "druga:" << endl;
    druga->wyswietl();
    cout << endl;
    pierwszy->wyswietl();
    cout << endl;
    pierwszy->sort2(6);
    pierwszy->wyswietl();


    return 0;
}

