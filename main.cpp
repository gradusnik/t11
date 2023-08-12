#include <iostream>
#include "curves.h"
#include <ctime>
#include <memory>
#include <algorithm>

double myRand() {
    double rez = double (std::rand() % 100) + double (std::rand() % 100) / 100;
    return rez;
}

int main() {
    std::srand(std::time(nullptr));

    double const PI = 3.1415;
    int const n = 9;
    std::vector<std::shared_ptr<Circle>> v(n);

//    2. Populate a container (e.g. vector or list) of objects of these types created in random manner with
//      random parameters.
    for (int i = 0; i < n; ++i) {
        int r = std::rand() % 3;
        if (r == 0) { v[i] = std::make_shared<Circle>( Circle(myRand())); }
        else if (r == 1) { v[i] = std::make_shared<Ellipse>( Ellipse(myRand(), myRand())); }
        else if (r == 2) { v[i] = std::make_shared<Helix>(Helix(myRand(), myRand())); }
        else std::cout << "smth wrong" << std::endl;
    }
    std::cout << std::endl;
    std::cout << std::endl;

//   3. Print coordinates of points and derivatives of all curves in the container at t=PI/4.
    double param = PI / 4;
    for (int i = 0; i < n; ++i) {
        ( v[i]->getPoint(param) ).display();
        ( v[i]->getVector(param) ).display();
        std::cout << std::endl;
    }

//    4. Populate a second container that would contain only circles from the first container. Make sure the
//    second container shares (i.e. not clones) circles of the first one, e.g. via pointers.
    std::vector<std::shared_ptr<Circle>> circles;
    for (int i = 0; i < n; ++i) {
        if (v[i]->getType() == 1) circles.emplace_back(std::shared_ptr<Circle>(v[i]));
    }

//    5. Sort the second container in the ascending order of circles’ radii. That is, the first element has the
//    smallest radius, the last - the greatest.
    auto cmp = [ ] ( std::shared_ptr<Circle> it1, std::shared_ptr<Circle> it2) {
        return  it1->getRadius() < it2->getRadius();
    };
    std::sort(circles.begin(), circles.end(), cmp );

    for (int i = 0; i < circles.size(); ++i) std::cout << circles[i]->getRadius() << "\t";
    std::cout << std::endl;


//    6. Compute the total sum of radii of all curves in the second container.
    double radiiSum = 0;
    for (int i = 0; i < circles.size(); ++i) { radiiSum += circles[i]->getRadius();  }
    std::cout << "radii sum is: " << radiiSum << std::endl;

    return 0;
}