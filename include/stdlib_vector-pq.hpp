#ifndef STDLIB_VECTOR_PQ_HPP
#define STDLIB_VECTOR_PQ_HPP

#include <algorithm>
#include <initializer_list>
#include <iterator>
#include <optional>
#include <vector>

template <typename T>
class PQ {
    std::vector<T> data;

public:
    auto empty() const { return data.empty(); }
    auto size() const { return data.size(); }
    auto push(const T &value)
    {
        data.push_back(value);
        std::push_heap(begin(data), end(data));
    }
    auto push(const std::initializer_list<T> &list)
    {
        for (const auto &v : list) {
            push(v);
        }
    }
    std::optional<T> pop()
    {
        if (data.empty()) {
            return {};
        } else {
            std::pop_heap(begin(data), end(data));
            const auto back = data.back();
            data.pop_back();
            return back;
        }
    }
};

#endif
