#include "Point2D.h"

Point2D::Point2D(float x, float y){
    mX = x;
    mY = y;
}

Point2D::Point2D(const Point2D& point)
{
    mX = point.mX;
    mY = point.mY;
}

float Point2D::getX() const
{
    return mX;
}

float Point2D::getY() const
{
    return mY;
}
