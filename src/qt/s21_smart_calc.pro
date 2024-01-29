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
    # credit_calc_view.cpp \
    creditview.cpp \
    main.cpp \
    mainwindow.cpp \
    qcustomplot.cpp \
    # ../controllers/s21_credit_controller.cc \
    # ../controllers/s21_deposit_controller.cc

HEADERS += \
    # calc_view.h \
    ../controllers/s21_calc_controller.h \
    ../models/s21_calc_model.h \
    # credit_calc_view.h \
    creditview.h \
    mainwindow.h \
    qcustomplot.h \
    # ../controllers/s21_credit_controller.h \
    # ../controllers/s21_deposit_controller.h

FORMS += \
    # credit_calc_view.ui \
    creditview.ui \
    mainwindow.ui
    # credit.ui
    # deposit.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
