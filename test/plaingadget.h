#ifndef PLAINGADGET_H
#define PLAINGADGET_H

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

#endif // PLAINGADGET_H
