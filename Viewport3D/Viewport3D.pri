!VIEWPORT_3D {

CONFIG += VIEWPORT_3D

INCLUDEPATH += $$PWD

include($$PWD/../Camera/Camera.pri)
include($$PWD/../GLObject/GLObject.pri)

HEADERS += \
    $$PWD/viewport3d.h

SOURCES += \
    $$PWD/viewport3d.cpp
}
