/**
 * @file   BigInt/include/BigUint.hpp
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
#ifndef BIGINT_BIGUINT_HPP
#define BIGINT_BIGUINT_HPP

#include <array>
#include <climits>
#include <istream>
#include <limits>
#include <ostream>

namespace Big{
    template<std::size_t N>
    class BigUint{
        static_assert(!(N % (sizeof(unsigned int) * CHAR_BIT)),
                      "Big::BigUint: N must be a multiple of 'sizeof(unsigned int) * CHAR_BIT'");

        std::array<unsigned int, N / (sizeof(unsigned int) * CHAR_BIT)> data;

    public:
        constexpr BigUint() = default;
        constexpr BigUint(const BigUint& other)noexcept;
        constexpr BigUint(BigUint&& other)noexcept;
        constexpr BigUint(unsigned long long other)noexcept;
        constexpr BigUint(float other)noexcept;
        constexpr BigUint(double other)noexcept;
        constexpr BigUint(long double other)noexcept;

        template<std::size_t M>
        constexpr BigUint(const BigUint<M>& other)noexcept;

        BigUint& operator=(const BigUint& other)noexcept;
        BigUint& operator=(BigUint&& other)noexcept;
        BigUint& operator=(unsigned long long other)noexcept;
        BigUint& operator=(float other)noexcept;
        BigUint& operator=(double other)noexcept;
        BigUint& operator=(long double other)noexcept;

        void swap(BigUint& other)noexcept;

        constexpr BigUint& operator~()noexcept;

        constexpr BigUint& operator+=(const BigUint& rhs)noexcept;
        constexpr BigUint& operator-=(const BigUint& rhs)noexcept;
        constexpr BigUint& operator*=(const BigUint& rhs)noexcept;
        constexpr BigUint& operator/=(const BigUint& rhs)noexcept;
        constexpr BigUint& operator%=(const BigUint& rhs)noexcept;
        constexpr BigUint& operator^=(const BigUint& rhs)noexcept;
        constexpr BigUint& operator&=(const BigUint& rhs)noexcept;
        constexpr BigUint& operator|=(const BigUint& rhs)noexcept;

        template <class IntType>constexpr BigUint& operator<<=(IntType shift)noexcept;
        template <class IntType>constexpr BigUint& operator>>=(IntType shift)noexcept;

        constexpr BigUint& operator++()noexcept;
        constexpr BigUint operator++(int)noexcept;
        constexpr BigUint& operator--()noexcept;
        constexpr BigUint operator--(int)noexcept;

        template<std::size_t M>
        friend std::ostream& operator<<(std::ostream& os, const BigUint<M>& obj);
        template<std::size_t M>
        friend std::istream& operator>>(std::istream& is, BigUint<M>& obj);
    };

    template<std::size_t N>
    std::ostream& operator<<(std::ostream& os, const BigUint<N>& obj){
        // write obj to stream
        return os;
    }

    template<std::size_t N>
    std::istream& operator>>(std::istream& is, BigUint<N>& obj){
        // read obj from stream
        if( /* T could not be constructed */ true )
            is.setstate(std::ios::failbit);
        return is;
    }

    template<std::size_t N>
    void swap(BigUint<N>& x, BigUint<N>& y)noexcept{
        x.swap(y);
    }

    template<std::size_t N>
    constexpr BigUint<N> operator+(BigUint<N> lhs, const BigUint<N>& rhs)noexcept{
        return lhs += rhs;
    }
    template<std::size_t N>
    constexpr BigUint<N> operator-(BigUint<N> lhs, const BigUint<N>& rhs)noexcept{
        return lhs -= rhs;
    }
    template<std::size_t N>
    constexpr BigUint<N> operator*(BigUint<N> lhs, const BigUint<N>& rhs)noexcept{
        return lhs *= rhs;
    }
    template<std::size_t N>
    constexpr BigUint<N> operator/(BigUint<N> lhs, const BigUint<N>& rhs)noexcept{
        return lhs /= rhs;
    }
    template<std::size_t N>
    constexpr BigUint<N> operator%(BigUint<N> lhs, const BigUint<N>& rhs)noexcept{
        return lhs %= rhs;
    }
    template<std::size_t N>
    constexpr BigUint<N> operator^(BigUint<N> lhs, const BigUint<N>& rhs)noexcept{
        return lhs ^= rhs;
    }
    template<std::size_t N>
    constexpr BigUint<N> operator&(BigUint<N> lhs, const BigUint<N>& rhs)noexcept{
        return lhs &= rhs;
    }
    template<std::size_t N>
    constexpr BigUint<N> operator|(BigUint<N> lhs, const BigUint<N>& rhs)noexcept{
        return lhs |= rhs;
    }

    template <std::size_t N, class IntType>
    constexpr BigUint<N> operator<<(const BigUint<N>& lhs, IntType shift)noexcept{
        return lhs <<= shift;
    }
    template <std::size_t N, class IntType>
    constexpr BigUint<N> operator>>(const BigUint<N>& lhs, IntType shift)noexcept{
        return lhs >>= shift;
    }


    template<std::size_t N>
    constexpr bool operator< (const BigUint<N>& lhs, const BigUint<N>& rhs) noexcept {
        return false; // TODO
    }
    template<std::size_t N>
    constexpr bool operator> (const BigUint<N>& lhs, const BigUint<N>& rhs) noexcept {
        return rhs < lhs;
    }
    template<std::size_t N>
    constexpr bool operator<=(const BigUint<N>& lhs, const BigUint<N>& rhs) noexcept {
        return !(lhs > rhs);
    }
    template<std::size_t N>
    constexpr bool operator>=(const BigUint<N>& lhs, const BigUint<N>& rhs) noexcept {
        return !(lhs < rhs);
    }

    template<std::size_t N>
    constexpr bool operator==(const BigUint<N>& lhs, const BigUint<N>& rhs) noexcept {
        return false;
    }
    template<std::size_t N>
    constexpr bool operator!=(const BigUint<N>& lhs, const BigUint<N>& rhs) noexcept {
        return !(lhs == rhs);
    }
};

#endif /* BIGINT_BIGUINT_HPP */
