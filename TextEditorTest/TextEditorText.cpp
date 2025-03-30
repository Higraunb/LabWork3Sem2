#include "HTextEditor.h"
#include "HConsole.h"
#include <gtest.h>

TEST(TString, can_create_String)
{
  ASSERT_NO_THROW(TString a);
}

TEST(TString, can_create_const_char)
{
  ASSERT_NO_THROW(TString a("pfpfp"));
}

TEST(TString, can_create_len_char)
{
  ASSERT_NO_THROW(TString a(5, "qweqw"));
}

TEST(TString, can_not_create_len_char)
{
  ASSERT_ANY_THROW(TString a(3, "qweqw"));
}

TEST(TString, can_create_const_TString)
{
  ASSERT_NO_THROW(TString a("ddd"), d(a));
}

TEST(TString, can_GetLen)
{
  TString a(3,"qwe");
  EXPECT_NEAR(3, a.GetLen(), 0.00001);
}

TEST(TString, can_GetStr)
{
  TString a("qwe");
  EXPECT_STREQ("qwe", a.GetStr());
}

TEST(TString, can_SetLen_len_less)
{
  TString a(3,"qwe");
  a.SetLen(2);
  EXPECT_STREQ("qw", a.GetStr());
  EXPECT_NEAR(2, a.GetLen(), 0.00001);
}

TEST(TString, can_SetLen_len_more)
{
  TString a(3, "qwe");
  a.SetLen(4);
  EXPECT_STREQ("qwe0", a.GetStr());
  EXPECT_NEAR(4, a.GetLen(), 0.00001);
}

TEST(TString, can_SetStr_str_less)
{
  TString a(3, "qwe");
  a.SetStr("qw");
  EXPECT_STREQ("qw", a.GetStr());
  EXPECT_NEAR(2, a.GetLen(), 0.00001);
}

TEST(TString, can_SetStr_str_more)
{
  TString a(3, "qwe");
  a.SetStr("qwer");
  EXPECT_STREQ("qwer", a.GetStr());
  EXPECT_NEAR(4, a.GetLen(), 0.00001);
}

TEST(TString, can_String_)
{
  TString a(3, "qwe");
  a.SetStr("qwer");
  EXPECT_STREQ("qwer", a.GetStr());
  EXPECT_NEAR(4, a.GetLen(), 0.00001);
}

TEST(TConsole, can_create_Console)
{
  ASSERT_NO_THROW(TConsole a);
}

TEST(TConsole, can_Console_create_x_y)
{
  ASSERT_NO_THROW(TConsole a(3, 4));
}

TEST(TConsole, can_Console_GetX)
{
  TConsole a(3, 4);
  EXPECT_NEAR(3, a.GetX(), 0.00001);
}

TEST(TConsole, can_Console_GetY)
{
  TConsole a(3, 4);
  EXPECT_NEAR(4, a.GetY(), 0.00001);
}

TEST(TConsole, can_Console_SetX)
{
  TConsole a;
  a.SetX(4);
  EXPECT_NEAR(4, a.GetX(), 0.00001);
}

TEST(TConsole, can_Console_SetY)
{
  TConsole a;
  a.SetY(4);
  EXPECT_NEAR(4, a.GetY(), 0.00001);
}