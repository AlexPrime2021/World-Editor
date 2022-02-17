!CAMERA_3D_PRI {

CONFIG += CAMERA_3D_PRI

INCLUDEPATH += $$PWD

include($$PWD/../Camera/Camera.pri)

HEADERS += \
    $$PWD/camera3d.h

SOURCES += \
    $$PWD/camera3d.cpp
}
