#include "..\Card\Card.h"
#include "..\Terminal\Terminal.h"
#include "..\Server\Server.h"
#include "app.h"



void appStart() {

	int x = 0;
	fillaccounts();
	while (1) getCardHolderName(&cardData);
	while (1){
	if(getCardHolderName(&cardData) !=0)
		break;
	if(getCardExpiryDate(&cardData) != 0)
		break;
	if (getCardPAN(&cardData) != 0)
		break;

	if (getTransactionDate(&termData) != 0)
		break;
	if (isCardExpired(cardData,termData) != 0)
		break;
	if (getTransactionAmount(&termData) != 0)
		break;
	if (setMaxAmount(&termData) != 0)
		break;
	if (isBelowMaxAmount(&termData) != 0)
		break;

	recieveTransactionData(&transData);
		
	saveTransaction(&transData);


	printtransactions(transactions);
	}
	
}
