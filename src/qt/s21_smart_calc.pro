QT       += core gui widgets
QT       += printsupport

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets
QMAKE_LFLAGS            += -Wall -Wextra -Werror 

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    ../controllers/s21_calc_controller.cc \
    ../models/s21_calc_model.cc \
    creditview.cpp \
    main.cpp \
    mainwindow.cpp \
    qcustomplot.cpp \
    ../controllers/s21_credit_controller.cc \
    ../models/s21_credit_calc.cc \
    # ../controllers/s21_deposit_controller.cc

HEADERS += \
    ../controllers/s21_calc_controller.h \
    ../models/s21_calc_model.h \
    creditview.h \
    mainwindow.h \
    qcustomplot.h \
    ../controllers/s21_credit_controller.h \
    ../models/s21_credit_calc.h \
    # ../controllers/s21_deposit_controller.h

FORMS += \
    creditview.ui \
    mainwindow.ui
    creditview.ui
    # deposit.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
