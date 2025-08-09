#include <stdbool.h>
#include <stdio.h>
#include <string.h>

int main(void)
{
	char itemName[50] = "";
	float itemPrice = 0.0f;
	int itemQuantity = 0;
	char priceSymbol = '$';

	printf("What item would you like to buy?: ");
	fgets(itemName, sizeof(itemName), stdin);
	itemName[strlen(itemName) - 1] = '\0';

	printf("What is the price for each?: ");
	scanf("%f", &itemPrice);

	printf("How many would you like?: ");
	scanf("%d", &itemQuantity);

	float totalPrice = itemPrice * itemQuantity;

	printf("\n");
	printf("You have bought %d %s/s\n", itemQuantity, itemName);
	printf("The total is: %c%.2f\n", priceSymbol, totalPrice);

	return 0;
}