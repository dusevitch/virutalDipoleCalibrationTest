#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QFile>
#include <QMainWindow>
#include <eigen3/Eigen/Dense>
#include <eigen3/Eigen/Eigen>
#include <electromagnet-calibration/EigenToYAML.h>
#include <electromagnet-calibration/electromagnet_calibration.h>
#include <vector>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void addPointFileData(QString filename, Eigen::Vector3d current_vector, std::vector< MagneticMeasurement> &dataList);

    std::vector< MagneticMeasurement> dataList1;
    std::vector< MagneticMeasurement> dataList20;
    std::vector< MagneticMeasurement> dataList40;

    void buildCalibMap();
    void calibrateMagnets();

    ElectromagnetCalibration omnimagnet_cal_1amp = ElectromagnetCalibration("inital_guess.yaml");
    ElectromagnetCalibration omnimagnet_cal_20amp = ElectromagnetCalibration("inital_guess.yaml");
    ElectromagnetCalibration omnimagnet_cal_40amp = ElectromagnetCalibration("inital_guess.yaml");

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
