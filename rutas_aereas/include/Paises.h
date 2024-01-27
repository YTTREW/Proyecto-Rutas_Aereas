/**
  * @file Paises.h
  * @brief Fichero para la declaración del módulo Paises.
  */

#include "Pais.h"
#include <set>
#include<iostream>

using namespace std;

#ifndef __PAISES__H
#define __PAISES_H

class Paises{
    
    private:
    /**
      @brief Almacen con los datos de los países.
    **/
    set<Pais> datos;

    public:
        /**
        * @brief Constructor por defecto.
        * @post Genera una instancia de la clase Pais con datos vacío.
        */
        Paises(){
   
        };
        
        /**
        * @brief Inserta un pais en datos.
        * @param P Pais que se quiere insertar.
        * @post Se ha insertado el pais pasado por referencia.
        * @return Void.
        */
        void Insertar(const Pais &P){
            datos.insert(P);
        }

        /**
        * @brief Borrar un pais de datos.
        * @param P Pais que se quiere borrar.
        * @post Se ha borrado el pais pasado por referencia.
        * @return Void.
        */
        void Borrar(const Pais &P){

            datos.erase(P);
        }

        class const_iterator;
        class iterator{
            private:
                set<Pais>::iterator p;
            public:
                /**
                * @brief Constructor por defecto.
                * @post Genera una instancia de la clase iterator
                */
                iterator(){}
                
                /**
                * @brief Sobrecarga del operator ++. 
                * @brief Incrementa el iterador a la posición siguiente 
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
                * @return Devulve el pais al que apunta p.
                */
                const Pais & operator*()const{
                    return *p;
                }       

                friend class Paises;
                friend class const_iterator;         
        };

        class const_iterator{
            private:
                set<Pais>::const_iterator p;
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
                const_iterator(const iterator & it){

                    p=it.p;
                }

                /**
                * @brief Sobrecarga del operator ++. 
                * @brief Incrementa el const_iterator a la posición siguiente .
                * @return Devulve el valor del const_iterator incrementado.
                */
                const_iterator & operator++(){

                    ++p;
                    return *this;
                } 

                /**
                * @brief Sobrecarga del operator --. 
                * @brief Decrementa el const_iterator a la posición anterior.
                * @return Devulve el valor del const_iterator decrementado.
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
                const Pais & operator*()const{

                    return *p;
                }  

                friend class Paises;   
        };
        
        /**
        * @brief Inicializa un iterator que apunta al primer elemento. 
        * @return Devuelve un objeto iterator con la posición del primer elemento en el conjunto "datos".
        */
        iterator begin(){
            iterator it;
            it.p = datos.begin();
            return it; 
        }
        
        /**
        * @brief Inicializa un const_iterator que apunta al primer elemento.
        * @return Devuelve un objeto const_iterator con la posición del primer elemento en el conjunto "datos".
        */ 
        const_iterator begin()const{
            const_iterator it;
            it.p = datos.cbegin();
            return it; 
        }

        /**
        * @brief Inicializa un iterator que apunta al elemento final.
        * @return Devuelve un objeto iterator con la posición del ultimo elemento en el conjunto "datos".
        */ 
        iterator end(){
            
            iterator it;
            it.p = datos.end();
            return it;   
        }
        
        /**
        * @brief Inicializa un const_iterator que apunta al elemento final.
        * @return Devuelve la posicion del const_iterador con la posición del ultimo elemento en el conjunto "datos".
        */ 
        const_iterator end()const{

            const_iterator it;
            it.p = datos.cend();
            return it;
        }

        /**
        * @brief Busca un elemento en el conjunto "datos". 
        * @param p Referencia al elemento de tipo Pais a buscar en el conjunto "datos".
        * @return Un objeto iterator que apunta a la posición del elemento en el conjunto 'datos' 
        * o al final si no se encuentra.
        */ 
        iterator find(const Pais &p){

            iterator it;
            set<Pais>::iterator i;

            for (i=datos.begin(); i!=datos.end() && !((*i)==p);++i);
                it.p=i;
            return it;

        }

        /**
        * @brief Busca un elemento en el conjunto "datos". 
        * @param p Referencia al elemento de tipo Punto a buscar en el conjunto "datos".
        * @return Un objeto iterator que apunta a la posición del elemento en el conjunto "datos" 
        * o al final si no se encuentra.
        */ 
        iterator find(const Punto &p){

            iterator it;
            set<Pais>::iterator i;

            for (i=datos.begin(); i!=datos.end() && !((*i)==p);++i);
                it.p=i;
            return it;
        }

        /**
        * @brief Sobrecarga del operador  de entrada (>>) para leer los paises.
        * @param is Flujo de entrada desde el cual se leen los datos.
        * @param R Referencia a un objeto "Paises" en el cual insertar los países leídos.
        * @return referencia al flujo de entrada.
        */ 
        friend istream & operator>>(istream & is, Paises & R){
	      Paises rlocal;
	      //leemos el comentario
	      if (is.peek()=='#'){
            string a;
            getline(is,a);
            }	
            
            Pais P;
            while (is>>P){
            rlocal.Insertar(P);
            
            }
            R=rlocal;
            return is;
        }

        /**
        * @brief Sobrecarga del operador  de salida (<<) para imprimir los paises.
        * @param os Flujo de salida desde el cual se imprimen los datos.
        * @param R Punto del que se imprime su punto,pais y bandera.
        * @return referencia al flujo de salida.
        */ 
        friend ostream & operator<<(ostream & os, const Paises & R){
	  
            Paises::const_iterator it;
            for (it=R.begin(); it!=R.end(); ++it){
            os<<*it<<"\t";
            }
            return os;
        }           
};

#endif