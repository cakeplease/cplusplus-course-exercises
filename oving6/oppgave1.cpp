#include <iostream>
#include <memory>
#include <string>
#include <vector>
#include <functional>


/**
 * This code is based on example1.cpp from Ole Christian Eidheim from lecture:Funksjonsobjekter og trådprogrammering: https://gitlab.com/ntnu-iini4003/examples6/-/blob/master/example1.cpp?ref_type=heads
 */

using namespace std;

class ChessBoard {
public:
    enum class Color { WHITE, BLACK };

    class Piece {
    public:
        Piece(Color color) : color(color) {}
        virtual ~Piece() {}

        Color color;
        std::string color_string() const {
            if (color == Color::WHITE)
                return "white";
            else
                return "black";
        }

        /// Return color and type of the chess piece
        virtual std::string type() const = 0;

        /// Returns true if the given chess piece move is valid
        virtual bool valid_move(int from_x, int from_y, int to_x, int to_y) const = 0;

        virtual string short_name() const;
    };

    class King : public Piece {
    public:
        King(Color color_) : Piece(color_) {}

        string type() const {
            return color_string() + " king";
        }

        bool valid_move(int from_x, int from_y, int to_x, int to_y) const {
            int abs_move_x = abs(from_x-to_x);
            int abs_move_y = abs(from_y-to_y);

            if ((abs_move_x == 0 || abs_move_x == 1) && (abs_move_y == 0 || abs_move_y == 1)) {
                return true;
            } else {
                return false;
            }
        }

        string short_name() const {
            return color_string().substr(0, 1)+"K";
        }

    };

    class Knight : public Piece {
    public:
        Knight(Color color_) : Piece(color_) {}

        string type() const {
            return color_string() + " knight";
        }
        virtual bool valid_move(int from_x, int from_y, int to_x, int to_y) const {
            int abs_move_x = abs(from_x-to_x);
            int abs_move_y = abs(from_y-to_y);

            if ((abs_move_x == 1 || abs_move_x == 2) && (abs_move_y == 1 || abs_move_y == 2)) {
                return true;
            } else {
                return false;
            }
        }

        string short_name() const {
            return color_string().substr(0, 1)+"k";
        }
    };

    ChessBoard() {
        // Initialize the squares stored in 8 columns and 8 rows:
        squares.resize(8);
        for (auto &square_column : squares)
            square_column.resize(8);
    }

    /// 8x8 squares occupied by 1 or 0 chess pieces
    vector<vector<unique_ptr<Piece>>> squares;

    function<void(const Piece &piece, const string &from, const string &to)> on_piece_move;
    function<void(const Piece &piece, const string &square)> on_piece_removed;
    function<void(Color color)> on_lost_game;
    function<void(const Piece &piece, const string &from, const string &to)> on_piece_move_invalid;
    function<void(const string &square)> on_piece_move_missing;
    function<void(const vector<vector<unique_ptr<Piece>>> &squares)> after_piece_move; // added after_piece_move function


    /// Move a chess piece if it is a valid move
    bool move_piece(const std::string &from, const std::string &to) {
        int from_x = from[0] - 'a';
        int from_y = stoi(string() + from[1]) - 1;
        int to_x = to[0] - 'a';
        int to_y = stoi(string() + to[1]) - 1;

        auto &piece_from = squares[from_x][from_y];
        if (piece_from) {
            if (piece_from->valid_move(from_x, from_y, to_x, to_y)) {
                if (on_piece_move)
                    on_piece_move(*piece_from, from, to);
                auto &piece_to = squares[to_x][to_y];
                if (piece_to) {
                    if (piece_from->color != piece_to->color) {
                        if (on_piece_removed)
                            on_piece_removed(*piece_to, to);
                        if (auto king = dynamic_cast<King *>(piece_to.get())) {
                            if (on_lost_game)
                                on_lost_game(king->color);
                        }
                    } else {
                        // piece in the from square has the same color as the piece in the to square
                        if (on_piece_move_invalid)
                            on_piece_move_invalid(*piece_from, from, to);
                        return false;
                    }
                }
                piece_to = move(piece_from);
                after_piece_move(squares); //prints chessboard
                return true;
            } else {
                if (on_piece_move_invalid)
                    on_piece_move_invalid(*piece_from, from, to);
                return false;
            }
        } else {
            if (on_piece_move_missing)
                on_piece_move_missing(from);
            return false;
        }
    }
};

/**
 * My new ChessBoardPrint class
 */
class ChessBoardPrint {
public:
    ChessBoardPrint(ChessBoard &chessBoard) {
        chessBoard.on_piece_move = [](const ChessBoard::Piece &piece, const string &from, const string &to) {
            cout << piece.type() << " is moving from " << from << " to " << to << endl;
        };
        chessBoard.on_piece_removed = [](const ChessBoard::Piece &piece, const string &square) {
            cout << piece.type() << " is being removed from " << square << endl;
        };
        chessBoard.on_lost_game = [](ChessBoard::Color color) {
            if (color == ChessBoard::Color::WHITE)
                cout << "Black";
            else
                cout << "White";
            cout << " won the game" << endl;
        };
        chessBoard.on_piece_move_invalid = [](const ChessBoard::Piece &piece, const string &from, const string &to) {
            cout << "can not move " << piece.type() << " from " << from << " to " << to << endl;
        };
        chessBoard.on_piece_move_missing = [](const string &square) {
            cout << "no piece at " << square << endl;
        };
        //prints whole chessboard
        chessBoard.after_piece_move = [](const vector<vector<unique_ptr<ChessBoard::Piece>>> &squares) {
            for(int row = 7; row >= 0; row--) {
                for(int col = 0; col < 8; col++) {

                    auto &piece = squares[col][row];
                    if (piece) {
                        cout << "["+piece->short_name()+"]";
                    } else {
                        cout << "[ ]";
                    }
                }
                cout << endl;
            }
        };
    }
};

string ChessBoard::Piece::short_name() const {
    return std::string();
}

int main() {

    ChessBoard board;
    ChessBoardPrint ChessBoardPrint(board); // prints chessboard

    board.squares[4][0] = make_unique<ChessBoard::King>(ChessBoard::Color::WHITE);
    board.squares[1][0] = make_unique<ChessBoard::Knight>(ChessBoard::Color::WHITE);
    board.squares[6][0] = make_unique<ChessBoard::Knight>(ChessBoard::Color::WHITE);

    board.squares[4][7] = make_unique<ChessBoard::King>(ChessBoard::Color::BLACK);
    board.squares[1][7] = make_unique<ChessBoard::Knight>(ChessBoard::Color::BLACK);
    board.squares[6][7] = make_unique<ChessBoard::Knight>(ChessBoard::Color::BLACK);

    cout << "Invalid moves:" << endl;
    board.move_piece("e3", "e2");
    board.move_piece("e1", "e3");
    board.move_piece("b1", "b2");
    cout << endl;

    cout << "A simulated game:" << endl;
    cout << "Name convention: first letter is color, black or white, then k- knight K- king" << endl;
    board.move_piece("e1", "e2");
    board.move_piece("g8", "h6");
    board.move_piece("b1", "c3");
    board.move_piece("h6", "g8");
    board.move_piece("c3", "d5");
    board.move_piece("g8", "h6");
    board.move_piece("d5", "f6");
    board.move_piece("h6", "g8");
    board.move_piece("f6", "e8");

}