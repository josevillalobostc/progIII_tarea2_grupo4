## Integrantes
- José Luis Villalobos Jiménez
- Elías Emanuel Paz Raymondi

## Elegir el test
Para elegir un test de `tests/`, modificar `CMakeLists.txt`, y reemplazar `main.cpp` por `testx.cpp`, donde x es el número de test que elijas.

## Modo de ejecución
Tener CMake instalado para la compilación del proyecto.
Ejecutar en la terminal
```shell
cmake -B build
```
para crear la carpeta de build, y luego 
```
cmake --build build
```
para compilar el ejecutable.

Finalmente, para ejecutar el programa simplemente se usa
```shell
./build/Tarea2
```
En caso de abrir el proyecto en CLion, simplemente darle al botón de Play, luego de crear la carpeta de `build/`.