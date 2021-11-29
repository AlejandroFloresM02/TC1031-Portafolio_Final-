/* En este programa se realizarán sumatorias de forma 
iterativa, recursiva y directa, todas con el objetivo de 
sumar de 1 hasta n
Alejandro Flores Madriz A01634167 
18/08/2021*/
#include <iostream>
using namespace std; 

int Suma_Iterativa(int n ){
    /*Esta funcion es una sumatoria de 1 a n donde se itera la suma n veces. 
    La complejidad de esta función de O(n) porque la cantidad de pasoso que va a realizar el algoritmo es igual al nimero de entrada */
    if(n>0){
        int sumFinal =0;
        for(int i =1 ; i <= n; i++){
            sumFinal+=i;
        } 
        return sumFinal;
    }
    else{
        return -1;
    }
}

int Suma_Recursiva(int n){
    /*Esta función suma de 1 a n por medio de un metodo recursivo donde la función se llama a si misma para llegar a el resultado esperado. 
    La complejidad de esta función es tambien O(n) porque la cantidad de pasos minimos es igual al numero de entrada*/
    if(n>=0){
        if(n==0){
            return 0;
        }
        else{
            return(n+Suma_Recursiva(n-1));
        }
    }
    else{
        return -1;
    } 
}


int Suma_Directa(int n){
    /*Esta función obtiene la suma de una forma directa al evaluar el valor de la variable n
    La complejidad de esta función es de O(1) al requerir un solo paso para llegar al resultado*/
    if(n>0){
        return (n*(n+1)/2);
    }
    else{
        return -1;
    }
}
int main(){
    int n_1= 10;
    cout<< "Sumatoria Iterativa cuando n = 10 es iagual a " << Suma_Iterativa(n_1)<< endl;
    cout <<"Sumatoria Recursiva cuando n = 10 es igual a  "<<Suma_Recursiva(n_1)<< endl;
    cout <<"Sumatoria Directa cuando n = 10 es igual a  " << Suma_Directa(n_1)<< endl<< endl;

    int n_2= 75;
    cout<< "Sumatoria Iterativa cuando n = 10 es iagual a " << Suma_Iterativa(n_2)<< endl;
    cout <<"Sumatoria Recursiva cuando n = 10 es igual a  "<<Suma_Recursiva(n_2)<< endl;
    cout <<"Sumatoria Directa cuando n = 10 es igual a  " << Suma_Directa(n_2)<< endl<< endl;

    int n_3= 100;
    cout<< "Sumatoria Iterativa cuando n = 10 es iagual a " << Suma_Iterativa(n_3)<< endl;
    cout <<"Sumatoria Recursiva cuando n = 10 es igual a  "<<Suma_Recursiva(n_3)<< endl;
    cout <<"Sumatoria Directa cuando n = 10 es igual a  " << Suma_Directa(n_3)<< endl<< endl;

    int n_4= 43;
    cout<< "Sumatoria Iterativa cuando n = 10 es iagual a " << Suma_Iterativa(n_4)<< endl;
    cout <<"Sumatoria Recursiva cuando n = 10 es igual a  "<<Suma_Recursiva(n_4)<< endl;
    cout <<"Sumatoria Directa cuando n = 10 es igual a  " << Suma_Directa(n_4)<< endl<< endl;
}

