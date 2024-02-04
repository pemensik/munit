/* µnit Testing Framework
 * Copyright (c) 2013-2017 Evan Nemerson <evan@nemerson.com>
 * Copyright (c) 2023 munit contributors
 *
 * Permission is hereby granted, free of charge, to any person
 * obtaining a copy of this software and associated documentation
 * files (the "Software"), to deal in the Software without
 * restriction, including without limitation the rights to use, copy,
 * modify, merge, publish, distribute, sublicense, and/or sell copies
 * of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be
 * included in all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
 * EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
 * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND
 * NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS
 * BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN
 * ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN
 * CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 */

#ifndef MUNITXX_H
#define MUNITXX_H

#include <munit.h>

#include <string>

#define assert_stdstring_equal(a, b)                                           \
  do {                                                                         \
    const std::string munit_tmp_a_ = a;                                        \
    const std::string munit_tmp_b_ = b;                                        \
    if (MUNIT_UNLIKELY(a != b)) {                                              \
      munit_hexdump_diff(stderr, munit_tmp_a_.c_str(), munit_tmp_a_.size(),    \
                         munit_tmp_b_.c_str(), munit_tmp_b_.size());           \
      munit_errorf("assertion failed: string %s == %s (\"%s\" == \"%s\")", #a, \
                   #b, munit_tmp_a_.c_str(), munit_tmp_b_.c_str());            \
    }                                                                          \
    MUNIT_PUSH_DISABLE_MSVC_C4127_                                             \
  } while (0) MUNIT_POP_DISABLE_MSVC_C4127_

#endif // MUNITXX_H
