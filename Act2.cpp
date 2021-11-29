/* En este programa se desarrollaran los diferentes algoritmos
utilizados para ordenar arreglos de n tamaño. 
Aleajandro Flores Madriz A01634167
05/09/2021*/
#include <bits/stdc++.h>
using namespace std; 

void ordenaIntercambio(vector<int> &Vec){
    /*Este algoritmo tiene una complejidad de O(n^2) */
    for(int i=0; i<Vec.size(); i++){
        int j=i;
        while(j-1 >=0 && Vec[j]<Vec[j-1]){
            int temp = Vec[j-1];
            Vec[j-1] = Vec[j];
            Vec[j] = temp;
            j--;
        }
    }
}

void ordenaBurbuja(vector<int> &Vec){
    /*Este algoritmo tiene una complejidad de O(n^2)*/
    int temp = 0;
    for(int i=0; i<Vec.size()-1; i++){
        for(int j = 0; j < Vec.size()-i-1;j++){
            if(Vec[j] > Vec[j+1]){
                temp = Vec[j];
                Vec[j] = Vec[j+1];
                Vec[j-1] = temp; 
            }
        }
    }
}

void merge(vector<int> &Vec, int left, int mid, int right){
    int lsize= mid-left+1;
    int rsize= right-mid;
    int i=0;
    int j=0;
    int k=0;
    vector<int>leftArray(lsize);
    vector<int>rightArray(rsize);
    for(i; i< lsize;i++){
        leftArray[i] = Vec[left+i];   
    }
    for(j; j<rsize;j++){
        rightArray[j] = Vec[mid+1+j];   
    }
    i=0;
    j=0;
    k=left;
    while(i< lsize && j< rsize){
       if(leftArray[i] <= rightArray[j]){
           Vec[k] = leftArray[i];
           i++;
       } 
       else{
           Vec[k] = rightArray[j];
           j++;
       }
       k++;
    }

    while(j < rsize){
        Vec[k] = rightArray[j];
        j++;
        k++;
    }
    while(i < lsize){
        Vec[k] = leftArray[i];
        i++;
        k++;
    }

}

void ordenaMerge(vector<int> &Vec, int left, int right){
    /*Este algortimo tiene una complejida de O(n log(n))*/
    if(left < right){
        int middle  = (left+ right)/2;
        ordenaMerge(Vec,left,middle);
        ordenaMerge(Vec,middle+1,right);
        merge(Vec,left,middle,right);
    }
}

int busqSecuencial(vector<int> Vec, int key){
    /*Este algoritmo tiene una complejidad de O(n)*/
    for(int i=0;i<Vec.size();i++){
        if(key <= Vec[i]){
            if( key == Vec[i]){
                return i;
            } 
            else{
                return -1;    
            }
        } 
    }
    return -1;
}

int busqBinaria(vector<int> Vec, int key){
    int left =0;
    int right = Vec.size()-1;
    int middle;
    while(left <= right){
        middle = floor(left+right)/2;
        if(key == Vec[middle]){
            return middle;
        }
        else if(key < Vec[middle]){
            right = middle-1;
        }
        else{
            left = middle+1;
        }
    } 
    return -1;
}

void imprimeVector(vector<int> Vect){
    for(int i=0;i < Vect.size();i++){
    cout<< Vect[i]<<" ";
    }
    cout<< endl;
}

int main(){
    vector<int> Vec1{56,72,28,12,16,34};
    vector<int> Vec2{53,78,63,5,19,54};
    vector<int> Vec3{63,14,85,69,78,12}; 
    vector<int> Vec4{52,36,14,12,39,3};   
cout<<"///////////////////Caso de Prueba 1///////////////////"<< endl;  
    cout<< "Caso de prueba uno donde el vector es igual a: ";
    imprimeVector(Vec1);
    ordenaIntercambio(Vec1);
    cout<< "Resultado utilizando la funcion ordenaIntercambio: ";
    imprimeVector(Vec1);
    ordenaBurbuja(Vec1);
    cout<< "Resultado utilizando la funcion ordenaBurbuja: ";
    imprimeVector(Vec1);
    ordenaMerge(Vec1,0,Vec1.size()-1);
    cout<< "Resultado utilizando la funcion ordenaMerge: ";
    imprimeVector(Vec1); 
    int num =0;
    cout << "ingrese el numero que quiere buscar "; 
    cin >> num;
    cout<< "indice donde se encuentra el numero 12 en el vector usando la funcion busqSecuanecial: " << busqSecuencial(Vec1,num);
    cout<< endl;
    cout<< "indice donde se encuentra el numero 56 en el vector usando la funcion busqBinaria: "<< busqBinaria(Vec1, num);
    cout << endl<<endl;

cout<<"///////////////////Caso de Prueba 2///////////////////"<< endl;
    cout<< "Caso de prueba uno donde el vector es igual a: ";
    imprimeVector(Vec2);
    ordenaIntercambio(Vec2);
    cout<< "Resultado utilizando la funcion ordenaIntercambio: ";
    imprimeVector(Vec2);
    ordenaBurbuja(Vec2);
    cout<< "Resultado utilizando la funcion ordenaBurbuja: ";
    imprimeVector(Vec2);
    ordenaMerge(Vec2,0,Vec2.size()-1);
    cout<< "Resultado utilizando la funcion ordenaMerge: ";
    imprimeVector(Vec2); 
    int num2=0;
    cout << "ingrese el numero que quiere buscar "; 
    cin >> num2;
    cout<< "indice donde se encuentra el numero 12 en el vector usando la funcion busqSecuanecial: " << busqSecuencial(Vec2,num2);
    cout<< endl;
    cout<< "indice donde se encuentra el numero 56 en el vector usando la funcion busqBinaria: "<< busqBinaria(Vec2, num2);
    cout << endl<<endl;

cout<<"///////////////////Caso de Prueba 3///////////////////"<< endl;
    cout<< "Caso de prueba uno donde el vector es igual a: ";
    imprimeVector(Vec3);
    ordenaIntercambio(Vec3);
    cout<< "Resultado utilizando la funcion ordenaIntercambio: ";
    imprimeVector(Vec3);
    ordenaBurbuja(Vec3);
    cout<< "Resultado utilizando la funcion ordenaBurbuja: ";
    imprimeVector(Vec3);
    ordenaMerge(Vec3,0,Vec3.size()-1);
    cout<< "Resultado utilizando la funcion ordenaMerge: ";
    imprimeVector(Vec3); 
    int num3=0;
    cout << "ingrese el numero que quiere buscar"; 
    cin >> num3;
    cout<< "indice donde se encuentra el numero 12 en el vector usando la funcion busqSecuanecial: " << busqSecuencial(Vec3,num3);
    cout<< endl;
    cout<< "indice donde se encuentra el numero 56 en el vector usando la funcion busqBinaria: "<< busqBinaria(Vec3, num3);
    cout << endl<<endl;

cout<<"///////////////////Caso de Prueba 4///////////////////"<< endl;
    cout<< "Caso de prueba uno donde el vector es igual a: ";
    imprimeVector(Vec4);
    ordenaIntercambio(Vec4);
    cout<< "Resultado utilizando la funcion ordenaIntercambio: ";
    imprimeVector(Vec4);
    ordenaBurbuja(Vec4);
    cout<< "Resultado utilizando la funcion ordenaBurbuja: ";
    imprimeVector(Vec4);
    ordenaMerge(Vec4,0,Vec4.size()-1);
    cout<< "Resultado utilizando la funcion ordenaMerge: ";
    imprimeVector(Vec4); 
    int num4=0;
    cout << "ingrese el numero que quiere buscar"; 
    cin >> num4;
    cout<< "indice donde se encuentra el numero 12 en el vector usando la funcion busqSecuanecial: " << busqSecuencial(Vec4,num4);
    cout<< endl;
    cout<< "indice donde se encuentra el numero 56 en el vector usando la funcion busqBinaria: "<< busqBinaria(Vec4, num4);
}