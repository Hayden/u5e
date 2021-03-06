#include "gtest/gtest.h"

#include <functional>
#include <iterator>
#include <string>
#include <sstream>

#include <u5e/codepoint.hpp>
#include <u5e/utf8_string.hpp>
#include <u5e/utf8_string_grapheme_iterator.hpp>
#include <u5e/utf8_string_grapheme.hpp>
#include <u5e/filter.hpp>

static int first_codepoint_in_grapheme(u5e::utf8_string_grapheme g,
                                       u5e::utf8_string& output) {
  u5e::utf8_string::const_iterator b = g.codepoint_begin();
  u5e::utf8_string::const_iterator e = b;
  e++;
  output.append(b,e);
  return 1;
}

TEST(t_008_filter, basic) { 
  u5e::utf8_string str("Ola\xCC\x81!");

  u5e::utf8_string output;

  int count = u5e::filter(str.grapheme_begin(),
                          str.grapheme_end(),
                          output, first_codepoint_in_grapheme);
  ASSERT_EQ(count, 4);
  ASSERT_STREQ(output.native_string.c_str(), "Ola!");
};
