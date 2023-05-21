#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <time.h>
#include <unistd.h>

#define MAX_USERNAME_LEN 100
#define MAX_PASSWORD_LEN 100
#define MAX_LINE_LEN 100

void login(void);

void leave_approver_login(void);  
void leave_approver_menu(void);
void manage_leave(void);
void monthly_report(void);
void staff_availability(void);

void admin_login (void);
void admin_menu (void);
void add_staff(void);
void view_admin_leave(void);

void staff_login(void);
void staff_menu(void);
void apply_leave(void);
void view_staff_leave(void);
void cancel_leave(void);

int main()
{
    // declare main_choice variable
    int main_choice;
    // print welcome message and school choices
    printf("\n\n\t\tWelcome to Leave Management System\n");
    printf("\nChoose a school\n\n [1] SOC (School of Computing)\n [2] SOB (School of Business) \n [3] SOE (School of Engineering)\n [4] Exit\n");

    // prompt user to enter choice and store it in main_choice variable
    printf("\nEnter your choice:");
    scanf("%d", &main_choice);

    // switch statement based on the user choice
    switch (main_choice){
        // if choice is 1, 2, or 3, call login function
        case 1:
            login();
            break;
        case 2:
            login();
            break;
        case 3:
            login();
            break;
        // if choice is 4, print exit message and terminate program with exit status 1
        case 4:
            printf("Thank you! Have a great day\n");
            exit(1);
            break;
        // if choice is not 1, 2, 3, or 4, print error message and call main function recursively
        default:
            printf("\nInvalid Input");
            printf("\nWrong school lah!\nWhat you doing lah?");
            main();
            break;
    }
    // return 0 to indicate successful program execution
    return 0;
}

void login()
{
    // Declare an integer variable named login_choice
    int login_choice;
    // Display a message asking user to select a login option
    printf("\n\nLogging in as ?\n\n [1] Leave Approver\n [2] Admin \n [3] Staff\n [4] Exit\n");
    // Get user input and store it in login_choice variable
    scanf("%d",&login_choice);
    // Switch statement to check the value of login_choice variable
    switch(login_choice)
    {
    // If login_choice is equal to 1
        case 1:
            // Display a message for leave approver login
            printf("\n\n");
            printf("\t\tLEAVE APPROVER LOGIN\n");
            // Call the function leave_approver_login()
            leave_approver_login();
            // Exit the switch statement
            break;
    // If login_choice is equal to 2
    case 2:
        // Display a message for admin login
        printf("\n\n");
        printf("\t\tADMIN LOGIN\n");
        // Call the function admin_login()
        admin_login();
        // Exit the switch statement
        break;
    
    // If login_choice is equal to 3
    case 3:
        // Display a message for staff login
        printf("\n\n");
        printf("\t\tSTAFF LOGIN\n");
        // Call the function staff_login()
        staff_login();
        // Exit the switch statement
        break;

    // If login_choice is equal to 4
    case 4:
        // Display a thank you message
        printf("Thank you! Have a great day\n");
        // Exit the program with exit code 0
        exit(0);
        // Exit the switch statement
        break;

    // If login_choice does not match any of the case statements
    default:
        // Display an error message
        printf("INVALID ENTRY! TRY AGAIN\n");
        login();
        // Exit the switch statement
        break;
    }
}


void leave_approver_login ()
{
    // Declare character arrays for username, password, and temporary username and password
    char username[MAX_USERNAME_LEN];
    char password[MAX_PASSWORD_LEN];
    char temp_username[MAX_USERNAME_LEN];
    char temp_password[MAX_PASSWORD_LEN];
    // Declare a flag to keep track of whether or not the user is logged in
    int logged_in = 0;
    // Declare a file pointer
    FILE *fp;

    // Prompt the user to enter their username and password
    printf("Username: ");
    scanf("%s", username);
    printf("Password: ");
    scanf("%s", password);

    // Check if the user exists in the "leave_approver.txt" file
    fp = fopen("leave_approver.txt", "r");
    while (fscanf(fp,"Username: %s\nPassword: %s\n\n", temp_username, temp_password) != EOF) {
        if (strcmp(username, temp_username) == 0) {
            // If the username matches, check if the password matches
            if (strcmp(password, temp_password) == 0) {
                logged_in = 1;
                break;
            } else {
                // If the password is incorrect, prompt the user to enter their credentials again
                printf("Incorrect password\n");
                leave_approver_login ();
                return;
            }
        }
    }
    fclose(fp);

    // If the user is not logged in
    if (!logged_in) {
        // Check if the user wants to register
        char register_choice;
        printf("User not found. Would you like to register? (y/n) ");
        scanf(" %c", &register_choice);

        // If the user wants to register
        if (register_choice == 'y') {
            // Register the user by appending their credentials to the "leave_approver.txt" file
            fp = fopen("leave_approver.txt", "a");
            fprintf(fp, "Username: %s\nPassword: %s\n\n", username, password);
            fclose(fp);
            printf("User successfully registered!\n");
        } else {
            // If the user does not want to register, prompt them to enter their credentials again
            printf("Login failed.\n");
            leave_approver_login ();
        }
    } else {
        // If the user is logged in, print a success message and display the leave_approver_menu
        printf("Login successful!\n");
        leave_approver_menu();
    }
    return;
}

void admin_login ()
{
    // Declare four character arrays to hold the username, password, and temporary username and password variables, and an integer variable to indicate whether the user is logged in
    char username[MAX_USERNAME_LEN];
    char password[MAX_PASSWORD_LEN];
    char temp_username[MAX_USERNAME_LEN];
    char temp_password[MAX_PASSWORD_LEN];
    int logged_in = 0;
    // Declare a file pointer variable to interact with files
    FILE *fp;
    // Print a prompt to enter the username and password
    printf("Username: ");
    // Read the username entered by the user and store it in the username variable
    scanf("%s", username);
    printf("Password: ");
    // Read the password entered by the user and store it in the password variable
    scanf("%s", password);

    // Open the admin.txt file for reading and check if the user exists in the file
    fp = fopen("admin.txt", "r");
    while(fscanf(fp,"Username: %s\nPassword: %s\n\n", temp_username, temp_password) != EOF) {
        if (strcmp(username, temp_username) == 0) {
            if (strcmp(password, temp_password) == 0) {
                // If the username and password match, set the logged_in variable to 1 and exit the loop
                logged_in = 1;
                break;
            } else {
                // If the password is incorrect, print an error message, call the admin_login function recursively, and return from the current function
                printf("Incorrect password\n");
                admin_login ();
                return;
            }
        }
    }
    // Close the file
    fclose(fp);

    // If the user is not logged in, check if they want to register
    if (!logged_in) {
        // Declare a character variable to hold the user's choice
        char register_choice;
        printf("User not found. Would you like to register? (y/n) ");
        // Read the user's choice and store it in the register_choice variable
        scanf(" %c", &register_choice);

        // If the user wants to register, add their username and password to the admin.txt file
        if (register_choice == 'y') {
            // Open the admin.txt file for appending
            fp = fopen("admin.txt", "a");
            // Write the user's username and password to the file
            fprintf(fp, "Username: %s\nPassword: %s\n\n", username, password);
            // Close the file
            fclose(fp);
            // Print a success message
            printf("User successfully registered!\n");
        } else {
            // If the user does not want to register, print a message indicating that the login failed, call the admin_login function recursively, and return from the current function
            printf("Login failed.\n");
            admin_login ();
        }
    } else {
        // If the user is logged in, print a success message and call the admin_menu function
        printf("Login successful!\n");
        admin_menu();
    }
    // Return from the function
    return;

}


void staff_login()
{
    // Define variables for storing user input and temp variables for checking credentials
    char username[MAX_USERNAME_LEN];
    char password[MAX_PASSWORD_LEN];
    char temp_username[MAX_USERNAME_LEN];
    char temp_password[MAX_PASSWORD_LEN];
    // Define a variable to keep track of whether the user is logged in or not
    int logged_in = 0;
    // Define a file pointer for reading staff credentials
    FILE *fp;
    // Prompt for user input
    printf("Username: ");
    scanf("%s", username);
    printf("Password: ");
    scanf("%s", password);

    // Check if user credentials match those in staff_credentials.txt
    fp = fopen("staff_credentials.txt", "r");
    while(fscanf(fp,"Username: %s\nPassword: %s\n\n", temp_username, temp_password) != EOF) {
        if (strcmp(username, temp_username) == 0) {
            if (strcmp(password, temp_password) == 0) {
                logged_in = 1;
                break;
            } else {
                printf("Incorrect password\n");
                // If the password is incorrect, recursively call staff_login() to prompt for input again
                staff_login();
                break;
                return;
            }
        }
    }
    fclose(fp);

    // If the user is not logged in, prompt them to contact the admin to register
    if (!logged_in)
    {
    printf("Login failed.\nPlease contact admin to register\n");
    login();
    }else {
        printf("Login successful!\n");
        // If the user is logged in, call staff_menu() to present them with menu options
        staff_menu();
    }
    return;
}

void admin_menu ()
{
    int main_choice;
    printf("\n\n\t\tADMIN MENU\n");

    printf("\nWhat would you like to do today?\n\n [1] Add New Staff\n [2] View Staff Leave Details\n [3] Generate Report \n [4] Exit \n");
        printf("\nEnter your choice:");
        scanf("%d", &main_choice);
        
        switch(main_choice)
        {
            case 1:
                printf("\n--------------ADD A NEW STAFF-------------\n");
                add_staff();
                break;

            case 2:
                printf("\n--------------VIEW STAFF LEAVE DETAILS-------------\n");
                view_admin_leave();
                break;
                
            case 3:
                printf("\n--------------GENERATE REPORT-------------\n");
                monthly_report();
                break;

            case 4:
                printf("Thank you! Have a great day");
                login();

            default:
                printf("INVALID ENTRY! TRY AGAIN\n");
                admin_menu();
                break;
        }
}

void add_staff()
{
    // Define a struct to store staff member details
    struct Staff
    {
        int id;
        char name[100];
        char department[100];
        int leave_balance;
    } staff;
    
    // Declare variables
    char line[100];
    int choice;
    FILE *fp;
    FILE *file;
    int repeat = 1;
    staff.leave_balance = 30;

    // Get staff member's name
    while (repeat) {
        repeat = 0;
        printf("Enter staff member's name: ");
        scanf("%s", staff.name);

        // Open file and check if name is already in the file
        fp = fopen("staff.txt", "r");
        while (fgets(line, sizeof(line), fp)) {
            if (strstr(line, staff.name)) {
                printf("Name already in file.\n");
                repeat = 1;
                break;
            }
        }
        fclose(fp);
    }

    // Get staff member's department choice
    printf("Enter staff member's department choice: \n");
    printf("[1] Academic\n");
    printf("[2] Administration\n");
    printf("[3] Management\n");
    printf("[4] Technical\n");
    scanf("%d", &choice);

    // Determine the department based on choice
    switch (choice) {
        case 1:
            strcpy(staff.department, "Academic");
            break;
        case 2:
            strcpy(staff.department, "Administration");
            break;
        case 3:
            strcpy(staff.department, "Management");
            break;
        case 4:
            strcpy(staff.department, "Technical");
            break;
        default:
            printf("Invalid department choice.\n");
    }

    // Generate an ID based on the name and a random number
    int random_num;
    srand(time(NULL));
    random_num = rand() % 1000; // generates a random number between 0 and 999
    staff.id = (int)staff.name[0] + (int)staff.name[strlen(staff.name)-1] + random_num;

    // Print the ID to the console
    printf("%s's ID is: %s%03d\n", staff.name, staff.name, staff.id);

    // Open or create file for writing
    fp = fopen("staff.txt", "a");
    file = fopen("staff_credentials.txt","a");

    // Write staff member details to file
    fprintf(fp, "%s%03d | Name: %s | Department: %s | Leave Balance: %d\n", staff.name, staff.id, staff.name, staff.department, staff.leave_balance);
    fprintf(file, "Username: %s%03d\nPassword: staff123\n\n", staff.name, staff.id);

    // Close file
    fclose(fp);
    fclose(file);

    // Print success message to console and go back to admin menu
    printf("%s has been added to file.\n", staff.name);
    printf("%s's credentials have been saved.\n", staff.name);
    sleep(1);
    admin_menu();
}

void leave_approver_menu ()
{
    // Declare a variable "main_choice" to store the user's choice
    int main_choice;
    // Print the leave approver menu
    printf("\n\n\t\tLEAVE APPROVER MENU\n");
    printf("\nWhat would you like to do today?\n\n [1] Manage Leave\n [2] Check Staff Availablity \n [3] View Staff Details\n [4] Exit \n");
    printf("\nEnter your choice:");

    // Read the user's choice
    scanf("%d", &main_choice);

    // Check the user's choice using a switch statement
    switch(main_choice)
    {
        // If the user selects 1, print the "MANAGE LEAVE" header and call the "manage_leave" function
        case 1:
            printf("\n--------------MANAGE LEAVE-------------\n");
            manage_leave();
            break;
        
        // If the user selects 2, print the "STAFF AVAILABILITY" header
        case 2:
            printf("\n--------------STAFF AVAILABILITY-------------\n");
            staff_availability();
            break;
        
        // If the user selects 3, print the "VIEW STAFF DETAILS" header and call the "staff_availability" function
        case 3:
            printf("\n--------------VIEW STAFF DETAILS-------------\n");
            staff_availability();
            break;
        
        // If the user selects 4, print a message and call the "login" function to return to the login screen
        case 4:
            printf("Thank you! Have a great day");
            login();
        
        // If the user enters an invalid choice, print an error message and call the "leave_approver_menu" function to display the menu again
        default:
            printf("INVALID ENTRY! TRY AGAIN\n");
            leave_approver_menu();
            break;
    }

}

void staff_menu()
{
// Declare a variable "staff_choice" to store the user's choice
int staff_choice;

    printf("\n\n\t\tSTAFF MENU\n");
    
    printf("\nWhat would you like to do today?\n\n [1] Apply Leave\n [2] Cancel Leave \n [3] View Leave details\n [4] Exit \n");
        printf("\nEnter your choice:");
        scanf("%d", &staff_choice);
        
        switch(staff_choice)
        {
            case 1:
                printf("\n--------------APPLY LEAVE-------------\n");
                apply_leave();
                break;

            case 2:
                printf("\n--------------CANCEL LEAVE-------------\n");
                cancel_leave();
                break;
                
            case 3:
                printf("\n--------------VIEW LEAVE DETAILS-------------\n");
                view_staff_leave();
                break;

            case 4:
                printf("Thank you! Have a great day");
                login();

            default:
                printf("INVALID ENTRY! TRY AGAIN\n");
                getchar();
                break;
        }
    
}

void apply_leave()
{
// Define a struct for leave with its attributes
struct Leave {
    char staff_name[30];
    char leave_type[20];
    char start_date[15];
    char leave_status;
};

// Define a struct for staff with its attributes
struct Staff {
    char id[10];
    char name[20];
    char department[20];
    int leave_balance;
};

// Declare variables
char line[MAX_LINE_LEN];
struct Staff staff;
struct Leave leave;
int leave_option;
int day_to_add = 0;
int new_leave_balance = 0;

// Ask for staff ID
printf(" staff ID: ");
scanf("%s",leave.staff_name);

// Display leave options and ask user to choose one
printf("Select leave option:\n");
printf("[1] Maternity Leave\n");
printf("[2] Annual Leave\n");
printf("[3] Emergency Leave\n");
printf("[4] Compassionate Leave\n");
printf("[5] Medical Leave\n");
scanf("%d",&leave_option);

// Open files for reading and appending
FILE *file = fopen("staff.txt", "r+");
FILE *fpt = fopen("leave_application.txt","a");

// Check the chosen leave option and update the staff's leave balance accordingly
switch(leave_option) {
    case 1:
        strcpy(leave.leave_type, "Maternity");
        printf("This will not be deducted from your leave balance");
        day_to_add = 180;
        break;
    case 2:
        strcpy(leave.leave_type, "Annual");
        day_to_add = 16;
        // Read each line of staff.txt and update the leave balance of the corresponding staff member
        while(fgets(line, MAX_LINE_LEN, file)) {
            sscanf(line, "%s | Name: %s | Department: %s | Leave Balance: %d", staff.id, staff.name, staff.department, &staff.leave_balance);
            if(strcmp(staff.id, leave.staff_name) == 0) {
                if(staff.leave_balance > day_to_add) {
                    new_leave_balance = staff.leave_balance - day_to_add;
                    fseek(file, -strlen(line), SEEK_CUR);
                    // Ask for start date of leave
                    printf("Enter start date in the format dd/mm/yyyy: ");
                    scanf("%s", &leave.start_date);
                    // Write updated leave balance to staff.txt and close file
                    fprintf(file,"%s | Name: %s | Department: %s | Leave Balance: %d\n",staff.id, staff.name, staff.department, new_leave_balance);
                    fclose(file);
                    // Display success message, write leave application to leave_application.txt and close file, and return to staff menu
                    printf("Leave application submitted successfully");
                    fprintf(fpt,"%s %s %s %s Pending\n",leave.staff_name,staff.department,leave.leave_type,leave.start_date);
                    fclose(fpt);
                    staff_menu();
                }
                else {
                    // Display error message and remaining leave balance, wait for 2 seconds, and return to staff menu
                    printf("Leave balance is not sufficient.\n");
                    printf("Remaining Leave Balance: %d",staff.leave_balance);
                    sleep(2);
                    staff_menu();
                }
            }
        }
        break;
    case 3:
        strcpy(leave.leave_type, "Emergency");
        day_to_add = 7;
        // Read each line of staff.txt and update the leave balance of the corresponding staff member
        while(fgets(line, MAX_LINE_LEN, file)){
                sscanf(line, "%s | Name: %s | Department: %s | Leave Balance: %d", staff.id, staff.name, staff.department, &staff.leave_balance);
                if(strcmp(staff.id, leave.staff_name) == 0) {
                    if(staff.leave_balance > day_to_add) {
                        new_leave_balance = staff.leave_balance - day_to_add;
                        fseek(file, -strlen(line), SEEK_CUR);
                        // Ask for start date of leave
                        printf("Enter start date in the format dd/mm/yyyy: ");
                        scanf("%s", &leave.start_date);
                        // Write updated leave balance to staff.txt and close file
                        fprintf(file,"%s | Name: %s | Department: %s | Leave Balance: %d\n",staff.id, staff.name, staff.department, new_leave_balance);
                        fclose(file);
                        // Display success message, write leave application to leave_application.txt and close file, and return to staff menu
                        printf("Leave application submitted successfully");
                        fprintf(fpt,"%s %s %s %s Pending\n",leave.staff_name,staff.department,leave.leave_type,leave.start_date);
                        fclose(fpt);
                        staff_menu();
                    }
                    else {
                        // Display error message and remaining leave balance, wait for 2 seconds, and return to staff menu
                        printf("Leave balance is not sufficient.\n");
                        printf("Remaining Leave Balance: %d",staff.leave_balance);
                        sleep(2);
                        staff_menu();
                    }
            }
        }
        break;              
    case 4:
        strcpy(leave.leave_type, "Compassionate");
        day_to_add = 5;
        // Read each line of staff.txt and update the leave balance of the corresponding staff member
        while(fgets(line, MAX_LINE_LEN, file)) {
            sscanf(line, "%s | Name: %s | Department: %s | Leave Balance: %d", staff.id, staff.name, staff.department, &staff.leave_balance);
            if(strcmp(staff.id, leave.staff_name) == 0) {
                if(staff.leave_balance > day_to_add) {
                    new_leave_balance = staff.leave_balance - day_to_add;
                    fseek(file, -strlen(line), SEEK_CUR);
                    // Ask for start date of leave
                    printf("Enter start date in the format dd/mm/yyyy: ");
                    scanf("%s", &leave.start_date);
                    // Write updated leave balance to staff.txt and close file
                    fprintf(file,"%s | Name: %s | Department: %s | Leave Balance: %d\n",staff.id, staff.name, staff.department, new_leave_balance);
                    fclose(file);
                    // Display success message, write leave application to leave_application.txt and close file, and return to staff menu
                    printf("Leave application submitted successfully");
                    fprintf(fpt,"%s %s %s %s Pending\n",leave.staff_name,staff.department,leave.leave_type,leave.start_date);
                    fclose(fpt);
                    staff_menu();
                }
                else {
                    printf("Leave balance is not sufficient.\n");
                    printf("Remaining Leave Balance: %d",staff.leave_balance);
                    sleep(2);
                    staff_menu();
                }
            }
        }                
        break;
    case 5:
        strcpy(leave.leave_type, "Medical");
        day_to_add = 3;
        // Read each line of staff.txt and update the leave balance of the corresponding staff member
        while(fgets(line, MAX_LINE_LEN, file)) {
            sscanf(line, "%s | Name: %s | Department: %s | Leave Balance: %d", staff.id, staff.name, staff.department, &staff.leave_balance);
            if(strcmp(staff.id, leave.staff_name) == 0) {
                if(staff.leave_balance > day_to_add) {
                    new_leave_balance = staff.leave_balance - day_to_add;
                    fseek(file, -strlen(line), SEEK_CUR);
                    // Ask for start date of leave
                    printf("Enter start date in the format dd/mm/yyyy: ");
                    scanf("%s", &leave.start_date);
                    // Write updated leave balance to staff.txt and close file
                    fprintf(file,"%s | Name: %s | Department: %s | Leave Balance: %d\n",staff.id, staff.name, staff.department, new_leave_balance);
                    fclose(file);
                    // Display success message, write leave application to leave_application.txt and close file, and return to staff menu
                    printf("Leave application submitted successfully");
                    fprintf(fpt,"%s %s %s %s Pending\n",leave.staff_name,staff.department,leave.leave_type,leave.start_date);
                    fclose(fpt);
                    staff_menu();
                }
                else {
                // Display error message and return to staff menu if leave balance not sufficient
                    printf("Leave balance is not sufficient.\n");
                    printf("Remaining Leave Balance: %d",staff.leave_balance);
                    sleep(2);
                    staff_menu();
                }
            }
        }
        break;
    default:
        printf("Invalid option selected");
        exit(1);
}

}

void manage_leave()
{
 // Defines struct to hold employee data
struct Employee {
    char id[20];
    char department[20];
    char leave_type[10];
    char date[20];
    char status[20];
    };
    // Opens file in read mode
    FILE *file = fopen("leave_application.txt", "r");

    // Initializes struct to hold employee data
    struct Employee emp;

    // Initializes variables to hold user input, status choice, whether the staff ID was found, and the line number to edit
    char id[30];
    int status;
    int found = 0;
    int line_num = 0;

    // Prompts user to enter staff ID to manage leave
    printf("Enter a staff ID to manage leave:");
    scanf("%s", id);

    // Finds and prints lines for the specified staff ID
    while (fscanf(file, "%s %s %s %s %s", emp.id, emp.department, emp.leave_type, emp.date, emp.status) != EOF) {
        if (strcmp(emp.id, id) == 0) {
            printf("%s %s %s %s %s\n", emp.id, emp.department, emp.leave_type, emp.date, emp.status);
            line_num++;
            found = 1;
        }
    }

    // If staff ID was found, prompts user to enter line number to edit
    if (found) {
        printf("Enter line number to edit:");
        scanf("%d", &line_num);
        rewind(file);
        // Opens a temporary file in write mode
        FILE *temp = fopen("temp.txt", "w");
        int current_line = 0;
        // Loops through each line of the file and updates the line specified by the user
        while (fscanf(file,"%s %s %s %s %s", emp.id, emp.department, emp.leave_type, emp.date, emp.status) != EOF) {
            if (strcmp(emp.id, id) == 0) {
                current_line++;
                if (current_line == line_num) {
                    // Prompts user to choose a status for the leave application
                    printf("\n[1] Approved\n[2] Reject\n\nEnter your choice:");
                    scanf("%d", &status);
                    // Updates the leave status based on the user's choice
                    if (status == 1) {
                        strcpy(emp.status, "Approved");
                    } else if (status == 2) {
                        strcpy(emp.status, "Reject");
                    }
                    // Prints a success message after updating the leave status
                    printf("Leave status successfully updated!\n");
                }
            }
            // Writes each line to the temporary file
            fprintf(temp, "%s %s %s %s %s\n", emp.id, emp.department, emp.leave_type, emp.date, emp.status);
        }
        // Closes the temporary file and deletes the original file, then renames the temporary file to the original file name
        fclose(temp);
        remove("leave_application.txt");
        rename("temp.txt", "leave_application.txt");
    } else {
        // Prints an error message if the staff ID was not found
        printf("Staff with ID %s not found!", id);
    }

    // Closes the file and returns 0 to indicate

        fclose(file);
        leave_approver_menu();
        return;
}


void view_staff_leave()
{
    // Declaring a character array 'line' to store a line of text from a file.
    char line[MAX_LINE_LEN];
    // Defining a structure 'Leave' to store staff leave information.
    struct Leave {
    char staff_name[30];
    char staff_department[30];
    char leave_type[20];
    char start_date[15];
    char leave_status[20];
    };
    // Declaring a variable 'leave' of type 'Leave' to store leave details of a staff member.
    struct Leave leave;

    // Declaring a character array 'id' to store the staff ID whose leave application is to be viewed.
    char id[30];

    // Prompting the user to enter the staff ID whose leave application is to be viewed.
    printf("Please confirm staff ID:");
    // Reading the input from the user and storing it in 'id'.
    scanf("%s",&id);

    // Opening the file 'leave_application.txt' in read mode and assigning its file pointer to 'file'.
    FILE *file = fopen("leave_application.txt", "r");
    // Displaying the column headings for the staff leave information.
    printf("\nID\t\tDepartment\t\tType\t\tStart Date\tStatus\n");

    // Reading each line from the file 'leave_application.txt' until the end of file is reached.
    while(fgets(line, MAX_LINE_LEN, file)) {
        // Parsing the contents of the line and storing the values in the variables of 'leave'.
        sscanf(line, "%s %s %s %s %s", leave.staff_name,leave.staff_department,leave.leave_type,leave.start_date,leave.leave_status);
        // Checking if the staff name in 'leave' matches the staff ID entered by the user.
        if(strcmp(leave.staff_name, id) == 0) {
            // Displaying the staff leave information for the matching staff ID.
            printf("%s\t%s\t\t%s\t%s\t%s\n", leave.staff_name,leave.staff_department,leave.leave_type,leave.start_date,leave.leave_status);
        }
    }
    // Closing the file 'leave_application.txt'.
    fclose(file);
    // Pausing the program execution for 2 seconds.
    sleep(2); 
    // Calling the staff_menu() function to display the staff menu options.
    staff_menu();  
}

void view_admin_leave()
{
    char line[MAX_LINE_LEN];
    struct Leave {
        char staff_name[30];
        char staff_department[30];
        char leave_type[20];
        char start_date[15];
        char leave_status[20];
    };
    struct Leave leave;

    char id[30];

    printf("Please confirm staff ID:");
    scanf("%s",&id);

    FILE *file = fopen("leave_application.txt", "r");
    printf("\nID\t\tDepartment\t\tType\t\tStart Date\tStatus\n");
    while(fgets(line, MAX_LINE_LEN, file)) {
        sscanf(line, "%s %s %s %s %s", leave.staff_name,leave.staff_department,leave.leave_type,leave.start_date,leave.leave_status);
        if(strcmp(leave.staff_name, id) == 0) {
            printf("%s\t%s\t\t%s\t%s\t%s\n", leave.staff_name,leave.staff_department,leave.leave_type,leave.start_date,leave.leave_status);
        }
    }
    fclose(file);
    sleep(2); 
    admin_menu();  
}

void staff_availability(){
    char line[MAX_LINE_LEN];
    struct Leave {
        char staff_name[30];
        char staff_department[30];
        char leave_type[20];
        char start_date[15];
        char leave_status[20];
    };
    struct Leave leave;

    char id[30];

    printf("Please confirm staff ID:");
    scanf("%s",&id);

    FILE *file = fopen("leave_application.txt", "r");
    printf("\nID\t\tDepartment\t\tType\t\tStart Date\tStatus\n");
    while(fgets(line, MAX_LINE_LEN, file)) {
        sscanf(line, "%s %s %s %s %s", leave.staff_name,leave.staff_department,leave.leave_type,leave.start_date,leave.leave_status);
        if(strcmp(leave.staff_name, id) == 0) {
            printf("%s\t%s\t\t%s\t%s\t%s\n", leave.staff_name,leave.staff_department,leave.leave_type,leave.start_date,leave.leave_status);
        }
    }
    fclose(file);
    sleep(2); 
    leave_approver_menu();  
}

void cancel_leave(){
    // Declare two file pointers, a character array, and four strings
    FILE *fp, *temp;
    char line[1000], name[20], type[20], date[20], status[20], action[20];
    int line_no, delete_line;
    char id[20];

    // Open the "leave_application.txt" file for reading and "temp.txt" file for writing
    fp = fopen("leave_application.txt", "r");
    temp = fopen("temp.txt", "w");

    // Check if the file was opened successfully. If not, print an error message and return
    if (fp == NULL) {
        printf("File not found.\n");
        return;
    }

    // Prompt user to input the staff ID and read the input into the "id" character array
    printf("Confirm staff ID:");
    scanf("%s",id);
    printf("Lines that start with %s\n",id);

    // Initialize the line counter to 1 and read each line of the "leave_application.txt" file
    line_no = 1;
    while (fgets(line, sizeof(line), fp)) {

        // Extract the staff name, leave type, start date, leave status, and action from the line using sscanf
        sscanf(line, "%s %s %s %s %s", name, type, date, status, action);

        // Check if the staff ID matches the staff name on the line. If so, print the line number and the line content
        if (strncmp(name, id, 9) == 0) {
            printf("%d: %s", line_no, line);
        }

        // Increment the line counter
        line_no++;
    }

    // Close the "leave_application.txt" file and reopen it for reading
    fclose(fp);
    fp = fopen("leave_application.txt", "r");

    // Prompt the user to input the line number for the leave to be deleted and read the input into "delete_line"
    printf("Enter the line number for the leave to be deleted: ");
    scanf("%d", &delete_line);

    // Initialize the line counter to 1 and read each line of the "leave_application.txt" file again
    line_no = 1;
    while (fgets(line, sizeof(line), fp)) {

        // If the current line number is not the line to be deleted, write it to the "temp.txt" file
        if (line_no != delete_line) {
            fputs(line, temp);
        }

        // Increment the line counter
        line_no++;
    }

    // Close both files
    fclose(fp);
    fclose(temp);

    // Delete the original "leave_application.txt" file and rename "temp.txt" to "leave_application.txt"
    remove("leave_application.txt");
    rename("temp.txt", "leave_application.txt");

    // Print a success message, return to staff menu, and end the function
    printf("Leave successfully cancelled");
    staff_menu();
    return;

}

void monthly_report()
{    
    // Declare and initialize variables.
    char department[20];
    int count = 0;
    float total = 0.0;
    // Define a structure to store employee information.
    struct Employee {
        char id[20];
        char department[20];
        char leave_type[10];
        char date[20];
        char status[20];
    };
    struct Employee emp;

    // Declare variables to hold user input.
    int department_choice;

    // Open the "leave_application.txt" file in read mode.
    FILE *file = fopen("leave_application.txt", "r");

    // Prompt the user to choose a department for the report and store the choice in "department_choice".
    printf("\nEnter department of choice for report\n[1] Academic\n[2] Administration \n[3] Management\n[4] Technical\nEnter choice: ");
    scanf("%d", &department_choice);

    // Use "department_choice" to determine the chosen department and store the result in "department".
    if (department_choice == 1){
    strcpy(department,"Academic");
    }else if (department_choice == 2){
    strcpy(department,"Administration");
    }else if(department_choice == 3){
    strcpy(department,"Management");
    }else if(department_choice == 4){
    strcpy(department,"Technical");
    }
    else{
        printf("Invalid Choice");
        monthly_report();
    }

    // Print the report header.
    printf("\nMonthly report for %s department:\n\n",department);
    printf("Employee ID\t\tLeave Type\t\tDate\t\tStatus\n\n");

    // Loop through each line of the file and extract the employee information.
    while(fscanf(file, "%s %s %s %s %s", emp.id, emp.department, emp.leave_type, emp.date, emp.status) != EOF) {
        // If the department of the current employee matches the chosen department, print their information.
        if (strcmp(emp.department, department) == 0) {
            printf("%s\t\t%s\t\t%s\t%s\n",emp.id, emp.leave_type, emp.date, emp.status);
            count++;
            // If the leave application is approved, increment the "total" variable.
            if (strcmp(emp.status, "Approved") == 0) {
                total++;
            }
        }
    }
    // Print the total number of leave applications and the percentage of approved leave applications.
    printf("\nTotal number of leave applications: %d\n",count);
    printf("\nPercentage of approved leave applications: %.2f%%\n", total/count * 100);

    // Close the file and return.
    fclose(file);
    admin_menu();

}