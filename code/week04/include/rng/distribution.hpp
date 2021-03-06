#pragma once

#include "rng.hpp"

namespace lcsc {

/**
 * A distribution takes the random integers that are generated by an engine, and
 * transforms them to effectively sample according to a given distribution.
 */
template <typename T>
class distribution {
  public:
    /** Sample according to the distribution */
    virtual T sample() = 0;
};

/**
 * A uniform distribution on a real interval $[a, b]$.
 */
template <typename T, typename U>
class uniform_distribution : public distribution<T> {
  public:
    /** Initialize the distribution with an engine, $a$, and $b$. */
    uniform_distribution(T a, T b, rng<U>& engine)
        : a_(a), b_(b), engine_(engine) {}

    T sample() override {
        auto u = ((T)engine_.next() / engine_.max());
        return a_ + (b_ - a_) * u;
    }

  private:
    T a_;
    T b_;
    rng<U>& engine_;
};

} // namespace lcsc
