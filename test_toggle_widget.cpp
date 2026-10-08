#include <QtTest/QtTest>
#include <QtWidgets>
#include <QDebug>

#include "toggle_widget.h"

class TestToggleWidget : public QObject {
  Q_OBJECT

private slots:

  void buttonClickTogglesLight();
  
};

void TestToggleWidget::buttonClickTogglesLight() {
  ToggleWidget widget;
  widget.show();

  auto button = widget.findChild<QPushButton *>();
  QVERIFY(button != nullptr);

  QVERIFY(widget.isOn() == false);

  QTest::mouseClick(button, Qt::LeftButton);
  QVERIFY(widget.isOn() == true);

  QTest::mouseClick(button, Qt::LeftButton);
  QVERIFY(widget.isOn() == false);
}


QTEST_MAIN(TestToggleWidget)
#include "test_toggle_widget.moc"
