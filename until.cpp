#include <iostream>
#include <functional>
#include <cassert>

using namespace std;

int until(int x, function<int(int)> f, function<bool(int)> g)
{
    while (!g(x))
    {
        x = f(x);
    }
    return x;
}

int double_number(int x)
{
    return x * 2;
}

bool greater_than_100(int x)
{
    return x > 100;
}

int add_five(int x)
{
    return x + 5;
}

bool at_least_20(int x)
{
    return x >= 20;
}

int subtract_one(int x)
{
    return x - 1;
}

bool less_than_0(int x)
{
    return x < 0;
}

int main()
{
    assert(until(1, double_number, greater_than_100) == 128);
    assert(until(0, add_five, at_least_20) == 20);
    assert(until(5, subtract_one, less_than_0) == -1);
    cout << "All tests passed!" << endl;

    return 0;
}

// Thought Provoking Questions:
//
// 1. A useful scenario for this would be when you would want to
// repeatedly apply an operation until a certain condition is met.
// For example, you might want to keep doubling a number until it
// exceeds a certain threshold, or keep adding a value until it
// reaches a target.
//
// 2. A variation that could be useful would be to add a max to the number
// of iterations to prevent infinite loops in case the condition is never met.