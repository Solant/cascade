# cascade
<a href="https://travis-ci.org/Solant/cascade"><img src="https://travis-ci.org/Solant/cascade.svg?branch=master" alt="Build Status"></a>
<img src="https://ci.appveyor.com/api/projects/status/692i7dilpws4tfhn/branch/master?svg=true" alt="Build Status">


Cascade is library for serialization and deserialization of QObjects and Gadgets.

Usage example:
```
// Gadget.h
#include <QObject>

class PlainGadget {
    Q_GADGET

    Q_PROPERTY(int propInt MEMBER propInt)
    Q_PROPERTY(QString propString MEMBER propString)
    Q_PROPERTY(bool propBool MEMBER propBool)

public:
    int propInt = 0;
    QString propString = 0;
    bool propBool = 0;
};


// main.cpp
#include "cascade.h"

auto json = QJsonObject {
        {"propInt", 1},
        {"propString", "qwerty"},
        {"propBool", true},
    };
auto result = Cascade::from<PlainGadget>(json);
// result.propInt == 1
// result.propString == "qwerty"
// result.propBool == true
```
