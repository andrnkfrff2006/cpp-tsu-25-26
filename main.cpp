#include "geometry.hpp"
#include <iostream>
#include <vector>
using namespace std;

struct TestCase {
    Point2D p1, p2;
    Kind g1;
    Point2D p3, p4;
    Kind g2;
    Double distance;
};

vector<TestCase> testCases = {
    // Add test cases here
    { { 10, 1 }, { 0, 4 }, Kind::Line, { 2, 1 }, { 10, 8 }, Kind::Line, { 0.0000000000000 } },
    { { 6, 5 }, { 4, 2 }, Kind::Line, { 5, 1 }, { 1, 6 }, Kind::Line, { 0.0000000000000 } },
    { { 8, 0 }, { 9, 5 }, Kind::Line, { 1, 5 }, { 4, 3 }, Kind::Line, { 0.0000000000000 } },
    { { 3, 1 }, { 5, 0 }, Kind::Line, { 3, 9 }, { 3, 0 }, Kind::Line, { 0.0000000000000 } },
    { { 2, 6 }, { 7, 7 }, Kind::Line, { 6, 0 }, { 2, 6 }, Kind::Line, { 0.0000000000000 } },
    { { 10, 0 }, { 3, 1 }, Kind::Line, { 13, -1 }, { 6, 0 }, Kind::Line, { 0.5656854249492 } },
    { { 0, 3 }, { 6, 6 }, Kind::Line, { 1, 5 }, { 7, 8 }, Kind::Line, { 1.3416407864999 } },
    { { 8, 4 }, { 2, 10 }, Kind::Line, { 8, 1 }, { 2, 7 }, Kind::Line, { 2.1213203435596 } },
    { { 7, 3 }, { 1, 7 }, Kind::Line, { 10, 4 }, { 4, 8 }, Kind::Line, { 2.4961508830135 } },
    { { 2, 0 }, { 0, 3 }, Kind::Line, { 3, 3 }, { 1, 6 }, Kind::Line, { 2.4961508830135 } },
    { { 5, 3 }, { 2, 8 }, Kind::Line, { 0, 1 }, { 2, 10 }, Kind::Segment, { 0.0000000000000 } },
    { { 6, 4 }, { 7, 4 }, Kind::Line, { 8, 10 }, { 7, 2 }, Kind::Segment, { 0.0000000000000 } },
    { { 1, 10 }, { 6, 4 }, Kind::Line, { 5, 2 }, { 10, 4 }, Kind::Segment, { 0.0000000000000 } },
    { { 7, 6 }, { 10, 9 }, Kind::Line, { 6, 7 }, { 6, 3 }, Kind::Segment, { 0.0000000000000 } },
    { { 7, 1 }, { 4, 3 }, Kind::Line, { 5, 8 }, { 1, 2 }, Kind::Segment, { 0.0000000000000 } },
    { { 9, 8 }, { 2, 6 }, Kind::Line, { 4, 5 }, { 0, 5 }, Kind::Segment, { 0.4120816918461 } },
    { { 0, 7 }, { 9, 9 }, Kind::Line, { -3, 8 }, { 6, 10 }, Kind::Segment, { 1.6269784336399 } },
    { { 3, 4 }, { 6, 10 }, Kind::Line, { 7, 8 }, { 7, 1 }, Kind::Segment, { 1.7888543819998 } },
    { { 1, 6 }, { 1, 8 }, Kind::Line, { 10, 9 }, { 5, 9 }, Kind::Segment, { 4.0000000000000 } },
    { { 0, 10 }, { 8, 0 }, Kind::Line, { 3, 13 }, { 11, 3 }, Kind::Segment, { 4.2166915709924 } },
    { { 1, 9 }, { 10, 2 }, Kind::Line, { 3, 2 }, { 7, 6 }, Kind::Ray, { 0.0000000000000 } },
    { { 7, 6 }, { 10, 7 }, Kind::Line, { 2, 3 }, { 8, 8 }, Kind::Ray, { 0.0000000000000 } },
    { { 5, 1 }, { 3, 3 }, Kind::Line, { 7, 2 }, { 6, 2 }, Kind::Ray, { 0.0000000000000 } },
    { { 4, 10 }, { 1, 2 }, Kind::Line, { 1, 8 }, { 2, 4 }, Kind::Ray, { 0.0000000000000 } },
    { { 2, 2 }, { 6, 0 }, Kind::Line, { 5, 6 }, { 10, 3 }, Kind::Ray, { 0.0000000000000 } },
    { { 8, 4 }, { 2, 5 }, Kind::Line, { 6, 3 }, { 0, 4 }, Kind::Ray, { 1.3151918984429 } },
    { { 4, 5 }, { 10, 8 }, Kind::Line, { 8, 5 }, { 0, 1 }, Kind::Ray, { 1.7888543819998 } },
    { { 6, 8 }, { 8, 9 }, Kind::Line, { 6, 6 }, { 8, 7 }, Kind::Ray, { 1.7888543819998 } },
    { { 1, 0 }, { 10, 3 }, Kind::Line, { 1, 3 }, { 1, 6 }, Kind::Ray, { 2.8460498941515 } },
    { { 7, 8 }, { 6, 8 }, Kind::Line, { 1, 2 }, { 8, 0 }, Kind::Ray, { 6.0000000000000 } },
    { { 3, 6 }, { 10, 6 }, Kind::Segment, { 2, 9 }, { 9, 4 }, Kind::Segment, { 0.0000000000000 } },
    { { 4, 10 }, { 9, 5 }, Kind::Segment, { 8, 5 }, { 6, 8 }, Kind::Segment, { 0.0000000000000 } },
    { { 6, 7 }, { 1, 9 }, Kind::Segment, { 0, 2 }, { 2, 9 }, Kind::Segment, { 0.0000000000000 } },
    { { 9, 1 }, { 3, 10 }, Kind::Segment, { 10, 1 }, { 2, 3 }, Kind::Segment, { 0.0000000000000 } },
    { { 8, 1 }, { 2, 0 }, Kind::Segment, { 9, 7 }, { 4, 0 }, Kind::Segment, { 0.0000000000000 } },
    { { 8, 3 }, { 4, 10 }, Kind::Segment, { 8, 2 }, { 9, 9 }, Kind::Segment, { 0.1414213562373 } },
    { { 3, 7 }, { 6, 3 }, Kind::Segment, { 10, 6 }, { 5, 6 }, Kind::Segment, { 1.0000000000000 } },
    { { 7, 0 }, { 10, 10 }, Kind::Segment, { 4, -3 }, { 7, 7 }, Kind::Segment, { 2.0114351989644 } },
    { { 2, 1 }, { 6, 0 }, Kind::Segment, { 0, -1 }, { 4, -2 }, Kind::Segment, { 2.4253562503633 } },
    { { 10, 8 }, { 3, 10 }, Kind::Segment, { 0, 3 }, { 0, 5 }, Kind::Segment, { 5.8309518948453 } },
    { { 9, 6 }, { 0, 0 }, Kind::Segment, { 3, 8 }, { 9, 0 }, Kind::Ray, { 0.0000000000000 } },
    { { 5, 1 }, { 4, 6 }, Kind::Segment, { 0, 4 }, { 8, 2 }, Kind::Ray, { 0.0000000000000 } },
    { { 2, 9 }, { 4, 0 }, Kind::Segment, { 6, 5 }, { 5, 6 }, Kind::Ray, { 0.0000000000000 } },
    { { 9, 0 }, { 5, 8 }, Kind::Segment, { 5, 1 }, { 8, 10 }, Kind::Ray, { 0.0000000000000 } },
    { { 2, 8 }, { 10, 4 }, Kind::Segment, { 8, 7 }, { 7, 6 }, Kind::Ray, { 0.0000000000000 } },
    { { 5, 5 }, { 9, 4 }, Kind::Segment, { 7, 5 }, { 11, 4 }, Kind::Ray, { 0.4850712500727 } },
    { { 7, 8 }, { 8, 2 }, Kind::Segment, { 8, 1 }, { 2, 1 }, Kind::Ray, { 1.0000000000000 } },
    { { 10, 6 }, { 9, 1 }, Kind::Segment, { 9, 7 }, { 8, 4 }, Kind::Ray, { 1.2649110640674 } },
    { { 4, 3 }, { 0, 9 }, Kind::Segment, { 0, 5 }, { 0, 0 }, Kind::Ray, { 2.2188007849009 } },
    { { 1, 10 }, { 4, 10 }, Kind::Segment, { 3, 2 }, { 5, 2 }, Kind::Ray, { 8.0000000000000 } },
    { { 7, 10 }, { 5, 2 }, Kind::Ray, { 3, 10 }, { 4, 10 }, Kind::Ray, { 0.0000000000000 } },
    { { 3, 9 }, { 1, 1 }, Kind::Ray, { 1, 8 }, { 2, 2 }, Kind::Ray, { 0.0000000000000 } },
    { { 7, 8 }, { 2, 4 }, Kind::Ray, { 9, 6 }, { 3, 8 }, Kind::Ray, { 0.0000000000000 } },
    { { 9, 1 }, { 6, 10 }, Kind::Ray, { 8, 5 }, { 4, 3 }, Kind::Ray, { 0.0000000000000 } },
    { { 10, 10 }, { 3, 5 }, Kind::Ray, { 10, 5 }, { 9, 5 }, Kind::Ray, { 0.0000000000000 } },
    { { 3, 10 }, { 8, 6 }, Kind::Ray, { 9, 4 }, { 0, 2 }, Kind::Ray, { 0.9370425713316 } },
    { { 0, 10 }, { 1, 10 }, Kind::Ray, { 3, 9 }, { 4, 9 }, Kind::Ray, { 1.0000000000000 } },
    { { 4, 1 }, { 3, 9 }, Kind::Ray, { 3, -1 }, { 2, 7 }, Kind::Ray, { 1.2403473458921 } },
    { { 4, 1 }, { 9, 0 }, Kind::Ray, { 5, 3 }, { 10, 2 }, Kind::Ray, { 2.1572774865200 } },
    { { 5, 3 }, { 1, 4 }, Kind::Ray, { 3, 6 }, { -1, 7 }, Kind::Ray, { 2.4253562503633 } },
};

string kind2string(Kind k)
{
    switch (k) {
    case Kind::Line:
        return "Line";
    case Kind::Ray:
        return "Ray";
    case Kind::Segment:
        return "Segment";
    default:
        return "Unknown";
    }
}

int main()
{
    int total = 0;

    for (int i = 0; i < testCases.size(); ++i) {
        const TestCase& tc = testCases[i];

        Geometry g1 = { tc.g1, tc.p1, tc.p2 };
        Geometry g2 = { tc.g2, tc.p3, tc.p4 };

        Double d = distance(g1, g2);

        if (d.is_equal(tc.distance)) {
            total++;
            cout << "OK ";
        } else {
            cout << "FAIL ";
        }

        cout << kind2string(tc.g1) << " [(" << tc.p1.x.value << ", " << tc.p1.y.value << "), ("
             << tc.p2.x.value << ", " << tc.p2.y.value << ")]  vs "
             << kind2string(tc.g2) << " [(" << tc.p3.x.value << ", " << tc.p3.y.value << "), ("
             << tc.p4.x.value << ", " << tc.p4.y.value << ")] : expected "
             << tc.distance.value << ", got " << d.value << '\n';
    }

    cout << "\n\nPassed " << total << " out of " << testCases.size() << " test cases." << endl;
    cout << "Score: " << ((total - 30) * 100) / (testCases.size() - 30) << "%" << endl;

    return 0;
}
