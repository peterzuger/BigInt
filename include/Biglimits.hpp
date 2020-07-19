/**
 * @file   BigInt/include/BigLimits.hpp
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
#ifndef BIGINT_BIGLIMITS_HPP
#define BIGINT_BIGLIMITS_HPP

#include "BigInt.hpp"
#include "BigUint.hpp"
#include "BigFloat.hpp"

namespace std{
    template<std::size_t N>
    class numeric_limits<Big::BigInt<N>>{
    public:
        using value_type = Big::BigInt<N>;

        static constexpr bool is_specialized = true;

        static constexpr value_type min()    noexcept { return ~value_type(); }
        static constexpr value_type max()    noexcept { return -min(); }
        static constexpr value_type lowest() noexcept { return min(); }

        static constexpr int digits       = static_cast<int>( N * sizeof(std::uint8_t) );
        static constexpr int digits10     = digits * 3 / 10;
        static constexpr int max_digits10 = 0;
        static constexpr bool is_signed   = true;
        static constexpr bool is_integer  = true;
        static constexpr bool is_exact    = true;
        static constexpr int radix        = 2;
        static constexpr value_type epsilon()     noexcept { return value_type(); }
        static constexpr value_type round_error() noexcept { return value_type(); }

        static constexpr int min_exponent   = 0;
        static constexpr int min_exponent10 = 0;
        static constexpr int max_exponent   = 0;
        static constexpr int max_exponent10 = 0;

        static constexpr bool has_infinity             = false;
        static constexpr bool has_quiet_NaN            = false;
        static constexpr bool has_signaling_NaN        = false;
        static constexpr float_denorm_style has_denorm = denorm_absent;
        static constexpr bool has_denorm_loss          = false;
        static constexpr value_type infinity()      noexcept { return value_type(); }
        static constexpr value_type quiet_NaN()     noexcept { return value_type(); }
        static constexpr value_type signaling_NaN() noexcept { return value_type(); }
        static constexpr value_type denorm_min()    noexcept { return value_type(); }

        static constexpr bool is_iec559  = false;
        static constexpr bool is_bounded = true;
        static constexpr bool is_modulo  = false;

        static constexpr bool traps                    = false;
        static constexpr bool tinyness_before          = false;
        static constexpr float_round_style round_style = round_toward_zero;
    };


    template<std::size_t N>
    class numeric_limits<Big::BigUint<N>>{
    public:
        using value_type = Big::BigUint<N>;

        static constexpr bool is_specialized = true;

        static constexpr value_type min()    noexcept { return value_type(); }
        static constexpr value_type max()    noexcept { return ~min(); }
        static constexpr value_type lowest() noexcept { return min(); }

        static constexpr int digits       = static_cast<int>( N * sizeof(std::uint8_t) );
        static constexpr int digits10     = digits * 3 / 10;
        static constexpr int max_digits10 = 0;
        static constexpr bool is_signed   = false;
        static constexpr bool is_integer  = true;
        static constexpr bool is_exact    = true;
        static constexpr int radix        = 2;
        static constexpr value_type epsilon()     noexcept { return value_type(); }
        static constexpr value_type round_error() noexcept { return value_type(); }

        static constexpr int min_exponent   = 0;
        static constexpr int min_exponent10 = 0;
        static constexpr int max_exponent   = 0;
        static constexpr int max_exponent10 = 0;

        static constexpr bool has_infinity             = false;
        static constexpr bool has_quiet_NaN            = false;
        static constexpr bool has_signaling_NaN        = false;
        static constexpr float_denorm_style has_denorm = denorm_absent;
        static constexpr bool has_denorm_loss          = false;
        static constexpr value_type infinity()      noexcept { return value_type(); }
        static constexpr value_type quiet_NaN()     noexcept { return value_type(); }
        static constexpr value_type signaling_NaN() noexcept { return value_type(); }
        static constexpr value_type denorm_min()    noexcept { return value_type(); }

        static constexpr bool is_iec559  = false;
        static constexpr bool is_bounded = true;
        static constexpr bool is_modulo  = false;

        static constexpr bool traps                    = false;
        static constexpr bool tinyness_before          = false;
        static constexpr float_round_style round_style = round_toward_zero;
    };


    template<std::size_t p, int b, std::size_t r>
    class numeric_limits<Big::BigFloat<p, b, r>>{
    public:
        using value_type = Big::BigFloat<p, b, r>;

        static constexpr bool is_specialized = true;

        static constexpr value_type min()    noexcept { return 0; }
        static constexpr value_type max()    noexcept { return 0; }
        static constexpr value_type lowest() noexcept { return 0; }

        static constexpr int digits       = 0;
        static constexpr int digits10     = 0;
        static constexpr int max_digits10 = 0;
        static constexpr bool is_signed   = true;
        static constexpr bool is_integer  = false;
        static constexpr bool is_exact    = false;
        static constexpr int radix        = b;
        static constexpr value_type epsilon()     noexcept { return value_type(); }
        static constexpr value_type round_error() noexcept { return value_type(); }

        static constexpr int min_exponent   = 0;
        static constexpr int min_exponent10 = 0;
        static constexpr int max_exponent   = 0;
        static constexpr int max_exponent10 = 0;

        static constexpr bool has_infinity             = false;
        static constexpr bool has_quiet_NaN            = false;
        static constexpr bool has_signaling_NaN        = false;
        static constexpr float_denorm_style has_denorm = denorm_absent;
        static constexpr bool has_denorm_loss          = false;
        static constexpr value_type infinity()      noexcept { return value_type(); }
        static constexpr value_type quiet_NaN()     noexcept { return value_type(); }
        static constexpr value_type signaling_NaN() noexcept { return value_type(); }
        static constexpr value_type denorm_min()    noexcept { return value_type(); }

        static constexpr bool is_iec559  = false;
        static constexpr bool is_bounded = true;
        static constexpr bool is_modulo  = false;

        static constexpr bool traps                    = false;
        static constexpr bool tinyness_before          = false;
        static constexpr float_round_style round_style = round_toward_zero;
    };
};

#endif /* BIGINT_BIGLIMITS_HPP */
