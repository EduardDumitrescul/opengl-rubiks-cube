#pragma once
#include <map>
#include <memory>
#include <queue>

#include "Rubik.h"

class RubikSolver
{
    std::shared_ptr<Rubik> rubik;
    std::vector <Move> moves = {
        UP, UP_REVERSE, DOWN, DOWN_REVERSE,
        LEFT, LEFT_REVERSE, RIGHT, RIGHT_REVERSE,
        FRONT, FRONT_REVERSE, BACK, BACK_REVERSE
    };

    void bfs()
    {
        Rubik solvedRubik;

        // This stores the shortest distance to each state
        std::map<Rubik, int> distance;
        // This maps each state to the move that was used to reach it
        std::map<Rubik, Move> moveMade;

        distance[*rubik] = 0;  // Starting state has distance 0
        std::queue<Rubik> queue;
        queue.push(*rubik);  // Start with the initial Rubik state

        while (!queue.empty())
        {
            Rubik current = queue.front();
            int dist = distance[current];
            queue.pop();

            if (current.isSolved())
            {
                solvedRubik = current;
                break;
            }

            for (Move move : moves)
            {
                Rubik next = current;  // Copy the current state
                next.performMove(move, []{}, false);  // Apply the move
            
                if (distance.find(next) == distance.end())  // State not visited yet
                {
                    distance[next] = dist + 1;  // Mark the distance
                    moveMade[next] = move;  // Record the move that led here
                    queue.push(next);  // Enqueue the next state
                }
            }
        }

        if (solvedRubik.isSolved())
        {
            std::vector<Move> solution;
            Rubik backtrack = solvedRubik;
        
            // Backtrack to find the solution sequence
            while (!(backtrack == *rubik))
            {
                Move move = moveMade[backtrack];
                solution.push_back(move);
                backtrack.performMove(move, []{}, true);  // Reverse the move
                backtrack.performMove(move, []{}, true);  // Reverse the move
                backtrack.performMove(move, []{}, true);  // Reverse the move
            }

            // Reverse the solution to get it in the correct order
            std::reverse(solution.begin(), solution.end());

            performMoves(solution, 0);
        }
    }

    void performMoves(const std::vector<Move>& moves, int index)
    {
        if (index >= moves.size()) {
            return;
        }

        Move move = moves[index];

        auto callback = [this, moves, index]() {
            performMoves(moves, index + 1);
        };

        rubik->performMove(move, callback);
    }

    

    
public:
    RubikSolver(std::shared_ptr<Rubik> rubik)
    {
        this->rubik = rubik;
    }

    void solve()
    {
        
    }
};
