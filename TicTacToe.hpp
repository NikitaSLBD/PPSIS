#pragma once 

using namespace std;

class TicTacToe
{
    private:
        bool player;

        void set_content(unsigned int);
        bool is_horizontal_win(char symbol);
        bool is_vertical_win(char symbol);
        bool is_diagonal_win(char symbol);

    public:
        char Field[10];
        TicTacToe(): Field("_________"), player(false) {};
        char get_content(unsigned int);
        bool get_player();
        void switch_player();
        void operator [] (unsigned int);
        bool is_win();
        bool is_tie();
        
};