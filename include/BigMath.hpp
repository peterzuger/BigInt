/**
 * @file   BigInt/include/BigMath.hpp
 * @author Peter Züger
 * @date   29.03.2020
 * @brief  Library for representing big integers
 *
 * The MIT License (MIT)
 *
 * Copyright (c) 2020 Philippe Peter
 * Copyright (c) 2020 Peter Züger
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
#ifndef BIGINT_BIGMATH_HPP
#define BIGINT_BIGMATH_HPP

#include "BigInt.hpp"
#include "BigUint.hpp"
#include "BigFloat.hpp"

namespace Big{
    template<std::size_t N> BigInt<N> abs(const BigInt<N>& x);
    template<std::size_t N> BigUint<N> abs(const BigUint<N>& x);
    template<std::size_t p, int b, std::size_t r> BigFloat<p, b, r> abs(const BigFloat<p, b, r>& x);

    template<std::size_t N> BigInt<N> sin(const BigInt<N>& x);
    template<std::size_t N> BigInt<N> cos(const BigInt<N>& x);
    template<std::size_t N> BigInt<N> tan(const BigInt<N>& x);
    template<std::size_t N> BigUint<N> sin(const BigUint<N>& x);
    template<std::size_t N> BigUint<N> cos(const BigUint<N>& x);
    template<std::size_t N> BigUint<N> tan(const BigUint<N>& x);
    template<std::size_t p, int b, std::size_t r> BigFloat<p, b, r> sin(const BigFloat<p, b, r>& x);
    template<std::size_t p, int b, std::size_t r> BigFloat<p, b, r> cos(const BigFloat<p, b, r>& x);
    template<std::size_t p, int b, std::size_t r> BigFloat<p, b, r> tan(const BigFloat<p, b, r>& x);

    template<std::size_t N> BigInt<N> sinh(const BigInt<N>& x);
    template<std::size_t N> BigInt<N> cosh(const BigInt<N>& x);
    template<std::size_t N> BigInt<N> tanh(const BigInt<N>& x);
    template<std::size_t N> BigUint<N> sinh(const BigUint<N>& x);
    template<std::size_t N> BigUint<N> cosh(const BigUint<N>& x);
    template<std::size_t N> BigUint<N> tanh(const BigUint<N>& x);
    template<std::size_t p, int b, std::size_t r> BigFloat<p, b, r> sinh(const BigFloat<p, b, r>& x);
    template<std::size_t p, int b, std::size_t r> BigFloat<p, b, r> cosh(const BigFloat<p, b, r>& x);
    template<std::size_t p, int b, std::size_t r> BigFloat<p, b, r> tanh(const BigFloat<p, b, r>& x);

    template<std::size_t N> BigInt<N> asin(const BigInt<N>& x);
    template<std::size_t N> BigInt<N> acos(const BigInt<N>& x);
    template<std::size_t N> BigInt<N> atan(const BigInt<N>& x);
    template<std::size_t N> BigUint<N> asin(const BigUint<N>& x);
    template<std::size_t N> BigUint<N> acos(const BigUint<N>& x);
    template<std::size_t N> BigUint<N> atan(const BigUint<N>& x);
    template<std::size_t p, int b, std::size_t r> BigFloat<p, b, r> asin(const BigFloat<p, b, r>& x);
    template<std::size_t p, int b, std::size_t r> BigFloat<p, b, r> acos(const BigFloat<p, b, r>& x);
    template<std::size_t p, int b, std::size_t r> BigFloat<p, b, r> atan(const BigFloat<p, b, r>& x);

    template<std::size_t N> BigInt<N> asinh(const BigInt<N>& x);
    template<std::size_t N> BigInt<N> acosh(const BigInt<N>& x);
    template<std::size_t N> BigInt<N> atanh(const BigInt<N>& x);
    template<std::size_t N> BigUint<N> asinh(const BigUint<N>& x);
    template<std::size_t N> BigUint<N> acosh(const BigUint<N>& x);
    template<std::size_t N> BigUint<N> atanh(const BigUint<N>& x);
    template<std::size_t p, int b, std::size_t r> BigFloat<p, b, r> asinh(const BigFloat<p, b, r>& x);
    template<std::size_t p, int b, std::size_t r> BigFloat<p, b, r> acosh(const BigFloat<p, b, r>& x);
    template<std::size_t p, int b, std::size_t r> BigFloat<p, b, r> atanh(const BigFloat<p, b, r>& x);

    template<std::size_t N> BigInt<N> exp(const BigInt<N>& x);
    template<std::size_t N> BigInt<N> exp2(const BigInt<N>& x);
    template<std::size_t N> BigInt<N> exp10(const BigInt<N>& x);
    template<std::size_t N> BigUint<N> exp(const BigUint<N>& x);
    template<std::size_t N> BigUint<N> exp2(const BigUint<N>& x);
    template<std::size_t N> BigUint<N> exp10(const BigUint<N>& x);
    template<std::size_t p, int b, std::size_t r> BigFloat<p, b, r> exp(const BigFloat<p, b, r>& x);
    template<std::size_t p, int b, std::size_t r> BigFloat<p, b, r> exp2(const BigFloat<p, b, r>& x);
    template<std::size_t p, int b, std::size_t r> BigFloat<p, b, r> exp10(const BigFloat<p, b, r>& x);

    template<std::size_t N> BigInt<N> log(const BigInt<N>& x);
    template<std::size_t N> BigInt<N> log2(const BigInt<N>& x);
    template<std::size_t N> BigInt<N> log10(const BigInt<N>& x);
    template<std::size_t p, int b, std::size_t r> BigFloat<p, b, r> log(const BigFloat<p, b, r>& x);
    template<std::size_t p, int b, std::size_t r> BigFloat<p, b, r> log2(const BigFloat<p, b, r>& x);
    template<std::size_t p, int b, std::size_t r> BigFloat<p, b, r> log10(const BigFloat<p, b, r>& x);

    template<std::size_t N> BigInt<N> hypot(const BigInt<N>& x, const BigInt<N>& y);
    template<std::size_t N> BigUint<N> hypot(const BigUint<N>& x, const BigUint<N>& y);
    template<std::size_t p, int b, std::size_t r> BigFloat<p, b, r> hypot(const BigFloat<p, b, r>& x, const BigFloat<p, b, r>& y);

    template<std::size_t N> BigInt<N> sqrt(const BigInt<N>& x);
    template<std::size_t N> BigUint<N> sqrt(const BigUint<N>& x);
    template<std::size_t p, int b, std::size_t r> BigFloat<p, b, r> sqrt(const BigFloat<p, b, r>& x);

    template<std::size_t N, class T> BigInt<N> pow(const BigInt<N>& base, const T& exp);
    template<std::size_t N, class T> BigInt<N> pow(const T& base, const BigInt<N>& exp);
    template<std::size_t N> BigInt<N> pow(const BigInt<N>& base, const BigInt<N>& exp);
    template<std::size_t N, class T> BigUint<N> pow(const BigUint<N>& base, const T& exp);
    template<std::size_t N, class T> BigUint<N> pow(const T& base, const BigUint<N>& exp);
    template<std::size_t N> BigUint<N> pow(const BigUint<N>& base, const BigUint<N>& exp);
    template<std::size_t p, int b, std::size_t r, class T> BigFloat<p, b, r> pow(const BigFloat<p, b, r>& base, const T& exp);
    template<std::size_t p, int b, std::size_t r, class T> BigFloat<p, b, r> pow(const T& base, const BigFloat<p, b, r>& exp);
    template<std::size_t p, int b, std::size_t r> BigFloat<p, b, r> pow(const BigFloat<p, b, r>& base, const BigFloat<p, b, r>& exp);
}

#endif /* BIGINT_BIGMATH_HPP */
