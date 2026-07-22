#pragma once

class IShape
{
public:
    virtual ~IShape() = default;

    virtual void Size() = 0;
    virtual void Draw() = 0;
};
