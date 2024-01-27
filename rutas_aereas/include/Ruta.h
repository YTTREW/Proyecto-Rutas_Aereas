/**
  * @file Ruta.h
  * @brief Fichero para la declaración del módulo Ruta.
  */


#include <string>
#include <list>
#include "Punto.h"
#include<iostream>

using namespace std;

#ifndef __RUTA__H
#define __RUTA_H

class Ruta{

    private:
        /**
          @brief Puntos que componen la ruta.
        **/
        list<Punto> puntos;
        
        /**
          @brief Código de la ruta.
        **/
        string code;
    public:

        /**
        * @brief Constructor por defecto.
        * @post Genera una instancia de la clase Ruta con puntos vacío.
        */
        Ruta(){}

        /**
        * @brief Inserta un punto en la lista de puntos.
        * @param n Punto que se quiere insertar.
        * @post Se ha insertado el punto pasado por referencia.
        * @return Void.
        */
        void Insertar(const Punto & n){

            puntos.push_back(n);
        }

        /**
        * @brief Borrar un punto de la lista de puntos.
        * @param n Punto que se quiere borrar.
        * @post Se ha borrado el punto pasado por referencia.
        * @return Void.
        */
        void Borrar(const Punto & n){

            puntos.remove(n);
        }
        
        /**
        * @brief Consultor de string code.
        * @return devuelva un string con el valor de code.
        */ 
        string getCode()const{
            return code;
        }

        /**
        * @brief Modificador de string code.
        * @param code Referencia a code por el que vamos a modifcar el actual.
        * @post Code pasa a tener un nuevo valor.
        * @return Void.
        */
        void SetCode(const string &code){

            this->code=code;
        }
        
        /**
        * @brief Sobrecarga del operador ==.
        * @param R Ruta para comparar sus puntos con los puntos de la ruta implicita.
        * @return Devuelve true si la ruta actual es igual que la ruta proporcionada.
        */ 
        bool operator==(const Ruta &R)const{

            list<Punto> aux = puntos;
            list<Punto> aux2 = R.puntos; 
            bool igual = true;   

            list<Punto>::iterator it=aux.begin();
            list<Punto>::iterator it2=aux2.begin();        

            if(puntos.size()!=R.puntos.size()){
                return false;
            }

            while(it != aux.end() && it2!=aux2.end() && igual){
                
                if(*it==*it2)
                    igual = true;
                else
                    igual = false;

                ++it;
                ++it2;
            }

            return igual;
        }

        /**
        * @brief Sobrecarga del operador <. 
        * @param R Ruta para comparar sus puntos con los puntos de la ruta implicita.
        * @return Devuelve true si la ruta actual es menor que la ruta proporcionada.
        */  
        bool operator<(const Ruta &R)const{
            
            list<Punto> aux = puntos;
            list<Punto> aux2 = R.puntos;
            
            aux.sort(); 
            aux2.sort();
            
            bool menor =true;
            list<Punto>::iterator it=aux.begin();
            list<Punto>::iterator it2=aux2.begin();
            
            if(puntos.size()>R.puntos.size()){
                return false;
            }

            if(puntos.size()<R.puntos.size()){
                return true;
            }
            
            while(it != aux.end() && it2!=aux2.end() && menor){

                if(*it<*it2)
                    menor=true;
                else if(*it==*it2)
                    menor=false;
                else
                    menor=false;
                    
                ++it;
                ++it2;
            }

            return menor;
        }
        

        class const_iterator;
        class iterator{
            private:
                list<Punto>::iterator p;
            public:

                /**
                * @brief Constructor por defecto.
                * @post Genera una instancia de la clase iterator.
                */
                iterator(){}
                
                /**
                * @brief Sobrecarga del operator ++. 
                * @brief Incrementa el iterador a la posición siguiente.
                * @return Devuelve el valor del iterador incrementado.
                */    
                iterator & operator++(){

                    ++p;
                    return *this;
                }  

                /**
                * @brief Sobrecarga del operator --. 
                * @brief Decrementa el iterador a la posición anterior.
                * @return Devuelve el valor del iterador decrementado.
                */
                iterator & operator--(){

                    --p;
                    return *this;
                }

                /**
                * @brief Sobrecarga del operador ==.
                * @param it iterator para comparar con el iterator p de set<Pais>.
                * @return Devuelve true si los dos iteradores apuntan a la misma posición.
                */ 
                bool operator==(const iterator & it){
                  
                    return it.p==p; 
                }

                /**
                * @brief Sobrecarga del operador !=.
                * @param it iterator para comparar con el iterator p de set<Pais>.
                * @return Devuelve true si dos iteradores no apuntan a la misma posición.
                */ 
                bool operator!=(const iterator & it){

                    return it.p!=p; 
                }

                /**
                * @brief Sobrecarga del operator *. 
                * @return Devulve el punto al que apunta p.
                */
                const Punto & operator*()const{
                    return *p;
                }       

                friend class Ruta;
                friend class const_iterator;

        };

        class const_iterator{
            private:
                list<Punto>::const_iterator p;
            public:
                /**
                * @brief Constructor por defecto.
                * @post Genera una instancia de la clase const_iterator.
                */
                const_iterator(){}

                /**
                * @brief Constructor copia de la clase const_iterator.
                * @param it Referencia al iterador a partir del cual se crea el const_iterator.
                * @post Genera una instancia de la clase const_iterator.
                */
                const_iterator(const iterator& it){

                    p=it.p;
                }

                /**
                * @brief Sobrecarga del operator ++. 
                * @brief Incrementa el const_iterator a la posición siguiente.
                * @return Devuelve el valor del const_iterator incrementado.
                */
                const_iterator & operator++(){

                    ++p;
                    return *this;
                } 

                /**
                * @brief Sobrecarga del operator --. 
                * @brief Decrementa el const_iterator a la posición anterior.
                * @return Devuelve el valor del const_iterator decrementado.
                */
                const_iterator & operator--(){

                    --p;
                    return *this;
                } 

                /**
                * @brief Sobrecarga del operador =.
                * @param it iterator que asigna su valor al const_iterator.
                * @return Devuelve true si los dos iteradores apuntan a la misma posición.
                */                 
                
                const_iterator & operator=(const iterator & it){

                    p=it.p;
                    
                    return *this;    
                }

                /**
                * @brief Sobrecarga del operador ==.
                * @param it const_iterator para comparar con el const_iterator p de set<Pais>.
                * @return Devuelve true si los dos iteradores apuntan a la misma posición.
                */ 
                bool operator==(const const_iterator & it){
                  
                    return it.p==p; 
                }

                /**
                * @brief Sobrecarga del operador !=.
                * @param it const_iterator para comparar con el const_iterator p de set<Pais>.
                * @return Devuelve true si dos iteradores no apuntan a la misma posición.
                */ 
                bool operator!=(const const_iterator & it){
                  
                    return it.p!=p; 
                }

                /**
                * @brief Sobrecarga del operator *. 
                * @return Devulve el pais al que apunta p.
                */
                const Punto & operator*()const{

                    return *p;
                }  

                friend class Ruta;
           
        };

        /**
        * @brief Inicializa un iterator que apunta al primer elemento. 
        * @return Devuelve un objeto iterator con la posición del primer elemento en la lista "puntos".
        */
        iterator begin(){
            iterator it;
            it.p = puntos.begin();
            return it; 
        }
        
        /**
        * @brief Inicializa un const_iterator que apunta al primer elemento.
        * @return Devuelve un objeto const_iterator con la posición del primer elemento en la lista "puntos".
        */ 
        const_iterator begin()const{
            const_iterator it;
            it.p = puntos.cbegin();
            return it; 
        }

        /**
        * @brief Inicializa un iterator que apunta al elemento final.
        * @return Devuelve un objeto iterator con la posición del ultimo elemento en la lista "puntos".
        */ 
        iterator end(){ 
            iterator it;
            it.p = puntos.end();
            return it;   
        }
        
        /**
        * @brief Inicializa un const_iterator que apunta al elemento final.
        * @return Devuelve la posicion del const_iterador con la posición del ultimo elemento en la lista "puntos".
        */ 
        const_iterator end()const{
            const_iterator it;
            it.p = puntos.cend();
            return it;
        }

        /**
        * @brief Busca un elemento en la lista "puntos". 
        * @param p Referencia al elemento de tipo Punto a buscar en la lista "puntos".
        * @return Un objeto iterator que apunta a la posición del elemento en la lista "puntos" 
        * o al final si no se encuentra.
        */ 
        iterator find(const Punto &p){

            iterator it;
            list<Punto>::iterator i;

            for (i=puntos.begin(); i!=puntos.end() && !((*i)==p);++i);
                it.p=i;
            return it;
        }

        /**
        * @brief Sobrecarga del operador  de entrada (>>) para leer las rutas.
        * @param is Flujo de entrada desde el cual se leen los puntos.
        * @param R Referencia a un objeto "Ruta" en el cual insertar los puntos leídos.
        * @return referencia al flujo de entrada.
        */ 
        friend istream & operator>>(istream & is, Ruta & R){
	        Ruta rlocal;
            int n=0;
            Punto punto;
            R=rlocal;
            
            is >> R.code;
            is >> n;
            
            for(int i=0;i<n;i++){

                Punto punto;
                is >> punto ;

                R.Insertar(punto);
            }
            return is; 
        }

        /**
        * @brief Sobrecarga del operador  de salida (<<) para imprimir las rutas.
        * @param os Flujo de salida desde el cual se imprimen los puntos.
        * @param R Punto del que se imprime los puntos y el codigo de ruta.
        * @return referencia al flujo de salida.
        */ 
        friend ostream & operator<<(ostream & os, const Ruta & R){
	
            os<<R.code<<" "<<endl;
            Ruta::const_iterator it;
            
            for(it = R.begin() ; it != R.end() ; ++it)
                os<<*it<<" " << endl;
          
            return os;
        }

};

#endif