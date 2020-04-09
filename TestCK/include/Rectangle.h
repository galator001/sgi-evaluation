#ifndef RECTANGLE_H
#define RECTANGLE_H
#include "Point2D.h"

class Rectangle
{
private:
    Point2D mBottomLeftPoint;
    Point2D mTopRightPoint;
    float mHeight;
    float mWidth;
public:
	Rectangle(const Point2D& mBottomLeftPoint, float mWidth, float mHeight);
	Rectangle(const Rectangle& rect);
	Rectangle& operator=(const Rectangle& rect);
	~Rectangle() = default;
	float getHeight() const;
	float getWidth() const;
	Point2D getBottomLeftPoint() const;
	Point2D getTopRightPoint() const;
	Point2D getBottomRightPoint() const;
	Point2D getTopLeftPoint() const;
	bool containsPoint(Point2D point) const;
	bool intersects(Rectangle rect) const;
	bool isValueInRange(float value, float min, float max) const;
};

#endif // RECTANGLE_H
