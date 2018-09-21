#pragma once
#include <cstdint>
#include <vector>
#include "Block.h"

using namespace std;

//Defines the blockchain class.
class BlockChain {
public:
	BlockChain();
	
	uint32_t GetDifficulty();

	void AddBlock(Block New);

	bool VerifyChain();

	uint32_t FindInvalidBlock();
	
	uint32_t GetChainLength();

private:

	uint32_t _nDifficulty;
	vector<Block> _vChain;

	Block _GetLastBlock();
};