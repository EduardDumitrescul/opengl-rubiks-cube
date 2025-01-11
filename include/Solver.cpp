#include "Solver.h"

Solver::Solver(std::shared_ptr<Rubik> rubik): rubik(rubik)
{
}

// Static member for the moves list
const std::vector<Move> Solver::moves = {
    UP, UP_REVERSE, DOWN, DOWN_REVERSE,
    FRONT, FRONT_REVERSE, BACK, BACK_REVERSE,
    LEFT, LEFT_REVERSE, RIGHT, RIGHT_REVERSE
};

void Solver::run()
{
    std::unordered_map<Rubik, int> distance;
    std::unordered_map<Rubik, Move> previous;
    std::queue<std::shared_ptr<Rubik>> queue;
        
    distance[*rubik] = 1;
    queue.push(rubik);  // Push the shared_ptr instead of copying the object

    int maxdist =  0;
    Rubik solvedCube;
    bool  solutionFound = false;
        
    while (!queue.empty() and solutionFound == false)
    {
        std::shared_ptr<Rubik> current = queue.front();
        queue.pop();
            
        // Use distance to track the state distance from the initial state
        if (maxdist < distance[*current])
        {
            maxdist++;
            if (maxdist == 5)
            {
                std::cout << "I'm not good enough to solve it\n";
                break;
            }
            std::cout << maxdist << std::endl;
        }
       

        for (const auto& move : moves)
        {
            std::shared_ptr<Rubik> next = std::make_shared<Rubik>(*current); 
            next->performMove(move, []{}, false);
                
            if (distance.find(*next) == distance.end())  // If the state hasn't been visited yet
            {
                distance[*next] = distance[*current] + 1;
                previous[*next] = move;
                queue.push(next);
            }

            if (current->isSolved())
            {
                solvedCube = *current;
                solutionFound = true;
                break;
            }
        }
    }

    if (solutionFound == true)
    {
        std::cout << "Solution found!" << std::endl;

        std::vector<Move> solution;
        while (!(*rubik == solvedCube))
        {
            Move move = previous[solvedCube];
            solution.push_back(previous[solvedCube]);
            solvedCube.performMove(move, []{}   , false);
            solvedCube.performMove(move, []{}   , false);
            solvedCube.performMove(move, []{}   , false);
        }

        std::reverse(solution.begin(), solution.end());
        performSolution(solution, 0);
    }
}

void Solver::performSolution(const std::vector<Move>& shuffleMoves, int index)
{
    if (index >= shuffleMoves.size()) {
        return;
    }

    Move move = shuffleMoves[index];

    auto callback = [this, shuffleMoves, index]() {
        performSolution(shuffleMoves, index + 1);
    };

    rubik->performMove(move, callback);
}
