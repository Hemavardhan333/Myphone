#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <stdbool.h>
#include <math.h>
#include <conio.h>
#include <windows.h>

/*Phonebook*/

struct Contact {
    char name[50];
    char phone[20];
    struct Contact *next;
};

struct Contact *head = NULL;

void insertContact(char name[], char phone[]) {
    struct Contact *newContact = (struct Contact*)malloc(sizeof(struct Contact));
    strcpy(newContact->name, name);
    strcpy(newContact->phone, phone);
    newContact->next = NULL;

    if (head == NULL || strcmp(head->name, name) > 0) {
        newContact->next = head;
        head = newContact;
    } else {
        struct Contact *current = head;
        while (current->next != NULL && strcmp(current->next->name, name) < 0) {
            current = current->next;
        }
        newContact->next = current->next;
        current->next = newContact;
    }
}

void displayContacts() {
    struct Contact *current = head;
    if (current == NULL) {
        printf("Phone book is empty.\n");
        return;
    }
    printf("Contacts in Phone Book:\n");
    while (current != NULL) {
        printf("Name: %s, Phone: %s\n", current->name, current->phone);
        current = current->next;
    }
}

void searchContact(char name[]) {
    struct Contact *current = head;
    while (current != NULL) {
        if (strcmp(current->name, name) == 0) {
            printf("Contact Found:\n");
            printf("Name: %s, Phone: %s\n", current->name, current->phone);
            return;
        }
        current = current->next;
    }
    printf("Contact not found.\n");
}

void deleteContact(char name[]) {
    struct Contact *current = head;
    struct Contact *prev = NULL;

    while (current != NULL && strcmp(current->name, name) != 0) {
        prev = current;
        current = current->next;
    }

    if (current == NULL) {
        printf("Contact not found.\n");
        return;
    }

    if (prev == NULL) {
        head = current->next;
    } else {
        prev->next = current->next;
    }

    free(current);
    printf("Contact deleted successfully.\n");
}

void editContact(char name[], char newPhone[]) {
    struct Contact *current = head;

    while (current != NULL && strcmp(current->name, name) != 0) {
        current = current->next;
    }

    if (current == NULL) {
        printf("Contact not found.\n");
        return;
    }

    strcpy(current->phone, newPhone);
    printf("Contact updated successfully.\n");
}

int mainPhoneBook() {
    int choice;
    char name[50];
    char phone[20];
    char newPhone[20];

    while (1) {
        printf("\n1. Add Contact\n");
        printf("2. Display Contacts\n");
        printf("3. Search Contact\n");
        printf("4. Delete Contact\n");
        printf("5. Edit Contact\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter name: ");
                scanf("%s", name);
                printf("Enter phone: ");
                scanf("%s", phone);
                insertContact(name, phone);
                break;
            case 2:
                displayContacts();
                break;
            case 3:
                printf("Enter name to search: ");
                scanf("%s", name);
                searchContact(name);
                break;
            case 4:
                printf("Enter name to delete: ");
                scanf("%s", name);
                deleteContact(name);
                break;
            case 5:
                printf("Enter name to edit: ");
                scanf("%s", name);
                printf("Enter new phone number: ");
                scanf("%s", newPhone);
                editContact(name, newPhone);
                break;
            case 6:
                printf("Exiting...\n");
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}

/*Clock*/

void Conversion24to12()
{
    int clockmin;
    int clockhour;
    char clockchar;
    scanf("%d %c %d", &clockhour, &clockchar, &clockmin);
    if (clockchar == ':')
    {
        if ((clockmin >= 0) && (clockmin < 60))
        {
            if ((clockhour < 12) && (clockhour > 0))
            {
                printf("%0.2d : %0.2d am", clockhour, clockmin);
            }
            else if ((clockhour > 12) && (clockhour < 24))
            {
                clockhour = clockhour - 12;
                printf("%0.2d : %0.2d pm", clockhour, clockmin);
            }
            else if( clockhour == 0){
                printf("%0.2d : %0.2d am",(clockhour + 12),clockmin);
            }
            else if( clockhour == 12){
                printf("%0.2d : %0.2d pm",(clockhour),clockmin);
            }
            else if (((clockhour >= 24) || (clockhour < 0)) || ((clockhour == 24) && (clockmin > 0)))
            {
                printf("Invalid Input");
            }
        }
        else
        {
            printf("Invalid Input");
        }
    }
    else
        printf("Invalid Input");
}

void Conversion12to24()
{
    int clockmin;
    int clockhour;
    char clockchar;
    printf("Enter time :\n");
    scanf("%d %c %d", &clockhour, &clockchar, &clockmin);
    printf("Enter am or pm ");
    char clockstr[2];
    scanf("%s", clockstr);
    if ((clockhour >= 0) && (clockhour < 12) && (clockmin >= 0) && (clockmin < 60))
    {
        if(clockstr[0] == 'a'){
            printf("%0.2d : %0.2d", clockhour,clockmin);
        }
        else if(clockstr[0]  == 'p'){
            printf("%0.2d : %0.2d", (clockhour + 12),clockmin);
        }
        else{
            printf("Invalid Output");
        }
    }
    else{
        printf("Invalid Output");
    }
    

}

void CurrentDisplaytime()
{
    time_t tm;
    time(&tm);
    printf("Current Date/Time = %s", ctime(&tm));
}

void Timer()
{

    int seconds, minutes, hours;

    printf("Enter the time in hours, minutes, and seconds format:\n");
    printf("Hours: ");
    scanf("%d", &hours);
    printf("Minutes: ");
    scanf("%d", &minutes);
    printf("Seconds: ");
    scanf("%d", &seconds);

    int total_seconds = hours * 3600 + minutes * 60 + seconds;

    while (total_seconds > 0)
    {
        system("cls"); // for clearing screen, change to "cls" on Windows
        printf("Time remaining: %02d:%02d:%02d\n", total_seconds / 3600, (total_seconds % 3600) / 60, total_seconds % 60);
        sleep(1);
        total_seconds--;
    }

    printf("Time's up!\n");
    int i = 0;
    while(i<10){
        Beep(1000,500);
        sleep(0.5);
        i++;
    }
}
int mainClock()
{
    printf("1. Conversion of 24 hour clock to 12 hour clock \n");
    printf("2. Conversion of 12 hour clock to 24 hour clock \n");
    printf("3. Show current time\n");
    printf("4. Timer\n");
    int clockx;
    scanf("%d", &clockx);
    switch (clockx)
    {
    case 1:
        Conversion24to12();
        break;
    case 2:
        Conversion12to24();
        break;
    case 3:
        CurrentDisplaytime();
        break;
    case 4:
        Timer();
        break;
    }
    return 0;
}

/*Calendar*/

//Mon-1, Tue-2, Wed-3, Thu-4, Fri-5, Sat-6, Sun-0
//Jan-1. Feb-2, Mar-3, Apr-4, May-5, Jun-6, Jul-7, Aug-8, Sep-9, Oct-10, Nov-11, Dec-12

int isLeap(int y)
{
    if(((y%100!=0)&&(y%4==0))||(y%400==0)){
        return 1;
    }
    return 0;
}

int fromDate1(int d, int m, int y)
{
    int dy = 365*(y-1) + (y-1)/4 - (y-1)/100 + (y-1)/400;
    int dm = 0;
    switch(m)
    {
        case 12:
            dm += 30;
        case 11:
            dm += 31;
        case 10:
            dm += 30;
        case 9:
            dm += 31;
        case 8:
            dm += 31;
        case 7:
            dm += 30;
        case 6:
            dm += 31;
        case 5:
            dm += 30;
        case 4:
            dm += 31;
        case 3:
            dm += 28 + isLeap(y);
        case 2:
            dm += 31;
    }
    return (d + dm + dy - 1);
}

int diffInDates(int d1, int m1, int y1, int d2, int m2, int y2)
{
    return (fromDate1(d2, m2, y2) - fromDate1(d1, m1, y1));
}

int mainCalendar()
{
    int d1, m1, y1, d2, m2, y2;
    printf("\n1. Find day on any date.\n");
    printf("2. Find number of days between any two days.\n");
    int choice;
    printf("Enter a choice: ");
    scanf("%d", &choice);
    switch(choice)
    {
    case 1:
        printf("Enter date(in DD/MM/YYYY): ");
        scanf("%d/%d/%d", &d1, &m1, &y1);
        if((d1>31) ||(m1>12)){
            printf("Error!\n");
            break;
        }
        int day = (fromDate1(d1, m1, y1) + 1)%7;
        switch(day)
        {
            case 0:
                printf("Sunday\n");
                break;
            case 1:
                printf("Monday\n");
                break;
            case 2:
                printf("Tuesday\n");
                break;
            case 3:
                printf("Wednesday\n");
                break;
            case 4:
                printf("Thursday\n");
                break;
            case 5:
                printf("Friday\n");
                break;
            case 6:
                printf("Saturday\n");
                break;
        }
        break;

    case 2:
        printf("From(in DD/MM/YYYY): ");
        scanf("%d/%d/%d", &d1, &m1, &y1);
        printf("To(in DD/MM/YYYY): ");
        scanf("%d/%d/%d", &d2, &m2, &y2);
        printf("%d days", diffInDates(d1, m1, y1, d2, m2, y2));
        break;
    default:
        printf("Invalid Choice\n");
        break;
    }
    return 0;
}

/*Calculator*/

// Function to perform basic arithmetic operations
double performOperation(double num1, double num2, char operator) {
    switch(operator) {
        case '+':
            return num1 + num2;
        case '-':
            return num1 - num2;
        case '*':
            return num1 * num2;
        case '/':
            if (num2 != 0)
                return num1 / num2;
            else {
                printf("Error! Division by zero.\n");
                exit(EXIT_FAILURE);
            }
        default:
            printf("Error! Unsupported operator.\n");
            exit(EXIT_FAILURE);
    }
}

// Function to check precedence of operators
int precedence(char op) {
    if(op == '+' || op == '-')
        return 1;
    if(op == '*' || op == '/')
        return 2;
    return 0;
}

// Function to evaluate the expression using the Shunting-yard algorithm
double evaluateExpression(const char *expression) {
    int index = 0; // Initialize the index to 0
    double numStack[100]; // Stack to hold numbers
    char opStack[100]; // Stack to hold operators
    int numTop = -1; // Index of the top element in the number stack
    int opTop = -1; // Index of the top element in the operator stack
    bool prevWasOperator = false; // Flag to track if the previous character was an operator
    
    while (expression[index] != '\0') {
        if (expression[index] >= '0' && expression[index] <= '9') {
            double num = 0; // Initialize the number to 0
            // Parse the number until a non-digit character is encountered
            while (expression[index] >= '0' && expression[index] <= '9') {
                num = num * 10 + (expression[index] - '0'); // Update the number
                index++; // Move to the next character
            }
            numStack[++numTop] = num; // Push the number onto the number stack
            index--; // Decrement index to handle the case where the loop advances it beyond the number
            prevWasOperator = false; // Reset the flag
        } else if (expression[index] == '(') {
            opStack[++opTop] = '('; // Push '(' onto the operator stack
            prevWasOperator = false; // Reset the flag
        } else if (expression[index] == ')') {
            while (opTop != -1 && opStack[opTop] != '(') {
                double num2 = numStack[numTop--];
                double num1 = numStack[numTop--];
                char op = opStack[opTop--];
                numStack[++numTop] = performOperation(num1, num2, op); // Perform the operation
            }
            opTop--; // Discard '('
            prevWasOperator = false; // Reset the flag
        } else if (expression[index] == '+' || expression[index] == '-' || expression[index] == '*' || expression[index] == '/') {
            if (prevWasOperator) {
                printf("syntax error.\n");
                exit(EXIT_FAILURE);
            }
            while (opTop != -1 && precedence(opStack[opTop]) >= precedence(expression[index])) {
                double num2 = numStack[numTop--];
                double num1 = numStack[numTop--];
                char op = opStack[opTop--];
                numStack[++numTop] = performOperation(num1, num2, op); // Perform the operation
            }
            opStack[++opTop] = expression[index]; // Push the operator onto the operator stack
            prevWasOperator = true; // Set the flag
        } else if (expression[index] == '^') {
            printf("Error! Power operator (^) is not supported.\n");
            exit(EXIT_FAILURE);
        }
        index++; // Move to the next character
    }

    while (opTop != -1) {
        double num2 = numStack[numTop--];
        double num1 = numStack[numTop--];
        char op = opStack[opTop--];
        numStack[++numTop] = performOperation(num1, num2, op); // Perform the operation
    }

    return numStack[numTop]; // Return the result
}

int mainCalculator() {
    char expression[100]; // Declare an array to store the expression
    printf("WELCOME TO CALCULATOR!!\n");
    printf("Use parentheses if needed\n");
    printf("Enter the expression: ");
    fflush(stdin);
    fgets(expression, sizeof(expression), stdin); // Read the expression from the user

    double result = evaluateExpression(expression); // Evaluate the expression

    printf("Result: %.2lf\n", result); // Print the result

    return 0;
}

/*Dice Game*/

// Function to generate a random number between 1 and 6
int rollDice() {
    return rand() % 6 + 1;
}
//declaring variable to calculate total number of games played
int tcount;
int mainDiceGame() {
    int dice1, dice2, prediction, sum, level, maxSum;
    int count1 = 0, count2 = 0, count3 = 0;

    srand(time(NULL));
   
    printf("Welcome to the Dice Game!\n");
    printf("   **let's start**     \n");
//if invalid choice is entered the game starts from beginning
start:    

 while (1) {
    printf("Choose a level:\n");
    printf("1. Easy (Sum range: 2-7)\n");
    printf("2. Medium (Sum range: 2-9)\n");
    printf("3. Hard (Sum range: 2-11)\n");
    scanf("%d", &level);

    switch(level) {
        case 1:
            maxSum = 7;
            break;
        case 2:
            maxSum = 9;
            break;
        case 3:
            maxSum = 11;
            break;
        default:
            printf("Invalid choice. please enter valid level.\n");
            goto start;
            return 0;
    }
        printf("Predict the sum of two dice rolls: ");
        scanf("%d", &prediction);
        if (prediction < 2 || prediction > maxSum) {
            printf("Please enter a valid prediction within the specified range.\n");
            continue;
        }
//numbers will be given to the variables dice1 and dice2 from rolldice function
        dice1 = rollDice();
        dice2 = rollDice();
        sum = dice1 + dice2;
        //assigning new number to variables if sum exceeds the range of the entered level.
        while((level==1&&sum>7)||(level==2&&sum>9)||(level==3&&sum>11))
        {
        if((level==1&&sum>7)||(level==2&&sum>9)||(level==3&&sum>11))
        {
        dice1 = rollDice();
        dice2 = rollDice();
        sum = dice1 + dice2;
        }
        }
        printf("Dice 1: %d, Dice 2: %d\n", dice1, dice2);
        printf("Sum: %d\n", sum);
//to check whether sum and predictions are equal or not
        if (sum == prediction) {
            printf("Congratulations! You guessed correctly.\n");
            if (sum <= 7)
                count1++;
            else if (sum <= 9)
                count2++;
            else
                count3++;
        } else {
            printf("Sorry, incorrect guess.\n");
        }

        printf("Do you want to play again? (1 for Yes / 0 for No): ");
        
        int playAgain;
        scanf("%d", &playAgain);
        tcount++;
        //to display the number of times the player played and won in each level if player wants to end the game
        if (!playAgain) {
        
            printf("Thank you for playing!\n");
            printf("You played %d games\n",tcount+1);
            break;
        }
    }

    return 0;
}

/*Number Game*/

// Function to calculate points based on the attempt and difficulty level
int calculate_points(int attempt, int lower, int upper) {
    if (upper - lower + 1 <= 9) { // Easy
        if (attempt == 1) {
            return 20;
        } else if (attempt >= 2 && attempt <= 4) {
            return 10;
        } else if (attempt >= 5 && attempt <= 10) {
            return 5;
        } else {
            return 0;
        }
    } else if (upper - lower + 1 <= 99) { // Medium
        if (attempt <= 3) {
            return 20;
        } else if (attempt <= 8) {
            return 10;
        } else if (attempt <= 18) {
            return 5;
        } else if (attempt <= 40) {
            return 3;
        } else {
            return 0;
        }
    } else { // Hard
        if (attempt <= 5) {
            return 20;
        } else if (attempt <= 15) {
            return 10;
        } else if (attempt <= 35) {
            return 5;
        } else {
            return 0;
        }
    }
}

// Function to play the game for the specified range
int play_game(int lower, int upper, int round) {
    srand(time(0)); // Seed for generating random numbers
    int target_number = rand() % (upper - lower + 1) + lower; // Generate a random number in the specified range
    int attempt = 0; // Initialize attempt counter
    int total_points = 0; // Initialize total points earned in this round

    printf("\n--- Round %d ---\n", round);
    printf("Welcome to the Number Guessing Game!\n");
    printf("Guess a number between %d and %d.\n", lower, upper);
    printf("Points System:\n");

    if (upper - lower + 1 <= 9) { // Easy
        printf("1. For first attempt: 20 points\n");
        printf("2. For 2nd to 4th attempt: 10 points\n");
        printf("3. For 5th to 10th attempt: 5 points\n");
        printf("4. For more than 10 attempts: 0 points\n");
    } else if (upper - lower + 1 <= 99) { // Medium
        printf("1. For first 3 tries: 20 points\n");
        printf("2. For next 5 tries: 10 points\n");
        printf("3. For next 10 tries: 5 points\n");
        printf("4. For next 22 tries: 3 points\n");
        printf("5. For further number of tries: 0 points\n");
    } else { // Hard
        printf("1. For first 5 tries: 20 points\n");
        printf("2. For next 10 tries: 10 points\n");
        printf("3. For next 20 tries: 5 points\n");
        printf("4. For more than 35 tries: 0 points\n");
    }

    while (1) {
        int guess;
        printf("Enter your guess (or '0' to quit): ");
        if (scanf("%d", &guess) != 1) {
            while (getchar() != '\n'); // Clear input buffer
            continue;
        }

        if (guess == 0) {
            printf("Quitting the game.\n");
            printf("Total points earned in round %d: %d\n", round, total_points);
            return total_points; // Return the total points earned in this round
        }

        if (guess < lower || guess > upper) {
            printf("Please enter a valid number in the range %d to %d.\n", lower, upper);
            continue;
        }

        attempt++; // Increment attempt counter

        // Check if the guess is correct
        if (guess == target_number) {
            total_points = calculate_points(attempt, lower, upper);
            printf("Congratulations! You guessed the number %d correctly!\n", target_number);
            printf("You earned %d points in round %d!\n", total_points, round);
            return total_points; // Return the total points earned in this round
        } else if (guess < target_number) {
            printf("Too low! Try a higher number.\n");
        } else {
            printf("Too high! Try a lower number.\n");
        }
    }
}

int mainNumberGuessingGame() {
    printf("Welcome to the Number Guessing Game!\n");
    printf("Choose your difficulty level:\n");
    printf("1. Easy (1-9)\n");
    printf("2. Medium (10-99)\n");
    printf("3. Hard (100-999)\n");

    int choice;
    do {
        printf("Enter your choice (1/2/3): ");
        scanf("%d", &choice);
    } while (choice < 1 || choice > 3);

    int lower, upper;
    switch (choice) {
        case 1:
            lower = 1;
            upper = 9;
            break;
        case 2:
            lower = 10;
            upper = 99;
            break;
        case 3:
            lower = 100;
            upper = 999;
            break;
        default:
            break;
    }

    int total_points = 0; // Initialize total points earned across rounds
    int round = 1; // Initialize round number

    while (1) {
        int round_points = play_game(lower, upper, round);
        if (round_points == 0) {
            break; // If the player chose to quit, exit the loop
        }
        total_points += round_points;
        
        char choice;
        printf("Do you want to continue? (y/n): ");
        scanf(" %c", &choice);
        if (choice != 'y' && choice != 'Y') {
            break;
        }
        
        round++; // Increment round number
    }

    printf("\nTotal points earned: %d\n", total_points);
    printf("Thanks for playing!\n");
    return 0;
}

/*Spaceship Game*/

#define ROAD_WIDTH 20
#define NUM_LANES 5
#define CAR_SYMBOL '>'
#define OBJECT_SYMBOL '#'
#define BORDER_SYMBOL '*'
#define LEFT_KEY 'w'
#define RIGHT_KEY 's'
#define QUIT_KEY 'q'
#define INITIAL_CAR_LANE NUM_LANES / 2
#define OBJECT_SPEED 100 // milliseconds
#define SPEEDUP_INTERVAL 10 // Increase speed every 10 score
#define MAX_SPEEDUP_ITERATIONS 5 // Maximum speed increase iterations
#define CONSTANT_SPEED_TIME 3000 // Constant speed duration in milliseconds

// Structure to represent objects
typedef struct {
    int lane;
    int position;
    bool active;
} Object;

// Function to draw the road with the car and objects
void drawRoad(int carLane, Object object[], int score) {
    system("cls");
    
    // Draw top border
    printf("%c", BORDER_SYMBOL);
    for (int i = 0; i < ROAD_WIDTH; i++)
        printf("%c", BORDER_SYMBOL);
    printf("%c\n", BORDER_SYMBOL);

    // Draw road and objects
    for (int i = 0; i < NUM_LANES; i++) {
        printf("%c", BORDER_SYMBOL); // Draw left border
        for (int j = 0; j < ROAD_WIDTH; j++) {
            if (i == carLane && j == ROAD_WIDTH / 2)
                printf("%c", CAR_SYMBOL); // Draw the car
            else {
                bool objectDrawn = false;
                for (int k = 0; k < NUM_LANES; k++) {
                    if (object[k].active && object[k].lane == i && object[k].position == j) {
                        printf("%c", OBJECT_SYMBOL); // Draw the object
                        objectDrawn = true;
                        break;
                    }
                }
                if (!objectDrawn)
                    printf(" ");
            }
        }
        printf("%c\n", BORDER_SYMBOL); // Draw right border
    }

    // Draw bottom border
    printf("%c", BORDER_SYMBOL);
    for (int i = 0; i < ROAD_WIDTH; i++)
        printf("%c", BORDER_SYMBOL);
    printf("%c\n", BORDER_SYMBOL);

    printf("Score: %d\n", score);
}

// Function to check collision
bool checkCollision(int carLane, Object object[]) {
    for (int i = 0; i < NUM_LANES; i++) {
        if (object[i].active && carLane == object[i].lane && ROAD_WIDTH / 2 == object[i].position)
            return true;
    }
    return false;
}

int mainSpaceshipGame() {
    int carLane = INITIAL_CAR_LANE;
    int score = 0;
    int speed = OBJECT_SPEED;
    int speedupIterations = 0;
    int elapsedTime = 0;
    clock_t startTime = clock();
    Object objects[NUM_LANES];
    char userInput;

    // Initialize objects
    for (int i = 0; i < NUM_LANES; i++) {
        objects[i].active = false;
    }

    do {
        // Calculate elapsed time
        elapsedTime = (clock() - startTime) * 1000 / CLOCKS_PER_SEC;

        // Generate new object
        if (rand() % 10 == 0) {
            int lane = rand() % NUM_LANES;
            if (!objects[lane].active) {
                objects[lane].active = true;
                objects[lane].position = ROAD_WIDTH - 1;
                objects[lane].lane = lane;
            }
        }

        // Move the objects
        for (int i = 0; i < NUM_LANES; i++) {
            if (objects[i].active) {
                objects[i].position--;
                if (objects[i].position < 0) {
                    objects[i].active = false;
                }
            }
        }

        // Check collision
        if (checkCollision(carLane, objects)) {
            printf("\nGame Over! You crashed!\n");
            break;
        }

        // Take user input
        if (_kbhit()) {
            userInput = getch(); // Get a single character input without echoing to the console
            // Move the car according to user input
            if (userInput == LEFT_KEY && carLane > 0)
                carLane--;
            else if (userInput == RIGHT_KEY && carLane < NUM_LANES - 1)
                carLane++;
        }

        // Increase score
        score++;

        // Speed up after a certain interval and limited iterations
        if (score % SPEEDUP_INTERVAL == 0 && speedupIterations < MAX_SPEEDUP_ITERATIONS) {
            speed -= 10;
            speedupIterations++;
        }

        // Set speed to constant after a certain time
        if (elapsedTime >= CONSTANT_SPEED_TIME) {
            speed = OBJECT_SPEED;
        }

        // Draw the road
        drawRoad(carLane, objects, score);

        // Delay to control speed
        Sleep(speed);

    } while (userInput != QUIT_KEY);
    printf("Game over. Press any key to exit.\n");
    int i = 0;
    while(i<5){
        Beep(1000,500);
        sleep(0.5);
        i++;
    }
    getch(); // Wait for user to press any key before exiting

    return 0;
}

/*Wordle Game*/

char words[50][5] = {
    "facet", "tithe", "shank", "equip", "blimp", "steel", "whiny", "louse",
    "broth", "merge", "breed", "voila", "finch", "wrist", "climb", "plait",
    "serum", "frond", "taboo", "force", "realm", "speak", "stung", "mayor",
    "sally", "towel", "risen", "decay", "shade", "lingo", "abide", "spelt",
    "snort", "toxin", "erupt", "since", "local", "heave", "pesky", "grasp",
    "cheer", "early", "clone", "teary", "hunch", "flame", "state", "urban",
    "forty", "image"
};

int numGen()
{
    srand(time(NULL));
    int i = rand() % 50;
    return i;
}

int greenCount(char guess[], char words[][5], int index)
{
    int flag = 0;
    for(int i = 0; i < 5; i++){
        if(guess[i]==words[index][i]){
            flag++;
        }
    }
    return flag;
}

int mainWordle()
{
    fflush(stdin);
    printf("\nWELCOME TO THE WORDLE GAME!!!\n");
    printf("\nRULES :-\n");
    printf("1. You get 6 tries to guess a secret word(5 letters)\n2. ");
    printf("\033[32m");
    printf("Green color");
    printf("\033[37m");
    printf(" indicates that letter is present in the word and is at the correct position\n3. ");
    printf("\033[33m");
    printf("Yellow color");
    printf("\033[37m");
    printf(" indicates that letter is present in the word but is not at the correct position\n");

    printf("\nPRESS ENTER TO CONTINUE.\n");
    getchar();
    system("cls");
    int index = numGen();
    
    for(int attempt = 1; attempt <=6; attempt++){
        char guess[6];
        printf("\nGuess a word of 5 letters(all in small letters): ");
        scanf("%5s", guess);

        for(int j = 0; j < 5; j++){
            if(guess[j]==words[index][j]){
                printf("\033[32m");
                printf("%c", guess[j]);
                printf("\033[37m");
                continue;
            }
            int y = 0;
            for(int k = 0; k < 5; k++){
                if((guess[j]==words[index][k])&&(j!=k)){
                    printf("\033[33m");
                    printf("%c", guess[j]);
                    printf("\033[37m");
                    y = 1;
                    break;
                }
            }
            if(y==0){
                printf("\033[37m");
                printf("%c", guess[j]);
            }

        }
        printf("\n");
        
        if(greenCount(guess, words, index) == 5){
            printf("\n\tCongratulations!! You won.\n");
            return 0;
        }
        printf("You have %d attempts left.\n", 6 - attempt);
        fflush(stdin);
    }
    printf("\nYou lost, better luck next time!\n");
    printf("\nThe word was %5s\n", words[index]);
    return 0;
}

int main()
{
    int y;
    printf("\n1. Phone book\n");
    printf("2. Clock\n");
    printf("3. Calendar\n");
    printf("4. Calculator\n");
    printf("5. Dice Game\n");
    printf("6. Number Guessing Game\n");
    printf("7. Spaceship Game\n");
    printf("8. Wordle Game\n");
    printf("9. Turn off phone\n");
    printf("\nEnter a choice: ");
    scanf("%d", &y);
    switch(y)
    {
        case 1:
            mainPhoneBook();
            break;
        case 2:
            mainClock();
            break;
        case 3:
            mainCalendar();
            break;
        case 4:
            mainCalculator();
            break;
        case 5:
            mainDiceGame();
            break;
        case 6:
            mainNumberGuessingGame();
            break;
        case 7:
            mainSpaceshipGame();
            break;
        case 8: 
            mainWordle();
            break;
        case 9:
            return 0;
        default:
            break;
    }
    return 0; 
}