QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# The following define makes your compiler emit warnings if you use
# any Qt feature that has been marked deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    electromagnet-calibration/electromagnet_calibration.cpp \
    electromagnet-calibration/scalorPotential.cpp \
    main.cpp \
    mainwindow.cpp

HEADERS += \
    electromagnet-calibration/EigenToYAML.h \
    electromagnet-calibration/electromagnet_calibration.h \
    electromagnet-calibration/scalorPotential.h \
    mainwindow.h \
    yaml-cpp-master/include/yaml-cpp/anchor.h \
    yaml-cpp-master/include/yaml-cpp/binary.h \
    yaml-cpp-master/include/yaml-cpp/contrib/anchordict.h \
    yaml-cpp-master/include/yaml-cpp/contrib/graphbuilder.h \
    yaml-cpp-master/include/yaml-cpp/depthguard.h \
    yaml-cpp-master/include/yaml-cpp/dll.h \
    yaml-cpp-master/include/yaml-cpp/emitfromevents.h \
    yaml-cpp-master/include/yaml-cpp/emitter.h \
    yaml-cpp-master/include/yaml-cpp/emitterdef.h \
    yaml-cpp-master/include/yaml-cpp/emittermanip.h \
    yaml-cpp-master/include/yaml-cpp/emitterstyle.h \
    yaml-cpp-master/include/yaml-cpp/eventhandler.h \
    yaml-cpp-master/include/yaml-cpp/exceptions.h \
    yaml-cpp-master/include/yaml-cpp/mark.h \
    yaml-cpp-master/include/yaml-cpp/node/convert.h \
    yaml-cpp-master/include/yaml-cpp/node/detail/impl.h \
    yaml-cpp-master/include/yaml-cpp/node/detail/iterator.h \
    yaml-cpp-master/include/yaml-cpp/node/detail/iterator_fwd.h \
    yaml-cpp-master/include/yaml-cpp/node/detail/memory.h \
    yaml-cpp-master/include/yaml-cpp/node/detail/node.h \
    yaml-cpp-master/include/yaml-cpp/node/detail/node_data.h \
    yaml-cpp-master/include/yaml-cpp/node/detail/node_iterator.h \
    yaml-cpp-master/include/yaml-cpp/node/detail/node_ref.h \
    yaml-cpp-master/include/yaml-cpp/node/emit.h \
    yaml-cpp-master/include/yaml-cpp/node/iterator.h \
    yaml-cpp-master/include/yaml-cpp/node/node.h \
    yaml-cpp-master/include/yaml-cpp/node/parse.h \
    yaml-cpp-master/include/yaml-cpp/node/ptr.h \
    yaml-cpp-master/include/yaml-cpp/node/type.h \
    yaml-cpp-master/include/yaml-cpp/noexcept.h \
    yaml-cpp-master/include/yaml-cpp/null.h \
    yaml-cpp-master/include/yaml-cpp/ostream_wrapper.h \
    yaml-cpp-master/include/yaml-cpp/parser.h \
    yaml-cpp-master/include/yaml-cpp/stlemitter.h \
    yaml-cpp-master/include/yaml-cpp/traits.h \
    yaml-cpp-master/include/yaml-cpp/yaml.h

FORMS += \
    mainwindow.ui


# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

win32:CONFIG(release, debug|release): LIBS += -L$$PWD/yaml-cpp-master/build/release/ -lyaml-cpp
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/yaml-cpp-master/build/debug/ -lyaml-cpp
else:unix: LIBS += -L$$PWD/yaml-cpp-master/build/ -lyaml-cpp

INCLUDEPATH += $$PWD/yaml-cpp-master/build
DEPENDPATH += $$PWD/yaml-cpp-master/build

win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$PWD/yaml-cpp-master/build/release/libyaml-cpp.a
else:win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$PWD/yaml-cpp-master/build/debug/libyaml-cpp.a
else:win32:!win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$PWD/yaml-cpp-master/build/release/yaml-cpp.lib
else:win32:!win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$PWD/yaml-cpp-master/build/debug/yaml-cpp.lib
else:unix: PRE_TARGETDEPS += $$PWD/yaml-cpp-master/build/libyaml-cpp.a
