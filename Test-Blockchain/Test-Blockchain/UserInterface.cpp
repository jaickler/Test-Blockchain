#include "stdafx.h"
#include "UserInterface.h"
#include <istream>
#include <strstream>
using namespace std;

UserInterface::UserInterface()
{
	_iMenu = 1;
}

void UserInterface::DisplayMenu(int menu)
{
	switch (menu)
	{
	case 1: cout << endl << endl << "Main Menu" << endl;
		cout << 1 << " - Mine Block" << endl;
		cout << 2 << " - Verify BlockChain" << endl;
		cout << 0 << " - Exit" << endl;
		cout << endl << "Please enter your selection: ";
		break;
	default:
		break;
	}
}

int UserInterface::GetCurrentMenu()
{
	return _iMenu;
}

int UserInterface::GetLastSelection()
{
	return _LastSelection;
}

int UserInterface::GetUserSelection()
{
	while (true) {
	string Input = _sGetUserInput();
	strstream SS;
	SS << Input;
	int ExtractedNum;
	
	if (SS >> ExtractedNum) {
		return ExtractedNum;
	}
	else {
		cout << endl << "Input not valid. Please try again: ";
	}
}
	
}

void UserInterface::ExecuteCommand(BlockChain &bChain)
{
	int Selection = GetUserSelection();
	if (Selection != 0) {
		switch (_iMenu) {
		case 1: switch (Selection) {
		case 1: _MineBlock(bChain); break;
		case 2: _VerifyChain(bChain); break;
		} break;
		}
	}
	else {
		_LastSelection = 0;
	}
}

void UserInterface::_VerifyChain(BlockChain &bChain)
{
	if (bChain.VerifyChain()) {
		cout << endl << endl << "BlockChain Valid" << endl;
	}
	else {
		cout << endl << endl << "Blockchain not valid." << endl;
	}
}

void UserInterface::_MineBlock(BlockChain &bChain)
{
	cout << endl << "Please input block data: ";
	Block bNew(bChain.GetChainLength(), _sGetUserInput());
	bChain.AddBlock(bNew);
	
}

string UserInterface::_sGetUserInput()
{
	string ReturnValue;
	getline(cin, ReturnValue);
	return(ReturnValue);
}
