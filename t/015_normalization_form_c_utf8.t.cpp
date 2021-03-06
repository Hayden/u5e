#include "gtest/gtest.h"

#include <u5e/utf8_string.hpp>
#include <u5e/filter.hpp>
#include <u5e/normalization_form_c.hpp>

TEST(t_013_normalization_form_c_utf8, basic) { 
  u5e::utf8_string str("A\xCC\x88!");
  u5e::utf8_string output;
  int count =
    u5e::filter(str.grapheme_begin(), str.grapheme_end(),
                output,
                u5e::normalization_form_c<u5e::utf8_string>);
  ASSERT_EQ(2, count);
  ASSERT_STREQ("\xC3\x84!", output.native_string.c_str());
};
