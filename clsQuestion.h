#pragma once
#include <iostream>
#include <fstream>
#include <vector>
#include "clsString.h"
using namespace std;

class clsQuestion
{
    private:
    string _Question;
    string _QuestionAnswer;
    bool   _IsCorrectAnswer;

    static clsQuestion _ConvertLineToQuestionObject(string Line,string Sep = "#//#")
    {
        vector <string> vQuestion = clsString::Split(Line,Sep);

        return clsQuestion(vQuestion[0],vQuestion[1]);
    }

    static vector <clsQuestion> _LoadQuestionsFromTheDatabase(string Filename, string Sep = "#//#")
    {
        fstream MyFile;
        MyFile.open(Filename,ios::in);
        vector <clsQuestion> vQuestions;

        if(MyFile.is_open())
        {   

            string Line = "";

            while(getline(MyFile,Line))
            {   
                vQuestions.push_back(_ConvertLineToQuestionObject(Line));
            }

            MyFile.close();
        }

        return vQuestions;
    }

    public:
    clsQuestion(string Question,string QuestionAnswer)
    {
        this->_Question = Question;
        this->_QuestionAnswer = QuestionAnswer;
    }
    void SetQuestion(string Question)
    {
        this->_Question = Question;
    }
    string GetQuestion()
    {
        return this->_Question;
    }
    void SetQuestionAnswer(string QuestionAnswer)
    {
        this->_QuestionAnswer = QuestionAnswer;
    }
    string GetQuestionAnswer()
    {
        return this->_QuestionAnswer;
    }
    bool IsCorrectAnswer(string Answer)
    {
        _IsCorrectAnswer = (Answer == _QuestionAnswer);
        return _IsCorrectAnswer;
    }

    enum enResult {Wrong = 0,Correct = 1};

    static vector <clsQuestion> GetQuestionList(string FileName)
    {
        return _LoadQuestionsFromTheDatabase(FileName);
    }

};