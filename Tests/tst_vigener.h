#ifndef TST_VIGENER_H
#define TST_VIGENER_H

#include "icipher.h"
#include "ikeyedcipher.h"
#include "vigener.h"

#include <QString>
#include <gmock/gmock-matchers.h>
#include <gtest/gtest.h>

class VigenerF : public testing::Test
{
protected:
    void SetUp()
    {
        vigener = new Vigener("key", false);
    }
    void TearDown()
    {
        delete vigener;
    }
    Vigener *vigener = nullptr;
};

TEST_F(VigenerF, enLow)
{
    ASSERT_EQ("orevmqr", vigener->encrypt("english"));
}

TEST_F(VigenerF, enUpper)
{
    ASSERT_EQ("OREVMQR", vigener->encrypt("ENGLISH"));
}

TEST_F(VigenerF, enMixed)
{
    ASSERT_EQ("Orevmqr", vigener->encrypt("English"));
}

TEST_F(VigenerF, bigKey)
{
    vigener->setKey("megalongkey");
    QString actual = vigener->encrypt("key");
    ASSERT_EQ(QString("wie"), actual);
}

#endif // TST_VIGENER_H
