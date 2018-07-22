#include <iostream>
using namespace std;

struct NODE {
    int data;
    NODE* pLeft;
    NODE* pRight;
};

NODE* createNode(int i) {
    NODE* p = new NODE();
    p->data = i;
    p->pLeft = p->pRight = NULL;
    return p;
};

NODE* findInsert(NODE* root, int i) {
    if (root == NULL) 
        return NULL;
    NODE* p = root;
    NODE* f = p;
    while (p != NULL) {
        f = p;
        if (i < p->data) {
            p = p->pLeft;
        } else if (i > p->data){
            p = p->pRight;
        }
        else return NULL;
    }
    return f;
};

NODE* searchNode(NODE* root, int i) {
    if (root == NULL) 
        return NULL;
    if (i == root->data) 
        return root;
    if (i < root->data) 
        searchNode(root->pLeft, i);
    else 
        searchNode(root->pRight, i);
}

NODE* getMAX(NODE* root) {
    if (root->pRight == NULL)
        return root;
    else 
        getMAX(root->pRight);
}

NODE* getMIN(NODE* root) {
    if (root->pLeft == NULL) 
        return root;
    else 
        getMIN(root->pLeft);
}

void insertNode(NODE* &root, int i) {
    NODE* n = createNode(i);
    if (root == NULL) {
        root = n;
        return;
    }
    NODE* f = findInsert(root, i);
    if (f != NULL) {
        if (i < f->data) 
            f->pLeft = n;
        else if (i > f->data) 
            f->pRight = n;
    }
};

// Chưa hoàn thành delete 
void deleteNode(NODE* &root, int i) {
    if (root == NULL) 
        return;
    NODE* n = searchNode(root, i);
    if (n != NULL) {
        if (n->pLeft == NULL && n->pRight == NULL) {
            delete n;
        }
        else {
            NODE* x = n;
            if (n->pLeft == NULL)
                n = n->pRight;
            if (n->pRight == NULL)
                n = n->pLeft;
            delete x;
        }
    }
};

template <int l>
void createTree(NODE* &root, int (&a)[l]) {
    if (root != NULL) 
        return;
    for (int i = 0; i < l; i++)
        insertNode(root, a[i]);
};

void NLR(NODE* root) {
    if (root != NULL) {
        cout << root->data << " ";
        NLR(root->pLeft);
        NLR(root->pRight);
    }
}
void NRL(NODE* root) {
    if (root != NULL) {
        cout << root->data << " ";
        NRL(root->pRight);
        NRL(root->pLeft);
    }
}

