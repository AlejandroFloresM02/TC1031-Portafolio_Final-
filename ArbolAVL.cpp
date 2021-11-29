//Alejandro Flores Madriz A01634167
#include <iostream>

using namespace std;

template <class T> class Node {
    public:
        T data; // The object information
        int key; // key of the value
        int height;
        Node<T>* left; // Pointer to the left node element
        Node<T>* right; // Pointer to the right node element
        
        Node(T new_data, int key, Node<T>* left, Node<T>* right){
            this->data = new_data;
            this->key = key;
            this->left = left;
            this->right = right;
            this->height = 1;
        }

        Node(){
            this->key = key;
            this->left = NULL;
            this->right= NULL;
            this->height = 1;
        }

        Node(T new_data, int key){
            this->data = new_data;
            this->key = key;
            this->left = NULL;
            this->right = NULL;
            this->height = 1;
        }
};

template <class T> 
int getHeight(Node<T> *N){
  if(!N){
    return 0;
  }
  else{
    return N->height;
  }
}

int max(int data1, int data2){
    if(data1 > data2){
        return data1;
    }
    else{
        return data2;
    }
}



template <class T>class AVLTree{
    public:
        Node<T> *root;
        
        AVLTree(){
            this->root = NULL;
        }
        ~AVLTree(){
        }
        //Funcion para realizar la rotación a la derecha, complejidad O(log(n))
        Node<T> *rightRotate(Node<T> *node){
            Node<T> *lnode = node->left;
            Node<T> *lrnode = lnode->right;

            lnode->right = node;
            node->left = lrnode;
            if(node == this->root){
                this->root = lnode;
            }
            node->height = max(getHeight(node->left), getHeight(node->right))+1;
            lnode->height = max(getHeight(lnode->left), getHeight(lnode->right))+1;

            return lnode;
        }
        //Funcion para realizar la rotación a la izquierda, complejidad O(log(n))
        Node<T>* leftRotate(Node<T> *node){
            Node<T> *rnode = node->right;
            Node<T> *rlnode = rnode->left;

            rnode->left = node;
            node->right = rlnode;
            if(node == this->root){
                this->root = rnode;
            }
            node->height = max(getHeight(node->left), getHeight(node->right))+1;
            rnode->height = max(getHeight(rnode->left), getHeight(rnode->right))+1;

            return rnode;
        } 


        //funcion para insetar un dato al arbol, complejidad O(log(n))
        Node<T>* insert(Node<T> *node, int key, T data){
            if (root == NULL){
                Node<T>* temp = new Node<T>;
                temp->key = key;
                temp->data = data;
                this->root = temp;
                return(temp);
            }
            if (node == NULL){
                Node<T>* temp= new Node<T>;
                temp ->key = key; 
                temp->data = data;
                return(temp);
            }
            if (key < node->key){
                node->right = insert(node->right, key, data);
            }
            else if (key> node->key){
                node->right = insert(node->right, key, data);
            }
            else{
                return node; 
            }
            
            //Cambiar altura de nodos
            node->height = 1 + max(getHeight(node->left), getHeight(node -> right));
            
            //verificar balance despues de que se inserto un nodo
            int balance = getBalance(node);

            //LLrotation
            if(balance > 1 && key < node->left->key){
                return rightRotate(node);
            }

            //RRrotation
            if ((balance < -1) && (key > node->right->key)){
                return leftRotate(node);
            }

            //LR rotation
            if((balance > 1) && (key > node->right->key)){
                node->left =  leftRotate(node->left);
                return rightRotate(node);
            }

            //RL rotation
            if (balance < -1 && key < node->right->key){
                node->right = rightRotate(node->right);
                return leftRotate(node);
            }
            return node; 
        }

        void insert(T data, int key){
            insert(this->root, key, data);
        }

        //Funcion para obtener el factor de balance de un nodo, complejidad O(log(n))
        int getBalance(Node<T> *node){
            if(node == NULL){
                return 0;
            }
            return getHeight(node->left) - getHeight(node->right);
        }
        

        // Funcion para borrar elementos en el arbol, complejidad O(log(n))
        Node<T>* del(Node<T>* node, int key){
          if(node == NULL){
                return node;
          }
          if(key< node->key){
                node->left =del(node->left, key);
          }
          else if(key > node->key){
                node->right = del(node->right, key);
          }
          else{
                if((node->left == NULL) || (node->right == NULL)){
                    Node<T>* temp = new Node<T>;
                    if(node->left){
                        temp = node->left;
                    }
                    else{
                        temp = node->right;
                    }
                    if (temp == NULL){
                        temp = node;
                        node = NULL; 
                    }
                    else{
                        *node = *temp;
                    }
                    free (temp);
                }
                else{
                    Node<T>* temp = node->right;
                    while (temp->left){
                        temp = temp->left;
                    }
                    node->key = temp->key;
                    node->right = del(node->right, temp->key);
                }
            }

            if (node == NULL){
                return node;
            }

            node->height = 1 + max(getHeight(node->left), getHeight(node->right));
            
            int balance = this->getBalance(node);
            
            //LL
            if (balance > 1 && getBalance(node->left)>=0){
                return rightRotate(node);
            }

            //RR
            if (balance < -1 && getBalance(node->right)<=0){
                return leftRotate(node);
            }

            //LR
            if (balance > 1 && getBalance(node->left) < 0){
                node->left = leftRotate(node->left);
                return rightRotate(node);
            }

            //RL 
            if(balance <-1 && getBalance(node->right) > 0 ){
                node->right = rightRotate(node->right);
                return leftRotate(node);
            }

            return node;
        } 
        
    
        //funcion que encuentra si un valor existe en el arbol, complejidad O(log(n))
        bool find(int key, Node<T> *node){
            if(node != NULL){
                if(node->key == key){
                    return 1;
                }
                else{
                    return find(key, node->left) || find(key, node->right);
                }
            }
            else{
                return 0;
            }
        }

        // funcion que despliega enb pantalla los contenidos del arbol de forma ascendente, complejidad O(log(n)) 
        void print(Node<T>* current_node){
            if(current_node){
                print(current_node->left);
                cout << current_node->key << " ";
                print(current_node->right);
            }
            if(this->root == current_node){
                cout<<endl;
            }
        }

        //funcion para obtener el tamaño del arbol, complejidad O(log(n))
        int size(Node<T> *node){
            if (node == NULL){
                return 0;
            }
            else{
                return 1+ size(node->left) + size(node->right); 
            }
        }
        int size(){
            return this->size(this->root);
        }
};

int main(){
    AVLTree<char> AVL;
    AVL.insert('A',10);
    AVL.insert('B',20);
    AVL.insert('C',30);
    AVL.insert('D',40);
    AVL.insert('E',50);
    AVL.insert('F',60);
    AVL.insert('G',70);
    AVL.insert('H',80);
    AVL.insert('I',90);
    cout << "Imprimiendo arbol" << endl;
    AVL.print(AVL.root);
    cout << "Tamano del arbol "<<endl;
    cout << AVL.size() << endl;
    cout << "Insertando el valor 100 en el arbol" << endl;
    AVL.insert('J',100);
    cout << "Tamano del arbol "<<endl;
    cout << AVL.size() << endl;
    cout << "Valor booleano que indica la existencia de 100 en el arbol: " << AVL.find(100, AVL.root) << endl;
    cout << "Imprimiendo arbol" << endl;
    AVL.print(AVL.root);
    cout<< "Eliminanado el dato 50 del arbol" << endl; 
    AVL.del(AVL.root, 50);
    cout<< "Eliminanado el dato 40 del arbol" << endl; 
    AVL.del(AVL.root, 40);
    cout<< "Eliminanado el dato 30 del arbol" << endl; 
    AVL.del(AVL.root, 30);
    cout << "Valor booleano que indica la existencia de 40 en el arbol: " << AVL.find(40, AVL.root) << endl;
     cout << "Imprimiendo arbol" << endl;
    AVL.print(AVL.root);
    cout << "Tamano del arbol "<<endl;
    cout << AVL.size() << endl;
}