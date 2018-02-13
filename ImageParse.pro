#-------------------------------------------------
#
# Project created by QtCreator 2018-02-12T09:40:35
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = ImageParse
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which as been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0


SOURCES += \
    main.cpp \
    mainwindow.cpp \
    imageparse.cpp \
\
    clip2tri/clip2tri/clip2tri.cpp \
    clip2tri/clipper/clipper.cpp \
    clip2tri/poly2tri/common/shapes.cc \
    clip2tri/poly2tri/sweep/advancing_front.cc \
    clip2tri/poly2tri/sweep/cdt.cc \
    clip2tri/poly2tri/sweep/sweep.cc \
    clip2tri/poly2tri/sweep/sweep_context.cc \

HEADERS += \
    mainwindow.h \
    imageparse.h \
\
    clip2tri/clip2tri/clip2tri.h \
    clip2tri/clipper/clipper.hpp \
    clip2tri/poly2tri/common/shapes.h \
    clip2tri/poly2tri/common/utils.h \
    clip2tri/poly2tri/sweep/advancing_front.h \
    clip2tri/poly2tri/sweep/cdt.h \
    clip2tri/poly2tri/sweep/sweep.h \
    clip2tri/poly2tri/sweep/sweep_context.h \
    clip2tri/poly2tri/poly2tri.h \

FORMS += \
        mainwindow.ui

DISTFILES += \
    .gitignore
