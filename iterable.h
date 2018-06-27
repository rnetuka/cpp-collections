//
// Created by rnetuka on 8.6.18.
//

#pragma once

#include "iterator.h"

namespace collections
{

    template <typename T>
    class Iterable
    {
    public:
        virtual Iterator<T> begin() const = 0;

        virtual Iterator<T> end() const = 0;
    };

}