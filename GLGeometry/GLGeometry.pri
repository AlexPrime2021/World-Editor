!GL_GEOMETRY_PRI {

CONFIG += GL_GEOMETRY_PRI

INCLUDEPATH += $$PWD

include($$PWD/../GLObject/GLObject.pri)
include($$PWD/../VertexData/VertexData.pri)

HEADERS += \
    $$PWD/glgeometry.h

SOURCES += \
    $$PWD/glgeometry.cpp

RESOURCES += \
    $$PWD/shaders.qrc
}
