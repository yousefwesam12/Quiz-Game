#pragma once
#include <iostream>
#include <fstream>
#include <vector>
#include "clsString.h"
#include "clsUtil.h"
#include <string>
using namespace std;

class clsQuestion
{
    private:
    string _Question;
    string _QuestionAnswer;
    bool   _IsCorrectAnswer;
    string _QuestionHint;
    string _QuestionChoices;

    static void _SwapTwoObjects(clsQuestion &Q1,clsQuestion &Q2)
    {
        clsQuestion Temp = Q1;
        Q1 = Q2;
        Q2 = Temp;
    }

    static vector <clsQuestion> _ShuffleQuestionsList(vector <clsQuestion> &vQuestions)
    {
        for(size_t i =0; i<vQuestions.size();i++)
        {
            _SwapTwoObjects(vQuestions[clsUtil::RandomNumber(1,vQuestions.size())-1],vQuestions[clsUtil::RandomNumber(1,vQuestions.size())-1]);
        }
        return vQuestions;
    }

    static clsQuestion _ConvertLineToQuestionObject(string Line,string Sep = "#//#")
    {
        vector <string> vQuestion = clsString::Split(Line,Sep);

        return clsQuestion(vQuestion[0],vQuestion[1],vQuestion[2],vQuestion[3]);
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

        return _ShuffleQuestionsList(vQuestions);
    }

    public:
    clsQuestion(string Question,string Hint,string QuestionChoices,string QuestionAnswer)
    {
        this->_Question = Question;
        this->_QuestionAnswer = QuestionAnswer;
        this->_QuestionHint= Hint;
        this->_QuestionChoices = QuestionChoices;
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
    string GetQuestionHint()
    {
        return this->_QuestionHint;
    }
    string GetQuestionChoices()
    {
        return this->_QuestionChoices;
    }
    
    bool IsCorrectAnswer(char Answer)
    {
        _IsCorrectAnswer = (toupper(Answer) == toupper(_QuestionAnswer[0]));

        return _IsCorrectAnswer;
    }

    enum enResult {Wrong = 0,Correct = 1};

    static vector <clsQuestion> GetQuestionList(string FileName)
    {
        return _LoadQuestionsFromTheDatabase(FileName);
    }

};