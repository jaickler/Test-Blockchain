#pragma once
#include "BlockChain.h"

using namespace std;

class UserInterface {
public:
	UserInterface();

	void DisplayMenu(int menu);

	int GetCurrentMenu();

	int GetLastSelection();

	int GetUserSelection();

	void ExecuteCommand(BlockChain &bChain);
	
private:
	void _VerifyChain(BlockChain &bChain);
	void _MineBlock(BlockChain &bChain);
	string _sGetUserInput();
	int _iMenu;
	int _LastSelection;
};