# Desafio 2

---

## Descripción
UdeATunes es una aplicación musical en C++ que permite gestionar usuarios, reproducir canciones, administrar favoritos y mostrar anuncios. La aplicación incluye un sistema de seguimiento de memoria y métricas, ideal para aprender sobre programación orientada a objetos, estructuras dinámicas y simulación de reproducción musical.

---

## Características principales

- Gestión de usuarios con soporte premium y favoritos.
- Registro y reproducción de canciones con créditos de productores, músicos y compositores.
- Gestión de artistas, álbumes y mensajes publicitarios.
- Sesión de reproducción con historial y métricas.
- Base de datos interna que soporta carga de datos de prueba y archivos.
- Monitoreo de uso de memoria mediante `MemoryTracker`.
- Arreglos dinámicos genéricos (`DynamicArray`) para manejar colecciones.
- Sistema de métricas y contadores (`Counter`) para monitorear operaciones.

---

## Estructura del proyecto

```

├── src/
│   ├── main.cpp             # Punto de entrada de la aplicación
│   ├── AppMusic.hpp/cpp     # Clase principal de la aplicación
│   ├── Database.hpp/cpp     # Gestión de usuarios, canciones y artistas
│   ├── PlaybackSession.hpp/cpp # Sesiones de reproducción
│   ├── User.hpp/cpp
│   ├── Song.hpp/cpp
│   ├── Artist.hpp/cpp
│   ├── Album.hpp/cpp
│   ├── Credit.hpp/cpp
│   ├── AdMessage.hpp/cpp
│   ├── MemoryTracker.hpp/cpp
│   ├── Counter.hpp
│   └── DynamicArray.hpp
├── version                  # Número de versión del proyecto (ej: 1.0.0)
├── README.md
└── docs/                    # Documentación generada con Doxygen

````

---

## Compilación y ejecución

1. Asegúrate de tener un compilador compatible con **C++17 o superior**.
2. Compila la aplicación usando tu IDE o **CMake/Makefile**.
3. Ejecuta el binario:

```bash
./AppMusic
````

4. La aplicación iniciará un menú de login y sesiones de usuario.

---

## Dependencias

* C++ Standard Library (iostream, string, thread, chrono, etc.)
* Qt Core (solo si usas `QCoreApplication` en `main.cpp`)
* Sin librerías externas obligatorias; todas las estructuras se implementan internamente.

---

## Clases principales

| Clase             | Descripción                                                       |
| ----------------- | ----------------------------------------------------------------- |
| `AppMusic`        | Controla la aplicación, menú de login y flujo de usuario.         |
| `Database`        | Almacena usuarios, canciones, artistas, álbumes y anuncios.       |
| `User`            | Representa un usuario, su estado premium y favoritos.             |
| `Song`            | Representa una canción con créditos y contador de reproducciones. |
| `Artist`          | Representa un artista musical y sus álbumes.                      |
| `Album`           | Representa un álbum con sus canciones y metadatos.                |
| `Credit`          | Representa un crédito (productor, músico, compositor).            |
| `AdMessage`       | Mensajes publicitarios con categoría y peso.                      |
| `PlaybackSession` | Gestiona la reproducción de canciones y anuncios.                 |
| `MemoryTracker`   | Monitorea memoria asignada y liberada.                            |
| `Counter`         | Contador de operaciones o métricas internas.                      |
| `DynamicArray`    | Arreglo dinámico genérico para manejar colecciones.               |

---

## Documentación

La documentación de la API se encuentra en la carpeta `html/` y puede ser generada usando **Doxygen**:

```bash
doxygen Doxyfile
```

---

## Versión

```
1.0.0
```

---

## Autor

 - Julian Mauricio Sánchez Ceballos
 - Jaider Bedoya Carmona

---

## Licencia

Este proyecto es libre para uso educativo y personal bajo la licensia GNU GENERAL PUBLIC LICENSE

```

