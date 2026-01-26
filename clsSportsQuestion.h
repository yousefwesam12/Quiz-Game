#pragma once
#include <iostream>
#include "clsScreen.h"
#include "clsQuestion.h"
#include "Global.h"

class clsSportsQuestionsScreen : protected clsScreen
{
    static void _PlayRound(clsQuestion Question)
    {
        Player.ResetAttempts();
        int Counter = 0;
        ++Counter;

        DrawQuestionHeader(Question.GetQuestion(),Counter);
        ShowChociesForTheQuestion(Question.GetQuestionChoices());

        do
        {

            Player.SetPlayerAnswer(clsInputValidate::ReadQuizChoices());
            Player.IncreasePlayerAttemptsByOne();

            if(Question.IsCorrectAnswer(Player.GetPlayerAnswer()))
            {
                ShowCorrectAnswerMessage();
                Player.IncreaseCorrectAnswersByOne();
                break;
            }
    
            ShowWrongAnswerMessage();

            if(!Player.IsHintAsked() && Player.GetPlayerAttempts() == 1)
            {
                char answer = clsInputValidate::ReadChar("Do you want to see a hint? [Y/N]? ");

                if(tolower(answer) == 'y')
                {
                    ShowHintForAQuestion(Question.GetQuestionHint());
                    Player.SetHintAsked(true);
                }
                  
            }

            if(Player.IsMaxAttempts())
            {
                ShowMaxAttemptsMessage(Question.GetQuestionAnswer());
                Player.IncreaseWrongAnswersByOne();
                break;
            }

            ShowAttemptsAvaliable(Player.GetPlayerAttempts());

        } while (true);
        
        cout << "----------------------------------------------------------\n";
        Counter++;
        return;
    
}

    static void GenerateSportsQuestion()
    {
        vector <clsQuestion> vSportsQuestions = clsQuestion::GetQuestionList("SportsQuestions.txt");
   
        char answer = 'n';
        do
        {
            clsQuestion Question = vSportsQuestions[clsUtil::RandomNumber(0,vSportsQuestions.size()-1)];
            _PlayRound(Question);
            answer = clsInputValidate::ReadChar("Do you want more questions? [Y/N]? ");
        
        } while (answer == 'Y' || answer == 'y'); 
        
    }

    public:
    static void ShowSportsQuestionsScreen()
    {
        DrawScreenHeader("\tSports Questions Screen");
        GenerateSportsQuestion();
        ShowFinalResultScreen(Player.GetCorrectAnswers(),Player.GetWrongAnswers(),Player.GetSkippedQuestions(),Player.GetOverallPerformance()); 
        Player.ResetInfo();
    }
};