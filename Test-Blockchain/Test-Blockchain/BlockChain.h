#pragma once
#include <cstdint>
#include <vector>
#include "Block.h"

using namespace std;

class BlockChain {
public:
	BlockChain();

	void AddBlock(Block New);

private:

	uint32_t _nDifficulty;
	vector<Block> _vChain;

	Block _GetLastBlock() const;
};