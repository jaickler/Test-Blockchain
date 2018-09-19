// Test-Blockchain.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "BlockChain.h"

int main() {

	BlockChain bChain = BlockChain();

	cout << "Mining Block 1..." << endl;
	bChain.AddBlock(Block(1, "Block 1 Data"));
	
	cout << "Mining Block 2..." << endl;
	bChain.AddBlock(Block(2, "Block 2 Data"));

	cout << "Mining Block 3..." << endl;
	bChain.AddBlock(Block(3, "Block 3 Data"));

	if (bChain.VerifyChain()) {
	cout << "BlockChain Valid" << endl;
	}
	else {
		cout << "Blockchain not valid." << endl;
	}
	return(0);
}