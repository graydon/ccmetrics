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

#ifndef SRC_METRIC_REGISTRY_IMPL_H_
#define SRC_METRIC_REGISTRY_IMPL_H_

#include <map>
#include <mutex>
#include <string>
#include <unordered_map>

#include "ccmetrics/counter.h"
#include "ccmetrics/meter.h"
#include "ccmetrics/timer.h"

namespace ccmetrics {

template<typename T>
struct MetricMap {
    mutable std::mutex mutex; // Mutable for use in logically-const methods
    std::unordered_map<std::string, T*> metrics;
};

class MetricRegistryImpl {
public:
    MetricRegistryImpl();
    ~MetricRegistryImpl();

    /** @return a new or existing counter. */
    Counter* counter(std::string const& name);

    /** @return a new or existing timer. */
    Timer* timer(std::string const& name);

    /** @return a new or existing meter. */
    Meter* meter(std::string const& naem);

    /** @return all registered counter metrics. */
    std::map<std::string, Counter*> counters() const;

    /** @return all registered timer metrics. */
    std::map<std::string, Timer*> timers() const;

    /** @return all registered meters. */
    std::map<std::string, Meter*> meters() const;
private:
    MetricMap<Counter> counters_;
    MetricMap<Timer> timers_;
    MetricMap<Meter> meters_;
};

} // ccmetrics namespace

#endif // SRC_METRIC_REGISTRY_IMPL_H_
