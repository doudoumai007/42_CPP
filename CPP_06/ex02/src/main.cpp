#include "Base.hpp"

int main()
{
    //Generate
    Base* test = generate();

    //Compare Ptr
    identify(test);

    //Compare Ref
    identify(*test);
    
    return (0);
}