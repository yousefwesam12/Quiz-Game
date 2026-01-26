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
        cout << "\n" << "Question No." << QuestionNum << " : \n" << Question;
        cout << "\n----------------------------------------------------------\n";
    }
        
    static void ShowWrongAnswerMessage()
    {
         cout << "\n" <<"Your answer is NOT right , try again: ";
     
    }
    static void ShowCorrectAnswerMessage()
    {
         cout << "\n" << "Right Answer!!\n";
    }
    static void ShowAttemptsAvaliable(int CurrAttempts)
    {
        const int MaxAttempts = 3;
        cout << "\nYou have " << MaxAttempts - CurrAttempts << " attempt(s) avaliable.";

    }
    static void ShowFinalResultScreen(short CorrectAnswers,short WrongAnswers,short SkippedQuestions,string Performance)
    {
        cout << setw(38) << left << "" << "=======================================\n";
        cout << setw(38) << left << "" << " \t\tF i n a l   R e s u l t\n";
        cout << setw(38) << left << "" << "=======================================\n";
        cout << setw(38) << left << "" << "\tCorrect Answers     : " << CorrectAnswers << endl;
        cout << setw(38) << left << "" << "\tWrong Answers       : " << WrongAnswers << endl;
        cout << setw(38) << left << "" << "\tSkipped Questions   : " << SkippedQuestions << endl;
        cout << setw(38) << left << "" << "\tOverall Performance : " << Performance << endl;
        cout << setw(38) << left << "" << "=======================================\n";
    }
    static void ShowMaxAttemptsMessage(string QuestionAnswer)
    {
        cout << "\nYour attempts has ended.";
        cout << "\nThe answer was " << QuestionAnswer << endl;
    }
    static void ShowHintForAQuestion(string Hint)
    {
           cout << "\n" << Hint << endl;
    }
    static void ShowChociesForTheQuestion(string Choices)
    {
        cout << "\n" << Choices << endl;
    }

    
  
};  