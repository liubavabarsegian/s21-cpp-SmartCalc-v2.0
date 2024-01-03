QT       += core gui
QT       += printsupport

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets
QMAKE_LFLAGS            += -Wall -Wextra -Werror -lm

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    dijkstra.c \
    main.cpp \
    mainwindow.cpp \
    qcustomplot.cpp \
    scan_rpn.c

HEADERS += \
    dijkstra.h \
    mainwindow.h \
    qcustomplot.h \
    scan_rpn.h

FORMS += \
    mainwindow.ui
    
# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
