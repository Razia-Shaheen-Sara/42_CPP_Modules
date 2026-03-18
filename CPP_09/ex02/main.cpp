#include "PmergeMe.hpp"
#include <iostream>

int main(int argc, char** argv)
{
    if (argc < 2)
    {
        std::cerr << "Error" << std::endl;
        return 1;
    }
    try
    {
        PmergeMe pm;
        pm.parseInput(argc, argv);
        pm.printBefore();           // line 1: unsorted
        pm.sort();                  // sort both containers, store times
        pm.printAfter();            // line 2: sorted
        pm.printTimes();            // line 3 & 4: timing
    }
    catch (const std::exception& e)
    {
        std::cerr << e.what() << std::endl;
        return 1;
    }
    return 0;
}


// Ford-Johnson algorithm (Merge-Insertion Sort):
// Minimizes the number of comparisons compared to normal insertion sort.

// High-level steps:
// 1. Pair up elements left to right. If odd, last element is a "straggler".
// 2. Pick the bigger one from each pair and put in the main chain(unsorted at this point).
    //(Now the smaller ones from each pairs are pending to be inserted in main)
// 3. Recursively sort the main chain (coz bigger in pair does not mean sorted in main).
// 4. Insert the first pending element from the hanging/pending/sitting smaller elements.
//   // This is the smaller element paired with main[0],(but it may NOT be the smallest overall, 
    //DOES NOT matter here) coz it is guaranteed to be <= main[0](coz his pair), safe to insert first
// 5. Rest are sorted using a specific order called the Jacobsthal sequence.
// 6. Finally, insert the straggler if it exists.

//What is the Jacobsthal sequence?
// This is the key to Ford-Johnson. It determines the order in which you insert the 
//smaller elements back. Inserting in this order minimizes comparisons.
// J(0) = 0
// J(1) = 1
// J(n) = J(n-1) + 2 * J(n-2)
//J(2) = J(1) + 2J(0) = 1 + 20 = 1
//J(3) = J(2) + 2J(1) = 1 + 21 = 3
//J(4) = J(3) + 2J(2) = 3 + 21 = 5
// So: 0, 1, 3, 5, 11, 21, 43, 85, 171...
//You don't insert left to right — you jump around following this sequence, using it as indexes for the
//pending elements. 


// Example simpler array: [4, 6, 3, 5, 9]
// Step 1: Pair up: (4,6), (3,5), straggler=9
// Step 2: Sort pairs (bigger first): main = [6,5], pending = [4,3], straggler=9
// Step 3: Recursively sort main: [5,6]
// Step 4: insert pending[0] linked to main[0] → insert 4 before 5 → [4,5,6]
// Step 5: next in Jacobsthal order: pending[1] → insert 3 → [3,4,5,6]
// Step 5: Insert straggler 9 → binary search → [3,4,5,6,9]

// Result: [3,4,5,6,9]