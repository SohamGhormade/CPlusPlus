#include<stack>
#include<queue>
#include "IntStack.cpp"
#include "MyQueue.cpp"
#include <gtest/gtest.h> // googletest header file
#include "heap.cpp"

using namespace std;

TEST(StackTest, EmptyTest) {
    stack<int> stk;
    EXPECT_EQ(1, stk.empty());
}


TEST(StackTest, SizeTest) {
    stack<int> stk;
    stk.push(1);
    stk.push(2);
    stk.push(3);
    stk.push(4);
    EXPECT_EQ(4, stk.size());
    stk.pop();
    EXPECT_EQ(3, stk.size());
}

TEST(StackTest, EmplaceTest) {
    stack<int> stk;
    stk.emplace(1);
    EXPECT_EQ(1, stk.size());
}


TEST(IntStackTest, EmptyTest) {
    IntStack stk;
    EXPECT_EQ(1, stk.empty());
}


TEST(IntStackTest, SizeTest) {
    IntStack stk;
    stk.push(1);
    EXPECT_EQ(1, stk.size());

    stk.push(2);
    EXPECT_EQ(2, stk.size());

    stk.push(3);
    EXPECT_EQ(3, stk.size());

    stk.push(4);
    EXPECT_EQ(4, stk.size());

    stk.pop();
    EXPECT_EQ(3, stk.size());
}

TEST(QueueTest, Enqueue){
    queue<double>q;
    EXPECT_EQ(1, q.empty());
    q.push(1.0);
    q.push(2.0);
    EXPECT_EQ(0, q.empty());
    EXPECT_EQ(2, q.size());
    q.push(-1.0);
    q.push(-2.0);
    double d = q.front();
    EXPECT_EQ(1.0, q.front());
    EXPECT_EQ(-2.0, q.back());

}


TEST(QueueTest, Dequeue){
    queue<string>q;
    EXPECT_EQ(1, q.empty());
    q.push("Hello");
    q.push("Hi");
    EXPECT_EQ(0, q.empty());
    EXPECT_EQ(2, q.size());
    EXPECT_EQ("Hello", q.front());
    EXPECT_EQ("Hi", q.back());
    q.pop();
    q.pop();
    EXPECT_EQ("", q.front());
    EXPECT_EQ("Hi", q.back());//WHY?
    q.push("Smith");
    EXPECT_EQ("Smith", q.front());
    EXPECT_EQ("Smith", q.back());
    q.push("John");
    EXPECT_EQ("Smith", q.front());
    EXPECT_EQ("John", q.back());
}
#pragma region MyQueue
TEST(MyQueueTest, Enqueue){
    MyQueue<double>q;
    EXPECT_EQ(1, q.empty());
    q.push(1.0);
    q.push(2.0);
    EXPECT_EQ(0, q.empty());
    EXPECT_EQ(2, q.size());
    q.push(-1.0);
    q.push(-2.0);
    double d = q.front();
    EXPECT_EQ(1.0, q.front());
    EXPECT_EQ(-2.0, q.back());

}


TEST(MyQueueTest, DISABLED_Dequeue){
    MyQueue<string>q;
    EXPECT_EQ(1, q.empty());
    q.push("Hello");
    q.push("Hi");
    EXPECT_EQ(0, q.empty());
    EXPECT_EQ(2, q.size());
    EXPECT_EQ("Hello", q.front());
    EXPECT_EQ("Hi", q.back());
    q.pop();
    q.pop();
    EXPECT_EQ("", q.front());
    EXPECT_EQ("Hi", q.back());//WHY?
    q.push("Smith");
    EXPECT_EQ("Smith", q.front());
    EXPECT_EQ("Smith", q.back());
    q.push("John");
    EXPECT_EQ("Smith", q.front());
    EXPECT_EQ("John", q.back());
}
#pragma endregion

#pragma region Vector
TEST(Vector,push_back_test)
{
    vector<int> v;
    EXPECT_EQ(true, v.empty());
    v.push_back(1);

    EXPECT_EQ(0, v.empty());
    v.push_back(2);
    EXPECT_EQ(0, v.empty());

    v.push_back(3);
    EXPECT_EQ(3, v.size());

    v.pop_back();
    EXPECT_EQ(1, v[0]);
    EXPECT_EQ(2, v[1]);
    EXPECT_EQ(1, v[0]);
    EXPECT_EQ(1, v.at(0));
    EXPECT_EQ(2, v.size());

    v.insert(v.begin() + 1, 4);
    EXPECT_EQ(3, v.size());
    EXPECT_EQ(4, v.at(1));
}
#pragma endregion

#pragma region Heap
TEST(HeapTest, Heap){
    vector<int>v;
    v.push_back(20);
    v.push_back(100);
    v.push_back(30);
    make_heap(v.begin(),v.end());
    EXPECT_EQ(100, v.front());
    pop_heap(v.begin(), v.end());
    EXPECT_EQ(30, v.front());
}

TEST(HeapTest, MyHeap){
    Heap<int> *h = new Heap<int>();
    h->insert(20);
    h->insert(100);
    h->insert(30);
    EXPECT_EQ(100, h->delMax());
    EXPECT_EQ(30, h->delMax());
    h = NULL;
}

#pragma endregion

int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();}
