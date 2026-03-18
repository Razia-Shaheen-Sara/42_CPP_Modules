#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <vector>
#include <deque>
#include <string>

class PmergeMe
{
    private:
        std::vector<int> _vec;
        std::deque<int>  _deq;
        double           _timeVec;
        double           _timeDeq;

        // Vector sort
        void    sortVector(std::vector<int>& vec);
        void    insertVector(std::vector<int>& main,
                             std::vector<int>& pending);

        // Deque sort
        void    sortDeque(std::deque<int>& deq);
        void    insertDeque(std::deque<int>& main,
                            std::deque<int>& pending);

        // Jacobsthal
        std::vector<int> buildJacobsthal(size_t limit);

    public:
        PmergeMe();
        PmergeMe(const PmergeMe& other);
        PmergeMe& operator=(const PmergeMe& other);
        ~PmergeMe();

        void    parseInput(int argc, char** argv);
        void    sort();
        void    printBefore() const;
        void    printAfter() const;
        void    printTimes() const;
};

#endif

// std::vector<int>
// Dynamic array (like C array but resizable)

// Basic syntax
// std::vector<int> v;
// std::vector<int> v(5);        // size 5
// std::vector<int> v = {1,2,3}; // C++11

// Common operations:
// v.push_back(10);     // add at end
// v.pop_back();        // remove last
// v[i];                // access (fast O(1))
// v.size();            
// v.begin(), v.end();  // iterators

//Use:
// contiguous memory (like array)
// fastest random access


// std::deque<int>
// Double-ended queue (array chunks internally)

// Syntax
// std::deque<int> d;
// Operations
// d.push_back(10);
// d.push_front(5);     // extra vs vector
// d.pop_back();
// d.pop_front();
// d[i];                // access (slightly slower than vector)


// fast insert/remove at front + back
// not contiguous memory
// random access exists but slower than vector

// vector vs deque (important)
// Feature	vector	deque
// memory	contiguous	fragmented
// push_back	fast	fast
// push_front	slow	fast
// random access	fastest	slightly slower

// In this project:
// vector = usually faster
// deque = just to compare behavior

// std::vector<bool>

// Special weird case:
// std::vector<bool> inserted;
// Not a real vector
// stores bits (compressed)
// ⚠️ behaves differently than normal vector


// Iterators (you used them)
// std::vector<int>::iterator it;
// Used like pointer:
// *it
// ++it

// With algorithms:

// std::lower_bound(v.begin(), v.end(), val);
// std::lower_bound
// What it does
// Binary search → gives position where element should go
// auto it = std::lower_bound(v.begin(), v.end(), val);
// v.insert(it, val);

// This is what actually keeps your array sorted

// auto keyword
//compiler figures out the type for you

// Example
// auto x = 5;           // int
// auto y = 3.14;        // double
// auto it = v.begin();  // iterator

// Same as:
// std::vector<int>::iterator it = v.begin();

// Common usage in your code
// auto pos = std::lower_bound(...);
// auto start = std::chrono::high_resolution_clock::now();


// vector → dynamic array, fastest access
// deque → flexible ends
// lower_bound → binary search insert position
// auto → let compiler write the type for you