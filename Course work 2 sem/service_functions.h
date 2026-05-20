#pragma once
#include <iostream>

// Цвета текста
#define RESET   "\033[0m"
#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define BLUE    "\033[34m"

// Служебные функции
void separation();
void stream_clear();
void waiting();
void error_detention();
void clear_screen();