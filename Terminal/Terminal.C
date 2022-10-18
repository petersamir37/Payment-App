#include "..\Card\Card.h"
#include "Terminal.h"
#include <stdio.h>
#include <stdlib.h>


getTransactionDate(ST_terminalData_t* termPTR) {
	printf("Enter transaction date: ");
	scanf_s("%11s", termPTR->transactionDate, 11);
	if (termPTR->transactionDate == NULL || strlen(termPTR->transactionDate) < 10 || termPTR->transactionDate[2] != '/'
		|| termPTR->transactionDate[5] != '/') {
		printf("Wrong date \n");
		return WRONG_DATE;
	}
	else{ printf("OK \n");
	return TERMINAL_OK;
	}
}

isCardExpired(ST_cardData_t cardData, ST_terminalData_t termData) {
	int a = atoi(&cardData.cardExpirationDate[3]);
	int b = atoi(&termData.transactionDate[8]);
	printf("%d %d \n", a, b);
	if (a >= b) { 
		a = atoi(&cardData.cardExpirationDate[0]);
		b = atoi(&termData.transactionDate[3]);
		printf("%d %d \n", a, b);
		if (a >= b) {
			printf("OK \n");
			return TERMINAL_OK;
		}
	}
	else {
		printf("Card Expired \n");
		return EXPIRED_CARD;
	
	}

}

getTransactionAmount(ST_terminalData_t* termPTR) {
	printf("Enter transaction amount: ");
	scanf_s("%f", &termPTR->transAmount);
	if (termPTR->transAmount <= 0) {
		printf("Invalid amount \n");
		return INVALID_AMOUNT;
	}
	else {
		printf("Ok \n");
		return TERMINAL_OK;
	}
}

setMaxAmount(ST_terminalData_t* termPTR) {
	printf("Enter max amount: ");
	scanf_s("%f", &termPTR->maxTransAmount);
	if (termPTR->maxTransAmount <= 0) {
		printf("Wrong amount \n");
		return INVALID_MAX_AMOUNT;		
	}
	else {
		printf("Ok \n");
		return TERMINAL_OK;
	}

}

isBelowMaxAmount(ST_terminalData_t* termData) {
	if (termData->transAmount > termData->maxTransAmount) {
		printf("Amount exceeds maximum \n");
		return EXCEED_MAX_AMOUNT;
	}
	else {
		printf("Amount ok \n");
		return TERMINAL_OK;
	}
}