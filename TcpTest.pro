QT += core network
QT -= gui

CONFIG += c++11

TARGET = TcpTest
CONFIG += console
CONFIG -= app_bundle

TEMPLATE = app

SOURCES += main.cpp \
    interfaces/aae_server_interface.cpp \
    interfaces/aae_client_interface.cpp \
    protoc/pipe.pb.cc

HEADERS += \
    interfaces/aae_server_interface.h \
    interfaces/aae_client_interface.h \
    protoc/pipe.pb.h


LIBS += -lprotobuf
