#include "RubikShuffler.h"

RubikShuffler::RubikShuffler(std::shared_ptr<Rubik> rubik): rubik(rubik)
{
    std::srand(std::time(0)); 
}

void RubikShuffler::shuffle()
{
    std::vector<Move> shuffleMoves;
    for (int i = 0; i < MOVES; i++) {
        int randomMoveIndex = 7 * std::rand() % 12;
        switch (randomMoveIndex)
        {
        case 0: shuffleMoves.push_back(Move::UP); break;
        case 1: shuffleMoves.push_back(Move::UP_REVERSE); break;
        case 2: shuffleMoves.push_back(Move::DOWN); break;
        case 3: shuffleMoves.push_back(Move::DOWN_REVERSE); break;
        case 4: shuffleMoves.push_back(Move::LEFT); break;
        case 5: shuffleMoves.push_back(Move::LEFT_REVERSE); break;
        case 6: shuffleMoves.push_back(Move::RIGHT); break;
        case 7: shuffleMoves.push_back(Move::RIGHT_REVERSE); break;
        case 8: shuffleMoves.push_back(Move::FRONT); break;
        case 9: shuffleMoves.push_back(Move::FRONT_REVERSE); break;
        case 10: shuffleMoves.push_back(Move::BACK); break;
        case 11: shuffleMoves.push_back(Move::BACK_REVERSE); break;
        }
    }

    performShuffleMoves(shuffleMoves, 0);
}

void RubikShuffler::performShuffleMoves(const std::vector<Move>& shuffleMoves, int index)
{
    if (index >= shuffleMoves.size()) {
        return;
    }

    Move move = shuffleMoves[index];

    auto callback = [this, shuffleMoves, index]() {
        performShuffleMoves(shuffleMoves, index + 1);
    };

    rubik->performMove(move, callback);
}
