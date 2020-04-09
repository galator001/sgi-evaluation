#include "Rectangle.h"

using namespace std;

Rectangle::Rectangle(const Point2D& point, float width, float height)
{
    float bottomLeftX = point.getX();
    float bottomLeftY = point.getY();

    if(width < 0){
        bottomLeftX += width;
        width = -width;
    }

    if(height < 0){
        bottomLeftY += height;
        height = -height;
    }

    mWidth = width;
    mHeight = height;
    mBottomLeftPoint = Point2D(bottomLeftX, bottomLeftY);
}

Rectangle::Rectangle(const Rectangle &rect): mBottomLeftPoint(rect.mBottomLeftPoint)
{
    mWidth = rect.mWidth;
    mHeight = rect.mHeight;
}

Rectangle& Rectangle::operator=(const Rectangle& rect)
{
    mBottomLeftPoint = rect.mBottomLeftPoint;
    mWidth = rect.mWidth;
    mHeight = rect.mHeight;
    return *this;
}

float Rectangle::getWidth() const
{
    return mWidth;
}

float Rectangle::getHeight() const
{
    return mHeight;
}

Point2D Rectangle::getBottomLeftPoint() const
{
    return mBottomLeftPoint;
}

Point2D Rectangle::getTopRightPoint() const
{
    float topRightX = mBottomLeftPoint.getX() + mWidth;
    float topRightY = mBottomLeftPoint.getY() + mHeight;
    return Point2D(topRightX, topRightY);
}

Point2D Rectangle::getTopLeftPoint() const
{
    float topRightY = mBottomLeftPoint.getY() + mHeight;
    return Point2D(mBottomLeftPoint.getX(), topRightY);
}

Point2D Rectangle::getBottomRightPoint() const
{
    float topRightX = mBottomLeftPoint.getX() + mWidth;
    return Point2D(topRightX, mBottomLeftPoint.getY());
}

bool Rectangle::containsPoint(Point2D point) const
{
    bool isWithinXBounds = point.getX() >= mBottomLeftPoint.getX() && point.getX() < getTopRightPoint().getX();
    bool isWithinYBounds = point.getY() >= mBottomLeftPoint.getY() && point.getY() < getTopRightPoint().getY();

    return isWithinXBounds && isWithinYBounds;
}

bool Rectangle::isValueInRange(float value, float min, float max) const
{
    return value >= min && value <= max;
}

bool Rectangle::intersects(Rectangle rect) const
{
    //check both rectangles bottom left x coordinates to see if the range is within the other's bounds
    bool doesXOverlap = isValueInRange(mBottomLeftPoint.getX(), rect.mBottomLeftPoint.getX(), rect.mBottomLeftPoint.getX() + rect.mWidth) ||
                    isValueInRange(rect.mBottomLeftPoint.getX(), mBottomLeftPoint.getX(), mBottomLeftPoint.getX() + mWidth);

    //check both rectangles bottom left y coordinates to see if the range is within the other's bounds
    bool doesYOverlap = isValueInRange(mBottomLeftPoint.getY(), rect.mBottomLeftPoint.getY(), rect.mBottomLeftPoint.getY() + rect.mHeight) ||
                    isValueInRange(rect.mBottomLeftPoint.getY(), mBottomLeftPoint.getY(), mBottomLeftPoint.getY() + mHeight);

    return doesXOverlap && doesYOverlap;
}

