#include <stdio.h>
#include <stdlib.h>
#include <string.h>
// FUNCTIONS FOR "COLOURS"
void blue()
{
    printf("\033[1;34m");
}
void red()
{
    printf("\033[3;31m");
}
void yellow()
{
    printf("\033[1;33m");
}
void purple()
{
    printf("\033[4;35m");
}
void reset()
{
    printf("\033[0m");
}
// Structure for taking username and password
struct data
{
    char username[25];
    char password[25];
};

struct data datalist[3] = {

    {"Nikhil", "nikhil@123"},
    {"Manikanta", "mani@123"},
    {"Pradeep", "pradeep@123"},
};
// external variable for storing who is operating  the system
char provider[20];
// FUNCTION for checking who is logging into the Friends Login page
int checking()
{

    char user[25], login[25];
    int i, k, n;
    static int flag = 0, pass = 0;
    printf("USERNAME :");
    scanf("%s", user);
    strcpy(provider, user);

    for (i = 0; i < 3; i++)
    {

        k = strcmp(user, datalist[i].username);
        if (k == 0)
        {
            flag = 1;
            break;
        }
    }
    if (flag == 1)
    {
        printf("PASSWORD :");
        scanf("%s", login);
        for (i = 0; i < 3; i++)
        {
            k = strcmp(login, datalist[i].password);
            if (k >= 0)
            {
                pass = 1;
                break;
            }
        }
    }
    // If any unknown user is found it will recall checking function untill correct username is entered
    if (flag == 0 || pass == 0)
    {
        red();
        printf("you entered a invalid USERNAME/ PASSWORD\n");
        printf("\n1-Try again\n2-Exit\nPress any index:");
        reset();
        scanf("%d", &n);

        if (n == 1)
        {
            checking();
        }
        else if (n == 2)
        {
            exit(9);
        }
    }
    if (pass == 1 && flag == 1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

//* STRUCTURE FOR MAIN MEDICINE LIST *//
struct medicine
{
    char name[100];
    int quantity;
    float price;
};
// FUNCTION for Checking the existing Stock
int stock_checking()
{
    // STRORING the FILE in THE STRUCTURE MEDICINE
    FILE *ptr;
    ptr = fopen("MEDICINE_LIST.csv", "rb");

    struct medicine me[499];
    int i = 0;
    while (i < 499)
    {
        fscanf(ptr, "%d,%f,%s", &me[i].quantity, &me[i].price, me[i].name);
        // printf(" %s %d %.2f\n",me[i].name,me[i].quantity,me[i].price);
        i++;
    }
    // Taking the input from the user which medicines he need to check
    int check_tablet;
    blue();
    printf("Enter the number of different medicines you want check:\n");
    reset();
    scanf("%d", &check_tablet);
    char check[check_tablet][100];
    // Checking
    for (int h = 0; h < check_tablet; h++)
    {
        printf("Enter the name of the %d medicine:\n", h + 1);
        scanf(" %s", check[h]);
    }
    int h, g;
    for (g = 0; g < check_tablet; g++)
    {
        for (h = 0; h < 499; h++)
        {
            // If STOCK is available it will print the stock
            int y = 10;
            y = strcmp(check[g], me[h].name);
            if (y == 0)
            {
                yellow();
                printf("Stock of %s medicine is %d\n", me[h].name, me[h].quantity);
                reset();
                break;
            }
        }
        if (h == 499)
        {
            // If STOCK is "NOT" available
            red();
            printf("!!%s medicine is  \"NOT FOUND\" !!\n", check[g]);
            reset();
        }
    }
    return 0;
}

// FUNCTION for Adding NEW stock

int adding()
{
    FILE *ptr;
    ptr = fopen("MEDICINE_LIST.csv", "rb");

    struct medicine me[499];
    int i = 0;
    while (i < 499)
    {
        fscanf(ptr, "%d,%f,%s", &me[i].quantity, &me[i].price, me[i].name);
        i++;
    }
    int add_num;
    // Taking input from the user
    blue();
    printf("Enter the number of different kinds of medicines you want add:\n");
    reset();
    scanf("%d", &add_num);
    char add[add_num][100];
    int num_tab[add_num];
    // Checking the name of the medicine
    for (int h = 0; h < add_num; h++)
    {
        printf("Enter the name of %d medicine\n", h + 1);
        scanf(" %s", add[h]);
        printf("Enter the number to add of %d medicine\n", h + 1);
        scanf("%d", &num_tab[h]);
    }

    int h, g;
    for (g = 0; g < add_num; g++)
    {
        for (h = 0; h < 499; h++)
        {
            int y = 10;
            y = strcmp(add[g], me[h].name);
            if (y == 0)
            {
                // Printing the updated stock
                me[h].quantity += num_tab[g];
                purple();
                printf("%s --> %d\n", me[h].name, me[h].quantity);
                reset();
                break;
            }
        }
        if (h == 499)
        {
            red();
            printf("!!%s medicine is  \"NOT FOUND\" !!\n", add[g]);
            reset();
        }
    }
    fclose(ptr);
    // UPDATING THE NEW STOCK IN THE MAIN LIST(FILE)
    ptr = fopen("MEDICINE_LIST.csv", "wb");
    if (ptr == NULL)
    {
        printf("FILE can't be opened\n");
    }
    int d = 0;
    while (d < 499)
    {
        fprintf(ptr, "%d,%f,%s\n", me[d].quantity, me[d].price, me[d].name);
        d++;
    }
    fclose(ptr);
    return 0;
}
// EXTERNAL integer variable to find index of the given medicince in the list
int index;
// FUNCTION for finding the index of the parcticluar medicine
int searching(char str[50], struct medicine me[499])
{
    int k, i, ans;

    for (i = 0; i < 499; i++)
    {
        k = strcmp(str, me[i].name);
        if (k == 0)
        {
            index = i;
            ans = 10;
            break;
        }
    }
    if (i == 499)
    {
        ans = 1;
    }
    return ans;
}
// FUNCTION for finding the price of the given medicine
float find_price(char str[50], struct medicine me[499])
{
    int k, i;
    float price;
    for (i = 0; i < 499; i++)
    {
        k = strcmp(str, me[i].name);
        if (k == 0)
        {
            price = me[i].price;
            break;
        }
    }
    return price;
}
// For billing medicine in order we have find the length of the medicine
// FUNCTION for finding the length
int length_of_name(char str[50])
{
    int len = 0;
    while (str[len] != '\0')
    {
        len++;
    }
    return len;
}
// FUNCTION for BILLING
int billing()
{
    FILE *ptr;
    ptr = fopen("MEDICINE_LIST.csv", "rb");

    struct medicine me[499];
    int i = 0;
    while (i < 499)
    {
        fscanf(ptr, "%d,%f,%s", &me[i].quantity, &me[i].price, me[i].name);
        i++;
    }
    char name_patient[100];
    // Taking input from user for NAME and PRESCRIPTION
    blue();
    printf("Enter the name of the patient :");
    reset();
    scanf("%s", name_patient);
    int num_tab;
    blue();
    printf("Enter the number of different medicines you need:");
    reset();
    scanf("%d", &num_tab);
    // STRUCTURE for storing the PRESCRIPTION
    struct prescription
    {
        char tablets[50];
        int quant;
    };
    // ARRAY to store the Sub_total of medicines
    float billing_amount[num_tab];
    struct prescription mem[num_tab];
    int k;
    // Checking the Availability of the Medicine
    for (int i = 0; i < num_tab; i++)
    {
        printf("Enter the name of the %d tablet\n", i + 1);
        scanf(" %s", mem[i].tablets);
        k = searching(mem[i].tablets, me);
        if (k == 10)
        {
            // If Medicine Available
            printf("Enter the Quntity you need\n");
            scanf("%d", &mem[i].quant);
            // Checking for stock Availablity
            if (me[index].quantity >= mem[i].quant)
            {
                // If Medicine's stock is  Available
                billing_amount[i] = me[index].price * mem[i].quant;
                me[index].quantity -= mem[i].quant;
            }
            else
            {
                // If Medicine's stock is NOT  Available
                red();
                printf("%s Tablet's Stock is not Available", mem[i].tablets);
                reset();
                billing_amount[i] = 0.00;
            }
        }
        else
        {
            // If Medicine NOT Available
            red();
            printf("%s Tablet is not Available\n", mem[i].tablets);
            reset();
            billing_amount[i] = 0.00;
        }
    }
    // Variable to store the Total Amount
    float total_amount = 0;
    // Finding the Total_Amount
    for (int i = 0; i < num_tab; i++)
    {
        total_amount += billing_amount[i];
    }
    // Closing the FILE
    fclose(ptr);
    // Reopening The File in wb mode to Update the stock
    ptr = fopen("MEDICINE_LIST.csv", "wb");
    if (ptr == NULL)
    {
        printf("FILE can't be opened\n");
    }
    int d = 0;
    while (d < 499)
    {
        fprintf(ptr, "%d,%f,%s\n", me[d].quantity, me[d].price, me[d].name);
        d++;
    }
    fclose(ptr);
    /// CODING FOR billing starts
    // STORES THE BILL ON THE NAME OF THE PATIENT
    FILE *fp_bill;
    fp_bill = fopen(name_patient, "w");
    // NAME
    fprintf(fp_bill, "===================================FRIENDS PHARMACY===================================\n");
    // ADDRESS
    fprintf(fp_bill, "Address:");
    for (int z = 0; z < 61; z++)
    {
        fprintf(fp_bill, " ");
    }
    // DATE MACRO
    fprintf(fp_bill, "DATE:%s\n", __DATE__);
    fprintf(fp_bill, "Friends Pharmacy,");
    for (int z = 0; z < 53; z++)
    {
        fprintf(fp_bill, " ");
    }
    // TIME MACRO
    fprintf(fp_bill, "TIME:%s\n", __TIME__);
    fprintf(fp_bill, "Nagpur,\n");
    fprintf(fp_bill, "Maharashtra,");
    for (int z = 0; z < 57; z++)
    {
        fprintf(fp_bill, " ");
    }
    fprintf(fp_bill, "P.No:73044 41207\n");
    fprintf(fp_bill, "440006.\n");
    for (int z = 0; z < 86; z++)
    {
        fprintf(fp_bill, "_");
    }
    fprintf(fp_bill, "\n\n");
    // Printing thr name of the patient
    fprintf(fp_bill, "Name of patient : %s\n\n", name_patient);
    fprintf(fp_bill, "***** MEDICINES LIST*****\n\n");
    for (int z = 0; z < 22; z++)
    {
        fprintf(fp_bill, " ");
    }
    // TABLE      NAME   | QUANTITY | PRICE | SUBTOTAL |
    fprintf(fp_bill, "NAME");
    for (int z = 0; z < 22; z++)
    {
        fprintf(fp_bill, " ");
    }
    fprintf(fp_bill, "|");
    fprintf(fp_bill, "  QUANTITY |");
    fprintf(fp_bill, "   PRICE   |");
    fprintf(fp_bill, " SUB_TOTAL  ");
    fprintf(fp_bill, "\n");
    int lth;
    for (int z = 0; z < num_tab; z++)
    {
        if (billing_amount[z] != 0)
        {
            // It only prints the tablets which are in stock
            fprintf(fp_bill, "%d) %s", z + 1, mem[z].tablets);
            lth = length_of_name(mem[z].tablets);
            for (int r = 0; r < (45 - lth); r++)
            {
                fprintf(fp_bill, " ");
            }
            fprintf(fp_bill, "|");
            fprintf(fp_bill, "    %d     |", mem[z].quant);
            fprintf(fp_bill, "   %.2f    |", find_price(mem[z].tablets, me));
            fprintf(fp_bill, "   %.2f    ", (mem[z].quant * find_price(mem[z].tablets, me)));
        }
        fprintf(fp_bill, "\n");
    }
    for (int s = 0; s < 67; s++)
    {
        fprintf(fp_bill, " ");
    }
    // Printing total amount
    fprintf(fp_bill, "TOTAL :%.2f\n", total_amount);
    for (int d = 0; d < 42; d++)
    {
        fprintf(fp_bill, "_ ");
    }
    fprintf(fp_bill, "\n");
    for (int y = 0; y < 48; y++)
    {
        fprintf(fp_bill, " ");
    }
    // The EXTERNAL CHAR VARIABLE IS USED HERE
    fprintf(fp_bill, "Bill Issued by:-%s\n", provider);
    for (int y = 0; y < 31; y++)
    {
        fprintf(fp_bill, " ");
    }
    fprintf(fp_bill, "WE ARE HERE TO HELP YOU,GET WELL SOON...............\n\n\n");

    // Closing the file
    fclose(fp_bill);
    // Reopening the file to print character by character
    fp_bill = fopen(name_patient, "r");
    char ch;
    purple();
    printf("****************************************BILL*****************************************\n");
    reset();
    while (1)
    {
        ch = fgetc(fp_bill);
        if (ch == EOF)
        {
            break;
        }
        else
        {
            printf("%c", ch);
        }
    }
    printf("\n");

    return 0;
}

int main()
{
    blue();
    printf("==================================WELCOME TO FRIENDS LOGIN PAGE=================================\n");
    reset();
    red();
    printf("!!!***Kindly enter your login details***!!!\n");
    reset();
    int n;
    // Calling "Checking Function" to check the user
    int k = checking();
    if (k == 0)
    {
        exit(100);
    }
    else
    {
    entry: // IF WRONG INPUT (OTHER THAN 1,2,3 is given goto entry is used)

        int b = 10;
        while (b != 0)
        {
            yellow();
            printf("\n1-Stock checking");
            printf("\n2-Add a new stock");
            printf("\n3-billing");
            reset();
            red();
            printf("\nEnter the input:");
            reset();
            scanf("%d", &n); // Taking input from user which one he want to update
            if (n == 1)
            {
                stock_checking();
            }
            else if (n == 2)
            {
                adding();
            }
            else if (n == 3)
            {
                billing();
            }
            else
            {
                printf("Entered an valid input!!\n");
                goto entry;
            }
            blue();
            printf("Enter any number to countinue and for exit enter \"0\":\n");
            reset();
            scanf("%d", &b);
        }
    }
    return 0;
}