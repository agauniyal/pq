#ifndef STDLIB_PQ_HPP
#define STDLIB_PQ_HPP

#include <initializer_list>
#include <optional>
#include <vector>
#include <utility>

template <typename T>
class PQ {
    std::vector<T> data;

    auto parent(const size_t pos) const { return pos ? ((pos - 1) / 2) : 0; }
    auto left_child(const size_t pos) const { return (2 * pos) + 1; }
    auto right_child(const size_t pos) const { return (2 * pos) + 2; }

    void bubble_up(const size_t index)
    {
        if (data[index] > data[parent(index)]) {
            std::swap(data[index], data[parent(index)]);
            bubble_up(parent(index));
        }
    }

    void trickle_down(const size_t index)
    {
        const auto left_index  = left_child(index);
        const auto right_index = right_child(index);
        auto largest_index    = index;

        if (left_index < size()) {
            if (right_index < size()) {
                if (data[left_index] > data[right_index]) {
                    largest_index = left_index;
                } else {
                    largest_index = right_index;
                }
            } else {
                largest_index = left_index;
            }
        }

        if (data[largest_index] > data[index]) {
            std::swap(data[largest_index], data[index]);
            trickle_down(largest_index);
        }
    }

public:
    auto empty() const { return data.empty(); }
    auto size() const { return data.size(); }

    auto push(const T &value)
    {
        data.push_back(value);
        bubble_up(size() - 1);
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
            std::swap(data[0], data[size() - 1]);
            const auto back = data.back();
            data.pop_back();
            if (!data.empty()) {
                trickle_down(0);
            }
            return back;
        }
    }
};

#endif
