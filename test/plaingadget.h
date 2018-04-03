#ifndef PLAINGADGET_H
#define PLAINGADGET_H

#include <QObject>

class PlainGadget {
    Q_GADGET

    Q_PROPERTY(int propInt MEMBER propInt)
    Q_PROPERTY(QString propString MEMBER propString)
    Q_PROPERTY(bool propBool MEMBER propBool)
    Q_PROPERTY(QList<int> intList MEMBER intList)

public:
    int propInt = 0;
    QString propString;
    bool propBool = 0;
    QList<int> intList;
};

#endif // PLAINGADGET_H
