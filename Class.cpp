//
// Created by San Byn Nguyen on 21.06.2018.
//

#include "Class.h"

Class::Class(int n) : _arr(new int[n])
{}

int *Class::get_arr() const
{
    return _arr;
}
