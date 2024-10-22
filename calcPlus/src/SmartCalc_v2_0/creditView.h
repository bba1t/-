#ifndef CPP3_SMARTCALC_V2_0_1_SMARTCALC_V2_0_CREDITVIEW_H_
#define CPP3_SMARTCALC_V2_0_1_SMARTCALC_V2_0_CREDITVIEW_H_

#include <QMainWindow>
#include <cmath>
#include <string>
#include <vector>

#include "controller.h"

namespace Ui {
class Credit;
}

namespace s21 {
class Credit : public QMainWindow {
  Q_OBJECT
 public:
  explicit Credit(QWidget *parent = nullptr);

  ~Credit();

 private slots:

  void on_pushButton_calculate_clicked();

 private:
  /**< Указатель на объект
                                               пользовательского интерфейса. */
  Ui::Credit *ui;

  bool validator(std::string input) const noexcept;
};
}  // namespace s21
#endif  // CPP3_SMARTCALC_V2_0_1_SMARTCALC_V2_0_CREDITVIEW_H_
