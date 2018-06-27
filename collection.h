//
// Created by rnetuka on 22.6.18.
//

#pragma once

#include <iostream>

#include "iterator.h"

namespace collections
{

    template <typename T>
    class Collection
    {
    private:
        using iterator = std::iterator<std::input_iterator_tag, T>;

    protected:
        virtual std::string str_open() const
        {
            return "[";
        }

        virtual std::string str_close() const
        {
            return "]";
        }

    public:
        bool all_of(bool (*function)(const T element)) const
        {
            return std::all_of(begin(), end(), function);
        }

        bool any_of(bool (*function)(const T element)) const
        {
            return std::any_of(begin(), end(), function);
        }

        bool none_of(bool (*function)(const T element)) const
        {
            return std::none_of(begin(), end(), function);
        }

        void map(T (*function)(const T))
        {
            std::transform(begin(), end(), begin(), function);
        }

        void for_each(void (*function)(const T element)) const
        {
            std::for_each(begin(), end(), function);
        }

        bool empty() const noexcept
        {
            return size() == 0;
        }

        Iterator<T> find(const T& element) const
        {
            return std::find(begin(), end(), element);
        }

        bool contains(const T& element) const noexcept
        {
            return find(element) != end();
        }

        virtual Iterator<T> begin() const noexcept = 0;
        virtual Iterator<T> end() const noexcept = 0;
        virtual int size() const noexcept = 0;
        virtual void add(T element) noexcept = 0;
        virtual void remove(const T& element) noexcept = 0;

        friend std::ostream& operator<<(std::ostream& stream, const Collection<T>& c)
        {
            using namespace std;

            stream << c.str_open();
            for (auto it = c.begin(); it != c.end(); it++)
            {
                stream << *it;
                if (it + 1 != c.end())
                    stream << ", ";
            }
            stream << c.str_close();
            return stream;
        }
    };




    template <typename T>
    class SortedCollection : public Collection<T>
    {
    public:

    };

}