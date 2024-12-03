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
int const cartSize = 50;               // Total No Of Products can be added in customer cart
int const dsize = 15;                  // Total No of Discounts Can be added
int const Esize = 20;

struct user
{
    string username;                   // For username & passwords 
    string password;
    string bank;                       // Bank account of user
    double balance;                    // balance added in card
    double usedBalance;                // total balance used
};

struct discount
{
    double discountCoupons;           
    double discountPercentage;         // discount criteria
    double maxDiscount;
};

struct product
{
    string product;
    double cost;
    double sale;
    int quantity;
};

struct cart
{
    string cart[cartSize];              // product in customer cart
    int quantity[cartSize];         // quatity & price of product
    int price[cartSize];
};

struct employee
{
    string employee;              // for employees name
    double salary;                // their salaries
};

struct sales
{
    double totalOfMonth[12];
    double saleOfMonth[12];
    int sale[31];                        // store day wise sales
};

bool validation(int input);                                                                     // check input validation
void inputDate(string date);                                                                    // input date from user
string hidePassword();

void logIn(string x, string name, string y, string key);                                        //for admin and employee log in
void signUp(user customer[], int size);           // sign up as user
void signIn(string x, string y, user customer[]);                                               // sign in 

double sort(discount rebate[], int size);                                                       // sort discount list to apply right discount

void initialize(string arr[], int size, string value);                                          // initialize string array
void initializeProduct(product arr[], int size, string value);                                          // initialize string array
void initializeUser(user arr[], int size, string value);                                        // initialize string array
void initializeCart(cart item[], int size, int lenght, string value);                           // intialize 2D array
void initializeDouble(double arr[], int size, double value); 
void initializeDiscount(discount arr[], int size, double value);                                    // double arr
void initializeEmployee(employee arr[], int size, string value);


double addProduct(product item[], int size);             // take products from admin
void addEmployee(employee detail[], int size);                                     // admin add employees 
void addCart(cart item[], product grocery[], product snacks[], product other[], int size);          // add products in user cart

void displayList(product item[], int size);              // display list of products
void discountList(discount rebate[], int size);                            // display list of discounts
void customerList(user customer[], int size);                 // display list of customers
void employeeList(employee detail[], int size);                                    // display list of employees
void cartList(cart item[], int size);              // display list of products in cart
void displayListToCustomer(product item[], int size);                // display list of products to customer

void generateBill(cart item[], product grocery[], product snacks[], product other[], user customer[], discount rebate[], sales income, int size);         // generate Bill of items in cart

bool productEdit(product item[], string edit, sales income, int size); // Admin edits products added 

bool searchProduct(product item[], string search, int size);                // search of product
bool searchCustomer(user customer[], string search, int size);       // search of customers

bool productDelete(product item[],sales income, string edit, int size);   //     *********************************
bool discountDelete(discount rebate[], double del, int size);                                          //
bool employeeDelete(employee detail[], string del, int size);                                          //      DELETE RESPECTIVE NAME ELEMENTS
bool customerDelete(user customer[], string del, int size);            //
bool cartDelete(cart item[], product grocery[], product snacks[], product other[], string del, int size);                       //     **********************************                             

void compareSales(int sale[]);                                                                         // Graphically compare sales on daily basis      
double totalSales(int sale[]);                                                                         // Total sales of Month

double applyDiscount(int bill, discount rebate[], int size);   // suitable Discounts on Purchase
void removeStock(cart item[], product grocery[], product snacks[], product other[], int find[][2], int index, int size);     // Remove  Purchased quantity from product stock
void plusStock(cart item[], product grocery[], product snacks[], product other[], int find[][2], int index, int size);                                            // Add quantity back in stock which is deleted from cart 
void rechargeCard(user customer[], int size);                            // recharge balance in store card

void validateDate(string date,sales income);                                                                        //validate and store date month
bool productValidation(int sale,int cost,int quantity);                                                //validate Product cost , sale, stock
bool stringValidation(string input);                                               
double profitLoss(double purchase, double sales);                                                      // Profit and Loss Percentsge Calculation
void graph(double month[]);                                                                            // Graphically shows sales of month
void setCoord(int x, int y);                                                                           // Set coordinates of graph

bool searchUser(string name, user customer[], int size, int index);                                    // check that same username exist or not
void upper(string& name);
// *****************************************************************************************************************************************************

void tokenizer(string token,product item[],int index);
bool loadProducts(product grocery[], product snacks[], product other[], discount rebate[], int size);
bool saveProducts(product grocery[], product snacks[], product other[], discount rebate[], int size);
void loadUser(user customer[], employee detail[]);
void saveUser(user customer[], employee detail[], int size);
void loadCart(cart item[]);
void saveCart(cart item[],int size);
void loadSales(sales income);
void saveSales(sales income);
int stringToInt(string word);

// *****************************************************************************************************************************************************
//                                 Functions to load and Store Data in files


int userSearchIndex = 0;               // Searches user in user name array
int index = 0;                         // Searches Product & its stock                 

bool flag1[psize];                     // Check for whether element exist or not

int productFind[cartSize][2];        // store product index and its existence in array

double total = 0;                    // total for bill


string date = "01-01-2024";
int day = 0;
int month = 0;
int year = 2024;

int main()
{
    product grocery[psize];         // Name, cost price, sale price, & stock
    product snacks[psize];
    product other[psize];

    cart item[psize];

    user customer[psize];

    discount rebate[dsize];

    employee detail[psize];

    sales income;

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



    initializeCart(item, cartSize,psize,"N/A");        //
    initializeUser(customer,psize,"N/A");              //
    initializeProduct(grocery,psize,"N/A");            //
    initializeProduct(snacks,psize,"N/A");             //
    initializeProduct(other,psize,"N/A");              //              intialization of array
    initializeDiscount(rebate,dsize,0);                //
    initializeEmployee(detail,psize,"N/A");            //
    initialize(queries,5,"N/A");                       //

    
    loadProducts(grocery,snacks,other,rebate,psize);
    loadUser(customer,detail);
    loadCart(item);
    loadSales(income);

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
            logIn(user,"Admin",key,"1234");
            
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
                            income.totalOfMonth[month] += addProduct(grocery,psize);  //
                        }

                        else if (Pchoice == 2)
                        {
                            income.totalOfMonth[month] += addProduct(snacks,psize);   //      Total Add in month
                        }

                        else if (Pchoice == 3)
                        {
                            income.totalOfMonth[month] += addProduct(other,psize);  //
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
                        editFlag = productEdit(grocery, edit, income, psize);             // if product is not find in 1 array then it goes to next
                    }

                    if (editFlag == false)
                    {
                        editFlag = productEdit(snacks, edit, income, psize);
                    }

                    if (editFlag == false)
                    {
                        editFlag = productEdit(other, edit, income, psize);
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
                        editFlag = productDelete(grocery, income, edit, psize);
                    }

                    if (editFlag == false)
                    {
                        editFlag = productDelete(snacks, income, edit, psize);
                    }

                    if (editFlag == false)
                    {
                        editFlag = productDelete(other, income, edit, psize);
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
                    displayList(grocery,psize);
                    cout << "                                                                 Snacks                                                               \n";
                    cout << endl;
                    displayList(snacks,psize);
                    cout << "                                                             Other Products                                                           \n";
                    cout << endl;
                    displayList(other,psize);
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
                    upper(edit);

                    if (editFlag == false)
                    {
                        editFlag = searchProduct(grocery, edit, psize);
                    }

                    if (editFlag == false)
                    {
                        editFlag = searchProduct(snacks, edit, psize);
                    }

                    if (editFlag == false)
                    {
                        editFlag = searchProduct(other, edit, psize);
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
                            if(rebate[i].discountCoupons == 0)
                            {
                                do
                                {
                                    cout << "                            Enter Min Limit for Discount     : ";
                                    cin >> rebate[i].discountCoupons;
                                    cout << "                            Enter Discount Percentage        : ";
                                    cin >> rebate[i].discountPercentage;
                                    cout << "                            Enter Maximum Discount on Coupon : ";
                                    cin >> rebate[i].maxDiscount;
                                } 
                                while (productValidation(rebate[i].discountCoupons,rebate[i].discountPercentage,rebate[i].maxDiscount));

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
                        sort(rebate,dsize);
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
                    cout <<  "         " << setw(30) << "Sr.no" << setw(30) << "Coupon Name" << setw(30) << "Discount Percentage" << "Maximum Discount" <<endl;
                    cout << endl;
                    discountList(rebate,dsize);
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

                    discountDelete(rebate,del,dsize);
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
                        addEmployee(detail, psize);
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

                    employeeList(detail, psize);
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

                    employeeDelete(detail,edit,psize);
                    getch();
                }

                else if (input == 12)
                {
                    income.saleOfMonth[month] = totalSales(income.sale);  // calculate total sales of month
                    graph(income.saleOfMonth);                            // graphically shows sale on monthly basis
                    compareSales(income.sale);                            // graphically shows sale on daily basis
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
                    income.saleOfMonth[month] = totalSales(income.sale);
                    cout << "         T O T A L   P U R C H A S E   :    " << income.totalOfMonth[month] << endl << endl;
                    cout << "         T O T A L   S A L E S         :    " << income.saleOfMonth[month] << endl << endl;

                    if ( income.totalOfMonth[month] > 0)  // shows profit or loss
                    {
                        profitPercentage = profitLoss(income.totalOfMonth[month],income.saleOfMonth[month]);
                        if (profitPercentage > 0)
                        {
                            cout << "         P R O F I T   O F   M O N T H        :    " << income.saleOfMonth[month] - income.totalOfMonth[month] << endl << endl;
                            cout << "         P R O F I T   P E R C E N T A G E    :    " << profitPercentage << " % " << endl;
                        }
                        else
                        {
                            cout << "         L O S S   O F   M O N T H            :    " << income.totalOfMonth[month] - income.saleOfMonth[month] << endl << endl;
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
    
        else if (choice == 2)  // log in as employee
        {
            logIn(user,"Employee",key,"1234");

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
                    displayList(grocery,psize);
                    cout << "                                                                 Snacks                                                               \n";
                    cout << endl;
                    displayList(snacks,psize);
                    cout << "                                                             Other Products                                                           \n";
                    cout << endl;
                    displayList(other,psize);
                    getch();
                }
                
                else if (input == 2)
                {
                    system("cls");
                    cout << "***************************************************************************************************************************" << endl;
                    cout << "         " << setw(30) << "Sr.no" << setw(30) <<"Customer Name" << setw(30) <<"Account No." << setw(30) <<"Balance" <<endl;
                    cout << "***************************************************************************************************************************" << endl <<endl;
                    
                    customerList(customer,psize);
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
                        editFlag = searchCustomer(customer, edit, psize);
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
                        editFlag = customerDelete(customer, edit, psize);
                    }
                    if (editFlag == false)
                    {
                        cout <<endl << endl;
                        cout << "    ----------------------------------Unable to Find Customer----------------------------------- " << endl;
                        cout << "    ----------------------------------Does not Exist in System---------------------------------- " << endl;
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

                    upper(edit);

                    if (editFlag == false)
                    {
                        editFlag = searchProduct(grocery, edit, psize);
                    }

                    if (editFlag == false)
                    {
                        editFlag = searchProduct(snacks, edit, psize);
                    }

                    if (editFlag == false)
                    {
                        editFlag = searchProduct(other, edit, psize);
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
                    compareSales(income.sale);
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
                    cout << "                                   Date :    " << day << "-" << month << "-" << year << endl << endl;
                    cout << " Enter Date in Format (DD-MM-YYYY)  :  ";
                    do
                    {
                        getline(cin,date);
                    } 
                    while (stringValidation(date));
                    
                    validateDate(date,income);
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
        
        else if (choice == 3)  // log in as customer
        {

            signIn(user,key,customer);
            
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
                        displayListToCustomer(grocery,psize);
                        cout << "                                                    Snacks                                                               \n";
                        cout << endl;
                        displayListToCustomer(snacks,psize);
                        cout << "                                                Other Products                                                           \n";
                        cout << endl;
                        displayListToCustomer(other,psize);
                        cout << endl << endl;

                        addCart(item, grocery, snacks, other, psize);

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
                    cartList(item,psize);
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

                    editFlag = cartDelete(item, grocery, snacks, other, edit, psize);
                    getch();
                }

                else if (input == 4)
                {
                    system("cls");
                    cout << "***************************************************************************************************************************" << endl;
                    cout << "         " << setw(20) << "Sr.no" << setw(30) <<"Product" << setw(30) <<"Price" << setw(30) <<"Stock" <<endl;
                    cout << "***************************************************************************************************************************" << endl <<endl;
                    cout << "                                                Grocery Items                                                            \n";
                    cout << endl;
                    displayListToCustomer(grocery,psize);
                    cout << "                                                    Snacks                                                               \n";
                    cout << endl;
                    displayListToCustomer(snacks,psize);
                    cout << "                                                Other Products                                                           \n";
                    cout << endl;
                    displayListToCustomer(other,psize);
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
                    cout << "               U S E R N A M E                       :       " << customer[userSearchIndex].username;
                    cout << endl << endl;
                    cout << "               B A N K  A C C O U N T   N O          :       " << customer[userSearchIndex].bank;
                    cout << endl << endl;
                    cout << "               S T O R E   C A R D   B A L A N C E   : Rs.   " << customer[userSearchIndex].balance;
                    cout << endl << endl;
                    cout << "               T O T A L   B A L A N C E   U S E D   : Rs.   " << customer[userSearchIndex].usedBalance;
                    getch();
                }

                else if (input == 6)
                {
                    system("cls");
                    cout << "***************************************************************************************************************************" << endl;
                    cout << "                                                   RECHARGE STORE CARD                                                   \n";
                    cout << "***************************************************************************************************************************" << endl;
                    cout << endl;
                    rechargeCard(customer,psize);
                }
                
                else if (input == 7)
                {
                    system("cls");
                    cout << "***************************************************************************************************************************" << endl;
                    cout << "                                             Products in Your Cart                                                       \n";
                    cout << "***************************************************************************************************************************" << endl;
                    generateBill(item,grocery,snacks,other,customer,rebate,income,cartSize);
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

        else if (choice == 4)  // sign up as customer
        {
            signUp(customer, psize);
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
    
    saveProducts(grocery,snacks,other,rebate,psize);
    saveUser(customer,detail,psize);
    saveCart(item,psize);
    saveSales(income);
    return 0;
}

void logIn(string x, string name, string y, string key)
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
        }
    }
}

void signUp(user customer[], int size)
{
    string confirm;
    for (int i = 0; i < size; i++)  
    {
        int index = 0;
        if (customer[i].username == "N/A" || customer[i].username == "")  // checks whether there is space in system or not
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
                getline(cin, customer[i].username);
                cout << setw(35);
                cout << endl <<"               P A S S W O R D                       :       ";
                customer[i].password = hidePassword();
                cout << setw(35);
                cout << endl <<"               C O N F I R M   P A S S W O R D       :       ";
                confirm = hidePassword();

                while (customer[i].password != confirm)
                {
                    cout << "  ------------------------------------------Invalid Confirm Password-----------------------------------------" << endl;
                    cout << "  -------------------------------------------------Try Again-------------------------------------------------" << endl;
                    cout << setw(35);
                    cout << "               C O N F I R M   P A S S W O R D :";
                    confirm = hidePassword();
                }

                cout << setw(35) << endl;
                cout << endl <<"               B A N K  A C C O U N T   N O          :       ";
                getline(cin, customer[i].bank);
                cout << setw(35) << endl;
            }
            while(stringValidation(customer[i].bank) || stringValidation(confirm) || searchUser(customer[i].username,customer,size,i)
                  || stringValidation(customer[i].password) || stringValidation(customer[i].username));

            cout <<  endl <<"               B A L A N C E   T O   R E C H A R G E :    Rs. ";
            cin >> customer[i].balance;
            cin.ignore(256, '\n'); 
            

            cout << "  ------------------------------------------Signed In Successfully-----------------------------------------" << endl;
            return ;
        }
    }
    cout << "                          ------------------------------------------Space is Full-----------------------------------------" << endl;
    cout << "                          -----------------------------------------Unable to Store----------------------------------------" << endl;
    
}

void signIn(string x, string y, user customer[])
{
    bool searchFlag;
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
            if (customer[i].username == x && customer[i].password == y)
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
            cin.get();
        }
    }while (searchFlag);
}

void initialize(string arr[], int size, string value) 
{
    for (int i = 0; i < size; i++) 
    {
        arr[i] = value;
    }
}

void initializeProduct(product arr[], int size, string value) 
{
    for (int i = 0; i < size; i++) 
    {
        arr[i].product = value;
    }
}

void initializeEmployee(employee arr[], int size, string value) 
{
    for (int i = 0; i < size; i++) 
    {
        arr[i].employee = value;
    }
}

void initializeUser(user arr[], int size, string value) 
{
    for (int i = 0; i < size; i++) 
    {
        arr[i].username = value;
        arr[i].password = value;
    }
}

void initializeDouble(double arr[], int size, double value) 
{
    for (int i = 0; i < size; i++) 
    {
        arr[i] = value;
    }
}

void initializeDiscount(discount arr[], int size, double value) 
{
    for (int i = 0; i < size; i++) 
    {
        arr[i].discountCoupons = value;
        arr[i].discountPercentage = value;
        arr[i].maxDiscount = value; 
    }
}

void initializeInt(int arr[], int size, int value) 
{
    for (int i = 0; i < size; i++) {
        arr[i] = value;
    }
}
            
void initializeCart(cart item[], int size, int lenght, string value)
{                                                                     // initialiaze 2D array
    for (int i = 0; i < lenght; i++)
    {
        for (int j = 0; j < size; j++)
        {
            item[i].cart[j] = value;
            item[i].price[j] = 0;
            item[i].quantity[j] = 0;
        }
    }
}

double addProduct(product item[], int size)
{
    double total = 0;
    for (int i = 0; i < psize; i++)
    {
        flag1[1] = true;     // used to find whether item is stored or not
        if (item[i].product == "N/A")
        {
            do
            {
                cout << endl  << "                Enter Product            : ";
                getline(cin,item[i].product);
                upper(item[i].product);
                cout << endl  << "                Enter Cost Price         : ";
                cin >> item[i].cost;
                cin.ignore(256,'\n');
                cout << endl  << "                Enter Sale Price         : ";
                cin >> item[i].sale;
                cin.ignore(256,'\n');
                cout << endl  << "                Enter Product Stock      : ";
                cin >> item[i].quantity;
                cin.ignore(256,'\n');
                cout << endl;
            } 
            while (productValidation(item[i].sale,item[i].cost,item[i].quantity) || stringValidation(item[i].product)); // check validation of input
            
            total += item[i].cost*item[i].quantity;
            flag1[1] = false;
            cout << endl << endl;
            cout << endl << "  ---------------------------------------Product Stored Successfully---------------------------------------      " << endl;
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

void addEmployee(employee detail[], int size)
{
    for (int i = 0; i < size; i++)
    {
        flag1[1] = true;
        if (detail[i].employee == "N/A")
        {
            do
            {
                cout << "                Enter Employee Name : ";
                getline(cin,detail[i].employee);
                cout << "                Enter Salary        : ";
                cin >> detail[i].salary;
                cin.ignore(256,'\n');
         
            }
            while(stringValidation(detail[i].employee) || validation(detail[i].salary));
            
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

void addCart(cart item[], product grocery[], product snacks[], product other[], int size)
{
    
    string add;
    int quantity;
    for (int i = 0; i < size; i++)
    {
        bool searchFlag = false;
        flag1[1] = true;
        if (item[userSearchIndex].cart[i] == "N/A")
        {
            do
            {
                cout << endl << "                Enter Product : ";
                getline(cin,add);
                cout << endl << "                Enter Quantity : ";
                cin >> quantity;
                cin.ignore(100,'\n');
            } 
            while (stringValidation(add) || validation(quantity));
            upper(add);

            if (searchFlag == false)
            {
                searchFlag = searchProduct(grocery, add, psize);
                if (searchFlag == true)
                {
                    if (quantity <= grocery[index].quantity)
                    {
                        item[userSearchIndex].cart[i] = add;
                        item[userSearchIndex].quantity[i] = quantity;
                        item[userSearchIndex].price[i] = grocery[index].sale;
                        productFind[i][0] = 1;
                        productFind[i][1] = index;
                        removeStock(item,grocery,snacks,other,productFind,i,size);
                    }
                    else if (quantity > grocery[index].quantity)
                    {                        
                        cout <<endl << endl;
                        cout << "    -------------------------------------Unable to Store------------------------------------- " ;
                        cout <<endl << endl;
                    }
                }
            }

            if (searchFlag == false)
            {
                searchFlag = searchProduct(snacks, add, psize);
                if (searchFlag == true)
                {
                    if (quantity <= snacks[index].quantity)
                    {                        
                        item[userSearchIndex].cart[i] = add;
                        item[userSearchIndex].quantity[i] = quantity;
                        item[userSearchIndex].price[i] = snacks[index].sale;
                        productFind[i][0] = 2;
                        productFind[i][1] = index;
                        removeStock(item,grocery,snacks,other,productFind,i,size);
                    }
                    else if (quantity > snacks[index].quantity)
                    {                        
                        cout <<endl << endl;
                        cout << "    -------------------------------------Unable to Store------------------------------------- " ;
                        cout <<endl << endl;
                        break;
                    }
                }
            }

            if (searchFlag == false)
            {
                searchFlag = searchProduct(other, add, psize);
                if (searchFlag == true)
                {
                    if (quantity <= other[index].quantity)
                    {
                        item[userSearchIndex].cart[i] = add;
                        item[userSearchIndex].quantity[i] = quantity;
                        item[userSearchIndex].price[i] = other[index].sale;
                        productFind[i][0] = 3;
                        productFind[i][1] = index;
                        removeStock(item,grocery,snacks,other,productFind,i,size);
                    }
                    else if (quantity > other[index].quantity)
                    {                        
                        cout <<endl << endl;
                        cout << "    -------------------------------------Unable to Store------------------------------------- " ;
                        cout <<endl << endl;
                        break;
                    }
                }
            }
            cout << endl << endl;
            cin.ignore(256,'\n');
            
            if (searchFlag == false)
            {
                cout <<endl << endl;
                cout << "    ---------------------------------------Unable to Find Product--------------------------------------- " ;
                cout <<endl << endl;
                break;
            }

            flag1[1] = false;
            cout << endl << "                                   Product Stored Successfully      " << endl;
            break;
        }
    }
}

void displayList(product item[], int size)
{
    cout <<left;
    flag1[4] = true;
    for (int i = 0; i < size; i++)
    {
        if (item[i].product != "N/A")
        {
            cout << "         " << setw(20) << i+1 << setw(30) << item[i].product << "Rs." << setw(30) << item[i].sale;
            cout << "Rs." << setw(30) << item[i].cost << setw(4) << item[i].quantity << "Pcs" <<endl;
            flag1[4] = false;
        }
    }
    if (flag1[4] != false)
    {
        cout << endl << endl;
    }
}

void displayListToCustomer(product item[], int size)
{
    cout <<left;
    flag1[4] = true;
    for (int i = 0; i < size; i++)
    {
        if (item[i].product != "N/A")
        {
            cout << "         " << setw(20) << i+1 << setw(30) << item[i].product << "Rs." << setw(30) << item[i].sale;
            cout << setw(30) << item[i].quantity <<endl;
            flag1[4] = false;
        }
    }
    if (!flag1[4])
    {
        cout << endl << endl;
    }
}

void discountList(discount rebate[], int size)
{
    cout <<left;
    bool disFlag = true;
    for (int i = 0; i < size; i++)
    {
        if (rebate[i].discountCoupons != 0)
        {
            cout << "         " << setw(30) << i+1 << "Rs. " << setw(30) << rebate[i].discountCoupons << rebate[i].discountPercentage << setw(30) << "%" ;
            cout << "Rs. " << rebate[i].maxDiscount <<endl;
            disFlag = false;
        }
    }
    if (disFlag == true)
    {
        cout << endl << endl;
    }
}

void cartList(cart item[], int size)
{
    cout <<left;
    bool cartFlag = true;
    for (int i = 0; i < size; i++)
    {
        if (item[userSearchIndex].cart[i] != "N/A")             // UserSearchIndex is global variable and assign its value customer sign in
        {
            cout << "         " << setw(20) << i+1 << setw(30) << item[userSearchIndex].cart[i];
            cout << setw(30)  << item[userSearchIndex].quantity[i];
            cout << "  Rs." << setw(30) << item[userSearchIndex].price[i] <<endl;
            cartFlag = false;
        }
    }
    if (!cartFlag)
    {
        cout << endl << endl;
    }
}

bool productEdit(product item[], string edit, sales income, int size)
{
    
    for (int i = 0; i < size; i++)
    {
        if (item[i].product == edit)
        {
            income.totalOfMonth[month] -= (item[i].cost)*(item[i].quantity);
            
            cout << endl << endl;
            cout << "          " << setw(30) <<"Product" << setw(30) <<"Price" << setw(30) <<"  Stock" <<endl;
            cout << "***************************************************************************************************************************" << endl <<endl;
            cout << "          " << setw(30) << item[i].product << "Rs." << setw(30) << item[i].cost << setw(30) << item[i].quantity <<endl << endl;
            do
            {
                cout << "                Enter Product            : ";
                getline(cin,item[i].product);
                upper(item[i].product);
                cout << "                Enter Cost Price         : ";
                cin >> item[i].cost;
                cin.ignore(256,'\n');
                cout << "                Enter Sale Price         : ";
                cin >> item[i].sale;
                cin.ignore(256,'\n');
                cout << "                Enter Product Stock      : ";
                cin >> item[i].quantity;
                cin.ignore(256,'\n');
                income.totalOfMonth[month] += (item[i].cost)*(item[i].quantity);
            } 
            while (productValidation(item[i].sale,item[i].cost,item[i].cost) || stringValidation(item[i].product));
            return true;
        }
    }
    return false;
}

bool searchProduct(product item[], string search, int size)
{
    
    for (int i = 0; i < size; i++)
    {
        if (item[i].product == search)
        {
            cout << endl << endl;
            
            cout << "          " << setw(30) <<"Product" << setw(30) <<"Price" << setw(30) <<"     Stock" <<endl;
            cout << "***************************************************************************************************************************" << endl <<endl;
            cout << "          " << setw(30) << item[i].product << "Rs." << setw(30) << item[i].sale;
            cout << setw(5) << item[i].quantity << "Pcs." <<endl << endl;
            index = i;
            return true;
        }
    }
    return false;
}

bool searchCustomer(user customer[], string search, int size)
{
    
    for (int i = 0; i < size; i++)
    {
        if (customer[i].username == search)
        {
            cout << endl << endl;
            
            cout << "          " << setw(30) <<"Customer Name" << setw(30) <<"Account No." << setw(30) <<"Balance" <<endl;
            cout << "***************************************************************************************************************************" << endl <<endl;
            cout << "          " << setw(30) << customer[i].username << setw(30) << customer[i].bank << "Rs." << setw(30) << customer[i].balance <<endl << endl;
            index = i;
            getch();
            return true;
        }
    }
    return false;
}

bool productDelete(product item[],sales income, string edit, int size)
{
    int flag = 0;
    if (searchProduct(item, edit, size))
    {
        cout << endl << endl;
        cout << "Confirm Delete (1 for Yes / 0 for no) : ";
        cin >> flag;
        if (flag == 1)
        {
            item[userSearchIndex].product = "N/A" ;
            income.totalOfMonth[month] = income.totalOfMonth[month] - (item[userSearchIndex].quantity) * (item[userSearchIndex].cost); 
            cout << "            ----------------------------------Product Deleted Succesfully.----------------------------------" << endl;
            return true;
        }
    }
    return false;
}

bool discountDelete(discount rebate[], double del, int size)
{
    int flag = 0;
    for (int i = 0; i < size; i++)
    {
        if (rebate[i].discountCoupons == del)
        {
            cout << endl << endl;
            cout << "Confirm Delete (1 for Yes / 0 for no) : ";
            cin >> flag;
            if (flag == 1)
            {
                rebate[i].discountCoupons = 0 ;
                cout << "";
                getch();
                return true;
            }
        }
    }
    
    return false;
}

bool employeeDelete(employee details[], string del, int size)
{
    int flag = 0;
    for (int i = 0; i < size; i++)
    {
        if (details[i].employee == del)
        {
            cout << endl << endl;
            cout << "Confirm Delete (1 for Yes / 0 for no) : ";
            cin >> flag;
            if (flag == 1)
            {
                details[i].employee = "N/A" ;
                getch();
                return true;
            }
        }
    }
    
    return false;
}

void customerList(user customer[], int size)
{
    cout <<left;
    bool disFlag = true;
    for (int i = 0; i < size; i++)
    {
        if (customer[i].username != "N/A" && customer[i].username != "")
        {
            cout  << "         " << setw(30) << i+1 << setw(30) << customer[i].username << setw(30) << customer[i].bank << "Rs." << customer[i].balance <<endl;
            disFlag = false;
        }
    }
    if (disFlag == true)
    {
        cout << endl << endl;
    }
}

void employeeList(employee details[], int size)
{
    cout <<left;
    bool disFlag = true;
    for (int i = 0; i < size; i++)
    {
        if (details[i].employee != "N/A")
        {
            cout  << "         " << setw(20) << i+1 << setw(50) << details[i].employee << "Rs." << details[i].salary <<endl;
            disFlag = false;
        }
    }
    if (disFlag == true)
    {
        cout << endl << endl;
    }
}

bool customerDelete(user customer[], string del, int size)
{
    int flag = 0;
    if (searchCustomer(customer, del, size))
    {
        cout << endl << endl;
        cout << "Confirm Delete (1 for Yes / 0 for no) : ";
        cin >> flag;
        if (flag == 1)
        {
            customer[userSearchIndex].username = "N/A" ;
            cout << "            -------------------------------------Customer Data Deleted.-------------------------------------" << endl;
            return true;
        }
    }
    return false;
}

bool cartDelete(cart item[], product grocery[], product snacks[], product other[], string del, int size)
{
    int flag = 0;
    for (int i = 0; i < size; i++)
    {
        if (item[userSearchIndex].cart[i] == del)                                  // UserSearchIndex is global variable and assign its value customer sign in
        {
            cout << endl << endl;
            cout << "Confirm Delete (1 for Yes / 0 for no) : ";
            cin >> flag;
            if (flag == 1)
            {
                item[userSearchIndex].cart[i] = "N/A" ;
                plusStock(item,grocery,snacks,other,productFind,i,size);
                cout << "            -------------------------------------Product Deleted.-------------------------------------" << endl;
                return true;
            }
        }
        }
    
    return false;
}

void generateBill(cart item[], product grocery[], product snacks[], product other[], user customer[], discount rebate[],sales income, int size)       // generate Bill of items in cart
{
    int confirm;
    cout << endl;
    cout << "         " << setw(20) << "Sr.no" << setw(30) <<"Product" << setw(30) <<"Quantity" << setw(30) <<"  Price" <<endl;
    cartList(item, size);
    cout << endl << endl;
    cout << "               Confirm Purchase (1 for Yes / 0 for No)  :   ";
    cin >> confirm;
    if (confirm == 1)
    {
        system("cls");
        cout <<left;
        bool disFlag = true;
        double total = 0;
        int choice;
        cout << "***************************************************************************************************************************" << endl;
        cout << "                                                          Bill                                                           \n";
        cout << "***************************************************************************************************************************" << endl;        
        cout << endl;
        cout << "         " << setw(20) << "Sr.no" << setw(30) <<"Product" << setw(30) <<"Quantity" << setw(30) <<"Price" <<endl;            
        for (int i = 0; i < size; i++)
        {
            if (item[userSearchIndex].cart[i] != "N/A")
            {
                double temp = 0;
                temp = item[userSearchIndex].price[i]*item[userSearchIndex].quantity[i];

                cout << "         " << setw(20) << i+1 << setw(30) << item[userSearchIndex].cart[i];
                cout << setw(4) << item[userSearchIndex].quantity[i] << setw(26)  << " Pcs.";
                cout << "Rs. "<< setw(30) << temp <<endl;
                total = total + temp;
                flag1[4] = false;
            }
        }

        total = applyDiscount(total,rebate,dsize);

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
            if (total <= customer[userSearchIndex].balance)    // add sales on day wise and subtract balance from user card and add in its activity
            {
                income.sale[day] = income.sale[day] + total;
                customer[userSearchIndex].usedBalance += total;
                customer[userSearchIndex].balance -= total;
                initializeCart(item,50,psize,"N/A");
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
            income.sale[day] = income.sale[day] + total;
            customer[userSearchIndex].usedBalance += total;
            initializeCart(item,50,psize,"N/A");
            cout << endl << endl;
            cout << "            ----------------------------------------THANK YOU FOR YOUR PURCHASE----------------------------------------" << endl;
            getch();            
        }
        else
        {
            cout << "            --------------------------------------------INVALID INPUT!--------------------------------------------" << endl;
            getch();
        }
        income.saleOfMonth[month] += totalSales(income.sale); 
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
        cout << "  (Rs. " << sale[i] << ")" << endl << endl;
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

double sort(discount rebate[], int size)
{
    for (int i = 0; i < size - 1; i++)
    {
        for (int j = 0; j < size - i - 1; j++)
        {
            if (rebate[i].discountCoupons < rebate[i + 1].discountPercentage)           // sort discount criteria and percentage as they are parllel
            {
                swap(rebate[i].discountCoupons,rebate[i + 1].discountCoupons);
                swap(rebate[i].discountPercentage,rebate[i + 1].discountPercentage);
            }
            
        }
    }
}

double applyDiscount(int bill ,discount rebate[], int size)
{
    double discount = 0;
    for (int i = 0; i < size; i++)            // apply discount and shows its value
    {
        if (bill >=  rebate[i].discountCoupons)
        {
            discount = bill * (rebate[i].discountPercentage / 100);
            if (discount <= rebate[i].maxDiscount)
            {
                cout << endl << setw(60) << "" << setw(29) << "Discount :" << "Rs." <<  discount << endl;
                bill = bill - discount;
            }
            else
            {
                cout << endl << setw(60) << "" << setw(29) << "Discount :" << "Rs." << rebate[i].maxDiscount << endl;
                bill = bill - rebate[i].maxDiscount; 
            }
            
            return bill;
        }
    }
    return bill;
}

void removeStock(cart item[], product grocery[], product snacks[], product other[], int find[][2], int index, int size)
{                                           //remove quantity when added to cart
    if (find[index][0] == 1)
    {
        grocery[find[index][1]].quantity -=  item[userSearchIndex].quantity[index];
    }
    if (find[index][0] == 2)
    {
        snacks[find[index][1]].quantity -=  item[userSearchIndex].quantity[index];
    }
    if (find[index][0] == 3)
    {
        other[find[index][1]].quantity -=  item[userSearchIndex].quantity[index];
    }
    return ;
}

void plusStock(cart item[], product grocery[], product snacks[], product other[], int find[][2], int index, int size)
{
    if (find[index][0] == 1)
    {
        grocery[find[index][1]].quantity +=  item[userSearchIndex].quantity[index];
    }
    if (find[index][0] == 2)
    {
        snacks[find[index][1]].quantity +=  item[userSearchIndex].quantity[index];
    }
    if (find[index][0] == 3)
    {
        other[find[index][1]].quantity +=  item[userSearchIndex].quantity[index];
    }
    return ;   
}

void rechargeCard(user customer[], int size)
{
    string name,key,acountNo;
    double recharge;
    do{                                                                         // recharge balance when user enter right credentials 
        cout << left;
        cout << setw(35) << endl;
        cout << "               U S E R N A M E                       :       ";
        getline(cin, name);
        cout << setw(35);
        cout << "               P A S S W O R D                       :       ";
        getline(cin, key);
        cout << setw(35) << endl;
        cout << "               B A N K  A C C O U N T   N O          :       ";
        getline(cin, acountNo);
        cout << setw(35) << endl;
    }
    while (stringValidation(name) || stringValidation(key) || stringValidation(acountNo));

    cout << "               B A L A N C E   T O   R E C H A R G E :        Rs. ";
    cin >> recharge;
    if (name == customer[userSearchIndex].username
        && key == customer[userSearchIndex].password
        && acountNo == customer[userSearchIndex].bank)
    {
        customer[userSearchIndex].balance += recharge;
    }
    else
    {
        cout << "            --------------------------------------------INVALID CREDENTIALS!--------------------------------------------" << endl;
    }
}

void validateDate(string date,sales income)
{
    int lenght = date.length();
    if (date >= "01-01-2000" && date <= "31-12-3000"
        && date[2] == '-' && date[5] == '-'
        && lenght == 10)
    {
        if (month != stringToInt(date.substr(3,2)) - 1)
        {
            initializeInt(income.sale,31,0);
        }
        if (year != stringToInt(date.substr(6,4)))
        {
            initializeDouble(income.totalOfMonth,12,0);
            initializeDouble(income.saleOfMonth,12,0);
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
    cout << "100000_|                                                                                                                                        " << endl;
    cout << "       |                                                                                                                                        " << endl;
    cout << " 90000_|                                                                                                                                        " << endl;
    cout << "       |                                                                                                                                        " << endl;
    cout << " 80000_|                                                                                                                                        " << endl;
    cout << "       |                                                                                                                                        " << endl;
    cout << " 70000_|                                                                                                                                        " << endl;
    cout << "       |                                                                                                                                        " << endl;
    cout << " 60000_|                                                                                                                                        " << endl;
    cout << "       |                                                                                                                                        " << endl;
    cout << " 50000_|                                                                                                                                        " << endl;
    cout << "       |                                                                                                                                        " << endl;
    cout << " 40000_|                                                                                                                                        " << endl;
    cout << "       |                                                                                                                                        " << endl;
    cout << " 30000_|                                                                                                                                        " << endl;
    cout << "       |                                                                                                                                        " << endl;
    cout << " 20000_|                                                                                                                                        " << endl;
    cout << "       |                                                                                                                                        " << endl;
    cout << " 10000_|                                                                                                                                        " << endl;
    cout << "       |                                                                                                                                        " << endl;
    cout << "     0-|                                                                                                                                        " << endl;
    cout << "       _________________________________________________________________________________________________________________________________________" << endl;
    cout << "       '          '          '          '          '          '          '          '          '          '          '          '          '    " << endl;
    cout << "                 JAN        FEB        MAR        APR        MAY        JUNE       JULY       AUG        SEP        OCT        NOV        DEC   " << endl << endl;
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
    setCoord(0,32);        // bring cursor back to normal position
}

bool searchUser(string name,user customer[], int size, int index)
{                                                         // check that same username exist or not
    for (int i = 0; i < size; i++)
    {
        if (name == customer[i].username && i != index)
        {
            cout << endl << endl; 
            cout << "            ----------------------------------------USERNAME ALREADY EXIST IN SYSTEM!--------------------------------------------" << endl;
            return true;
        }
    }
    return false;
}

bool loadProducts(product grocery[],product snacks[],product other[], discount rebate[], int size)
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
            tokenizer(token,grocery,count);
            count = count + 1;
        }
    }
    count = 0;
    while (token != "Other Product" && !fin.eof())
    {
        getline(fin, token);
        if (token != "Other Product" && !token.empty())
        {
            tokenizer(token,snacks,count);
            count = count + 1;
        }
    }
    count = 0;
    while (!fin.eof() && token != "Discounts")
    {
        getline(fin, token);
        if (token != "Discounts" && !token.empty())
        {
            tokenizer(token,other,count);
            count = count + 1;
        }
    }
    count = 0;
    while (!fin.eof())
    {
        fin >> rebate[count].discountCoupons;
        fin.ignore();
        fin >> rebate[count].discountPercentage;
        fin.ignore();
        fin >> rebate[count].maxDiscount;
        fin.ignore();
        count = count + 1;
    }
    fin.close();
}

bool saveProducts(product grocery[],product snacks[],product other[], discount rebate[], int size)
{
    ofstream fout("loadProduct.csv");
    fout << day << "-" << month << "-" << year << endl;
    fout << "Product Name,Cost Price,Sale Price,Stock" << endl;
    fout << "Grocery" << endl;
    for (int i = 0; i < size; i++)
    {
        if (grocery[i].product != "N/A")
        {
            fout << grocery[i].product << "," << grocery[i].cost << "," << grocery[i].sale << "," << grocery[i].quantity << endl;
        }
    }
    fout << "Snacks" << endl;
    for (int i = 0; i < size; i++)
    {
        if (snacks[i].product != "N/A")
        {
            fout << snacks[i].product << "," << snacks[i].cost << "," << snacks[i].sale << "," << snacks[i].quantity << endl;
        }
    }
    fout << "Other Product" << endl;
    for (int i = 0; i < size; i++)
    {
        if (other[i].product != "N/A")
        {
            fout << other[i].product << "," << other[i].cost << "," << other[i].sale << "," << other[i].quantity << endl;
        }
    }
    fout << "Discounts" << endl;
    for (int i = 0; i < 15; i++)
    {
        if (rebate[i].discountCoupons != 0 && rebate[i].discountPercentage != 0)
        {
            fout << rebate[i].discountCoupons << "," << rebate[i].discountPercentage << "," << rebate[i].maxDiscount << endl;
        }
    }
    fout.close();
}

void loadUser(user customer[], employee detail[])
{
    ifstream fin("load_User.csv");
    int count = 0;
    string check;
    getline(fin,check);
    while(!fin.eof())
    {
        getline(fin,customer[count].username,',');
        getline(fin,customer[count].password,',');
        getline(fin,customer[count].bank,',');
        fin >> customer[count].balance;
        fin.get();
        fin >> customer[count].usedBalance;
        fin.ignore();
        getline (fin,detail[count].employee,',');
        fin >> detail[count].salary;
        fin.ignore();
        count += 1;
    }
    fin.close();
}

void saveUser(user customer[], employee detail[], int size)
{
    ofstream fout("load_User.csv");
    fout << "Username,Password,Account No.,Balance,Used Balance,Employee Name,Salary" << endl;
    for (int i = 0; i < size; i++)
    {
        if ((customer[i].username != "N/A" && customer[i].username != "") || detail[i].employee != "N/A")
        {
            fout << customer[i].username << "," << customer[i].password << "," << customer[i].bank << "," << customer[i].balance << "," << customer[i].usedBalance;
            fout << "," << detail[i].employee << "," << detail[i].salary << endl;
        }
    }
    fout.close();
}

void loadCart(cart item[])
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
        getline(fin,item[index].cart[count],',');
        fin >> item[index].quantity[count];
        fin.ignore();
        fin >> item[index].price[count];
        fin.ignore();
        count += 1; 
    }
    fin.close();
}

void saveCart(cart item[],int size)
{
    ofstream fout("Load_Cart.csv");
    fout << "Product,Quantity,Price" << endl;
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < 50; j++)
        {
            if (item[i].cart[j] != "N/A")
            {
                fout << i << "," << item[i].cart[j] << "," << item[i].quantity[j] << "," << item[i].price[j] << endl;
            }
            
        }
        
    }
    fout.close();
}

void loadSales(sales income)
{
    ifstream fin("Sales.csv");
    int day ;
    string check;
    getline(fin,check);
    while (!fin.eof())
    {
        fin >> day;
        fin.ignore();
        fin >> income.sale[day];
        fin.ignore(); 
        if (day < 12)
        {
            fin >> income.totalOfMonth[day];
            fin.ignore();
            fin >> income.saleOfMonth[day];
            fin.ignore();
        }
        
    }
    fin.close();
}

void saveSales(sales income)
{
    ofstream fout("Sales.csv");
    fout << "Day,Sales,Monthly Total,Montly Sales" << endl;
    for (int i = 0; i < 31; i++)
    {
        
        fout << i << "," << income.sale[i] << ",";
        if (i < 12)
        {
            fout << income.totalOfMonth[i] << "," << income.saleOfMonth[i];
        }
        fout << endl;
    }
    fout.close();
}

void tokenizer(string token,product item[],int index)
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

    item[index].product = word[0];
    item[index].cost = stringToInt(word[1]);
    item[index].sale = stringToInt(word[2]);
    item[index].quantity = stringToInt(word[3]);
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
        switch (name[i])
        {
        case '_':
            name[i] = ' ';
            break;
        
        case '-':
            name[i] = ' ';
            break;
        
        case ',':
            name[i] = ' ';
            break;
        
        case '.':
            name[i] = ' ';
            break;
        
        default:
            name[i] = toupper(name[i]);
            break;
        }
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