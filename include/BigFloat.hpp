/**
 * @file   BigInt/include/BigFloat.hpp
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
#ifndef BIGINT_BIGFLOAT_HPP
#define BIGINT_BIGFLOAT_HPP

#include <array>
#include <climits>
#include <istream>
#include <limits>
#include <ostream>

namespace Big{
    /**
     * represents an arbitraryly big IEEE754 float
     * in the form:
     *   x = s * m * b ^ e
     *   s sign
     *   m mantissa (p bits long)
     *   b radix (base = 2)
     *   e exponent (r bits long)
     */
    template<std::size_t p, int b, std::size_t r>
    class BigFloat{
        bool s;

    public:
        constexpr BigFloat() = default;
        constexpr BigFloat(const BigFloat& other)noexcept;
        constexpr BigFloat(BigFloat&& other)noexcept;
        constexpr BigFloat(long long other)noexcept;
        constexpr BigFloat(unsigned long long other)noexcept;
        constexpr BigFloat(float other)noexcept;
        constexpr BigFloat(double other)noexcept;
        constexpr BigFloat(long double other)noexcept;

        BigFloat& operator=(const BigFloat& other)noexcept;
        BigFloat& operator=(BigFloat&& other)noexcept;
        BigFloat& operator=(long long other)noexcept;
        BigFloat& operator=(unsigned long long other)noexcept;
        BigFloat& operator=(float other)noexcept;
        BigFloat& operator=(double other)noexcept;
        BigFloat& operator=(long double other)noexcept;

        void swap(BigFloat& other)noexcept;

        constexpr BigFloat& operator-()noexcept;

        constexpr BigFloat& operator+=(const BigFloat& rhs)noexcept;
        constexpr BigFloat& operator-=(const BigFloat& rhs)noexcept;
        constexpr BigFloat& operator*=(const BigFloat& rhs)noexcept;
        constexpr BigFloat& operator/=(const BigFloat& rhs)noexcept;
        constexpr BigFloat& operator%=(const BigFloat& rhs)noexcept;
        constexpr BigFloat& operator^=(const BigFloat& rhs)noexcept;
        constexpr BigFloat& operator&=(const BigFloat& rhs)noexcept;
        constexpr BigFloat& operator|=(const BigFloat& rhs)noexcept;

        constexpr BigFloat& operator++()noexcept;
        constexpr BigFloat operator++(int)noexcept;
        constexpr BigFloat& operator--()noexcept;
        constexpr BigFloat operator--(int)noexcept;

        template<std::size_t P, int B, std::size_t R>
        friend std::ostream& operator<<(std::ostream& os, const BigFloat<P, B, R>& obj);
        template<std::size_t P, int B, std::size_t R>
        friend std::istream& operator>>(std::istream& is, BigFloat<P, B, R>& obj);
    };

    template<std::size_t p, int b, std::size_t r>
    std::ostream& operator<<(std::ostream& os, const BigFloat<p, b, r>& obj){
        // write obj to stream
        return os;
    }

    template<std::size_t p, int b, std::size_t r>
    std::istream& operator>>(std::istream& is, BigFloat<p, b, r>& obj){
        // read obj from stream
        if( /* T could not be constructed */ true )
            is.setstate(std::ios::failbit);
        return is;
    }

    template<std::size_t p, int b, std::size_t r>
    void swap(BigFloat<p, b, r>& x, BigFloat<p, b, r>& y)noexcept{
        x.swap(y);
    }

    template<std::size_t p, int b, std::size_t r>
    constexpr BigFloat<p, b, r> operator+(BigFloat<p, b, r> lhs, const BigFloat<p, b, r>& rhs)noexcept{
        return lhs += rhs;
    }
    template<std::size_t p, int b, std::size_t r>
    constexpr BigFloat<p, b, r> operator-(BigFloat<p, b, r> lhs, const BigFloat<p, b, r>& rhs)noexcept{
        return lhs -= rhs;
    }
    template<std::size_t p, int b, std::size_t r>
    constexpr BigFloat<p, b, r> operator*(BigFloat<p, b, r> lhs, const BigFloat<p, b, r>& rhs)noexcept{
        return lhs *= rhs;
    }
    template<std::size_t p, int b, std::size_t r>
    constexpr BigFloat<p, b, r> operator/(BigFloat<p, b, r> lhs, const BigFloat<p, b, r>& rhs)noexcept{
        return lhs /= rhs;
    }
    template<std::size_t p, int b, std::size_t r>
    constexpr BigFloat<p, b, r> operator%(BigFloat<p, b, r> lhs, const BigFloat<p, b, r>& rhs)noexcept{
        return lhs %= rhs;
    }


    template<std::size_t p, int b, std::size_t r>
    constexpr bool operator< (const BigFloat<p, b, r>& lhs, const BigFloat<p, b, r>& rhs)noexcept{
        return false; // TODO
    }
    template<std::size_t p, int b, std::size_t r>
    constexpr bool operator> (const BigFloat<p, b, r>& lhs, const BigFloat<p, b, r>& rhs)noexcept{
        return rhs < lhs;
    }
    template<std::size_t p, int b, std::size_t r>
    constexpr bool operator<=(const BigFloat<p, b, r>& lhs, const BigFloat<p, b, r>& rhs)noexcept{
        return !(lhs > rhs);
    }
    template<std::size_t p, int b, std::size_t r>
    constexpr bool operator>=(const BigFloat<p, b, r>& lhs, const BigFloat<p, b, r>& rhs)noexcept{
        return !(lhs < rhs);
    }

    template<std::size_t p, int b, std::size_t r>
    constexpr bool operator==(const BigFloat<p, b, r>& lhs, const BigFloat<p, b, r>& rhs)noexcept{
        return false; // TODO
    }
    template<std::size_t p, int b, std::size_t r>
    constexpr bool operator!=(const BigFloat<p, b, r>& lhs, const BigFloat<p, b, r>& rhs)noexcept{
        return !(lhs == rhs);
    }
};

#endif /* BIGINT_BIGFLOAT_HPP */
