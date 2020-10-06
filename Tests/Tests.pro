include(gtest_dependency.pri)

TEMPLATE = app
CONFIG += console c++17
CONFIG -= app_bundle
CONFIG += thread
CONFIG += qt

INCLUDEPATH += \
    Cesar/ \
    ../Crypto

HEADERS += \
    ../Crypto/alphabets.h \
    ../Crypto/cesar.h \
    ../Crypto/gibberish.h \
    ../Crypto/icipher.h \
    Cesar/tst_cesar.h

SOURCES += \
        ../Crypto/cesar.cpp \
        ../Crypto/gibberish.cpp \
        ../Crypto/icipher.cpp \
        main.cpp
