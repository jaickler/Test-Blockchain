#include "stdafx.h"
#include "Block.h"
#include "sha256.h"
#include <strstream>
#include <vector>

SHA256 sha256;
Block::Block(uint32_t nIndexIn, const string &sDataIn) : _nIndex(nIndexIn), _sData(sDataIn) {
	_nNonce = -1;
	_tTime = time(nullptr);
}

string Block::GetHash() {
	if (_sHash.length() == 0) {
		_CalculateHash();
	}
		return(_sHash);
}

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

bool Block::VerifyBlock()
{

	if (_sHash == _CalculateHash()) {
		return true;
	} else {
		return false;
	}

}

void Block::SetHash()
{
	_sHash = _CalculateHash();
}

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

