#include "model.h"

void s21::Model::resultModel(std::string input, double x) noexcept {
  // Преобразуем многосимвольные лексемы и переворачиваем выражение
  std::string rNotation = convertLexToSym(input, x);
  rNotation = reverseNotation(rNotation);

  // Стек для операндов
  std::stack<double> operands;

  // Создаем поток для разбора выражения
  std::istringstream iss(rNotation);

  // Читаем токены из потока
  while (iss) {
    std::string token;
    iss >> token;

    if (token.empty()) continue;

    // Если токен - число или знак "+" или "-"
    if (isdigit(token[0]) || ((token[0] == '-' || token[0] == '+') &&
                              token.size() > 1 && isdigit(token[1]))) {
      double number = std::stod(token);
      operands.push(number);
    }

    // Обработка функций и операторов
    else {
      double result = 0.0;

      // Обработка математических функций
      if (token == "s") {
        double operand = operands.top();
        operands.pop();
        result = sin(operand);
      }

      else if (token == "c") {
        double operand = operands.top();
        operands.pop();
        result = cos(operand);
      }

      else if (token == "t") {
        double operand = operands.top();
        operands.pop();
        result = tan(operand);
      }

      else if (token == "S") {
        double operand = operands.top();
        operands.pop();
        result = asin(operand);
      }

      else if (token == "C") {
        double operand = operands.top();
        operands.pop();
        result = acos(operand);
      }

      else if (token == "T") {
        double operand = operands.top();
        operands.pop();
        result = atan(operand);
      }

      else if (token == "q") {
        double operand = operands.top();
        operands.pop();
        result = sqrt(operand);
      }

      else if (token == "l") {
        double operand = operands.top();
        operands.pop();
        result = log(operand);
      }

      else if (token == "g") {
        double operand = operands.top();
        operands.pop();
        result = log10(operand);
      }
      // Обработка бинарных операторов
      else {
        double operand2 = operands.top();
        operands.pop();
        double operand1 = operands.top();
        operands.pop();

        switch (token[0]) {
          case '+':
            result = operand1 + operand2;
            break;
          case '-':
            result = operand1 - operand2;
            break;
          case '*':
            result = operand1 * operand2;
            break;
          case '/':
            result = operand1 / operand2;
            break;
          case '^':
            result = pow(operand1, operand2);
            break;
          case '%':
            result = fmod(operand1, operand2);
            break;
        }
      }
      operands.push(result);  // Записываем результат обратно в стек
    }
  }

  data =
      operands.top();  // Сохраняем результат вычислений в приватное поле `data`
}

std::string s21::Model::reverseNotation(std::string input) noexcept {
  std::string reversedNotation;  // Результат в постфиксной записи
  std::stack<char> operators;  // Стек для операторов
  std::unordered_map<char, int> precedence;  // Приоритет операторов

  // Задаем приоритеты операторов
  precedence['+'] = precedence['-'] = 1;
  precedence['*'] = precedence['/'] = precedence['%'] = 2;
  precedence['^'] = 3;
  precedence['s'] = precedence['c'] = precedence['t'] = precedence['S'] =
      precedence['C'] = precedence['T'] = precedence['q'] = precedence['g'] =
          precedence['l'] = 4;

  size_t i = 0;
  while (i < input.size()) {
    char ch = input[i];  // Текущий символ

    // Обработка отрицательных и положительных чисел
    if ((ch == '-' && (i == 0 || input[i - 1] == '(')) ||
        (ch == '+' && (i == 0 || input[i - 1] == '('))) {
      reversedNotation += ch;
      i++;
    }

    // Обработка открывающей скобки
    else if (ch == '(') {
      operators.push(ch);
      i++;
    }

    // Обработка закрывающей скобки
    else if (ch == ')') {
      while (!operators.empty() && operators.top() != '(') {
        reversedNotation += ' ';
        reversedNotation += operators.top();
        operators.pop();
      }
      operators.pop();
      i++;
    }

    // Обработка операторов
    else if (precedence.find(ch) != precedence.end()) {
      while (!operators.empty() && operators.top() != '(' &&
             precedence[ch] <= precedence[operators.top()]) {
        if (!reversedNotation.empty()) {
          reversedNotation += ' ';
        }
        reversedNotation += operators.top();
        operators.pop();
      }
      if (!reversedNotation.empty()) {
        reversedNotation += ' ';
      }
      operators.push(ch);
      i++;
    }

    // Обработка чисел и десятичной точки
    else if (std::isdigit(ch) || ch == '.') {
      std::string number;
      while (i < input.size() && (std::isdigit(input[i]) || input[i] == '.')) {
        number += input[i];
        i++;
      }
      reversedNotation += number;
      reversedNotation += ' ';
    }

    // Пропускаем пробелы и неопознанные символы
    else
      i++;
  }

  // Добавляем оставшиеся операторы из стека
  while (!operators.empty()) {
    reversedNotation += ' ';
    reversedNotation += operators.top();
    operators.pop();
  }

  return reversedNotation;  // Возвращаем выражение в постфиксной записи
}

std::string s21::Model::convertLexToSym(std::string input, double x) noexcept {
  std::string convertNotation;  // Результат преобразования
  std::stringstream xStrStream;  // Поток для преобразования x в строку
  xStrStream << x;
  std::string xStr = xStrStream.str();  // Значение x в строковом формате

  for (size_t i = 0; i < input.size(); ++i) {
    // Если символ 'x', заменяем его значением переменной x
    if (input[i] == 'x') convertNotation += xStr;

    // Проверяем многосимвольные лексемы и заменяем их
    else if (input[i] == 's') {
      if (input[i + 1] == 'i') {
        convertNotation += 's';  // Заменяем 'sin' на 's'
        i += 2;
      } else {
        convertNotation += "q";  // Заменяем другие случаи на 'q'
        i += 3;
      }
    }

    // Заменяем 'cos' на 'c'
    else if (input[i] == 'c') {
      convertNotation += input[i];
      i += 2;
    }

    // Заменяем 'tan' на 't'
    else if (input[i] == 't') {
      convertNotation += input[i];
      i += 2;
    }

    // Заменяем 'asin', 'acos', 'atan' на 'S', 'C', 'T' соответственно
    else if (input[i] == 'a') {
      if (input[i + 1] == 's') {
        convertNotation += 'S';
        i += 3;
      } else if (input[i + 1] == 'c') {
        convertNotation += 'C';
        i += 3;
      } else if (input[i + 1] == 't') {
        convertNotation += 'T';
        i += 3;
      }
    }

    // Заменяем 'log' на 'l', оставляем другие случаи без изменений
    else if (input[i] == 'l') {
      if (input[i + 1] == 'o') {
        convertNotation += 'g';
        i += 2;
      } else {
        convertNotation += 'l';
        i += 1;
      }
    }

    // Добавляем символ в результат без изменений
    else
      convertNotation += input[i];
  }

  return convertNotation;  // Возвращаем преобразованное выражение
}

bool s21::Model::checkInputCorrect(const std::string input) noexcept {
  bool result = true;  // Изначально считаем, что ввод корректен
  int braceCount = 0;  // Счетчик открытых скобок

  for (size_t i = 0; i < input.size(); ++i)
    // Проверка недопустимого положения переменной x
    if (input[i] == 'x' &&
        (std::isdigit(input[i + 1]) || std::isdigit(input[i - 1])))
      result = false;

  std::string convertInput = convertLexToSym(input, 'x');

  // Проверка максимальной длины ввода
  if (input.size() > MAXSIZE) {
    result = false;
  }

  // Проверка недопустимых начальных символов
  if (convertInput[0] == ')' || convertInput[0] == '%' ||
      convertInput[0] == '.' || convertInput[0] == '*' ||
      convertInput[0] == '/' || convertInput[0] == '^') {
    result = false;
  }

  // Проверка недопустимых комбинаций символов
  for (size_t i = 0; i < convertInput.size(); ++i) {
    // Проверка непарных символов
    if (convertInput[i] == '+' && convertInput[i + 1] == '\0') {
      result = false;
    }

    if (convertInput[i] == 'n' && convertInput[i + 1] == '\0') {
      result = false;
    }

    if (convertInput[i] == 's' && convertInput[i + 1] == '\0') {
      result = false;
    }

    if (convertInput[i] == '-' && convertInput[i + 1] == '\0') {
      result = false;
    }

    if (convertInput[i] == 'r' && convertInput[i + 2] == '\0') {
      result = false;
    }

    if (isOperator(convertInput[i]) && convertInput[i + 1] == '\0') {
      result = false;
    }
    // Проверка недопустимого положения операторов
    if (isOperator(convertInput[i]) &&
        (convertInput[i - 1] == '.' || convertInput[i + 1] == '.')) {
      result = false;
    }

    if (isOperator(convertInput[i]) &&
        (isOperator(convertInput[i + 1]) || isOperator(convertInput[i - 1]))) {
      result = false;
    }

    if (isOperator(convertInput[i]) && isOperator(convertInput[i + 1])) {
      result = false;
    }

    if (isUnaryOperator(convertInput[i]) && convertInput[i + 1] != '(') {
      result = false;
    }

    // Проверка недопустимого положения десятичных чисел
    if (std::isdigit(convertInput[i]) && convertInput[i + 1] == '.' &&
        convertInput[i + 2] == '.') {
      result = false;
    }

    if (std::isdigit(convertInput[i]) && convertInput[i + 1] == '.' &&
        convertInput[i - 1] == '.') {
      result = false;
    }

    if (std::isdigit(convertInput[i]) && convertInput[i - 1] == '.' &&
        convertInput[i - 2] == '.') {
      result = false;
    }

    if ((convertInput[i] == '(') &&
        (std::isdigit(convertInput[i - 1]) || convertInput[i + 1] == '.' ||
         convertInput[i - 1] == '.' || convertInput[i - 1] == 'x')) {
      result = false;
    }
    //  Проверка недопустимоого положения скобочек
    if ((convertInput[i] == ')') &&
        (std::isdigit(convertInput[i + 1]) || convertInput[i + 1] == '.' ||
         convertInput[i + 1] == 'x' || convertInput[i + 1] == 'l')) {
      result = false;
      --braceCount;
    }

    if ((std::isdigit(convertInput[i]) || convertInput[i] == 'x' ||
         convertInput[i] == '.') &&
        (convertInput[i + 1] == 's' || convertInput[i + 1] == 'c' ||
         convertInput[i + 1] == 't' || convertInput[i + 1] == 'a')) {
      result = false;
    }
  }

  // Проверка на непарное количество скобок
  if (braceCount != 0) {
    result = false;
  }

  return result;
}

bool s21::Model::validator(std::string input) const noexcept {
  // Проверка, что все символы являются цифрами или точкой
  for (size_t i = 0; i < input.size(); ++i) {
    if (input[i] != '.' && !(std::isdigit(input[i]))) {
      return false;
    }
  }

  // Проверка, что строка не начинается или не заканчивается точкой
  if (input[0] == '.' || input[input.size() - 1] == '.') {
    return false;
  }

  // Проверка, что строка не содержит подряд идущих точек
  for (size_t i = 0; i < input.size(); ++i) {
    if (input[i] == '.' && input[i + 1] == '.') {
      return false;
    }
  }

  // Входная строка представляет корректное число
  return true;
}
