#include <experimental/ranges/algorithm>
#include <experimental/ranges/iterator>
#include <chrono>
#include <iostream>
#include <random>
#include <vector>

std::vector<int> make_crowd(const int children, const int adults, const int seniors)
{
   auto crowd = std::vector<int>{};

   // random number generator in C++... much better than what you're used to!
   namespace chrono = std::chrono;
   auto generator = std::mt19937(chrono::system_clock::now().time_since_epoch().count());
   auto distribute = std::uniform_int_distribution<>{0, 17};

   for (auto i = 0; i < children; ++i)
      crowd.push_back(distribute(generator));

   distribute = std::uniform_int_distribution<>{18, 64};
   for (auto i = 0; i < adults; ++i)
      crowd.push_back(distribute(generator));

   distribute = std::uniform_int_distribution<>{65, 128};
   for (auto i = 0; i < seniors; ++i)
      crowd.push_back(distribute(generator));

   return crowd;
}

namespace ranges = std::experimental::ranges::v1;

int main()
{
   auto a = make_crowd(100, 2, 5);
   ranges::sort(a);

   auto b = make_crowd(5, 2, 100);
   ranges::sort(b);

   // get the container that has the extremes
   auto youngest = a.front() < b.front();
   auto oldest = a.back() > b.back();

   if (youngest && oldest)
      ranges::copy(a, ranges::ostream_iterator<decltype(a)::value_type>{std::cout, "\n"});
   else if (not (youngest || oldest))
      ranges::copy(b, ranges::ostream_iterator<decltype(b)::value_type>{std::cout, "\n"});
   else
      std::cout << "ranges overlap\n";
}