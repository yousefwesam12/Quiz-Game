#pragma once
#include <iostream>
#include "clsScreen.h"
#include "clsQuestion.h"
#include "clsInputValidate.h"
#include "Global.h"

class clsScienceQuestionsScreen : protected clsScreen
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

    static void GenerateScienceQuestion()
    {
        vector <clsQuestion> vScienceQuestions = clsQuestion::GetQuestionList("ScienceQuestions.txt");
   
        char answer = 'n';
        do
        {
            clsQuestion Question = vScienceQuestions[clsUtil::RandomNumber(0,vScienceQuestions.size()-1)];
            _PlayRound(Question);
            answer = clsInputValidate::ReadChar("Do you want more questions? [Y/N]? ");
        
        } while (answer == 'Y' || answer == 'y'); 
        
    }

    public:
    static void ShowScienceQuestionsScreen()
    {
        DrawScreenHeader("\tScience Questions Screen");
        GenerateScienceQuestion();
        ShowFinalResultScreen(Player.GetCorrectAnswers(),Player.GetWrongAnswers(),Player.GetSkippedQuestions(),Player.GetOverallPerformance()); 
        Player.ResetInfo();
    }
};