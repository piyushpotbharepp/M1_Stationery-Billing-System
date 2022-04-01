#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <stdlib.h>

struct items{
    char item[20];
    float price;
    int qty;
};

struct orders{
    char customer[50];
    char date[35];
    int numOfItems;
    struct items itm[50];
};

void generateBillHeader(char name[75], char date[35])
{
    printf("\n\n");

    printf("\t Pallavi Pustakalaya");
    printf("\n\t -----------------------------");
    printf("\nDate : %s", date);
    printf("\nInvoice To : %s", name);
    printf("\n");
    printf("--------------------------------------------------\n");
    printf("Items\t\t");
    printf("Quantity\t\t");
    printf("Total\t\t");
    printf("\n--------------------------------------------------");
    printf("\n\n");
}

void generateBillBody(char item[50], int quantity, float price)
{
    printf("%s\t\t", item);
    printf("%d\t\t", quantity);
    printf("%.2f\t\t", quantity * price);
    printf("\n");
}

void generateBillFooter(float total)
{
    printf("\n");
    float dis = 0.1 * total;
    float netTotal = total - dis;
    float cgst = 0.09 * netTotal, grandTotal = netTotal + 2 * cgst;
    printf("-------------------------------------------------\n");
    printf("Sub Total\t\t\t%.2f", total);
    printf("\nDiscount @10%s\t\t\t%.2f", "%", dis);
    printf("\n\t\t\t\t-------------");
    printf("\nNet Total\t\t\t%.2f", netTotal);
    printf("CGST @9%s\t\t\t%.2f", "%", cgst);
    printf("SGST @9%sw\t\t\t%.2f", "%", cgst);
    printf("\n--------------------------------------------------");
    printf("\nGrand Total\t\t\t%.2f", grandTotal);
    printf("\n--------------------------------------------------\n");
}

int main()
{
	system("CLS"); 
	float total;
    int opt, opt2, n;
    struct orders ord;
    struct orders order;
    char saveBill = 'y', contFlag = 'y';
    char name[75];
    FILE *fp;

	while(contFlag == 'y')
	{
		float total = 0;
		int invoiceFound = 0;
		
    	printf("\t============== PALLAVI PUSTAKLAYA ==============");
    	printf("\n\nPlease select your prefered operater :\t");
    	printf("\n[1] Generate Invoice");
    	printf("\n[2] Show All Invoices");
    	printf("\n[3] Search Invoice");
    	printf("\n[4] Exit");

    	printf("\n\nSelect Your Choice : \t");
    	scanf("%d", &opt);
    	fgetc(stdin);

    	switch(opt)
    	{
    		
        	case 1:
        		printf("\nPlease Enter The Name Of The Customer :\t");
        		fgets(ord.customer, 50, stdin);
        		ord.customer[strlen(ord.customer)-1] = 0;
        		strcpy(ord.date, __DATE__);
        		
        		printf("\nPlease Select The Type Of Items From Below List :\t");
        		printf("\n[1] Stationery Items");
        		printf("\n[2] School Books");
        		printf("\n[3] Other");
        		
        		printf("\n\nSelect Your Choice :\t");
        		scanf("%d", &opt2);
        		fgetc(stdin);
        		
        		switch(opt2)
        		{
        			case 1:
        				printf("Please Enter The Number Of Items :\t");
        				scanf("%d", &n);
        				ord.numOfItems = n;
        
        				for(int i=0;i<n;i++)
        				{
        					fgetc(stdin);
        					printf("\n");
        					printf("Please Enter The Item %d\t", i+1);
        					fgets(ord.itm[i].item, 20, stdin);
							ord.itm[i].item[strlen(ord.itm[i].item)-1] = 0;
							printf("Please Enter The Quantity :\t");
							scanf("%d", &ord.itm[i].qty);
							printf("Please Enter The Unit Price :\t");
							scanf("%f", &ord.itm[i].price);
							total += ord.itm[i] .qty * ord.itm[i].price;		
						}
						break;
				
					case 2:
						printf("Please Enter The Number Of Items :\t");
        				scanf("%d", &n);
        				ord.numOfItems = n;
        
        				for(int i=0;i<n;i++)
        				{
        					fgetc(stdin);
        					printf("\n");
        					printf("Please Enter The Item %d\t", i+1);
        					fgets(ord.itm[i].item, 20, stdin);
							ord.itm[i].item[strlen(ord.itm[i].item)-1] = 0;
							printf("Please Enter The Quantity :\t");
							scanf("%d", &ord.itm[i].qty);
							printf("Please Enter The Unit Price :\t");
							scanf("%f", &ord.itm[i].price);
							total += ord.itm[i] .qty * ord.itm[i].price;		
						}
						break;
				
					case 3:
						printf("Please Enter The Number Of Items :\t");
        				scanf("%d", &n);
        				ord.numOfItems = n;
        
        				for(int i=0;i<n;i++)
        				{
        					fgetc(stdin);
        					printf("\n");
        					printf("Please Enter The Item %d\t", i+1);
        					fgets(ord.itm[i].item, 20, stdin);
							ord.itm[i].item[strlen(ord.itm[i].item)-1] = 0;
							printf("Please Enter The Quantity :\t");
							scanf("%d", &ord.itm[i].qty);
							printf("Please Enter The Unit Price :\t");
							scanf("%f", &ord.itm[i].price);
							total += ord.itm[i] .qty * ord.itm[i].price;		
						}
						break;
				
					default :
						printf("You Have Entered Wrong Choice!");
						break;
				}
		
				generateBillHeader(ord.customer, ord.date);
				for(int i=0;i<ord.numOfItems;i++)
				{
					generateBillBody(ord.itm[i].item, ord.itm[i].qty, ord.itm[i].price);
				}
		 
				generateBillFooter(total);
		
				printf("\nDo You Want To Save The Invoice [y/n]:\t");
				scanf("%s", &saveBill);
		
				if(saveBill == 'y')
				{
					fp = fopen("StoreBill.dat", "a+");
					fwrite(&ord, sizeof(struct orders), 1, fp);
					if(!fwrite != 0)
					{
						printf("\nSuccessfully Saved");
					}
					else
					{
						printf("\nError Saving");
					}
					fclose(fp);
				}
			
			case 2:
				system("CLS");
				fp = fopen("StoreBill.dat", "r");
				printf("\n  ************ Previous Invoices ************\n");
				while(fread(&order, sizeof(struct orders), 1, fp))
				{
					float tot = 0;
					generateBillHeader(order.customer, order.date);
					for(int i=0;i<order.numOfItems;i++)
					{	
						generateBillBody(order.itm[i].item, order.itm[i].qty, order.itm[i].price);
						tot += order.itm[i].qty * order.itm[i].price;	
					}
				
					generateBillFooter(tot);
				}
			
				fclose(fp);
				break;
			
			case 3:
				system("CLS");
				printf("\nEnter The Name Of The Customer :\t");
				fgets(name, 75, stdin);
				name[strlen(name)-1] = 0;
			
				system("clear");
				fp = fopen("StoreBill.dat", "r");
				printf("\t  ************ Invoices Of %s ************\n", name);
				while(fread(&order, sizeof(struct orders), 1, fp))
				{
					float tot = 0;
					if(!strcmp(order.customer, name))
					{
						generateBillHeader(order.customer, order.date);
						for(int i=0;i<order.numOfItems;i++)
						{	
							generateBillBody(order.itm[i].item, order.itm[i].qty, order.itm[i].price);
							tot += order.itm[i].qty * order.itm[i].price;	
						}
				
						generateBillFooter(tot);
						invoiceFound = 1;
					}		
				}
			
				if(!invoiceFound)
				{
					printf("Sorry The Invoice For %s Doesnot Exists", name);
				}
			
				fclose(fp);
				break;
		
			case 4:
				system("CLS");
				printf("\n\t\t Bye Bye :");
				exit(0);
				break;
			
			default:
				printf("Sorry Invalid Option");
				break;
    	}
    	
    	printf("\nDo You Want To Perform Another Operation [y/n] :\t");
    	scanf("%s", &contFlag);
	}
    
    printf("\n\t\t Bye Bye :");
    printf("\n\n");
    
    return 0;
}
