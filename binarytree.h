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
    p->pLeft = NULL;
    p->pRight = NULL;
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

    NODE* p = root;
    NODE* f = p;
    while(p->data != i) {
        if (i < p->data)
            p = p->pLeft;
        else 
            p = p->pRight;
        f = p;
    }
    return f;
};
NODE* searchParent(NODE* root, int i) {
    if (root == NULL)
        return NULL;
    NODE* p = root;
    NODE* f = p;
    while(p->data != i) {
        f = p;
        if (i < p->data)
            p = p->pLeft;
        else 
            p = p->pRight;
    }
    return f;
};

NODE* getMAX(NODE* root) {
    if (root == NULL) 
        return NULL;
    else {
        NODE* m = root;
        NODE* f = m;
        while(m->pRight != NULL) {
            m = m->pRight;
            f = m;
        }
        return f;
    }
};

NODE* getMIN(NODE* root) {
    if (root == NULL) 
        return NULL;
    else {
        NODE* m = root;
        NODE* f = m;
        while(m->pLeft != NULL) {
            m = m->pLeft;
            f = m;
        }
        return f;
    }
};

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
        if (i > f->data) 
            f->pRight = n;
    }
};

// Chưa hoàn thành delete 
void deleteNode(NODE* &root, int i) {
    if (root == NULL) 
        return;

    NODE* nodeDelete = searchNode(root, i);
    NODE* parent_nodeDelete = searchParent(root, i);
    // Ở đây ta có:
    //  + Node "parent_nodeDelete" là node cha của "nodeDelete"
    //  + So sách giá trị của hai node cha con để tìm vị trí của node cha với node con


    if (nodeDelete != NULL) {
        // Node lá
        if (nodeDelete->pLeft == NULL && nodeDelete->pRight == NULL) { 

            if (parent_nodeDelete->data > nodeDelete->data)
                parent_nodeDelete->pLeft = NULL;
            else if (parent_nodeDelete->data < nodeDelete->data)
                parent_nodeDelete->pRight = NULL;
            delete nodeDelete;
        }
        else {
            // Node chỉ có cây con phải 
            if (nodeDelete->pLeft == NULL) {
                if (parent_nodeDelete->data > nodeDelete->data)
                    parent_nodeDelete->pLeft = nodeDelete->pRight;
                else if (parent_nodeDelete->data < nodeDelete->data) 
                    parent_nodeDelete->pRight = nodeDelete->pRight;
            }
            // Node chỉ có cây con trái
            else if (nodeDelete->pRight == NULL) {
                if (parent_nodeDelete->data > nodeDelete->data)
                    parent_nodeDelete->pLeft = nodeDelete->pLeft;
                else if (parent_nodeDelete->data < nodeDelete->data)
                    parent_nodeDelete->pRight = nodeDelete->pLeft;
            }
            else if (nodeDelete->pRight != NULL && nodeDelete->pLeft != NULL) {
                NODE* nodeChange = getMAX(nodeDelete->pLeft);
                NODE* parent_nodeChange = searchParent(root, nodeChange->data);
                
                if (parent_nodeChange->data == nodeDelete->data) {

                    if (nodeChange->pLeft != NULL) {

                        NODE* left_nodeChange = nodeChange->pLeft;
                        NODE* f = findInsert(nodeDelete->pRight, left_nodeChange->data);

                        if (left_nodeChange->data < f->data)
                            f->pLeft = left_nodeChange;
                        else if (left_nodeChange->data > f->data) 
                            f->pRight = left_nodeChange;
                    }

                    if (parent_nodeDelete->data < nodeDelete->data) 
                        parent_nodeDelete->pRight = nodeChange;
                    else if (parent_nodeDelete->data > nodeDelete->data)
                        parent_nodeDelete->pLeft  = nodeChange;
                    nodeChange->pRight = nodeDelete->pRight;
                    nodeDelete->pLeft  = NULL;
                    nodeDelete->pRight = NULL;

                } else {
                    if (nodeChange->pLeft != NULL) {

                        NODE* left_nodeChange = nodeChange->pLeft;
                        NODE* f = findInsert(nodeDelete->pRight, left_nodeChange->data);

                        if (left_nodeChange->data < f->data)
                            f->pLeft = left_nodeChange;
                        else if (left_nodeChange->data > f->data) 
                            f->pRight = left_nodeChange;

                    }
                    nodeChange->pLeft  = nodeDelete->pLeft;
                    nodeChange->pRight = nodeDelete->pRight;
                    parent_nodeChange->pRight = NULL;

                    if (parent_nodeDelete->data < nodeDelete->data) 
                        parent_nodeDelete->pRight = nodeChange;
                    else if (parent_nodeDelete->data > nodeDelete->data)
                        parent_nodeDelete->pLeft  = nodeChange;
                    nodeDelete->pLeft  = NULL;
                    nodeDelete->pRight = NULL;
                }
            }
            delete nodeDelete;
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

