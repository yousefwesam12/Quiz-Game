#pragma once
#include <iostream>
#include "clsScreen.h"
#include "clsQuestion.h"
#include "clsInputValidate.h"

class clsScienceQuestionsScreen : protected clsScreen
{

    static void GenerateScienceQuestion()
    {
    vector <clsQuestion> vScienceQuestions = clsQuestion::GetQuestionList("ScienceQuestions.txt");
    int Counter = 1;

    for (clsQuestion &Question : vScienceQuestions)
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
    static void ShowScienceQuestionsScreen()
    {
        DrawScreenHeader("\tScience Questions Screen");
        GenerateScienceQuestion();
    }
};