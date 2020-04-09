#ifndef POINT2D_H
#define POINT2D_H

class Point2D
{
private:
    float mX;
    float mY;

public:
    Point2D() = default;
	Point2D(float mX, float mY);
	Point2D(const Point2D &point);
	~Point2D() = default;
	float getX() const;
	float getY() const;
};

#endif // POINT2D_H
