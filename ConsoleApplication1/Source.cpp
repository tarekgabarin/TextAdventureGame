#include <iostream>
#include <string>

using String = std::string;

class TextAdventure 
{

	String CurrentAdventureText = "start of game";
	String CurentOptionsText = "stuff";
	
	enum GameTextTypes {
		ADVENTURE_TEXT = 1,
		OPTIONS_TEXT = 2,
	};

	enum TypesOfUseCommands {
		TALK = 1,
		LOOK = 2,
		USE = 3
	};

	public:
		void SetAdventureText(String NewText, GameTextTypes TypeOfGameText)
		{
			CurrentAdventureText  = NewText;
		}
		void ReadGameText(GameTextTypes TypeOfGameText)
		{
			switch (TypeOfGameText) {
				case 1:
					std::cout << CurrentAdventureText << std::endl;
					break;
				case 2:
					std::cout << CurentOptionsText << std::endl;
			}
		}

		///use unroderd maps for the scenes

		




};