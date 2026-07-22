#include "Circle.h"
#include "IShape.h"
#include "Rectangle.h"

int main()
{
    Circle circle(5.0f);
    Rectangle rectangle(4.0f, 6.0f);

    IShape* shapes[2] =
    {
        &circle,
        &rectangle
    };

    for (int i = 0; i < 2; i++)
    {
        shapes[i]->Size();
        shapes[i]->Draw();
    }

    return 0;
}
