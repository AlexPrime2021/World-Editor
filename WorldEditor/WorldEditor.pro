QT       += core gui opengl
LIBS += -lopengl32

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

DEFINES += QT_DEPRECATED_WARNINGS

SOURCES += \
    camera.cpp \
    camera3d.cpp \
    globject.cpp \
    main.cpp \
    mainwindow.cpp

HEADERS += \
    camera.h \
    camera3d.h \
    globject.h \
    mainwindow.h \
    view.h

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
