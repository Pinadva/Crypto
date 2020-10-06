#include "tst_cesar.h"

#include <QString>
#include <gtest/gtest.h>
#include <string>

QT_BEGIN_NAMESPACE
inline void PrintTo(const QString &str, ::std::wostream *os)
{
    *os << qUtf8Printable(str);
}
QT_END_NAMESPACE

int main(int argc, char *argv[])
{
    setlocale(LC_ALL, "Russian");
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
