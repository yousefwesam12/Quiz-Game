#pragma once
#include <iostream>
#include "clsScreen.h"
#include "clsQuestion.h"
#include "clsInputValidate.h"

class clsSportsQuestionsScreen : protected clsScreen
{

    static void GenerateSportsQuestion()
    {
    vector <clsQuestion> vSportsQuestions = clsQuestion::GetQuestionList("SportsQuestions.txt");
    int Counter = 1;

    for (clsQuestion &Question : vSportsQuestions)
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
    static void ShowSportsQuestionsScreen()
    {
        DrawScreenHeader("\tSports Questions Screen");
        GenerateSportsQuestion();
    }
};