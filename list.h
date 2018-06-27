//
// Created by rnetuka on 8.6.18.
//

#pragma once

#include <algorithm>
#include <iostream>
#include <list>

#include "collection.h"
#include "iterator.h"

namespace collections
{

    template <typename T>
    class list final : public std::list<T>, public Collection<T>
    {
    private:
        using super = std::list<T>;

    public:
        list()
        {

        }

        list(const std::initializer_list<T>& init_list) : super(init_list)
        {

        }

        Iterator<T> begin() const noexcept override
        {
            auto it = super::begin();
            return Iterator<T>(it);
        }

        Iterator<T> end() const noexcept override
        {
            auto it = super::end();
            return Iterator<T>(it);
        }

        int size() const noexcept override
        {
            return static_cast<int>(super::size());
        }

        void add(T element) noexcept override
        {
            super::push_back(element);
        }

    };


    template <typename T>
    using List = collections::list<T>;

}