TEMPLATE = lib
CONFIG += plugin c++11
DESTDIR = ../../bin/plugins/tools/
MOC_DIR = .moc
RCC_DIR = .moc
QT += widgets

INCLUDEPATH += \
	$$PWD/../.. \
	$$PWD/../../qrgui/ \
	$$PWD/../../qrgui/thirdparty \
	
HEADERS = \
        graphBeautifier.h
SOURCES = \
        graphBeautifier.cpp
