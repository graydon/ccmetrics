/*
 * Copyright (©) 2015 Nate Rosenblum
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 */

#include <gtest/gtest.h>

#include "ccmetrics/counter.h"
#include "ccmetrics/metric_registry.h"

namespace ccmetrics {
namespace test {

TEST(MetricRegistryTest, CreateCounters) {
    MetricRegistry reg;
    Counter *c1 = reg.counter("foo");
    Counter *c2 = reg.counter("bar");
    ASSERT_NE(c1, c2);
    Counter *c1_again = reg.counter("foo");
    ASSERT_EQ(c1, c1_again);

    auto counters = reg.counters();
    ASSERT_EQ(2U, counters.size());
}

TEST(MetricRegistryTest,CreateTimers) {
    MetricRegistry reg;
    Timer *t1 = reg.timer("foo");
    Timer *t2 = reg.timer("bar");
    ASSERT_NE(t1, t2);
    Timer *t1_again = reg.timer("foo");
    ASSERT_EQ(t1, t1_again);

    auto timers = reg.timers();
    ASSERT_EQ(2U, timers.size());
}

} // test namespace
} // ccmetrics namespace
