/*Alejandro Flores Madriz A01634167*/
#include <vector>
#include <iostream>
using namespace std;

class PriorityQueue{
    public:
        vector<int> Pqueue;
        // construstor 
        PriorityQueue(){
        }
        //Funcion que define la posicion del indice padre 0(1)
        int parent (int i){
            return (i-1)/2;
        }
        //Funcion que define la posicion del indice del hijo izquierdo O(1) 
        int left (int i){
            return (2*i + 1);
        }
        //Funcion que define la posicion del indice del hijo derecho O(1) 
        int right (int i){
            return (2*i + 2);
        }
        //Funcion que regres aun valor boolenao que indica si el heap esta vacio O(1)
        bool isEmpty(){ 
            if(Pqueue.size()==0){
                return 1;
            }
            else{
                return 0; 
            }
        }
        //Funcion que imprime los valores dentro del heap ordenados por prioridad O(n)
        void print(){
            for(int i =0; i<Pqueue.size()-1; i++){
                cout << Pqueue[i] << " -- ";
            }
            if(Pqueue.size() > 0){
                cout << Pqueue[Pqueue.size()-1] << endl;
            }
        }
        //Funcion que insterta un nuevo elemento en el heap tiene una complejidad de O(n)
        void push(int i){
            Pqueue.push_back(i);
            int size  = Pqueue.size()-1;
            while (size != 0 && Pqueue[parent(size)]< Pqueue[size]){
                int temp = Pqueue[size];
                Pqueue[size] = Pqueue[parent(size)];
                Pqueue[parent(size)] = temp;
                size = parent(size);  
            }
        }
        //Funcion que elimina el primer elemento en el heap O(1)
        int pop(){
            if(Pqueue.size() ==1){
                Pqueue.erase(Pqueue.begin());
            }
            else if(Pqueue.size()>1){
                Pqueue[0] = Pqueue[Pqueue.size()-1];
                Pqueue.pop_back();
                rearrange(0); 
            }
        }
        //Funcion para reordenar el heap a partir de un indice O(n)
        void rearrange(int i){
            int new_parent = i;
            int new_left = left(new_parent);
            int new_right = right( new_parent);

            if(new_left < Pqueue.size() && Pqueue[new_left] > Pqueue[new_parent]){
                new_parent = new_left; 
            }
            if(new_right < Pqueue.size() && Pqueue[new_right] > Pqueue[new_parent]){
                new_parent = new_right; 
            }
            if(new_parent != i){
                int temp = Pqueue[i];
                Pqueue[i] = Pqueue[new_parent];
                Pqueue[new_parent] = temp;

                rearrange(new_parent); 
            }
            
        }           
        //Funcion qeu obtiene el valor con mayor priorioridad en el heap O(1)
        int top(){
            if(Pqueue.size() >=1){
                return Pqueue[0];
            }
            else{
                return -1;
            }
        }
       
      
    }; 



int main(){
PriorityQueue Pqueue;
cout << "-------- caso de prueba 1 --------" << endl;
cout << "Agregando numero 59 al Heap "<< endl;
Pqueue.push(59);
Pqueue.print();
cout << "Verificando si el heap esta vacio (si = 1, no = 0)"<< endl;
cout << Pqueue.isEmpty() << endl;
cout << "Agregando elementos 19, 95 y 44 al Heap" << endl;
Pqueue.push(19);
Pqueue.push(95);
Pqueue.push(44);
Pqueue.print();
cout << "Verificando si el heap esta vacio (si = 1, no = 0)"<< endl;
cout << Pqueue.isEmpty() << endl;
cout<< "Realizando el pop" << endl;
Pqueue.pop();
Pqueue.print();
cout<< "Realizando el top"<<endl;
cout<< Pqueue.top()<< endl;
cout<< "Limpiando caso de prueba 1 "<<endl;
Pqueue.pop();
Pqueue.pop();
Pqueue.pop();
cout<< "Verificando si el heap esta vacio (si = 1, no = 0) "<<endl;
cout << Pqueue.isEmpty() << endl;
cout<< endl; 

cout << "-------- caso de prueba 2 --------" << endl;
cout << "Agregando numero 92 al Heap "<< endl;
Pqueue.push(92);
Pqueue.print();
cout << "Verificando si el heap esta vacio (si = 1, no = 0)"<< endl;
cout << Pqueue.isEmpty() << endl;
cout << "Agregando elementos 58, 12, 19, 61 y 24 al Heap" << endl;
Pqueue.push(58);
Pqueue.push(12);
Pqueue.push(19);
Pqueue.push(61);
Pqueue.push(24);
Pqueue.print();
cout << "Verificando si el heap esta vacio (si = 1, no = 0)"<< endl;
cout << Pqueue.isEmpty() << endl;
cout<< "Realizando el pop" << endl;
Pqueue.pop();
Pqueue.print();
cout<< "Realizando el top"<<endl;
cout<< Pqueue.top()<< endl;
cout<< "Limpiando caso de prueba 2 "<<endl;
Pqueue.pop();
Pqueue.pop();
Pqueue.pop();
Pqueue.pop();
Pqueue.pop();
cout<< "Verificando si el heap esta vacio (si = 1, no = 0) "<<endl;

cout << "-------- caso de prueba 3 --------" << endl;
cout << "Agregando numero 28 al Heap "<< endl;
Pqueue.push(28);
Pqueue.print();
cout << "Verificando si el heap esta vacio (si = 1, no = 0)"<< endl;
cout << Pqueue.isEmpty() << endl;
cout << "Agregando elementos 66, 39, 37, 6 y 39 al Heap" << endl;
Pqueue.push(66);
Pqueue.push(39);
Pqueue.push(37);
Pqueue.push(6);
Pqueue.push(39);
Pqueue.print();
cout << "Verificando si el heap esta vacio (si = 1, no = 0)"<< endl;
cout << Pqueue.isEmpty() << endl;
cout<< "Realizando el pop" << endl;
Pqueue.pop();
Pqueue.print();
cout<< "Realizando el top"<<endl;
cout<< Pqueue.top()<< endl;
cout<< "Limpiando caso de prueba 3 "<<endl;
Pqueue.pop();
Pqueue.pop();
Pqueue.pop();
Pqueue.pop();
Pqueue.pop();
cout<< "Verificando si el heap esta vacio (si = 1, no = 0) "<<endl;
cout << Pqueue.isEmpty() << endl;

cout << "-------- caso de prueba 4 --------" << endl;
cout << "Agregando numero 54 al Heap "<< endl;
Pqueue.push(54);
Pqueue.print();
cout << "Verificando si el heap esta vacio (si = 1, no = 0)"<< endl;
cout << Pqueue.isEmpty() << endl;
cout << "Agregando elementos 52, 27, 63, 100 y 64 al Heap" << endl;
Pqueue.push(52);
Pqueue.push(27);
Pqueue.push(63);
Pqueue.push(100);
Pqueue.push(64);
Pqueue.print();
cout << "Verificando si el heap esta vacio (si = 1, no = 0)"<< endl;
cout << Pqueue.isEmpty() << endl;
cout<< "Realizando el pop" << endl;
Pqueue.pop();
Pqueue.print();
cout<< "Realizando el top"<<endl;
cout<< Pqueue.top()<< endl;
cout<< "Limpiando caso de prueba 4 "<<endl;
Pqueue.pop();
Pqueue.pop();
Pqueue.pop();
Pqueue.pop();
Pqueue.pop();
cout<< "Verificando si el heap esta vacio (si = 1, no = 0) "<<endl;
cout << Pqueue.isEmpty() << endl;
}