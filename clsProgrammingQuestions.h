#pragma once
#include <iostream>
#include "clsScreen.h"
#include "clsQuestion.h"
#include "clsInputValidate.h"
#include "clsString.h"

class clsProgrammingQuestionsScreen : protected clsScreen
{

    static void GenerateProgrammingQuestion()
    {
    vector <clsQuestion> vProgrammingQuestions = clsQuestion::GetQuestionList("ProgrammingQuestions.txt");
    int Counter = 1;

    for (clsQuestion &Question : vProgrammingQuestions)
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
    static void ShowProgrammingQuestionsScreen()
    {
        DrawScreenHeader("\tProgramming Questions Screen");
        GenerateProgrammingQuestion();
    }
};