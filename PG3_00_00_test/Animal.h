#pragma once

class Animal
{
public:
    virtual ~Animal() = default;

    virtual void MakeSound() = 0;
};
