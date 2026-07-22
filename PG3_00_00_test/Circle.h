#pragma once

#include "IShape.h"

class Circle : public IShape
{
public:
    explicit Circle(float radius);

    void Size() override;
    void Draw() override;

private:
    float radius_;
    float area_;
};
