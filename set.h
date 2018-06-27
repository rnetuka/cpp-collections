//
// Created by rnetuka on 22.6.18.
//

#pragma once

#include <algorithm>
#include <set>

#include "collection.h"

namespace collections
{

    template <typename T>
    class set : public std::set<T>, public SortedCollection<T>
    {
    private:
        using super = std::set<T>;

    public:
        set(std::initializer_list<T> init_list) : super(init_list)
        {

        }

        std::string str_open() const override
        {
            return "{";
        }

        std::string str_close() const override
        {
            return "}";
        }

        bool contains(const T& element) const noexcept override
        {
            return std::find(this->begin(), this->end(), element) != this->end();
        }

        set<T> operator+(const set<T>& other) const
        {

        }

        set<T> operator-(const set<T>& other) const
        {

        }

        friend std::ostream& operator<<(std::ostream& stream, const set& s)
        {
            using namespace std;
            cout << "{";
            for (auto it = s.begin(); it != s.end(); it++)
            {
                cout << *it;
                if (it + 1 != s.end())
                    cout << ", ";
            }
            cout << "}";
            return stream;
        }

    };

}
