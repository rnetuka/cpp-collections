//
// Created by rnetuka on 8.6.18.
//

#pragma once

#include <iterator>

namespace collections
{

    class IteratorException : std::exception
    {
    public:
        explicit IteratorException(const std::string& message)
        {

        }
    };


    template <typename T>
    class Iterator : public std::iterator<std::input_iterator_tag, T>
    {
    private:
        int offset;
        int max_offset;
        T* ptr;
        bool started;

        bool valid() const
        {
            return offset <= max_offset;
        }

    public:
        Iterator(T* ptr, int offset, int max_offset) : started(false)
        {
            this->ptr = ptr;
            this->offset = offset;
            this->max_offset = max_offset;
        }

        bool has_next() const noexcept
        {
            return offset < max_offset;
        }

        T& next()
        {
            if (! has_next())
                throw IteratorException("Iterator reached its end. No next element is present.");

            if (started)
                (*this)++;
            else
                started = true;
            return **this;
        }

        Iterator<T> operator++()
        {
            offset++;
            return *this;
        }

        Iterator<T> operator++(int)
        {
            offset++;
            return *this;
        }

        T& operator*()
        {
            if (! valid())
                throw IteratorException("");

            return *(ptr + offset);
        }

        T* operator->()
        {
            if (! valid())
                throw IteratorException("");

            return valid() ? ptr + offset : nullptr;
        }

        Iterator<T> operator+(int n) const noexcept
        {
            return Iterator<T>(ptr, offset + n, max_offset);
        }

        int operator-(const Iterator<T>& other) const
        {
            return offset - other.offset;
        }

        bool operator==(const Iterator<T>& other) const
        {
            return offset == other.offset;
        }

        bool operator!=(const Iterator<T>& other) const
        {
            return offset != other.offset;
        }
    };

}