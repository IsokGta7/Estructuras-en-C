# Estructuras en C++

Colección de estructuras de datos implementadas en C++ utilizadas como material de estudio. Incluye:

- **Pila**: implementación genérica basada en `std::vector` con demostraciones y pruebas automatizadas.
- **Árbol B estrella (B\*)**: cliente original incluido para referencia histórica.

## Estructura del repositorio

- `Pila/`: implementación de la pila y ejemplo de uso.
- `ArbolBAsterisco(Estrella)/`: código legado del árbol B* y utilidades asociadas.
- `tests/`: pruebas automatizadas de la pila.

## Uso

### Compilar ejemplo de la pila

```bash
g++ -std=c++17 -I./Pila Pila/Main.cpp -o pila_demo
./pila_demo
```

### Ejecutar pruebas

```bash
g++ -std=c++17 -I./Pila tests/test_pila.cpp -o tests/test_pila
./tests/test_pila
```

Las pruebas utilizan únicamente `<cassert>` para evitar dependencias externas.

## Notas

El código del árbol B* se mantiene sin cambios funcionales para preservar el comportamiento original. Las mejoras actuales se concentran en documentar y probar la pila.
