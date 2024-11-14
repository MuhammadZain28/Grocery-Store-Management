# include <iostream>
# include <iomanip>
# include <cstring>
# include <string>
# include <fstream>
# include <conio.h>

using namespace std;

void logIn(string x, string name, string y, string key);
void signUp(string name[], string pass[], string bank[], double balance[], int size);
void signIn(string x, string y);

void initialize(string arr[], int size, string value);
void initializeDouble(double arr[], int size, double value);

void addProduct(string arr1[], int arr2[], int arr3[], int size);
void addEmployee(string arr1[], double arr2[], int size);
void addCart(string arr1[], int arr2[][2], int size);

void displayList(string arr1[], int arr2[], int arr3[], int size);
void discountList(string arr1[], double arr2[], int size);
void customerList(string arr1[], string arr2[], double arr3[], int size);
void employeeList(string arr1[], double arr2[], int size);
void cartList(string arr1[], int arr2[][2], int size);

bool productEdit(string arr1[], int arr2[], int arr3[], string edit, int size);

bool searchProduct(string arr1[], int arr2[], int arr3[], string edit, int size);
bool searchCustomer(string arr1[], string arr2[], double arr3[], string edit, int size);

bool productDelete(string arr1[], int arr2[], int arr3[], string edit, int size);
bool discountDelete(string arr1[], string edit, int size);
bool customerDelete(string arr1[], int arr2[], int arr3[], string edit, int size);
bool cartDelete(string arr1[], int arr2[][2], string del, int size);


int const psize = 100;
int const cartSize = 500;

int index = 0;
int userSearchIndex = 0;

string username[psize];
string passkey[psize];

bool flag1[psize];
bool flag2[psize];

string snacks[psize];
string grocery[psize];
string product[psize]; // products other than above both

// S for snack ,G for grocery ,O for other products
int Sprice[psize];
int Sstock[psize];
int Gprice[psize];
int Gstock[psize];
int Oprice[psize];
int Ostock[psize];

string bank[psize];
double balance[psize];

string employee[psize];
double salary[psize];

string cart[cartSize]; //product in customer cart
int cartQuantity[cartSize][2]; // quatity & price of product

int main()
{
    const int dsize = 15;

    int choice = 0;
    int input = 0;
    int Pchoice = 0;

    string user = "N/A";
    string key = "N/A";

    bool flag = false;  // loop controller
    bool Aflag = false; // admin page loop controller
    bool Cflag = false; // Customer page loop controller
    bool Eflag = false; // employee page loop controller

    string edit = "N/A"; //for edit and delete a product
    string discountCoupons[dsize];
    double discountPercentage[dsize];

    initialize(username,psize,"N/A");
    initialize(grocery,psize,"N/A");
    initialize(snacks,psize,"N/A");
    initialize(product,psize,"N/A");
    initialize(discountCoupons,dsize,"N/A");
    initialize(employee,psize,"N/A");
    initialize(cart,cartSize,"N/A");


    while(flag == false)
    {
        bool flag = false;  // loop controller
        bool Aflag = false; // admin page loop controller
        bool Cflag = false; // Customer page loop controller
        bool Eflag = false; // employee page loop controller
        system("cls");
        cout << "***************************************************************************************************************************" << endl;
        cout << "                                                STORE MANAGEMENT SYSTEM                                                    " << endl;
        cout << "***************************************************************************************************************************" << endl;
        cout << endl;
        cout << "   1.           Log in as Admin       " << endl;
        cout << "   2.           Log in as Employee    " << endl;
        cout << "   3.           Sign in as Customer    " << endl;
        cout << "   4.           Sign Up as Customer   " << endl;
        cout << "   0.           Exit                  " << endl << endl;
        cout << "Enter Choice : ";
        cin >> choice;
        cin.ignore(100,'\n');
        cout << endl;
        if (choice == 1)
        {
            logIn(user,"Admin",key,"1234");
            
            while (Aflag == false)
            {
                system("cls");
                cout << "***************************************************************************************************************************" << endl;
                cout << "                                              STORE MANAGEMENT SYSTEM                                                      " << endl;
                cout << "                                                      (ADMIN)                                                              " << endl;
                cout << "***************************************************************************************************************************" << endl;
                cout << endl;
                cout << "  1.       Add a Product stock                         " << endl;
                cout << "  2.       Edit a Product                              " << endl;
                cout << "  3.       Delete a Product                            " << endl;
                cout << "  4.       List of Product                             " << endl;
                cout << "  5.       Search a Product                            " << endl;
                cout << "  6.       Set Discounts                               " << endl;
                cout << "  7.       List of Discounts                           " << endl;
                cout << "  8.       Delete a Discount                           " << endl;
                cout << "  9.       Add a Employee                              " << endl;
                cout << "  10.      List of Employees                           " << endl;
                cout << "  11.      Delete a Employee                           " << endl;
                cout << "  12.      Total Sales of Month                        " << endl;
                cout << "  13.      Comparison of Sales on daily basis          " << endl;
                cout << "  14.      Profit/Loss Percentage                      " << endl;
                cout << "  0.       Exit                                " << endl << endl;
                cout << "                        Enter Choice : ";
                cin >> input;
                cin.ignore(100,'\n');
                cout << endl;

                if (input == 1)
                {
                    system("cls");
                    cout << "***************************************************************************************************************************" << endl;
                    cout << "                                                 Add a Product                                                           \n";
                    cout << "***************************************************************************************************************************" << endl;
                    cout << endl;
                    cout << "  1.       Grocery                             " << endl;
                    cout << "  2.       Snacks                              " << endl;
                    cout << "  3.       Others                            \n" << endl;
                    cout << "                  Enter Product type you want to Add : ";
                    cin >> Pchoice;
                    cin.ignore(100,'\n');
                    cout << endl << endl;

                    if (Pchoice == 1)
                    {
                        addProduct(grocery,Gprice,Gstock,psize);
                    }
                    
                    else if (Pchoice == 2)
                    {
                        addProduct(snacks,Sprice,Sstock,psize);   
                    }

                    else if (Pchoice == 3)
                    {
                        addProduct(product,Oprice,Ostock,psize);
                    }
                    else
                    {
                        cout << "            -----------------------------------------Invalid Input !-----------------------------------------" <<endl;
                        getch();
                    }
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

                    if (editFlag == false)
                    {
                        editFlag = productEdit(grocery, Gprice, Gstock, edit, psize);
                    }
                    if (editFlag == false)
                    {
                        editFlag = productEdit(snacks, Sprice, Sstock, edit, psize);
                    }
                    if (editFlag == false)
                    {
                        editFlag = productEdit(product, Oprice, Ostock, edit, psize);
                    }
                    else if (editFlag == false)
                    {
                        cout <<endl << endl;
                        cout << "    -------------------------------------Unable to Find Product------------------------------------- ";
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

                    if (editFlag == false)
                    {
                        editFlag = productDelete(grocery, Gprice, Gstock, edit, psize);
                    }
                    if (editFlag == false)
                    {
                        editFlag = productDelete(snacks, Sprice, Sstock, edit, psize);
                    }
                    if (editFlag == false)
                    {
                        editFlag = productDelete(product, Oprice, Ostock, edit, psize);
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
                    cout << "***************************************************************************************************************************" << endl;
                    cout << "         " << setw(20) << "Sr.no" << setw(30) <<"Product" << setw(30) <<"Price" << setw(30) <<"Stock" <<endl;
                    cout << "***************************************************************************************************************************" << endl <<endl;
                    cout << "                                                Grocery Items                                                            \n";
                    cout << endl;
                    displayList(grocery,Gprice,Gstock,psize);
                    cout << "                                                    Snacks                                                               \n";
                    cout << endl;
                    displayList(snacks,Sprice,Sstock,psize);
                    cout << "                                                Other Products                                                           \n";
                    cout << endl;
                    displayList(product,Oprice,Ostock,psize);
                    getch();
                }
                
                else if (input == 5)
                {
                    bool editFlag = false;
                    system("cls");
                    cout << "***************************************************************************************************************************" << endl;
                    cout << "                                                 Search a Product                                                        \n";
                    cout << "***************************************************************************************************************************" << endl;
                    cout << endl;
                    cout << "                    Enter Product You Want to Search : ";
                    getline(cin, edit);

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
                        getch();
                    }
                    
                }
                
                else if (input == 6)
                {
                    Pchoice = '0';
                    system("cls");
                    cout << "***************************************************************************************************************************" << endl;
                    cout << "                                                 Set Discounts Coupons                                                   \n";
                    cout << "***************************************************************************************************************************" << endl;
                    cout << endl;

                    for (int i = 0; i < dsize; i++)
                    {
                        if(discountCoupons[i] == "N/A")
                        {
                            cout << "                            Enter Coupon Name           : ";
                            cin >> discountCoupons[i];
                            cout << "                            Enter Discount Percentage   : ";
                            cin >> discountPercentage[i];
                            break;
                        }
                        else
                        {       
                            cout <<endl << endl;
                            cout << "    ----------------------------------Unable to Store Discount---------------------------------- ";
                            cout <<endl << endl;
                            cout << "       ----------------------------------Unsufficient Storage---------------------------------- ";
                        }
                    }
                    
                    getch();
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
                    cout << "***************************************************************************************************************************" << endl;
                    cout << "                                                Delete a Discount                                                        \n";
                    cout << "***************************************************************************************************************************" << endl;
                    cout << endl;
                    cout << "                    Enter Discount Coupon You Want to Delete : ";
                    getline(cin, edit); 

                    discountDelete(discountCoupons,edit,dsize);
                    getch();
                }

                else if (input == 9)
                {
                    system("cls");
                    cout << "***************************************************************************************************************************" << endl;
                    cout << "                                                 Add a Employee                                                          \n";
                    cout << "***************************************************************************************************************************" << endl;
                    cout << endl;
                    addEmployee(employee, salary, psize);
                    getch();
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

                    discountDelete(employee,edit,dsize);
                    getch();
                }

                else if (input == 12)
                {
                    //code
                }

                else if (input == 0)
                {
                    cout << "              --------------------------------------------T H A N K  Y O U !----------------------------------------------" <<endl;
                    cout << "             ----------------------------------------Program Closed Successfully-------------------------------------------" << endl;
                    Aflag = true;
                    getch();
                }

                else
                {
                    cout << "            ------------------------------------------------INVALID INPUT!------------------------------------------------" << endl;
                    getch();
                }
            }
        }
    
        else if (choice == 2)
        {
            logIn(user,"Employee",key,"1234");

            while (Eflag == false)
            {
                system("cls");
                cout << "***************************************************************************************************************************" << endl;
                cout << "                                              STORE MANAGEMENT SYSTEM                                                      " << endl;
                cout << "                                                    (Employee)                                                             " << endl;
                cout << "***************************************************************************************************************************" << endl;
                cout << endl;
                cout << "  1.       List of Products             " << endl;
                cout << "  2.       Customer Details             " << endl;
                cout << "  3.       Search Customer              " << endl;
                cout << "  4.       Delete a Customer            " << endl;
                cout << "  5.       Search a Product             " << endl;
                cout << "  6.       Total Sales                  " << endl;
                cout << "  0.       Exit                  " << endl << endl;
                cout << "                        Enter Choice : ";
                cin >> input;       
                cin.ignore(100,'\n');
                cout << endl;
                
                if (input == 1)
                {
                    system("cls");
                    cout << "***************************************************************************************************************************" << endl;
                    cout << "         " << setw(20) << "Sr.no" << setw(30) <<"Product" << setw(30) <<"Price" << setw(30) <<"Stock" <<endl;
                    cout << "***************************************************************************************************************************" << endl <<endl;
                    cout << "                                                Grocery Items                                                            \n";
                    cout << endl;
                    displayList(grocery,Gprice,Gstock,psize);
                    cout << "                                                    Snacks                                                               \n";
                    cout << endl;
                    displayList(snacks,Sprice,Sstock,psize);
                    cout << "                                                Other Products                                                           \n";
                    cout << endl;
                    displayList(product,Oprice,Ostock,psize);
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

                    if (editFlag == false)
                    {
                        editFlag = searchCustomer(username, bank, balance, edit, psize);
                    }
                    if (editFlag == false)
                    {
                        cout <<endl << endl;
                        cout << "    -------------------------------------Unable to Customer------------------------------------- ";
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
                    cout << endl;
                    cout << "                    Enter Product You Want to Search : ";
                    getline(cin, edit);

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
                        getch();
                    }
                    
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
        
        else if (choice == 3)
        {

            signIn(user,key);

            while (Cflag == false)
            {
                system("cls");
                cout << "***************************************************************************************************************************" << endl;
                cout << "                                              STORE MANAGEMENT SYSTEM                                                      " << endl;
                cout << "                                                    (CUSTOMER)                                                             " << endl;
                cout << "***************************************************************************************************************************" << endl;
                cout << endl;
                cout << "  1.       Add a Product to Cart        " << endl;
                cout << "  2.       Show Products in Your Cart   " << endl;
                cout << "  3.       Delete a Product from Cart   " << endl;
                cout << "  4.       List of All Products at Store" << endl;
                cout << "  5.       User Detail                  " << endl;
                cout << "  6.       Recharge Store Card          " << endl;
                cout << "  7.       Generate Total Bill          " << endl;
                cout << "  0.       Exit                  " << endl << endl;
                cout << "                        Enter Choice : ";
                cin >> input;       
                cin.ignore(100,'\n');
                cout << endl;
                
                if (input == 1)
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
                    displayList(grocery,Gprice,Gstock,psize);
                    cout << "                                                    Snacks                                                               \n";
                    cout << endl;
                    displayList(snacks,Sprice,Sstock,psize);
                    cout << "                                                Other Products                                                           \n";
                    cout << endl;
                    displayList(product,Oprice,Ostock,psize);
                    cout << endl << endl;
                    addCart(cart,cartQuantity,cartSize);
                    getch();
                }

                else if (input == 2)
                {
                    system("cls");
                    cout << "***************************************************************************************************************************" << endl;
                    cout << "                                             Show Products in Cart                                                       \n";
                    cout << "***************************************************************************************************************************" << endl;
                    cout << endl;
                    cout << "         " << setw(20) << "Sr.no" << setw(30) <<"Product" << setw(30) <<"Price" << setw(30) <<"Stock" <<endl;
                    cout << "***************************************************************************************************************************" << endl; 
                    cout <<endl;
                    cartList(cart,cartQuantity,cartSize);
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
                    displayList(grocery,Gprice,Gstock,psize);
                    cout << "                                                    Snacks                                                               \n";
                    cout << endl;
                    displayList(snacks,Sprice,Sstock,psize);
                    cout << "                                                Other Products                                                           \n";
                    cout << endl;
                    displayList(product,Oprice,Ostock,psize);
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
                    cout << "               T O T A L   B A L A N C E   U S E D   : Rs.   ";
                    cin.get();
                }

                else if (input == 0)
                {
                    cout << "            ------------------------------------------T H A N K  Y O U !------------------------------------------" <<endl;
                    cout << "            -------------------------------------Program Closed Successfully.-------------------------------------" << endl;
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

        else if (choice == 4)
        {
            signUp(username, passkey, bank, balance, psize);
        }
    }   
}

void logIn(string x, string name, string y, string key)
{
    while(x != name || y != key)
    {
        system("cls");
        cout << "***************************************************************************************************************************" << endl;
        cout << "                                           GROCERY STORE MANAGEMENT SYSTEM                                                 " << endl;
        cout << "                                                   (LOGIN PAGE)                                                            " << endl;
        cout << "***************************************************************************************************************************" << endl;
                
        cout << left;
        cout << setw(35) << endl;
        cout << "               U S E R N A M E :";
        getline(cin,x);
        cout << setw(35);
        cout << "               P A S S W O R D :";
        getline(cin,y);
        if(x != name || y != key)
        {
            cout << endl << endl;
            cout << "            --------------------------------------------INVALID USERNAME OR PASSWORD--------------------------------------------" << endl << endl;
            cout << "                      --------------------------------------------TRY AGAIN--------------------------------------------         " << endl << endl;
            cin.get();
        }
    }
}

void signUp(string name[], string pass[], string bank[], double balance[], int size)
{
    string confirm;
    for (int i = 0; i < size; i++)
    {
        if (name[i] == "N/A")
        {
            system("cls");
            cout << "***************************************************************************************************************************" << endl;
            cout << "                                           GROCERY STORE MANAGEMENT SYSTEM                                                 " << endl;
            cout << "                                                   (LOGIN PAGE)                                                            " << endl;
            cout << "***************************************************************************************************************************" << endl;

            cout << left;
            cout << setw(35) << endl;
            cout << "               U S E R N A M E                       :       ";
            getline(cin, name[i]);
            cout << setw(35);
            cout << "               P A S S W O R D                       :       ";
            getline(cin, pass[i]);
            cout << setw(35);
            cout << "               C O N F I R M   P A S S W O R D       :       ";
            getline(cin, confirm);

            while (pass[i] != confirm)
            {
                cout << "  ------------------------------------------Invalid Confirm Password-----------------------------------------" << endl;
                cout << "  -------------------------------------------------Try Again-------------------------------------------------" << endl;
                cout << setw(35);
                cout << "               C O N F I R M   P A S S W O R D :";
                getline(cin, confirm);
            }

            cout << setw(35) << endl;
            cout << "               B A N K  A C C O U N T   N O          :       ";
            getline(cin, bank[i]);
            cout << setw(35) << endl;
            cout << "               B A L A N C E   T O   R E C H A R G E : Rs.   ";
            cin >> balance[i];
            cin.ignore(256, '\n'); 

            cout << "  ------------------------------------------Signed In Successfully-----------------------------------------" << endl;
            return ;
        }
    }
    cout << "  ------------------------------------------Space is Full-----------------------------------------" << endl;
    cout << "  -----------------------------------------Unable to Store----------------------------------------" << endl;
    
}

void signIn(string x, string y)
{
    bool searchFlag;
    do
    {
        searchFlag = true;
        system("cls");
        cout << "***************************************************************************************************************************" << endl;
        cout << "                                           GROCERY STORE MANAGEMENT SYSTEM                                                 " << endl;
        cout << "                                                   (LOGIN PAGE)                                                            " << endl;
        cout << "***************************************************************************************************************************" << endl;
                
        cout << left;
        cout << setw(35) << endl;
        cout << "               U S E R N A M E :";
        getline(cin,x);
        cout << setw(35);
        cout << "               P A S S W O R D :";
        getline(cin,y);
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
            cin.get();
        }
    }while (searchFlag);
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

void addProduct(string arr1[], int arr2[], int arr3[], int size)
{
    for (int i = 0; i < psize; i++)
    {
        flag1[1] = true;
        if (arr1[i] == "N/A")
        {
            cout << "                Enter Product : ";
            getline(cin,arr1[i]);
            cout << "                Enter Price : ";
            cin >> arr2[i];
            cin.ignore(256,'\n');
            cout << "                Enter Product Stock : ";
            cin >> arr3[i];
            cin.ignore(256,'\n');
            flag1[1] == false;
            cout << endl << "                   Product Stored Successfully      " << endl;
            break;
        }
    }
    if (flag1[1] != true)
    {
        cout << "            -------------------------------------Store is Full-------------------------------------" <<endl;
        cout << "            ------------------------------------Unable to store------------------------------------" <<endl;
    }
}

void addEmployee(string arr1[], double arr2[], int size)
{
    for (int i = 0; i < size; i++)
    {
        flag1[1] = true;
        if (arr1[i] == "N/A")
        {
            cout << "                Enter Employee Name : ";
            getline(cin,arr1[i]);
            cout << "                Enter Salary        : ";
            cin >> arr2[i];
            cin.ignore(256,'\n');
            flag1[1] == false;
            cout << endl << "                            Employee Data Stored Successfully      " << endl;
            break;
        }
    }
    if (flag1[1] != true)
    {
        cout << "            -------------------------------------Store is Full-------------------------------------" <<endl;
        cout << "            ------------------------------------Unable to store------------------------------------" <<endl;
    }
}

void addCart(string arr1[], int arr2[][2], int size)
{
    for (int i = 0; i < size; i++)
    {
        bool searchFlag = false;
        flag1[1] = true;
        string add;
        if (arr1[i] == "N/A")
        {
            cout << "                Enter Product : ";
            getline(cin,add);

            if (searchFlag == false)
            {
                searchFlag = searchProduct(grocery, Gprice, Gstock, add, psize);
                if (searchFlag == true)
                {
                    arr1[i] = add;
                    arr2[i][1] = Gprice[index];
                }
            }
            if (searchFlag == false)
            {
                searchFlag = searchProduct(snacks, Sprice, Sstock, add, psize);
                if (searchFlag == true)
                {
                    arr1[i] = add;
                    arr2[i][1] = Sprice[index];
                }
            }
            if (searchFlag == false)
            {
                searchFlag = searchProduct(product, Oprice, Ostock, add, psize);
                if (searchFlag == true)
                {
                    arr1[i] = add;
                    arr2[i][1] = Oprice[index];
                }
            }
            cout << endl << endl;
            cout << "                Enter Quantity : ";
            cin >> arr2[i][0];
            cin.ignore(256,'\n');
            
            if (searchFlag == false)
            {
                cout <<endl << endl;
                cout << "    -------------------------------------Unable to Find Product------------------------------------- ";
                break;
            }

            flag1[1] == false;
            cout << endl << "                   Product Stored Successfully      " << endl;
            break;
        }
    }
}

void displayList(string arr1[], int arr2[], int arr3[], int size)
{
    cout <<left;
    flag1[4] = true;
    for (int i = 0; i < size; i++)
    {
        if (arr1[i] != "N/A")
        {
            cout  << "         " << setw(20) << i+1 << setw(30) << arr1[i] << "Rs." << setw(30) << arr2[i] << setw(30) << arr3[i] <<endl;
            flag1[4] = false;
        }
    }
    if (flag1[4] != false)
    {
        cout << endl << endl;
    }
}

void discountList(string arr1[], double arr2[], int size)
{
    cout <<left;
    bool disFlag = true;
    for (int i = 0; i < size; i++)
    {
        if (arr1[i] != "N/A")
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

void cartList(string arr1[], int arr2[][2], int size)
{
    cout <<left;
    bool disFlag = true;
    for (int i = 0; i < size; i++)
    {
        if (arr1[i] != "N/A")
        {
            cout  << "         " << setw(20) << i+1 << setw(30) << arr1[i] << "Rs." << setw(30)  << arr2[i][1] << setw(30) << arr2[i][0] <<endl;
            flag1[4] = false;
        }
    }
    if (flag1[4] != false)
    {
        cout << endl << endl;
    }
}

bool productEdit(string arr1[], int arr2[], int arr3[], string edit, int size)
{
    
    for (int i = 0; i < size; i++)
    {
        if (arr1[i] == edit)
        {
            cout << endl << endl;

            cout << "          " << setw(30) <<"Product" << setw(30) <<"Price" << setw(30) <<"Stock" <<endl;
            cout << "***************************************************************************************************************************" << endl <<endl;
            cout << "          " << setw(30) << arr1[i] << "Rs." << setw(30) << arr2[i] << setw(30) << arr3[i] <<endl << endl;
            
            cout << "                Enter Update Product Name : ";
            getline(cin,arr1[i]);
            cout << "                Enter Update Price        : ";
            cin >> arr2[i];
            cout << "                Enter Update Stock        : ";
            cin >> arr3[i];
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
            
            cout << "          " << setw(30) <<"Product" << setw(30) <<"Price" << setw(30) <<"Stock" <<endl;
            cout << "***************************************************************************************************************************" << endl <<endl;
            cout << "          " << setw(30) << arr1[i] << "Rs." << setw(30) << arr2[i] << setw(30) << arr3[i] <<endl << endl;
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

bool productDelete(string arr1[], int arr2[], int arr3[], string edit, int size)
{
    int flag = 0;
    if (searchProduct(arr1, arr2, arr3, edit, size))
    {
        cout << endl << endl;
        cout << "Confirm Delete (1 for Yes / 0 for no) : ";
        cin >> flag;
        if (flag == 1)
        {
            arr1[index] = "N/A" ;
            cout << "            -------------------------------------Discount Coupon Deleted.-------------------------------------" << endl;
            return true;
        }
    }
    return false;
}

bool discountDelete(string arr1[], string edit, int size)
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
        if (arr1[i] != "N/A")
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
            arr1[index] = "N/A" ;
            cout << "            -------------------------------------Customer Data Deleted.-------------------------------------" << endl;
            return true;
        }
    }
    return false;
}

bool cartDelete(string arr1[], int arr2[][2], string del, int size)
{
    int flag = 0;
    for (int i = 0; i < size; i++)
    {
        if (arr1[i] == del)
        {
            cout << endl << endl;
            cout << "Confirm Delete (1 for Yes / 0 for no) : ";
            cin >> flag;
            if (flag == 1)
            {
                arr1[index] = "N/A" ;
                cout << "            -------------------------------------Discount Coupon Deleted.-------------------------------------" << endl;
                return true;
            }
        }
        }
    
    return false;
}