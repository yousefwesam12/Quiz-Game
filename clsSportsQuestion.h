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
        string PlayerAnswer = "";

        DrawQuestionHeader(Question.GetQuestion(),Counter);

        PlayerAnswer = clsInputValidate::ReadString();

        while(!Question.IsCorrectAnswer(clsString::LowerAllString(PlayerAnswer)))
        {
            ShowWrongAnswerMessage();
            PlayerAnswer = clsInputValidate::ReadString();
        }

        ShowCorrectAnswerMessage();
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