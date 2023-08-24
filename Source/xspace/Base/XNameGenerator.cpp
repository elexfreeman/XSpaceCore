// Fill out your copyright notice in the Description page of Project Settings.


#include "XNameGenerator.h"

FString UXNameGenerator::getRandNumber()
{
	TArray<FString> numList;
	numList.Add("0");
	numList.Add("1");
	numList.Add("2");
	numList.Add("3");
	numList.Add("4");
	numList.Add("5");
	numList.Add("6");
	numList.Add("7");
	numList.Add("8");
	numList.Add("9");

	return numList[FMath::RandRange(0, numList.Num() - 1)];
}

FString UXNameGenerator::getRandChar()
{
	TArray<FString> charList;
	charList.Add("A");
	charList.Add("B");
	charList.Add("C");
	charList.Add("D");
	charList.Add("E");
	charList.Add("F");
	charList.Add("G");
	charList.Add("H");
	charList.Add("J");
	charList.Add("K");
	charList.Add("L");
	charList.Add("N");
	charList.Add("M");
	charList.Add("O");
	charList.Add("P");
	charList.Add("Q");
	charList.Add("A");
	charList.Add("S");
	charList.Add("T");
	charList.Add("V");
	charList.Add("W");
	charList.Add("X");
	charList.Add("Y");
	charList.Add("Z");

	return charList[FMath::RandRange(0, charList.Num() - 1)];
}

FString UXNameGenerator::generate(FString _startStr)
{
	FString delimiter = TEXT("-");

	FString out  = _startStr
		+ this->getRandChar()
		+ this->getRandChar()
		+ this->getRandChar()
		+ delimiter
		+ this->getRandNumber()
		+ this->getRandNumber()
		+ this->getRandNumber()
		+ this->getRandNumber();

	this->existNameList.Add(out);

	return out;
}
