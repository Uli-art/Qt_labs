QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    circle.cpp \
    eightstar.cpp \
    fivestar.cpp \
    hexagon.cpp \
    infoaboutfigure.cpp \
    main.cpp \
    mainwindow.cpp \
    paintScene.cpp \
    parallelogram.cpp \
    point.cpp \
    rectangle.cpp \
    romb.cpp \
    shape.cpp \
    sixstar.cpp \
    square.cpp \
    triangle.cpp

HEADERS += \
    circle.h \
    eightstar.h \
    fivestar.h \
    hexagon.h \
    infoaboutfigure.h \
    mainwindow.h \
    paintScene.h \
    parallelogram.h \
    point.h \
    rectangle.h \
    romb.h \
    shape.h \
    sixstar.h \
    square.h \
    triangle.h

FORMS += \
    infoaboutfigure.ui \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
