/**
  * @file Almacen_Rutas.h
  * @brief Fichero para la declaración del módulo Almacen_Rutas.
  */

#include "Ruta.h"
#include<utility>
#include<map>
#include<vector>

using namespace std;

#ifndef __ALMACEN_RUTAS__H
#define __ALMACEN_RUTAS_H

class Almacen_Rutas{
    private:
        /**
          @brief Map con todas las rutas.
        **/
        map<string,Ruta> rutas;

        /**
          @brief Multimap con los puntos de cada ruta.
        **/
        multimap<Punto, string> puntos;

    public:

        /**
        * @brief Constructor por defecto .
        * @post Genera una instancia de la clase Almacen_Rutas con rutas vacías.
        */
        Almacen_Rutas(){}

        /**
        * @brief Inserta una ruta en el map de rutas.
        * @param R Ruta que se quiere insertar.
        * @post Se ha insertado la ruta pasada por referencia.
        * @return Void.
        */
        void Insertar(const Ruta &R){
            
            rutas.emplace(R.getCode(),R);
        }

        /**
        * @brief Borrar una ruta del map de rutas.
        * @param R Ruta que se quiere borrar.
        * @post Se ha borrado la ruta pasada por referencia.
        * @return Void.
        */
        void Borrar(const Ruta &R){

            auto it = rutas.find(R.getCode());
            if (it != rutas.end()) 
                rutas.erase(it);
        }
        
        /**
        * @brief Consultor ruta.
        * @return devuelva una ruta con el valor de a.
        */ 
        Ruta GetRuta(const string & a){

            return rutas[a];
        }

        class const_iterator;        
        class iterator{
            private:
                map<string,Ruta>::iterator p;
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
                * @param it iterator para comparar con el iterator p de map<string,Ruta>.
                * @return Devuelve true si los dos iteradores apuntan a la misma posición.
                */ 
                bool operator==(const iterator & it){
                  
                    return it.p==p; 
                }

                /**
                * @brief Sobrecarga del operador !=.
                * @param it iterator para comparar con el iterator p de map<string,Ruta>.
                * @return Devuelve true si dos iteradores no apuntan a la misma posición.
                */ 
                bool operator!=(const iterator & it){

                    return it.p!=p; 
                }

                /**
                * @brief Sobrecarga del operator *. 
                * @return Devulve la ruta al que apunta p.
                */
                const pair<string,Ruta> operator*()const{
                    return *p;
                }

            friend class Almacen_Rutas;
            friend class const_iterator;
            
        };
        class const_iterator{
            private:
                map<string,Ruta>::const_iterator p;
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
                const_iterator & operator = (const iterator & it){

                    p=it.p;
                    
                    return *this;    
                }

                /**
                * @brief Sobrecarga del operador ==.
                * @param it const_iterator para comparar con el const_iterator p de map<string,Ruta>.
                * @return Devuelve true si los dos iteradores apuntan a la misma posición.
                */ 
                bool operator==(const const_iterator & it){
                  
                    return it.p==p; 
                }

                /**
                * @brief Sobrecarga del operador !=.
                * @param it const_iterator para comparar con el const_iterator p de map<string,Ruta>.
                * @return Devuelve true si dos iteradores no apuntan a la misma posición.
                */ 
                bool operator!=(const const_iterator & it){
                  
                    return it.p!=p; 
                }

                /**
                * @brief Sobrecarga del operator *. 
                * @return Devulve la ruta al que apunta p.
                */
                const pair<string,Ruta> operator*()const{

                    return *p;
                } 

            friend class Almacen_Rutas;
        };


         /**
        * @brief Inicializa un iterator que apunta al primer elemento. 
        * @return Devuelve un objeto iterator con la posición del primer elemento en el map "rutas".
        */
        iterator begin(){
            iterator it;
            it.p = rutas.begin();
            return it; 
        }

        /**
        * @brief Inicializa un const_iterator que apunta al primer elemento.
        * @return Devuelve un objeto const_iterator con la posición del primer elemento en el map "rutas".
        */ 
        const_iterator begin()const{
            const_iterator it;
            it.p = rutas.cbegin();
            return it; 
        }

        /**
        * @brief Inicializa un iterator que apunta al elemento final.
        * @return Devuelve un objeto iterator con la posición del ultimo elemento en el map "rutas".
        */ 
        iterator end(){
            iterator it;
            it.p = rutas.end();
            return it;         
        }

        /**
        * @brief Inicializa un const_iterator que apunta al elemento final.
        * @return Devuelve la posicion del const_iterador con la posición del ultimo elemento en el map "rutas".
        */     
        const_iterator end() const{
            const_iterator it;
            it.p = rutas.cend();
            return it;              
        }
        
        /**
        * @brief Sobrecarga del operador  de entrada (>>) para leer el almacen de rutas.
        * @param is Flujo de entrada desde el cual se leen las rutas.
        * @param AR Referencia a un objeto "Almacen_Rutas" en el cual insertar las rutas leídas.
        * @return referencia al flujo de entrada.
        */ 
        friend istream & operator >>(istream & is, Almacen_Rutas &AR){

            Almacen_Rutas rlocal;
            //leemos el comentario
            if (is.peek()=='#'){
                string a;
                getline(is,a);
                }                
                
                Ruta P;
                while (is>>P){
                rlocal.Insertar(P);
                
                }
                AR=rlocal;
                return is;   
        }

        /**
        * @brief Sobrecarga del operador  de salida (<<) para imprimir el almacen de rutas.
        * @param os Flujo de salida desde el cual se imprimen las rutas enteras.
        * @param R Punto del que se imprime las rutas.
        * @return referencia al flujo de salida.
        */ 
        friend ostream & operator <<(ostream & os, const Almacen_Rutas &R){
	  
             Almacen_Rutas::const_iterator it;
            for (it=R.begin(); it!=R.end(); ++it){
            os<<(*it).second<<"\t";
            } 

            return os;
        }
};

#endif