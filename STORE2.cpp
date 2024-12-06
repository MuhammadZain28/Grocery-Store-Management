# include <iostream>
# include <iomanip>
# include <cstring>
# include <string>
# include <fstream>
# include <conio.h>
# include <windows.h>
# include <cctype>

using namespace std;

int const psize = 100;                 // Total No Of Products can be added

bool validation(int input);                                                                     // check input validation
void inputDate(string date);                                                                    // input date from user
string hidePassword();

bool logIn(string x, string name, string y, string key);                                        //for admin and employee log in
void signUp(string name[], string pass[], string bank[], double balance[], int size);           // sign up as user
bool signIn(string x, string y);                                                                // sign in 

double sort(double arr1[], double arr2[],double arr3[], int size);                              // sort discount list to apply right discount

void initialize(string arr[], int size, string value);                                          // initialize string array
void assigning(string arr[][50], int size, int lenght, string value);                           // intialize 2D array
void initializeDouble(double arr[], int size, double value);                                    // double array

double addProduct(string arr1[], int arr2[], int arr3[], int arr4[], int size);                 // take products from admin
void addEmployee(string arr1[], double arr2[], int size);                                       // admin add employees 
void addCart(string products[][50], int Cartquantity[][50],int price[][50], int size);          // add products in user cart

void displayList(string arr1[], int sale[], int cost[], int stock[], int size);                 // display list of products
void discountList(double arr1[], double arr2[], int size);                                      // display list of discounts
void customerList(string arr1[], string arr2[], double arr3[], int size);                       // display list of customers
void employeeList(string arr1[], double arr2[], int size);                                      // display list of employees
void cartList(string product[][50], int quantity[][50],int price[][50], int size);              // display list of products in cart
void displayListToCustomer(string arr1[], int sale[], int stock[], int size);                   // display list of products to customer

void generateBill(string product[][50], int quantity[][50], int price[][50], int size);         // generate Bill of items in cart

bool productEdit(string arr1[], int arr2[], int arr3[], int arr4[], string edit, int size);     // Admin edits products added 

bool searchProduct(string arr1[], int arr2[], int arr3[], string edit, int size);               // search of product
bool searchCustomer(string arr1[], string arr2[], double arr3[], string edit, int size);        // search of customers

bool productDelete(string item[], int price[], int stock[], int costPrice[], string edit, int size);   //     *********************************
bool discountDelete(double arr1[], double edit, int size);                                             //
bool employeeDelete(string arr1[], string edit, int size);                                             //      DELETE RESPECTIVE NAME ELEMENTS
bool customerDelete(string arr1[], string arr2[], double arr3[], string edit, int size);               //
bool cartDelete(string product[][50], int quantity[][50], string del, int size);                       //     **********************************                             

void compareSales(int sale[]);                                                                         // Graphically compare sales on daily basis      
double totalSales(int sale[]);                                                                         // Total sales of Month

double applyDiscount(int bill, double criteria[], double percentage[],double maxDiscount[], int size);   // suitable Discounts on Purchase
void removeStock(int quantity[][50], int find[][2], int index, int size);                              // Remove  Purchased quantity from product stock
void plusStock(int quantity[][50], int find[][2], int index, int size);                                            // Add quantity back in stock which is deleted from cart 
void rechargeCard(string name[], string password[], string bank[], double balance[], int size);        // recharge balance in store card

void validateDate(string date);                                                                        //validate and store date month
bool productValidation(int sale,int cost,int quantity);                                                //validate Product cost , sale, stock
bool stringValidation(string input);                                               
double profitLoss(double purchase, double sales);                                                      // Profit and Loss Percentsge Calculation
void graph(double month[]);                                                                            // Graphically shows sales of month
void setCoord(int x, int y);                                                                           // Set coordinates of graph

bool searchUser(string user, int size, int index);                                                     // check that same username exist or not
void upper(string& name);
// *****************************************************************************************************************************************************

void tokenizer(string token,string (&product)[psize], int (&cost)[psize], int (&sale)[psize], int (&stock)[psize],int index);
bool loadProducts(string (&product)[psize], int (&cost)[psize], int (&sale)[psize], int (&stock)[psize], int size);
bool saveProducts(string (&product)[psize], int (&cost)[psize], int (&sale)[psize], int (&stock)[psize], int size);
void loadUser(string (&username)[psize],string (&passkey)[psize],string (&bank)[psize],double (&balance)[psize],double (&usedBalance)[psize]);
void saveUser(string (&username)[psize],string (&passkey)[psize],string (&bank)[psize],double (&balance)[psize],double (&usedBalance)[psize],int size);
void loadCart(string (&cart)[psize][50],int (&quantity)[psize][50],int (&price)[psize][50]);
void saveCart(string (&cart)[psize][50],int (&quantity)[psize][50],int (&price)[psize][50],int size);
void loadSales(int (&sale)[31],double (&saleOfMonth)[12],double (&totalOfMonth)[12]);
void saveSales(int (&sale)[31],double (&saleOfMonth)[12],double (&totalOfMonth)[12]);
int stringToInt(string word);

// *****************************************************************************************************************************************************
//                                 Functions to load and Store Data in files


int const cartSize = 50;               // Total No Of Products can be added in customer cart
const int dsize = 15;                  // Total No of Discounts Can be added
            
int userSearchIndex = 0;               // Searches user in user name array
int index = 0;                         // Searches Product & its stock

string username[psize];            
string passkey[psize];                 // For username & passwords 

bool flag1[psize];                     // Check for whether element exist or not

string snacks[psize];
string grocery[psize];
string product[psize];                 // products other than above both

                                       
// S for snack ,G for grocery ,O for other products

// cost price, sale price, & stock
int Sprice[psize];
int Sstock[psize];
int ScostPrice[psize];

// cost price, sale price, & stock
int Gprice[psize];
int Gstock[psize];
int GcostPrice[psize];

// cost price, sale price, & stock
int Oprice[psize];
int Ostock[psize];
int OcostPrice[psize];

string bank[psize];                  // Bank account of user
double balance[psize];               // balance added in card
double usedBalance[psize];           // total balance used 
 
string employee[psize];              // for employees name
double salary[psize];                // their salaries
 
string cart[psize][50];              // product in customer cart
int cartQuantity[psize][50];         // quatity & price of product
int cartPrice[psize][50];
 
double discountCoupons[dsize];       // discount criteria
double discountPercentage[dsize];
double maxDiscount[dsize];

int productFind[cartSize][2];        // store product index and its existence in array

int sale[31];                        // store day wise sales
double total = 0;                    // total for bill

double totalOfMonth[12] = {0};
double saleOfMonth[12] = {0};

string date = "01-01-2024";
int day = 0;
int month = 0;
int year = 2024;

int main()
{
    int choice = 0;     // choice in main menu
    int input = 0;      // choice in sub menu
    int Pchoice = 0;    // choice in menu inside sub menu

    string user = "N/A";    
    string key = "N/A";

    char control;

    bool mainLoopFlag = false;      // loop controller
    bool Aflag = false;             // admin page loop controller
    bool Cflag = false;             // Customer page loop controller
    bool Eflag = false;             // employee page loop controller

    string edit = "N/A";            //for edit and delete a product
    string queries[5];


    assigning(cart, cartSize,psize,"N/A");             //
    initialize(username,psize,"N/A");                  //
    initialize(grocery,psize,"N/A");                   //
    initialize(snacks,psize,"N/A");                    //
    initialize(product,psize,"N/A");                   //              intialization of array
    initializeDouble(discountCoupons,dsize,0);         //
    initializeDouble(discountPercentage,dsize,0);      //
    initialize(employee,psize,"N/A");                  //
    initialize(queries,5,"N/A");                       //

    
    loadProducts(grocery,GcostPrice,Gprice,Gstock,psize);
    loadUser(username,passkey,bank,balance,usedBalance);
    loadCart(cart,cartQuantity,cartPrice);
    loadSales(sale,saleOfMonth,totalOfMonth);

    while(mainLoopFlag == false)
    {
        bool flag = false;           // controller
        Aflag = false;               // admin page loop controller
        Cflag = false;               // Customer page loop controller
        Eflag = false;               // employee page loop controller
        system("cls");
        system("color 06");
        cout << "****************************************************************************************************************************************************************************" << endl;                                                
        cout << "              _______ .______        ______     ______  _______ .______     ____    ____         _______.___________.  ______   .______       _______                       " << endl;
        cout << "             /  _____||   _  \\      /  __  \\   /      ||   ____||   _  \\    \\   \\  /   /        /       |           | /  __  \\  |   _  \\     |   ____|               " << endl;
        cout << "            |  |  __  |  |_)  |    |  |  |  | |  ,----'|  |__   |  |_)  |    \\   \\/   /        |   (----`---|  |----`|  |  |  | |  |_)  |    |  |__                       " << endl;
        cout << "            |  | |_ | |      /     |  |  |  | |  |     |   __|  |      /      \\_    _/          \\   \\       |  |     |  |  |  | |      /     |   __|                     " << endl;
        cout << "            |  |__| | |  |\\  \\----.|  `--'  | |  `----.|  |____ |  |\\  \\----.   |  |        .----)   |      |  |     |  `--'  | |  |\\  \\----.|  |____                 " << endl;
        cout << "             \\______| | _| `._____| \\______/   \\______||_______|| _| `._____|   |__|        |_______/       |__|      \\______/  | _| `._____||_______|                  " << endl;
        cout << "                                                                                                                                                                            " << endl;                                       
        cout << "****************************************************************************************************************************************************************************" << endl;
        cout << endl;
        cout << "                       1.           Log in as Admin       " << endl;
        cout << "                       2.           Log in as Employee    " << endl;
        cout << "                       3.           Sign in as Customer   " << endl;
        cout << "                       4.           Sign Up as Customer   " << endl;
        cout << "                       0.           Exit                  " << endl << endl;
        do
        {
            cout << "                                    Enter Choice : ";
            cin >> choice;
            cin.ignore(100,'\n');
        } 
        while (validation(choice));
        
        cout << endl;
        if (choice == 1)        // log in as admin
        {
            if (logIn(user,"Admin",key,"1234"))
            {
                        while (Aflag == false)
                {
                    system("cls");
                    cout << "****************************************************************************************************************************************************************************" << endl;                                                
                    cout << "                 _______ .______        ______     ______  _______ .______     ____    ____         _______.___________.  ______   .______       _______                    " << endl;
                    cout << "                /  _____||   _  \\      /  __  \\   /      ||   ____||   _  \\    \\   \\  /   /        /       |           | /  __  \\  |   _  \\     |   ____|            " << endl;
                    cout << "               |  |  __  |  |_)  |    |  |  |  | |  ,----'|  |__   |  |_)  |    \\   \\/   /        |   (----`---|  |----`|  |  |  | |  |_)  |    |  |__                    " << endl;
                    cout << "               |  | |_ | |      /     |  |  |  | |  |     |   __|  |      /      \\_    _/          \\   \\       |  |     |  |  |  | |      /     |   __|                  " << endl;
                    cout << "               |  |__| | |  |\\  \\----.|  `--'  | |  `----.|  |____ |  |\\  \\----.   |  |        .----)   |      |  |     |  `--'  | |  |\\  \\----.|  |____              " << endl;
                    cout << "                \\______| | _| `._____| \\______/   \\______||_______|| _| `._____|   |__|        |_______/       |__|      \\______/  | _| `._____||_______|               " << endl;
                    cout << "                                                                                                                                                                            " << endl;                                       
                    cout << "                                                                                  (ADMIN)                                                                                " << endl;
                    cout << "****************************************************************************************************************************************************************************" << endl;
                    cout << endl;
                    cout << "                      1.             Add a Product stock                         " << endl;
                    cout << "                      2.             Edit a Product                              " << endl;
                    cout << "                      3.             Delete a Product                            " << endl;
                    cout << "                      4.             List of Product                             " << endl;
                    cout << "                      5.             Search a Product                            " << endl;
                    cout << "                      6.             Set Discounts                               " << endl;
                    cout << "                      7.             List of Discounts                           " << endl;
                    cout << "                      8.             Delete a Discount                           " << endl;
                    cout << "                      9.             Add a Employee                              " << endl;
                    cout << "                      10.            List of Employees                           " << endl;
                    cout << "                      11.            Delete a Employee                           " << endl;
                    cout << "                      12.            Comparison of Sales                         " << endl;
                    cout << "                      13.            Profit/Loss Percentage                      " << endl;
                    cout << "                      14.            Queries from Staff                          " << endl;
                    cout << "                      0.             Exit                                " << endl << endl;
                    do
                    {
                        cout << "                                     Enter Choice : ";
                        cin >> input;
                        cin.ignore(100,'\n');
                    } 
                    while (validation(input));
            
                    cout << endl;

                    if (input == 1)
                    {
                        do
                        {
                            system("cls");
                            cout << "***************************************************************************************************************************" << endl;
                            cout << "                                                 Add a Product                                                           \n";
                            cout << "***************************************************************************************************************************" << endl;
                            cout << endl;
                            cout << "  1.       Grocery                             " << endl;
                            cout << "  2.       Snacks                              " << endl;
                            cout << "  3.       Others                            \n" << endl;
                            do
                            {
                                cout << "                  Enter Product type you want to Add :   "; // select type from 1, 2, 3
                                cin >> Pchoice;
                                cin.ignore(100,'\n');
                            } 
                            while (validation(Pchoice));

                            cout << endl << endl;

                            if (Pchoice == 1)
                            {
                                totalOfMonth[month] += addProduct(grocery,Gprice,GcostPrice,Gstock,psize);  //
                            }

                            else if (Pchoice == 2)
                            {
                                totalOfMonth[month] += addProduct(snacks,Sprice,ScostPrice,Sstock,psize);   //      Total Add in month
                            }

                            else if (Pchoice == 3)
                            {
                                totalOfMonth[month] += addProduct(product,Oprice,OcostPrice,Ostock,psize);  //
                            }
                            else
                            {
                                cout << "            -----------------------------------------Invalid Input !-----------------------------------------" <<endl;
                            }
                            cout << "                  Enter '0' for exit :   ";     // pressing 0 bring back to menu
                            control = getch();
                        } 
                        while (control != '0');
                        
                        
                    }

                    else if (input == 2)
                    {
                        bool editFlag = false;
                        system("cls");
                        cout << "***************************************************************************************************************************" << endl;
                        cout << "                                                  Edit a Product                                                         \n";
                        cout << "***************************************************************************************************************************" << endl;
                        cout << endl;
                        cout << "                    Enter Product You Want to Edit : ";
                        getline(cin, edit);
                        upper(edit);

                        if (editFlag == false)
                        {
                            editFlag = productEdit(grocery, Gprice, Gstock,GcostPrice, edit, psize);             // if product is not find in 1 array then it goes to next
                        }
                        if (editFlag == false)
                        {
                            editFlag = productEdit(snacks, Sprice, Sstock,ScostPrice, edit, psize);
                        }
                        if (editFlag == false)
                        {
                            editFlag = productEdit(product, Oprice, Ostock,OcostPrice, edit, psize);
                        }
                        else if (editFlag == false)
                        {
                            cout <<endl << endl;
                            cout << "    -------------------------------------Unable to Find Product------------------------------------- ";
                            cout <<endl << endl;
                        }
                        else
                        {
                            cout <<endl << endl;
                            cout << "    ----------------------------------Product Updated Successfully---------------------------------- ";
                            cout <<endl << endl;
                        }
                        getch();
                    }
                    
                    else if (input == 3)
                    {
                        bool editFlag = false;
                        system("cls");
                        cout << "***************************************************************************************************************************" << endl;
                        cout << "                                                 Delete a Product                                                        \n";
                        cout << "***************************************************************************************************************************" << endl;
                        cout << endl;
                        cout << "                    Enter Product You Want to Delete : ";
                        getline(cin, edit);
                        upper(edit);

                        if (editFlag == false)
                        {
                            editFlag = productDelete(grocery, Gprice, Gstock,GcostPrice, edit, psize);
                        }
                        if (editFlag == false)
                        {
                            editFlag = productDelete(snacks, Sprice, Sstock,ScostPrice, edit, psize);
                        }
                        if (editFlag == false)
                        {
                            editFlag = productDelete(product, Oprice, Ostock,OcostPrice, edit, psize);
                        }
                        if (editFlag == false)
                        {
                            cout <<endl << endl;
                            cout << "    -------------------------------------Unable to Find Product------------------------------------- ";
                        }
                        
                    }

                    else if (input == 4)
                    {
                        system("cls");
                        cout << "*********************************************************************************************************************************" << endl;
                        cout << "         " << setw(20) << "Sr.no" << setw(30) <<"Product" << setw(30) <<"Sale Price" << setw(30) <<"Cost Price" <<"    Stock" <<endl;
                        cout << "*********************************************************************************************************************************" << endl <<endl;
                        cout << "                                                             Grocery Items                                                            \n";
                        cout << endl;
                        displayList(grocery,Gprice,GcostPrice,Gstock,psize);
                        cout << "                                                                 Snacks                                                               \n";
                        cout << endl;
                        displayList(snacks,Sprice,ScostPrice,Sstock,psize);
                        cout << "                                                             Other Products                                                           \n";
                        cout << endl;
                        displayList(product,Oprice,OcostPrice,Ostock,psize);
                        getch();
                    }
                    
                    else if (input == 5)
                    {
                        bool editFlag = false;
                        system("cls");
                        cout << "***************************************************************************************************************************" << endl;
                        cout << "                                                 Search a Product                                                        \n";
                        cout << "***************************************************************************************************************************" << endl;
                        
                        do
                        {
                            cout << endl;
                            cout << "                    Enter Product You Want to Search : ";
                            getline(cin, edit);
                        }
                        while(stringValidation(edit));

                        if (editFlag == false)
                        {
                            editFlag = searchProduct(grocery, Gprice, Gstock, edit, psize);
                        }
                        if (editFlag == false)
                        {
                            editFlag = searchProduct(snacks, Sprice, Sstock, edit, psize);
                        }
                        if (editFlag == false)
                        {
                            editFlag = searchProduct(product, Oprice, Ostock, edit, psize);
                        }
                        if (editFlag == false)
                        {
                            cout <<endl << endl;
                            cout << "    -------------------------------------Unable to Find Product------------------------------------- ";
                            cout <<endl << endl;
                        }
                        getch();
                    }
                    
                    else if (input == 6)
                    {
                        int check;
                        do
                        {
                            system("cls");
                            cout << "***************************************************************************************************************************" << endl;
                            cout << "                                                 Set Discounts Coupons                                                   \n";
                            cout << "***************************************************************************************************************************" << endl;
                            cout << endl;
                        
                            for (int i = 0; i < dsize; i++)
                            {
                                flag = true;
                                if(discountCoupons[i] == 0)
                                {
                                    do
                                    {
                                        cout << "                            Enter Min Limit for Discount     : ";
                                        cin >> discountCoupons[i];
                                        cout << "                            Enter Discount Percentage        : ";
                                        cin >> discountPercentage[i];
                                        cout << "                            Enter Maximum Discount on Coupon : ";
                                        cin >> maxDiscount[i];
                                    } 
                                    while (productValidation(discountCoupons[i],discountPercentage[i],maxDiscount[i]));

                                    flag = false;
                                    break;
                                }
                            }

                            if (flag)
                            {       
                                cout <<endl << endl;
                                cout << "    ----------------------------------Unable to Store Discount---------------------------------- ";
                                cout <<endl << endl;
                                cout << "       ----------------------------------Unsufficient Storage---------------------------------- ";
                                cout <<endl << endl;
                            }
                            sort(discountCoupons,discountPercentage,maxDiscount,dsize);
                            cout << "                  Enter '0' for exit :   ";
                            control = getch();
                            
                        } 
                        while (control != '0' && check != 0);
                    }
                    
                    else if (input == 7)
                    {
                        system("cls");
                        cout << "***************************************************************************************************************************" << endl;
                        cout << "                                                    Discounts List                                                       \n";
                        cout << "***************************************************************************************************************************" << endl <<endl;
                        cout <<  "         " << setw(30) << "Sr.no" << setw(30) << "Coupon Name" << setw(30) << "Discount Percentage" <<endl;
                        cout << endl;
                        discountList(discountCoupons,discountPercentage,dsize);
                        getch();
                    }

                    else if (input == 8)
                    {
                        system("cls");
                        double del = 0;
                        cout << "***************************************************************************************************************************" << endl;
                        cout << "                                                Delete a Discount                                                        \n";
                        cout << "***************************************************************************************************************************" << endl;
                        cout << endl;
                        cout << "                    Enter Discount Coupon You Want to Delete : ";
                        cin >> del; 

                        discountDelete(discountCoupons,del,dsize);
                        getch();
                    }

                    else if (input == 9)
                    {
                        do
                        {
                            system("cls");
                            cout << "***************************************************************************************************************************" << endl;
                            cout << "                                                 Add a Employee                                                          \n";
                            cout << "***************************************************************************************************************************" << endl;
                            cout << endl;
                            addEmployee(employee, salary, psize);
                            cout << "                  Enter '0' for exit :   ";
                            control = getch();
                        } 
                        while (control != '0');
                    }

                    else if (input == 10)
                    {
                        system("cls");
                        cout << "***************************************************************************************************************************" << endl;
                        cout << "         " << setw(20) << "Sr.no" << setw(50) <<"Employee Name" << setw(30) << "Salary" <<endl;
                        cout << "***************************************************************************************************************************" << endl <<endl;

                        employeeList(employee, salary, psize);
                        getch();
                    }

                    else if (input == 11)
                    {
                        system("cls");
                        cout << "***************************************************************************************************************************" << endl;
                        cout << "                                             Delete a Employee Record                                                    \n";
                        cout << "***************************************************************************************************************************" << endl;
                        cout << endl;
                        cout << "                    Enter Employee Name You Want to Delete : ";
                        getline(cin, edit); 

                        employeeDelete(employee,edit,dsize);
                        getch();
                    }

                    else if (input == 12)
                    {
                        saleOfMonth[month] = totalSales(sale);  // calculate total sales of month
                        graph(saleOfMonth);                     // graphically shows sale on monthly basis
                        compareSales(sale);                     // graphically shows sale on daily basis
                        getch();
                    }

                    else if (input == 13)
                    {
                        double profitPercentage = 0;
                        system("cls");
                        cout << "***************************************************************************************************************************" << endl;
                        cout << "                                            Profit and Loss Percentage                                              \n";
                        cout << "***************************************************************************************************************************" << endl;
                        cout << endl;
                        saleOfMonth[month] = totalSales(sale);
                        cout << "         T O T A L   P U R C H A S E   :    " << totalOfMonth[month] << endl << endl;
                        cout << "         T O T A L   S A L E S         :    " << saleOfMonth[month] << endl << endl;

                        if ( totalOfMonth[month] > 0)  // shows profit or loss
                        {
                            profitPercentage = profitLoss(totalOfMonth[month],saleOfMonth[month]);
                            if (profitPercentage > 0)
                            {
                                cout << "         P R O F I T   O F   M O N T H        :    " << saleOfMonth[month] - totalOfMonth[month] << endl << endl;
                                cout << "         P R O F I T   P E R C E N T A G E    :    " << profitPercentage << " % " << endl;
                            }
                            else
                            {
                                cout << "         L O S S   O F   M O N T H            :    " << totalOfMonth[month] - saleOfMonth[month] << endl << endl;
                                cout << "         L O S S   P E R C E N T A G E        :    " << profitPercentage << " % " << endl;
                            }
                        }
                        getch();
                    }

                    else if (input == 14)
                    {
                        system("cls");
                        cout << "***************************************************************************************************************************" << endl;
                        cout << "                                                   Queries from Staff                                                    \n";
                        cout << "***************************************************************************************************************************" << endl;
                        cout << endl;
                        for (int i = 0; i < 5; i++)
                        {
                            if (queries[i] != "N/A")
                            {
                                cout << i + 1 << ".    "<< queries[i]; 
                                flag = true;
                            }
                        }
                        if (!flag)
                        {
                            cout <<endl << endl;
                            cout << "    -------------------------------------Queries Section is Empty------------------------------------- ";
                        }    
                        getch();

                        initialize(queries,5,"N/A");  // made empty queries admin read it
                    }
                    
                    else if (input == 0)
                    {
                        cout << "              --------------------------------------------T H A N K  Y O U !----------------------------------------------" <<endl;
                        cout << "             -------------------------------------------- BACK TO LOGIN PAGE-----------------------------------------------" << endl;
                        Aflag = true;
                        getch();
                    }

                    else
                    {
                        cout << "            --------------------------------------------INVALID INPUT!--------------------------------------------" << endl;
                        getch();
                    }
                }
        
            }    
        }
    
        else if (choice == 2)  // log in as employee
        {
            if (logIn(user,"Employee",key,"1234"))
            {
                        while (Eflag == false)
                {
                    system("cls");
                    cout << "****************************************************************************************************************************************************************************" << endl;                                                
                    cout << "                 _______ .______        ______     ______  _______ .______     ____    ____         _______.___________.  ______   .______       _______                    " << endl;
                    cout << "                /  _____||   _  \\      /  __  \\   /      ||   ____||   _  \\    \\   \\  /   /        /       |           | /  __  \\  |   _  \\     |   ____|            " << endl;
                    cout << "               |  |  __  |  |_)  |    |  |  |  | |  ,----'|  |__   |  |_)  |    \\   \\/   /        |   (----`---|  |----`|  |  |  | |  |_)  |    |  |__                    " << endl;
                    cout << "               |  | |_ | |      /     |  |  |  | |  |     |   __|  |      /      \\_    _/          \\   \\       |  |     |  |  |  | |      /     |   __|                  " << endl;
                    cout << "               |  |__| | |  |\\  \\----.|  `--'  | |  `----.|  |____ |  |\\  \\----.   |  |        .----)   |      |  |     |  `--'  | |  |\\  \\----.|  |____              " << endl;
                    cout << "                \\______| | _| `._____| \\______/   \\______||_______|| _| `._____|   |__|        |_______/       |__|      \\______/  | _| `._____||_______|               " << endl;
                    cout << "                                                                                                                                                                            " << endl;                                       
                    cout << "                                                                                    (Employee)                                                                              " << endl;
                    cout << "****************************************************************************************************************************************************************************" << endl;
                    cout << endl;
                    cout << "                        1.       List of Products             " << endl;
                    cout << "                        2.       Customer Details             " << endl;
                    cout << "                        3.       Search Customer              " << endl;
                    cout << "                        4.       Delete a Customer            " << endl;
                    cout << "                        5.       Search a Product             " << endl;
                    cout << "                        6.       Total Sales                  " << endl;
                    cout << "                        7.       Send Queries                 " << endl;
                    cout << "                        8.       Set Date                     " << endl;
                    cout << "                        0.       Exit                  " << endl << endl;
                    
                    do
                        {
                        cout << "                                 Enter Choice : ";
                        cin >> input;
                        cin.ignore(100,'\n');
                    } 
                    while (validation(input));
                    
                    cout << endl;
                    
                    if (input == 1)
                    {
                        system("cls");
                        cout << "***********************************************************************************************************************************" << endl;
                        cout << "         " << setw(20) << "Sr.no" << setw(30) <<"Product" << setw(30) <<"Sales Price" << setw(30) <<"Cost Price" << setw(30) <<"Stock" <<endl;
                        cout << "***********************************************************************************************************************************" << endl <<endl;
                        cout << "                                                             Grocery Items                                                            \n";
                        cout << endl;
                        displayList(grocery,Gprice,GcostPrice,Gstock,psize);
                        cout << "                                                                 Snacks                                                               \n";
                        cout << endl;
                        displayList(snacks,Sprice,ScostPrice,Sstock,psize);
                        cout << "                                                             Other Products                                                           \n";
                        cout << endl;
                        displayList(product,Oprice,OcostPrice,Ostock,psize);
                        getch();
                    }
                    
                    else if (input == 2)
                    {
                        system("cls");
                        cout << "***************************************************************************************************************************" << endl;
                        cout << "         " << setw(30) << "Sr.no" << setw(30) <<"Customer Name" << setw(30) <<"Account No." << setw(30) <<"Balance" <<endl;
                        cout << "***************************************************************************************************************************" << endl <<endl;
                        
                        customerList(username,bank,balance,psize);
                        getch();
                    }

                    else if (input == 3)
                    {
                        bool editFlag = false;
                        system("cls");
                        cout << "***************************************************************************************************************************" << endl;
                        cout << "                                                Search a Customer                                                        \n";
                        cout << "***************************************************************************************************************************" << endl;
                        cout << endl;
                        cout << "                    Enter Username of Customer : ";
                        getline(cin, edit);

                        if (editFlag == false)                                                        // search whether customer is exist or not
                        {
                            editFlag = searchCustomer(username, bank, balance, edit, psize);
                        }
                        if (editFlag == false)
                        {
                            cout <<endl << endl;
                            cout << "    -------------------------------------Unable to Customer------------------------------------- " <<endl << endl;
                            cout << "    ----------------------------------Does not Exist in System---------------------------------- " <<endl << endl;
                        }
                        getch();
                    }

                    else if (input == 4)
                    {
                        bool editFlag = false;
                        system("cls");
                        cout << "***************************************************************************************************************************" << endl;
                        cout << "                                                Delete a Customer                                                        \n";
                        cout << "***************************************************************************************************************************" << endl;
                        cout << endl;
                        cout << "                    Enter Username of Customer : ";
                        getline(cin, edit);

                        if (editFlag == false)
                        {
                            editFlag = customerDelete(username, bank, balance, edit, psize);
                        }
                        if (editFlag == false)
                        {
                            cout <<endl << endl;
                            cout << "    ----------------------------------Unable to Find Customer----------------------------------- ";
                            cout << "    ----------------------------------Does not Exist in System---------------------------------- ";
                        }
                        getch();
                    }
                            
                    else if (input == 5)
                    {
                        bool editFlag = false;
                        system("cls");
                        cout << "***************************************************************************************************************************" << endl;
                        cout << "                                                 Search a Product                                                        \n";
                        cout << "***************************************************************************************************************************" << endl;
                        
                        do
                        {
                            cout << endl;
                            cout << "                    Enter Product You Want to Search : ";
                            getline(cin, edit);
                        }
                        while(stringValidation(edit));

                        if (editFlag == false)
                        {
                            editFlag = searchProduct(grocery, Gprice, Gstock, edit, psize);
                        }
                        if (editFlag == false)
                        {
                            editFlag = searchProduct(snacks, Sprice, Sstock, edit, psize);
                        }
                        if (editFlag == false)
                        {
                            editFlag = searchProduct(product, Oprice, Ostock, edit, psize);
                        }
                        if (editFlag == false)
                        {
                            cout <<endl << endl;
                            cout << "    -------------------------------------Unable to Find Product------------------------------------- ";
                            cout <<endl << endl;
                        }
                        getch();
                    }
                    
                    else if (input == 6)
                    {
                        system("cls");
                        compareSales(sale);
                        getch();
                    }

                    else if (input == 7)
                    {
                        system("cls");
                        cout << "***************************************************************************************************************************" << endl;
                        cout << "                                                 Send Queries To Admin                                                   \n";
                        cout << "***************************************************************************************************************************" << endl;
                        cout << endl;
                        cout << " Enter Your Query  :  ";
                        for (int i = 0; i < 5; i++)
                        {
                            if (queries[i] == "N/A")
                            {
                                do
                                {
                                    getline(cin,queries[i]);
                                } 
                                while (stringValidation(queries[i]));
                                
                                flag = true;
                                break;
                            }
                            
                        }
                        if (!flag)
                        {
                            cout <<endl << endl;
                            cout << "    -------------------------------------Queries Section is Full------------------------------------- ";
                        }
                    }
                    
                    else if (input == 8)
                    {
                        system("cls");
                        cout << "***************************************************************************************************************************" << endl;
                        cout << "                                                     Set Date                                                            \n";
                        cout << "***************************************************************************************************************************" << endl;
                        cout << endl;
                        cout << "                                   Date :    " << date << endl << endl;
                        cout << " Enter Date in Format (DD-MM-YYYY)  :  ";
                        do
                        {
                            getline(cin,date);
                        } 
                        while (stringValidation(date));
                        
                        validateDate(date);
                        getch();
                    }

                    else if (input == 0)
                    {
                        cout << "            ------------------------------------------T H A N K  Y O U !------------------------------------------" <<endl;
                        cout << "            ------------------------------------------Back To Login Page------------------------------------------" << endl;
                        Eflag = true;
                        getch();
                    }
                    
                    else
                    {
                        cout << "            --------------------------------------------INVALID INPUT!--------------------------------------------" << endl;
                        getch();
                    }
                }
        
            }
            
        }
        
        else if (choice == 3)  // log in as customer
        {

            if (signIn(user,key))
            {
                    while (Cflag == false)
            {
                system("cls");
                cout << "****************************************************************************************************************************************************************************" << endl;                                                
                cout << "                 _______ .______        ______     ______  _______ .______     ____    ____         _______.___________.  ______   .______       _______                    " << endl;
                cout << "                /  _____||   _  \\      /  __  \\   /      ||   ____||   _  \\    \\   \\  /   /        /       |           | /  __  \\  |   _  \\     |   ____|            " << endl;
                cout << "               |  |  __  |  |_)  |    |  |  |  | |  ,----'|  |__   |  |_)  |    \\   \\/   /        |   (----`---|  |----`|  |  |  | |  |_)  |    |  |__                    " << endl;
                cout << "               |  | |_ | |      /     |  |  |  | |  |     |   __|  |      /      \\_    _/          \\   \\       |  |     |  |  |  | |      /     |   __|                  " << endl;
                cout << "               |  |__| | |  |\\  \\----.|  `--'  | |  `----.|  |____ |  |\\  \\----.   |  |        .----)   |      |  |     |  `--'  | |  |\\  \\----.|  |____              " << endl;
                cout << "                \\______| | _| `._____| \\______/   \\______||_______|| _| `._____|   |__|        |_______/       |__|      \\______/  | _| `._____||_______|               " << endl;
                cout << "                                                                                                                                                                            " << endl;                                       
                cout << "                                                                                  (Customer Menu)                                                                           " << endl;
                cout << "****************************************************************************************************************************************************************************" << endl;
                cout << endl;
                cout << "                        1.       Add a Product to Cart        " << endl;
                cout << "                        2.       Show Products in Your Cart   " << endl;
                cout << "                        3.       Delete a Product from Cart   " << endl;
                cout << "                        4.       List of All Products at Store" << endl;
                cout << "                        5.       User Detail                  " << endl;
                cout << "                        6.       Recharge Store Card          " << endl;
                cout << "                        7.       Generate Total Bill          " << endl;
                cout << "                        0.       Exit                  " << endl << endl;
        
                do
                {
                    cout << "                                 Enter Choice : ";
                    cin >> input;
                    cin.ignore(100,'\n');
                } 
                while (validation(input));
        
                if (input == 1)
                {
                    do
                    {        
                        system("cls");
                        cout << "***************************************************************************************************************************" << endl;
                        cout << "                                             Add a Product in Cart                                                       \n";
                        cout << "***************************************************************************************************************************" << endl;
                        cout << endl;
                        cout << "         " << setw(20) << "Sr.no" << setw(30) <<"Product" << setw(30) <<"Price" << setw(30) <<"Stock" <<endl;
                        cout << "***************************************************************************************************************************" << endl; 
                        cout <<endl;
                        cout << "                                                Grocery Items                                                            \n";
                        cout << endl;
                        displayListToCustomer(grocery,Gprice,Gstock,psize);
                        cout << "                                                    Snacks                                                               \n";
                        cout << endl;
                        displayListToCustomer(snacks,Sprice,Sstock,psize);
                        cout << "                                                Other Products                                                           \n";
                        cout << endl;
                        displayListToCustomer(product,Oprice,Ostock,psize);
                        cout << endl << endl;

                        addCart(cart,cartQuantity,cartPrice,psize);

                        cout << "                  Enter '0' for exit :   ";
                        control = getch();
                    } 
                    while (control != '0');
                    
                }

                else if (input == 2)
                {
                    system("cls");
                    cout << "***************************************************************************************************************************" << endl;
                    cout << "                                             Show Products in Cart                                                       \n";
                    cout << "***************************************************************************************************************************" << endl;
                    cout << endl;
                    cout << "         " << setw(20) << "Sr.no" << setw(30) <<"Product" << setw(30) <<"Quantity" << setw(30) <<"Price" <<endl;
                    cout << "***************************************************************************************************************************" << endl; 
                    cout <<endl;
                    cartList(cart,cartQuantity,cartPrice,psize);
                    getch();
                }
                
                else if (input == 3)
                {
                    bool editFlag = false;
                    system("cls");
                    cout << "***************************************************************************************************************************" << endl;
                    cout << "                                                 Delete a Product                                                        \n";
                    cout << "***************************************************************************************************************************" << endl;
                    cout << endl;
                    cout << "                    Enter Product You Want to Delete : ";
                    do
                    {
                        getline(cin, edit);

                    }
                    while (stringValidation(edit));
                    
                    upper(edit);

                    editFlag = cartDelete(cart, cartQuantity, edit, psize);
                }

                else if (input == 4)
                {
                    system("cls");
                    cout << "***************************************************************************************************************************" << endl;
                    cout << "         " << setw(20) << "Sr.no" << setw(30) <<"Product" << setw(30) <<"Price" << setw(30) <<"Stock" <<endl;
                    cout << "***************************************************************************************************************************" << endl <<endl;
                    cout << "                                                Grocery Items                                                            \n";
                    cout << endl;
                    displayListToCustomer(grocery,Gprice,Gstock,psize);
                    cout << "                                                    Snacks                                                               \n";
                    cout << endl;
                    displayListToCustomer(snacks,Sprice,Sstock,psize);
                    cout << "                                                Other Products                                                           \n";
                    cout << endl;
                    displayListToCustomer(product,Oprice,Ostock,psize);
                    getch();
                }
                
                else if (input == 5)
                {
                    system("cls");
                    cout << "***************************************************************************************************************************" << endl;
                    cout << "                                                      User Details                                                       \n";
                    cout << "***************************************************************************************************************************" << endl;
                    cout << endl;
                    
                    cout << left;
                    cout << endl << endl;
                    cout << "               U S E R N A M E                       :       "  << username[userSearchIndex];
                    cout << endl << endl;
                    cout << "               B A N K  A C C O U N T   N O          :       " << bank[userSearchIndex];
                    cout << endl << endl;
                    cout << "               S T O R E   C A R D   B A L A N C E   : Rs.   " << balance[userSearchIndex];
                    cout << endl << endl;
                    cout << "               T O T A L   B A L A N C E   U S E D   : Rs.   " << usedBalance[userSearchIndex];
                    getch();
                }

                else if (input == 6)
                {
                    system("cls");
                    cout << "***************************************************************************************************************************" << endl;
                    cout << "                                                   RECHARGE STORE CARD                                                   \n";
                    cout << "***************************************************************************************************************************" << endl;
                    cout << endl;
                    rechargeCard(username,passkey,bank,balance,psize);
                }
                
                else if (input == 7)
                {
                    system("cls");
                    cout << "***************************************************************************************************************************" << endl;
                    cout << "                                             Products in Your Cart                                                       \n";
                    cout << "***************************************************************************************************************************" << endl;
                    generateBill(cart,cartQuantity,cartPrice,psize);
                    getch();
                }

                else if (input == 0)
                {
                    cout << "            ------------------------------------------T H A N K  Y O U !------------------------------------------" <<endl;
                    cout << "            ------------------------------------------Back To Login Page.-----------------------------------------" << endl;
                    Cflag = true;
                    getch();
                }

                else
                {
                    cout << "            --------------------------------------------INVALID INPUT!--------------------------------------------" << endl;
                    getch();
                }
            }
        
            }    
        
        }

        else if (choice == 4)  // sign up as customer
        {
            signUp(username, passkey, bank, balance, psize);
        }

        else if (choice == 0)  // exiting program
        {
            cout << "            ------------------------------------------T H A N K  Y O U !------------------------------------------" <<endl;
            cout << "            -------------------------------------Program Closed Successfully.-------------------------------------" << endl;                
            mainLoopFlag = true;
        }
        
        else
        {
            cout << "            --------------------------------------------INVALID INPUT!--------------------------------------------" << endl;
            getch();
        }
    }
    
    saveProducts(grocery,GcostPrice,Gprice,Gstock,psize);
    saveUser(username,passkey,bank,balance,usedBalance,psize);
    saveCart(cart,cartQuantity,cartPrice,psize);
    saveSales(sale,saleOfMonth,totalOfMonth);
    return 0;
}

bool logIn(string x, string name, string y, string key)
{
    char ch = '1';
    while((x != name || y != key))  // loop runs until user enter right credentials     
    {
        system("cls");
        cout << "****************************************************************************************************************************************************************************" << endl;                                                
        cout << "                 _______ .______        ______     ______  _______ .______     ____    ____         _______.___________.  ______   .______       _______                    " << endl;
        cout << "                /  _____||   _  \\      /  __  \\   /      ||   ____||   _  \\    \\   \\  /   /        /       |           | /  __  \\  |   _  \\     |   ____|            " << endl;
        cout << "               |  |  __  |  |_)  |    |  |  |  | |  ,----'|  |__   |  |_)  |    \\   \\/   /        |   (----`---|  |----`|  |  |  | |  |_)  |    |  |__                    " << endl;
        cout << "               |  | |_ | |      /     |  |  |  | |  |     |   __|  |      /      \\_    _/          \\   \\       |  |     |  |  |  | |      /     |   __|                  " << endl;
        cout << "               |  |__| | |  |\\  \\----.|  `--'  | |  `----.|  |____ |  |\\  \\----.   |  |        .----)   |      |  |     |  `--'  | |  |\\  \\----.|  |____              " << endl;
        cout << "                \\______| | _| `._____| \\______/   \\______||_______|| _| `._____|   |__|        |_______/       |__|      \\______/  | _| `._____||_______|               " << endl;
        cout << "                                                                                                                                                                            " << endl;                                       
        cout << "                                                                                  (LOGIN PAGE)                                                                              " << endl;
        cout << "****************************************************************************************************************************************************************************" << endl;
        cout << endl;
        do
        {    
            cout << left;
            cout << setw(35) << endl;
            cout << "               U S E R N A M E :";
            getline(cin,x);
            cout << setw(35);
            cout << "               P A S S W O R D :";
            y = hidePassword();
        }
        while(stringValidation(x) || stringValidation(y));

        if(x != name || y != key)
        {
            cout << endl << endl;
            cout << "            --------------------------------------------INVALID USERNAME OR PASSWORD--------------------------------------------" << endl << endl;
            cout << "                      --------------------------------------------TRY AGAIN--------------------------------------------         " << endl << endl;
            cout << "Press 0 to exit  :  ";
            ch = getch();
            if (ch == '0')
            {
                return false;
            }
             
        }
    }
    return true;
}

void signUp(string name[], string pass[], string bank[], double balance[], int size)
{
    string confirm;
    for (int i = 0; i < size; i++)  
    {
        int index = 0;
        if (name[i] == "N/A" || name[i] == "")  // checks whether there is space in system or not
        {
            system("cls");
            cout << "****************************************************************************************************************************************************************************" << endl;                                                
            cout << "                 _______ .______        ______     ______  _______ .______     ____    ____         _______.___________.  ______   .______       _______                    " << endl;
            cout << "                /  _____||   _  \\      /  __  \\   /      ||   ____||   _  \\    \\   \\  /   /        /       |           | /  __  \\  |   _  \\     |   ____|            " << endl;
            cout << "               |  |  __  |  |_)  |    |  |  |  | |  ,----'|  |__   |  |_)  |    \\   \\/   /        |   (----`---|  |----`|  |  |  | |  |_)  |    |  |__                    " << endl;
            cout << "               |  | |_ | |      /     |  |  |  | |  |     |   __|  |      /      \\_    _/          \\   \\       |  |     |  |  |  | |      /     |   __|                  " << endl;
            cout << "               |  |__| | |  |\\  \\----.|  `--'  | |  `----.|  |____ |  |\\  \\----.   |  |        .----)   |      |  |     |  `--'  | |  |\\  \\----.|  |____              " << endl;
            cout << "                \\______| | _| `._____| \\______/   \\______||_______|| _| `._____|   |__|        |_______/       |__|      \\______/  | _| `._____||_______|               " << endl;
            cout << "                                                                                                                                                                            " << endl;                                       
            cout << "                                                                                  (LOGIN PAGE)                                                                              " << endl;
            cout << "****************************************************************************************************************************************************************************" << endl;
            cout << endl;
            cout << left;
            do
            {
                cout << setw(35) << endl;
                cout << endl <<"               U S E R N A M E                       :       ";
                getline(cin, name[i]);
                cout << setw(35);
                cout << endl <<"               P A S S W O R D                       :       ";
                pass[i] = hidePassword();
                cout << setw(35);
                cout << endl <<"               C O N F I R M   P A S S W O R D       :       ";
                confirm = hidePassword();

                while (pass[i] != confirm)
                {
                    cout << "  ------------------------------------------Invalid Confirm Password-----------------------------------------" << endl;
                    cout << "  -------------------------------------------------Try Again-------------------------------------------------" << endl;
                    cout << setw(35);
                    cout << "               C O N F I R M   P A S S W O R D :";
                    confirm = hidePassword();
                }

                cout << setw(35) << endl;
                cout << endl <<"               B A N K  A C C O U N T   N O          :       ";
                getline(cin, bank[i]);
                cout << setw(35) << endl;
            }
            while(stringValidation(bank[i]) || stringValidation(confirm) || searchUser(name[i],size,i)
                  || stringValidation(pass[i]) || stringValidation(name[i]));

            cout <<  endl <<"               B A L A N C E   T O   R E C H A R G E :    Rs. ";
            cin >> balance[i];
            cin.ignore(256, '\n'); 
            

            cout << "  ------------------------------------------Signed In Successfully-----------------------------------------" << endl;
            return ;
        }
    }
    cout << "                          ------------------------------------------Space is Full-----------------------------------------" << endl;
    cout << "                          -----------------------------------------Unable to Store----------------------------------------" << endl;
    
}

bool signIn(string x, string y)
{
    bool searchFlag;
    char ch;                  // used take out of login page
    do
    {
        searchFlag = true;
        system("cls");
        cout << "****************************************************************************************************************************************************************************" << endl;                                                
        cout << "                 _______ .______        ______     ______  _______ .______     ____    ____         _______.___________.  ______   .______       _______                    " << endl;
        cout << "                /  _____||   _  \\      /  __  \\   /      ||   ____||   _  \\    \\   \\  /   /        /       |           | /  __  \\  |   _  \\     |   ____|            " << endl;
        cout << "               |  |  __  |  |_)  |    |  |  |  | |  ,----'|  |__   |  |_)  |    \\   \\/   /        |   (----`---|  |----`|  |  |  | |  |_)  |    |  |__                    " << endl;
        cout << "               |  | |_ | |      /     |  |  |  | |  |     |   __|  |      /      \\_    _/          \\   \\       |  |     |  |  |  | |      /     |   __|                  " << endl;
        cout << "               |  |__| | |  |\\  \\----.|  `--'  | |  `----.|  |____ |  |\\  \\----.   |  |        .----)   |      |  |     |  `--'  | |  |\\  \\----.|  |____              " << endl;
        cout << "                \\______| | _| `._____| \\______/   \\______||_______|| _| `._____|   |__|        |_______/       |__|      \\______/  | _| `._____||_______|               " << endl;
        cout << "                                                                                                                                                                            " << endl;                                       
        cout << "                                                                                  (LOGIN PAGE)                                                                              " << endl;
        cout << "****************************************************************************************************************************************************************************" << endl;
        cout << endl;
        do
        {                    
            cout << left;
            cout << setw(35) << endl;
            cout << "               U S E R N A M E :";
            getline(cin,x);
            cout << setw(35);
            cout << "               P A S S W O R D :";
            y = hidePassword();
        
        } 
        while (stringValidation(x) || stringValidation(y));

        for (int i = 0; i < psize; i++)
        {
            if (username[i] == x && passkey[i] == y)
            {
                userSearchIndex = i;
                searchFlag = false;
                break;
            }
        }
        if(searchFlag)
        {
            cout << endl << endl;
            cout << "            --------------------------------------------INVALID USERNAME OR PASSWORD--------------------------------------------" << endl << endl;
            cout << "                      --------------------------------------------TRY AGAIN--------------------------------------------         " << endl << endl;
            cout << "Press '0' to exit  ";
            ch = getch();
        
            if (ch == '0')
            {
                return false;
            }
            
        }
    }while (searchFlag);

    return true;
}

void initialize(string arr[], int size, string value) 
{
    for (int i = 0; i < size; i++) {
        arr[i] = value;
    }
}

void initializeDouble(double arr[], int size, double value) 
{
    for (int i = 0; i < size; i++) {
        arr[i] = value;
    }
}

void initializeInt(int arr[], int size, int value) 
{
    for (int i = 0; i < size; i++) {
        arr[i] = value;
    }
}

double addProduct(string arr1[], int arr2[], int arr3[], int arr4[], int size)
{
    double total = 0;
    for (int i = 0; i < psize; i++)
    {
        flag1[1] = true;     // used to find whether item is stored or not
        if (arr1[i] == "N/A")
        {
            do
            {
                cout << endl  << "                Enter Product            : ";
                getline(cin,arr1[i]);
                upper(arr1[i]);
                cout << endl  << "                Enter Cost Price         : ";
                cin >> arr3[i];
                cin.ignore(256,'\n');
                cout << endl  << "                Enter Sale Price         : ";
                cin >> arr2[i];
                cin.ignore(256,'\n');
                cout << endl  << "                Enter Product Stock      : ";
                cin >> arr4[i];
                cin.ignore(256,'\n');
            } 
            while (productValidation(arr2[i],arr3[i],arr4[i]) || stringValidation(arr1[i])); // check validation of input
            
            total += arr3[i]*arr4[i];
            flag1[1] = false;
            cout << endl << "                   Product Stored Successfully      " << endl;
            break;
        }
    }
    if (flag1[1])
    {
        cout << "            -------------------------------------Store is Full-------------------------------------" <<endl;
        cout << "            ------------------------------------Unable to store------------------------------------" <<endl;
    }
    return total;
}

void addEmployee(string arr1[], double arr2[], int size)
{
    for (int i = 0; i < size; i++)
    {
        flag1[1] = true;
        if (arr1[i] == "N/A")
        {
            do
            {
                cout << "                Enter Employee Name : ";
                getline(cin,arr1[i]);
                cout << "                Enter Salary        : ";
                cin >> arr2[i];
                cin.ignore(256,'\n');
         
            }
            while(stringValidation(arr1[i]) || validation(arr2[i]));
            
            flag1[1] = false;
            cout << endl << "                            Employee Data Stored Successfully      " << endl;
            break;
        }
    }
    if (flag1[1])
    {
        cout << "            -------------------------------------Store is Full-------------------------------------" <<endl;
        cout << "            ------------------------------------Unable to store------------------------------------" <<endl;
    }
}

void addCart(string products[][50], int Cartquantity[][50],int price[][50], int size)
{
    
    string add;
    int quantity;
    for (int i = 0; i < size; i++)
    {
        bool searchFlag = false;
        flag1[1] = true;
        if (products[userSearchIndex][i] == "N/A")
        {
            do
            {
                cout << endl << "                Enter Product : ";
                getline(cin,add);
                upper(add);
                cout << endl << "                Enter Quantity : ";
                cin >> quantity;
                cin.ignore(100,'\n');
            } 
            while (stringValidation(add) || validation(quantity));
                

            if (searchFlag == false)
            {
                searchFlag = searchProduct(grocery, Gprice, Gstock, add, psize);
                if (searchFlag == true)
                {
                    if (quantity <= Gstock[index])
                    {
                        products[userSearchIndex][i] = add;
                        cartQuantity[userSearchIndex][i] = quantity;
                        price[userSearchIndex][i] = Gprice[index];
                        productFind[i][0] = 1;
                        productFind[i][1] = index;
                        removeStock(Cartquantity,productFind,i,size);
                    }
                    else if (quantity > Gstock[index])
                    {                        
                        cout <<endl << endl;
                        cout << "    -------------------------------------Unable to Store------------------------------------- " ;
                        cout <<endl << endl;
                    }
                }
            }
            if (searchFlag == false)
            {
                searchFlag = searchProduct(snacks, Sprice, Sstock, add, psize);
                if (searchFlag == true)
                {
                    if (quantity <= Sstock[index])
                    {
                        products[userSearchIndex][i] = add;
                        cartQuantity[userSearchIndex][i] = quantity;
                        price[userSearchIndex][i] = Sprice[index];
                        productFind[i][0] = 2;
                        productFind[i][1] = index;
                        removeStock(Cartquantity,productFind,i,size);
                    }
                    else if (quantity > Sstock[index])
                    {                        
                        cout <<endl << endl;
                        cout << "    -------------------------------------Unable to Store------------------------------------- " ;
                        cout <<endl << endl;
                    }
                }
            }
            if (searchFlag == false)
            {
                searchFlag = searchProduct(product, Oprice, Ostock, add, psize);
                if (searchFlag == true)
                {
                    if (quantity <= Ostock[index])
                    {
                        products[userSearchIndex][i] = add;
                        cartQuantity[userSearchIndex][i] = quantity;
                        price[userSearchIndex][i] = Oprice[index];
                        productFind[i][0] = 3;
                        productFind[i][1] = index;
                        removeStock(Cartquantity,productFind,i,size);
                    }
                    else if (quantity > Ostock[index])
                    {                        
                        cout <<endl << endl;
                        cout << "    -------------------------------------Unable to Store------------------------------------- " ;
                        cout <<endl << endl;
                    }
                }            }
            cout << endl << endl;
            cin.ignore(256,'\n');
            
            if (searchFlag == false)
            {
                cout <<endl << endl;
                cout << "    -------------------------------------Unable to Find Product------------------------------------- " ;
                cout <<endl << endl;
                break;
            }

            flag1[1] = false;
            cout << endl << "                   Product Stored Successfully      " << endl;
            break;
        }
    }
}

void displayList(string arr1[], int sale[], int cost[], int stock[], int size)
{
    cout <<left;
    flag1[4] = true;
    for (int i = 0; i < size; i++)
    {
        if (arr1[i] != "N/A")
        {
            cout  << "         " << setw(20) << i+1 << setw(30) << arr1[i] << "Rs." << setw(30) << sale[i] << "Rs." << setw(30) << cost[i] << stock[i] <<endl;
            flag1[4] = false;
        }
    }
    if (flag1[4] != false)
    {
        cout << endl << endl;
    }
}

void displayListToCustomer(string arr1[], int sale[], int stock[], int size)
{
    cout <<left;
    flag1[4] = true;
    for (int i = 0; i < size; i++)
    {
        if (arr1[i] != "N/A")
        {
            cout  << "         " << setw(20) << i+1 << setw(30) << arr1[i] << "Rs." << setw(30) << sale[i] << setw(30) << stock[i] <<endl;
            flag1[4] = false;
        }
    }
    if (!flag1[4])
    {
        cout << endl << endl;
    }
}

void discountList(double arr1[], double arr2[], int size)
{
    cout <<left;
    bool disFlag = true;
    for (int i = 0; i < size; i++)
    {
        if (arr1[i] != 0)
        {
            cout  << "         " << setw(30) << i+1 << setw(30) << arr1[i]  << arr2[i] << "%" <<endl;
            disFlag = false;
        }
    }
    if (disFlag == true)
    {
        cout << endl << endl;
    }
}

void cartList(string product[][50], int quantity[][50],int price[][50], int size)
{
    cout <<left;
    bool cartFlag = true;
    for (int i = 0; i < size; i++)
    {
        if (product[userSearchIndex][i] != "N/A")             // UserSearchIndex is global variable and assign its value customer sign in
        {
            cout  << "         " << setw(20) << i+1 << setw(30) << product[userSearchIndex][i] << setw(30)  << quantity[userSearchIndex][i]  << "  Rs." << setw(30) << price[userSearchIndex][i] <<endl;
            cartFlag = false;
        }
    }
    if (!cartFlag)
    {
        cout << endl << endl;
    }
}

bool productEdit(string item[], int sale[], int cost[], int stock[], string edit, int size)
{
    
    for (int i = 0; i < size; i++)
    {
        if (item[i] == edit)
        {
            totalOfMonth[month] -= cost[i]*stock[i];
            
            cout << endl << endl;
            cout << "          " << setw(30) <<"Product" << setw(30) <<"Price" << setw(30) <<"Stock" <<endl;
            cout << "***************************************************************************************************************************" << endl <<endl;
            cout << "          " << setw(30) << item[i] << "Rs." << setw(30) << cost[i] << setw(30) << stock[i] <<endl << endl;
            do
            {
                cout << "                Enter Product            : ";
                getline(cin,item[i]);
                cout << "                Enter Cost Price         : ";
                cin >> cost[i];
                cin.ignore(256,'\n');
                cout << "                Enter Sale Price         : ";
                cin >> sale[i];
                cin.ignore(256,'\n');
                cout << "                Enter Product Stock      : ";
                cin >> stock[i];
                cin.ignore(256,'\n');
                totalOfMonth[month] += cost[i]*stock[i];
            } 
            while (productValidation(sale[i],cost[i],stock[i]) || stringValidation(item[i]));
            return true;
        }
    }
    return false;
}

bool searchProduct(string arr1[], int arr2[], int arr3[], string edit, int size)
{
    
    for (int i = 0; i < size; i++)
    {
        if (arr1[i] == edit)
        {
            cout << endl << endl;
            
            cout << "***************************************************************************************************************************" << endl;
            cout << "          " << setw(30) <<"Product" << setw(30) <<"Price" << setw(30) <<"Stock" <<endl;
            cout << "***************************************************************************************************************************" << endl <<endl;
            cout << "          " << setw(30) << arr1[i] << "Rs." << setw(30) << arr2[i] << setw(30) << arr3[i] <<endl << endl;
            cout << "***************************************************************************************************************************" << endl <<endl;
            index = i;
            getch();
            return true;
        }
    }
    return false;
}

bool searchCustomer(string arr1[], string arr2[], double arr3[], string edit, int size)
{
    
    for (int i = 0; i < size; i++)
    {
        if (arr1[i] == edit)
        {
            cout << endl << endl;
            
            cout << "          " << setw(30) <<"Customer Name" << setw(30) <<"Account No." << setw(30) <<"Balance" <<endl;
            cout << "***************************************************************************************************************************" << endl <<endl;
            cout << "          " << setw(30) << arr1[i]<< setw(30) << arr2[i]  << "Rs." << setw(30) << arr3[i] <<endl << endl;
            index = i;
            getch();
            return true;
        }
    }
    return false;
}

bool productDelete(string item[], int price[], int stock[], int costPrice[], string edit, int size)
{
    int flag = 0;
    if (searchProduct(item, stock, price, edit, size))
    {
        cout << endl << endl;
        cout << "Confirm Delete (1 for Yes / 0 for no) : ";
        cin >> flag;
        if (flag == 1)
        {
            item[userSearchIndex] = "N/A" ;
            totalOfMonth[month] = totalOfMonth[month] - stock[userSearchIndex]*costPrice[userSearchIndex]; 
            cout << "            ----------------------------------Product Deleted Succesfully.----------------------------------" << endl;
            return true;
        }
    }
    return false;
}

bool discountDelete(double arr1[], double edit, int size)
{
    int flag = 0;
    for (int i = 0; i < size; i++)
    {
        if (arr1[i] == edit)
        {
            cout << endl << endl;
            cout << "Confirm Delete (1 for Yes / 0 for no) : ";
            cin >> flag;
            if (flag == 1)
            {
                arr1[i] = 0 ;
                cout << "";
                getch();
                return true;
            }
        }
    }
    
    return false;
}

bool employeeDelete(string arr1[], string edit, int size)
{
    int flag = 0;
    for (int i = 0; i < size; i++)
    {
        if (arr1[i] == edit)
        {
            cout << endl << endl;
            cout << "Confirm Delete (1 for Yes / 0 for no) : ";
            cin >> flag;
            if (flag == 1)
            {
                arr1[i] = "N/A" ;
                cout << "";
                getch();
                return true;
            }
        }
    }
    
    return false;
}

void customerList(string arr1[], string arr2[], double arr3[], int size)
{
    cout <<left;
    bool disFlag = true;
    for (int i = 0; i < size; i++)
    {
        if (arr1[i] != "N/A" && arr1[i] != "")
        {
            cout  << "         " << setw(30) << i+1 << setw(30) << arr1[i]  << setw(30) << arr2[i] << "Rs." << arr3[i] <<endl;
            disFlag = false;
        }
    }
    if (disFlag == true)
    {
        cout << endl << endl;
    }
}

void employeeList(string arr1[], double arr2[], int size)
{
    cout <<left;
    bool disFlag = true;
    for (int i = 0; i < size; i++)
    {
        if (arr1[i] != "N/A")
        {
            cout  << "         " << setw(20) << i+1 << setw(50) << arr1[i] << "Rs." << arr2[i] <<endl;
            disFlag = false;
        }
    }
    if (disFlag == true)
    {
        cout << endl << endl;
    }
}

bool customerDelete(string arr1[], string arr2[], double arr3[], string edit, int size)
{
    int flag = 0;
    if (searchCustomer(arr1, arr2, arr3, edit, size))
    {
        cout << endl << endl;
        cout << "Confirm Delete (1 for Yes / 0 for no) : ";
        cin >> flag;
        if (flag == 1)
        {
            arr1[userSearchIndex] = "N/A" ;
            cout << "            -------------------------------------Customer Data Deleted.-------------------------------------" << endl;
            return true;
        }
    }
    return false;
}

bool cartDelete(string product[][50], int quantity[][50], string del, int size)
{
    int flag = 0;
    for (int i = 0; i < size; i++)
    {
        if (product[userSearchIndex][i] == del)                                  // UserSearchIndex is global variable and assign its value customer sign in
        {
            cout << endl << endl;
            cout << "Confirm Delete (1 for Yes / 0 for no) : ";
            cin >> flag;
            if (flag == 1)
            {
                product[userSearchIndex][index] = "N/A" ;
                plusStock(quantity,productFind,i,size);
                cout << "            -------------------------------------Product Deleted.-------------------------------------" << endl;
                return true;
            }
        }
        }
    
    return false;
}

void generateBill(string product[][50], int quantity[][50], int price[][50], int size)
{
    int confirm;
    cout << endl;
    cout << "         " << setw(20) << "Sr.no" << setw(30) <<"Product" << setw(30) <<"Quantity" << setw(30) <<"  Price" <<endl;
    cartList(product, quantity, price, size);
    cout << endl << endl;
    cout << "               Confirm Purchase (1 for Yes / 0 for No)  :   ";
    cin >> confirm;
    if (confirm == 1)
    {
        system("cls");
        cout <<left;
        bool disFlag = true;
        int total = 0;
        int choice;
        cout << "***************************************************************************************************************************" << endl;
        cout << "                                                          Bill                                                           \n";
        cout << "***************************************************************************************************************************" << endl;        
        cout << endl;
        cout << "         " << setw(20) << "Sr.no" << setw(30) <<"Product" << setw(30) <<"Quantity" << setw(30) <<"Price" <<endl;            
        for (int i = 0; i < size; i++)
        {
            if (product[userSearchIndex][i] != "N/A")
            {
                cout  << "         " << setw(20) << i+1 << setw(30) << product[userSearchIndex][i] << setw(4) << quantity[userSearchIndex][i] << setw(26)  << " Pcs." << "Rs. "<< setw(30) << price[userSearchIndex][i]*quantity[userSearchIndex][i] <<endl;
                total = total + price[userSearchIndex][i]*quantity[userSearchIndex][i];
                flag1[4] = false;
            }
        }

        total = applyDiscount(total,discountCoupons,discountPercentage,maxDiscount,dsize);

        if (flag1[4] == false)
        {
            cout << endl;
            cout << "         " << setw(76) << " " << " **************" << endl;
            cout << endl;  
            cout << setw(60) << "         " << setw(28) << "Total : " << " Rs. " << total << endl;
            cout << endl;
            cout << "         " << setw(76) << " " << " **************" << endl;
        }
        cout << endl <<endl;
        cout << "     1.    STORE CARD     " << endl;
        cout << "     2.    CASH PAYMENT   " << endl << endl;

        do
        {
            cout << "           SELECT PAYMENT METHOD  :  ";
            cin >> choice;
        } 
        while (validation(choice));
            
        if (choice == 1)
        {
            if (total <= balance[userSearchIndex])    // add sales on day wise and subtract balance from user card and add in its activity
            {
                sale[day] = sale[day] + total;
                usedBalance [userSearchIndex] += total;
                balance [userSearchIndex] -= total;
                assigning(product,50,psize,"N/A");
                cout << endl << endl;
                cout << "            ----------------------------------------THANK YOU FOR YOUR PURCHASE----------------------------------------" << endl;
                getch();        
            }
            else
            {
                cout << "            --------------------------------------------NOT ENOUGH BALANCE--------------------------------------------" << endl;
                getch();
            }
            
        }
        else if (choice == 2)                 // add sales on day wise and add in its activity
        {
            sale[day] = sale[day] + total;
            usedBalance [userSearchIndex] += total;
            assigning(product,50,psize,"N/A");
            cout << endl << endl;
            cout << "            ----------------------------------------THANK YOU FOR YOUR PURCHASE----------------------------------------" << endl;
            getch();            
        }
        else
        {
            cout << "            --------------------------------------------INVALID INPUT!--------------------------------------------" << endl;
            getch();
        }
        saleOfMonth[month] += totalSales(sale); 
    }
    
}

void compareSales(int sale[])
{
        cout << "***************************************************************************************************************************" << endl;
        cout << "                                       Comparison of Sales on Daily Basis                                                \n";
        cout << "***************************************************************************************************************************" << endl;
    for (int i = 0; i < 31; i++)
    {
        cout << "    Day " << setw(2) << i+1 << setw(20)<< " :     ";

        for (int j = 1; j <= sale[i]; j=j+400)                   //Shows number * with respect sale on day
        {
            cout << "*";
        }
        cout << "  (Rs. " << sale[i] << ")" << endl;
    }
    cout << "          Rs. " << setw(15) << "";
    for (int i = 0; i <= 50000; i=i+5000)
    {
        cout << i << setw(8) << "";   
    }
}

bool validation(int input)
{
    
    if (cin.fail())       // to encounter crtl+z and string and char values
    {
        cin.clear();
        cin.ignore(256,'\n');
        return true;
    }
    else if (input < 0) 
    {
        cout << endl << endl;
        cout << "            --------------------------------------------INVALID INPUT!--------------------------------------------" << endl;
        cout << endl << endl;
        return true;
        getch();
    }
    else
    {
        return false;
    }
}

bool productValidation(int sale,int cost,int quantity)
{
    
    if (cin.fail())                                   
    {
        cin.clear();
        cin.ignore(256,'\n');
        return true;
    }
    else if (sale <= 0 || cost <= 0 || quantity <= 0)            // as these can never be -ve
    {
        cout << "            --------------------------------------------INVALID INPUT!--------------------------------------------" << endl;
        return true;
        getch();
    }
    else
    {
        return false;
    }
}

bool stringValidation(string input)
{
    if (cin.fail())
    {
        cin.clear();
        cin.ignore(256,'\n');
        cout << endl << endl;
        cout << "            --------------------------------------------INVALID INPUT!--------------------------------------------" << endl;
        cout << endl << endl;
        return true;
    }
    else
    {
        return false;
    }
}

double totalSales(int sale[])
{
    double total = 0;
    for (int i = 0; i < 31; i++)
    {
        total += sale[i];
    }
    return total;
}

double sort(double arr1[], double arr2[],double arr3[], int size)
{
    for (int i = 0; i < size - 1; i++)
    {
        for (int j = 0; j < size - i - 1; j++)
        {
            if (arr1[i] < arr1[i + 1]  && arr1[i + 1] != 0)           // sort discount criteria and percentage as they are parllel
            {
                swap(arr1[i],arr1[i + 1]);
                swap(arr2[i],arr2[i + 1]);
                swap(arr3[i],arr3[i + 1]);
            }
            
        }
    }
}

double applyDiscount(int bill,double criteria[], double percentage[],double maxDiscount[], int size)
{
    double discount = 0;
    for (int i = 0; i < size; i++)            // apply discount and shows its value
    {
        if (bill >=  criteria[i])
        {
            discount = bill * (percentage[i] / 100);
            if (discount <= maxDiscount[i])
            {
                cout << endl << setw(60) << "" << setw(29) << "Discount :" << "Rs." <<  discount << endl;
                bill = bill - discount;
            }
            else
            {
                cout << endl << setw(60) << "" << setw(29) << "Discount :" << "Rs." <<  maxDiscount << endl;
                bill = bill - maxDiscount[i]; 
            }
            
            return bill;
        }
    }
    return bill;
}

void removeStock(int quantity[][50], int find[][2], int index, int size)
{                                           //remove quantity when added to cart
    if (find[index][0] == 1)
    {
        Gstock[find[index][1]] -=  quantity[userSearchIndex][index];
    }
    if (find[index][0] == 2)
    {
        Sstock[find[index][1]] -=  quantity[userSearchIndex][index];
    }
    if (find[index][0] == 3)
    {
        Ostock[find[index][1]] -=  quantity[userSearchIndex][index];
    }
    return ;
}

void plusStock(int quantity[][50], int find[][2], int index, int size)
{
    if (find[index][0] == 1)
    {
        Gstock[find[index][1]] +=  quantity[userSearchIndex][index];
    }
    if (find[index][0] == 2)
    {
        Sstock[find[index][1]] +=  quantity[userSearchIndex][index];
    }
    if (find[index][0] == 3)
    {
        Ostock[find[index][1]] +=  quantity[userSearchIndex][index];
    }
    return ;   
}

void rechargeCard(string name[], string password[], string bank[], double balance[], int size)
{
    string user,key,acountNo;
    double recharge;
    do{                                                                         // recharge balance when user enter right credentials 
        cout << left;
        cout << setw(35) << endl;
        cout << "               U S E R N A M E                       :       ";
        getline(cin, user);
        cout << setw(35);
        cout << "               P A S S W O R D                       :       ";
        getline(cin, key);
        cout << setw(35) << endl;
        cout << "               B A N K  A C C O U N T   N O          :       ";
        getline(cin, acountNo);
        cout << setw(35) << endl;
    }
    while (stringValidation(user) || stringValidation(key) || stringValidation(acountNo));

    cout << "               B A L A N C E   T O   R E C H A R G E :        Rs. ";
    cin >> recharge;
    if (user == name[userSearchIndex]
        && key == password[userSearchIndex]
        && acountNo == bank[userSearchIndex])
    {
        balance[userSearchIndex] += recharge;
    }
    else
    {
        cout << "            --------------------------------------------INVALID CREDENTIALS!--------------------------------------------" << endl;
    }
}

void validateDate(string date)
{
    int lenght = date.length();
    if (date >= "01-01-2000" && date <= "31-12-3000"
        && date[2] == '-' && date[5] == '-'
        && lenght == 10)
    {
        if (month != stringToInt(date.substr(3,2)) - 1)
        {
            initializeInt(sale,31,0);
        }
        if (year != stringToInt(date.substr(6,4)))
        {
            initializeDouble(totalOfMonth,12,0);
            initializeDouble(saleOfMonth,12,0);
        }
        day =  stringToInt(date.substr(0,2)) - 1;
        month = stringToInt(date.substr(3,2)) - 1;
        year = stringToInt(date.substr(6,4));
    }
    else
    {
        cout << endl << endl;
        cout << "            ------------------------------------------INVALID FORMAT------------------------------------------" <<endl;
        cout << endl << endl;
        date = "00-00-0000";
    }
}

double profitLoss(double purchase, double sales)
{
    double profit;
    profit = ((sales-purchase) / purchase) * 100;
    return profit;
}

void setCoord(int x,int y)
{                                             // use in graphical representation
	COORD coordinates;
	coordinates.X = x;
	coordinates.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),coordinates);
}

void graph(double month[])
{
    system("cls");
    cout << "***************************************************************************************************************************" << endl;
    cout << "                                               Sales Graph on Monthly Basis                                              \n";
    cout << "***************************************************************************************************************************" << endl;
    cout << endl << endl;
    cout << "100000_|                                                                                                                         " << endl;
    cout << "       |                                                                                                                         " << endl;
    cout << " 90000_|                                                                                                                         " << endl;
    cout << "       |                                                                                                                         " << endl;
    cout << " 80000_|                                                                                                                         " << endl;
    cout << "       |                                                                                                                         " << endl;
    cout << " 70000_|                                                                                                                         " << endl;
    cout << "       |                                                                                                                         " << endl;
    cout << " 60000_|                                                                                                                         " << endl;
    cout << "       |                                                                                                                         " << endl;
    cout << " 50000_|                                                                                                                         " << endl;
    cout << "       |                                                                                                                         " << endl;
    cout << " 40000_|                                                                                                                         " << endl;
    cout << "       |                                                                                                                         " << endl;
    cout << " 30000_|                                                                                                                         " << endl;
    cout << "       |                                                                                                                         " << endl;
    cout << " 20000_|                                                                                                                         " << endl;
    cout << "       |                                                                                                                         " << endl;
    cout << " 10000_|                                                                                                                         " << endl;
    cout << "       |                                                                                                                         " << endl;
    cout << "     0-|                                                                                                                         " << endl;
    cout << "       __________________________________________________________________________________________________________________________" << endl;
    cout << "                '          '          '          '          '          '          '          '          '          '           ' " << endl;
    
    double x = 9,y = 25;
    double range = 0;
    for (int i = 0; i < 12; i++)
    {   
        range = 24 - (month[i]/5000);
        if (month[i] >= month[i+1])
        {
            while (y >= range + 1)
            {
                setCoord(x,y);
                cout << "*";
                x += 1.0;
                y = y - (range/10);
            }
            setCoord(x,y-2);
            cout << "("<< month[i] << " , " << i+1 << ")";
            
        }
        if (month[i] < month[i+1])
        {
            while (y <= range - 1)
            {
                setCoord(x,y);
                cout << "*";
                x += 1.0;
                y = y + (range/10);
            }
        
            setCoord(x,y+2);
            cout << "(" << month[i] << " , " << i+1 << ")";
        }
    }
    setCoord(0,28);        // bring cursor back to normal position
}
            
void assigning(string arr[][50], int size, int lenght, string value)
{                                                                     // initialiaze 2D array
    for (int i = 0; i < lenght; i++)
    {
        for (int j = 0; j < size; j++)
        {
            arr[i][j] = value;
        }
    }
}

bool searchUser(string user, int size, int index)
{                                                         // check that same username exist or not
    for (int i = 0; i < size; i++)
    {
        if (user == username[i] && i != index)
        {
            cout << endl << endl; 
            cout << "            ----------------------------------------USERNAME ALREADY EXIST IN SYSTEM!--------------------------------------------" << endl;
            return true;
        }
    }
    return false;
}

bool loadProducts(string (&grocery)[psize], int (&cost)[psize], int (&sale)[psize], int (&stock)[psize], int size)
{
    ifstream fin("loadProduct.csv");
    string token;
    string check;
    int count = 0;
    fin >> day;
    fin.ignore();
    fin >> month;
    fin.ignore();
    fin >> year;
    fin.ignore();
    getline(fin,check);
    getline(fin,check);
    while (token != "Snacks" && !fin.eof())
    {
        getline(fin, token);
        if (token != "Snacks" && !token.empty())
        {
            tokenizer(token,grocery,cost,sale,stock,count);
            count = count + 1;
        }
    }
    count = 0;
    while (token != "Other Product" && !fin.eof())
    {
        getline(fin, token);
        if (token != "Other Product" && !token.empty())
        {
            tokenizer(token,snacks,ScostPrice,Sprice,Sstock,count);
            count = count + 1;
        }
    }
    count = 0;
    while (!fin.eof() && token != "Discounts")
    {
        getline(fin, token);
        if (token != "Discounts" && !token.empty())
        {
            tokenizer(token,product,OcostPrice,Oprice,Ostock,count);
            count = count + 1;
        }
    }
    count = 0;
    while (!fin.eof())
    {
        fin >> discountCoupons[count];
        fin.ignore();
        fin >> discountPercentage[count];
        fin.ignore();
        fin >> maxDiscount[count];
        fin.ignore();
        count = count + 1;
    }
    fin.close();
}

bool saveProducts(string (&grocery)[psize], int (&cost)[psize], int (&sale)[psize], int (&stock)[psize], int size)
{
    ofstream fout("loadProduct.csv");
    fout << day << "-" << month << "-" << year << endl;
    fout << "Product Name,Cost Price,Sale Price,Stock" << endl;
    fout << "Grocery" << endl;
    for (int i = 0; i < size; i++)
    {
        if (grocery[i] != "N/A")
        {
            fout << grocery[i] << "," << cost[i] << "," << sale[i] << "," << stock[i] << endl;
        }
    }
    fout << "Snacks" << endl;
    for (int i = 0; i < size; i++)
    {
        if (snacks[i] != "N/A")
        {
            fout << snacks[i] << "," << ScostPrice[i] << "," << Sprice[i] << "," << Sstock[i] << endl;
        }
    }
    fout << "Other Product" << endl;
    for (int i = 0; i < size; i++)
    {
        if (product[i] != "N/A")
        {
            fout << product[i] << "," << OcostPrice[i] << "," << Oprice[i] << "," << Ostock[i] << endl;
        }
    }
    fout << "Discounts" << endl;
    for (int i = 0; i < 15; i++)
    {
        if (discountCoupons[i] != 0 && discountPercentage != 0)
        {
            fout << discountCoupons[i] << "," << discountPercentage[i] << "," << maxDiscount[i] << endl;
        }
    }
    fout.close();
}

void loadUser(string (&username)[psize],string (&passkey)[psize],string (&bank)[psize],double (&balance)[psize],double (&usedBalance)[psize])
{
    ifstream fin("load_User.csv");
    int count = 0;
    string check;
    getline(fin,check);
    while(!fin.eof())
    {
        getline(fin,username[count],',');
        getline(fin,passkey[count],',');
        getline(fin,bank[count],',');
        fin >> balance[count];
        fin.get();
        fin >> usedBalance[count];
        fin.ignore();
        getline (fin,employee[count],',');
        fin >> salary[count];
        fin.ignore();
        count += 1;
    }
    fin.close();
}

void saveUser(string (&username)[psize],string (&passkey)[psize],string (&bank)[psize],double (&balance)[psize],double (&usedBalance)[psize],int size)
{
    ofstream fout("load_User.csv");
    fout << "Username,Password,Account No.,Balance,Employee Name,Salary" << endl;
    for (int i = 0; i < size; i++)
    {
        if ((username[i] != "N/A" && username[i] != "") || employee[i] != "N/A")
        {
            fout << username[i] << "," << passkey[i] << "," << bank[i] << "," << balance[i] << "," << usedBalance[i];
            fout << "," << employee[i] << "," << salary[i] << endl;
        }
    }
    fout.close();
}

void loadCart(string (&cart)[psize][50],int (&quantity)[psize][50],int (&price)[psize][50])
{
    ifstream fin("Load_Cart.csv");
    int index;
    int count = 0;
    string check;
    getline(fin,check);
    while (!fin.eof())
    {
        fin >> index;
        fin.ignore();
        getline(fin,cart[index][count],',');
        fin >> quantity[index][count];
        fin.ignore();
        fin >> price[index][count];
        fin.ignore();
        count += 1; 
    }
    fin.close();
}

void saveCart(string (&cart)[psize][50],int (&quantity)[psize][50],int (&price)[psize][50],int size)
{
    ofstream fout("Load_Cart.csv");
    fout << "Product,Quantity,Price" << endl;
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < 50; j++)
        {
            if (cart[i][j] != "N/A")
            {
                fout << i << "," << cart[i][j] << "," << quantity[i][j] << "," << price[i][j] << endl;
            }
            
        }
        
    }
    fout.close();
}

void loadSales(int (&sale)[31],double (&saleOfMonth)[12],double (&totalOfMonth)[12])
{
    ifstream fin("Sales.csv");
    int day ;
    string check;
    getline(fin,check);
    while (!fin.eof())
    {
        fin >> day;
        fin.ignore();
        fin >> sale[day];
        fin.ignore(); 
        if (day < 12)
        {
            fin >> totalOfMonth[day];
            fin.ignore();
            fin >> saleOfMonth[day];
            fin.ignore();
        }
        
    }
    fin.close();
}

void saveSales(int (&sale)[31],double (&saleOfMonth)[12],double (&totalOfMonth)[12])
{
    ofstream fout("Sales.csv");
    fout << "Day,Sales,Monthly Total,Montly Sales" << endl;
    for (int i = 0; i < 31; i++)
    {
        
        fout << i << "," << sale[i] << ",";
        if (i < 12)
        {
            fout << totalOfMonth[i] << "," << saleOfMonth[i];
        }
        fout << endl;
    }
    fout.close();
}

void tokenizer(string token,string (&product)[psize], int (&cost)[psize], int (&sale)[psize], int (&stock)[psize],int index)
{
    string word[4];
    int arrIndex;
    for (int i = 0; i < token.length(); i++)
    {
        if (token[i] == ',')
        {
            arrIndex = arrIndex + 1;
        }
        else
            word[arrIndex] = word[arrIndex] + token[i];
    }

    product[index] = word[0];
    cost[index] = stringToInt(word[1]);
    sale[index] = stringToInt(word[2]);
    stock[index] = stringToInt(word[3]);
}

int stringToInt(string word)
{
    int res = 0;
    for (int i = 0; i < word.length(); i++)
    {
        res *= 10;
        res += int(word[i]-48);
    }
    return res;
}

void upper(string& name)
{
    int size = name.length();
    for (int i = 0; i < size; i++)
    {
        name[i] = toupper(name[i]);
    }
    return;  
}

string hidePassword()
{
    string passkey;
    char ch;    
    while (true) {
        ch = getch();
        if (ch == '\r')
        {
            break;
        } 
        else if (ch == '\b') 
        { 
            if (!passkey.empty()) 
            {
                passkey.pop_back(); 
                cout << "\b \b";   
            }
        } 
        else 
        {
            passkey.push_back(ch); 
            cout << '*';
        }
    }
    return passkey;
}