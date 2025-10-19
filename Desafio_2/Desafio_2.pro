QT       = core
CONFIG  += c++17 console

# Archivos fuente
SOURCES += \
    src/main.cpp \
    src/Credit.cpp


# Archivos de cabecera
HEADERS += \
    include/DynamicArray.hpp \ 
    include/Credit.hpp

INCLUDEPATH += include

# Carpetas de salida
DESTDIR     = bin        # ejecutable
OBJECTS_DIR = build      # objetos intermedios (.o)

TARGET = Desafio_2
