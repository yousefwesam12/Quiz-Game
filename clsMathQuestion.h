#pragma once
#include <iostream>
#include "clsScreen.h"
#include "clsQuestion.h"
#include "clsInputValidate.h"

class clsMathQuestionsScreen : protected clsScreen
{

    static void GenerateMathQuestion()
    {
    vector <clsQuestion> vMathQuestions = clsQuestion::GetQuestionList("MathQuestions.txt");
    int Counter = 1;

    for (clsQuestion &Question : vMathQuestions)
    {
        string PlayerAnswer = "";

        Question.SetQuestionAnswer(clsQuestion::GetQuestionAnswer("MathAnswers.txt",Question.GetQuestionReference()));

        DrawQuestionHeader(Question.GetQuestion(),Counter);

        PlayerAnswer = clsInputValidate::ReadString();

        while(!Question.IsCorrectAnswer(PlayerAnswer))
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
    static void ShowMathQuestionsScreen()
    {
        DrawScreenHeader("\tMath Questions Screen");
        GenerateMathQuestion();
    }
};