#pragma once
#include <iostream>
#include "clsScreen.h"
#include "clsQuestion.h"
#include "clsInputValidate.h"
#include "Global.h"
#include "clsUtil.h"

class clsHistoryQuestionsScreen : protected clsScreen
{
   static void _PlayRound(clsQuestion Question)
    {
        Player.ResetAttempts();
        static int Counter = 1;

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

    static void GenerateHistoryQuestion()
    {
        vector <clsQuestion> vHistoryQuestions = clsQuestion::GetQuestionList("HistoryQuestions.txt");
   
        char answer = 'n';
        do
        {
            clsQuestion Question = vHistoryQuestions[clsUtil::RandomNumber(0,vHistoryQuestions.size()-1)];
            _PlayRound(Question);
            answer = clsInputValidate::ReadChar("Do you want more questions? [Y/N]? ");
        
        } while (answer == 'Y' || answer == 'y'); 
        
    }

    public:
    static void ShowHistoryQuestionsScreen()
    {
        DrawScreenHeader("\tHistory Questions Screen");
        GenerateHistoryQuestion();
        ShowFinalResultScreen(Player.GetCorrectAnswers(),Player.GetWrongAnswers(),Player.GetSkippedQuestions(),Player.GetOverallPerformance()); 
        Player.ResetInfo();
    }
};