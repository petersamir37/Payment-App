#include "Card.h"
#include <stdio.h>
#include <stdlib.h>


getCardHolderName(ST_cardData_t* cardPTR)
{	

	printf("Enter name: ");

	scanf_s("%[^\n]25s", cardPTR->cardHolderName, 25);


	int length = strlen(cardPTR->cardHolderName);


	printf("%d \n", length);

	//printf("%s %d \n", cardPTR->cardHolderName, length);


	/*for (int i = 0; i < length; i++) {
		if  ( (toupper(cardPTR->cardHolderName[i]) < 'A' || toupper(cardPTR->cardHolderName[i]) > 'Z') && cardPTR->cardHolderName[i] != ' ') {
			printf("Only letters allowed \n");
			
			return WRONG_NAME;
		}
	}*/

	if (cardPTR->cardHolderName == NULL || length < 20 || length >24) {
		printf("Wrong name \n");
		return WRONG_NAME;
	}
	else {
		printf("OK \n");
		return CARD_OK;

	}
}

getCardExpiryDate(ST_cardData_t* cardPTR) {
	printf("Enter expiry date: ");
	scanf_s("%6s", cardPTR->cardExpirationDate, 6);
	int length = strlen(cardPTR->cardExpirationDate);
	int month;

	month= atoi(&cardPTR->cardExpirationDate[0]);

	if (month >12 || month <1 || cardPTR->cardExpirationDate == NULL || length != 5 || cardPTR->cardExpirationDate[2] != '/') 
	{
		printf("Wrong Date");
		return WRONG_EXP_DATE;
	}
	else {
		printf("OK \n");
		return CARD_OK;

	}


}

getCardPAN(ST_cardData_t* cardPTR) {
	printf("Enter PAN: ");
	scanf_s("%20s", cardPTR->primaryAccountNumber, 20);
	int length = strlen(cardPTR->primaryAccountNumber);

	//printf("%s", cardPTR->primaryAccountNumber);
	
	for (int i = 0; i < length; i++) {
		if (cardPTR->primaryAccountNumber[i] > '9')
		{
			printf("Letters not allowed \n");
			return WRONG_PAN;
		}
	}

	if (cardPTR->primaryAccountNumber == NULL || length > 19 || length < 16) {
		printf("Wrong PAN \n" );
		return WRONG_PAN;
	}
	else {
		printf("OK \n");
		return CARD_OK;
	}
}

