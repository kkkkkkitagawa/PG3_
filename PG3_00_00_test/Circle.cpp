#include <stdio.h>

#include "Circle.h"

Circle::Circle(float radius)
    : radius_(radius), area_(0.0f)
{
}

void Circle::Size()
{
    area_ = radius_ * radius_ * 3.14f;
}

void Circle::Draw()
{
    printf("Circle area: %.2f\n", area_);
}
