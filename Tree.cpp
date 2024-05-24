#include <iostream>
#include <algorithm>


#define MAX 20

using namespace std;

class Tree {
    private: 
        typedef struct tree {
            char data;
            struct tree *left;
            struct tree *right;
        } tree;
    public:
        tree *root;
        Tree(){
            root = NULL;
        }
        
        void insert(char data) {
            tree *node = new tree;
            tree *parent;
            node->data = data;
            node->left = NULL;
            node->right = NULL;
            parent = NULL;
            if(root == NULL) {
                root = node;
            } else {
                tree *ptr;
                ptr = root;
                while(ptr != NULL) {
                    parent = ptr;
                    if(data > ptr->data) {
                        ptr = ptr->right;
                    } else {
                        ptr = ptr->left;
                    }
                }
                if(data < parent->data) {
                    parent->left = node;
                } else {
                    parent->right = node;
                }
            }
        }

        void inorder(tree *ptr) {
            if(ptr != NULL) {
                inorder(ptr->left);
                cout << " " << ptr->data;
                inorder(ptr->right);
            }
        }

        void preorder(tree *ptr) {
            if(ptr != NULL) {
                cout << " " << ptr->data;
                preorder(ptr->left);
                preorder(ptr->right);
            }
        }

        void postorder(tree *ptr) {
            if(ptr != NULL) {
                postorder(ptr->left);
                postorder(ptr->right);
                cout << " " << ptr->data;
            }
        }

        void display(tree *ptr, int level) {
            int i;
            if(ptr != NULL) {
                display(ptr->right, level+1);
                cout << endl;
                if(ptr == root) {
                    cout << "Root -> ";
                }
                for(i=0; i<level && ptr != root; i++) {
                    cout << "        ";
                }
                cout << ptr->data;
                display(ptr->left, level+1);
            }
        }

        void search(tree *ptr, char data) {
            if(ptr != NULL) {
                search(ptr->left, data);
                if(ptr->data == data) {
                    cout << "Element found in tree";
                }
                search(ptr->right, data);
            }
        }

        void deleteNode(tree *ptr, char data) {
            tree *parent;
            tree *current;
            tree *temp;
            tree *child;
            tree *suc;
            tree *psuc;
            parent = NULL;
            current = root;
            while(current != NULL && current->data != data) {
                parent = current;
                if(data < current->data) {
                    current = current->left;
                } else {
                    current = current->right;
                }
            }
            if(current == NULL) {
                cout << "Element not found";
                return;
            }
            if(current->left == NULL) {
                child = current->right;
            } else if(current->right == NULL) {
                child = current->left;
            } else {
                temp = current;
                child = current->right;
                suc = current->right;
                while(suc->left != NULL) {
                    temp = suc;
                    suc = suc->left;
                }
                if(current != temp) {
                    temp->left = suc->right;
                    suc->left = current->left;
                    suc->right = current->right;
                }
            }
            if(parent == NULL) {
                root = suc;
            } else {
                if(current == parent->left) {
                    parent->left = suc;
                } else {
                    parent->right = suc;
                }
            }
            delete current;
        }

        int height(tree *ptr) {
            int hLeft, hRight;
            if(ptr == NULL) {
                return 0;
            }
            hLeft = height(ptr->left);
            hRight = height(ptr->right);
            if(hLeft > hRight) {
                return 1 + hLeft;
            } else {
                return 1 + hRight;
            }
        }

        void printLevel(tree *ptr, int level) {
            if(ptr == NULL) {
                return;
            }
            if(level == 1) {
                cout << " " << ptr->data;
            } else if(level > 1) {
                printLevel(ptr->left, level-1);
                printLevel(ptr->right, level-1);
            }
        }

        void levelOrder(tree *ptr) {
            int h = height(ptr);
            int i;
            for(i=1; i<=h; i++) {
                printLevel(ptr, i);
            }
        }

        void mirror(tree *ptr) {
            tree *temp;
            if(ptr != NULL) {
                mirror(ptr->left);
                mirror(ptr->right);
                temp = ptr->left;
                ptr->left = ptr->right;
                ptr->right = temp;
            }
        }

        void deltree(tree *ptr) {
            if(ptr != NULL) {
                deltree(ptr->left);
                deltree(ptr->right);
                delete ptr;
            }
        }

        ~Tree() {
            deltree(root);
        }
};

int main() {
    Tree t;
    t.insert('P');
    t.insert('U');
    t.insert('Y');
    t.insert('R');
    t.insert('A');
    t.insert('M');
    t.insert('I');
    cout << "Inorder: ";
    t.inorder(t.root);
    cout << endl;
    cout << "Preorder: ";
    t.preorder(t.root);
    cout << endl;
    cout << "Postorder: ";
    t.postorder(t.root);
    cout << endl;
    cout << "Display: " << endl;
    t.display(t.root, 1);
    cout << endl;
    cout << "Height of tree: " << t.height(t.root) << endl;
    cout << "Level Order Traversal: ";
    t.levelOrder(t.root);
    cout << endl;
    t.mirror(t.root);
    cout << "Mirror image: " << endl;
    t.display(t.root, 1);
    cout << endl;
    t.search(t.root, 'A');
    cout << endl;
    t.search(t.root, 'Z');
    cout << endl;
    t.deleteNode(t.root, 'A');
    cout << "After deleting element A: " << endl;
    t.display(t.root, 1);
    cout << endl;
    cout << "Height of tree: " << t.height(t.root) << endl;
    return 0;
}