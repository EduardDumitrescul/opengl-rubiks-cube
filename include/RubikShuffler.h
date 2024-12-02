#include <memory>
#include <cstdlib>
#include <ctime>

#include "Move.h"
#include "Rubik.h"

class RubikShuffler
{
    std::shared_ptr<Rubik> rubik;
    static const int MOVES = 12; 

public:
    RubikShuffler(std::shared_ptr<Rubik> rubik);

    void shuffle();

private:
    void performShuffleMoves(const std::vector<Move>& shuffleMoves, int index);
};
