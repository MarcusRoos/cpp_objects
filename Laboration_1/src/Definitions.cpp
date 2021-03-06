#include "Prototypes.h"

using std::cout;
using std::cin;
using std::endl;

void assignmentFunction() {
    cout << "Enter the size of the array." << endl;
    int size;
    bool valid=true; // Bool for value
    do { // Loop to confirm proper input
        cin >> size;
        if (cin.fail() || size<=0) { // If fail, request new input
            cout << "You did not enter a positive int, please retry.\n";
            cin.clear();
            cin.ignore(std::numeric_limits <std::streamsize>::max(), '\n');
        } else
            valid = false;
    } while (valid);
    int *arrPtr = new int[size]; // Assign a pointer of arrays, size per input

    //Random Generator to generate numbers, used to fill array
    std::default_random_engine gen(static_cast<unsigned>(time(nullptr)));
    std::uniform_real_distribution<double> rd(-5000,5000);

    size_t counter=0, row=0; // Counter to not print more than 200 per page.
    bool header=true; // Header, prints once per page

    for(size_t i=0; i<size; i++) { // index loop to fill array
        arrPtr[i] = rd(gen); // Fills array with random numbers
        while (header){ // Formatting
            header = false;
            cout << "Numbers within the array \n";
            for (int k=0; k<80; k++)
                cout << "_";
            cout << "\n";
        }
        if(row<10) { // Formatting
            cout << "|" << std::setw(7) << std::left <<arrPtr[i];
            row++;
            if (row==10) {
            cout << "|\n";
            row = 0;
            }
        }
        counter++; // Increase counter for every iteration
        if (counter==200) { // If counter == 200, print and pause
            std::string txt = std::to_string(size-(i+1));
            pauseFunction("There are " + txt +
             " numbers left, press any key to show the next page of numbers.");
            counter = 0;
            header = true;
            clearScreen(); // Clear console to make it easier to comprehend.
        }
    }

    int* end = arrPtr + size; // Pointer to keep track of size
    int max = *arrPtr, min = *arrPtr, sum=0; // Pointer and sums being declared
    for (int *ia = arrPtr; ia < end; ia++){ // Loop using pointers
        if (*ia > max) { // If ia is bigger than max
             max = *ia; // Assign value that ia is pointing at, to max
        }
        if (*ia < min){ // If ia is bigger than max
            min = *ia; // Assign value that ia is pointing at, to min
        }
        sum += *ia; /* For each iteration, append the value ia is pointing at
        to sum */
     }

    cout << "\nMax:" << max << "\n";
    cout << "Min:" << min << "\n";
    cout << "Sum: " << sum << endl;

    pauseFunction("\nEnd of program, press any key to exit");

    delete[] arrPtr; // Deletes the array, frees up memory
}

/**Help functions below**/
void pauseFunction(const std::string& text){ /* Function used when program
 * should wait for user input before it continues */
    std::cout << text; // Prints function parameter on screen
    std::cin.clear(); // Clear stream
    std::cin.sync(); // Synchronizes the input stream
    std::cin.get(); // Waits for user input before it continues
    std::cin.clear(); // Clear stream once again to remove leftovers
    std::cin.sync(); // Synchronizes the input stream
}

/*Taken from anders-jens Urstad, depending on OS it will use two different
 * methods of clearing the console window.*/

void clearScreen()
{
#if defined (__unix__) || (defined (__APPLE__) && defined (__MACH__))/*If user
 * is on unix system, apple system or mach, use this method*/
    std::cout << "\033[2J\033[1;1H" << std::endl;
#elif _WIN32 // If user is on windows, use this method
    system("cls");
#else // If OS is unknown, print 100 \n's
    std::cout << std::string(100, '\n') << std::endl;
#endif
}