#include <stdio.h>

#include "Rectangle.h"

Rectangle::Rectangle(float width, float height)
    : width_(width), height_(height), area_(0.0f)
{
}

void Rectangle::Size()
{
    area_ = width_ * height_;
}

void Rectangle::Draw()
{
    printf("Rectangle area: %.2f\n", area_);
}
