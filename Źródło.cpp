#include <iostream>
#include <ctime>
#include <cstdlib>

int playerwin=0, computerwin=0;

//funkcja rejestrujaca wybor gracza
char getUserChoice()
{
	char player;
	std::cout << "Rock-Paper-Sciccors Game!\n";
	std::cout << "**************************\n";
	do
	{
		std::cout << "Choose 1\n***\n'r' for rock\n'p' for paper\n's'for scissors\n";
		std::cin >> player;
	} while (player!='r'&& player != 'p'&& player != 's');
	
	return player;
}

//funkcja pseudolosujaca wybor komputera
char getComputerChoice()
{
	srand(time(0));
	int num = rand() % 3 + 1;

	switch (num)
	{
	case 1: return'r';
	case 2: return'p';
	case 3: return's';
	}
	return 0;
}

//funkcja oglaszajaca wybor
void showChoice(char choice) 
{
	switch (choice)
	{
	case 'r': std::cout << "Rock\n";
		break;
	case 'p': std::cout << "Paper\n";
		break;
	case 's': std::cout << "Scissors\n";
		break;
	}
}

//funkcja sprawdzajaca, kto wygra³
void chooseWinner(char player, char computer)
{
	switch (player)
	{
	case 'r': if (computer == 'r')
				{
				std::cout<<"It's a tie!\n";
				}
				else if (computer == 'p')
				{
				std::cout<<"You lost!\n";
				computerwin++;
				}
				else
				{
				std::cout<<"You win!\n";
				playerwin++;
				}
					break;
	case 'p': if (computer == 'p')
				{
				std::cout << "It's a tie!\n";
				}
				else if (computer == 's')
				{
				std::cout << "You lost!\n";
				computerwin++;
				}
				else
				{
				std::cout << "You win!\n";
				playerwin++;
				}
					break;
	case 's': if (computer == 's')
				{
				std::cout << "It's a tie!\n";
				}
				else if (computer == 'r')
				{
				std::cout << "You lost!\n";
				computerwin++;
				}
				else
				{
				std::cout << "You win!\n";
				playerwin++;
				}
					break;
				}
}

int main()
{
	int ending;

	for(int i=0;i<=5;i++)
	{
		do
		{
			char player;
			char computer;

			player = getUserChoice();
			system("cls");
			std::cout << "Your choice: ";
			showChoice(player);

			computer = getComputerChoice();
			std::cout << "Computer's choice: ";
			showChoice(computer);


			chooseWinner(player, computer);


			std::cout << "\n\nYou won: " << playerwin;
			std::cout << "\nComputer won: " << computerwin << "\n";


			std::cout << "If you want to end, type in 0. If not, type in any other number...";
			std::cin >> ending;

			system("cls");
		} while (ending != 0);
	}
	if (playerwin < computerwin)
	{
		std::cout << "\nYou lost";
	}
	else if (playerwin > computerwin)
	{
		std::cout << "\nYou won";
	}
	else
	{
		std::cout << "\n It's a draw";
	}
	
	return 0;
}