#include <stack>
#include <assert.h>
using namespace std;

int main()
{
    stack<char> s;
    assert(s.empty());
    s.push('a');
    assert('a' == s.top());
    s.pop();
    s.push('b');
    s.push('c');
    s.push('x');
    assert(3 == s.size());

    s.pop();
    assert(2 == s.size());

    s.pop();
    assert(1 == s.size());
}