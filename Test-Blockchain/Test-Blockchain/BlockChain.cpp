#include "stdafx.h"
#include "BlockChain.h"

//Constructor for the blockchain class.
BlockChain::BlockChain() {
	_vChain.emplace_back(Block(0, "Genesis Block"));
	_nDifficulty = 3;
	_vChain.reserve(100000);
	BlockChain::_vChain[0].MineBlock(_nDifficulty);
}

uint32_t BlockChain::GetDifficulty()
{
	return uint32_t(_nDifficulty);
}

//Adds a block at the end of the blockchain.
void BlockChain::AddBlock(Block bNew) {
	bNew.sPrevHash = BlockChain::_GetLastBlock().GetHash();
	bNew.MineBlock(_nDifficulty);
	_vChain.push_back(bNew);
}

//Verifies the integrity of the blockchain.
bool BlockChain::VerifyChain()
{
	for (size_t i = 0; i < _vChain.size(); i++) {
		if (BlockChain::_vChain[i].VerifyBlock()) {
			
		}
		else {
			return false;
		}
	}
	
	return true;
}

//Finds the location of the first invalid block in _vchain.
uint32_t BlockChain::FindInvalidBlock()
{
	for (size_t i = 0; i < _vChain.size(); i++) {
		if (BlockChain::_vChain[i].VerifyBlock()) {

		}
		else {
			return i;
		}
	}

	return NULL;
}

uint32_t BlockChain::GetChainLength()
{
	return uint32_t(_vChain.size());
}

//Returns the last block in the blockchain.
Block BlockChain::_GetLastBlock() {
	return(_vChain.back());
}