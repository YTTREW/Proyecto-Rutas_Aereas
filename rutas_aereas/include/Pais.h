/**
  * @file Pais.h
  * @brief Fichero para la declaración del módulo Pais.
  */

#include <string>
#include <Punto.h>
#include <iostream>
#include <fstream>
#include <string>
#include <cassert>
#include "imagenES.h"

using namespace std;

#ifndef __PAIS__H
#define __PAIS_H

class Pais{
  private:
    /**
      @brief Punto del pais.
    **/
    Punto p;
    
    /**
      @brief Nombre del país.
    **/
    string pais;
    
    /**
      @brief Bandera del país.
    **/
    string bandera;
    
  public:

    /**
    * @brief Constructor por defecto .
    * @post Genera una instancia de la clase Pais con p.longitud=0,p.latitud=0
    * pais="" y bandera="".
    * @return Punto, el objeto punto creado.
    */
    Pais(){

        p.SetLatitud(0);
        p.SetLongitud(0);
        pais="";
        bandera="";
    }

    /**
    * @brief Punto del pais.
    * @return El punto del pais.
    * @post el pais no se modifica.
    */ 
    Punto GetPunto()const{

      return p;
    }

    /**
    * @brief Nombre del pais.
    * @return El nombre del pais.
    * @post el pais no se modifica.
    */ 
    string GetPais()const{

      return pais;
    }

    /**
    * @brief Bandera del pais.
    * @return El bandera del pais.
    * @post el pais no se modifica.
    */ 
    string GetBandera()const{

      return bandera;
    }

    /**
    * @brief Sobrecarga del operador <.
    * @param p Pais para comparar con el pais implicito.
    * @return Devuelve true si el pais actual es menor que el pais proporcionado.
    */  
    bool operator<(const Pais &P)const{

      if(p<P.p)
            return true;
        else 
            return false;
    }

    /**
    * @brief Sobrecarga del operador ==.
    * @param p Pais para comparar con el pais implicito.
    * @return Devuelve true si el pais actual es igual que el pais proporcionado.
    */ 
    bool operator==(const Pais &P)const{

      if(p==P.p)
            return true;
        else
            return false;
    }

    /**
    * @brief Sobrecarga del operador ==.
    * @param p Punto para comparar con el pais implicito.
    * @return Devuelve true si el pais actual es igual que el punto proporcionado.
    */ 
    bool operator==(const Punto &P)const{

      if(p==P)
            return true;
        else
            return false;
    }

    /**
    * @brief Sobrecarga del operador  de entrada (>>) para leer punto,pais y bandera.
    * @param is Flujo de entrada desde el cual se leen los datos.
    * @param p pais al que se le asignan los valores leídos.
    * @return referencia al flujo de entrada.
    */ 
    friend istream & operator>>(istream & is, Pais & P){

      double lat,lng;
        
        is>>lat>>lng>>P.pais>>P.bandera;
        
        P.p=Punto(lat,lng,"");
        return is;
    }

    /**
    * @brief Sobrecarga del operador  de salida (<<) para imprimir punto,pais y bandera.
    * @param os Flujo de salida desde el cual se imprimen los datos.
    * @param p Punto del que se imprime su punto,pais y bandera.
    * @return referencia al flujo de salida.
    */ 
    friend ostream & operator<<(ostream & os, const Pais &P){

      os<<P.p<<" "<<P.pais<<" "<<P.bandera<<endl;
      return os;
    }
};





#endif