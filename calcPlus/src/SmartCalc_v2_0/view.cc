#include "view.h"

#include "./ui_view.h"

s21::view::view(QWidget *parent) : QMainWindow(parent), ui(new Ui::view) {
  ui->setupUi(this);
}

s21::view::~view() { delete ui; }

void s21::view::concat(QString str) const noexcept {
  // Получение текущего содержимого текстового поля
  QString text = ui->lineEdit->text();

  // Проверка на случай, если текущая строка содержит только одну цифру '0'
  // и добавляемый символ не является точкой '.'
  if (static_cast<int>(text.length()) == 1 &&
      *text.toLocal8Bit().constData() == '0' &&
      *str.toLocal8Bit().constData() != '.')
    ui->lineEdit->clear();

  // Добавление символа к текущему содержимому строки
  ui->lineEdit->setText(ui->lineEdit->text() + str);
}

void s21::view::on_pushButton_C_clicked() const noexcept {
  ui->lineEdit->clear();
}

void s21::view::on_pushButton_sign_clicked() const noexcept {
  double res = 0.;
  QString tmp;
  if (ui->pushButton_sign->text() == "+/-") {
    res = (ui->lineEdit->text()).toDouble();
    res *= -1;
    tmp = QString::number(res, 'g', 15);
  }
  ui->lineEdit->setText(tmp);
}

void s21::view::on_pushButton_result_clicked() const noexcept {
  if (ui->lineEdit->text() != "" && ui->lineEdit->text() != "ERROR!") {
    std::string str = ui->lineEdit->text().toStdString();
    QString str_x = ui->lineEdit_value->text();
    double x = str_x.toDouble();

    if (controller->checkInputCorrect(str)) {
      double res = controller->resultController(str, x);
      QString p = QString::number(res);
      ui->lineEdit->setText(p);
    } else
      ui->lineEdit->setText("ERROR!");

  } else if (ui->lineEdit->text() == "ERROR!")
    ui->lineEdit->clear();
}

void s21::view::on_pushButton_print_clicked() noexcept {
  // Очищаем графики и массивы данных
  ui->widget->clearGraphs();
  x.clear();
  y.clear();

  // Проверка правильности ввода области значения и области определения функции
  if (controller->validatorController(
          ui->lineEdit_xBegin->text().toStdString()) &&
      controller->validatorController(
          ui->lineEdit_xEnd->text().toStdString()) &&
      controller->validatorController(
          ui->lineEdit_step->text().toStdString()) &&
      controller->validatorController(
          ui->lineEdit_xMax->text().toStdString()) &&
      controller->validatorController(
          ui->lineEdit_xMin->text().toStdString()) &&
      controller->validatorController(
          ui->lineEdit_yMax->text().toStdString()) &&
      controller->validatorController(
          ui->lineEdit_yMin->text().toStdString()) &&
      (controller->checkInputCorrect(ui->lineEdit->text().toStdString())) &&
      (ui->lineEdit->text() != "ERROR!")) {
    // Получаем значения параметров для построения графика
    QString str_xBegin = ui->lineEdit_xBegin->text();
    QString str_xEnd = ui->lineEdit_xEnd->text();
    QString str_step = ui->lineEdit_step->text();

    double xStart = str_xBegin.toDouble();
    double xEnd = str_xEnd.toDouble();
    double step = str_step.toDouble();

    QString str_xMax = ui->lineEdit_xMax->text();
    QString str_xMin = ui->lineEdit_xMin->text();

    double xMax = str_xMax.toDouble();
    double xMin = str_xMin.toDouble();

    QString str_yMax = ui->lineEdit_yMax->text();
    QString str_yMin = ui->lineEdit_yMin->text();

    double yMax = str_yMax.toDouble();
    double yMin = str_yMin.toDouble();

    // Устанавливаем диапазоны для осей x и y графика
    ui->widget->xAxis->setRange(xMin, xMax);
    ui->widget->yAxis->setRange(yMin, yMax);

    // Получаем введенное пользователем математическое выражение
    std::string str = ui->lineEdit->text().toStdString();

    // Проверяем корректность введенного выражения
    if (controller->checkInputCorrect(str)) {
      // Проверяем, заданы ли параметры для построения графика
      if ((xStart || xEnd || step || xMax || xMin || yMax || yMin)) {
        // Строим массивы данных x и y для построения графика
        for (double tmp = xStart; tmp <= xEnd; tmp += step) {
          x.push_back(tmp);
          y.push_back(controller->resultController(str, tmp));
        }

        // Добавляем график на графическое окно и перерисовываем
        ui->widget->addGraph();
        ui->widget->graph(0)->addData(x, y);
        ui->widget->replot();
      }
    } else
      ui->lineEdit->setText("ERROR!");  // Выводим ошибку на текстовое поле
  } else
    ui->lineEdit->setText("ERROR!");  // Выводим ошибку на текстовое поле
}

void s21::view::on_pushButton_credit_clicked() noexcept {
  credit.show();  // Открываем интерфейс кредитного калькулятора
}

void s21::view::on_pushButton_deposit_clicked() noexcept {
  deposit.show();  // Открываем интерфейс депозитного калькулятора
}
