//
// Created by rnetuka on 21.6.18.
//

#pragma once

#include <algorithm>
#include <iostream>
#include <vector>

#include "collection.h"

namespace collections
{

    template <typename T>
    class vector final : public std::vector<T>, public Collection<T>
    {
    private:
        using super = std::vector<T>;
        using iterator = typename std::vector<T>::iterator;

    public:
        vector() : super()
        {

        }

        explicit vector(int size) : super(size)
        {

        }

        vector(int size, T value) : super(size, value)
        {

        }

        vector(std::initializer_list<T> list) : super(list)
        {

        }

        int index_of(const T& element) const
        {
            auto it = std::find(begin(), end(), element);
            return it == end() ? -1 : end() - it;
        }

        void insert(const Iterator<T>& position, T element)
        {
            int offset = position - begin();
            super::insert(super::begin() + offset, element);
        }

        void insert(int position, T element)
        {
            if (position < 0 || position > size())
                throw std::invalid_argument("Position ");

            insert(begin() + position, element);
        }

        Iterator<T> begin() const noexcept override
        {
            //return super::begin();
            //T* ptr = const_cast<T*>(&((*this)[0]));
            //return Iterator<T>(ptr);

            auto it = super::begin();
            T& val = const_cast<T&>(*it);
            return Iterator<T>(&val, 0, size() - 1);
        }

        Iterator<T> end() const noexcept override
        {
            //return super::end();
            //return Iterator<T>(const_cast<T*>(&((*this)[size()])));
            auto it = super::begin();
            T& val = const_cast<T&>(*it);
            return Iterator<T>(&val, size(), size() - 1);
        }

        int size() const noexcept override
        {
            return static_cast<int>(super::size());
        }

        void add(T element) noexcept override
        {
            this->push_back(element);
        }

        void remove(const T& element) noexcept override
        {
            auto it = std::remove(begin(), end(), element);
            int c = end() - it;
            for (int i = 0; i < c; i++)
                this->pop_back();
        }

        bool operator==(const vector<T>& other) const
        {
            if (size() != other.size())
                return false;

            for (int i = 0; i < size(); i++)
                if ((*this)[i] != other[i])
                    return false;

            return true;
        }

    };


    template <typename T>
    using Vector = collections::vector<T>;

}