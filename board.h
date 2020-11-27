#ifndef BOARD_H
#define BOARD_H

#include <iostream>
#include <vector>
#include <set>
#include <tuple>

static const size_t BOARD_ROW_COUNT = 3;
static const size_t BOARD_COLUMN_COUNT = 3;

struct Board {
  struct Move {
    Move(size_t row, size_t column)
      : row(row),
        column(column)
    {}

    size_t row = 0;
    size_t column = 0;
  };

  struct Cell {
    enum class State {
      Open = 0,
      X,
      O
    };

    Cell(size_t row, size_t column, State state = State::Open)
      : row(row),
        column(column),
        state(state)
    {}

    size_t row = 0;
    size_t column = 0;
    State state = State::Open;
  };

  Board();

  size_t rowCount() const {
    return BOARD_ROW_COUNT;
  }

  size_t columnCount() const {
    return BOARD_COLUMN_COUNT;
  }

  Cell::State getCellState(size_t row, size_t column) const;

  void setCellState(size_t row, size_t column, Cell::State state);

  bool isRowFilled(size_t row, Cell::State player);

  bool isColumnFilled(size_t column, Cell::State player);

  bool isTopLeftDiagonalFilled(Cell::State player);

  bool isBottomLeftDiagonalFilled(Cell::State player);

  bool isWinner(Cell::State player);

  bool isWinnerX();

  bool isWinnerO();

  std::set<std::tuple<size_t, size_t> > possibleMoves() const;
  bool isPossibleMove(size_t row, size_t column) const;
  bool isPossibleMove(std::tuple<size_t, size_t> coordinates) const;

  enum class GameState {
    Pending = 0,
    winX,
    winO,
    Draw
  };

  GameState checkGameState();

  void clear();

  static Board Create(const std::vector<Move> & moves);

  static Cell::State otherPlayer(Cell::State player);


  std::vector<Cell> cells;
};


std::ostream & operator<<(std::ostream & os, const Board & board);
std::ostream & operator<<(std::ostream & os, const std::tuple<size_t, size_t> & t);


#endif // BOARD_H
