#pragma once
#include <iostream>
#include <fstream>
#include <vector>
#include "clsString.h"
using namespace std;

class clsQuestion
{
    private:
    short  _QuestionReference;
    string _Question;
    string _QuestionAnswer;
    bool   _IsCorrectAnswer;

    static clsQuestion _ConvertLineToQuestionObject(string Line,string Sep = "#//#")
    {
        vector <string> vQuestion = clsString::Split(Line,Sep);

        return clsQuestion(vQuestion[0],stoi(vQuestion[1]));
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

    static string _GetQuestionAnswer(string AnswersFileName,short QuestionReference)
    {        
        fstream MyFile;
        MyFile.open(AnswersFileName,ios::in);
        string Answer = "";

        if(MyFile.is_open())
        {

            int Counter = 1;

            string Line;

            while(getline(MyFile,Line))
            {
                if(Counter == QuestionReference)
                {
                    Answer = Line;
                }

                Counter++;
            }

            MyFile.close();
        }
        return Answer;

        
    }

    public:
    clsQuestion(string Question,short QuestionReference)
    {
        this->_Question = Question;
        this->_QuestionReference = QuestionReference;
    }
    void SetQuestion(string Question)
    {
        this->_Question = Question;
    }
    string GetQuestion()
    {
        return this->_Question;
    }
    void SetQuestionReference(short QuestionReference)
    {
        this->_QuestionReference =  QuestionReference;
    }
    short GetQuestionReference()
    {
        return this->_QuestionReference;
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
    static string GetQuestionAnswer(string FileName, short QuestionReference)
    {
        return _GetQuestionAnswer(FileName,QuestionReference);
    }
    

};