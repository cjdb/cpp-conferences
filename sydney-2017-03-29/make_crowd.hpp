#ifndef MAKE_CROWD_HPP
#define MAKE_CROWD_HPP

#include <experimental/ranges/algorithm>
#include <experimental/ranges/iterator>
#include <iostream>
#include <random>

namespace ranges = std::experimental::ranges;

template <ranges::InputRange Rng>
Rng make_crowd(const int children, const int adults, const int seniors)
{
   auto crowd = std::vector<int>{};

   // random number generator in C++... much better than what you're used to!
   auto generator = std::mt19937{std::random_device{}()};
   auto distribute = std::uniform_int_distribution<>{0, 17};

   for (auto i = 0; i < children; ++i)
      crowd.push_back(distribute(generator));

   distribute = std::uniform_int_distribution<>{18, 64};
   for (auto i = 0; i < adults; ++i)
      crowd.push_back(distribute(generator));

   distribute = std::uniform_int_distribution<>{65, 128};
   for (auto i = 0; i < seniors; ++i)
      crowd.push_back(distribute(generator));

   return {crowd.cbegin(), crowd.cend()};
}

template <ranges::InputIterator I, ranges::Sentinel<I> S>
void print_crowd(I first, S last)
{
   ranges::copy(first, last, ranges::ostream_iterator<ranges::value_type_t<I>>{std::cout, " "});
   std::cout << '\n';
}

constexpr auto young_adult = 18;
constexpr auto almost_senior = 64;

#endif // MAKE_CROWD_HPP