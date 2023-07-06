// Fill out your copyright notice in the Description page of Project Settings.
#include "MyTestClass.h"

MyTestClass::MyTestClass()
{
}

MyTestClass::~MyTestClass()
{
}

int MyTestClass::GetRandom(){
    return rand.randInt(100);
}