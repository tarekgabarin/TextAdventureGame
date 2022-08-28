#include <iostream>
#include <string>
#include <vector>

using String = std::string;

/// <summary>
/// The base Hotspot class for the whenever the player does an action. Is versatile enough for all three command types ("Look at", "Use", "Talk to"). 
/// </summary>
class Hotspot 
{
	public:
		/// <summary>
		/// Text that comes up whenever a character looks at, uses, or talks to a hotspot
		/// </summary>
		String ActionText;
		/// <summary>
		/// Determines whether a new scene is unlocked when player does action. if an item is required, use use the boolean result of CheckIfPlayerHasItem as the value. Else, just put True or False here.
		/// </summary>
		bool DoesPlayerActionUnlockNewScene;
		Hotspot(String x, bool y) 
		{
			ActionText = x;
			DoesPlayerActionUnlockNewScene = y;
		}
};

/// <summary>
/// A Derived class of Hotspot for instances wherein player takes an InventoryItem upon utillizing "Use" command on a given hotspot
/// </summary>
class ItemHotSpot : public Hotspot
{
	public:
		int ItemId;

};

class TextAdventure 
{

	String CurrentAdventureText = "start of game";
	String CurentOptionsText = "stuff";

	/// <summary>
	/// Increases by one whenever new scene is unlocked
	/// </summary>
	int CurrentSceneIndex = 0;

	/// <summary>
	/// A Vector (a List in other languages) containing the Ids of Items the player has. 
	/// Also, PASS IT BY REFERENCE WHEN YOU PASS IT TO A FUNCTION
	/// </summary>
	std::vector<int> InventoryOfPlayerItemsByItemId;

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
			switch (TypeOfGameText) {
				case 1:
					CurrentAdventureText = NewText;
					break;
				case 2:
					CurentOptionsText = NewText;
			}
		}
		void ReadGameText(GameTextTypes TypeOfGameText)
		{
			switch (TypeOfGameText) {
				case 1:
					std::cout << CurrentAdventureText << std::endl;
					break;
				case 2:
					std::cout << CurentOptionsText << std::endl;
					break;
			}
		}
		void GoToNextScene() 
		{
			CurrentSceneIndex += 1;

			/// fill out more code for when the scene changes
		}
		bool CheckIfPlayerHasItem(int ItemId) 
		{
			return std::find(InventoryOfPlayerItemsByItemId.begin(), InventoryOfPlayerItemsByItemId.end(), ItemId) != InventoryOfPlayerItemsByItemId.end();
		}
		void AddItemToInventory(int ItemId) 
		{
			InventoryOfPlayerItemsByItemId.push_back(ItemId);
		}

		void RemoveItemFromInventory(int ItemId) 
		{
			if (CheckIfPlayerHasItem(ItemId)) 
			{

				for (int i = 0; i < InventoryOfPlayerItemsByItemId.size(); i++)
				{
					if (InventoryOfPlayerItemsByItemId[i] == ItemId)
					{
						InventoryOfPlayerItemsByItemId.erase(InventoryOfPlayerItemsByItemId.begin() + i);
						break;
					}
				}

			}

		}

		///use unordered maps for the scenes

		




};