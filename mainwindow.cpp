#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>
#include <vector>
#include <stdlib.h>

const double PI = 3.14159265358;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);


    addPointFileData("m1_0.csv", Eigen::Vector3d(1,0,0), dataList1);
    addPointFileData("m1_1.csv", Eigen::Vector3d(0,1,0), dataList1);
    addPointFileData("m1_2.csv", Eigen::Vector3d(0,0,1), dataList1);

    addPointFileData("m20_0.csv", Eigen::Vector3d(20,0,0), dataList20);
    addPointFileData("m20_1.csv", Eigen::Vector3d(0,20,0), dataList20);
    addPointFileData("m20_2.csv", Eigen::Vector3d(0,0,20), dataList20);

    addPointFileData("m40_0.csv", Eigen::Vector3d(40,0,0), dataList40);
    addPointFileData("m40_1.csv", Eigen::Vector3d(0,40,0), dataList40);
    addPointFileData("m40_2.csv", Eigen::Vector3d(0,0,40), dataList40);


}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::addPointFileData(QString filename, Eigen::Vector3d current_vector, std::vector< MagneticMeasurement> &dataList){

    //Load data from the
    QFile file(filename);
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
        return;

    QTextStream in(&file);

    int line_ind = 0;
    double fieldMatrix [64][3];
    double locationMatrix[64][3];

    while (!in.atEnd()) {
        QString line = in.readLine();
        QStringList list = line.split(',');

        for (int i=0;i<3;i++){
          fieldMatrix[line_ind][i] = list[i].toDouble();
        }

        for (int i=3;i<6;i++){
          locationMatrix[line_ind][i-3] = list[i].toDouble();
        }
        Eigen::Vector3d curFieldPt = Eigen::Vector3d(fieldMatrix[line_ind][0], fieldMatrix[line_ind][1], fieldMatrix[line_ind][2]);
        Eigen::Vector3d curLocPt = Eigen::Vector3d(locationMatrix[line_ind][0],locationMatrix[line_ind][1], locationMatrix[line_ind][2]);

        MagneticMeasurement cur_measurement = MagneticMeasurement(curFieldPt, curLocPt, current_vector);
        dataList.push_back(cur_measurement);

        line_ind++;
    }

}


void MainWindow::calibrateMagnets(){

    //loadCalibData(dataList1){}
    omnimagnet_cal_1amp.calibrate("OmniMag_1Amp", dataList1);
    omnimagnet_cal_1amp.writeCalibration("OmniMag_1Amp");

    omnimagnet_cal_20amp.calibrate("OmniMag_20Amp", dataList20);
    omnimagnet_cal_20amp.writeCalibration("OmniMag_20Amp");

    omnimagnet_cal_40amp.calibrate("OmniMag_40Amp", dataList40);
    omnimagnet_cal_40amp.writeCalibration("OmniMag_40Amp");
}


//void MainWindow::readMagFile(QString filename){
//    //read file with position values and write to array
//    QFile file(filename);
//       if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
//           return;

//    QTextStream in(&file);
//    QString line = in.readLine();
//    int i = 1;
//    while (!line.isNull()) {
//        //           //pos_rot struct to store values;
//        //           pos_rot point;

//        //           QStringList list1 = line.split(",");

//        //           //std::cout << "list1,0: " << list1.value(0).toDouble() << "list1,1: " << list1.value(1).toDouble() << "list1,2: " << list1.value(2).toDouble() << "list1,3: " << list1.value(3).toDouble() << std::endl;
//        //           // Create the location vector
//        //           point.pos = Eigen::Vector3d(list1.value(1).toDouble(),list1.value(2).toDouble(),list1.value(3).toDouble());

//        //           // Create the rotation matrix (rotate about x)
//        //           Eigen::Matrix3d mat;
//        //           double deg = list1.value(0).toDouble();
//        //           point.deg = deg;
//        //           mat << 1, 0, 0,
//        //                  0, cos(deg*PI/180), -sin(deg*PI/180),
//        //                  0, sin(deg*PI/180), cos(deg*PI/180);
//        //           point.rot = mat;


//        //           //Set the calib_map value to the pos_rot struct called point
//        //           calib_map[i] = point;
//        //           i++; // Increment i

//        //           line = in.readLine();

//    }

//}

// This function maps all of the numbers to a rotation, It uses the global calib_mat variable declared in the header file
void MainWindow::buildCalibMap(){

//    //read file with position values and write to array
//    QFile file("rot_loc_calib_cube_data.csv");
//       if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
//           return;

//       QTextStream in(&file);
//       QString line = in.readLine();
//       int i = 1;
//       while (!line.isNull()) {

//           //pos_rot struct to store values;
//           pos_rot point;

//           QStringList list1 = line.split(",");

//           //std::cout << "list1,0: " << list1.value(0).toDouble() << "list1,1: " << list1.value(1).toDouble() << "list1,2: " << list1.value(2).toDouble() << "list1,3: " << list1.value(3).toDouble() << std::endl;
//           // Create the location vector
//           point.pos = Eigen::Vector3d(list1.value(1).toDouble(),list1.value(2).toDouble(),list1.value(3).toDouble());

//           // Create the rotation matrix (rotate about x)
//           Eigen::Matrix3d mat;
//           double deg = list1.value(0).toDouble();
//           point.deg = deg;
//           mat << 1, 0, 0,
//                  0, cos(deg*PI/180), -sin(deg*PI/180),
//                  0, sin(deg*PI/180), cos(deg*PI/180);
//           point.rot = mat;


//           //Set the calib_map value to the pos_rot struct called point
//           calib_map[i] = point;
//           i++; // Increment i

//           line = in.readLine();
//       }
//    //read file with rotations and write to array

}

//void MainWindow::calibrateMagnets(){

//    // Names of all the point files used for calibration
//    QStringList pointNames1 = {"calibPoint1.csv","calibPoint5.csv","calibPoint7.csv","calibPoint10.csv","calibPoint17.csv", "calibPoint19.csv", "calibPoint23.csv",
//                               "calibPoint24.csv","calibPoint30.csv","calibPoint32.csv","calibPoint38.csv","calibPoint40.csv", "calibPoint42.csv", "calibPoint46.csv",
//                               "calibPoint47.csv","calibPoint50.csv","calibPoint53.csv","calibPoint56.csv","calibPoint63.csv", "calibPoint66.csv", "calibPoint69.csv",
//                               "calibPoint70.csv","calibPoint74.csv","calibPoint77.csv","calibPoint80.csv","calibPoint85.csv", "calibPoint88.csv", "calibPoint92.csv",
//                               "calibPoint93.csv","calibPoint97.csv","calibPoint101.csv","calibPoint102.csv","calibPoint108.csv", "calibPoint111.csv", "calibPoint115.csv"};


//    QString path_to_points = "/home/telerobotics/src/GuineaPig_OmniControl/calib_measurements/side0/";

//    // Vector distance from the center of the Omnimagnet to the center of the calibCube
//    Eigen::Vector3d vecToMag1 = Eigen::Vector3d(0.0,0.0,-20.0);

//    // Add all the points from the above file to the dataLists (pointNames1 is the first side measured)
//    for (int i=0; i<pointNames1.size(); i++){
//        addPointFileData(path_to_points + pointNames1[i], vecToMag1);
//    }

//    ElectromagnetCalibration omnimagnet_cal_1amp("inital_guess.yaml");
//    //loadCalibData(dataList1){}
//    omnimagnet_cal_1amp.calibrate("OmniMag_1Amp", dataList1);
//    omnimagnet_cal_1amp.writeCalibration("OmniMag_1Amp");

//    ElectromagnetCalibration omnimagnet_cal_20amp("inital_guess.yaml");
//    omnimagnet_cal_1amp.calibrate("OmniMag_1Amp", dataList20);
//    omnimagnet_cal_1amp.writeCalibration("OmniMag_1Amp");

//    ElectromagnetCalibration omnimagnet_cal_40amp("inital_guess.yaml");
//    omnimagnet_cal_1amp.calibrate("OmniMag_1Amp", dataList40);
//    omnimagnet_cal_1amp.writeCalibration("OmniMag_1Amp");

//}
