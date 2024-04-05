#include <iostream>
#include <cstdlib>

using namespace std;

enum en_game { stone = 1, paper, scissors };

enum en_result { lose, draw, win };

int random_number(int min, int max)
{
    int random_number = rand() % (max - min + 1) + min;
    return random_number;
}

short play_rounds()
{
    short rounds;
    do
    {
        cout << "\nHow many rounds do you want to play? ";
        cin >> rounds;
    } while (rounds <= 0);
    return rounds;
}

en_game user_choice()
{
    short user_choice;
    do
    {
        cout << "\nWhich is your choice: [1]Stone, [2]Paper,[3]Scissors? ";
        cin >> user_choice;
    } while (user_choice < 1 || user_choice > 3);
    return en_game(user_choice);
}

en_game computer_choice()
{
    en_game computer_choice = en_game(random_number(1, 3));
    return computer_choice;
}

en_result round_result(en_game user_choice, en_game computer_choice)
{
    if ((user_choice == stone && computer_choice == scissors) || (user_choice == scissors && computer_choice == paper) || (user_choice == paper && computer_choice == stone))
        return win;
    else if (user_choice == computer_choice)
        return draw;
    return lose;
}
  
void print_user_or_computer_choice(en_game choice)
{
    if (choice == stone)
        cout << "Stone";
    else if (choice == paper)
        cout << "Paper";
    else cout << "Scissors";
}

void print_round_winner(en_result round_result)
{
    if (round_result == lose)
        cout << "[Computer]";
    else if (round_result == draw)
        cout << "[No winner]";
    else if (round_result == win)
        cout << "[User]";
}

void print_round_result(en_game user_choice, en_game computer_choice, short round_number, en_result round_result)
{

    cout << "\n______________Round[" << round_number << "]______________";
    cout << "\nPlayer choice: ";
    print_user_or_computer_choice(user_choice);
    cout << "\nComputer choice: ";
    print_user_or_computer_choice(computer_choice);
    cout << "\nRound winner: ";
    print_round_winner(round_result);
    cout << "\n____________________________________\n";
}

en_result game_result(short won_rounds, short lost_rounds)
{
    if (won_rounds > lost_rounds)
        return win;
    else if (lost_rounds == won_rounds)
        return draw;
    return lose;
}

void print_game_result(en_result game_result)
{
    if (game_result == win)
        cout << "Player won";
    else if (game_result == draw)
        cout << "No winner";
    else if (game_result == lose)
        cout << "Computer won";
}

void print_game_result(short rounds_number, short user_won_rounds, short computer_won_rounds, short draw_rounds, en_result game_result)
{
    cout << "\n\t\t\t\t________________________________________";
    cout << "\n\t\t\t\t        +++ G a m e  O v e r +++      ";
    cout << "\n\t\t\t\t________________________________________\n";
    cout << "\n\t\t\t\t_____________[Game Results]_____________";
    cout << "\n\t\t\t\tGame rounds: " << rounds_number;
    cout << "\n\t\t\t\tPlayer won times: " << user_won_rounds;
    cout << "\n\t\t\t\tComputer won times: " << computer_won_rounds;
    cout << "\n\t\t\t\tDraw times: " << draw_rounds;
    cout << "\n\t\t\t\tFinal winner: ";
    print_game_result(game_result);
    cout << "\n\t\t\t\t________________________________________";
}

void game()
{
    short won_rounds = 0, lost_rounds = 0, draw_rounds = 0, game_rounds;
    en_game player_choice, computer_choices;
    en_result round_results, game_results;
    game_rounds = play_rounds();
    for (short round_number = 1; round_number <= game_rounds; round_number++)
    {
        cout << "\nRound [" << round_number << "] begin:\n";
        player_choice = user_choice();
        computer_choices = computer_choice();
        round_results = round_result(player_choice, computer_choices);
        if (round_results == win)
            won_rounds++;
        else if (round_results == lose)
            lost_rounds++;
        else draw_rounds++;
        print_round_result(player_choice, computer_choices, round_number, round_results);
    }
    game_results = game_result(won_rounds, lost_rounds);
    print_game_result(game_rounds, won_rounds, lost_rounds, draw_rounds, game_results);
}

void start_game()
{
    char play_again;
    do
    {
        game();
        do
        {
            cout << "\n\nDo you want to play again? (y/n)";
            cin >> play_again;
        } while (play_again != 'y' && play_again != 'Y' && play_again != 'n' && play_again != 'N');
    } while (play_again == 'y' || play_again == 'Y');
}

int main()
{
    srand((unsigned)time(NULL));
    start_game();
}