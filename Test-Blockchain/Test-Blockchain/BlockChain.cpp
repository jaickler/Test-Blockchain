#include "stdafx.h"
#include "BlockChain.h"

BlockChain::BlockChain() {
	_vChain.emplace_back(Block(0, "Genesis Block"));
	_nDifficulty = 6;
}

void BlockChain::AddBlock(Block bNew) {
	bNew.sPrevHash = _GetLastBlock().GetHash();
	bNew.MineBlock(_nDifficulty);
	_vChain.push_back(bNew);
}

Block BlockChain::_GetLastBlock() const {
	return(_vChain.back());
}