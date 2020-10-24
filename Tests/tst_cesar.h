#ifndef TST_CESAR_H
#define TST_CESAR_H

#include "alphabets.h"
#include "cesar.h"
#include "icipher.h"

#include <QString>
#include <gmock/gmock-matchers.h>
#include <gtest/gtest.h>

TEST(Cesar, enUpShift1)
{
    Cesar cesar(true, 1);
    ASSERT_EQ("HPE", cesar.encrypt("GOD"));
}
TEST(Cesar, enUpOverflow)
{
    Cesar cesar(true, 20);
    ASSERT_EQ("AIX", cesar.encrypt("GOD"));
}

TEST(Cesar, enLowShift1)
{
    Cesar cesar(true, 1);
    ASSERT_EQ("hpe", cesar.encrypt("god"));
}
TEST(Cesar, enLowOverflow)
{
    Cesar cesar(true, 20);
    ASSERT_EQ("aix", cesar.encrypt("god"));
}

#endif // TST_CESAR_H
