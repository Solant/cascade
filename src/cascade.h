#ifndef CASCADE_H
#define CASCADE_H

#include <QJsonObject>
#include <QMetaObject>
#include <QMetaProperty>
#include <QDebug>

class Cascade
{

public:
    Cascade();

    template <typename T>
    static T from(const QJsonObject &obj)
    {
        T result = T();
        const QMetaObject metaObject = T::staticMetaObject;
        from(&result, obj, metaObject);
        return result;
    }

private:
    static void from(void *target, const QJsonObject &obj, const QMetaObject &targetMetaObject)
    {
        int props = targetMetaObject.propertyCount();
        for (int i = 0; i < props; i++) {
            const auto &prop = targetMetaObject.property(i);
            const auto &name = prop.name();
            if (obj.contains(name)) {
                const QJsonValue &value = obj.value(name);
                if (
                    value.isArray()
                    || value.isObject()
                ) {
                    qWarning() << "Nested object deserialization is not supported";
                }
                prop.writeOnGadget(target, value.toVariant());
            }
        }
    }
};

#endif // CASCADE_H
