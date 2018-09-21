#include "stdafx.h"
#include "Block.h"
#include "sha256.h"
#include <strstream>
#include <vector>

// Creates the object that will be used to run the sha256 hashing algorithm.
SHA256 sha256;

//Constructor for the block class.
Block::Block(uint32_t nIndexIn, const string &sDataIn) : _nIndex(nIndexIn), _sData(sDataIn) {
	_nNonce = -1;
	_tTime = time(nullptr);
}

//Returns the block's hash.
string Block::GetHash() {
		return(_sHash);
}

//Finds a valid hash for the current block.
void Block::MineBlock(uint32_t nDifficulty) {
	char *cstr;
	cstr = new char [nDifficulty + 1];
	for (uint32_t i = 0; i < nDifficulty; i++) {
		cstr[i] = '0';
	}
	cstr[nDifficulty] = '\0';

	string str(cstr);

	do {
		_nNonce++;
		_sHash = _CalculateHash();
	} while (_sHash.substr(0, nDifficulty) != str);

	cout << "Block mined: " << _sHash << endl;
}

//Verifies the validity of the owner block.
bool Block::VerifyBlock()
{

	if (_sHash == _CalculateHash()) {
		return true;
	} else {
		return false;
	}

}

//Sets the hash of the origin block.
void Block::SetHashOrigin()
{
	_sHash = _CalculateHash();
}

//Calculates and returns the hash of the block based on current information.
string Block::_CalculateHash() {
	strstream SS;
	
	if (_tTime) {} else{
	time_t timer;
	time(&timer);
	_tTime = timer;
}
	SS << _nIndex << _tTime << _sData << _nNonce << sPrevHash;

	return sha256(SS.str());

}

