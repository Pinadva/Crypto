include(gtest_dependency.pri)

TEMPLATE = app
CONFIG += console c++17
CONFIG += thread
CONFIG += qt

INCLUDEPATH += \
    Cesar/ \
    ../Crypto/ \
    ../Crypto/Model

HEADERS += \
    ../Crypto/Model/ikeyedcipher.h \
    ../Crypto/Model/polybius_square.h \
    ../Crypto/Model/siberian.h \
    ../Crypto/Model/vigener.h \
    ../Crypto/alphabets.h \
    ../Crypto/Model/cesar.h \
    ../Crypto/Model/gibberish.h \
    ../Crypto/Model/icipher.h \
    tst_cesar.h \
    tst_vigener.h

SOURCES += \
        ../Crypto/Model/cesar.cpp \
        ../Crypto/Model/gibberish.cpp \
        ../Crypto/Model/icipher.cpp \
        ../Crypto/Model/ikeyedcipher.cpp \
        ../Crypto/Model/polybius_square.cpp \
        ../Crypto/Model/siberian.cpp \
        ../Crypto/Model/vigener.cpp \
        ../Crypto/alphabets.cpp \
        main.cpp
