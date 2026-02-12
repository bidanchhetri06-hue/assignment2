#ifndef ASSIGNMENT2_H
#define ASSIGNMENT2_H

/* Question 1 */

// The function gets the filename and username/password,
// and adds the pait to the file.
// If the user is not in the file,
// the function adds the pair to the file and returns 1.
// If the user is already in the file,
// the function does not modify the file and returns 0.
// If the file does not exist,
// the function creates a new file with the given name,
// adds the pair to the file, and returns 1.
int add_user_password(const char* file_name,
                    const char* username, const char* password);


// The function gets the filename and username/password,
// and searches the file for them.
// If the username is found and the password matches,
// the function returns 1.
// If the file does not exist , the function returns -1.
// If the username is not found, the function returns -2.
// If the username is found but the password doesn’t match,
// the function returns -3.
int check_user_password(const char* file_name,
                    const char* username, const char* password);


/* Question 2 */

// define fib3_p(0) = 0, fib3_p(1) = 1, fib3_p(2) = 2
// fib3_p(n) = fib3_p(n-1) + fib3_p(n-2) + fib3_p(n-3) (mod p) for all n>=3
// the function gets n>0 and p>2 and returns fib_p(n)
int fib3_p(unsigned int n, unsigned int p);


/* Question 3 */

// the function gets a string representing a state of the game,
// and returns a string representing the next state of the game.
char* evolve(const char* state);


// the function gets a string representing a state of the game,
// and returns a string representing the last state of the game.
char* last_state(const char* state);

#endif
