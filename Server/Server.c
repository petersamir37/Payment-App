#include "..\Card\Card.h"
#include "..\Terminal\Terminal.h"
#include "Server.h"
#include <stdio.h>
#include <stdlib.h>

ST_accountsDB_t accountsDB[255];
ST_accountsDB_t StolenaccountsDB[255];
ST_transaction_t transactions[255] = { {{{{0}}}} };
ST_accountsDB_t Stolen={ 0 ,"5803065408848177809"};

unsigned int sequence = 1;
int Account;

void fillaccounts() {
	
	for (int i = 0; i < 255; i++) {
		accountsDB[i].balance = rand();
		for (int j = 0; j < 19; j++) {
			accountsDB[i].primaryAccountNumber[j] = (rand() %10) + '0';
		}
		printf("%f %s \n", accountsDB[i].balance, accountsDB[i].primaryAccountNumber);
	}
}

void printtransactions(ST_transaction_t transactions[]) {
	for (int i = 0; i < 255; i++) {
		printf("%d \n Name %s \n Expiration %s \n PAN %s \n MaxTrans %f \n Date %s \n Amount %f \n SEQ %d \n State %d \n \n",
			i,
			transactions[i].cardHolderData.cardHolderName,
			transactions[i].cardHolderData.cardExpirationDate,
			transactions[i].cardHolderData.primaryAccountNumber,
			transactions[i].terminalData.maxTransAmount,
			transactions[i].terminalData.transactionDate,
			transactions[i].terminalData.transAmount,
			transactions[i].transactionSequenceNumber,
			transactions[i].transState

		);
	}
}

isValidAccount(ST_cardData_t* cardData) {


	transData.cardHolderData = *cardData;

	//printf("%s \n", cardData->primaryAccountNumber);

	//printf("%s \n", accountsDB[254].primaryAccountNumber);

	for (int i=0 ; i< 255; i++) {
		if (strcmp(cardData->primaryAccountNumber, Stolen.primaryAccountNumber) == 0)
			break;

		if (strcmp(cardData->primaryAccountNumber , accountsDB[i].primaryAccountNumber)==0) {			
			printf("Account exists \n");
			Account = i;
			return SERVER_OK;
			break;
		}
	}
	printf("Stolen card \n");
	return DECLINED_STOLEN_CARD;
}

isAmountAvailable(ST_terminalData_t * termData) {
	
	transData.terminalData = *termData;

	if (termData->transAmount > accountsDB[Account].balance) {
		printf("Low balance \n");
		return LOW_BALANCE;
	}
	else {
		printf("Amount ok \n");
		return SERVER_OK;
	}
}

recieveTransactionData(ST_transaction_t * transData) {
	transData->transactionSequenceNumber = sequence;
	if (isValidAccount(&cardData) == 0) {
		if (isAmountAvailable(&termData) == 0) {
			accountsDB[Account].balance -= transData->terminalData.transAmount;
			transData->transState = APPROVED;
			return APPROVED;
		}
		else {
			transData->transState = DECLINED_INSUFFECIENT_FUND;
			return DECLINED_INSUFFECIENT_FUND;
		}
	}
	else {
		transData->transState = DECLINED_STOLEN_CARD;
		return DECLINED_STOLEN_CARD;
	}
	
} 


saveTransaction(ST_transaction_t* transData) {
	if (transData->transState == INTERNAL_SERVER_ERROR) {
		printf("Saving Failed");
		return SAVING_FAILED;
	}
	else {
		transactions[sequence - 1] = *transData;
		sequence++;
		printf("Balance now is: %f \n", accountsDB[Account].balance);
		return SERVER_OK;
	}
}