#include <queue>
#include <assert.h>

using namespace std;
//queue is FIFO
// use STL library
int main()
{
    queue<int> q;
    assert(q.empty());

    q.push(1);
    assert(1 == q.front());

    q.push(11);
    assert(11 == q.back());

    q.push(111);
    assert(!q.empty());
    assert(111 == q.back());

    q.pop();
    assert(111 == q.back());
    assert(11 == q.front());
    assert(2==q.size());
}