#ifndef CASCADE_H
#define CASCADE_H

#include <QJsonObject>
#include <QMetaObject>
#include <QMetaProperty>
#include "cascade_global.h"

class CASCADESHARED_EXPORT Cascade
{

public:
    Cascade();

    template <typename T>
    static T from(const QJsonObject &obj) {
        T result = T();
        const QMetaObject metaObject = T::staticMetaObject;
        from(&result, obj, metaObject);
        return result;
    }

private:
    static void from(void *target, const QJsonObject &obj, const QMetaObject &targetMetaObject);
};

#endif // CASCADE_H
