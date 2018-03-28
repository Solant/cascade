#ifndef CASCADE_GLOBAL_H
#define CASCADE_GLOBAL_H

#include <QtCore/qglobal.h>

#if defined(CASCADE_LIBRARY)
#  define CASCADESHARED_EXPORT Q_DECL_EXPORT
#else
#  define CASCADESHARED_EXPORT Q_DECL_IMPORT
#endif

#endif // CASCADE_GLOBAL_H
