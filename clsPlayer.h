#pragma once
#include <iostream>
using namespace std;

class clsPlayer
{

    private:

    enum enOverallPerformance
    {
        eBad = 1, eGood = 2, eExcellent = 3
    };

    char _PlayerAnswer;
    short _PlayerAttempts;
    short _CorrectAnswers = 0;
    short _WrongAnswers = 0;
    short _SkippedQuestions = 0;
    string _OverallPerformance = "";
    enOverallPerformance Performance;
    bool HintAsked = false;

    string _GetOverallPerformanceAsString(enOverallPerformance OverallPerformance)
    {
        switch(OverallPerformance)
        {
            case eBad:
                return "Bad";
                break;

            case eGood:
                return "Good";
                break;

            case eExcellent:
                return "Excellent";
                break;

            default:
                break;
        }
    }   

    public:
    void SetPlayerAnswer(char PlayerAnswer)
    {
        this->_PlayerAnswer = PlayerAnswer;
    }
    char GetPlayerAnswer()
    {
        return this->_PlayerAnswer;
    }
    void SetPlayerAttempts(short PlayerAttempts)
    {
        this->_PlayerAttempts = PlayerAttempts;
    }
    short GetPlayerAttempts()
    {
        return this->_PlayerAttempts;
    }
    short GetCorrectAnswers()
    {
        return this->_CorrectAnswers;
    }
    bool GetHintAsked()
    {
        return HintAsked;
    }
    void SetHintAsked(bool Result)
    {
        this->HintAsked = Result;
    }
    short GetWrongAnswers()
    {
        return this->_WrongAnswers;
    }
    short GetSkippedQuestions()
    {
        return this->_SkippedQuestions;
    }
    string GetOverallPerformance()
    {
        this->Performance = CalculateOverallPerformance();

        return (_OverallPerformance) = _GetOverallPerformanceAsString(this->Performance);
    }
    clsPlayer(char PlayerAnswer, short PlayerAttempts,short CorrectAnswers,short WrongAnswers,short SkippedQuestions,string OverallPerformance,enOverallPerformance Performance)
    {
        this->_PlayerAnswer = PlayerAnswer;
        this->_PlayerAttempts = PlayerAttempts;
        this->_CorrectAnswers =CorrectAnswers;
        this->_WrongAnswers = WrongAnswers;
        this->_SkippedQuestions = SkippedQuestions;
        this->_OverallPerformance = OverallPerformance;
        this->Performance = Performance;
    }
    void IncreasePlayerAttemptsByOne()
    {
        SetPlayerAttempts(GetPlayerAttempts() + 1 );
    }
    void IncreaseCorrectAnswersByOne()
    {
        this->_CorrectAnswers++;
    }
    void IncreaseWrongAnswersByOne()
    {
        this->_WrongAnswers++;
    }
    void IncreaseSkippedQuestionsByOne()
    {
        this->_SkippedQuestions++;
    }
    bool IsMaxAttempts()
    {
        return GetPlayerAttempts() == 3;
    }
    enOverallPerformance CalculateOverallPerformance()
    {
        if(_CorrectAnswers > _WrongAnswers)
        {
            return (Performance = eExcellent);
        }
        if(_CorrectAnswers == _WrongAnswers)
        {
            return (Performance = eGood);
        }
        return (Performance = eBad);
    }
    static clsPlayer GetEmptyPlayer()
    {
        return clsPlayer(' ',0,0,0,0,"",eBad);
    }
    void ResetInfo()
    {
        _CorrectAnswers = 0;
        _WrongAnswers = 0;
        _SkippedQuestions =0;
        _OverallPerformance = "";
        this->HintAsked = false;
    }
    void ResetAttempts()
    {
        SetPlayerAttempts(0);
    }
    bool IsHintAsked() 
    {
        return (this->HintAsked) == true;
    }

};