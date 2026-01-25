#pragma once
#include <iostream>
using namespace std;

class clsPlayer
{

    private:
    string _PlayerAnswer;
    short _PlayerAttempts;


    public:
    void SetPlayerAnswer(string PlayerAnswer)
    {
        this->_PlayerAnswer = PlayerAnswer;
    }
    string GetPlayerAnswer()
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
    clsPlayer(string PlayerAnswer, short PlayerAttempts)
    {
        this->_PlayerAnswer = PlayerAnswer;
        this->_PlayerAttempts = PlayerAttempts;
    }
    void IncreasePlayerAttemptsByOne()
    {
        SetPlayerAttempts(GetPlayerAttempts() + 1 );
    }
    bool IsMaxAttempts()
    {
        return GetPlayerAttempts() == 3;
    }



};