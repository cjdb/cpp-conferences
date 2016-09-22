#include <experimental/ranges/concepts>
#include <iostream>
#include <memory>

namespace ranges = std::experimental::ranges::v1;

struct Foobar {
   Foobar() = default;
   Foobar(int i, double d) : foo{i}, bar{d} {}

   int foo{0};
   double bar{0.0};
};

template <ranges::Semiregular T, ranges::Regular... Args>
std::unique_ptr<T> make_unique(Args&&... args)
{
   return std::unique_ptr<T>(new T{std::forward<Args>(args)...});
}

int main()
{
   auto p = make_unique<Foobar>(10, 2.1);
   std::cout << p->foo << ' ' << p->bar << '\n';
}