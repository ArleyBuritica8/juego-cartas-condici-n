# Juego de Cartas por Condición

Proyecto desarrollado en C++ para la asignatura Estructura de Datos.


##  Presentación:

Juego de Cartas por Condición es un proyecto desarrollado en lenguaje C++ para la asignatura de Estructura de Datos, cuyo propósito es aplicar de manera práctica conceptos fundamentales de programación orientada a objetos, estructuras dinámicas, manejo de colecciones, modularización, archivos y serialización de información.

El proyecto consiste en un juego de cartas en el que participan varios jugadores. Cada jugador recibe una cantidad configurable de cartas y, durante cada ronda, se establece una condición que determina qué tipo de carta puede resultar ganadora.

La condición de una ronda está determinada por un color y un orden de comparación, que puede ser MAYOR o MENOR. Los jugadores seleccionan una carta de su mano y las cartas jugadas son evaluadas de acuerdo con la condición establecida para determinar la carta ganadora.

Además de la lógica principal del juego, el proyecto incorpora un sistema de **guardado y carga de partidas mediante serialización binaria**, permitiendo conservar el estado de una partida y recuperarlo posteriormente.

El desarrollo se realizó utilizando Git y GitHub, empleando ramas independientes y Pull Requests para organizar el trabajo y facilitar la integración de las diferentes funcionalidades del proyecto.


#  Objetivos

## Objetivo general

Desarrollar un juego de cartas por condición utilizando C++, aplicando principios de programación orientada a objetos, estructuras de datos dinámicas, modularización, control de versiones y serialización de información para gestionar de manera organizada el estado y funcionamiento de una partida.

## Objetivos específicos

- Diseñar e implementar clases que representen los diferentes elementos del juego.
- Aplicar principios de programación orientada a objetos como encapsulamiento y separación de responsabilidades.
- Utilizar estructuras dinámicas como vector para almacenar cartas, jugadores y rondas.
- Implementar una baraja de cartas que pueda ser creada, mezclada y utilizada durante la partida.
- Permitir la configuración de la cantidad de jugadores y cartas por jugador.
- Implementar condiciones de juego basadas en colores y órdenes de comparación.
- Gestionar las diferentes rondas de una partida.
- Determinar la carta ganadora de acuerdo con la condición establecida.
- Implementar un sistema de guardado y carga de partidas mediante archivos binarios.
- Aplicar serialización para conservar información de cartas, jugadores, condiciones, rondas y estado general del juego.
- Utilizar Git y GitHub para controlar las versiones del proyecto.
- Organizar el desarrollo mediante ramas y Pull Requests.
- Documentar la arquitectura del sistema mediante un diagrama de clases UML.

---

# 🎮 Descripción del juego

El juego está compuesto por una baraja de cartas que contiene diferentes colores y valores numéricos.

Cada carta posee:

- Un color.
- Un número.

La baraja utilizada por el programa contiene cuatro colores:

- Rojo
- Azul
- Verde
- Amarillo

Cada color contiene cartas numeradas del 1 al 10.Por lo tanto, la baraja está compuesta por:
4 colores × 10 valores = 40 cartas.



#  Funcionamiento del juego

El funcionamiento general del juego se divide en varias etapas.

### 1. Configuración

El usuario puede configurar:

- Cantidad de jugadores.
- Cantidad de cartas que recibirá cada jugador.

### 2. Creación de la baraja

El programa crea una baraja con las cartas disponibles y posteriormente puede mezclarlas para distribuirlas de manera aleatoria.

### 3. Repartición

Las cartas son repartidas entre los jugadores de acuerdo con la cantidad configurada.

Cada jugador posee una mano de cartas independiente.

### 4. Inicio de la partida

Una vez configurado el juego y repartidas las cartas, la partida puede comenzar.

### 5. Desarrollo de una ronda

Cada ronda posee una condición determinada por:

- Un color.
- Un orden de comparación.

Los órdenes disponibles son:

```text
MAYOR
MENOR