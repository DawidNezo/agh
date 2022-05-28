#include <iostream>

using namespace std;

struct Node {
    int index;
    string info;
    int tab[4];

    Node* left;
    Node* right;
    Node* parent;
};

class BST {
    Node* root = NULL;

    Node* insertBST(Node* _node, Node* _parent, int _index, string _info, int _tab[]) {
        if (_node == NULL) {
            _node = new Node;
            _node->index = _index;
            _node->info = _info;
            for (int i = 0; i < 4; i++) {
                _node->tab[i] = _tab[i];
            }
            _node->right = _node->left = NULL;
            _node->parent = _parent;

            if (root == NULL) {
                root = _node;
            }

            return _node;
        }
        else {
            Node* temp = new Node;
            if (_index <= _node->index) {
                temp = insertBST(_node->left, _node, _index, _info, _tab);
                if (temp != NULL) {
                    _node->left = temp;
                }
            }
            else {
                temp = insertBST(_node->right, _node, _index, _info, _tab);
                if (temp != NULL) {
                    _node->right = temp;
                }
            }
            return NULL;
        }
    }

    void inOrderBST(Node* _parent) {
        if (_parent != NULL) {
            inOrderBST(_parent->left);
            cout << _parent->info << "(" << _parent->index << ") ";
            for (int i = 0; i < 4; i++) {
                cout << ";" << _parent->tab[i];
            }
            cout << endl;
            inOrderBST(_parent->right);
        }
    }

    void wyrzucanieStudentowBST(Node* _parent) {
        if (_parent != NULL) {
            if (_parent->left != NULL) {
                wyrzucanieStudentowBST(_parent->left);
            }
            int sum = 0;
            for (int i = 0; i < 4; i++) {
                if (_parent->tab[i] == 2) {
                    sum++;
                }
            }
            if (sum >= 2) {
                deleteNode(_parent);
                return;
            }
            if (_parent != NULL && _parent->right != NULL) {
                wyrzucanieStudentowBST(_parent->right);
            }
        }
    }

    void deleteNodeBST(Node* _node, int _index)
    {
        if (_node != NULL)
        {
            if (_node->index != _index) {
                if (_index <= _node->index) {
                    deleteNodeBST(_node->left, _index);
                }
                else {
                    deleteNodeBST(_node->right, _index);
                }
            }
            else {
                deleteNode(_node);
            }
        }
    }

    void deleteNode(Node* _node) {
        if (_node != NULL)
        {
            if (_node->left == NULL && _node->right == NULL)
            {
                if (_node->parent != NULL)
                {
                    if (_node->parent->left == _node) {
                        _node->parent->left = NULL;
                    }
                    else {
                        _node->parent->right = NULL;
                    }
                }
                delete _node;
            }
            else if (_node->left != NULL) {
                _node->parent->left = _node->left;
                delete _node;
            }
            else if (_node->right != NULL) {
                _node->parent->right = _node->right;
                delete _node;
            }
            else
            {
                Node* temp = minValueNode(_node->right);

                _node->index = temp->index;
                _node->info = temp->info;
                for (int i = 0; i < 4; i++) {
                    _node->tab[i] = temp->tab[i];
                }
                _node->right = temp->right;

                delete temp;
            }
        }
    }

    Node* minValueNode(Node* _node)
    {
        Node* current = _node;

        while (current && current->left != NULL)
            current = current->left;

        return current;
    }
public:

    void insert(int _index, string _info, int _tab[]) {
        insertBST(root, NULL, _index, _info, _tab);
    }

    bool isNotEmpty() {
        return root != NULL;
    }

    void inOrder() {
        if (isNotEmpty()) {
            inOrderBST(root);
        }
    }

    void deleteByIndex(int _index) {
        if (isNotEmpty()) {
            deleteNodeBST(root, _index);
        }
    }

    void wyrzucanieStudentow() {
        if (isNotEmpty()) {
            wyrzucanieStudentowBST(root);
        }
    }
};

int losuj() {
    int max = 5;
    int min = 2;
    int range = max - min + 1;
    int num = rand() % range + min;
    return num;
}

int main()
{
    srand(time(NULL));
    BST* tree = new BST;

    int tab[4] = {};
    for (int i = 0; i < 4; i++) {
        tab[i] = losuj();
    }
    tree->insert(500, "Dawid", tab);
    for (int i = 0; i < 4; i++) {
        tab[i] = losuj();
    }
    tree->insert(490, "Bartek", tab);
    for (int i = 0; i < 4; i++) {
        tab[i] = losuj();
    }
    tree->insert(380, "Marek", tab);
    for (int i = 0; i < 4; i++) {
        tab[i] = losuj();
    }
    tree->insert(530, "Tomek", tab);
    for (int i = 0; i < 4; i++) {
        tab[i] = 2;
    }
    tree->insert(600, "Darek", tab);
    for (int i = 0; i < 4; i++) {
        tab[i] = losuj();
    }
    tree->insert(900, "Zbysiu", tab);

    tree->inOrder();

    cout << "Delete: " << endl;
    //tree->deleteByIndex(900);
    tree->inOrder();

    cout << "Delete: " << endl;
    //tree->deleteByIndex(490);
    tree->inOrder();

    cout << "Koniec semestru: " << endl;
    tree->wyrzucanieStudentow();
    tree->inOrder();
}
