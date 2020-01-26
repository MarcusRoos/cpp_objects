#include "Prototypes.h"

using std::cout;
using std::cin;
using std::endl;

void assignmentFunction() {
    cout << "Enter the size of the array." << endl;
    size_t size;
    cin >> size;
    int *arrPtr = new int[size];

    std::default_random_engine gen(static_cast<unsigned>(time(0)));
    std::uniform_real_distribution<double> rd(-5000,5000);

    size_t counter=0; // Counter to not print more than 200 per page.
    for(size_t i=0; i<size; i++) { // index loop to fill array
        arrPtr[i] = rd(gen); // Fills array with random numbers
        cout << arrPtr[i] << endl;
        counter++; // Increase counter for every iteration
        if (counter==200) { // If counter == 200, print and pause
            std::string txt = std::to_string(size-(i+1));
            pauseFunction("There are " + txt +
             " numbers left, press any key to show the next 200 numbers.");
            counter = 0;
        }
    }

    int* end = arrPtr + size;
    int max = *arrPtr, min = *arrPtr;
    for (int *ia = arrPtr; ia != end; ia++){
        if (*ia > max) {
             max = *ia;
        }
        if (*ia < min){
            min = *ia;
        }

     }


    cout << "Max:" << max << "\n";
    cout << "Min:" << min << "\n";

    delete[] arrPtr;
}

//Help functions below
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