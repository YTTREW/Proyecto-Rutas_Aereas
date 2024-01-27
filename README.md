# Proyecto TDAs-Rutas_A-reas

Este proyecto tiene como objetivo visualizar rutas aéreas sobre un mapa del mundo, indicando los países que atraviesa y proporcionando una representación gráfica de la ruta con banderas y marcadores de aviones.

## Requisitos Previos

Asegúrate de tener instalados los siguientes requisitos previos antes de ejecutar el proyecto:

- CMake

## Instrucciones de Compilación

1. Clona este repositorio en tu máquina local:

   ```bash
   git clone git@github.com:YTTREW/TDAs-Rutas_A-reas.git
   cd TDAs-Rutas_A-reas
   cmake ./
   make

## Ejecutables
1. Ruta Aérea (ruta_aereas) 
Este programa se encarga de obtener un mapa del mundo con una ruta pintada.
```bash
ruta_aerea paises.txt mapa.ppm dir_banderas almacen_rutas.txt avion.ppm mascara_avion.pgm
```
2. Rotar una imagen (pruebarotacion)
Este programa permite rotar una imagen dada un ángulo específico.
```bash
pruebarotacion avion.ppm 45 avion_45.ppm
```
3. Superponer imagenes (pruebapegado)
Esta función superpone la segunda imagen sobre la imagen de fondo.

```bash
pruebapegado espana_reshigh.ppm avion2.ppm mascara_avion2.pgm espana_avion2_blending.ppm 0 0 1
```
