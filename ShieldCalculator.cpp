#include <iostream>
#include <cmath>
#include <string>
#include <limits>
#include <random>
#include <ctime>
#include <cstdlib>

using namespace std;


struct stShieldNumbers
{
    int ShieldNum = 0;
    int HealShieldPower = 0;
    int MoonStone = 0;
    int FinalNumberOfShield = 0;
    int FinalNumberOfShieldWithMoonStone = 0;
};


int GetShieldNum(stShieldNumbers ShieldPower, const string Message)
{
    int Num1 = 0;
    cout << "\n" << Message << ":\n";
    cin >> Num1;

    return Num1;
}


int GetShieldNumAfterPower(stShieldNumbers ShieldPower)
{
    int PercentOfAShield = 0;
    PercentOfAShield = ShieldPower.ShieldNum * ShieldPower.HealShieldPower / 100;

    return PercentOfAShield + ShieldPower.ShieldNum;
}


stShieldNumbers RunCalculations(stShieldNumbers &ShieldPower)
{
    ShieldPower.FinalNumberOfShield = GetShieldNumAfterPower(ShieldPower);
    ShieldPower.FinalNumberOfShieldWithMoonStone = ShieldPower.FinalNumberOfShield * ShieldPower.MoonStone / 100;

    return ShieldPower;
}


void MainCalculation(stShieldNumbers& ShieldPower)
{
    ShieldPower.ShieldNum = GetShieldNum(ShieldPower, "\033[34m Enter the number of the shield \033[0m ");
    ShieldPower.HealShieldPower = GetShieldNum(ShieldPower, "\033[32m Enter the number of shield/healpower (without the percentage symbol)\033[0m");
    ShieldPower.MoonStone = 35;

    RunCalculations(ShieldPower);
}


void PrintResults(stShieldNumbers ShieldPower)
{
    cout << "\033[36m " << "\nShield without moonstone: " << "\033[0m " << ShieldPower.FinalNumberOfShield << endl;
    cout << "\033[36m " << "\nShield with moonstone: " << "\033[0m " << ShieldPower.FinalNumberOfShieldWithMoonStone + ShieldPower.FinalNumberOfShield << endl;
}


int main()
{
    stShieldNumbers ShieldPower;
    MainCalculation(ShieldPower);

    PrintResults(ShieldPower);
    return 0;
}