#include <iostream>
#include <fstream>
#include "clsMainMenuScreen.h"
#include "clsQuestion.h"
#include "clsInputValidate.h"
using namespace std;


int main()
{
    //  ---------------------------------------
    //            Math Questions Screen 
    //  ---------------------------------------
    //   Question No.1 : What is the result of adding 2 to 5? 
    //   if correct?     Right Answer, Go on!! 
    //   if not correct? Your answer is not right, try again! 
    //   Do you want More Questions? Y/N?
    //   if Yes? Question No.2 : .. and so on.
    //   else? go back to main menue.

    clsMainMenueScreen::ShowMainQuizScreen();
    
}