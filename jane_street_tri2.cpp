#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using std::vector;
using std::cout;
using std::endl;

///////////////
//  Globals  //
//////////////

/*
 * Represents the length of the square grid in which the triangle lie.
 */

const int MATRIX_MAX = 17;

////////////////////////////
//  Forward Declarations  //
///////////////////////////

struct Point;
vector<Point> createShifts(Point P);
bool pointInTriangle (Point pt, Point v1, Point v2, Point v3);

///////////////
//  Classes  //
//////////////

/*
 *  Self-explanatory
 */

struct Point {
    float x;
    float y;
    Point(float X, float Y) : x(X), y(Y) {};
};

/*
 *  The struct carries two impprtant pieces of information:
 *  1. The dimensions of our triangle in the form of (base, height)
 *  2. All the possible offsets that this base/height combination
 *  can achieve while simultaneously keeping the square (on the grid)
 *  inside of it.
 * 
 *  For example, a triangle of area 20 can have dimensions 2 by 20, 4 by 10, and 8 by 5
 *  EACH of these dimensions allows us to move the triangle in a given direction while maintaing
 *  that the box that represents its area lies within it. For example,
 * 
 *  |\
 *  | \            
 *  |  \
 *  |   \
 *  |    \
 *  |5____\
 *
 * 
 *  The following triangle can be moved from downwards once, downwards and left once, downwards twice,
 *  downwards twice and left once, downwards twice and left twice, so on and so forth, as long as
 *  the number 5 DOESNT fall outside if its perimeter.
*/

struct PossibleShifts {
    // _dimensions is in the format of a point (x,y) but it really represents a dimension
    // as a (base, height) combination.
    Point _dimensions;
    vector<Point> _shifts;
    PossibleShifts(Point point, vector<Point> shifts) : _dimensions(point), _shifts(shifts) {};
};


/*
 * The triangle class is where all the action happens.
 *      Variables:
 *         _x and _y are the X and Y coordinates of the right angle traingle.
 *         _area is the area if the triangle.
 * 
 *      _combination hodls all the possible dimensions of the triangle, as well as the repective
 *      valid offsets for each dimension
 * 
 *     _allTriangles holds all the possible valid triangle combinations (each shape base/height combination) and each
 *      triangle orientation. Given that a triangle has three vertices, each three points represent one triangle.
 *      For instance, a vector may contain 27 points. This means it contains 9 valid triangles.
 * 
*/

class Triangle {
    private:

        int _x;
        int _y;
        int _area;

    public:
        
        vector<PossibleShifts> _combinations;
        vector<Point> _allTriangles;

        Triangle(int area, int x, int y) :
            _x(x),
            _y(y),
            _area(area)
{
            createDimensions(_area, _combinations);
            makeCombinations(_x,_y,_combinations,_allTriangles);
};

        void createDimensions(int area, vector<PossibleShifts>& combinations);
        void makeCombinations(int x, int y, vector<PossibleShifts>& combinations, vector<Point>& allTrinagles);

        vector<Point> createShifts(Point dimensions);

        int inline getXC() const {return _x;};
        int inline getYC() const {return _y;};

        void printDimensions() const;
        void printTriangles() const;

        vector<PossibleShifts> getCombinations() {return _combinations;};
};

/* Calculate all valud integer base/height combinations given
 * the triangle's area. Do so by imagining the triangle is a square.
 *
 * A base must be at least 2 squares wide, otherwise, the 1 by 1 square
 * representing that triangle's area cannot fit in it.
*/

void Triangle::createDimensions(int area, vector<PossibleShifts>& combinations) {
    int effectiveArea = 2 * area;

    for (int base{2}; base < effectiveArea; ++base) {
        int height;
        if (effectiveArea % base == 0) {
            height = effectiveArea / base;
            combinations.push_back(PossibleShifts(Point(base, height), createShifts(Point(base, height))));
        }
    }
    return;
}

vector<Point> Triangle::createShifts(Point dimensions) {
    
    vector<Point> results;

    int shiftY{}, shiftX{};

    /*
     * The box that our triangle contains is size 1 by 1
     */

    Point q1(1,1);

    // The three vertices of our triangle.
    Point v1(shiftX,shiftY);
    Point v2(0, dimensions.y);
    Point v3(dimensions.x, 0);

    int maxHeight = dimensions.y;
    while (pointInTriangle(q1))
}
