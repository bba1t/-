#ifndef CPP3_SMARTCALC_V2_0_1_SMARTCALC_V2_0_VIEW_H_
#define CPP3_SMARTCALC_V2_0_1_SMARTCALC_V2_0_VIEW_H_

#include <QMainWindow>
#include <QVector>

#include "controller.h"
#include "creditView.h"
#include "depositView.h"
#include "qcustomplot.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class view;
}
QT_END_NAMESPACE

namespace s21 {

class view : public QMainWindow {
  Q_OBJECT

 public:
  view(QWidget *parent = nullptr);

  view(Controller *c) : controller(c){};

  ~view();

 private:
  Ui::view *ui;  ///< Указатель на объект интерфейса.
  Controller *controller;  ///< Указатель на объект контроллера.
  QVector<double> x, y;  ///< Векторы для хранения данных для графика.
  Credit credit;  ///< Объект кредитного калькулятора.
  Deposit deposit;  ///< Объект депозитного калькулятора.

 private slots:
  // Код слотов для обработки событий кнопок

  void concat(QString str) const noexcept;

  inline void on_pushButton_0_clicked() const noexcept { view::concat("0"); }

  inline void on_pushButton_1_clicked() const noexcept { view::concat("1"); }

  inline void on_pushButton_2_clicked() const noexcept { view::concat("2"); }

  inline void on_pushButton_3_clicked() const noexcept { view::concat("3"); }

  inline void on_pushButton_4_clicked() const noexcept { view::concat("4"); }

  inline void on_pushButton_5_clicked() const noexcept { view::concat("5"); }

  inline void on_pushButton_6_clicked() const noexcept { view::concat("6"); }

  inline void on_pushButton_7_clicked() const noexcept { view::concat("7"); }

  inline void on_pushButton_8_clicked() const noexcept { view::concat("8"); }

  inline void on_pushButton_9_clicked() const noexcept { view::concat("9"); }

  inline void on_pushButton_dot_clicked() const noexcept { view::concat("."); }

  inline void on_pushButton_div_clicked() const noexcept { view::concat("/"); }

  inline void on_pushButton_mul_clicked() const noexcept { view::concat("*"); }

  inline void on_pushButton_sub_clicked() const noexcept { view::concat("-"); }

  inline void on_pushButton_sum_clicked() const noexcept { view::concat("+"); }

  inline void on_pushButton_sin_clicked() const noexcept {
    view::concat("sin");
  }

  inline void on_pushButton_cos_clicked() const noexcept {
    view::concat("cos");
  }

  inline void on_pushButton_tan_clicked() const noexcept {
    view::concat("tan");
  }

  inline void on_pushButton_asin_clicked() const noexcept {
    view::concat("asin");
  }

  inline void on_pushButton_acos_clicked() const noexcept {
    view::concat("acos");
  }

  inline void on_pushButton_atan_clicked() const noexcept {
    view::concat("atan");
  }

  inline void on_pushButton_LBracket_clicked() const noexcept {
    view::concat("(");
  }

  inline void on_pushButton_Rbracket_clicked() const noexcept {
    view::concat(")");
  }

  inline void on_pushButton_mod_clicked() const noexcept { view::concat("%"); }

  inline void on_pushButton_const_clicked() const noexcept {
    view::concat("x");
  }

  inline void on_pushButton_nlog_clicked() const noexcept {
    view::concat("ln");
  }

  inline void on_pushButton_log_clicked() const noexcept {
    view::concat("log");
  }

  inline void on_pushButton_pow_clicked() const noexcept { view::concat("^"); }

  inline void on_pushButton_sqwrt_clicked() const noexcept {
    view::concat("sqrt");
  }

  void on_pushButton_C_clicked() const noexcept;

  void on_pushButton_sign_clicked() const noexcept;

  void on_pushButton_result_clicked() const noexcept;

  void on_pushButton_print_clicked() noexcept;

  void on_pushButton_credit_clicked() noexcept;

  void on_pushButton_deposit_clicked() noexcept;
};
}  // namespace s21
#endif  // CPP3_SMARTCALC_V2_0_1_SMARTCALC_V2_0_VIEW_H_
