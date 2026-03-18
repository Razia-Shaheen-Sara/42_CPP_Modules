#include "PmergeMe.hpp"
#include <iostream>
#include <algorithm>
#include <stdexcept>
#include <vector>
#include <deque>
#include <chrono>

PmergeMe::PmergeMe() {}
PmergeMe::PmergeMe(const PmergeMe& src) : _vec(src._vec), _deq(src._deq) {}
PmergeMe& PmergeMe::operator=(const PmergeMe& src) 
{
    if (this != &src) { _vec = src._vec; _deq = src._deq; }
    return *this;
}
PmergeMe::~PmergeMe() {}

void PmergeMe::printBefore() const
{
    std::cout << "Before: ";
    for (size_t i = 0; i < _vec.size(); i++)
        std::cout << _vec[i] << " ";
    std::cout << std::endl;
}

void PmergeMe::printTimes() const
{
    std::cout << "Time to process a range of " << _vec.size()
              << " elements with std::vector : "
              << _timeVec << " us" << std::endl;
    std::cout << "Time to process a range of " << _deq.size()
              << " elements with std::deque  : "
              << _timeDeq << " us" << std::endl;
}

void PmergeMe::printAfter() const
{
    std::cout << "After: ";
    for (size_t i = 0; i < _vec.size(); i++)
        std::cout << _vec[i] << " ";
    std::cout << std::endl;
}
std::vector<int> PmergeMe::buildJacobsthal(size_t limit)
{
    std::vector<int> jac = {0, 1};//J(0) = 0, J(1) = 1
    while (jac.back() < (int)limit)//keep building until we reach the limit (size of pending)
        jac.push_back(jac[jac.size() - 1] + 2 * jac[jac.size() - 2]);//J(n) = J(n-1) + 2 * J(n-2)
    return jac;//return array of Jacobsthal numbers up to the limit (size of pending)
}
void PmergeMe::insertVector(std::vector<int>& main, std::vector<int>& pending)
{
    std::vector<int> jac = buildJacobsthal(pending.size());
    std::vector<int> order;//make a variable to store the order of indexes
    std::vector<bool> inserted(pending.size(), false);//flag to keep track
    for (size_t j = 1; j < jac.size(); j++)
    {
        int jacv = jac[j];//current Jacobsthal number
        int prev = jac[j - 1];//previous Jacobsthal number
        for (int idx = jacv - 1; idx >= prev; idx--)//go backwards from jacv-1 to prev;idx = index of an element inside pending
        {
            if (idx < (int)pending.size() && !inserted[idx])
            {
                order.push_back(idx);//build the order of indexes to insert based on Jacobsthal sequence
                inserted[idx] = true;
            }
        }//after this loop, we got the order in which we will insert the pending elements into main
    }
    for (size_t i = 0; i < pending.size(); i++)//add any remaining indexes that were not added in the Jacobsthal loop
        if (!inserted[i])
            order.push_back(i);
    //take each value stored inside order and assign it to k
    for (int k : order)//range based loop to actually insert following order
    {
        int val = pending[k];
        auto pos = std::upper_bound(main.begin(), main.end(), val);//find the position to insert val in main to keep it sorted
        main.insert(pos, val);
    }
}
void PmergeMe::sortVector(std::vector<int>& vec)
{
    if (vec.size() <= 1)
        return;
    std::vector<int> main_chain;
    std::vector<int> pending;
    int straggler = -1;
    bool hasStraggler = false;
    if (vec.size() % 2 != 0)//if odd
    {
        straggler = vec.back();//last element is straggler
        vec.pop_back();//remove last element from vec
        hasStraggler = true;
    }
    for (size_t i = 0; i < vec.size(); i += 2)
    {
        int a = vec[i], b = vec[i + 1];//pair up
        if (a > b) std::swap(a, b);//sort pair (bigger first)
        main_chain.push_back(b);//bigger goes to main
        pending.push_back(a);//smaller goes to pending
    }
    sortVector(main_chain);//recursively sort main
    std::vector<int>::iterator pos =
        std::upper_bound(main_chain.begin(), main_chain.end(), pending[0]);//find position to insert pending[0] (linked to main[0])
    main_chain.insert(pos, pending[0]);//insert first pending element (linked to main[0])
    pending.erase(pending.begin());//remove first pending element
    insertVector(main_chain, pending);//insert rest of pending in Jacobsthal order
    if (hasStraggler)
    {
        auto pos = std::upper_bound(main_chain.begin(), main_chain.end(), straggler);//find position to insert straggler
        main_chain.insert(pos, straggler);
    }
    vec = std::move(main_chain);//move sorted main_chain back to vec (efficient move, no copy)
}
void PmergeMe::insertDeque(std::deque<int>& main, std::deque<int>& pending)
{
    std::vector<int> jac = buildJacobsthal(pending.size());
    std::vector<int> order;
    std::vector<bool> inserted(pending.size(), false);
    for (size_t j = 1; j < jac.size(); j++)
    {
        int jacv = jac[j];
        int prev = jac[j - 1];
        for (int idx = jacv - 1; idx >= prev; idx--)
        {
            if (idx < (int)pending.size() && !inserted[idx])
            {
                order.push_back(idx);
                inserted[idx] = true;
            }
        }
    }
    for (size_t i = 0; i < pending.size(); i++)
        if (!inserted[i])
            order.push_back(i);
    for (int idx : order)
    {
        int val = pending[idx];
        auto pos = std::upper_bound(main.begin(), main.end(), val);
        main.insert(pos, val);
    }
}
void PmergeMe::sortDeque(std::deque<int>& deq)
{
    if (deq.size() <= 1)
        return;
    std::deque<int> main_chain;
    std::deque<int> pending;
    int straggler = -1;
    bool hasStraggler = false;
    if (deq.size() % 2 != 0)
    {
        straggler = deq.back();
        deq.pop_back();
        hasStraggler = true;
    }
    for (size_t i = 0; i < deq.size(); i += 2)
    {
        int a = deq[i], b = deq[i + 1];
        if (a > b) std::swap(a, b);
        main_chain.push_back(b);
        pending.push_back(a);
    }
    sortDeque(main_chain);
    std::deque<int>::iterator pos =
        std::upper_bound(main_chain.begin(), main_chain.end(), pending[0]);
    main_chain.insert(pos, pending[0]);
    pending.pop_front();
    insertDeque(main_chain, pending);
    if (hasStraggler)
    {
        auto pos = std::upper_bound(main_chain.begin(), main_chain.end(), straggler);
        main_chain.insert(pos, straggler);
    }

    deq = std::move(main_chain);
}
// std::chrono → library for time // high_resolution_clock → a precise clock
// ::now() → gives current time point
// auto → compiler figures the type (it’s a time-point type)
void PmergeMe::sort()
{
    auto startVec = std::chrono::high_resolution_clock::now();//store the current time (very precise) in startVec
    sortVector(_vec);
    auto endVec = std::chrono::high_resolution_clock::now();
    auto startDeq = std::chrono::high_resolution_clock::now();
    sortDeque(_deq);
    auto endDeq = std::chrono::high_resolution_clock::now();
    _timeVec = std::chrono::duration<double, std::micro>(endVec - startVec).count();
    _timeDeq = std::chrono::duration<double, std::micro>(endDeq - startDeq).count();
}

void PmergeMe::parseInput(int argc, char** argv)
{
    for (int i = 1; i < argc; i++)
    {
        try 
        {
            int val = std::stoi(argv[i]);//stoi = string to int, throws std::invalid_argument if not a number, std::out_of_range if too big
            if (val <= 0)
                throw std::runtime_error("Error");
            _vec.push_back(val);
            _deq.push_back(val);
        }
        catch (...) //... means catch all exceptions, including std::invalid_argument and std::out_of_range from stoi
        {
            throw std::runtime_error("Error");
        }
    }
    if(_vec.empty())
        throw std::runtime_error("Error");
}