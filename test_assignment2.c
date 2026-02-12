#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "assignment2.h"
bool test_q1_1()  {
const char* filename = "passwords.db";
const char* user1 = "bob2002";
const char* pass1 = "12345678";
const char* user2 = "Mary";
const char* pass2 = "vErY@sEcrE_t";
int ans1 = add_user_password(filename, user1, pass1); // new user: return 1
int ans2 = add_user_password(filename, user2, pass2); // new user: return 1
int ans3 = add_user_password(filename, user2, "wrong guess"); // existing user: return 0
if (ans1==1 && ans2==1 && ans3==0)  {
printf("Q1-1 ok\n");
return true;
  }
else  {
printf("Q1-1 ERROR\n");
return false;
  }
}
bool test_q1_2()  {
const char* no_filename = "no_file.xyz";
const char* filename1 = "my_passwords.txt";
const char* user1 = "bob2002";
const char* pass1 = "12345678";
int ans1 = add_user_password(filename1, user1, pass1); // return 1
int ans2 = check_user_password(filename1, user1, pass1); // return 1
int ans3 = check_user_password(no_filename, "user", "pass"); // no file: return -1
if (ans1==1 && ans2==1 && ans3==-1)  {
printf("Q1-2 ok\n");
return true;
  }
else  {
printf("Q1-2 ERROR\n");
return false;
  }
}
bool test_q1_3()  {
const char* filename1 = "very_secret1.db";
const char* filename2 = "very_secret2.db";
const char* user1 = "CryptoKing";
const char* pass1 = "--to.the.moon.--\nrocket\nrocket\ndiamond hands";
const char* user2 = "bob2002";
const char* pass2 = "12345678";
const char* user3 = "rocket";
const char* pass3 = "$c13nTi$t";
int ans1 = add_user_password(filename1, user1, pass1); // new user: return 1
int ans2 = add_user_password(filename2, user2, pass2); // new user: return 1
int ans3 = check_user_password(filename1, user3, pass3); // user not found: return -2
int ans4 = add_user_password(filename1, user3, pass3); // new user: return 1
int ans5 = check_user_password(filename1, user3, pass2); // user in filename1 but wrong password: return -3
int ans6 = check_user_password(filename2, user3, pass3); // user not found in filename2: return -2
int ans7 = check_user_password(filename1, user3, pass3); // found user/pass: return 1
int ans8 = check_user_password(filename2, user2, pass2); // found user/pass: return 1
int ans9 = check_user_password("wrong_file_name.txt", user1, pass1); // file not found: return -1
if (ans1==1 && ans2==1 && ans3==-2 && ans4==1 &&
ans5==-3 && ans6==-2 && ans7==1 && ans8==1 && ans9==-1)  {
printf("Q1-3 ok\n");
return true;
  }
else  {
printf("Q1-3 ERROR\n");
return false;
  }
} 

bool test_q2_1()  {
  int ans1 = fib3_p(1,7);
  int ans2 = fib3_p(2,17);
  if (ans1 == 1 && ans2 == 2)   {
    printf("Q2-1 ok\n");
    return true;
  }
  else  {
    printf("Q2-1 ERROR\n");
    return false;
  }
}

bool test_q2_2()  {
  int ans1 = fib3_p(15,3);
  int ans2 = fib3_p(5,17);
  int ans3 = fib3_p(1000001,29);
  if (ans1==2 && ans2==11 && ans3==16)  {
    printf("Q2-2 ok\n");
    return true;
  }
  else  {
    printf("Q2-2 ERROR\n");
    return false;
  }
}



bool test_q3a_1()  {
  char* state1 = "---";
  char* sol_1  = "---";
  char* state2 = "--**----**-";
  char* sol_2  = "--**----**-";

  char* next1 = evolve(state1);
  char* next2 = evolve(state2);
  
  bool ok = next1 && strcmp(next1,sol_1)==0 &&
            next2 && strcmp(next2,sol_2)==0;
  if (next1)
    free(next1);
  if (next2)
    free(next2);

  if (ok)  {
    printf("Q3a-1 ok\n");
    return true;
  }
  else  {
    printf("Q3a-1 ERROR\n");
    return false;
  }
}

bool test_q3a_2()  {
  char* state1 = "---*---*---*-";
  char* sol_1  = "----*-----*--";
  char* state2 = "-*-*-*-*---*--*--*-";
  char* sol_2  = "--*---*-----*---*--";

  char* next1 = evolve(state1);
  char* next2 = evolve(state2);
  

  bool ok = next1 && strcmp(next1,sol_1)==0 &&
            next2 && strcmp(next2,sol_2)==0;
  if (next1)
    free(next1);
  if (next2)
    free(next2);

  if (ok)  {
    printf("Q3a-2 ok\n");
    return true;
  }
  else  {
    printf("Q3a-2 ERROR\n");
    return false;
  }
}


bool test_q3b_1()  {
  char* state1 = "---";
  char* sol_1  = "---";
  char* state2 = "--**---*--*";
  char* sol_2  = "--**----**-";

  char* last1 = last_state(state1);
  char* last2 = last_state(state2);
  
  bool ok = last1 && strcmp(last1,sol_1)==0 &&
            last2 && strcmp(last2,sol_2)==0;
  if (last1)
    free(last1);
  if (last2)
    free(last2);

  if (ok)  {
    printf("Q3b-1 ok\n");
    return true;
  }
  else  {
    printf("Q3b-1 ERROR\n");
    return false;
  }
}


bool test_q3b_2()  {
  char* state1 = "--*---*-*----";
  char* sol_1  = "---*---------";
  char* state2 = "--*--*------*-*-*-*----*--*-----------------*---*-*----*-";
  char* sol_2  = "---**-------------------**-----------------------**------";

  char* last1 = last_state(state1);
  char* last2 = last_state(state2);
  
  bool ok = last1 && strcmp(last1,sol_1)==0 &&
            last2 && strcmp(last2,sol_2)==0;
  if (last1)
    free(last1);
  if (last2)
    free(last2);

  if (ok)  {
    printf("Q3b-2 ok\n");
    return true;
  }
  else  {
    printf("Q3b-2 ERROR\n");
    return false;
  }
}


// when testing your code, it may be convenient 
// to comment out some of the test cases
// and focus only on the one you are working on right now
int main()  {
 
  // don't forget to delete the files between tests
  test_q1_1();
  test_q1_2();
  test_q1_3();
  
  test_q2_1();
  test_q2_2();
  
  test_q3a_1();
  test_q3a_2();
  
  test_q3b_1();
  test_q3b_2();
  
  return 0;
}