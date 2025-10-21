QT       = core
CONFIG  += c++17 console

# Archivos fuente
SOURCES += \
    src/Counter.cpp \
    src/main.cpp \
    src/Credit.cpp \
    src/Song.cpp \
    src/Album.cpp \
    src/Artist.cpp \
    src/User.cpp \
    src/AdMessage.cpp \
    src/Counter.cpp


# Archivos de cabecera
HEADERS += \
    include/Counter.hpp \
    include/DynamicArray.hpp \ 
    include/Credit.hpp \
    include/Song.hpp \
    include/Album.hpp \
    include/Artist.hpp \
    include/User.hpp \
    include/AdMessage.hpp \
    include/Counter.hpp

INCLUDEPATH += include

# Carpetas de salida
DESTDIR     = bin        # ejecutable
OBJECTS_DIR = build      # objetos intermedios (.o)

TARGET = Desafio_2
