#pragma once
#include <iostream>
#include "clsScreen.h"
#include "clsQuestion.h"
#include "clsInputValidate.h"

class clsHistoryQuestionsScreen : protected clsScreen
{

    static void GenerateHistoryQuestion()
    {
    vector <clsQuestion> vHistoryQuestions = clsQuestion::GetQuestionList("HistoryQuestions.txt");
    int Counter = 1;

    for (clsQuestion &Question : vHistoryQuestions)
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
    static void ShowHistoryQuestionsScreen()
    {
        DrawScreenHeader("\tHistory Questions Screen");
        GenerateHistoryQuestion();
    }
};