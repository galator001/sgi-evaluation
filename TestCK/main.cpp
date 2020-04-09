#include <iostream>
#include "Point2D.h"
#include "Rectangle.h"
#include "FactorChecker.h"
#include <assert.h>

using namespace std;

/*
    Running tests to make sure the bottom left point, width and height are getting set correctly
*/
void RunCreateRectangleTests(){
    Point2D point = Point2D(2, 2);
    Rectangle rect = Rectangle(point, 5, 6);
    assert(rect.getBottomLeftPoint().getX() == point.getX());
    assert(rect.getBottomLeftPoint().getY() == point.getY());
    assert(rect.getWidth() == 5);
    assert(rect.getHeight() == 6);

    point = Point2D(2, 2);
    rect = Rectangle(point, -5, 6);
    assert(rect.getBottomLeftPoint().getX() == point.getX() - 5);
    assert(rect.getBottomLeftPoint().getY() == point.getY());
    assert(rect.getWidth() == 5);
    assert(rect.getHeight() == 6);

    point = Point2D(2, 2);
    rect = Rectangle(point, -5, -6);
    assert(rect.getBottomLeftPoint().getX() == point.getX() - 5);
    assert(rect.getBottomLeftPoint().getY() == point.getY() - 6);
    assert(rect.getWidth() == 5);
    assert(rect.getHeight() == 6);

    point = Point2D(2, 2);
    rect = Rectangle(point, 5, -6);
    assert(rect.getBottomLeftPoint().getX() == point.getX());
    assert(rect.getBottomLeftPoint().getY() == point.getY() - 6);
    assert(rect.getWidth() == 5);
    assert(rect.getHeight() == 6);
}

void RunPointContainsTests(){
    Point2D bottomLeftPoint = Point2D(2, 2);
    Rectangle rect = Rectangle(bottomLeftPoint, 5, 6);

    Point2D testPoint = Point2D(3, 3);
    bool result = rect.containsPoint(testPoint);
    assert(result == true);

    testPoint = Point2D(7, 2);
    result = rect.containsPoint(testPoint);
    assert(result == false);

    testPoint = Point2D(-7, 2);
    result = rect.containsPoint(testPoint);
    assert(result == false);
}

void RunIntersectTests(){
    //overlapping rectangles
    Point2D rect1Point = Point2D(2, 2);
    Rectangle rect1 = Rectangle(rect1Point, 5, 6);

    Point2D rect2Point = Point2D(2, 2);
    Rectangle rect2 = Rectangle(rect2Point, 5, 6);

    bool result = rect1.intersects(rect2);
    assert(result == true);

    //long rect on y-axis
    rect2Point = Point2D(2, 1);
    rect2 = Rectangle(rect2Point, 2, 8);

    result = rect1.intersects(rect2);
    assert(result == true);

    //non-insersecting rect
    rect2Point = Point2D(10, 20);
    rect2 = Rectangle(rect2Point, 2, 8);

    result = rect1.intersects(rect2);
    assert(result == false);

    //long rect on x-axis
    rect2Point = Point2D(1, 3);
    rect2 = Rectangle(rect2Point, 8, 1);

    result = rect1.intersects(rect2);
    assert(result == true);

    //rect2 within rect1
    rect2Point = Point2D(3, 3);
    rect2 = Rectangle(rect2Point, 1, 1);

    result = rect1.intersects(rect2);
    assert(result == true);
}

void RunRectangleTests(){
    cout << "Running Rectangle tests" << endl;
    RunCreateRectangleTests();
    RunPointContainsTests();
    RunIntersectTests();
    cout << "Finished running Rectangle tests" << endl;
}

int main()
{
    RunRectangleTests();

    FactorChecker f = FactorChecker();
    int val = f.getFactorForIndex(1500);
    cout << "Factor Checker for index 1500 = " << val << endl;
    return 0;
}

