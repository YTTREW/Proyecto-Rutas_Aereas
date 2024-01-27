/**
  * @file imagen.h
  * @brief Fichero cabecera para la E/S de imágenes.
  */

#include <string>
#include "imagenES.h"
#include <cassert>
#include <iostream>

using namespace std;


#ifndef __IMAGEN__H
#define __IMAGEN_H

enum Tipo_Pegado {OPACO, BLENDING};

struct Pixel{
    unsigned char r,g,b;
    unsigned char transparencia;
};

class Imagen{
private:

    /**
      @brief Lugar donde se almacena la información de la imagen
    **/
    Pixel **data;  
    //Otra posible representación
    //Pixel*datos

    /**
      @brief Número de filas de la imagen.
    **/
    int nf;

    /**
      @brief Número de columnas de la imagen.
    **/
    int nc;

    /**
    * @brief Borrar una imagen.
    * @brief Libera la memoria reservada en la que se almacenaba la imagen que llama a la función.
    * @post Si la imagen estaba vacía no hace nada.
    */
    void Borrar();

    /**
    * @brief Copiar una imagen.
    * @brief Copiar la imagen pasada por parametros en la imagen implícita.
    * @param I Referencia a la imagen original que se quiere copiar.
    * @post La imagen resultante es una copia de la imagen original.
    */
    void Copiar(const Imagen &I);

    public:

    /**
    * @brief Constructor por defecto .
    * @post Genera una instancia de la clase Imagen con O filas y O colunmas.
    * @return Imagen, el objeto imagen creado.
    */
    Imagen(); 

    /**
    * @brief Constructor de copias.
    * @param I Referencia a la imagen original que se quiere copiar.
    * @return Imagen, el objeto imagen creado.
    */
    Imagen(const Imagen &I); 

    /**
    * @brief Constructor con parámetros.
    * @param nf Número de filas de la imagen.
    * @param nc Número de columnas de la imagen.
    * @post La imagen creada es de nf y nc columnas. Estará inicializada al valor por defecto.
    * @return Imagen, el objeto imagen creado.
    */

    Imagen (int nf,int nc); //constructor con parámetros

    /**
      * @brief Operador de tipo destructor.
      * @return void.
      * @post El objeto Imagen destruido no puede usarse salvo que se haga sobre él una operacion Imagen().
      */
    ~Imagen();

    /**
    * @brief Operador de asignación.
    * @param I Referencia a la imagen original que desea copiarse.
    * @return Una referencia al objeto imagen modificado.
    * @post Destroy cualquier información que contuviera previamente la imagen que llama al operador de asignación.
    */

    Imagen & operator =(const Imagen & I);

    /**
    * @brief Filas de la imagen.
    * @return El número de filas de la imagen.
    * @post la imagen no se modifica.
    */ 
    int GetFilas()const; 
    
    /**
    * @brief Columnas de la imagen.
    * @return El número de columnas de la imagen.
    * @post la imagen no se modifica.
    */
    int GetCols()const; 

    /**
    * @brief Eliminar la transparencia de los pixeles de la imagen
    * cuya transparencia no es completamente opaca (0) ni completamente transparente (255).
    * @return void.
    * @post La transparencia de la imagen ha sido borrada.
    */
    void LimpiarTransp();
    
    
    /**
    * @brief Sobrecarga del operador() para acceder a un pixel.
    * @param i fila del pixel.
    * @param j columna del pixel.
    * @return Devuelve el pixel que se encuentra en la fila y columna solicitada.
    * @post la imagen no se modifica.
    */
    Pixel & operator()(int i,int j); 

    /**
    * @brief Sobrecarga del operador() para acceder a un pixel.
    * @param i fila del pixel.
    * @param j columna del pixel.
    * @return Devuelve el pixel que se encuentra en la fila y columna solicitada.
    * @post la imagen no se modifica.
    */
    const Pixel & operator()(int i,int j)const; 
    
    /**
    * @brief Escribe una imagen en formato PPM y su máscara asociada en formato PGM.
    * @brief Toma una imagen en formato RGB y genera dos archivos de imagen: uno en formato PPM para la imagen original. 
    * y otro en formato PGM para la máscara de transparencia. 
    * @param nombre Nombre del archivo de imagen en formato PPM.
    * @return void.
    */
    void EscribirImagen(const char *nombre); //escribe en disco la imagen
    
    /**
    * @brief Lee la imagen de tipo PPM y su mascara de tipo PGM.
    * @param nimagen Nombre de la imagen a leer.
    * @param nombre_mascara Nombre de la mascara de la imagen, por defecto es "".
    * @return void.
    */
    void LeerImagen(const char *nimagen, string nombre_mascara="");//Leer una imagen de disco.

    /**
    * @brief Coloca una imagen sobre otra en una posición especófica con distintas opciones de pegado.
    * @param posi Posición vertical en la que se colocará la esquina superior izquierda de la imagen.
    * @param posj Posición horizontal en la que se colocará la esquina superior izquierda de la imagen.
    * @param I Referencia a la imagen que se colocará sobre la imagen de destino.
    * @param tippegado Tipo de pegado a realizar. Puede ser opaco o de fusión.
    * @return void
    */
    void PutImagen(int posi,int posj, const Imagen &I,Tipo_Pegado tippegado);

    /**
    * @brief Extrae una subimagen de la imagen actual.
    * @param posi La posición inicial de la fila de la
    * @param posj Posición inicial de la columna.
    * @param dimi Numero de filas de la subimagen.
    * @param dimj Número de columnas de la subimagen.
    * @return Un nuevo objeto Imagen que representa la subimagen extraída.
    */
    Imagen ExtraeImagen(int posi, int posj, int dimi, int dimj);
};

#endif