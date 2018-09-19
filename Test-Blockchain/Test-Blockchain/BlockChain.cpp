#include "stdafx.h"
#include "BlockChain.h"

BlockChain::BlockChain() {
	_vChain.emplace_back(Block(0, "Genesis Block"));
	_nDifficulty = 3;
	BlockChain::_vChain[0].SetHash();
}

void BlockChain::AddBlock(Block bNew) {
	bNew.sPrevHash = BlockChain::_GetLastBlock().GetHash();
	bNew.MineBlock(_nDifficulty);
	_vChain.push_back(bNew);
}

bool BlockChain::VerifyChain()
{
	for (size_t i = 1; i < _vChain.size(); i++) {
		if (BlockChain::_vChain[i].VerifyBlock()) {
			
		}
		else {
			return false;
		}
	}
	return true;
}

Block BlockChain::_GetLastBlock() {
	return(_vChain.back());
}