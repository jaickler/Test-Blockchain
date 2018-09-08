#pragma once
#include <cstdint>
#include <iostream>
#include <string>
#include <time.h>

using namespace std;

// Creates the definition for the Block class.
class Block {
public:

	string sPrevHash;

	Block(uint32_t nIndexIn, const string &sDataIn);

	string GetHash();

	void MineBlock(uint32_t nDifficulty);

private:

	uint16_t _nIndex;
	int64_t _nNonce;
	string _sData;
	string _sHash;
	time_t _tTime;

	string _CalculateHash() const;
};