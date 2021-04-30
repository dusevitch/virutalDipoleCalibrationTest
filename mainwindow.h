#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QFile>
#include <QMainWindow>
#include <eigen3/Eigen/Dense>
#include <eigen3/Eigen/Eigen>
#include <yaml-cpp/yaml.h>
#include <electromagnet-calibration/electromagnet_calibration.h>


QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void addPointFileData(QString filename, Eigen::Vector3d vecToMag);

    const std::vector< MagneticMeasurement> dataList1;
    const std::vector< MagneticMeasurement> dataList20;
    const std::vector< MagneticMeasurement> dataList40;

    void buildCalibMap();
    void calibrateMagnets();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
