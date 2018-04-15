#include "include/manual_heap-pq.hpp"
#include <iostream>

int main()
{
    PQ<int> q;
    q.push({ 10, 100, 20, 30, 5, 1 });
    try {
        std::cout << q.pop().value() << '\n'
                  << q.pop().value() << '\n'
                  << q.pop().value() << '\n'
                  << q.pop().value() << '\n'
                  << q.pop().value() << '\n'
                  << q.pop().value() << '\n'
                  << q.pop().value() << '\n';
    } catch (std::bad_optional_access &e) {
        std::cout << "Intentional bad access after 6 elements!\n";
    }
}
