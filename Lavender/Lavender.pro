QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    baseanimalfarm.cpp \
    baseestablish.cpp \
    basefarm.cpp \
    basesilo.cpp \
    basestorage.cpp \
    baseupgrade.cpp \
    baseuser.cpp \
    courtgame.cpp \
    dairyfarm.cpp \
    dairyfarmbuilding.cpp \
    daynight.cpp \
    hayfarm.cpp \
    hayfarmbuilding.cpp \
    levelup.cpp \
    lockdairyfarm.cpp \
    lockhayfarm.cpp \
    lockpoultryfarm.cpp \
    locksheepfold.cpp \
    main.cpp \
    login.cpp \
    mainmenu.cpp \
    poultryfarm.cpp \
    poultryfarmbuilding.cpp \
    ranking.cpp \
    sheepfold.cpp \
    sheepfoldbuilding.cpp \
    shopbuilding.cpp \
    shop.cpp \
    signup.cpp \
    silo.cpp \
    silobuilding.cpp \
    storage.cpp \
    storagebuilding.cpp \
    user.cpp \
    wheatfarm.cpp \
    wheatfarmbuilding.cpp

HEADERS += \
    baseanimalfarm.h \
    baseestablish.h \
    basefarm.h \
    basesilo.h \
    basestorage.h \
    baseupgrade.h \
    baseuser.h \
    courtgame.h \
    dairyfarm.h \
    dairyfarmbuilding.h \
    daynight.h \
    hayfarm.h \
    levelup.h \
    hayfarmbuilding.h \
    lockdairyfarm.h \
    lockhayfarm.h \
    lockpoultryfarm.h \
    locksheepfold.h \
    login.h \
    mainmenu.h \
    poultryfarm.h \
    poultryfarmbuilding.h \
    ranking.h \
    sheepfold.h \
    sheepfoldbuilding.h \
    shopbuilding.h \
    shop.h \
    signup.h \
    silo.h \
    silobuilding.h \
    storage.h \
    storagebuilding.h \
    user.h \
    wheatfarm.h \
    wheatfarmbuilding.h

FORMS += \
    courtgame.ui \
    dairyfarm.ui \
    daynight.ui \
    hayfarm.ui \
    levelup.ui \
    lockdairyfarm.ui \
    lockhayfarm.ui \
    lockpoultryfarm.ui \
    locksheepfold.ui \
    login.ui \
    mainmenu.ui \
    poultryfarm.ui \
    ranking.ui \
    sheepfold.ui \
    shop.ui \
    signup.ui \
    silo.ui \
    storage.ui \
    wheatfarm.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    gifs.qrc \
    pic.qrc

