#ifndef STDLIB_PQ_HPP
#define STDLIB_PQ_HPP

#include <initializer_list>
#include <optional>
#include <queue>

template <typename T>
class PQ {
    std::priority_queue<T> data;

public:
    auto empty() const { return data.empty(); }
    auto size() const { return data.size(); }
    auto push(const T &value) { data.push(value); }
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
            const auto top = data.top();
            data.pop();
            return top;
        }
    }
};

#endif
