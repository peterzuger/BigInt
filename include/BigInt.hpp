/**
 * @file   BigInt/include/BigInt.hpp
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
#ifndef BIGINT_BIGINT_HPP
#define BIGINT_BIGINT_HPP

#include <array>
#include <climits>
#include <istream>
#include <limits>
#include <ostream>

namespace Big{
    template<std::size_t N>
    class BigInt{
        static_assert(!(N % (sizeof(unsigned int) * CHAR_BIT)),
                      "Big::BigInt: N must be a multiple of 'sizeof(unsigned int) * CHAR_BIT'");

        std::array<unsigned int, N / (sizeof(unsigned int) * CHAR_BIT)> data;

    public:
        constexpr BigInt() = default;
        constexpr BigInt(const BigInt& other)noexcept;
        constexpr BigInt(BigInt&& other)noexcept;
        constexpr BigInt(long long other)noexcept;
        constexpr BigInt(unsigned long long other)noexcept;
        constexpr BigInt(float other)noexcept;
        constexpr BigInt(double other)noexcept;
        constexpr BigInt(long double other)noexcept;

        template<std::size_t M>
        constexpr BigInt(const BigInt<M>& other)noexcept;

        BigInt& operator=(const BigInt& other)noexcept;
        BigInt& operator=(BigInt&& other)noexcept;
        BigInt& operator=(long long other)noexcept;
        BigInt& operator=(unsigned long long other)noexcept;
        BigInt& operator=(float other)noexcept;
        BigInt& operator=(double other)noexcept;
        BigInt& operator=(long double other)noexcept;

        void swap(BigInt& other)noexcept;

        constexpr BigInt& operator~()noexcept;
        constexpr BigInt& operator-()noexcept;

        constexpr BigInt& operator+=(const BigInt& rhs)noexcept;
        constexpr BigInt& operator-=(const BigInt& rhs)noexcept;
        constexpr BigInt& operator*=(const BigInt& rhs)noexcept;
        constexpr BigInt& operator/=(const BigInt& rhs)noexcept;
        constexpr BigInt& operator%=(const BigInt& rhs)noexcept;
        constexpr BigInt& operator^=(const BigInt& rhs)noexcept;
        constexpr BigInt& operator&=(const BigInt& rhs)noexcept;
        constexpr BigInt& operator|=(const BigInt& rhs)noexcept;

        template <class IntType>constexpr BigInt& operator<<=(IntType shift)noexcept;
        template <class IntType>constexpr BigInt& operator>>=(IntType shift)noexcept;

        constexpr BigInt& operator++()noexcept;
        constexpr BigInt operator++(int)noexcept;
        constexpr BigInt& operator--()noexcept;
        constexpr BigInt operator--(int)noexcept;

        template<std::size_t M>
        friend std::ostream& operator<<(std::ostream& os, const BigInt<M>& obj);
        template<std::size_t M>
        friend std::istream& operator>>(std::istream& is, BigInt<M>& obj);
    };

    template<std::size_t N>
    std::ostream& operator<<(std::ostream& os, const BigInt<N>& obj){
        // write obj to stream
        return os;
    }

    template<std::size_t N>
    std::istream& operator>>(std::istream& is, BigInt<N>& obj){
        // read obj from stream
        if( /* T could not be constructed */ true )
            is.setstate(std::ios::failbit);
        return is;
    }

    template<std::size_t N>
    void swap(BigInt<N>& x, BigInt<N>& y)noexcept{
        x.swap(y);
    }

    template<std::size_t N>
    constexpr BigInt<N> operator+(BigInt<N> lhs, const BigInt<N>& rhs)noexcept{
        return lhs += rhs;
    }
    template<std::size_t N>
    constexpr BigInt<N> operator-(BigInt<N> lhs, const BigInt<N>& rhs)noexcept{
        return lhs -= rhs;
    }
    template<std::size_t N>
    constexpr BigInt<N> operator*(BigInt<N> lhs, const BigInt<N>& rhs)noexcept{
        return lhs *= rhs;
    }
    template<std::size_t N>
    constexpr BigInt<N> operator/(BigInt<N> lhs, const BigInt<N>& rhs)noexcept{
        return lhs /= rhs;
    }
    template<std::size_t N>
    constexpr BigInt<N> operator%(BigInt<N> lhs, const BigInt<N>& rhs)noexcept{
        return lhs %= rhs;
    }
    template<std::size_t N>
    constexpr BigInt<N> operator^(BigInt<N> lhs, const BigInt<N>& rhs)noexcept{
        return lhs ^= rhs;
    }
    template<std::size_t N>
    constexpr BigInt<N> operator&(BigInt<N> lhs, const BigInt<N>& rhs)noexcept{
        return lhs &= rhs;
    }
    template<std::size_t N>
    constexpr BigInt<N> operator|(BigInt<N> lhs, const BigInt<N>& rhs)noexcept{
        return lhs |= rhs;
    }

    template <std::size_t N, class IntType>
    constexpr BigInt<N> operator<<(const BigInt<N>& lhs, IntType shift)noexcept{
        return lhs <<= shift;
    }
    template <std::size_t N, class IntType>
    constexpr BigInt<N> operator>>(const BigInt<N>& lhs, IntType shift)noexcept{
        return lhs >>= shift;
    }


    template<std::size_t N>
    constexpr bool operator< (const BigInt<N>& lhs, const BigInt<N>& rhs) noexcept {
        return false; // TODO
    }
    template<std::size_t N>
    constexpr bool operator> (const BigInt<N>& lhs, const BigInt<N>& rhs) noexcept {
        return rhs < lhs;
    }
    template<std::size_t N>
    constexpr bool operator<=(const BigInt<N>& lhs, const BigInt<N>& rhs) noexcept {
        return !(lhs > rhs);
    }
    template<std::size_t N>
    constexpr bool operator>=(const BigInt<N>& lhs, const BigInt<N>& rhs) noexcept {
        return !(lhs < rhs);
    }

    template<std::size_t N>
    constexpr bool operator==(const BigInt<N>& lhs, const BigInt<N>& rhs) noexcept {
        return false;
    }
    template<std::size_t N>
    constexpr bool operator!=(const BigInt<N>& lhs, const BigInt<N>& rhs) noexcept {
        return !(lhs == rhs);
    }
};

#endif /* BIGINT_BIGINT_HPP */
