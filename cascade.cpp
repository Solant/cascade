#include "cascade.h"


Cascade::Cascade()
{
}

void Cascade::from(void *target, const QJsonObject &obj, const QMetaObject &targetMetaObject)
{
    int props = targetMetaObject.propertyCount();
    for (int i = 0; i < props; i++) {
        const auto prop = targetMetaObject.property(i);
        const auto name = prop.name();
        if (obj.contains(name)) {
            prop.writeOnGadget(target, obj.value(name).toVariant());
        }
    }
}
