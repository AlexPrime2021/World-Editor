QT       += core gui opengl
LIBS += -lopengl32

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

DEFINES += QT_DEPRECATED_WARNINGS

include($$PWD/../GLGeometry/GLGeometry.pri)
include($$PWD/../Camera3D/Camera3D.pri)
include($$PWD/../Viewport3D/Viewport3D.pri)

SOURCES += \
    main.cpp \
    mainwindow.cpp

HEADERS += \
    mainwindow.h

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
