#include "QuadraticFunction.hpp"

int main() {
    QuadraticFunction function;
    function.Start();
    std::cout << "a = " << function.a << ", b = " << function.b << ", c = " << function.c << std::endl;
    std::cout << "number of x-intersepts = " << function.x_intersept_count << std::endl;
    function.Roots();
    function.Vertex();
    return 0;
}


//-1x^2-10x+3