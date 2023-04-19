#include <stdio.h>
#include <stdlib.h>

/*
 * Program1.c
 *
 *  Created on: Feb 8, 2023
 *      Author: h232m035
 */


float salesData[] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};

void printMonth(int monthnum, int useSpaces){
	if (monthnum == 0){
		printf("January");
		if (useSpaces){
			printf("         ");
		}
	}
	else if (monthnum == 1){
		printf("February");
		if (useSpaces){
			printf("        ");
		}
	}
	else if (monthnum == 2){
		printf("March");
		if (useSpaces){
			printf("           ");
		}
	}
	else if (monthnum == 3){
		printf("April");
		if (useSpaces){
			printf("           ");
		}
	}
	else if (monthnum == 4){
		printf("May");
		if (useSpaces){
			printf("             ");
		}
	}
	else if (monthnum == 5){
		printf("June");
		if (useSpaces){
			printf("            ");
		}
	}
	else if (monthnum == 6){
		printf("July");
		if (useSpaces){
			printf("            ");
		}
	}
	else if (monthnum == 7){
		printf("August");
		if (useSpaces){
			printf("          ");
		}
	}
	else if (monthnum == 8){
		printf("September");
		if (useSpaces){
			printf("       ");
		}
	}
	else if (monthnum == 9){
		printf("October");
		if (useSpaces){
			printf("         ");
		}
	}
	else if (monthnum == 10){
		printf("November");
		if (useSpaces){
			printf("        ");
		}
	}
	else if (monthnum == 11){
		printf("December");
		if (useSpaces){
			printf("        ");
		}
	}
	else{
		printf("Invalid month number");
	}
}

void maxMonth(float monthData[], int listLength){
	float mostMoney = monthData[0];
	int mostIndex = 0;
	for (int i = 1; i < listLength; i++){
		if (monthData[i] > mostMoney){
			mostIndex = i;
			mostMoney = monthData[i];
		}
	}
	printf("Maximum sales:  %.2f   (", mostMoney);
	printMonth(mostIndex, 0);
	printf(")\n");
}

void minMonth(float monthData[], int listLength){
	float minMoney = monthData[0];
	int minIndex = 0;
	for (int i = 1; i < listLength; i++){
		if (monthData[i] < minMoney){
			minIndex = i;
			minMoney = monthData[i];
		}
	}
	printf("Minimum sales:  %.2f   (", minMoney);
	printMonth(minIndex, 0);
	printf(")\n");
}

void averageSales(float monthData[], int listLength){
	float total = 0;
	for (int i = 0; i < listLength; i++){
		total += monthData[i];
	}
	printf("Average Sales:  %.2f\n", total / listLength);
}

void func0(float monthData[], int listLength){
	printf("Month           Sales\n");
	for (int i = 0; i < listLength; i++){
		printMonth(i, 1);
		printf("%.2f\n", monthData[i]);
	}
}

void func1(float monthData[], int listLength){
	minMonth(monthData, listLength);
	maxMonth(monthData, listLength);
	averageSales(monthData, listLength);
}

void func2(float monthData[], int listLength){
	for (int i = 0; i < 7; i++){
		if (i == 0){
			printf("January-June    ");
		}
		else if (i == 1){
			printf("February-July   ");
		}
		else if (i == 2){
			printf("March-August    ");
		}
		else if (i == 3){
			printf("April-September ");
		}
		else if (i == 4){
			printf("May-October     ");
		}
		else if (i == 5){
			printf("June-November   ");
		}
		else if (i == 6){
			printf("July-December   ");
		}
		float miniTotal = 0;
		for (int j = i; j < i + 6; j++){
			miniTotal += monthData[j];
		}
		printf("%.2f\n", miniTotal / 6);
	}
}

void func3(float monthData[], int listLength){
	printf("Month           Sales\n");
	float maxUsed = 0;
	int useMax = 0;
	int maxmonth = -1;
	float maxAm = 0;
	int sorting = 1;
	while (sorting){
		maxAm = 0;
		maxmonth = -1;

		for (int i = 0; i < listLength; i ++){
			if (!useMax || monthData[i] < maxUsed){
				//check if this is valid
				if (maxmonth == -1 || monthData[i] > maxAm){
					maxAm = monthData[i];
					maxmonth = i;
				}
			}
		}
		if (maxmonth == -1){
			sorting = 0;
			break;
		}
		//print out data
		printMonth(maxmonth, 1);
		printf("%.2f\n", maxAm);
		//data setup
		useMax = 1;
		maxUsed = maxAm;
	}
}

int main(){
	//first, get the 12 inputs for month data
	FILE *inputTxt;
	inputTxt = fopen("input.txt", "r");
	for (int i = 0; i < 12; i++){
		fscanf(inputTxt, "%f", &salesData[i]);
	}
	printf("\nMonthly sales report for 2022\n\n");
	func0(salesData, 12);
	printf("\nSales summary\n\n");
	func1(salesData, 12);
	printf("\nSix-Month moving average report\n\n");
	func2(salesData, 12);
	printf("\nSales report\n\n");
	func3(salesData, 12);
}
