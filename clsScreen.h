#pragma once
#include <iostream>
#include <iomanip>
using namespace std;

class clsScreen
{

    protected:
    static void ClearScreen()
    {
        system("clear");
    }
    static void DrawScreenHeader(string Title,string SubTitle = "")
    {
        cout <<  "\t\t\t\t\t______________________________________";
        cout << "\n\n\t\t\t\t\t" << " " << Title;

        if (SubTitle != "")
        {
            cout << "\n" << "\t\t\t\t\t" << SubTitle;
        }
        cout << "\n" << "\t\t\t\t\t" << "______________________________________\n\n";
    }
    static void DrawQuestionHeader(string Question,short QuestionNum)
    {
        cout << "\n----------------------------------------------------------";
        cout << "\n" << "Question No." << QuestionNum << " : " << Question;
        cout << "\n----------------------------------------------------------\n";
    }
    static void ShowWrongAnswerMessage()
    {
         cout << "\n" <<"Your answer is not right , try again: ";
    }
    static void ShowCorrectAnswerMessage()
    {
         cout << "\n" << "Right Answer, Go on !!\n";
    }
    
  
};  