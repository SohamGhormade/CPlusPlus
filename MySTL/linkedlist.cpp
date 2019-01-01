#include <list>
#include <assert.h>
#include<string>
#include<iostream>
using namespace std;

int main()
{
    list<string> l;
    assert(l.empty());
    l.emplace_front("blah");
    l.emplace_front("blah1");
    assert(2==l.size());
    l.emplace_back("xyz");
    l.push_back("abc");
    for(list<string>::iterator i = l.begin();i!=l.end();++i)
    {
        cout<<*i<<endl;

    }
    l.push_back("abc");
    l.clear();
    assert(l.empty());

}