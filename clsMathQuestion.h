#pragma once
#include <iostream>
#include "clsScreen.h"
#include "clsQuestion.h"
#include "clsInputValidate.h"
#include "clsPlayer.h"

class clsMathQuestionsScreen : protected clsScreen
{

    static void GenerateMathQuestion()
    {
    vector <clsQuestion> vMathQuestions = clsQuestion::GetQuestionList("MathQuestions.txt");
    int Counter = 1;

    for (clsQuestion &Question : vMathQuestions)
    {
        clsPlayer Player("",0);

        DrawQuestionHeader(Question.GetQuestion(),Counter);

        Player.SetPlayerAnswer(clsInputValidate::ReadString());

        while(!Question.IsCorrectAnswer(clsString::LowerAllString(Player.GetPlayerAnswer())))
        {
            Player.IncreasePlayerAttemptsByOne();

            if(Player.IsMaxAttempts())
            {
                cout << "\nYour attempts has ended.";
                cout << "\nThe answer was " << Question.GetQuestionAnswer() << endl;
                break;
            }

            ShowAttemptsAvaliable(Player.GetPlayerAttempts());
            ShowWrongAnswerMessage();
            Player.SetPlayerAnswer(clsInputValidate::ReadString());
        }

        if(Question.IsCorrectAnswer(clsString::LowerAllString(Player.GetPlayerAnswer())))
        {   
            ShowCorrectAnswerMessage();
        }
        cout << "----------------------------------------------------------\n";

        char answer = clsInputValidate::ReadChar("Do you want more questions? [Y/N]? ");
     
        if(tolower(answer)!='y')
        {
            return;
        }

        Counter++;
        
    }
}

    public:
    static void ShowMathQuestionsScreen()
    {
        DrawScreenHeader("\tMath Questions Screen");
        GenerateMathQuestion();
    }
};