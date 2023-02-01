/*
COSC2420 - 001
Assignment 7 - Fall 2022
Jose Lopez
December 8, 2022

This program is meant to be a stores inventory and sales. It has a menu for the user to choose what they want to do
you are able to input when an item is sold and it will update the the sales and inventory.It also gives you a report
for all the items and tell you how much they have generated in sales. It also functions monthly so you are able to input the month
and stock and it will update through all the inventory.
*/

#include <stdio.h>
#include <string.h>
#pragma warning (disable:4996)

//function prototypes
void itemSale(struct store items[]);
void dailyReport(struct store items[]);
void monthlyUpdate(struct store items[]);

struct store{
		char currentMonth[20];//current month
		char item[20];  //item name
		int itemCode;  //Unique item code
		int quantity;  //number of item
		float price;  // cost of item
		float sales;  //total sales
};
int main() {

	struct store items[5]; // array with stores inventory info

	//initializing the stores inventory
	strcpy(items[0].item, "Pepsi");
	strcpy(items[0].currentMonth, "January");
	items[0].itemCode = 1;
	items[0].quantity = 20;
	items[0].price = 1.39;
	items[0].sales = 0;

	strcpy(items[1].item, "Rice");
	strcpy(items[1].currentMonth, "January");
	items[1].itemCode = 2;
	items[1].quantity = 30;
	items[1].price = 2.20;
	items[1].sales = 0;

	strcpy(items[2].item, "Milk");
	strcpy(items[2].currentMonth, "January");
	items[2].itemCode = 3;
	items[2].quantity = 50;
	items[2].price = .99;
	items[2].sales = 0;

	strcpy(items[3].item, "Tortilla");
	strcpy(items[3].currentMonth, "January");
	items[3].itemCode = 4;
	items[3].quantity = 23;
	items[3].price = 1.29;
	items[3].sales = 0;

	strcpy(items[4].item, "Tomato Sauce");
	strcpy(items[3].currentMonth, "January");
	items[4].itemCode = 5;
	items[4].quantity = 15;
	items[4].price = 1.00;
	items[4].sales = 0;



	char choice;
	int menuChoice;
	int itemCode, sales, i;

	//loops code
	while (1) {
		printf("0.Exit\n1.Item Sale\n2.Daily Report\n3.Monthly Update\n");
		printf("What is your choice? "); // asking user to choose a choice
		scanf("%d", &menuChoice);

		//to exit loop
		if (menuChoice == 0)
			break;

		switch (menuChoice) {

		case 1:
			itemSale(items);
			break;
		case 2:
			dailyReport(items);
			break;
		case 3:
			monthlyUpdate(items);
			break;
		default:
			break;
		}
	}
	return 0;
}

	void itemSale(struct store items[]) {
		int itemCode, sales;
		//asking user for item code and amount sold
		printf("Enter items code ");
		scanf("%d", &itemCode);
		printf("How many were sold? ");
		scanf("%d", &sales);
		printf("\n");


		// check through all inventory for specific item
		for (int i = 0; i < 5; i++) {

			if (itemCode == items[i].itemCode) {
				items[i].quantity -= sales; // decreases the quantity of item
				items[i].sales = items[i].sales + items[i].price * sales; //updates total sale of item
				break;
			}

		}
	}



	void dailyReport(struct store items[]) {
		printf("\n");
		printf("Report:\n\n"); //prints to show that its report

		//loops through inventory to print every item
		for (int i = 0;i < 5;i++) {
			printf("%d%20.2f\n", items[i].itemCode, items[i].sales);
			printf("\n");
		}
	}
	void monthlyUpdate(struct store items[]) {

		char currentMonth[20];
		int currentQuantity;
		//ask user for current month and quantity of stock
		printf("Can you enter the current month: ");
		scanf("%s", &currentMonth);
		printf("Enter the quantity: ");
		scanf("%d", &currentQuantity);
		printf("\n");
		//loops through and updates current month and quantity
		for (int i = 0;i < 5;i++) {
			strcpy(items[i].currentMonth,currentMonth);
			items[i].quantity = currentQuantity;
			items[i].sales = 0;//resets all sales to 0

		}

	}





