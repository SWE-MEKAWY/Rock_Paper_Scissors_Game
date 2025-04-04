#include <iostream>
using namespace std;

enum enChoice {Stone = 1 , Paper = 2 , Scissor = 3};
enum enRoundStatus {PlayerIsTheWinner = 1 , CompIsTheWinner = 2 , Draw = 3};

int RandomNumber(int from, int to)
{
	int RandNum = rand() % (to - from + 1) + from;
	return RandNum;
}

int ReadNumber()
{
	int num;
	cout << "How Many Rounds You Want To Play \"maximum 10\" ?  ";
	cin >> num;
	return num;
}

void RoundHeader(int i)
{
	if (i >= 9)
	{
		cout << "\n------------------- Round " << "[" << (i + 1) << "] ------------------" << endl;
	}
	else
	{
		cout << "\n------------------- Round " << "[" << (i + 1) << "] -------------------" << endl;
	}
}

enChoice UserChoice()
{
	int UserInput;
	cout << "Your Choice : [1] Stone , [2] Paper , [3] Scissor ? ";
	cin >> UserInput;
	cout << "\n";
	switch (UserInput)
	{
	case 1:
		return enChoice::Stone;
		break;
	case 2:
		return enChoice::Paper;
		break;
	case 3:
		return enChoice::Scissor;
		break;
	default:
		break;
	}
}

enChoice ComputerChoice()
{
	int CompInput = RandomNumber(1, 3);
	
	switch (CompInput)
	{
	case 1:
		return enChoice::Stone;
		break;
	case 2:
		return enChoice::Paper;
		break;
	case 3:
		return enChoice::Scissor;
		break;
	default:
		break;
	}
}

enRoundStatus RoundStates(int rounds)
{
	for (int i = 0; i < rounds; i++)
	{
		RoundHeader(i);

		enChoice user = UserChoice();
		enChoice comp = ComputerChoice();

		if (user == enChoice::Stone && comp == enChoice::Stone)
		{
			
			cout << "Player  Choice  : Stone\n";
			cout << "Computer Choice : Stone\n";
			cout << "Round Winner    : No Winner\n";
			cout << system("color 60"); 
			return enRoundStatus::Draw;
		}
		else if (user == enChoice::Stone && comp == enChoice::Paper)
		{

			cout << "Player  Choice  : Stone\n";
			cout << "Computer Choice : Paper\n";
			cout << "Round Winner    : Computer\n";
			cout << system("color 40");
			return enRoundStatus::CompIsTheWinner;
		}
		else if (user == enChoice::Stone && comp == enChoice::Scissor)
		{
			
			cout << "Player  Choice  : Stone\n";
			cout << "Computer Choice : Scissor\n";
			cout << "Round Winner    : Player\n";
			cout << system("color 20");
			return enRoundStatus::PlayerIsTheWinner;
		}

		if (user == enChoice::Paper && comp == enChoice::Stone)
		{
			
			cout << "Player  Choice  : Paper\n";
			cout << "Computer Choice : Stone\n";
			cout << "Round Winner    : Player\n";
			cout << system("color 20");
			return enRoundStatus::PlayerIsTheWinner;
		}
		else if (user == enChoice::Paper && comp == enChoice::Paper)
		{
			
			cout << "Player  Choice  : Paper\n";
			cout << "Computer Choice : Paper\n";
			cout << "Round Winner    : No Winner\n";
			cout << system("color 60");
			return enRoundStatus::Draw;
		}
		else if (user == enChoice::Paper && comp == enChoice::Scissor)
		{
			
			cout << "Player  Choice  : Paper\n";
			cout << "Computer Choice : Scissor\n";
			cout << "Round Winner    : Computer\n";
			cout << system("color 40");
			return enRoundStatus::CompIsTheWinner;
		}

		if (user == enChoice::Scissor && comp == enChoice::Stone)
		{
			
			cout << "Player  Choice  : Scissor\n";
			cout << "Computer Choice : Stone\n";
			cout << "Round Winner    : Computer\n";
			cout << system("color 40");
			return enRoundStatus::CompIsTheWinner;
		}
		else if (user == enChoice::Scissor && comp == enChoice::Paper)
		{
			
			cout << "Player  Choice  : Scissor\n";
			cout << "Computer Choice : Paper\n";
			cout << "Round Winner    : Player\n";
			cout << system("color 20");
			return enRoundStatus::PlayerIsTheWinner;
		}
		else if (user == enChoice::Scissor && comp == enChoice::Scissor)
		{
			
			cout << "Player  Choice  : Scissor\n";
			cout << "Computer Choice : Scissor\n";
			cout << "Round Winner    : No Winner\n";
			cout << system("color 60");
			return enRoundStatus::Draw;
		}

	}
}

void FinalResult(int rounds)
{
	short PlayerCounter = 0, ComputerCounter = 0, DrawCounter = 0;

	for (int i = 0; i < rounds; i++)
	{
		enRoundStatus R = RoundStates(rounds);

		if (R == enRoundStatus::PlayerIsTheWinner)
		{
			PlayerCounter++;
		}
		if (R == enRoundStatus::CompIsTheWinner)
		{
			ComputerCounter++;
		}
		if (R == enRoundStatus::Draw)
		{
			DrawCounter++;
		}
	}

	cout << "\n_______________________________________________________________________\n";
	cout << "\n+-+-+-+-+-+-+-+-+-+-+-+- G A M E   O V E R +-+-+-+-+-+-+-+-+-+-+-+-+-+-\n";
	cout << "\n_______________________________________________________________________\n";
	cout << "\n                         Game Rounds : " << rounds << "\n";
	cout << "\n                         Player Win Times : " << PlayerCounter << "\n";
	cout << "\n                         Computer Win Times : " << ComputerCounter << "\n";
	cout << "\n                         Draw Times : " << DrawCounter << "\n";
	if (PlayerCounter > ComputerCounter)
	{
		cout << "\n                         The Winner Is The Player\n";
	}
	else if (PlayerCounter < ComputerCounter)
	{
		cout << "\n                         The Winner Is The Computer\n";
	}
	else
	{
		cout << "\n                         There Is No Winner Today :)\n";
	}
}

void PlayGame()
{
	char msg;
	do
	{
		int rounds = ReadNumber();
		FinalResult(rounds);
		cout << "\nDo You Want To Play Again ! Y/N ? ";
		cin >> msg;
		cout << system("color 07 && cls");
	} while (msg == "y" || msg == "Y");
}

int main()
{
	srand((unsigned)time(NULL));
	PlayGame();
	return 0;
}
//-------------------------------------------------------------------------------------------------------------//

