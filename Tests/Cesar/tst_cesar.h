#ifndef TST_CESAR_H
#define TST_CESAR_H

#include "cesar.h"
#include "icipher.h"

#include <QString>
#include <gmock/gmock-matchers.h>
#include <gtest/gtest.h>

TEST(Cesar, enUpShift1)
{
    Cesar cesar(1, true);
    ASSERT_EQ("HPE", cesar.encrypt("GOD"));
}
TEST(Cesar, enUpOverflow)
{
    Cesar cesar(20, true);
    ASSERT_EQ("AIX", cesar.encrypt("GOD"));
}

TEST(Cesar, enLowShift1)
{
    Cesar cesar(1, true);
    ASSERT_EQ("hpe", cesar.encrypt("god"));
}
TEST(Cesar, enLowOverflow)
{
    Cesar cesar(20, true);
    ASSERT_EQ("aix", cesar.encrypt("god"));
}

#endif // TST_CESAR_H
