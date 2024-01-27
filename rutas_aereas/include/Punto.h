/**
  * @file Punto.h
  * @brief Fichero para la declaración del módulo Punto.
  */

#include <iostream>
#include <fstream>
#include <string>
#include <cassert>
#include "imagenES.h"

using namespace std;


#ifndef __PUNTO__H
#define __PUNTO__H

class Punto{

    private:
    /**
      @brief Latitud del punto.
    **/
    double latitud;
    
    /**
      @brief Longitud del punto.
    **/
    double longitud;

    public:
    
    /**
    * @brief Constructor por defecto .
    * @post Genera una instancia de la clase Punto con latitud=0 y longitud=0.
    * @return Punto, el objeto punto creado.
    */
    Punto(){
        latitud=longitud=0;
    }
    
    /**
    * @brief Constructor con parametros.
    * @param l Latitud del punto.
    * @param L Longitud del punto.
    * @param d Descripcion opcional del punto.
    * @post Genera una instancia de la clase Punto.
    * @return Punto, el objeto punto creado.
    */
    Punto (double l, double L, const string & d):latitud(l),longitud(L){}

    /**
    * @brief Latitud del punto.
    * @return La latitud del punto.
    * @post el punto no se modifica.
    */ 
    double GetLatitud()const{
        return latitud;
    }
    
    /**
    * @brief Longitud del punto.
    * @return La longitud del punto.
    * @post El punto no se modifica.
    */ 
    double GetLongitud()const{
        return longitud;
    }
    
    /**
    * @brief Modifica la latitud del punto.
    * @param l Latitud del punto.
    * @return void.
    */ 
    void SetLatitud(double l){
        latitud=l;
    }

    /**
    * @brief Modifica la longitud del punto.
    * @param l Longitud del punto.
    * @return void.
    */ 
    void SetLongitud(double l){
        longitud=l;
    }

    /**
    * @brief Sobrecarga del operador <. 
    * @param p Punto para comparar con el punto implicito.
    * @return Devuelve true si el punto actual es menor que el punto proporcionado.
    */   
    bool operator<(const Punto & p)const{
        if (latitud < p.latitud) {
            return true;

        } else if (latitud > p.latitud) {
            return false;
        } 
            
        else {

            // Si las latitudes son iguales, comparar por longitud
            if( longitud < p.longitud){
                return true;
            }
            else if(longitud > p.longitud){
                return false;
            }
            //Si las longitudes son iguales
            else{

            return false;
            }
        }   
    }
    
    /**
    * @brief Sobrecarga del operador ==.
    * @param p Punto para comparar con el punto implicito.
    * @return Devuelve true si el punto actual es igual que el punto proporcionado.
    */ 
    bool operator==(const Punto & p)const{

        if((latitud==p.latitud) && (longitud==p.longitud)){
            return true;
        }
        else
            return false;
    }

    /**
    * @brief Sobrecarga del operador  de entrada (>>) para leer latitud y longitud.
    * @param is Flujo de entrada desde el cual se leen los datos.
    * @param p Punto al que se le asignan los valores leídos.
    * @return referencia al flujo de entrada.
    */ 
    friend istream & operator >> (istream & is, Punto &p){

        char a,b,c;//Para leer los parentesis y la coma.

        is >> a >> p.latitud >> b >> p.longitud >> c;
        return is;
    }

    /**
    * @brief Sobrecarga del operador  de salida (<<) para imprimir latitud y longitud.
    * @param os Flujo de salida desde el cual se imprimen los datos.
    * @param p Punto del que se imprime su latitud y longitud.
    * @return referencia al flujo de salida.
    */ 
    friend ostream & operator << (ostream & os, const Punto &p){

        os<< "Latitud: " << p.latitud << " Longitud: "<< p.longitud;
        return os;
    }
};

#endif