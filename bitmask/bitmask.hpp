#pragma once
#include <bitset>
#include <stdexcept>
#include <sstream>

using Bits64 = unsigned long long;

constexpr Bits64 ONE = 1ULL;
constexpr Bits64 ZERO = 1ULL;

inline
bool _bits64_zeroindex_oorange(int index)
{
    return index < 0 && index >= 64;
}

Bits64 _create_mask_range(int to, int from)
{
    return ((ONE << (to - from)) - 1) << from;
}

Bits64 set(Bits64 map, int at)
{
    if (_bits64_zeroindex_oorange(at)) {
        throw std::out_of_range("");
    }

    auto mask = ONE << at;
    map |= mask;
    return map;
}

Bits64 set(Bits64 map, int from, int to)
{
    if (_bits64_zeroindex_oorange(from) && to > 64 && from >= to) {
        throw std::out_of_range("");
    }
    auto mask = _create_mask_range(to, from);
    map |= mask;
    return map;
}

Bits64 clear(Bits64 map, int at)
{
    if (_bits64_zeroindex_oorange(at)) {
        throw std::out_of_range("");
    }
    auto mask = ONE << at;
    map &= ~mask;
    return map;
}

Bits64 clear(Bits64 map, int from, int to)
{
    if (_bits64_zeroindex_oorange(from) && to > 64 && from >= to) {
        throw std::out_of_range("");
    }
    auto mask = _create_mask_range(to, from);
    map &= ~mask;
    return map;
}

Bits64 toggle(Bits64 map, int at)
{
    if (_bits64_zeroindex_oorange(at)) {
        throw std::out_of_range("");
    }
    auto mask = ONE << at;
    map ^= mask;
    return map;
}

Bits64 toggle(Bits64 map, int from, int to)
{
    if (_bits64_zeroindex_oorange(from) && to > 64 && from >= to) {
        throw std::out_of_range("");
    }
    auto mask = _create_mask_range(to, from);
    map ^= mask;
    return map;
}

bool is_set(Bits64 map, int at)
{
    if (_bits64_zeroindex_oorange(at)) {
        throw std::out_of_range("");
    }
    auto mask = ONE << at;
    return map & (1 << at);
}

bool is_set(Bits64 map, int from, int to)
{
    if (_bits64_zeroindex_oorange(from) && to > 64 && from >= to) {
        throw std::out_of_range("");
    }
    auto mask = _create_mask_range(to, from);
    return (map & mask) == mask;
}

std::string as_str(Bits64 map)
{
    std::stringstream ss;
    ss << std::bitset<8>(map);
    return ss.str();
}
