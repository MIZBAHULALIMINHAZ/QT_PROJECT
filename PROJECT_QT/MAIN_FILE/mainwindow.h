#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPrinter>

#include <QPrintDialog>
#include <QMessageBox>

#include <QtCore/qstring.h>
#include <QtCore/qcoreevent.h>
#include <QtCore/qobjectdefs.h>
#include <Qfile>
#include <QDir>
#include <QDebug>
#include <QString>
#include <qstring.h>

#include <QApplication>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>

#include <QTextStream>

#include <QDataStream>
#include <QGlobal.h>
#include <QTime>
#include <QObject>
#include <QDate>
#include <QVector>


QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);

    ~MainWindow();

private slots:
    void on_LOG_IN_BTN_clicked();

    void on_REGISTER_BTN_clicked();

    void on_RESET_BTN_clicked();

    void on_GET_OTP_clicked();

    void on_OTP_DONE_clicked();

    void on_REGISTRATION_clicked();

    void on_log_OUT_clicked();

    void on_BACK_IN_LOGIN_clicked();

    void on_pushButton_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

    void on_EXIT__clicked();

    void on_DONE_SET_PAS_BTN_clicked();

    void on_pushButton_8_clicked();

    void on_PASSENGER_BTTN_clicked();

    void on_EMPLOYEE_BTTN_clicked();

    void on_pushButton_2_clicked();

    void on_EXIT_N_clicked();

    void on_BACK_N_clicked();

    void on_EXIT_NN_clicked();

    void on_LOG_IN_ADMIN_clicked();

    void on_EXIT_n1_clicked();

    void on_CEO_LOG_in_BTN_clicked();

    void on_pushButton_5_clicked();

    void on_pushButton_6_clicked();

    void on_OWNER_BTTN_clicked();

    void on_ADMIN_BTTN_clicked();

    void on_ADMIN_ADD_CEO_clicked();

    void on_EXIT__K_clicked();

    void on_ADD_FLIGHT_BTN_clicked();

    void on_ADD_FLIGHT_BTN_2_clicked();

    void on_EXIT_OP_clicked();

    void on_Flight_no_in_btn_clicked();

    void on_CHECK_FLIGHT_BTN_clicked();

    void on_pushButton_15_clicked();

    void on_pushButton_16_clicked();

    void on_pushButton_22_clicked();

    void on_pushButton_21_clicked();

    void on_ADMIN_CLOSE_CEO_clicked();

    void on_ADMIN_INFO_CEO_clicked();

    void on_pushButton_27_clicked();

    void on_pushButton_26_clicked();

    void on_EXIR_clicked();

    void on_back_clicked();

    void on_flight_cncl_btn_clicked();

    void on_CENCEL_FLIGHT_BTN_clicked();

    void on_pushButton_7_clicked();

    void on_pushButton_9_clicked();

    void on_pushButton_28_clicked();

    void on_pushButton_10_clicked();

    void on_pushButton_11_clicked();

    void on_CEO_TRANSFER_clicked();

    void on_pushButton_12_clicked();

    void on_TRANSPER_CEO_clicked();

    void on_pushButton_13_clicked();

    void on_TRANSPER_CEO_3_clicked();

    void on_TRANSPER_CEO_2_clicked();

    void on_SHEDULE_CHEACK_ADMIN_clicked();

    void on_FLIGHT_SETTINGS_clicked();

    void on_pushButton_14_clicked();

    void on_stackedWidget_currentChanged(int arg1);

    void on_pushButton_57_clicked();

    void on_A_1_clicked();

    void on_a1_clicked();

    void on_a2_clicked();

    void on_A_2_clicked();

    void on_A_3_clicked();

    void on_A_4_clicked();

    void on_A_5_clicked();

    void on_pushButton_62_clicked();

    void on_A_6_clicked();

    void on_pushButton_61_clicked();

    void on_BKASH_clicked();

    void on_pushButton_63_clicked();

    void on_pushButton_65_clicked();

    void on_pushButton_66_clicked();

    void on_pushButton_67_clicked();

    void on_pushButton_69_clicked();

    void on_pushButton_68_clicked();

    void on_pushButton_70_clicked();

    void on_pushButton_71_clicked();

    void on_B_1_clicked();

    void on_B_2_clicked();

    void on_B_3_clicked();

    void on_B_4_clicked();

    void on_B_5_clicked();

    void on_B_6_clicked();

    void on_C_1_clicked();

    void on_C_2_clicked();

    void on_C_3_clicked();

    void on_C_4_clicked();

    void on_C_5_clicked();

    void on_C_6_clicked();

    void on_D_1_clicked();

    void on_D_2_clicked();

    void on_D_3_clicked();

    void on_D_4_clicked();

    void on_D_5_clicked();

    void on_D_6_clicked();

    void on_E_1_clicked();

    void on_E_2_clicked();

    void on_E_3_clicked();

    void on_E_4_clicked();

    void on_E_5_clicked();

    void on_E_6_clicked();

    void on_E_7_clicked();

    void on_E_8_clicked();

    void on_F_1_clicked();

    void on_F_2_clicked();

    void on_F_3_clicked();

    void on_F_4_clicked();

    void on_F_5_clicked();

    void on_F_6_clicked();

    void on_F_7_clicked();

    void on_F_8_clicked();

    void on_G_1_clicked();

    void on_G_2_clicked();

    void on_G_3_clicked();

    void on_G_4_clicked();

    void on_G_5_clicked();

    void on_G_6_clicked();

    void on_G_7_clicked();

    void on_G_8_clicked();

    void on_H_1_clicked();

    void on_H_2_clicked();

    void on_H_3_clicked();

    void on_H_4_clicked();

    void on_H_5_clicked();

    void on_H_6_clicked();

    void on_H_7_clicked();

    void on_H_8_clicked();

    void on_H_9_clicked();

    void on_I_1_clicked();

    void on_I_2_clicked();

    void on_I_3_clicked();

    void on_I_4_clicked();

    void on_I_5_clicked();

    void on_I_6_clicked();

    void on_I_7_clicked();

    void on_I_8_clicked();

    void on_I_9_clicked();

    void on_J_1_clicked();

    void on_J_2_clicked();

    void on_J_3_clicked();

    void on_J_4_clicked();

    void on_J_5_clicked();

    void on_J_6_clicked();

    void on_J_7_clicked();

    void on_J_8_clicked();

    void on_J_9_clicked();

    void on_BKASH_2_clicked();

    void on_pushButton_64_clicked();

    void on_pushButton_72_clicked();

    void on_pushButton_29_clicked();

    void on_pushButton_73_clicked();

    void on_pushButton_74_clicked();

    void on_pushButton_75_clicked();

    void on_pushButton_76_clicked();

    void on_pushButton_77_clicked();

    void on_pushButton_79_clicked();

    void on_pushButton_78_clicked();

    void on_pushButton_80_clicked();

    void on_pushButton_81_clicked();

    void on_pushButton_82_clicked();

    void on_FLIGHT_SETTINGS_5_clicked();

    void on_comboBox_4_currentIndexChanged(int index);

    void on_pushButton_30_clicked();

    void on_DONE_SET_PAS_BTN_5_clicked();

    void on_comboBox_6_currentIndexChanged(int index);

    void on_DONE_SET_PAS_BTN_8_clicked();

    void on_comboBox_8_currentIndexChanged(int index);

    void on_pushButton_83_clicked();

    void on_pushButton_84_clicked();

    void on_pushButton_85_clicked();

    void on_pushButton_87_clicked();

    void on_pushButton_86_clicked();

    void on_pushButton_88_clicked();

    void on_pushButton_89_clicked();

    void on_pushButton_90_clicked();

    void on_pushButton_91_clicked();

    void on_pushButton_93_clicked();

    void on_comboBox_9_currentIndexChanged(int index);

    void on_pushButton_92_clicked();

    void on_pushButton_95_clicked();

    void on_pushButton_94_clicked();

    void on_SHEDULE_CHECK_20_currentTextChanged(const QString &arg1);

    void on_SHEDULE_CHECK_20_currentIndexChanged(int index);

    void on_pushButton_96_clicked();

    void on_pushButton_97_clicked();

    void on_pushButton_104_clicked();

    void on_pushButton_103_clicked();

    void on_pushButton_102_clicked();

    void on_pushButton_100_clicked();

    void on_pushButton_101_clicked();

    void on_pushButton_98_clicked();

    void on_pushButton_106_clicked();

    void on_pushButton_105_clicked();

    void on_pushButton_107_clicked();

    void on_pushButton_108_clicked();

    void on_pushButton_99_clicked();

    void on_pushButton_109_clicked();

private:
    Ui::MainWindow *ui;
    //QSqlDatabase DB_Connection;
    QString ADD_ADMIN_PASSWORDE,ADD_ADMIN_IDE,send_by,back;
    int jhkl;
    QString CEO_ID,CEO_PASSWORD_1,CEO_PASSWORD_2;
    QString login_user_id,log_in_password,macthed_user_password,macthed_user_id ;
    QString login_CEO_id,log_in_CEO1_password,log_in_CEO2_password  ;
    QString Regis_email,regis_pass,Regis_password,Regis_password_re,Regis_number;
    QString login_ADMIN_id,log_in_ADMIN_password,macthed_ADMIN_id,macthed_ADMIN_password;
    QString Flight_choice,BOOKKING,opener,CUSTOMER,id_new,id_type,LOCAL;
    QVector<QString>mai_is;
    QVector<QString >line_flight,line_booking_id;
};
#endif // MAINWINDOW_H
