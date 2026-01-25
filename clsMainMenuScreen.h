#include <iostream>
#include "clsScreen.h"
#include "clsInputValidate.h"
#include "clsMathQuestion.h"
#include "clsHistoryQuestion.h"
#include "clsScienceQuestions.h"
#include "clsProgrammingQuestions.h"
#include "clsSportsQuestion.h"

class clsMainMenueScreen : protected clsScreen
{
    
    enum _enMainMenueChoices
    {
        eMath = 1, eHistory = 2, eScience = 3,
        eProgramming = 4, eSports = 5, eExit = 6
    };

    static short _ReadMainQuizChocie()
    {
        short Chocie = 0;
        cout << setw(36) << left << "" << "In which field you want questions? [1 to 6]? ";
        Chocie = clsInputValidate::ReadIntNumberBetween(1,6);
        return Chocie;
    }

    static void _ShowMathQuestionsScreen()
    {
        //cout << "\n" << "Math Questions Screen Will be here..\n";
        clsMathQuestionsScreen::ShowMathQuestionsScreen();
    }

    static void _ShowHistoryQuestionsScreen()
    {
        //cout << "\n" << "History Questions Screen Will be here..\n";
        clsHistoryQuestionsScreen::ShowHistoryQuestionsScreen();
    }
    
    static void _ShowScienceQuestionsScreen()
    {
        //cout << "\n" << "Science Questions Screen Will be here..\n";
        clsScienceQuestionsScreen::ShowScienceQuestionsScreen();
    }
     
    static void _ShowProgrammingQuestionsScreen()
    {
        //cout << "\n" << "Programming Questions Screen Will be here..\n";
        clsProgrammingQuestionsScreen::ShowProgrammingQuestionsScreen();
    }

    static void _ShowSportsQuestionsScreen()
    {
        //cout << "\n" << "Sports Questions Screen Will be here..\n";
        clsSportsQuestionsScreen::ShowSportsQuestionsScreen();
    }
    static void _ShowExitScreen()
    {
        cout << "\n" << "Exit Screen Will be here..\n";
    }

    static void _PerformMainMenueChoice(_enMainMenueChoices MainMenueChoice)
    {
        switch(MainMenueChoice)
        {
            case eMath:
            ClearScreen();
            _ShowMathQuestionsScreen();
            _GoBackToMainMenue();
            break;

            case eHistory:
            ClearScreen();
            _ShowHistoryQuestionsScreen();
            _GoBackToMainMenue();
            break;

            case eScience:
            ClearScreen();
            _ShowScienceQuestionsScreen();
            _GoBackToMainMenue();
            break;

            case eProgramming:
            ClearScreen();
            _ShowProgrammingQuestionsScreen();
            _GoBackToMainMenue();
            break;

            case eSports:
            ClearScreen();
            _ShowSportsQuestionsScreen();
            _GoBackToMainMenue();
            break;

            case eExit:
            ClearScreen();
            _ShowExitScreen();
            _GoBackToMainMenue();
            break;
        }
    }

    static void _GoBackToMainMenue()
    {
        cout << "Press any key to go back to main menu...";
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cin.get();
        ClearScreen();
        ShowMainQuizScreen();
    }
    
    public:
    static void ShowMainQuizScreen()
    {
        string Title = "\t\tQ u i z   G a m e";
        cout << setw(38) << left << "" << "=======================================\n";
        cout << setw(38) << left << "" <<  Title << "\n";
        cout << setw(38) << left << "" << "=======================================\n";
        cout << setw(38) << left << "" << "\t[1].Math           [2].History\n";
        cout << setw(38) << left << "" << "\t[3].Science        [4].Programming\n";
        cout << setw(38) << left << "" << "\t[5].Sports         [6].Exit\n";
        cout << setw(38) << left << "" << "=======================================" << endl;
        _PerformMainMenueChoice(_enMainMenueChoices(_ReadMainQuizChocie()));
    }
    
};