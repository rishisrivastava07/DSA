#include <iostream>
#include <vector>
#include <list>
#include <deque>
#include <stack>
#include <queue>
#include <set>
#include <map>

using namespace std;

void explainPair()
{
    pair<int, int> p1 = {1, 3};
    cout << p1.first << " " << p1.second << endl;
    pair<int, pair<int, int>> p2 = {1, {3, 4}};
    cout << p2.first << " " << p2.second.first << " " << p2.second.second << endl;
    pair<int, int> arr[] = {{1, 2}, {3, 4}, {5, 6}};

    cout << arr[1].second << endl;
}
// dynamic in nature
void explainVector()
{
    vector<int> v1;

    v1.push_back(1);
    v1.push_back(2);
    v1.emplace_back(3); // similar to push_back() and faster than push_back()

    vector<pair<int, int>> vec;

    vec.push_back({1, 2});
    vec.emplace_back(3, 4); // it will automatically takes it as a pair

    vector<int> v2(5, 100); // {100,100,100,100,100}
    // vector<int> v2(5);  // {0,0,0,0,0}
    // vector<int> v2(5,20); // {20,20,20,20}
    // vector<int> v2(v1); // v2 = {1,2,3}

    // accessing the vector
    vector<int>::iterator it = v2.begin();

    it++;
    cout << *(it) << " ";

    it = it + 2;
    cout << *(it) << endl;

    // vector<int> :: iterator it = v2.end();   // end will points right after the memory allocation of last element
    // vector<int> :: iterator it = v2.rend();
    // vector<int> :: iterator it = v2.rbegin();

    cout << v2[0] << " " << v2.at(0) << endl;
    cout << v2.back() << " ";

    for (vector<int>::iterator it = v2.begin(); it != v2.end(); it++)
    {
        cout << *(it) << " ";
    }

    for (auto it = v2.begin(); it != v2.end(); it++)
    {
        cout << *(it) << " ";
    }

    for (auto it : v2)
    {
        cout << it << " ";
    }

    // delete element from vector v2
    v2.erase(v2.begin() + 1);
    v2.erase(v2.begin() + 2, v2.begin() + 4); // [start,end)

    // insert function
    vector<int> v3(2, 100);
    v3.insert(v3.begin(), 300);
    v3.insert(v3.begin() + 1, 2, 10);

    vector<int> copy(2, 50);
    v3.insert(v3.begin(), copy.begin(), copy.end());

    cout << v3.size();

    v3.pop_back();
    v3.swap(v2);
    v3.clear(); // erases the entire vector
    cout << v3.empty();
}

void explainList()
{
    list<int> ls;

    ls.push_back(2);    // {2}
    ls.emplace_back(4); // {2,4}

    ls.push_front(5); // {5,2,4}

    ls.emplace_front(); // {2,4};
    // rest functions same as vector
    // begin, end, rbegin, rend, clear, insert, size, swap
}

void explainDeque()
{
    deque<int> dq;
    dq.push_back(1);     // {1}
    dq.emplace_back(2);  // {1,2}
    dq.push_front(4);    // {4,1,2}
    dq.emplace_front(3); // {3,4,1,2}

    dq.pop_back();  // {3,4,1}
    dq.pop_front(); // {4,1}

    dq.back();
    dq.front();

    // rest functions same as vector
    // begin, end, rbegin, rend, clear, insert, size, swap
}

void explainStack()
{
    stack<int> st;
    st.push(1);
    st.push(2);
    st.push(3);
    st.push(3);
    st.emplace(5);
}

void explainPQ()
{
    // max heap
    priority_queue<int> pq;
    pq.push(5);
    pq.push(2);
    pq.push(8);

    pq.emplace(10);

    cout << pq.top() << " ";

    // min heap
    priority_queue<int, vector<int>, greater<int>> pq1;

    pq1.push(5);
    pq1.push(2);
    pq1.push(8);

    pq1.emplace(10);

    cout << pq1.top();
}

void explainSet()
{
    // stores everything in sorted order and its unique
    set<int> st;
    st.insert(1);  // {1}
    st.insert(21); // {1,21}
    st.insert(5);  // {1,5,21}
    st.insert(3);  // {1,3,5,21}
    st.emplace(2); // {1,2,3,5,21}

    auto it = st.find(3);  // returns an iterator which points to 3 and stored in variable "it".
    auto it2 = st.find(6); // if not present then always return the after st.end()
}

void explainMap()
{
    map<int, int> mp;
    map<int, pair<int, int>> mp1;
    map<pair<int, int>, int> mp2;

    mp[1] = 2;
    mp.insert({3, 1});
    mp.emplace(2, 4);

    mp2[{2, 3}] = 10;
}
int main()
{
    // cout << "Hello " << endl;
    // explainPair();
    // explainPQ();
    explainSet();
    return 0;
}