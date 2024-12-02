#pragma once
#include <memory>
#include <unordered_map>
#include <queue>
#include <functional>
#include "Rubik.h"
#include "Move.h"

class Solver
{
    std::shared_ptr<Rubik> rubik;
    
    static const std::vector<Move> moves;  // Static list of moves

public:
    Solver(std::shared_ptr<Rubik> rubik);

    void run();
    void performSolution(const std::vector<Move>& shuffleMoves, int index);
    void performShuffleMoves(const std::vector<Move>& shuffleMoves, int index);
};



// Hash function for Rubik
namespace std {
    template <>
    struct hash<Rubik> {
        size_t operator()(const Rubik& rubik) const {
            // A more efficient hash function could be considered.
            // Using the state string for simplicity but can be optimized.
            std::string state = rubik.toString();
            size_t hashValue = 0;

            // Using FNV-1a hash for better distribution and fewer collisions
            const size_t FNV_offset_basis = 14695981039346656037U;
            const size_t FNV_prime = 1099511628211U;

            for (char c : state) {
                hashValue ^= static_cast<size_t>(c);
                hashValue *= FNV_prime;
            }

            return hashValue;
        }
    };
}
