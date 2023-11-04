#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QGlobal.h>
#include <QTime>
#include <QComboBox>
#include <QStringList>


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
     ui->stackedWidget->setCurrentIndex(6);



}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_LOG_IN_BTN_clicked()
{

    int i=0;
    QVector<QString>file_id,file_passort,file_number,file_password;
    QFile Fiile("Registration.txt");
    if(Fiile.open(QIODevice::ReadOnly))
    {
        QTextStream stream(&Fiile);
        QString FileData1,FileData2,FileData3,FileData4;
        while ( stream.atEnd()==false)
        {
            FileData1 = stream.readLine();
            file_id.push_back(FileData1);
            FileData2 = stream.readLine();
            file_passort.push_back(FileData2);
            FileData3 = stream.readLine();
            file_number.push_back(FileData3);
            FileData4 = stream.readLine();
            file_password.push_back(FileData4);
            i++;
        }
    }
    login_user_id = ui->USER_ID->text();
    log_in_password =ui->PASWORD->text();
    int alpa=file_id.indexOf(login_user_id);
    if(alpa!=-1){
    macthed_user_id=file_id.at(alpa);
    macthed_user_password=file_password.at(alpa);
    if(login_user_id ==macthed_user_id && log_in_password==macthed_user_password)
    {
            CUSTOMER=login_user_id;
        ui->stackedWidget->setCurrentIndex(5);
    }
    else
    {
        QMessageBox :: warning(this,"login","Wrong Email Or Password");
    }
    }
    else
    {
    QMessageBox :: warning(this,"login","Register first");
    }
    ui->USER_ID->clear();
    ui->PASWORD->clear();
    Fiile.close();
   // ui->stackedWidget->setCurrentIndex(5);
}


void MainWindow::on_REGISTER_BTN_clicked()
{

    ui->stackedWidget->setCurrentIndex(1);
}


void MainWindow::on_RESET_BTN_clicked()
{
    ui->stackedWidget->setCurrentIndex(2);
}


void MainWindow::on_GET_OTP_clicked()
{
    QString log_in_pasport,log_in_number,log_in_id,macth_user_id,macth_user_passport,macth_user_number,macth_user_password;
    int i=0;
    QVector<QString>file_id,file_passort,file_number,file_password;
    QFile Fiile("Registration.txt");
    if(Fiile.open(QIODevice::ReadOnly))
    {
    QTextStream stream(&Fiile);
    QString FileData1,FileData2,FileData3,FileData4;
    while ( stream.atEnd()==false)
    {
        FileData1 = stream.readLine();
        file_id.push_back(FileData1);
        FileData2 = stream.readLine();
        file_passort.push_back(FileData2);
        FileData3 = stream.readLine();
        file_number.push_back(FileData3);
        FileData4 = stream.readLine();
        file_password.push_back(FileData4);
        i++;
    }
    }
    log_in_id = ui->USER_IS_R->text();
    log_in_pasport =ui->NUMBER_R->text();
    log_in_number =ui->NUMBER_R_5->text();
    int alpa=file_id.indexOf(log_in_id);
    if(alpa!=-1){
    macth_user_id=file_id.at(alpa);
    macth_user_passport=file_passort.at(alpa);
    macth_user_number= file_number.at(alpa);
    macth_user_password=file_password.at(alpa);
    if(log_in_id ==macth_user_id && macth_user_passport==log_in_pasport && log_in_number==macth_user_number)
    {
        QMessageBox :: warning(this,"password",macth_user_password);
    }
    else
    {
        QMessageBox :: warning(this,"login","Wrong Email Or Password");
    }
    }
    else
    {
    QMessageBox :: warning(this,"login","Register first");
    }
    ui->USER_IS_R->clear();
    ui->NUMBER_R->clear();
    ui->NUMBER_R_5->clear();
    Fiile.close();
    //ui->stackedWidget->setCurrentIndex(3);
}


void MainWindow::on_OTP_DONE_clicked()
{
    QString PORT,country;
    PORT= ui->OTP_INPUT->text();
    country= ui->OTP_INPUT_5->text();
    QFile port("PORT.txt");
    if(port.open(QIODevice::Append | QIODevice::WriteOnly))
    {
    QTextStream stream(&port);
    stream<<PORT+"\n";
    stream<<country+"\n";
    }
    port.close();

    ui->OTP_INPUT->clear();
    ui->OTP_INPUT_5->clear();
    //ui->stackedWidget->setCurrentIndex(4);
}


void MainWindow::on_REGISTRATION_clicked()
{
    Regis_email=ui->E_MAIL->text();
    regis_pass =ui->PASSPORT->text();
    Regis_number = ui->NUMBER->text();
    Regis_password = ui->PASSWORD->text();
    Regis_password_re = ui->USER_ID_5->text();

    QFile HIS(Regis_email);
    if(HIS.open(QIODevice::Append | QIODevice::ReadWrite))
    {
        QTextStream stream(&HIS);
    }
    HIS.close();
    QFile File("Registration.txt");
    if(File.open(QIODevice::Append | QIODevice::ReadWrite))
    {
        QTextStream stream(&File);
        stream<< ui->E_MAIL-> text() + "\n";
        stream<< ui->PASSPORT-> text() + "\n";
        stream<< ui->NUMBER-> text() + "\n";
        stream<< ui->PASSWORD-> text() + "\n";
    }
    File.close();
    ui->E_MAIL->clear();
    ui->PASSPORT->clear();
    ui->NUMBER->clear();
    ui->PASSWORD->clear();
    ui->USER_ID_5->clear();
    ui->stackedWidget->setCurrentIndex(6);
}


void MainWindow::on_log_OUT_clicked()
{
    ui->stackedWidget->setCurrentIndex(6);
}


void MainWindow::on_BACK_IN_LOGIN_clicked()
{
    ui->stackedWidget->setCurrentIndex(6);
}


void MainWindow::on_pushButton_clicked()
{
    ui->stackedWidget->setCurrentIndex(6);
}


void MainWindow::on_pushButton_3_clicked()
{
    ui->stackedWidget->setCurrentIndex(6);
}


void MainWindow::on_pushButton_4_clicked()
{
    ui->stackedWidget->setCurrentIndex(9);
}


void MainWindow::on_EXIT__clicked()
{
    ui->stackedWidget->setCurrentIndex(20);
}


void MainWindow::on_DONE_SET_PAS_BTN_clicked()
{
    ui->comboBox_9->clear();
    QVector<QString> mai_lis;


    int o=0;
    QFile PORTEd("flight_id.txt");
    if(PORTEd.open(QIODevice::ReadOnly))
    {
        QTextStream stream(&PORTEd);
        while(stream.atEnd()==false)
        {
        mai_lis.push_back(stream.readLine());
        //side_list.push_back(stream.readLine());
        o++;
        }
    }
    PORTEd.close();
    for(int kj=0;kj<o;kj++)
    {
        ui->comboBox_9->addItem(mai_lis.at(kj));
    }

    ui->stackedWidget->setCurrentIndex(37);

}


void MainWindow::on_PASSENGER_BTTN_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}
void MainWindow::on_pushButton_8_clicked()
{
    ui->FLIGTH_MODEL->clear();
    ui->FLIGTH_EMPLOYEE_2->clear();
    ui->FLIGTH_EMPLOYEE_3->clear();
    ui->FLIGTH_EMPLOYEE_4->clear();
    ui->FLIGTH_EMPLOYEE_5->clear();
    ui->FLIGTH_PAILOT_1->clear();
    ui->FLIGTH_PAILOT_2->clear();
    ui->FLIGTH_FROM->clear();
    ui->FLIGHT_TO->clear();
    ui->stackedWidget->setCurrentIndex(9);
}

void MainWindow::on_EMPLOYEE_BTTN_clicked()
{
    ui->stackedWidget->setCurrentIndex(42);
}


void MainWindow::on_pushButton_2_clicked()
{
    ui->stackedWidget->setCurrentIndex(7);
    QVector<QString>FROM_D,TO_D,S_DATE_D,S_SRNO_D,STRT_TIME_D,END_TIME_D,DAY;
    QVector<QString>employ_1,employ_2,employ_3,employ_4,employ_5,flight_mdl,pailot_1,pailot_2,b_price,ecoprice,pecoprice;
    QFile Fiiile("FLIGHT.txt");
    int i=0;
    if(Fiiile.open(QIODevice::ReadOnly))
    {
        QTextStream stream(&Fiiile);
        QString FileData1,FileData2,FileData3,FileData4,FileData5,FileData6;
        while ( stream.atEnd()==false)
        {
        FileData1 = stream.readLine();
        S_SRNO_D.push_back(FileData1);
        FileData2 = stream.readLine();
        FROM_D.push_back(FileData2);
        FileData3 = stream.readLine();
        TO_D.push_back(FileData3);
        FileData4 = stream.readLine();
        STRT_TIME_D.push_back(FileData4);
        FileData5 = stream.readLine();
        END_TIME_D.push_back(FileData5);
        FileData6 = stream.readLine();
        S_DATE_D.push_back(FileData6);
        DAY.push_back(stream.readLine());
        i++;
        }
    }
    Fiiile.close();
    ui->SHEDULE_CHECK->setRowCount(i);
    for(int j=0;j<i;j++)
    {
        ui->SHEDULE_CHECK->setItem(j,0,new QTableWidgetItem(S_SRNO_D.at(j)));
        ui->SHEDULE_CHECK->setItem(j,1,new QTableWidgetItem(FROM_D.at(j)));
        ui->SHEDULE_CHECK->setItem(j,2,new QTableWidgetItem(TO_D.at(j)));
        ui->SHEDULE_CHECK->setItem(j,3,new QTableWidgetItem(STRT_TIME_D.at(j)));
        ui->SHEDULE_CHECK->setItem(j,4,new QTableWidgetItem(END_TIME_D.at(j)));
        ui->SHEDULE_CHECK->setItem(j,5,new QTableWidgetItem(S_DATE_D.at(j)));

    }
   // ui->tableWidget_flight->
}


void MainWindow::on_EXIT_N_clicked()
{
    ui->stackedWidget->setCurrentIndex(6);
}


void MainWindow::on_BACK_N_clicked()
{
    ui->stackedWidget->setCurrentIndex(5);
}


void MainWindow::on_EXIT_NN_clicked()
{
    ui->stackedWidget->setCurrentIndex(6);
}


void MainWindow::on_LOG_IN_ADMIN_clicked()
{
    login_ADMIN_id = ui->ADMIN_ID_L-> text();
    log_in_ADMIN_password =ui->ADMIN_PASSWORD_L->text();
    int i=0;
    QVector<QString>ADMIN_id,ADMIN_password;
    QFile Fiile("Registration_ADMIN.txt");
    if(Fiile.open(QIODevice::ReadOnly))
    {
        QTextStream stream(&Fiile);
        QString FileData1,FileData2;
        while ( stream.atEnd()==false)
        {
        FileData1 = stream.readLine();
        ADMIN_id.push_back(FileData1);
        FileData2 = stream.readLine();
        ADMIN_password.push_back(FileData2);
        i++;
        }
    }
    int alpa=ADMIN_id.indexOf(login_ADMIN_id);
    if(alpa!=-1){
        macthed_ADMIN_id=ADMIN_id.at(alpa);
        macthed_ADMIN_password=ADMIN_password.at(alpa);
        if(login_ADMIN_id ==macthed_ADMIN_id && log_in_ADMIN_password==macthed_ADMIN_password)
        {
         ui->stackedWidget->setCurrentIndex(9);
        }
        else
        {
        QMessageBox :: warning(this,"login","Wrong Email Or Password");
        }
    }
    else
    {
        QMessageBox :: warning(this,"login","Contact CEO");
    }
    ui->ADMIN_ID_L->clear();
    ui->ADMIN_PASSWORD_L->clear();
}


void MainWindow::on_EXIT_n1_clicked()
{
    ui->stackedWidget->setCurrentIndex(6);
}


void MainWindow::on_CEO_LOG_in_BTN_clicked()
{
    login_CEO_id = ui->EMAIL_CEO_2->text();
    log_in_CEO1_password = ui->PASWORD_1_CEO->text();
    log_in_CEO2_password = ui->PASWORD_2_CEO->text();
    QFile Fiile("CEO_TIME.txt");
    if(Fiile.open(QIODevice::ReadOnly))
    {
        QTextStream stream(&Fiile);
        while ( stream.atEnd()==false)
        {
        CEO_ID = stream.readLine();
        CEO_PASSWORD_1 = stream.readLine();
        CEO_PASSWORD_2 = stream.readLine();        }

        if(login_CEO_id ==CEO_ID && log_in_CEO1_password==CEO_PASSWORD_1 && log_in_CEO2_password==CEO_PASSWORD_2)
        {
        ui->stackedWidget->setCurrentIndex(11);
        }
        else
        {
        QMessageBox :: warning(this,"login","Wrong Email Or Password");
        }
    }
    else
    {
        QMessageBox :: warning(this,"login","Register first");
    }
    ui->EMAIL_CEO_2->clear();
    ui->PASWORD_1_CEO->clear();
    ui->PASWORD_2_CEO->clear();

}


void MainWindow::on_pushButton_5_clicked()
{

    ADD_ADMIN_IDE=ui->ADD_ADMIN_ID->text();
    ADD_ADMIN_PASSWORDE =ui->ADD_ADMIN_PASSWORD->text();
    QFile Fille("Registration_ADMIN.txt");
    if(Fille.open(QIODevice::Append | QIODevice::ReadWrite))
    {
        QTextStream stream(&Fille);
        stream<< ADD_ADMIN_IDE + "\n";
        stream<< ADD_ADMIN_PASSWORDE + "\n";
    }
    Fille.close();
    ui->ADD_ADMIN_ID->clear();
    ui->ADD_ADMIN_PASSWORD->clear();
    ui->stackedWidget->setCurrentIndex(11);
}


void MainWindow::on_pushButton_6_clicked()
{
    ui->stackedWidget->setCurrentIndex(11);
}


void MainWindow::on_OWNER_BTTN_clicked()
{
    ui->stackedWidget->setCurrentIndex(10);
}


void MainWindow::on_ADMIN_BTTN_clicked()
{
    ui->stackedWidget->setCurrentIndex(8);
}


void MainWindow::on_ADMIN_ADD_CEO_clicked()
{
    ui->stackedWidget->setCurrentIndex(12);
}


void MainWindow::on_EXIT__K_clicked()
{
        ui->stackedWidget->setCurrentIndex(6);
}


void MainWindow::on_ADD_FLIGHT_BTN_clicked()
{


        QVector<QString>pailot_list,worker_list,model_list,pailot_pass,worker_pass,port_list,country_list;

        int o=0;
        QFile PORT("PORT.txt");
        if(PORT.open(QIODevice::ReadOnly))
        {
        QTextStream stream(&PORT);
        while(stream.atEnd()==false)
        {
        port_list.push_back(stream.readLine());
        country_list.push_back(stream.readLine());
        o++;
        }
        }
        PORT.close();
        for(int kj=0;kj<o;kj++)
        {
        ui->FLIGTH_FROM->addItem(port_list.at(kj));
        ui->FLIGHT_TO->addItem(port_list.at(kj));
        }



        QFile pailotfile("PAILOT");
        if(pailotfile.open(QIODevice::ReadOnly))
        {
        QTextStream stream(&pailotfile);
        while ( stream.atEnd()==false)
        {
        pailot_list.push_back(stream.readLine());
        pailot_pass.push_back(stream.readLine());
        }

        }
        pailotfile.close();


        QFile modelfile("MODEL");
        if(modelfile.open(QIODevice::ReadOnly))
        {
        QTextStream stream(&modelfile);
        while ( stream.atEnd()==false)
        {
        model_list.push_back(stream.readLine());
        }

        }
        modelfile.close();

        /*for(int kj=0;kj<model_list.size();kj++)
        {
        ui->FLIGTH_MODEL->removeItem( kj);
        }*/

        for(int kj=0;kj<model_list.size();kj++)
        {
        ui->FLIGTH_MODEL->addItem(model_list.at(kj));
        }

        QFile workerlfile("WORKER");
        if(workerlfile.open(QIODevice::ReadOnly))
        {
        QTextStream stream(&workerlfile);
        while ( stream.atEnd()==false)
        {
        worker_list.push_back(stream.readLine());
        worker_pass.push_back(stream.readLine());
        }

        }
        workerlfile.close();
        //ui->FLIGTH_MODEL->set;


        /**/
        //ui->FLIGTH_EMPLOYEE_1->set

        /*for(int kj=0;kj<worker_list.size();kj++)
        {
        ui->FLIGTH_EMPLOYEE_2->removeItem( kj);
        ui->FLIGTH_EMPLOYEE_3->removeItem( kj);
        ui->FLIGTH_EMPLOYEE_4->removeItem( kj);
        ui->FLIGTH_EMPLOYEE_5->removeItem( kj);

        }*/



            for(int kj=0;kj<worker_list.size();kj++)
        {
        ui->FLIGTH_EMPLOYEE_2->addItem(worker_list.at(kj));
        ui->FLIGTH_EMPLOYEE_3->addItem(worker_list.at(kj));
        ui->FLIGTH_EMPLOYEE_4->addItem(worker_list.at(kj));
        ui->FLIGTH_EMPLOYEE_5->addItem(worker_list.at(kj));

        }
            /*for(int kj=0;kj<pailot_list.size();kj++)
            {
        //ui->FLIGTH_PAILOT_1->removeItem( kj);
        //ui->FLIGTH_PAILOT_2->removeItem( kj);
        //ui->FLIGTH_PAILOT_2->clear();
            }*/


            for(int kj=0;kj<pailot_list.size();kj++)
            {
        ui->FLIGTH_PAILOT_1->addItem(pailot_list.at(kj));
        ui->FLIGTH_PAILOT_2->addItem(pailot_list.at(kj));
            }

    ui->stackedWidget->setCurrentIndex(13);
}


void MainWindow::on_ADD_FLIGHT_BTN_2_clicked()
{
    QString Flight_From,Flight_to,flight_times,flight_timee,flight_date;
    QString flight_empoyee_1,flight_empoyee_2,flight_empoyee_3,flight_empoyee_4,flight_empoyee_5;
    QString flight_model,flight_pailot_1,flight_pailot_2,flight_price_Buss,flight_price_eco,flight_price_peco;


    Flight_From = ui->FLIGTH_FROM->currentText();
    Flight_to = ui->FLIGHT_TO->currentText();
    flight_times = ui->START_TIME->text();
    flight_timee = ui->END_TIME->text();

    flight_date = ui->FLY_DATE->text();
    flight_empoyee_1 = ui->FLIGTH_EMPLOYEE_1->currentText();
    flight_empoyee_2 = ui->FLIGTH_EMPLOYEE_2->currentText();
    flight_empoyee_3 = ui->FLIGTH_EMPLOYEE_3->currentText();
    flight_empoyee_4 = ui->FLIGTH_EMPLOYEE_4->currentText();
    flight_empoyee_5 = ui->FLIGTH_EMPLOYEE_5->currentText();
    flight_model = ui->FLIGTH_MODEL->currentText();
    flight_pailot_1 = ui->FLIGTH_PAILOT_1->currentText();
    flight_pailot_2 = ui->FLIGTH_PAILOT_2->currentText();
    flight_price_Buss = ui->FLIGTH_PRICE_BUSSNESS->text();
    flight_price_peco = ui->FLIGTH_PRICE_PECO->text();
    flight_price_eco = ui->FLIGTH_PRICE_ECO->text();
    QString n,rt,yt,op;
    int p;
    QFile counter("count.txt");
    if(counter.open(QIODevice::ReadOnly))
    {
        QTextStream stream(&counter);
        while ( stream.atEnd()==false)
        {
        n = stream.readLine();
        }

    }
        p = n.toInt();
        p=p+1;
        //QDebug<<p;
        op= QString ::number (p);
    counter.close();
        QFile couonter("count.txt");
        if(couonter.open(QIODevice::WriteOnly))
        {
        QTextStream stream(&couonter);
        op= QString ::number (p);
        stream<< op+"\n";
        }
        couonter.close();
    rt=Flight_From[0];
    yt=Flight_to[0];
    QString fly_id;
    fly_id=rt+yt+op;
    QFile Fiele("FLIGHT.txt");
    if(Fiele.open(QIODevice::Append | QIODevice::ReadWrite))
    {
        QTextStream stream(&Fiele);
        stream<< rt+yt+op+"\n";
        stream<< Flight_From+"\n";
        stream<< Flight_to+"\n";
        stream<< flight_times+"\n";
        stream<< flight_timee+"\n";
        stream<< flight_date+"\n";
        stream<< flight_empoyee_1+"\n";
    }
    Fiele.close();
    QFile F("flight_id.txt");
    if(F.open(QIODevice::Append | QIODevice::WriteOnly))
    {
        QTextStream stream(&F);
        stream<< fly_id+"\n";
    }
    F.close();
    QFile Fiee(fly_id);
    if(Fiee.open(QIODevice::Append | QIODevice::WriteOnly))
    {
        QTextStream stream(&Fiee);
        stream<< "OPENED\n";
        for(int i=0;i<75;i++)
        {
        stream<< "nonbooked\n";
        }
        stream<< flight_empoyee_1+"\n";
        stream<< flight_empoyee_2+"\n";
        stream<< flight_empoyee_3+"\n";
        stream<< flight_empoyee_4+"\n";
        stream<< flight_empoyee_5+"\n";
        stream<< flight_model+"\n";
        stream<< flight_pailot_1+"\n";
        stream<< flight_pailot_2+"\n";
        stream<< flight_price_Buss+"\n";
        stream<< flight_price_peco+"\n";
        stream<< flight_price_eco+"\n";
    }
    Fiee.close();

    //pailot1
    QFile pailot_1(flight_pailot_1);
    if(pailot_1.open(QIODevice::Append | QIODevice::WriteOnly))
    {
        QTextStream stream(&pailot_1);
        stream<< rt+yt+op+"\n";
    }
    pailot_1.close();

    //pailot2
    QFile pailot_2(flight_pailot_2);
    if(pailot_2.open(QIODevice::Append | QIODevice::WriteOnly))
    {
        QTextStream stream(&pailot_2);
        stream<< rt+yt+op+"\n";
    }
    pailot_2.close();

    //worker1
    QFile worker_1(flight_empoyee_2);
    if(worker_1.open(QIODevice::Append | QIODevice::WriteOnly))
    {
        QTextStream stream(&worker_1);
        stream<< rt+yt+op+"\n";
    }
    worker_1.close();

    //worker2
    QFile worker_2(flight_empoyee_3);
    if(worker_2.open(QIODevice::Append | QIODevice::WriteOnly))
    {
        QTextStream stream(&worker_2);
        stream<< rt+yt+op+"\n";
    }
    worker_2.close();

    //worker3
    QFile worker_3(flight_empoyee_4);
    if(worker_3.open(QIODevice::Append | QIODevice::WriteOnly))
    {
        QTextStream stream(&worker_3);
        stream<< rt+yt+op+"\n";
    }
    worker_3.close();

    //worker4
    QFile worker_4(flight_empoyee_5);
    if(worker_4.open(QIODevice::Append | QIODevice::WriteOnly))
    {
        QTextStream stream(&worker_4);
        stream<< rt+yt+op+"\n";
    }
    worker_1.close();


    ui->FLIGTH_FROM->clear();
    ui->FLIGHT_TO->clear();
    ui->START_TIME->clear();
    ui->END_TIME->clear();
    ui->FLY_DATE->clear();
    ui->FLIGTH_EMPLOYEE_2->clear();
    ui->FLIGTH_EMPLOYEE_3->clear();
    ui->FLIGTH_EMPLOYEE_4->clear();
    ui->FLIGTH_EMPLOYEE_5->clear();
    ui->FLIGTH_MODEL->clear();
    ui->FLIGTH_PAILOT_1->clear();
    ui->FLIGTH_PAILOT_2->clear();
    ui->FLIGTH_PRICE_BUSSNESS->clear();
    ui->FLIGTH_PRICE_PECO->clear();
    ui->FLIGTH_PRICE_ECO->clear();
    ui->stackedWidget->setCurrentIndex(9);
}


void MainWindow::on_EXIT_OP_clicked()
{
    ui->stackedWidget->setCurrentIndex(6);
}


void MainWindow::on_Flight_no_in_btn_clicked()
{
    ui->ticket_email->clear();
    ui->ticket_name->clear();
    ui->ticket_extra->clear();
    ui->ticket_number->clear();
    ui->ticket_passport->clear();
    QVector<QString>booking,flight_find;
    QString sl;
    Flight_choice = ui->Flight_no_in->text();
    QFile FR("flight_id.txt");
    if(FR.open(QIODevice::ReadOnly))
    {
        QTextStream stream(&FR);
        while ( stream.atEnd()==false)
        {
        flight_find.push_back(stream.readLine());
        }

    }
    FR.close();
    ui->Flight_no_in->clear();
    int alap=flight_find.indexOf(Flight_choice);
    if(alap!=-1){
    //ui->stackedWidget->setCurrentIndex(6);
        int jr=0;
    QFile Fiiree(Flight_choice);
    if(Fiiree.open(QIODevice::ReadOnly))
    {
        QTextStream stream(&Fiiree);
        while ( stream.atEnd()==false)
        {
        sl = stream.readLine();
        booking.push_back(sl);
        jr++;
        }
    }

    Fiiree.close();
    if(booking.at(0)=="OPENED"){
    for(int i=1;i<=75;i++)
    {
        if(booking.at(1)=="booked")
        {
            ui->A_1->setStyleSheet(QString("QPushButton {background-color: red;border:2px solid white;border-width: 2px;border-radius: 10px;border-color: beige;font: bold 14px;}"));
        }
        else
        {
            ui->A_1->setStyleSheet(QString("QPushButton {background-color: green;border:2px solid white;border-width: 2px;border-radius: 10px;border-color: beige;font: bold 14px;}"));

        }
        if(booking.at(2)=="booked")
        {
            ui->A_2->setStyleSheet(QString("QPushButton {background-color: red;border:2px solid white;border-width: 2px;border-radius: 10px;border-color: beige;font: bold 14px;}"));
        }
        else
        {
            ui->A_2->setStyleSheet(QString("QPushButton {background-color: green;border:2px solid white;border-width: 2px;border-radius: 10px;border-color: beige;font: bold 14px;}"));

        }
        if(booking.at(3)=="booked")
        {
            ui->A_3->setStyleSheet(QString("QPushButton {background-color: red;border:2px solid white;border-width: 2px;border-radius: 10px;border-color: beige;font: bold 14px;}"));
        }
        else
        {
            ui->A_3->setStyleSheet(QString("QPushButton {background-color: green;border:2px solid white;border-width: 2px;border-radius: 10px;border-color: beige;font: bold 14px;}"));

        }
        if(booking.at(4)=="booked")
        {
            ui->A_4->setStyleSheet(QString("QPushButton {background-color: red;border:2px solid white;border-width: 2px;border-radius: 10px;border-color: beige;font: bold 14px;}"));
        }
        else
        {
            ui->A_4->setStyleSheet(QString("QPushButton {background-color: green;border:2px solid white;border-width: 2px;border-radius: 10px;border-color: beige;font: bold 14px;}"));

        }
        if(booking.at(5)=="booked")
        {
            ui->A_5->setStyleSheet(QString("QPushButton {background-color: red;border:2px solid white;border-width: 2px;border-radius: 10px;border-color: beige;font: bold 14px;}"));
        }
        if(booking.at(6)=="booked")
        {
            ui->A_6->setStyleSheet(QString("QPushButton {background-color: red;border:2px solid white;border-width: 2px;border-radius: 10px;border-color: beige;font: bold 14px;}"));
        }
        else
        {
            ui->A_5->setStyleSheet(QString("QPushButton {background-color: green;border:2px solid white;border-width: 2px;border-radius: 10px;border-color: beige;font: bold 14px;}"));

        }
        if(booking.at(7)=="booked")
        {
            ui->B_1->setStyleSheet(QString("QPushButton {background-color: red;border:2px solid white;border-width: 2px;border-radius: 10px;border-color: beige;font: bold 14px;}"));
        }
        else
        {
            ui->B_1->setStyleSheet(QString("QPushButton {background-color: green;border:2px solid white;border-width: 2px;border-radius: 10px;border-color: beige;font: bold 14px;}"));

        }
        if(booking.at(8)=="booked")
        {
            ui->B_2->setStyleSheet(QString("QPushButton {background-color: red;border:2px solid white;border-width: 2px;border-radius: 10px;border-color: beige;font: bold 14px;}"));
        }
        else
        {
            ui->B_2->setStyleSheet(QString("QPushButton {background-color: green;border:2px solid white;border-width: 2px;border-radius: 10px;border-color: beige;font: bold 14px;}"));

        }
        if(booking.at(9)=="booked")
        {
            ui->B_3->setStyleSheet(QString("QPushButton {background-color: red;border:2px solid white;border-width: 2px;border-radius: 10px;border-color: beige;font: bold 14px;}"));
        }
        else
        {
            ui->B_3->setStyleSheet(QString("QPushButton {background-color: green;border:2px solid white;border-width: 2px;border-radius: 10px;border-color: beige;font: bold 14px;}"));

        }
        if(booking.at(10)=="booked")
        {
            ui->B_4->setStyleSheet(QString("QPushButton {background-color: red;border:2px solid white;border-width: 2px;border-radius: 10px;border-color: beige;font: bold 14px;}"));
        }
        else
        {
            ui->B_4->setStyleSheet(QString("QPushButton {background-color: green;border:2px solid white;border-width: 2px;border-radius: 10px;border-color: beige;font: bold 14px;}"));

        }
        if(booking.at(11)=="booked")
        {
            ui->B_5->setStyleSheet(QString("QPushButton {background-color: red;border:2px solid white;border-width: 2px;border-radius: 10px;border-color: beige;font: bold 14px;}"));
        }
        else
        {
            ui->B_5->setStyleSheet(QString("QPushButton {background-color: green;border:2px solid white;border-width: 2px;border-radius: 10px;border-color: beige;font: bold 14px;}"));

        }
        if(booking.at(12)=="booked")
        {
            ui->B_6->setStyleSheet(QString("QPushButton {background-color: red;border:2px solid white;border-width: 2px;border-radius: 10px;border-color: beige;font: bold 14px;}"));
        }
        else
        {
            ui->B_6->setStyleSheet(QString("QPushButton {background-color: green;border:2px solid white;border-width: 2px;border-radius: 10px;border-color: beige;font: bold 14px;}"));

        }
        if(booking.at(13)=="booked")
        {
            ui->C_1->setStyleSheet(QString("QPushButton {background-color: red;border:2px solid white;border-width: 2px;border-radius: 10px;border-color: beige;font: bold 14px;}"));
        }
        else
        {
            ui->C_1->setStyleSheet(QString("QPushButton {background-color: green;border:2px solid white;border-width: 2px;border-radius: 10px;border-color: beige;font: bold 14px;}"));

        }
        if(booking.at(14)=="booked")
        {
            ui->C_2->setStyleSheet(QString("QPushButton {background-color: red;border:2px solid white;border-width: 2px;border-radius: 10px;border-color: beige;font: bold 14px;}"));
        }
        else
        {
            ui->C_2->setStyleSheet(QString("QPushButton {background-color: green;border:2px solid white;border-width: 2px;border-radius: 10px;border-color: beige;font: bold 14px;}"));

        }
        if(booking.at(15)=="booked")
        {
            ui->C_3->setStyleSheet(QString("QPushButton {background-color: red;border:2px solid white;border-width: 2px;border-radius: 10px;border-color: beige;font: bold 14px;}"));
        }
        else
        {
            ui->C_3->setStyleSheet(QString("QPushButton {background-color: green;border:2px solid white;border-width: 2px;border-radius: 10px;border-color: beige;font: bold 14px;}"));

        }
        if(booking.at(16)=="booked")
        {
            ui->C_4->setStyleSheet(QString("QPushButton {background-color: red;border:2px solid white;border-width: 2px;border-radius: 10px;border-color: beige;font: bold 14px;}"));
        }
        else
        {
            ui->C_4->setStyleSheet(QString("QPushButton {background-color: green;border:2px solid white;border-width: 2px;border-radius: 10px;border-color: beige;font: bold 14px;}"));

        }
        if(booking.at(17)=="booked")
        {
            ui->C_5->setStyleSheet(QString("QPushButton {background-color: red;border:2px solid white;border-width: 2px;border-radius: 10px;border-color: beige;font: bold 14px;}"));
        }
        else
        {
            ui->C_5->setStyleSheet(QString("QPushButton {background-color: green;border:2px solid white;border-width: 2px;border-radius: 10px;border-color: beige;font: bold 14px;}"));

        }
        if(booking.at(18)=="booked")
        {
            ui->C_6->setStyleSheet(QString("QPushButton {background-color: red;border:2px solid white;border-width: 2px;border-radius: 10px;border-color: beige;font: bold 14px;}"));
        }
        else
        {
            ui->C_6->setStyleSheet(QString("QPushButton {background-color: green;border:2px solid white;border-width: 2px;border-radius: 10px;border-color: beige;font: bold 14px;}"));

        }
        if(booking.at(19)=="booked")
        {
            ui->D_1->setStyleSheet(QString("QPushButton {background-color: red;border:2px solid white;border-width: 2px;border-radius: 10px;border-color: beige;font: bold 14px;}"));
        }
        else
        {
            ui->D_1->setStyleSheet(QString("QPushButton {background-color: green;border:2px solid white;border-width: 2px;border-radius: 10px;border-color: beige;font: bold 14px;}"));

        }
        if(booking.at(20)=="booked")
        {
            ui->D_2->setStyleSheet(QString("QPushButton {background-color: red;border:2px solid white;border-width: 2px;border-radius: 10px;border-color: beige;font: bold 14px;}"));
        }
        else
        {
            ui->D_2->setStyleSheet(QString("QPushButton {background-color: green;border:2px solid white;border-width: 2px;border-radius: 10px;border-color: beige;font: bold 14px;}"));

        }
        if(booking.at(21)=="booked")
        {
            ui->D_3->setStyleSheet(QString("QPushButton {background-color: red;border:2px solid white;border-width: 2px;border-radius: 10px;border-color: beige;font: bold 14px;}"));
        }
        else
        {
            ui->D_3->setStyleSheet(QString("QPushButton {background-color: green;border:2px solid white;border-width: 2px;border-radius: 10px;border-color: beige;font: bold 14px;}"));

        }
        if(booking.at(22)=="booked")
        {
            ui->D_4->setStyleSheet(QString("QPushButton {background-color: red;border:2px solid white;border-width: 2px;border-radius: 10px;border-color: beige;font: bold 14px;}"));
        }
        else
        {
            ui->D_4->setStyleSheet(QString("QPushButton {background-color: green;border:2px solid white;border-width: 2px;border-radius: 10px;border-color: beige;font: bold 14px;}"));

        }
        if(booking.at(23)=="booked")
        {
            ui->D_5->setStyleSheet(QString("QPushButton {background-color: red;border:2px solid white;border-width: 2px;border-radius: 10px;border-color: beige;font: bold 14px;}"));
        }
        else
        {
            ui->D_5->setStyleSheet(QString("QPushButton {background-color: green;border:2px solid white;border-width: 2px;border-radius: 10px;border-color: beige;font: bold 14px;}"));

        }
        if(booking.at(24)=="booked")
        {
            ui->D_6->setStyleSheet(QString("QPushButton {background-color: red;border:2px solid white;border-width: 2px;border-radius: 10px;border-color: beige;font: bold 14px;}"));
        }
        else
        {
            ui->D_6->setStyleSheet(QString("QPushButton {background-color: green;border:2px solid white;border-width: 2px;border-radius: 10px;border-color: beige;font: bold 14px;}"));

        }
        if(booking.at(25)=="booked")
        {
            ui->E_1->setStyleSheet(QString("QPushButton {background-color: red;border:2px solid white;border-width: 2px;border-radius: 10px;border-color: beige;font: bold 14px;}"));
        }
        else
        {
            ui->E_1->setStyleSheet(QString("QPushButton {background-color:  rgb(159, 239, 0);border:2px solid white;border-width: 2px;border-radius: 10px;border-color: beige;font: bold 14px;}"));

        }
        if(booking.at(26)=="booked")
        {
            ui->E_2->setStyleSheet(QString("QPushButton {background-color: red;border:2px solid white;border-width: 2px;border-radius: 10px;border-color: beige;font: bold 14px;}"));
        }
        else
        {
            ui->E_2->setStyleSheet(QString("QPushButton {background-color: rgb(159, 239, 0);border:2px solid white;border-width: 2px;border-radius: 10px;border-color: beige;font: bold 14px;}"));

        }
        if(booking.at(27)=="booked")
        {
            ui->E_3->setStyleSheet(QString("QPushButton {background-color: red;border:2px solid white;border-width: 2px;border-radius: 10px;border-color: beige;font: bold 14px;}"));
        }
        else
        {
            ui->E_3->setStyleSheet(QString("QPushButton {background-color: rgb(159, 239, 0);border:2px solid white;border-width: 2px;border-radius: 10px;border-color: beige;font: bold 14px;}"));

        }
        if(booking.at(28)=="booked")
        {
            ui->E_4->setStyleSheet(QString("QPushButton {background-color: red;border:2px solid white;border-width: 2px;border-radius: 10px;border-color: beige;font: bold 14px;}"));
        }
        else
        {
            ui->E_4->setStyleSheet(QString("QPushButton {background-color: rgb(159, 239, 0);border:2px solid white;border-width: 2px;border-radius: 10px;border-color: beige;font: bold 14px;}"));

        }
        if(booking.at(29)=="booked")
        {
            ui->E_5->setStyleSheet(QString("QPushButton {background-color: red;border:2px solid white;border-width: 2px;border-radius: 10px;border-color: beige;font: bold 14px;}"));
        }
        else
        {
            ui->E_5->setStyleSheet(QString("QPushButton {background-color: rgb(159, 239, 0);border:2px solid white;border-width: 2px;border-radius: 10px;border-color: beige;font: bold 14px;}"));

        }
        if(booking.at(30)=="booked")
        {
            ui->E_6->setStyleSheet(QString("QPushButton {background-color: red;border:2px solid white;border-width: 2px;border-radius: 10px;border-color: beige;font: bold 14px;}"));
        }
        else
        {
            ui->E_6->setStyleSheet(QString("QPushButton {background-color: rgb(159, 239, 0);border:2px solid white;border-width: 2px;border-radius: 10px;border-color: beige;font: bold 14px;}"));

        }
        if(booking.at(31)=="booked")
        {
            ui->E_7->setStyleSheet(QString("QPushButton {background-color: red;border:2px solid white;border-width: 2px;border-radius: 10px;border-color: beige;font: bold 14px;}"));
        }
        else
        {
            ui->E_7->setStyleSheet(QString("QPushButton {background-color: rgb(159, 239, 0);border:2px solid white;border-width: 2px;border-radius: 10px;border-color: beige;font: bold 14px;}"));

        }
        if(booking.at(32)=="booked")
        {
            ui->E_8->setStyleSheet(QString("QPushButton {background-color: red;border:2px solid white;border-width: 2px;border-radius: 10px;border-color: beige;font: bold 14px;}"));
        }
        else
        {
            ui->E_8->setStyleSheet(QString("QPushButton {background-color: rgb(159, 239, 0);border:2px solid white;border-width: 2px;border-radius: 10px;border-color: beige;font: bold 14px;}"));

        }
        if(booking.at(33)=="booked")
        {
            ui->F_1->setStyleSheet(QString("QPushButton {background-color: red;border:2px solid white;border-width: 2px;border-radius: 10px;border-color: beige;font: bold 14px;}"));
        }
        else
        {
            ui->F_1->setStyleSheet(QString("QPushButton {background-color: rgb(159, 239, 0);border:2px solid white;border-width: 2px;border-radius: 10px;border-color: beige;font: bold 14px;}"));

        }
        if(booking.at(34)=="booked")
        {
            ui->F_2->setStyleSheet(QString("QPushButton {background-color: red;border:2px solid white;border-width: 2px;border-radius: 10px;border-color: beige;font: bold 14px;}"));
        }
        else
        {
            ui->F_2->setStyleSheet(QString("QPushButton {background-color: rgb(159, 239, 0);border:2px solid white;border-width: 2px;border-radius: 10px;border-color: beige;font: bold 14px;}"));

        }
        if(booking.at(35)=="booked")
        {
            ui->F_3->setStyleSheet(QString("QPushButton {background-color: red;border:2px solid white;border-width: 2px;border-radius: 10px;border-color: beige;font: bold 14px;}"));
        }
        else
        {
            ui->F_3->setStyleSheet(QString("QPushButton {background-color: rgb(159, 239, 0);border:2px solid white;border-width: 2px;border-radius: 10px;border-color: beige;font: bold 14px;}"));

        }
        if(booking.at(36)=="booked")
        {
            ui->F_4->setStyleSheet(QString("QPushButton {background-color: red;border:2px solid white;border-width: 2px;border-radius: 10px;border-color: beige;font: bold 14px;}"));
        }
        else
        {
            ui->F_4->setStyleSheet(QString("QPushButton {background-color: rgb(159, 239, 0);border:2px solid white;border-width: 2px;border-radius: 10px;border-color: beige;font: bold 14px;}"));

        }
        if(booking.at(37)=="booked")
        {
            ui->F_5->setStyleSheet(QString("QPushButton {background-color: red;border:2px solid white;border-width: 2px;border-radius: 10px;border-color: beige;font: bold 14px;}"));
        }
        else
        {
            ui->F_5->setStyleSheet(QString("QPushButton {background-color:rgb(159, 239, 0);border:2px solid white;border-width: 2px;border-radius: 10px;border-color: beige;font: bold 14px;}"));

        }
        if(booking.at(38)=="booked")
        {
            ui->F_6->setStyleSheet(QString("QPushButton {background-color: red;border:2px solid white;border-width: 2px;border-radius: 10px;border-color: beige;font: bold 14px;}"));
        }
        else
        {
            ui->F_6->setStyleSheet(QString("QPushButton {background-color: rgb(159, 239, 0);border:2px solid white;border-width: 2px;border-radius: 10px;border-color: beige;font: bold 14px;}"));

        }
        if(booking.at(39)=="booked")
        {
            ui->F_7->setStyleSheet(QString("QPushButton {background-color: red;border:2px solid white;border-width: 2px;border-radius: 10px;border-color: beige;font: bold 14px;}"));
        }
        else
        {
            ui->F_7->setStyleSheet(QString("QPushButton {background-color: rgb(159, 239, 0);border:2px solid white;border-width: 2px;border-radius: 10px;border-color: beige;font: bold 14px;}"));

        }
        if(booking.at(40)=="booked")
        {
            ui->F_8->setStyleSheet(QString("QPushButton {background-color: red;border:2px solid white;border-width: 2px;border-radius: 10px;border-color: beige;font: bold 14px;}"));
        }
        else
        {
            ui->F_8->setStyleSheet(QString("QPushButton {background-color: rgb(159, 239, 0);border:2px solid white;border-width: 2px;border-radius: 10px;border-color: beige;font: bold 14px;}"));

        }
        if(booking.at(41)=="booked")
        {
            ui->G_1->setStyleSheet(QString("QPushButton {background-color: red;border:2px solid white;border-width: 2px;border-radius: 10px;border-color: beige;font: bold 14px;}"));
        }
        else
        {
            ui->G_1->setStyleSheet(QString("QPushButton {background-color: rgb(159, 239, 0);border:2px solid white;border-width: 2px;border-radius: 10px;border-color: beige;font: bold 14px;}"));

        }
        if(booking.at(42)=="booked")
        {
            ui->G_2->setStyleSheet(QString("QPushButton {background-color: red;border:2px solid white;border-width: 2px;border-radius: 10px;border-color: beige;font: bold 14px;}"));
        }
        else
        {
            ui->G_2->setStyleSheet(QString("QPushButton {background-color: rgb(159, 239, 0);border:2px solid white;border-width: 2px;border-radius: 10px;border-color: beige;font: bold 14px;}"));

        }
        if(booking.at(43)=="booked")
        {
            ui->G_3->setStyleSheet(QString("QPushButton {background-color: red;border:2px solid white;border-width: 2px;border-radius: 10px;border-color: beige;font: bold 14px;}"));
        }
        else
        {
            ui->G_3->setStyleSheet(QString("QPushButton {background-color: rgb(159, 239, 0);border:2px solid white;border-width: 2px;border-radius: 10px;border-color: beige;font: bold 14px;}"));

        }
        if(booking.at(44)=="booked")
        {
            ui->G_4->setStyleSheet(QString("QPushButton {background-color: red;border:2px solid white;border-width: 2px;border-radius: 10px;border-color: beige;font: bold 14px;}"));
        }
        else
        {
            ui->G_4->setStyleSheet(QString("QPushButton {background-color: rgb(159, 239, 0);border:2px solid white;border-width: 2px;border-radius: 10px;border-color: beige;font: bold 14px;}"));

        }
        if(booking.at(45)=="booked")
        {
            ui->G_5->setStyleSheet(QString("QPushButton {background-color: red;border:2px solid white;border-width: 2px;border-radius: 10px;border-color: beige;font: bold 14px;}"));
        }
        else
        {
            ui->G_5->setStyleSheet(QString("QPushButton {background-color: rgb(159, 239, 0);border:2px solid white;border-width: 2px;border-radius: 10px;border-color: beige;font: bold 14px;}"));

        }
        if(booking.at(46)=="booked")
        {
            ui->G_6->setStyleSheet(QString("QPushButton {background-color: red;border:2px solid white;border-width: 2px;border-radius: 10px;border-color: beige;font: bold 14px;}"));
        }
        else
        {
            ui->G_6->setStyleSheet(QString("QPushButton {background-color: rgb(159, 239, 0);border:2px solid white;border-width: 2px;border-radius: 10px;border-color: beige;font: bold 14px;}"));

        }
        if(booking.at(47)=="booked")
        {
            ui->G_7->setStyleSheet(QString("QPushButton {background-color: red;border:2px solid white;border-width: 2px;border-radius: 10px;border-color: beige;font: bold 14px;}"));
        }
        else
        {
            ui->G_7->setStyleSheet(QString("QPushButton {background-color: rgb(159, 239, 0);border:2px solid white;border-width: 2px;border-radius: 10px;border-color: beige;font: bold 14px;}"));

        }
        if(booking.at(48)=="booked")
        {
            ui->G_8->setStyleSheet(QString("QPushButton {background-color: red;border:2px solid white;border-width: 2px;border-radius: 10px;border-color: beige;font: bold 14px;}"));
        }
        else
        {
            ui->G_8->setStyleSheet(QString("QPushButton {background-color: rgb(159, 239, 0);border:2px solid white;border-width: 2px;border-radius: 10px;border-color: beige;font: bold 14px;}"));

        }
        if(booking.at(49)=="booked")
        {
            ui->H_1->setStyleSheet(QString("QPushButton {background-color: red;border:2px solid white;border-width: 2px;border-radius: 10px;border-color: beige;font: bold 14px;}"));
        }
        else
        {
            ui->H_1->setStyleSheet(QString("QPushButton {background-color: rgb(0, 255, 0);border:2px solid white;border-width: 2px;border-radius: 10px;border-color: beige;font: bold 14px;}"));

        }
        if(booking.at(50)=="booked")
        {
            ui->H_2->setStyleSheet(QString("QPushButton {background-color: red;border:2px solid white;border-width: 2px;border-radius: 10px;border-color: beige;font: bold 14px;}"));
        }
        else
        {
            ui->H_2->setStyleSheet(QString("QPushButton {background-color:  rgb(0, 255, 0);border:2px solid white;border-width: 2px;border-radius: 10px;border-color: beige;font: bold 14px;}"));

        }
        if(booking.at(51)=="booked")
        {
            ui->H_3->setStyleSheet(QString("QPushButton {background-color: red;border:2px solid white;border-width: 2px;border-radius: 10px;border-color: beige;font: bold 14px;}"));
        }
        else
        {
            ui->H_3->setStyleSheet(QString("QPushButton {background-color: rgb(0, 255, 0);border:2px solid white;border-width: 2px;border-radius: 10px;border-color: beige;font: bold 14px;}"));

        }
        if(booking.at(52)=="booked")
        {
            ui->H_4->setStyleSheet(QString("QPushButton {background-color: red;border:2px solid white;border-width: 2px;border-radius: 10px;border-color: beige;font: bold 14px;}"));
        }
        else
        {
            ui->H_4->setStyleSheet(QString("QPushButton {background-color: rgb(0, 255, 0);border:2px solid white;border-width: 2px;border-radius: 10px;border-color: beige;font: bold 14px;}"));

        }
        if(booking.at(53)=="booked")
        {
            ui->H_5->setStyleSheet(QString("QPushButton {background-color: red;border:2px solid white;border-width: 2px;border-radius: 10px;border-color: beige;font: bold 14px;}"));
        }
        else
        {
            ui->H_5->setStyleSheet(QString("QPushButton {background-color: rgb(0, 255, 0);border:2px solid white;border-width: 2px;border-radius: 10px;border-color: beige;font: bold 14px;}"));

        }
        if(booking.at(54)=="booked")
        {
            ui->H_6->setStyleSheet(QString("QPushButton {background-color: red;border:2px solid white;border-width: 2px;border-radius: 10px;border-color: beige;font: bold 14px;}"));
        }
        else
        {
            ui->H_6->setStyleSheet(QString("QPushButton {background-color: rgb(0, 255, 0);border:2px solid white;border-width: 2px;border-radius: 10px;border-color: beige;font: bold 14px;}"));

        }
        if(booking.at(55)=="booked")
        {
            ui->H_7->setStyleSheet(QString("QPushButton {background-color: red;border:2px solid white;border-width: 2px;border-radius: 10px;border-color: beige;font: bold 14px;}"));
        }
        else
        {
            ui->H_7->setStyleSheet(QString("QPushButton {background-color: rgb(0, 255, 0);border:2px solid white;border-width: 2px;border-radius: 10px;border-color: beige;font: bold 14px;}"));

        }
        if(booking.at(56)=="booked")
        {
            ui->H_8->setStyleSheet(QString("QPushButton {background-color: red;border:2px solid white;border-width: 2px;border-radius: 10px;border-color: beige;font: bold 14px;}"));
        }
        else
        {
            ui->H_8->setStyleSheet(QString("QPushButton {background-color: rgb(0, 255, 0);border:2px solid white;border-width: 2px;border-radius: 10px;border-color: beige;font: bold 14px;}"));

        }
        if(booking.at(57)=="booked")
        {
            ui->H_9->setStyleSheet(QString("QPushButton {background-color: red;border:2px solid white;border-width: 2px;border-radius: 10px;border-color: beige;font: bold 14px;}"));
        }
        else
        {
            ui->H_9->setStyleSheet(QString("QPushButton {background-color: rgb(0, 255, 0);border:2px solid white;border-width: 2px;border-radius: 10px;border-color: beige;font: bold 14px;}"));

        }
        if(booking.at(58)=="booked")
        {
            ui->I_1->setStyleSheet(QString("QPushButton {background-color: red;border:2px solid white;border-width: 2px;border-radius: 10px;border-color: beige;font: bold 14px;}"));
        }
        else
        {
            ui->I_1->setStyleSheet(QString("QPushButton {background-color: rgb(0, 255, 0);border:2px solid white;border-width: 2px;border-radius: 10px;border-color: beige;font: bold 14px;}"));

        }
        if(booking.at(59)=="booked")
        {
            ui->I_2->setStyleSheet(QString("QPushButton {background-color: red;border:2px solid white;border-width: 2px;border-radius: 10px;border-color: beige;font: bold 14px;}"));
        }
        else
        {
            ui->I_2->setStyleSheet(QString("QPushButton {background-color: rgb(0, 255, 0);border:2px solid white;border-width: 2px;border-radius: 10px;border-color: beige;font: bold 14px;}"));

        }
        if(booking.at(60)=="booked")
        {
            ui->I_3->setStyleSheet(QString("QPushButton {background-color: red;border:2px solid white;border-width: 2px;border-radius: 10px;border-color: beige;font: bold 14px;}"));
        }
        else
        {
            ui->I_3->setStyleSheet(QString("QPushButton {background-color: rgb(0, 255, 0);border:2px solid white;border-width: 2px;border-radius: 10px;border-color: beige;font: bold 14px;}"));

        }
        if(booking.at(61)=="booked")
        {
            ui->I_4->setStyleSheet(QString("QPushButton {background-color: red;border:2px solid white;border-width: 2px;border-radius: 10px;border-color: beige;font: bold 14px;}"));
        }
        else
        {
            ui->I_4->setStyleSheet(QString("QPushButton {background-color: rgb(0, 255, 0);border:2px solid white;border-width: 2px;border-radius: 10px;border-color: beige;font: bold 14px;}"));

        }
        if(booking.at(62)=="booked")
        {
            ui->I_5->setStyleSheet(QString("QPushButton {background-color: red;border:2px solid white;border-width: 2px;border-radius: 10px;border-color: beige;font: bold 14px;}"));
        }
        else
        {
            ui->I_5->setStyleSheet(QString("QPushButton {background-color: rgb(0, 255, 0);border:2px solid white;border-width: 2px;border-radius: 10px;border-color: beige;font: bold 14px;}"));

        }
        if(booking.at(63)=="booked")
        {
            ui->I_6->setStyleSheet(QString("QPushButton {background-color: red;border:2px solid white;border-width: 2px;border-radius: 10px;border-color: beige;font: bold 14px;}"));
        }
        else
        {
            ui->I_6->setStyleSheet(QString("QPushButton {background-color: rgb(0, 255, 0);border:2px solid white;border-width: 2px;border-radius: 10px;border-color: beige;font: bold 14px;}"));

        }
        if(booking.at(64)=="booked")
        {
            ui->I_7->setStyleSheet(QString("QPushButton {background-color: red;border:2px solid white;border-width: 2px;border-radius: 10px;border-color: beige;font: bold 14px;}"));
        }
        else
        {
            ui->I_7->setStyleSheet(QString("QPushButton {background-color: rgb(0, 255, 0);border:2px solid white;border-width: 2px;border-radius: 10px;border-color: beige;font: bold 14px;}"));

        }
        if(booking.at(65)=="booked")
        {
            ui->I_8->setStyleSheet(QString("QPushButton {background-color: red;border:2px solid white;border-width: 2px;border-radius: 10px;border-color: beige;font: bold 14px;}"));
        }
        else
        {
            ui->I_8->setStyleSheet(QString("QPushButton {background-color: rgb(0, 255, 0);border:2px solid white;border-width: 2px;border-radius: 10px;border-color: beige;font: bold 14px;}"));

        }
        if(booking.at(66)=="booked")
        {
            ui->I_9->setStyleSheet(QString("QPushButton {background-color: red;border:2px solid white;border-width: 2px;border-radius: 10px;border-color: beige;font: bold 14px;}"));
        }
        else
        {
            ui->I_9->setStyleSheet(QString("QPushButton {background-color: rgb(0, 255, 0);border:2px solid white;border-width: 2px;border-radius: 10px;border-color: beige;font: bold 14px;}"));

        }
        if(booking.at(67)=="booked")
        {
            ui->J_1->setStyleSheet(QString("QPushButton {background-color: red;border:2px solid white;border-width: 2px;border-radius: 10px;border-color: beige;font: bold 14px;}"));
        }
        else
        {
            ui->J_1->setStyleSheet(QString("QPushButton {background-color: rgb(0, 255, 0);border:2px solid white;border-width: 2px;border-radius: 10px;border-color: beige;font: bold 14px;}"));

        }
        if(booking.at(68)=="booked")
        {
            ui->J_2->setStyleSheet(QString("QPushButton {background-color: red;border:2px solid white;border-width: 2px;border-radius: 10px;border-color: beige;font: bold 14px;}"));
        }
        else
        {
            ui->J_2->setStyleSheet(QString("QPushButton {background-color: rgb(0, 255, 0);border:2px solid white;border-width: 2px;border-radius: 10px;border-color: beige;font: bold 14px;}"));

        }
        if(booking.at(69)=="booked")
        {
            ui->J_3->setStyleSheet(QString("QPushButton {background-color: red;border:2px solid white;border-width: 2px;border-radius: 10px;border-color: beige;font: bold 14px;}"));
        }
        else
        {
            ui->J_3->setStyleSheet(QString("QPushButton {background-color: rgb(0, 255, 0);border:2px solid white;border-width: 2px;border-radius: 10px;border-color: beige;font: bold 14px;}"));

        }
        if(booking.at(70)=="booked")
        {
            ui->J_4->setStyleSheet(QString("QPushButton {background-color: red;border:2px solid white;border-width: 2px;border-radius: 10px;border-color: beige;font: bold 14px;}"));
        }
        else
        {
            ui->J_4->setStyleSheet(QString("QPushButton {background-color: rgb(0, 255, 0);border:2px solid white;border-width: 2px;border-radius: 10px;border-color: beige;font: bold 14px;}"));

        }
        if(booking.at(71)=="booked")
        {
            ui->J_5->setStyleSheet(QString("QPushButton {background-color: red;border:2px solid white;border-width: 2px;border-radius: 10px;border-color: beige;font: bold 14px;}"));
        }
        else
        {
            ui->J_5->setStyleSheet(QString("QPushButton {background-color: rgb(0, 255, 0);border:2px solid white;border-width: 2px;border-radius: 10px;border-color: beige;font: bold 14px;}"));

        }
        if(booking.at(72)=="booked")
        {
            ui->J_6->setStyleSheet(QString("QPushButton {background-color: red;border:2px solid white;border-width: 2px;border-radius: 10px;border-color: beige;font: bold 14px;}"));
        }
        else
        {
            ui->J_6->setStyleSheet(QString("QPushButton {background-color: rgb(0, 255, 0);border:2px solid white;border-width: 2px;border-radius: 10px;border-color: beige;font: bold 14px;}"));

        }
        if(booking.at(73)=="booked")
        {
            ui->J_7->setStyleSheet(QString("QPushButton {background-color: red;border:2px solid white;border-width: 2px;border-radius: 10px;border-color: beige;font: bold 14px;}"));
        }
        else
        {
            ui->J_7->setStyleSheet(QString("QPushButton {background-color: rgb(0, 255, 0);border:2px solid white;border-width: 2px;border-radius: 10px;border-color: beige;font: bold 14px;}"));

        }
        if(booking.at(74)=="booked")
        {
            ui->J_8->setStyleSheet(QString("QPushButton {background-color: red;border:2px solid white;border-width: 2px;border-radius: 10px;border-color: beige;font: bold 14px;}"));
        }
        else
        {
            ui->J_8->setStyleSheet(QString("QPushButton {background-color: rgb(0, 255, 0);border:2px solid white;border-width: 2px;border-radius: 10px;border-color: beige;font: bold 14px;}"));

        }
        if(booking.at(75)=="booked")
        {
            ui->J_9->setStyleSheet(QString("QPushButton {background-color: red;border:2px solid white;border-width: 2px;border-radius: 10px;border-color: beige;font: bold 14px;}"));
        }
        else
        {
            ui->J_9->setStyleSheet(QString("QPushButton {background-color: rgb(0, 255, 0);border:2px solid white;border-width: 2px;border-radius: 10px;border-color: beige;font: bold 14px;}"));

        }


    }
    ui->SHEDULE_CHECK_7->setItem(0,0,new QTableWidgetItem(booking.at(81)));
    ui->SHEDULE_CHECK_7->setItem(1,0,new QTableWidgetItem(booking.at(82)));
    ui->SHEDULE_CHECK_7->setItem(2,0,new QTableWidgetItem(booking.at(83)));
    ui->SHEDULE_CHECK_7->setItem(3,0,new QTableWidgetItem(booking.at(76)));
    ui->SHEDULE_CHECK_7->setItem(4,0,new QTableWidgetItem(booking.at(77)));
    ui->SHEDULE_CHECK_7->setItem(5,0,new QTableWidgetItem(booking.at(78)));
    ui->SHEDULE_CHECK_7->setItem(6,0,new QTableWidgetItem(booking.at(79)));
    ui->SHEDULE_CHECK_7->setItem(7,0,new QTableWidgetItem(booking.at(80)));
    ui->stackedWidget->setCurrentIndex(19);
    }
    }
    else if(booking.at(0)=="CLOSED"){
    QMessageBox :: warning(this,"FLIGHT","Flight Closed!!!");
    }
    else
    {
      QMessageBox :: warning(this,"FLIGHT","Wrong Flight ID");
    }
}
void MainWindow::on_CHECK_FLIGHT_BTN_clicked()
{

}


void MainWindow::on_pushButton_15_clicked()
{
    ui->stackedWidget->setCurrentIndex(20);
}


void MainWindow::on_pushButton_16_clicked()
{
    ui->stackedWidget->setCurrentIndex(6);
}


void MainWindow::on_pushButton_22_clicked()
{
    ui->stackedWidget->setCurrentIndex(6);
}


void MainWindow::on_pushButton_21_clicked()
{


    QVector<QString>closing_id,closing_password;
    int i=0;
    QFile Fiiole("Registration_ADMIN.txt");
    if(Fiiole.open(QIODevice::ReadOnly))
    {
        QTextStream stream(&Fiiole);
        QString FileData1,FileData2;
        while ( stream.atEnd()==false)
        {
        FileData1 = stream.readLine();
        closing_id.push_back(FileData1);
        FileData2 = stream.readLine();
        closing_password.push_back(FileData2);
        i++;
        }
    }
    Fiiole.close();
    QString close_ADMIN_IDE,close_CEO_PASSWORDE1,close_CEO_PASSWORDE2;
    close_ADMIN_IDE=ui->CLOSE_ADMIN_ID->text();
    close_CEO_PASSWORDE1 =ui->CLOSE_CEO_PASSWORD_1->text();
    close_CEO_PASSWORDE2 =ui->CLOSE_CEO_PASSWORD_2->text();
    QFile Fiile("CEO_TIME.txt");
    if(Fiile.open(QIODevice::ReadOnly))
    {
        QTextStream stream(&Fiile);
        while ( stream.atEnd()==false)
        {
        CEO_ID = stream.readLine();
        CEO_PASSWORD_1 = stream.readLine();
        CEO_PASSWORD_2 = stream.readLine();        }
    }
        if(close_CEO_PASSWORDE1==CEO_PASSWORD_1 && close_CEO_PASSWORDE2==CEO_PASSWORD_2)
        {
         QFile Filleo("Registration_ADMIN.txt");
         if(Filleo.open(QIODevice::WriteOnly))
         {
            QTextStream stream(&Filleo);
            for(int j=0;j<i;j++)
            {
                if(closing_id.at(j)==close_ADMIN_IDE)continue;
                stream<< closing_id.at(j) + "\n";
                stream<< closing_password.at(j) + "\n";
            }
         }
         Filleo.close();
         ui->stackedWidget->setCurrentIndex(11);

        }
        else
        {
        QMessageBox :: warning(this,"login","Wrong Email Or Password");
        }
    ui->CLOSE_ADMIN_ID->clear();
    ui->CLOSE_CEO_PASSWORD_1->clear();
    ui->CLOSE_CEO_PASSWORD_2->clear();
}


void MainWindow::on_ADMIN_CLOSE_CEO_clicked()
{
    ui->stackedWidget->setCurrentIndex(15);
}


void MainWindow::on_ADMIN_INFO_CEO_clicked()
{
    ui->stackedWidget->setCurrentIndex(16);
    QVector<QString>ADMIN_IDI,ADMIN_PASSWORD_I;
    QFile Ffiiile("Registration_ADMIN.txt");
    int i=0;
    if(Ffiiile.open(QIODevice::ReadOnly))
    {
        QTextStream stream(&Ffiiile);
        QString FileData1,FileData2;
        while ( stream.atEnd()==false)
        {
            FileData1 = stream.readLine();
            ADMIN_IDI.push_back(FileData1);
            FileData2 = stream.readLine();
            ADMIN_PASSWORD_I.push_back(FileData2);
            i++;
        }
    }
    Ffiiile.close();
    ui->SHEDULE_CHECK_6->setRowCount(i);
    for(int j=0;j<i;j++)
    {
        ui->SHEDULE_CHECK_6->setItem(j,0,new QTableWidgetItem(ADMIN_IDI.at(j)));
        ui->SHEDULE_CHECK_6->setItem(j,1,new QTableWidgetItem(ADMIN_PASSWORD_I.at(j)));
    }

}


void MainWindow::on_pushButton_27_clicked()
{
    ui->stackedWidget->setCurrentIndex(6);
}


void MainWindow::on_pushButton_26_clicked()
{
    ui->stackedWidget->setCurrentIndex(11);
}


void MainWindow::on_EXIR_clicked()
{
    ui->stackedWidget->setCurrentIndex(6);
}


void MainWindow::on_back_clicked()
{
    ui->stackedWidget->setCurrentIndex(20);
}


void MainWindow::on_flight_cncl_btn_clicked()
{
    QString cnclflight,admn_id,admn_pass,macthed_ADMIN_idr,macthed_ADMIN_passwordr;
    cnclflight = ui->flight_cncl_id->text();
    admn_id = ui->admin_id->text();
    admn_pass = ui ->admin_password->text();

    int i=0;
    QVector<QString>ADMIN_iid,ADMIN_ppassword;
    QFile Fiile("Registration_ADMIN.txt");
    if(Fiile.open(QIODevice::ReadOnly))
    {
        QTextStream stream(&Fiile);
        QString FileData1,FileData2;
        while ( stream.atEnd()==false)
        {
            FileData1 = stream.readLine();
            ADMIN_iid.push_back(FileData1);
            FileData2 = stream.readLine();
            ADMIN_ppassword.push_back(FileData2);
            i++;
        }
    }
    int alpa=ADMIN_iid.indexOf(login_ADMIN_id);
    if(alpa!=-1){
        macthed_ADMIN_idr=ADMIN_iid.at(alpa);
        macthed_ADMIN_passwordr=ADMIN_ppassword.at(alpa);
        if(macthed_ADMIN_idr ==admn_id && macthed_ADMIN_passwordr==admn_pass)
        {

            QVector<QString>FRoOM_D,TO_oD,S_DATE_oD,S_SRNO_oD,STRT_TIME_oD,END_TIME_oD,DAY;
            QFile Fiiile("FLIGHT.txt");
            int i=0;
            if(Fiiile.open(QIODevice::ReadOnly))
            {
                QTextStream stream(&Fiiile);
                QString FileData1,FileData2,FileData3,FileData4,FileData5,FileData6;
                while ( stream.atEnd()==false)
                {
                    FileData1 = stream.readLine();
                    S_SRNO_oD.push_back(FileData1);
                    FileData2 = stream.readLine();
                    FRoOM_D.push_back(FileData2);
                    FileData3 = stream.readLine();
                    TO_oD.push_back(FileData3);
                    FileData4 = stream.readLine();
                    STRT_TIME_oD.push_back(FileData4);
                    FileData5 = stream.readLine();
                    END_TIME_oD.push_back(FileData5);
                    FileData6 = stream.readLine();
                    S_DATE_oD.push_back(FileData6);
                    DAY.push_back(stream.readLine());
                    i++;
                }
            }
            Fiiile.close();
            QFile Fiele("FLIGHT.txt");
            if(Fiele.open(QIODevice::WriteOnly))
            {
                QTextStream stream(&Fiele);
                for(int j=0;j<i;j++){
                    if(S_SRNO_oD.at(j)==cnclflight)continue;
                stream<< S_SRNO_oD.at(j)+"\n";
                stream<< FRoOM_D.at(j)+"\n";
                stream<< TO_oD.at(j)+"\n";
                stream<< STRT_TIME_oD.at(j)+"\n";
                stream<< END_TIME_oD.at(j)+"\n";
                stream<< S_DATE_oD.at(j)+"\n";
                stream<< DAY.at(j)+"\n";
                }
            }
            Fiele.close();
            QVector<QString>flight_id_c;
            QFile FFF("flight_id.txt");
            int rr=0;
            if(FFF.open(QIODevice::ReadOnly))
            {
                QTextStream stream(&FFF);
                flight_id_c.push_back( stream.readLine());
                rr++;
            }
            FFF.close();
            QFile FF("flight_id.txt");
            if(FF.open(QIODevice::WriteOnly))
            {
                QTextStream stream(&FF);
                for(int l=0;l<rr;l++)
                {
                if(flight_id_c.at(l)==cnclflight)continue;
                stream<< flight_id_c.at(l)+"\n";
                }
            }
            FF.close();



        }
        else
        {
            QMessageBox :: warning(this,"login","Wrong Email Or Password");
        }
    }
    else
    {
        QMessageBox :: warning(this,"login","Contact CEO");
    }

    ui->flight_cncl_id->clear();
    ui->admin_id->clear();
    ui ->admin_password->clear();
    ui->stackedWidget->setCurrentIndex(9);
}


void MainWindow::on_CENCEL_FLIGHT_BTN_clicked()
{
    ui->stackedWidget->setCurrentIndex(17);
}


void MainWindow::on_pushButton_7_clicked()
{
    ui->stackedWidget->setCurrentIndex(11);
}


void MainWindow::on_pushButton_9_clicked()
{
    ui->stackedWidget->setCurrentIndex(20);
}


void MainWindow::on_pushButton_28_clicked()
{
    ui->stackedWidget->setCurrentIndex(11);
}


void MainWindow::on_pushButton_10_clicked()
{
    ui->stackedWidget->setCurrentIndex(6);
}


void MainWindow::on_pushButton_11_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}


void MainWindow::on_CEO_TRANSFER_clicked()
{
    ui->stackedWidget->setCurrentIndex(18);
}


void MainWindow::on_TRANSPER_CEO_clicked()
{
    QString P_in_CEO1_password,P_in_CEO2_password,N_CEO_id,N_in_CEO1_password,N_in_CEO2_password;
    QString ceo_id,ceo_pass1,ceo_pass2;

    P_in_CEO1_password = ui->P_ceo_pass1->text();
    P_in_CEO2_password = ui->P_ceo_pass2->text();
    N_CEO_id = ui->N_ceo_ID->text();
    N_in_CEO1_password = ui->N_ceo_pass1->text();
    N_in_CEO2_password = ui->N_ceo_pass2->text();
    QFile Fiilee("CEO_TIME.txt");
    if(Fiilee.open(QIODevice::ReadOnly))
    {
        QTextStream stream(&Fiilee);
        while ( stream.atEnd()==false)
        {
            ceo_id = stream.readLine();
            ceo_pass1 = stream.readLine();
            ceo_pass2 = stream.readLine();
        }
    }
    else
    {
        QMessageBox :: warning(this,"login","Register first");
    }
    Fiilee.close();

    if(ceo_pass1==P_in_CEO1_password && ceo_pass2==P_in_CEO2_password)
    {
        QFile Fiiee("CEO_TIME.txt");
        if(Fiiee.open(QIODevice::WriteOnly))
        {
            QTextStream stream(&Fiiee);
            stream<< ui->N_ceo_ID-> text() + "\n";
            stream<< ui->N_ceo_pass1-> text() + "\n";
            stream<< ui->N_ceo_pass2-> text() + "\n";

        }
        Fiiee.close();
        ui->stackedWidget->setCurrentIndex(6);
    }
    else
    {
        QMessageBox :: warning(this,"login","Wrong Email Or Password");
    }

    ui->P_ceo_pass1->clear();
    ui->P_ceo_pass2->clear();
    ui->N_ceo_ID->clear();
    ui->N_ceo_pass1->clear();
    ui->N_ceo_pass2->clear();
}


void MainWindow::on_pushButton_12_clicked()
{
    ui->stackedWidget->setCurrentIndex(6);
}


void MainWindow::on_pushButton_13_clicked()
{
        QVector<QString>booking,flight_find;
        QString sl;
        Flight_choice = ui->lineEdit->text();
        QFile FR("flight_id.txt");
        if(FR.open(QIODevice::ReadOnly))
        {
            QTextStream stream(&FR);
            while ( stream.atEnd()==false)
            {
                flight_find.push_back(stream.readLine());
            }

        }
        FR.close();
        ui->Flight_no_in->clear();
        int alap=flight_find.indexOf(Flight_choice);
        if(alap!=-1){
            ui->stackedWidget->setCurrentIndex(22);
            int jr=0;
            QFile Fiiree(Flight_choice);
            if(Fiiree.open(QIODevice::ReadOnly))
            {
                QTextStream stream(&Fiiree);
                while ( stream.atEnd()==false)
                {
                sl = stream.readLine();
                booking.push_back(sl);
                jr++;
                }
            }

            Fiiree.close();
            {
                for(int i=0;i<=75;i++)
                {
                if(booking.at(0)=="OPENED")
                {

                }
                if(booking.at(1)=="booked")
                {
                    ui->a1->setStyleSheet(QString("QPushButton {background-color: red;border:2px solid white;border-width: 2px;border-radius: 10px;border-color: beige;font: bold 14px;}"));
                }
                else
                {
                    ui->a1->setStyleSheet(QString("QPushButton {background-color: green;border:2px solid white;border-width: 2px;border-radius: 10px;border-color: beige;font: bold 14px;}"));

                }
                if(booking.at(2)=="booked")
                {
                    ui->a2->setStyleSheet(QString("QPushButton {background-color: red;border:2px solid white;border-width: 2px;border-radius: 10px;border-color: beige;font: bold 14px;}"));
                }
                else
                {
                    ui->a2->setStyleSheet(QString("QPushButton {background-color: green;border:2px solid white;border-width: 2px;border-radius: 10px;border-color: beige;font: bold 14px;}"));

                }
                if(booking.at(3)=="booked")
                {
                    ui->a3->setStyleSheet(QString("QPushButton {background-color: red;border:2px solid white;border-width: 2px;border-radius: 10px;border-color: beige;font: bold 14px;}"));
                }
                else
                {
                    ui->a3->setStyleSheet(QString("QPushButton {background-color: green;border:2px solid white;border-width: 2px;border-radius: 10px;border-color: beige;font: bold 14px;}"));

                }
                if(booking.at(4)=="booked")
                {
                    ui->a4->setStyleSheet(QString("QPushButton {background-color: red;border:2px solid white;border-width: 2px;border-radius: 10px;border-color: beige;font: bold 14px;}"));
                }
                else
                {
                    ui->a4->setStyleSheet(QString("QPushButton {background-color: green;border:2px solid white;border-width: 2px;border-radius: 10px;border-color: beige;font: bold 14px;}"));

                }
                if(booking.at(5)=="booked")
                {
                    ui->a5->setStyleSheet(QString("QPushButton {background-color: red;border:2px solid white;border-width: 2px;border-radius: 10px;border-color: beige;font: bold 14px;}"));
                }
                else
                {
                    ui->a5->setStyleSheet(QString("QPushButton {background-color: green;border:2px solid white;border-width: 2px;border-radius: 10px;border-color: beige;font: bold 14px;}"));

                }
                if(booking.at(6)=="booked")
                {
                    ui->a6->setStyleSheet(QString("QPushButton {background-color: red;border:2px solid white;border-width: 2px;border-radius: 10px;border-color: beige;font: bold 14px;}"));
                }
                else
                {
                    ui->a6->setStyleSheet(QString("QPushButton {background-color: green;border:2px solid white;border-width: 2px;border-radius: 10px;border-color: beige;font: bold 14px;}"));

                }
                if(booking.at(7)=="booked")
                {
                    ui->b1->setStyleSheet(QString("QPushButton {background-color: red;border:2px solid white;border-width: 2px;border-radius: 10px;border-color: beige;font: bold 14px;}"));
                }
                else
                {
                    ui->b1->setStyleSheet(QString("QPushButton {background-color: green;border:2px solid white;border-width: 2px;border-radius: 10px;border-color: beige;font: bold 14px;}"));

                }
                if(booking.at(8)=="booked")
                {
                    ui->b2->setStyleSheet(QString("QPushButton {background-color: red;border:2px solid white;border-width: 2px;border-radius: 10px;border-color: beige;font: bold 14px;}"));
                }
                else
                {
                    ui->b2->setStyleSheet(QString("QPushButton {background-color: green;border:2px solid white;border-width: 2px;border-radius: 10px;border-color: beige;font: bold 14px;}"));

                }
                if(booking.at(9)=="booked")
                {
                    ui->b3->setStyleSheet(QString("QPushButton {background-color: red;border:2px solid white;border-width: 2px;border-radius: 10px;border-color: beige;font: bold 14px;}"));
                }
                else
                {
                    ui->b3->setStyleSheet(QString("QPushButton {background-color: green;border:2px solid white;border-width: 2px;border-radius: 10px;border-color: beige;font: bold 14px;}"));

                }
                if(booking.at(10)=="booked")
                {
                    ui->b4->setStyleSheet(QString("QPushButton {background-color: red;border:2px solid white;border-width: 2px;border-radius: 10px;border-color: beige;font: bold 14px;}"));
                }
                else
                {
                    ui->b4->setStyleSheet(QString("QPushButton {background-color: green;border:2px solid white;border-width: 2px;border-radius: 10px;border-color: beige;font: bold 14px;}"));

                }
                if(booking.at(11)=="booked")
                {
                    ui->b5->setStyleSheet(QString("QPushButton {background-color: red;border:2px solid white;border-width: 2px;border-radius: 10px;border-color: beige;font: bold 14px;}"));
                }
                else
                {
                    ui->b5->setStyleSheet(QString("QPushButton {background-color: green;border:2px solid white;border-width: 2px;border-radius: 10px;border-color: beige;font: bold 14px;}"));

                }
                if(booking.at(12)=="booked")
                {
                    ui->b6->setStyleSheet(QString("QPushButton {background-color: red;border:2px solid white;border-width: 2px;border-radius: 10px;border-color: beige;font: bold 14px;}"));
                }
                else
                {
                    ui->b6->setStyleSheet(QString("QPushButton {background-color: green;border:2px solid white;border-width: 2px;border-radius: 10px;border-color: beige;font: bold 14px;}"));

                }
                if(booking.at(13)=="booked")
                {
                    ui->c1->setStyleSheet(QString("QPushButton {background-color: red;border:2px solid white;border-width: 2px;border-radius: 10px;border-color: beige;font: bold 14px;}"));
                }
                else
                {
                    ui->c1->setStyleSheet(QString("QPushButton {background-color: green;border:2px solid white;border-width: 2px;border-radius: 10px;border-color: beige;font: bold 14px;}"));

                }
                if(booking.at(14)=="booked")
                {
                    ui->c2->setStyleSheet(QString("QPushButton {background-color: red;border:2px solid white;border-width: 2px;border-radius: 10px;border-color: beige;font: bold 14px;}"));
                }
                else
                {
                    ui->c2->setStyleSheet(QString("QPushButton {background-color: green;border:2px solid white;border-width: 2px;border-radius: 10px;border-color: beige;font: bold 14px;}"));

                }
                if(booking.at(15)=="booked")
                {
                    ui->c3->setStyleSheet(QString("QPushButton {background-color: red;border:2px solid white;border-width: 2px;border-radius: 10px;border-color: beige;font: bold 14px;}"));
                }
                else
                {
                    ui->c3->setStyleSheet(QString("QPushButton {background-color: green;border:2px solid white;border-width: 2px;border-radius: 10px;border-color: beige;font: bold 14px;}"));

                }
                if(booking.at(16)=="booked")
                {
                    ui->c4->setStyleSheet(QString("QPushButton {background-color: red;border:2px solid white;border-width: 2px;border-radius: 10px;border-color: beige;font: bold 14px;}"));
                }
                else
                {
                    ui->c4->setStyleSheet(QString("QPushButton {background-color: green;border:2px solid white;border-width: 2px;border-radius: 10px;border-color: beige;font: bold 14px;}"));

                }
                if(booking.at(17)=="booked")
                {
                    ui->c5->setStyleSheet(QString("QPushButton {background-color: red;border:2px solid white;border-width: 2px;border-radius: 10px;border-color: beige;font: bold 14px;}"));
                }
                else
                {
                    ui->c5->setStyleSheet(QString("QPushButton {background-color: green;border:2px solid white;border-width: 2px;border-radius: 10px;border-color: beige;font: bold 14px;}"));

                }
                if(booking.at(18)=="booked")
                {
                    ui->c6->setStyleSheet(QString("QPushButton {background-color: red;border:2px solid white;border-width: 2px;border-radius: 10px;border-color: beige;font: bold 14px;}"));
                }
                else
                {
                    ui->c6->setStyleSheet(QString("QPushButton {background-color: green;border:2px solid white;border-width: 2px;border-radius: 10px;border-color: beige;font: bold 14px;}"));

                }
                if(booking.at(19)=="booked")
                {
                    ui->d1->setStyleSheet(QString("QPushButton {background-color: red;border:2px solid white;border-width: 2px;border-radius: 10px;border-color: beige;font: bold 14px;}"));
                }
                else
                {
                    ui->d1->setStyleSheet(QString("QPushButton {background-color: green;border:2px solid white;border-width: 2px;border-radius: 10px;border-color: beige;font: bold 14px;}"));

                }
                if(booking.at(20)=="booked")
                {
                    ui->d2->setStyleSheet(QString("QPushButton {background-color: red;border:2px solid white;border-width: 2px;border-radius: 10px;border-color: beige;font: bold 14px;}"));
                }
                else
                {
                    ui->d2->setStyleSheet(QString("QPushButton {background-color: green;border:2px solid white;border-width: 2px;border-radius: 10px;border-color: beige;font: bold 14px;}"));

                }
                if(booking.at(21)=="booked")
                {
                    ui->d3->setStyleSheet(QString("QPushButton {background-color: red;border:2px solid white;border-width: 2px;border-radius: 10px;border-color: beige;font: bold 14px;}"));
                }
                else
                {
                    ui->d3->setStyleSheet(QString("QPushButton {background-color: green;border:2px solid white;border-width: 2px;border-radius: 10px;border-color: beige;font: bold 14px;}"));

                }
                if(booking.at(22)=="booked")
                {
                    ui->d4->setStyleSheet(QString("QPushButton {background-color: red;border:2px solid white;border-width: 2px;border-radius: 10px;border-color: beige;font: bold 14px;}"));
                }
                else
                {
                    ui->d4->setStyleSheet(QString("QPushButton {background-color: green;border:2px solid white;border-width: 2px;border-radius: 10px;border-color: beige;font: bold 14px;}"));

                }
                if(booking.at(23)=="booked")
                {
                    ui->d5->setStyleSheet(QString("QPushButton {background-color: red;border:2px solid white;border-width: 2px;border-radius: 10px;border-color: beige;font: bold 14px;}"));
                }
                else
                {
                    ui->d5->setStyleSheet(QString("QPushButton {background-color: green;border:2px solid white;border-width: 2px;border-radius: 10px;border-color: beige;font: bold 14px;}"));

                }
                if(booking.at(24)=="booked")
                {
                    ui->d6->setStyleSheet(QString("QPushButton {background-color: red;border:2px solid white;border-width: 2px;border-radius: 10px;border-color: beige;font: bold 14px;}"));
                }
                else
                {
                    ui->d6->setStyleSheet(QString("QPushButton {background-color: green;border:2px solid white;border-width: 2px;border-radius: 10px;border-color: beige;font: bold 14px;}"));

                }
                if(booking.at(25)=="booked")
                {
                    ui->e1->setStyleSheet(QString("QPushButton {background-color: red;border:2px solid white;border-width: 2px;border-radius: 10px;border-color: beige;font: bold 14px;}"));
                }
                else
                {
                    ui->e1->setStyleSheet(QString("QPushButton {background-color:  rgb(159, 239, 0);border:2px solid white;border-width: 2px;border-radius: 10px;border-color: beige;font: bold 14px;}"));

                }
                if(booking.at(26)=="booked")
                {
                    ui->e2->setStyleSheet(QString("QPushButton {background-color: red;border:2px solid white;border-width: 2px;border-radius: 10px;border-color: beige;font: bold 14px;}"));
                }
                else
                {
                    ui->e2->setStyleSheet(QString("QPushButton {background-color: rgb(159, 239, 0);border:2px solid white;border-width: 2px;border-radius: 10px;border-color: beige;font: bold 14px;}"));

                }
                if(booking.at(27)=="booked")
                {
                    ui->e3->setStyleSheet(QString("QPushButton {background-color: red;border:2px solid white;border-width: 2px;border-radius: 10px;border-color: beige;font: bold 14px;}"));
                }
                else
                {
                    ui->e3->setStyleSheet(QString("QPushButton {background-color: rgb(159, 239, 0);border:2px solid white;border-width: 2px;border-radius: 10px;border-color: beige;font: bold 14px;}"));

                }
                if(booking.at(28)=="booked")
                {
                    ui->e4->setStyleSheet(QString("QPushButton {background-color: red;border:2px solid white;border-width: 2px;border-radius: 10px;border-color: beige;font: bold 14px;}"));
                }
                else
                {
                    ui->e4->setStyleSheet(QString("QPushButton {background-color: rgb(159, 239, 0);border:2px solid white;border-width: 2px;border-radius: 10px;border-color: beige;font: bold 14px;}"));

                }
                if(booking.at(29)=="booked")
                {
                    ui->e5->setStyleSheet(QString("QPushButton {background-color: red;border:2px solid white;border-width: 2px;border-radius: 10px;border-color: beige;font: bold 14px;}"));
                }
                else
                {
                    ui->e5->setStyleSheet(QString("QPushButton {background-color: rgb(159, 239, 0);border:2px solid white;border-width: 2px;border-radius: 10px;border-color: beige;font: bold 14px;}"));

                }
                if(booking.at(30)=="booked")
                {
                    ui->e6->setStyleSheet(QString("QPushButton {background-color: red;border:2px solid white;border-width: 2px;border-radius: 10px;border-color: beige;font: bold 14px;}"));
                }
                else
                {
                    ui->e6->setStyleSheet(QString("QPushButton {background-color: rgb(159, 239, 0);border:2px solid white;border-width: 2px;border-radius: 10px;border-color: beige;font: bold 14px;}"));

                }
                if(booking.at(31)=="booked")
                {
                    ui->e7->setStyleSheet(QString("QPushButton {background-color: red;border:2px solid white;border-width: 2px;border-radius: 10px;border-color: beige;font: bold 14px;}"));
                }
                else
                {
                    ui->e7->setStyleSheet(QString("QPushButton {background-color: rgb(159, 239, 0);border:2px solid white;border-width: 2px;border-radius: 10px;border-color: beige;font: bold 14px;}"));

                }
                if(booking.at(32)=="booked")
                {
                    ui->e8->setStyleSheet(QString("QPushButton {background-color: red;border:2px solid white;border-width: 2px;border-radius: 10px;border-color: beige;font: bold 14px;}"));
                }
                else
                {
                    ui->e8->setStyleSheet(QString("QPushButton {background-color: rgb(159, 239, 0);border:2px solid white;border-width: 2px;border-radius: 10px;border-color: beige;font: bold 14px;}"));

                }
                if(booking.at(33)=="booked")
                {
                    ui->f1->setStyleSheet(QString("QPushButton {background-color: red;border:2px solid white;border-width: 2px;border-radius: 10px;border-color: beige;font: bold 14px;}"));
                }
                else
                {
                    ui->f1->setStyleSheet(QString("QPushButton {background-color: rgb(159, 239, 0);border:2px solid white;border-width: 2px;border-radius: 10px;border-color: beige;font: bold 14px;}"));

                }
                if(booking.at(34)=="booked")
                {
                    ui->f2->setStyleSheet(QString("QPushButton {background-color: red;border:2px solid white;border-width: 2px;border-radius: 10px;border-color: beige;font: bold 14px;}"));
                }
                else
                {
                    ui->f2->setStyleSheet(QString("QPushButton {background-color: rgb(159, 239, 0);border:2px solid white;border-width: 2px;border-radius: 10px;border-color: beige;font: bold 14px;}"));

                }
                if(booking.at(35)=="booked")
                {
                    ui->f3->setStyleSheet(QString("QPushButton {background-color: red;border:2px solid white;border-width: 2px;border-radius: 10px;border-color: beige;font: bold 14px;}"));
                }
                else
                {
                    ui->f3->setStyleSheet(QString("QPushButton {background-color: rgb(159, 239, 0);border:2px solid white;border-width: 2px;border-radius: 10px;border-color: beige;font: bold 14px;}"));

                }
                if(booking.at(36)=="booked")
                {
                    ui->f4->setStyleSheet(QString("QPushButton {background-color: red;border:2px solid white;border-width: 2px;border-radius: 10px;border-color: beige;font: bold 14px;}"));
                }
                else
                {
                    ui->f4->setStyleSheet(QString("QPushButton {background-color: rgb(159, 239, 0);border:2px solid white;border-width: 2px;border-radius: 10px;border-color: beige;font: bold 14px;}"));

                }
                if(booking.at(37)=="booked")
                {
                    ui->f5->setStyleSheet(QString("QPushButton {background-color: red;border:2px solid white;border-width: 2px;border-radius: 10px;border-color: beige;font: bold 14px;}"));
                }
                else
                {
                    ui->f5->setStyleSheet(QString("QPushButton {background-color:rgb(159, 239, 0);border:2px solid white;border-width: 2px;border-radius: 10px;border-color: beige;font: bold 14px;}"));

                }
                if(booking.at(38)=="booked")
                {
                    ui->f6->setStyleSheet(QString("QPushButton {background-color: red;border:2px solid white;border-width: 2px;border-radius: 10px;border-color: beige;font: bold 14px;}"));
                }
                else
                {
                    ui->f6->setStyleSheet(QString("QPushButton {background-color: rgb(159, 239, 0);border:2px solid white;border-width: 2px;border-radius: 10px;border-color: beige;font: bold 14px;}"));

                }
                if(booking.at(39)=="booked")
                {
                    ui->f7->setStyleSheet(QString("QPushButton {background-color: red;border:2px solid white;border-width: 2px;border-radius: 10px;border-color: beige;font: bold 14px;}"));
                }
                else
                {
                    ui->f7->setStyleSheet(QString("QPushButton {background-color: rgb(159, 239, 0);border:2px solid white;border-width: 2px;border-radius: 10px;border-color: beige;font: bold 14px;}"));

                }
                if(booking.at(40)=="booked")
                {
                    ui->f8->setStyleSheet(QString("QPushButton {background-color: red;border:2px solid white;border-width: 2px;border-radius: 10px;border-color: beige;font: bold 14px;}"));
                }
                else
                {
                    ui->f8->setStyleSheet(QString("QPushButton {background-color: rgb(159, 239, 0);border:2px solid white;border-width: 2px;border-radius: 10px;border-color: beige;font: bold 14px;}"));

                }
                if(booking.at(41)=="booked")
                {
                    ui->g1->setStyleSheet(QString("QPushButton {background-color: red;border:2px solid white;border-width: 2px;border-radius: 10px;border-color: beige;font: bold 14px;}"));
                }
                else
                {
                    ui->g1->setStyleSheet(QString("QPushButton {background-color: rgb(159, 239, 0);border:2px solid white;border-width: 2px;border-radius: 10px;border-color: beige;font: bold 14px;}"));

                }
                if(booking.at(42)=="booked")
                {
                    ui->g2->setStyleSheet(QString("QPushButton {background-color: red;border:2px solid white;border-width: 2px;border-radius: 10px;border-color: beige;font: bold 14px;}"));
                }
                else
                {
                    ui->g2->setStyleSheet(QString("QPushButton {background-color: rgb(159, 239, 0);border:2px solid white;border-width: 2px;border-radius: 10px;border-color: beige;font: bold 14px;}"));

                }
                if(booking.at(43)=="booked")
                {
                    ui->g3->setStyleSheet(QString("QPushButton {background-color: red;border:2px solid white;border-width: 2px;border-radius: 10px;border-color: beige;font: bold 14px;}"));
                }
                else
                {
                    ui->g3->setStyleSheet(QString("QPushButton {background-color: rgb(159, 239, 0);border:2px solid white;border-width: 2px;border-radius: 10px;border-color: beige;font: bold 14px;}"));

                }
                if(booking.at(44)=="booked")
                {
                    ui->g4->setStyleSheet(QString("QPushButton {background-color: red;border:2px solid white;border-width: 2px;border-radius: 10px;border-color: beige;font: bold 14px;}"));
                }
                else
                {
                    ui->g4->setStyleSheet(QString("QPushButton {background-color: rgb(159, 239, 0);border:2px solid white;border-width: 2px;border-radius: 10px;border-color: beige;font: bold 14px;}"));

                }
                if(booking.at(45)=="booked")
                {
                    ui->g5->setStyleSheet(QString("QPushButton {background-color: red;border:2px solid white;border-width: 2px;border-radius: 10px;border-color: beige;font: bold 14px;}"));
                }
                else
                {
                    ui->g5->setStyleSheet(QString("QPushButton {background-color: rgb(159, 239, 0);border:2px solid white;border-width: 2px;border-radius: 10px;border-color: beige;font: bold 14px;}"));

                }
                if(booking.at(46)=="booked")
                {
                    ui->g6->setStyleSheet(QString("QPushButton {background-color: red;border:2px solid white;border-width: 2px;border-radius: 10px;border-color: beige;font: bold 14px;}"));
                }
                else
                {
                    ui->g6->setStyleSheet(QString("QPushButton {background-color: rgb(159, 239, 0);border:2px solid white;border-width: 2px;border-radius: 10px;border-color: beige;font: bold 14px;}"));

                }
                if(booking.at(47)=="booked")
                {
                    ui->g7->setStyleSheet(QString("QPushButton {background-color: red;border:2px solid white;border-width: 2px;border-radius: 10px;border-color: beige;font: bold 14px;}"));
                }
                else
                {
                    ui->g7->setStyleSheet(QString("QPushButton {background-color: rgb(159, 239, 0);border:2px solid white;border-width: 2px;border-radius: 10px;border-color: beige;font: bold 14px;}"));

                }
                if(booking.at(48)=="booked")
                {
                    ui->g8->setStyleSheet(QString("QPushButton {background-color: red;border:2px solid white;border-width: 2px;border-radius: 10px;border-color: beige;font: bold 14px;}"));
                }
                else
                {
                    ui->g8->setStyleSheet(QString("QPushButton {background-color: rgb(159, 239, 0);border:2px solid white;border-width: 2px;border-radius: 10px;border-color: beige;font: bold 14px;}"));

                }
                if(booking.at(49)=="booked")
                {
                    ui->h1->setStyleSheet(QString("QPushButton {background-color: red;border:2px solid white;border-width: 2px;border-radius: 10px;border-color: beige;font: bold 14px;}"));
                }
                else
                {
                    ui->h1->setStyleSheet(QString("QPushButton {background-color: rgb(159, 239, 0);border:2px solid white;border-width: 2px;border-radius: 10px;border-color: beige;font: bold 14px;}"));

                }
                if(booking.at(50)=="booked")
                {
                    ui->h2->setStyleSheet(QString("QPushButton {background-color: red;border:2px solid white;border-width: 2px;border-radius: 10px;border-color: beige;font: bold 14px;}"));
                }
                else
                {
                    ui->h2->setStyleSheet(QString("QPushButton {background-color:  rgb(0, 255, 0);border:2px solid white;border-width: 2px;border-radius: 10px;border-color: beige;font: bold 14px;}"));

                }
                if(booking.at(51)=="booked")
                {
                    ui->h3->setStyleSheet(QString("QPushButton {background-color: red;border:2px solid white;border-width: 2px;border-radius: 10px;border-color: beige;font: bold 14px;}"));
                }
                else
                {
                    ui->h3->setStyleSheet(QString("QPushButton {background-color: rgb(0, 255, 0);border:2px solid white;border-width: 2px;border-radius: 10px;border-color: beige;font: bold 14px;}"));

                }
                if(booking.at(52)=="booked")
                {
                    ui->h4->setStyleSheet(QString("QPushButton {background-color: red;border:2px solid white;border-width: 2px;border-radius: 10px;border-color: beige;font: bold 14px;}"));
                }
                else
                {
                    ui->h4->setStyleSheet(QString("QPushButton {background-color: rgb(0, 255, 0);border:2px solid white;border-width: 2px;border-radius: 10px;border-color: beige;font: bold 14px;}"));

                }
                if(booking.at(53)=="booked")
                {
                    ui->h5->setStyleSheet(QString("QPushButton {background-color: red;border:2px solid white;border-width: 2px;border-radius: 10px;border-color: beige;font: bold 14px;}"));
                }
                else
                {
                    ui->h5->setStyleSheet(QString("QPushButton {background-color: rgb(0, 255, 0);border:2px solid white;border-width: 2px;border-radius: 10px;border-color: beige;font: bold 14px;}"));

                }
                if(booking.at(54)=="booked")
                {
                    ui->h6->setStyleSheet(QString("QPushButton {background-color: red;border:2px solid white;border-width: 2px;border-radius: 10px;border-color: beige;font: bold 14px;}"));
                }
                else
                {
                    ui->h6->setStyleSheet(QString("QPushButton {background-color: rgb(0, 255, 0);border:2px solid white;border-width: 2px;border-radius: 10px;border-color: beige;font: bold 14px;}"));

                }
                if(booking.at(55)=="booked")
                {
                    ui->h7->setStyleSheet(QString("QPushButton {background-color: red;border:2px solid white;border-width: 2px;border-radius: 10px;border-color: beige;font: bold 14px;}"));
                }
                else
                {
                    ui->h7->setStyleSheet(QString("QPushButton {background-color: rgb(0, 255, 0);border:2px solid white;border-width: 2px;border-radius: 10px;border-color: beige;font: bold 14px;}"));

                }
                if(booking.at(56)=="booked")
                {
                    ui->h8->setStyleSheet(QString("QPushButton {background-color: red;border:2px solid white;border-width: 2px;border-radius: 10px;border-color: beige;font: bold 14px;}"));
                }
                else
                {
                    ui->h8->setStyleSheet(QString("QPushButton {background-color: rgb(0, 255, 0);border:2px solid white;border-width: 2px;border-radius: 10px;border-color: beige;font: bold 14px;}"));

                }
                if(booking.at(57)=="booked")
                {
                    ui->h9->setStyleSheet(QString("QPushButton {background-color: red;border:2px solid white;border-width: 2px;border-radius: 10px;border-color: beige;font: bold 14px;}"));
                }
                else
                {
                    ui->h9->setStyleSheet(QString("QPushButton {background-color: rgb(0, 255, 0);border:2px solid white;border-width: 2px;border-radius: 10px;border-color: beige;font: bold 14px;}"));

                }
                if(booking.at(58)=="booked")
                {
                    ui->i1->setStyleSheet(QString("QPushButton {background-color: red;border:2px solid white;border-width: 2px;border-radius: 10px;border-color: beige;font: bold 14px;}"));
                }
                else
                {
                    ui->i1->setStyleSheet(QString("QPushButton {background-color: rgb(0, 255, 0);border:2px solid white;border-width: 2px;border-radius: 10px;border-color: beige;font: bold 14px;}"));

                }
                if(booking.at(59)=="booked")
                {
                    ui->i2->setStyleSheet(QString("QPushButton {background-color: red;border:2px solid white;border-width: 2px;border-radius: 10px;border-color: beige;font: bold 14px;}"));
                }
                else
                {
                    ui->i2->setStyleSheet(QString("QPushButton {background-color: rgb(0, 255, 0);border:2px solid white;border-width: 2px;border-radius: 10px;border-color: beige;font: bold 14px;}"));

                }
                if(booking.at(60)=="booked")
                {
                    ui->i3->setStyleSheet(QString("QPushButton {background-color: red;border:2px solid white;border-width: 2px;border-radius: 10px;border-color: beige;font: bold 14px;}"));
                }
                else
                {
                    ui->i3->setStyleSheet(QString("QPushButton {background-color: rgb(0, 255, 0);border:2px solid white;border-width: 2px;border-radius: 10px;border-color: beige;font: bold 14px;}"));

                }
                if(booking.at(61)=="booked")
                {
                    ui->i4->setStyleSheet(QString("QPushButton {background-color: red;border:2px solid white;border-width: 2px;border-radius: 10px;border-color: beige;font: bold 14px;}"));
                }
                else
                {
                    ui->i4->setStyleSheet(QString("QPushButton {background-color: rgb(0, 255, 0);border:2px solid white;border-width: 2px;border-radius: 10px;border-color: beige;font: bold 14px;}"));

                }
                if(booking.at(62)=="booked")
                {
                    ui->i5->setStyleSheet(QString("QPushButton {background-color: red;border:2px solid white;border-width: 2px;border-radius: 10px;border-color: beige;font: bold 14px;}"));
                }
                else
                {
                    ui->i5->setStyleSheet(QString("QPushButton {background-color: rgb(0, 255, 0);border:2px solid white;border-width: 2px;border-radius: 10px;border-color: beige;font: bold 14px;}"));

                }
                if(booking.at(63)=="booked")
                {
                    ui->i6->setStyleSheet(QString("QPushButton {background-color: red;border:2px solid white;border-width: 2px;border-radius: 10px;border-color: beige;font: bold 14px;}"));
                }
                else
                {
                    ui->i6->setStyleSheet(QString("QPushButton {background-color: rgb(0, 255, 0);border:2px solid white;border-width: 2px;border-radius: 10px;border-color: beige;font: bold 14px;}"));

                }
                if(booking.at(64)=="booked")
                {
                    ui->i7->setStyleSheet(QString("QPushButton {background-color: red;border:2px solid white;border-width: 2px;border-radius: 10px;border-color: beige;font: bold 14px;}"));
                }
                else
                {
                    ui->i7->setStyleSheet(QString("QPushButton {background-color: rgb(0, 255, 0);border:2px solid white;border-width: 2px;border-radius: 10px;border-color: beige;font: bold 14px;}"));

                }
                if(booking.at(65)=="booked")
                {
                    ui->i8->setStyleSheet(QString("QPushButton {background-color: red;border:2px solid white;border-width: 2px;border-radius: 10px;border-color: beige;font: bold 14px;}"));
                }
                else
                {
                    ui->i8->setStyleSheet(QString("QPushButton {background-color: rgb(0, 255, 0);border:2px solid white;border-width: 2px;border-radius: 10px;border-color: beige;font: bold 14px;}"));

                }
                if(booking.at(66)=="booked")
                {
                    ui->i9->setStyleSheet(QString("QPushButton {background-color: red;border:2px solid white;border-width: 2px;border-radius: 10px;border-color: beige;font: bold 14px;}"));
                }
                else
                {
                    ui->i9->setStyleSheet(QString("QPushButton {background-color: rgb(0, 255, 0);border:2px solid white;border-width: 2px;border-radius: 10px;border-color: beige;font: bold 14px;}"));

                }
                if(booking.at(67)=="booked")
                {
                    ui->j1->setStyleSheet(QString("QPushButton {background-color: red;border:2px solid white;border-width: 2px;border-radius: 10px;border-color: beige;font: bold 14px;}"));
                }
                else
                {
                    ui->j1->setStyleSheet(QString("QPushButton {background-color: rgb(0, 255, 0);border:2px solid white;border-width: 2px;border-radius: 10px;border-color: beige;font: bold 14px;}"));

                }
                if(booking.at(68)=="booked")
                {
                    ui->j2->setStyleSheet(QString("QPushButton {background-color: red;border:2px solid white;border-width: 2px;border-radius: 10px;border-color: beige;font: bold 14px;}"));
                }
                else
                {
                    ui->j2->setStyleSheet(QString("QPushButton {background-color: rgb(0, 255, 0);border:2px solid white;border-width: 2px;border-radius: 10px;border-color: beige;font: bold 14px;}"));

                }
                if(booking.at(69)=="booked")
                {
                    ui->j3->setStyleSheet(QString("QPushButton {background-color: red;border:2px solid white;border-width: 2px;border-radius: 10px;border-color: beige;font: bold 14px;}"));
                }
                else
                {
                    ui->j3->setStyleSheet(QString("QPushButton {background-color: rgb(0, 255, 0);border:2px solid white;border-width: 2px;border-radius: 10px;border-color: beige;font: bold 14px;}"));

                }
                if(booking.at(70)=="booked")
                {
                    ui->j4->setStyleSheet(QString("QPushButton {background-color: red;border:2px solid white;border-width: 2px;border-radius: 10px;border-color: beige;font: bold 14px;}"));
                }
                else
                {
                    ui->j4->setStyleSheet(QString("QPushButton {background-color: rgb(0, 255, 0);border:2px solid white;border-width: 2px;border-radius: 10px;border-color: beige;font: bold 14px;}"));

                }
                if(booking.at(71)=="booked")
                {
                    ui->j5->setStyleSheet(QString("QPushButton {background-color: red;border:2px solid white;border-width: 2px;border-radius: 10px;border-color: beige;font: bold 14px;}"));
                }
                else
                {
                    ui->j5->setStyleSheet(QString("QPushButton {background-color: rgb(0, 255, 0);border:2px solid white;border-width: 2px;border-radius: 10px;border-color: beige;font: bold 14px;}"));

                }
                if(booking.at(72)=="booked")
                {
                    ui->j6->setStyleSheet(QString("QPushButton {background-color: red;border:2px solid white;border-width: 2px;border-radius: 10px;border-color: beige;font: bold 14px;}"));
                }
                else
                {
                    ui->j6->setStyleSheet(QString("QPushButton {background-color: rgb(0, 255, 0);border:2px solid white;border-width: 2px;border-radius: 10px;border-color: beige;font: bold 14px;}"));

                }
                if(booking.at(73)=="booked")
                {
                    ui->j7->setStyleSheet(QString("QPushButton {background-color: red;border:2px solid white;border-width: 2px;border-radius: 10px;border-color: beige;font: bold 14px;}"));
                }
                else
                {
                    ui->j7->setStyleSheet(QString("QPushButton {background-color: rgb(0, 255, 0);border:2px solid white;border-width: 2px;border-radius: 10px;border-color: beige;font: bold 14px;}"));

                }
                if(booking.at(74)=="booked")
                {
                    ui->j8->setStyleSheet(QString("QPushButton {background-color: red;border:2px solid white;border-width: 2px;border-radius: 10px;border-color: beige;font: bold 14px;}"));
                }
                else
                {
                    ui->j8->setStyleSheet(QString("QPushButton {background-color: rgb(0, 255, 0);border:2px solid white;border-width: 2px;border-radius: 10px;border-color: beige;font: bold 14px;}"));

                }
                if(booking.at(75)=="booked")
                {
                    ui->j9->setStyleSheet(QString("QPushButton {background-color: red;border:2px solid white;border-width: 2px;border-radius: 10px;border-color: beige;font: bold 14px;}"));
                }
                else
                {
                    ui->j9->setStyleSheet(QString("QPushButton {background-color: rgb(0, 255, 0);border:2px solid white;border-width: 2px;border-radius: 10px;border-color: beige;font: bold 14px;}"));

                }
                }
                ui->SHEDULE_CHECK_12->setItem(0,0,new QTableWidgetItem(booking.at(81)));
                ui->SHEDULE_CHECK_12->setItem(1,0,new QTableWidgetItem(booking.at(82)));
                ui->SHEDULE_CHECK_12->setItem(2,0,new QTableWidgetItem(booking.at(83)));
                ui->SHEDULE_CHECK_12->setItem(3,0,new QTableWidgetItem(booking.at(76)));
                ui->SHEDULE_CHECK_12->setItem(4,0,new QTableWidgetItem(booking.at(77)));
                ui->SHEDULE_CHECK_12->setItem(5,0,new QTableWidgetItem(booking.at(78)));
                ui->SHEDULE_CHECK_12->setItem(6,0,new QTableWidgetItem(booking.at(79)));
                ui->SHEDULE_CHECK_12->setItem(7,0,new QTableWidgetItem(booking.at(80)));
                ui->SHEDULE_CHECK_12->setItem(8,0,new QTableWidgetItem(booking.at(0)));
                ui->stackedWidget->setCurrentIndex(22);
            }
        }
        else
        {

            QMessageBox :: warning(this,"FLIGHT","Wrong Flight ID");
        }
        ui->lineEdit->clear();

}


void MainWindow::on_TRANSPER_CEO_3_clicked()
{
    ui->stackedWidget->setCurrentIndex(6);
}


void MainWindow::on_TRANSPER_CEO_2_clicked()
{
    ui->stackedWidget->setCurrentIndex(11);
}


void MainWindow::on_SHEDULE_CHEACK_ADMIN_clicked()
{
    {
        ui->stackedWidget->setCurrentIndex(14);
        QVector<QString>FROM_D,TO_D,S_DATE_D,S_SRNO_D,STRT_TIME_D,END_TIME_D,DAY;
        QFile Fiiile("FLIGHT.txt");
        int i=0;
        if(Fiiile.open(QIODevice::ReadOnly))
        {
            QTextStream stream(&Fiiile);
            QString FileData1,FileData2,FileData3,FileData4,FileData5,FileData6;
            while ( stream.atEnd()==false)
            {
                FileData1 = stream.readLine();
                S_SRNO_D.push_back(FileData1);
                FileData2 = stream.readLine();
                FROM_D.push_back(FileData2);
                FileData3 = stream.readLine();
                TO_D.push_back(FileData3);
                FileData4 = stream.readLine();
                STRT_TIME_D.push_back(FileData4);
                FileData5 = stream.readLine();
                END_TIME_D.push_back(FileData5);
                FileData6 = stream.readLine();
                S_DATE_D.push_back(FileData6);
                DAY.push_back(stream.readLine());
                i++;
            }
        }
        Fiiile.close();
        ui->SHEDULE_CHECK_3->setRowCount(i);
        for(int j=0;j<i;j++)
        {
            ui->SHEDULE_CHECK_3->setItem(j,0,new QTableWidgetItem(S_SRNO_D.at(j)));
            ui->SHEDULE_CHECK_3->setItem(j,1,new QTableWidgetItem(FROM_D.at(j)));
            ui->SHEDULE_CHECK_3->setItem(j,2,new QTableWidgetItem(TO_D.at(j)));
            ui->SHEDULE_CHECK_3->setItem(j,3,new QTableWidgetItem(STRT_TIME_D.at(j)));
            ui->SHEDULE_CHECK_3->setItem(j,4,new QTableWidgetItem(END_TIME_D.at(j)));
            ui->SHEDULE_CHECK_3->setItem(j,5,new QTableWidgetItem(S_DATE_D.at(j)));

        }
    }
}


void MainWindow::on_FLIGHT_SETTINGS_clicked()
{
    ui->stackedWidget->setCurrentIndex(20);
}


void MainWindow::on_pushButton_14_clicked()
{
    ui->stackedWidget->setCurrentIndex(21);
}


void MainWindow::on_pushButton_57_clicked()
{
    ui->stackedWidget->setCurrentIndex(20);
}


void MainWindow::on_A_1_clicked()
{
    QVector<QString>xy;
    QVector<QString>FRoOM_D,TO_oD,S_DATE_oD,S_SRNO_oD,STRT_TIME_oD,END_TIME_oD,DAY;

    QFile ree(Flight_choice);
    if(ree.open(QIODevice::ReadOnly))
    {
        QTextStream stream(&ree);
        while ( stream.atEnd()==false)
        {
            xy.push_back(stream.readLine());
        }
        if(xy.at(1)=="nonbooked")
        {

            QFile Fiiile("FLIGHT.txt");
           /* int i=0;*/
            if(Fiiile.open(QIODevice::ReadOnly))
            {
                QTextStream stream(&Fiiile);
                while ( stream.atEnd()==false)
                {
                    S_SRNO_oD.push_back(stream.readLine());
                    FRoOM_D.push_back(stream.readLine());
                    TO_oD.push_back(stream.readLine());
                    STRT_TIME_oD.push_back(stream.readLine());
                    END_TIME_oD.push_back(stream.readLine());
                    S_DATE_oD.push_back(stream.readLine());
                    DAY.push_back(stream.readLine());
                }
            }
            Fiiile.close();
            int inh = S_SRNO_oD.indexOf(Flight_choice);

            ui->SHEDULE_CHECK_13->setItem(0,0,new QTableWidgetItem(xy.at(81)));
            ui->SHEDULE_CHECK_13->setItem(1,0,new QTableWidgetItem("A1"));
            ui->Ticket_P->setText("A1");
            ui->CLASS_P->setText("Business class");BOOKKING=Flight_choice+"A1";
            ui->SHEDULE_CHECK_13->setItem(2,0,new QTableWidgetItem(FRoOM_D.at(inh)));
            ui->SHEDULE_CHECK_13->setItem(3,0,new QTableWidgetItem(TO_oD.at(inh)));
            ui->SHEDULE_CHECK_13->setItem(4,0,new QTableWidgetItem(xy.at(84)));
             ui->stackedWidget->setCurrentIndex(23);
        }
        else
        {
            QMessageBox :: warning(this,"Ticket","NOT AVAILABLE!");
        }
    }
    ree.close();
}





void MainWindow::on_A_2_clicked()
{
    QVector<QString>xy;
    QVector<QString>FRoOM_D,TO_oD,S_DATE_oD,S_SRNO_oD,STRT_TIME_oD,END_TIME_oD,DAY;

    QFile ree(Flight_choice);
    if(ree.open(QIODevice::ReadOnly))
    {
        QTextStream stream(&ree);
        while ( stream.atEnd()==false)
        {
            xy.push_back(stream.readLine());
        }
        if(xy.at(2)=="nonbooked")
        {

            QFile Fiiile("FLIGHT.txt");
            //int i=0;
            if(Fiiile.open(QIODevice::ReadOnly))
            {
                QTextStream stream(&Fiiile);
                while ( stream.atEnd()==false)
                {
                    S_SRNO_oD.push_back(stream.readLine());
                    FRoOM_D.push_back(stream.readLine());
                    TO_oD.push_back(stream.readLine());
                    STRT_TIME_oD.push_back(stream.readLine());
                    END_TIME_oD.push_back(stream.readLine());
                    S_DATE_oD.push_back(stream.readLine());
                    DAY.push_back(stream.readLine());
                }
            }
            Fiiile.close();
            int inh = S_SRNO_oD.indexOf(Flight_choice);

            ui->SHEDULE_CHECK_13->setItem(0,0,new QTableWidgetItem(xy.at(81)));
            ui->SHEDULE_CHECK_13->setItem(1,0,new QTableWidgetItem("A2"));
            ui->Ticket_P->setText("A2");ui->CLASS_P->setText("Business class");BOOKKING=Flight_choice+"A2";
            ui->SHEDULE_CHECK_13->setItem(2,0,new QTableWidgetItem(FRoOM_D.at(inh)));
            ui->SHEDULE_CHECK_13->setItem(3,0,new QTableWidgetItem(TO_oD.at(inh)));
            ui->SHEDULE_CHECK_13->setItem(4,0,new QTableWidgetItem(xy.at(84)));
            ui->stackedWidget->setCurrentIndex(23);
        }
        else
        {
            QMessageBox :: warning(this,"Ticket","NOT AVAILABLE!");
        }
    }
    ree.close();
}


void MainWindow::on_A_3_clicked()
{
    QVector<QString>xy;
    QVector<QString>FRoOM_D,TO_oD,S_DATE_oD,S_SRNO_oD,STRT_TIME_oD,END_TIME_oD,DAY;

    QFile ree(Flight_choice);
    if(ree.open(QIODevice::ReadOnly))
    {
        QTextStream stream(&ree);
        while ( stream.atEnd()==false)
        {
            xy.push_back(stream.readLine());
        }
        if(xy.at(3)=="nonbooked")
        {

            QFile Fiiile("FLIGHT.txt");
            int i=0;
            if(Fiiile.open(QIODevice::ReadOnly))
            {
                QTextStream stream(&Fiiile);
                while ( stream.atEnd()==false)
                {
                    S_SRNO_oD.push_back(stream.readLine());
                    FRoOM_D.push_back(stream.readLine());
                    TO_oD.push_back(stream.readLine());
                    STRT_TIME_oD.push_back(stream.readLine());
                    END_TIME_oD.push_back(stream.readLine());
                    S_DATE_oD.push_back(stream.readLine());
                    DAY.push_back(stream.readLine());
                }
            }
            Fiiile.close();
            int inh = S_SRNO_oD.indexOf(Flight_choice);

            ui->SHEDULE_CHECK_13->setItem(0,0,new QTableWidgetItem(xy.at(81)));
            ui->SHEDULE_CHECK_13->setItem(1,0,new QTableWidgetItem("A3"));
            ui->Ticket_P->setText("A3");ui->CLASS_P->setText("Business class");BOOKKING=Flight_choice+"A3";
            ui->SHEDULE_CHECK_13->setItem(2,0,new QTableWidgetItem(FRoOM_D.at(inh)));
            ui->SHEDULE_CHECK_13->setItem(3,0,new QTableWidgetItem(TO_oD.at(inh)));
            ui->SHEDULE_CHECK_13->setItem(4,0,new QTableWidgetItem(xy.at(84)));
            ui->stackedWidget->setCurrentIndex(23);
        }
        else
        {
            QMessageBox :: warning(this,"Ticket","NOT AVAILABLE!");
        }
    }
    ree.close();
}


void MainWindow::on_A_4_clicked()
{
    QVector<QString>xy;
    QVector<QString>FRoOM_D,TO_oD,S_DATE_oD,S_SRNO_oD,STRT_TIME_oD,END_TIME_oD,DAY;

    QFile ree(Flight_choice);
    if(ree.open(QIODevice::ReadOnly))
    {
        QTextStream stream(&ree);
        while ( stream.atEnd()==false)
        {
            xy.push_back(stream.readLine());
        }
        if(xy.at(4)=="nonbooked")
        {

            QFile Fiiile("FLIGHT.txt");
            if(Fiiile.open(QIODevice::ReadOnly))
            {
                QTextStream stream(&Fiiile);
                while ( stream.atEnd()==false)
                {
                    S_SRNO_oD.push_back(stream.readLine());
                    FRoOM_D.push_back(stream.readLine());
                    TO_oD.push_back(stream.readLine());
                    STRT_TIME_oD.push_back(stream.readLine());
                    END_TIME_oD.push_back(stream.readLine());
                    S_DATE_oD.push_back(stream.readLine());
                    DAY.push_back(stream.readLine());
                }
            }
            Fiiile.close();
            int inh = S_SRNO_oD.indexOf(Flight_choice);

            ui->SHEDULE_CHECK_13->setItem(0,0,new QTableWidgetItem(xy.at(81)));
            ui->SHEDULE_CHECK_13->setItem(1,0,new QTableWidgetItem("A4"));
            ui->Ticket_P->setText("A4");ui->CLASS_P->setText("Business class");BOOKKING=Flight_choice+"A4";
            ui->SHEDULE_CHECK_13->setItem(2,0,new QTableWidgetItem(FRoOM_D.at(inh)));
            ui->SHEDULE_CHECK_13->setItem(3,0,new QTableWidgetItem(TO_oD.at(inh)));
            ui->SHEDULE_CHECK_13->setItem(4,0,new QTableWidgetItem(xy.at(84)));
            ui->stackedWidget->setCurrentIndex(23);
        }
        else
        {
            QMessageBox :: warning(this,"Ticket","NOT AVAILABLE!");
        }
    }
    ree.close();
}


void MainWindow::on_A_5_clicked()
{
    QVector<QString>xy;
    QVector<QString>FRoOM_D,TO_oD,S_DATE_oD,S_SRNO_oD,STRT_TIME_oD,END_TIME_oD,DAY;

    QFile ree(Flight_choice);
    if(ree.open(QIODevice::ReadOnly))
    {
        QTextStream stream(&ree);
        while ( stream.atEnd()==false)
        {
            xy.push_back(stream.readLine());
        }
        if(xy.at(5)=="nonbooked")
        {

            QFile Fiiile("FLIGHT.txt");
            if(Fiiile.open(QIODevice::ReadOnly))
            {
                QTextStream stream(&Fiiile);
                while ( stream.atEnd()==false)
                {
                    S_SRNO_oD.push_back(stream.readLine());
                    FRoOM_D.push_back(stream.readLine());
                    TO_oD.push_back(stream.readLine());
                    STRT_TIME_oD.push_back(stream.readLine());
                    END_TIME_oD.push_back(stream.readLine());
                    S_DATE_oD.push_back(stream.readLine());
                    DAY.push_back(stream.readLine());
                }
            }
            Fiiile.close();
            int inh = S_SRNO_oD.indexOf(Flight_choice);

            ui->SHEDULE_CHECK_13->setItem(0,0,new QTableWidgetItem(xy.at(81)));
            ui->SHEDULE_CHECK_13->setItem(1,0,new QTableWidgetItem("A5"));
            ui->Ticket_P->setText("A5");
            ui->CLASS_P->setText("Business class");BOOKKING=Flight_choice+"A5";
            ui->SHEDULE_CHECK_13->setItem(2,0,new QTableWidgetItem(FRoOM_D.at(inh)));
            ui->SHEDULE_CHECK_13->setItem(3,0,new QTableWidgetItem(TO_oD.at(inh)));
            ui->SHEDULE_CHECK_13->setItem(4,0,new QTableWidgetItem(xy.at(84)));
            ui->stackedWidget->setCurrentIndex(23);
        }
        else
        {
            QMessageBox :: warning(this,"Ticket","NOT AVAILABLE!");
        }
    }
    ree.close();
}


void MainWindow::on_pushButton_62_clicked()
{
    ui->stackedWidget->setCurrentIndex(19);
}


void MainWindow::on_A_6_clicked()

    {
        QVector<QString>xy;
        QVector<QString>FRoOM_D,TO_oD,S_DATE_oD,S_SRNO_oD,STRT_TIME_oD,END_TIME_oD,DAY;

        QFile ree(Flight_choice);
        if(ree.open(QIODevice::ReadOnly))
        {
            QTextStream stream(&ree);
            while ( stream.atEnd()==false)
            {
                xy.push_back(stream.readLine());
            }
            if(xy.at(6)=="nonbooked")
            {

                QFile Fiiile("FLIGHT.txt");
                int i=0;
                if(Fiiile.open(QIODevice::ReadOnly))
                {
                    QTextStream stream(&Fiiile);
                    while ( stream.atEnd()==false)
                    {
                        S_SRNO_oD.push_back(stream.readLine());
                        FRoOM_D.push_back(stream.readLine());
                        TO_oD.push_back(stream.readLine());
                        STRT_TIME_oD.push_back(stream.readLine());
                        END_TIME_oD.push_back(stream.readLine());
                        S_DATE_oD.push_back(stream.readLine());
                        DAY.push_back(stream.readLine());
                    }
                }
                Fiiile.close();
                int inh = S_SRNO_oD.indexOf(Flight_choice);

                ui->SHEDULE_CHECK_13->setItem(0,0,new QTableWidgetItem(xy.at(81)));
                ui->SHEDULE_CHECK_13->setItem(1,0,new QTableWidgetItem("A6"));
                ui->Ticket_P->setText("A6");ui->CLASS_P->setText("Business class");BOOKKING=Flight_choice+"A6";
                ui->SHEDULE_CHECK_13->setItem(2,0,new QTableWidgetItem(FRoOM_D.at(inh)));
                ui->SHEDULE_CHECK_13->setItem(3,0,new QTableWidgetItem(TO_oD.at(inh)));
                ui->SHEDULE_CHECK_13->setItem(4,0,new QTableWidgetItem(xy.at(84)));
                ui->stackedWidget->setCurrentIndex(23);
            }
            else
            {
                QMessageBox :: warning(this,"Ticket","NOT AVAILABLE!");
            }
        }
        ree.close();

}


void MainWindow::on_pushButton_61_clicked()
{
        QString book_email,book_name,book_number,book_extra,book_passort,book_birth,GENDER;

        if(ui->ticket_name->text()!='\0'){
            book_email=ui->ticket_email->text();
            book_name=ui->ticket_name->text();
            book_extra=ui->ticket_extra->text();
            book_number=ui->ticket_number->text();
            GENDER=ui->comboBox->currentText();
            book_passort=ui->ticket_passport->text();
            book_birth=ui->dateEdit->date().toString();
            ui->NAME_P->setText(book_name);
            ui->PASPORT_P->setText(book_passort);
            ui->CONTACT_P->setText(book_number);
            ui->CONTACT_P_2->setText(book_email);
            ui->ticket_email->clear();
            ui->ticket_name->clear();
            ui->ticket_extra->clear();
            ui->ticket_number->clear();
            ui->ticket_passport->clear();
            ui->stackedWidget->setCurrentIndex(24);}
        else
        {
            QMessageBox :: warning(this,"NAME","FILL!");
        }


}


void MainWindow::on_BKASH_clicked()
{
        QFile Fiile("PAYMENT.txt");
        QString payment;
        QString FileData1;
        if(Fiile.open(QIODevice::ReadOnly))
        {
            QTextStream stream(&Fiile);

            while ( stream.atEnd()==false)
            {
                FileData1 = stream.readLine();
            }
        }
        payment=ui->SHEDULE_CHECK_13->item(4,0)->text();
        ui->textBrowser_165->setText("\nMARCENT      : BIMAN BANGLADESH\nINVOICE NO  : "+FileData1+"\nAMOUNT       : "+payment+"\n");
        ui->stackedWidget->setCurrentIndex(25);


}


void MainWindow::on_pushButton_63_clicked()
{
        QVector<QString>s,p,o,il,k,l,DAY;
        if(ui->checkBox->isChecked())
        {
            if(ui->lineEdit_3->text()!="\0")
            {
                int i=0;
                ui->stackedWidget->setCurrentIndex(26);
                QFile FR("FLIGHT.txt");
                if(FR.open(QIODevice::ReadOnly))
                {
                    QTextStream stream(&FR);
                    while ( stream.atEnd()==false)
                    {
                        s.push_back(stream.readLine());
                        p.push_back(stream.readLine());
                        o.push_back(stream.readLine());
                        il.push_back(stream.readLine());
                        k.push_back(stream.readLine());
                        l.push_back(stream.readLine());
                        DAY.push_back(stream.readLine());
                        i++;
                    }

                }
                FR.close();
                int alap=s.indexOf(Flight_choice);
                ui->FROM_T->setText(p.at(alap));
                //ui->FROM_T->setText(BOOKKING);
                ui->TO_T->setText(o.at(alap));
                ui->DATE_P->setText(l.at(alap));
                ui->DEPART_TIME->setText(il.at(alap));
                ui->LAND_TIME->setText(k.at(alap));
                ui->DEPART_S->setText(p.at(alap));
                ui->LAND_S->setText(o.at(alap));
                ui->FLIGHT_NO_P->setText(s.at(alap));
                ui->DAY_P->setText(DAY.at(alap));



                QString seat=BOOKKING;
                QString flt=Flight_choice;
                //int jk=
                seat.remove(0, Flight_choice.length());


                QVector<QString>xyz,YXZ;
                int cnt=0;
                QFile eee(flt);
                if(eee.open(QIODevice::ReadOnly))
                {
                    QTextStream stream(&eee);
                    while ( stream.atEnd()==false)
                    {
                        xyz.push_back(stream.readLine());
                        cnt++;
                    }

                }

                eee.close();

                QFile Iee("SEAT.txt");
                if(Iee.open(QIODevice::ReadOnly))
                {
                    QTextStream stream(&Iee);
                    while ( stream.atEnd()==false)
                    {
                        YXZ.push_back(stream.readLine());

                    }

                }
                Iee.close();

                int inhi = YXZ.indexOf(seat);

                //xyz.at(inhi)="booked";
                QFile eoe(flt);
                if(eoe.open(QIODevice::WriteOnly))
                {
                    QTextStream stream(&eoe);
                    for(int hj=0;hj<cnt;hj++)
                    {
                        if(hj==inhi){stream<<"booked\n"; }
                        else {stream<<xyz.at(hj)+"\n";}
                    }


                }
                eoe.close();




                QString id;
                QFile FRr("PAYMENT.txt");
                if(FRr.open(QIODevice::ReadOnly))
                {
                    QTextStream stream(&FRr);
                    while ( stream.atEnd()==false)
                    {
                        id=stream.readLine();
                    }
                }
                FRr.close();


                ui->BOOKING_ID->setText(id+BOOKKING);

                QFile customer(CUSTOMER);
                if(customer.open(QIODevice::Append  |  QIODevice::ReadOnly))
                {
                    QTextStream stream(&customer);
                    stream<<Flight_choice+"\n";
                    stream<<id+BOOKKING+"\n";

                }


                customer.close();

                int ty = id.toInt();
                ty++;
                QFile FyR("PAYMENT.txt");
                if(FyR.open(QIODevice::WriteOnly))
                {
                    QTextStream stream(&FyR);
                    stream<<ty;
                }
                FyR.close();
                ui->lineEdit_3->clear();
                //ui->checkBox->makeCheckable();


            }
            else
            {
                QMessageBox :: warning(this,"NUMBER","GIVE NUMBER!");
            }
        }
        else
        {
            QMessageBox :: warning(this,"AGREE","CLICK OK IN AGREE BUTTON!");
        }
}


void MainWindow::on_pushButton_65_clicked()
{
    ui->stackedWidget->setCurrentIndex(6);
}


void MainWindow::on_pushButton_66_clicked()
{
QMessageBox :: warning(this,"AGREE","bKash is a payment method only. bKash is not liable if you do not receive the desired service/product from online merchant against your payment.·       Your bKash Account information is not shared with the online merchant"
"·       If you face any problem, please call bKash Helpline at 16247"
"In some cases, merchant may request bKash to hold your payment amount instead of completing the entire payment process till the confirmation of availability of product and/or service from the merchant's end. In these cases, you will not receive an instant payment notification. However, the payment amount will be deducted from your balance and held by bKash for a certain period of time. Based on the confirmation from merchant's system, the held payment amount will be transferred to merchant or returned to your bKash account with notification."
"In absence of any confirmation from the merchant, your money will be reverted to your bKash account automatically within certain period of time and you will receive a SMS notification."
                                         "If the online merchant is unable to provide the product and/or service (for example, ticket), they can release the money which is immediately reverted to your bKash account.");
}


void MainWindow::on_pushButton_67_clicked()
{
    ui->stackedWidget->setCurrentIndex(20);
}


void MainWindow::on_pushButton_69_clicked()
{
    ui->stackedWidget->setCurrentIndex(6);
}


void MainWindow::on_pushButton_68_clicked()
{
    ui->stackedWidget->setCurrentIndex(20);
}


void MainWindow::on_pushButton_70_clicked()
{
    ui->stackedWidget->setCurrentIndex(6);
}


void MainWindow::on_pushButton_71_clicked()
{
    ui->stackedWidget->setCurrentIndex(9);
}


void MainWindow::on_B_1_clicked()
{
    QVector<QString>xy;
    QVector<QString>FRoOM_D,TO_oD,S_DATE_oD,S_SRNO_oD,STRT_TIME_oD,END_TIME_oD,DAY;

    QFile ree(Flight_choice);
    if(ree.open(QIODevice::ReadOnly))
    {
            QTextStream stream(&ree);
            while ( stream.atEnd()==false)
            {
                xy.push_back(stream.readLine());
            }
            if(xy.at(7)=="nonbooked")
            {

                QFile Fiiile("FLIGHT.txt");
                int i=0;
                if(Fiiile.open(QIODevice::ReadOnly))
                {
                    QTextStream stream(&Fiiile);
                    while ( stream.atEnd()==false)
                    {
                        S_SRNO_oD.push_back(stream.readLine());
                        FRoOM_D.push_back(stream.readLine());
                        TO_oD.push_back(stream.readLine());
                        STRT_TIME_oD.push_back(stream.readLine());
                        END_TIME_oD.push_back(stream.readLine());
                        S_DATE_oD.push_back(stream.readLine());
                        DAY.push_back(stream.readLine());
                    }
                }
                Fiiile.close();
                int inh = S_SRNO_oD.indexOf(Flight_choice);

                ui->SHEDULE_CHECK_13->setItem(0,0,new QTableWidgetItem(xy.at(81)));
                ui->SHEDULE_CHECK_13->setItem(1,0,new QTableWidgetItem("B1"));
                ui->Ticket_P->setText("B1");ui->CLASS_P->setText("Business class");BOOKKING=Flight_choice+"B1";
                ui->SHEDULE_CHECK_13->setItem(2,0,new QTableWidgetItem(FRoOM_D.at(inh)));
                ui->SHEDULE_CHECK_13->setItem(3,0,new QTableWidgetItem(TO_oD.at(inh)));
                ui->SHEDULE_CHECK_13->setItem(4,0,new QTableWidgetItem(xy.at(84)));
                ui->stackedWidget->setCurrentIndex(23);
            }
            else
            {
                QMessageBox :: warning(this,"Ticket","NOT AVAILABLE!");
            }
    }
    ree.close();
}


void MainWindow::on_B_2_clicked()
{
    QVector<QString>xy;
    QVector<QString>FRoOM_D,TO_oD,S_DATE_oD,S_SRNO_oD,STRT_TIME_oD,END_TIME_oD,DAY;

    QFile ree(Flight_choice);
    if(ree.open(QIODevice::ReadOnly))
    {
            QTextStream stream(&ree);
            while ( stream.atEnd()==false)
            {
                xy.push_back(stream.readLine());
            }
            if(xy.at(8)=="nonbooked")
            {

                QFile Fiiile("FLIGHT.txt");
                if(Fiiile.open(QIODevice::ReadOnly))
                {
                    QTextStream stream(&Fiiile);
                    while ( stream.atEnd()==false)
                    {
                        S_SRNO_oD.push_back(stream.readLine());
                        FRoOM_D.push_back(stream.readLine());
                        TO_oD.push_back(stream.readLine());
                        STRT_TIME_oD.push_back(stream.readLine());
                        END_TIME_oD.push_back(stream.readLine());
                        S_DATE_oD.push_back(stream.readLine());
                        DAY.push_back(stream.readLine());
                    }
                }
                Fiiile.close();
                int inh = S_SRNO_oD.indexOf(Flight_choice);

                ui->SHEDULE_CHECK_13->setItem(0,0,new QTableWidgetItem(xy.at(81)));
                ui->SHEDULE_CHECK_13->setItem(1,0,new QTableWidgetItem("B2"));
                ui->Ticket_P->setText("B2");ui->CLASS_P->setText("Business class");BOOKKING=Flight_choice+"B2";
                ui->SHEDULE_CHECK_13->setItem(2,0,new QTableWidgetItem(FRoOM_D.at(inh)));
                ui->SHEDULE_CHECK_13->setItem(3,0,new QTableWidgetItem(TO_oD.at(inh)));
                ui->SHEDULE_CHECK_13->setItem(4,0,new QTableWidgetItem(xy.at(84)));
                ui->stackedWidget->setCurrentIndex(23);
            }
            else
            {
                QMessageBox :: warning(this,"Ticket","NOT AVAILABLE!");
            }
    }
    ree.close();
}


void MainWindow::on_B_3_clicked()
{
    QVector<QString>xy;
    QVector<QString>FRoOM_D,TO_oD,S_DATE_oD,S_SRNO_oD,STRT_TIME_oD,END_TIME_oD,DAY;

    QFile ree(Flight_choice);
    if(ree.open(QIODevice::ReadOnly))
    {
            QTextStream stream(&ree);
            while ( stream.atEnd()==false)
            {
                xy.push_back(stream.readLine());
            }
            if(xy.at(9)=="nonbooked")
            {

                QFile Fiiile("FLIGHT.txt");
                int i=0;
                if(Fiiile.open(QIODevice::ReadOnly))
                {
                    QTextStream stream(&Fiiile);
                    while ( stream.atEnd()==false)
                    {
                        S_SRNO_oD.push_back(stream.readLine());
                        FRoOM_D.push_back(stream.readLine());
                        TO_oD.push_back(stream.readLine());
                        STRT_TIME_oD.push_back(stream.readLine());
                        END_TIME_oD.push_back(stream.readLine());
                        S_DATE_oD.push_back(stream.readLine());
                        DAY.push_back(stream.readLine());
                    }
                }
                Fiiile.close();
                int inh = S_SRNO_oD.indexOf(Flight_choice);

                ui->SHEDULE_CHECK_13->setItem(0,0,new QTableWidgetItem(xy.at(81)));
                ui->SHEDULE_CHECK_13->setItem(1,0,new QTableWidgetItem("B3"));
                ui->Ticket_P->setText("B3");ui->CLASS_P->setText("Business class");BOOKKING=Flight_choice+"B3";
                ui->SHEDULE_CHECK_13->setItem(2,0,new QTableWidgetItem(FRoOM_D.at(inh)));
                ui->SHEDULE_CHECK_13->setItem(3,0,new QTableWidgetItem(TO_oD.at(inh)));
                ui->SHEDULE_CHECK_13->setItem(4,0,new QTableWidgetItem(xy.at(84)));
                ui->stackedWidget->setCurrentIndex(23);
            }
            else
            {
                QMessageBox :: warning(this,"Ticket","NOT AVAILABLE!");
            }
    }
    ree.close();
}


void MainWindow::on_B_4_clicked()
{
    QVector<QString>xy;
    QVector<QString>FRoOM_D,TO_oD,S_DATE_oD,S_SRNO_oD,STRT_TIME_oD,END_TIME_oD,DAY;

    QFile ree(Flight_choice);
    if(ree.open(QIODevice::ReadOnly))
    {
            QTextStream stream(&ree);
            while ( stream.atEnd()==false)
            {
                xy.push_back(stream.readLine());
            }
            if(xy.at(10)=="nonbooked")
            {

                QFile Fiiile("FLIGHT.txt");
                int i=0;
                if(Fiiile.open(QIODevice::ReadOnly))
                {
                    QTextStream stream(&Fiiile);
                    while ( stream.atEnd()==false)
                    {
                        S_SRNO_oD.push_back(stream.readLine());
                        FRoOM_D.push_back(stream.readLine());
                        TO_oD.push_back(stream.readLine());
                        STRT_TIME_oD.push_back(stream.readLine());
                        END_TIME_oD.push_back(stream.readLine());
                        S_DATE_oD.push_back(stream.readLine());
                        DAY.push_back(stream.readLine());
                    }
                }
                Fiiile.close();
                int inh = S_SRNO_oD.indexOf(Flight_choice);

                ui->SHEDULE_CHECK_13->setItem(0,0,new QTableWidgetItem(xy.at(81)));
                ui->SHEDULE_CHECK_13->setItem(1,0,new QTableWidgetItem("B4"));
                ui->Ticket_P->setText("B4");ui->CLASS_P->setText("Business class");BOOKKING=Flight_choice+"B4";
                ui->SHEDULE_CHECK_13->setItem(2,0,new QTableWidgetItem(FRoOM_D.at(inh)));
                ui->SHEDULE_CHECK_13->setItem(3,0,new QTableWidgetItem(TO_oD.at(inh)));
                ui->SHEDULE_CHECK_13->setItem(4,0,new QTableWidgetItem(xy.at(84)));
                ui->stackedWidget->setCurrentIndex(23);
            }
            else
            {
                QMessageBox :: warning(this,"Ticket","NOT AVAILABLE!");
            }
    }
    ree.close();
}


void MainWindow::on_B_5_clicked()
{
    QVector<QString>xy;
    QVector<QString>FRoOM_D,TO_oD,S_DATE_oD,S_SRNO_oD,STRT_TIME_oD,END_TIME_oD,DAY;

    QFile ree(Flight_choice);
    if(ree.open(QIODevice::ReadOnly))
    {
            QTextStream stream(&ree);
            while ( stream.atEnd()==false)
            {
                xy.push_back(stream.readLine());
            }
            if(xy.at(11)=="nonbooked")
            {

                QFile Fiiile("FLIGHT.txt");
                int i=0;
                if(Fiiile.open(QIODevice::ReadOnly))
                {
                    QTextStream stream(&Fiiile);
                    while ( stream.atEnd()==false)
                    {
                        S_SRNO_oD.push_back(stream.readLine());
                        FRoOM_D.push_back(stream.readLine());
                        TO_oD.push_back(stream.readLine());
                        STRT_TIME_oD.push_back(stream.readLine());
                        END_TIME_oD.push_back(stream.readLine());
                        S_DATE_oD.push_back(stream.readLine());
                        DAY.push_back(stream.readLine());
                    }
                }
                Fiiile.close();
                int inh = S_SRNO_oD.indexOf(Flight_choice);

                ui->SHEDULE_CHECK_13->setItem(0,0,new QTableWidgetItem(xy.at(81)));
                ui->SHEDULE_CHECK_13->setItem(1,0,new QTableWidgetItem("B5"));
                ui->Ticket_P->setText("B5");ui->CLASS_P->setText("Business class");BOOKKING=Flight_choice+"B5";
                ui->SHEDULE_CHECK_13->setItem(2,0,new QTableWidgetItem(FRoOM_D.at(inh)));
                ui->SHEDULE_CHECK_13->setItem(3,0,new QTableWidgetItem(TO_oD.at(inh)));
                ui->SHEDULE_CHECK_13->setItem(4,0,new QTableWidgetItem(xy.at(84)));
                ui->stackedWidget->setCurrentIndex(23);
            }
            else
            {
                QMessageBox :: warning(this,"Ticket","NOT AVAILABLE!");
            }
    }
    ree.close();
}


void MainWindow::on_B_6_clicked()
{
    QVector<QString>xy;
    QVector<QString>FRoOM_D,TO_oD,S_DATE_oD,S_SRNO_oD,STRT_TIME_oD,END_TIME_oD,DAY;

    QFile ree(Flight_choice);
    if(ree.open(QIODevice::ReadOnly))
    {
            QTextStream stream(&ree);
            while ( stream.atEnd()==false)
            {
                xy.push_back(stream.readLine());
            }
            if(xy.at(12)=="nonbooked")
            {

                QFile Fiiile("FLIGHT.txt");
                int i=0;
                if(Fiiile.open(QIODevice::ReadOnly))
                {
                    QTextStream stream(&Fiiile);
                    while ( stream.atEnd()==false)
                    {
                        S_SRNO_oD.push_back(stream.readLine());
                        FRoOM_D.push_back(stream.readLine());
                        TO_oD.push_back(stream.readLine());
                        STRT_TIME_oD.push_back(stream.readLine());
                        END_TIME_oD.push_back(stream.readLine());
                        S_DATE_oD.push_back(stream.readLine());
                        DAY.push_back(stream.readLine());
                    }
                }
                Fiiile.close();
                int inh = S_SRNO_oD.indexOf(Flight_choice);

                ui->SHEDULE_CHECK_13->setItem(0,0,new QTableWidgetItem(xy.at(81)));
                ui->SHEDULE_CHECK_13->setItem(1,0,new QTableWidgetItem("B6"));
                ui->Ticket_P->setText("B6");ui->CLASS_P->setText("Business class");BOOKKING=Flight_choice+"B6";
                ui->SHEDULE_CHECK_13->setItem(2,0,new QTableWidgetItem(FRoOM_D.at(inh)));
                ui->SHEDULE_CHECK_13->setItem(3,0,new QTableWidgetItem(TO_oD.at(inh)));
                ui->SHEDULE_CHECK_13->setItem(4,0,new QTableWidgetItem(xy.at(84)));
                ui->stackedWidget->setCurrentIndex(23);
            }
            else
            {
                QMessageBox :: warning(this,"Ticket","NOT AVAILABLE!");
            }
    }
    ree.close();
}


void MainWindow::on_C_1_clicked()
{
    QVector<QString>xy;
    QVector<QString>FRoOM_D,TO_oD,S_DATE_oD,S_SRNO_oD,STRT_TIME_oD,END_TIME_oD,DAY;

    QFile ree(Flight_choice);
    if(ree.open(QIODevice::ReadOnly))
    {
            QTextStream stream(&ree);
            while ( stream.atEnd()==false)
            {
                xy.push_back(stream.readLine());
            }
            if(xy.at(13)=="nonbooked")
            {

                QFile Fiiile("FLIGHT.txt");
                int i=0;
                if(Fiiile.open(QIODevice::ReadOnly))
                {
                    QTextStream stream(&Fiiile);
                    while ( stream.atEnd()==false)
                    {
                        S_SRNO_oD.push_back(stream.readLine());
                        FRoOM_D.push_back(stream.readLine());
                        TO_oD.push_back(stream.readLine());
                        STRT_TIME_oD.push_back(stream.readLine());
                        END_TIME_oD.push_back(stream.readLine());
                        S_DATE_oD.push_back(stream.readLine());
                        DAY.push_back(stream.readLine());
                    }
                }
                Fiiile.close();
                int inh = S_SRNO_oD.indexOf(Flight_choice);

                ui->SHEDULE_CHECK_13->setItem(0,0,new QTableWidgetItem(xy.at(81)));
                ui->SHEDULE_CHECK_13->setItem(1,0,new QTableWidgetItem("C1"));
                ui->Ticket_P->setText("C1");ui->CLASS_P->setText("Business class");BOOKKING=Flight_choice+"C1";
                ui->SHEDULE_CHECK_13->setItem(2,0,new QTableWidgetItem(FRoOM_D.at(inh)));
                ui->SHEDULE_CHECK_13->setItem(3,0,new QTableWidgetItem(TO_oD.at(inh)));
                ui->SHEDULE_CHECK_13->setItem(4,0,new QTableWidgetItem(xy.at(84)));
                ui->stackedWidget->setCurrentIndex(23);
            }
            else
            {
                QMessageBox :: warning(this,"Ticket","NOT AVAILABLE!");
            }
    }
    ree.close();

}


void MainWindow::on_C_2_clicked()
{
    QVector<QString>xy;
    QVector<QString>FRoOM_D,TO_oD,S_DATE_oD,S_SRNO_oD,STRT_TIME_oD,END_TIME_oD,DAY;

    QFile ree(Flight_choice);
    if(ree.open(QIODevice::ReadOnly))
    {
            QTextStream stream(&ree);
            while ( stream.atEnd()==false)
            {
                xy.push_back(stream.readLine());
            }
            if(xy.at(14)=="nonbooked")
            {

                QFile Fiiile("FLIGHT.txt");
                int i=0;
                if(Fiiile.open(QIODevice::ReadOnly))
                {
                    QTextStream stream(&Fiiile);
                    while ( stream.atEnd()==false)
                    {
                        S_SRNO_oD.push_back(stream.readLine());
                        FRoOM_D.push_back(stream.readLine());
                        TO_oD.push_back(stream.readLine());
                        STRT_TIME_oD.push_back(stream.readLine());
                        END_TIME_oD.push_back(stream.readLine());
                        S_DATE_oD.push_back(stream.readLine());
                        DAY.push_back(stream.readLine());
                    }
                }
                Fiiile.close();
                int inh = S_SRNO_oD.indexOf(Flight_choice);

                ui->SHEDULE_CHECK_13->setItem(0,0,new QTableWidgetItem(xy.at(81)));
                ui->SHEDULE_CHECK_13->setItem(1,0,new QTableWidgetItem("C2"));
                ui->Ticket_P->setText("C2");ui->CLASS_P->setText("Business class");BOOKKING=Flight_choice+"C2";
                ui->SHEDULE_CHECK_13->setItem(2,0,new QTableWidgetItem(FRoOM_D.at(inh)));
                ui->SHEDULE_CHECK_13->setItem(3,0,new QTableWidgetItem(TO_oD.at(inh)));
                ui->SHEDULE_CHECK_13->setItem(4,0,new QTableWidgetItem(xy.at(84)));
                ui->stackedWidget->setCurrentIndex(23);
            }
            else
            {
                QMessageBox :: warning(this,"Ticket","NOT AVAILABLE!");
            }
    }
    ree.close();

}


void MainWindow::on_C_3_clicked()
{
    QVector<QString>xy;
    QVector<QString>FRoOM_D,TO_oD,S_DATE_oD,S_SRNO_oD,STRT_TIME_oD,END_TIME_oD,DAY;

    QFile ree(Flight_choice);
    if(ree.open(QIODevice::ReadOnly))
    {
            QTextStream stream(&ree);
            while ( stream.atEnd()==false)
            {
                xy.push_back(stream.readLine());
            }
            if(xy.at(15)=="nonbooked")
            {

                QFile Fiiile("FLIGHT.txt");
                int i=0;
                if(Fiiile.open(QIODevice::ReadOnly))
                {
                    QTextStream stream(&Fiiile);
                    while ( stream.atEnd()==false)
                    {
                        S_SRNO_oD.push_back(stream.readLine());
                        FRoOM_D.push_back(stream.readLine());
                        TO_oD.push_back(stream.readLine());
                        STRT_TIME_oD.push_back(stream.readLine());
                        END_TIME_oD.push_back(stream.readLine());
                        S_DATE_oD.push_back(stream.readLine());
                        DAY.push_back(stream.readLine());
                    }
                }
                Fiiile.close();
                int inh = S_SRNO_oD.indexOf(Flight_choice);

                ui->SHEDULE_CHECK_13->setItem(0,0,new QTableWidgetItem(xy.at(81)));
                ui->SHEDULE_CHECK_13->setItem(1,0,new QTableWidgetItem("C3"));
                ui->Ticket_P->setText("C3");ui->CLASS_P->setText("Business class");BOOKKING=Flight_choice+"C3";
                ui->SHEDULE_CHECK_13->setItem(2,0,new QTableWidgetItem(FRoOM_D.at(inh)));
                ui->SHEDULE_CHECK_13->setItem(3,0,new QTableWidgetItem(TO_oD.at(inh)));
                ui->SHEDULE_CHECK_13->setItem(4,0,new QTableWidgetItem(xy.at(84)));
                ui->stackedWidget->setCurrentIndex(23);
            }
            else
            {
                QMessageBox :: warning(this,"Ticket","NOT AVAILABLE!");
            }
    }
    ree.close();
}


void MainWindow::on_C_4_clicked()
{
    QVector<QString>xy;
    QVector<QString>FRoOM_D,TO_oD,S_DATE_oD,S_SRNO_oD,STRT_TIME_oD,END_TIME_oD,DAY;

    QFile ree(Flight_choice);
    if(ree.open(QIODevice::ReadOnly))
    {
            QTextStream stream(&ree);
            while ( stream.atEnd()==false)
            {
                xy.push_back(stream.readLine());
            }
            if(xy.at(16)=="nonbooked")
            {

                QFile Fiiile("FLIGHT.txt");
                int i=0;
                if(Fiiile.open(QIODevice::ReadOnly))
                {
                    QTextStream stream(&Fiiile);
                    while ( stream.atEnd()==false)
                    {
                        S_SRNO_oD.push_back(stream.readLine());
                        FRoOM_D.push_back(stream.readLine());
                        TO_oD.push_back(stream.readLine());
                        STRT_TIME_oD.push_back(stream.readLine());
                        END_TIME_oD.push_back(stream.readLine());
                        S_DATE_oD.push_back(stream.readLine());
                        DAY.push_back(stream.readLine());
                    }
                }
                Fiiile.close();
                int inh = S_SRNO_oD.indexOf(Flight_choice);

                ui->SHEDULE_CHECK_13->setItem(0,0,new QTableWidgetItem(xy.at(81)));
                ui->SHEDULE_CHECK_13->setItem(1,0,new QTableWidgetItem("C4"));
                ui->Ticket_P->setText("C4");ui->CLASS_P->setText("Business class");BOOKKING=Flight_choice+"C4";
                ui->SHEDULE_CHECK_13->setItem(2,0,new QTableWidgetItem(FRoOM_D.at(inh)));
                ui->SHEDULE_CHECK_13->setItem(3,0,new QTableWidgetItem(TO_oD.at(inh)));
                ui->SHEDULE_CHECK_13->setItem(4,0,new QTableWidgetItem(xy.at(84)));
                ui->stackedWidget->setCurrentIndex(23);
            }
            else
            {
                QMessageBox :: warning(this,"Ticket","NOT AVAILABLE!");
            }
    }
    ree.close();
}


void MainWindow::on_C_5_clicked()
{
    QVector<QString>xy;
    QVector<QString>FRoOM_D,TO_oD,S_DATE_oD,S_SRNO_oD,STRT_TIME_oD,END_TIME_oD,DAY;

    QFile ree(Flight_choice);
    if(ree.open(QIODevice::ReadOnly))
    {
            QTextStream stream(&ree);
            while ( stream.atEnd()==false)
            {
                xy.push_back(stream.readLine());
            }
            if(xy.at(17)=="nonbooked")
            {

                QFile Fiiile("FLIGHT.txt");
                int i=0;
                if(Fiiile.open(QIODevice::ReadOnly))
                {
                    QTextStream stream(&Fiiile);
                    while ( stream.atEnd()==false)
                    {
                        S_SRNO_oD.push_back(stream.readLine());
                        FRoOM_D.push_back(stream.readLine());
                        TO_oD.push_back(stream.readLine());
                        STRT_TIME_oD.push_back(stream.readLine());
                        END_TIME_oD.push_back(stream.readLine());
                        S_DATE_oD.push_back(stream.readLine());
                        DAY.push_back(stream.readLine());
                    }
                }
                Fiiile.close();
                int inh = S_SRNO_oD.indexOf(Flight_choice);

                ui->SHEDULE_CHECK_13->setItem(0,0,new QTableWidgetItem(xy.at(81)));
                ui->SHEDULE_CHECK_13->setItem(1,0,new QTableWidgetItem("C5"));
                ui->Ticket_P->setText("C5");ui->CLASS_P->setText("Business class");BOOKKING=Flight_choice+"C5";
                ui->SHEDULE_CHECK_13->setItem(2,0,new QTableWidgetItem(FRoOM_D.at(inh)));
                ui->SHEDULE_CHECK_13->setItem(3,0,new QTableWidgetItem(TO_oD.at(inh)));
                ui->SHEDULE_CHECK_13->setItem(4,0,new QTableWidgetItem(xy.at(84)));
                ui->stackedWidget->setCurrentIndex(23);
            }
            else
            {
                QMessageBox :: warning(this,"Ticket","NOT AVAILABLE!");
            }
    }
    ree.close();
}


void MainWindow::on_C_6_clicked()
{
    QVector<QString>xy;
    QVector<QString>FRoOM_D,TO_oD,S_DATE_oD,S_SRNO_oD,STRT_TIME_oD,END_TIME_oD,DAY;

    QFile ree(Flight_choice);
    if(ree.open(QIODevice::ReadOnly))
    {
            QTextStream stream(&ree);
            while ( stream.atEnd()==false)
            {
                xy.push_back(stream.readLine());
            }
            if(xy.at(18)=="nonbooked")
            {

                QFile Fiiile("FLIGHT.txt");
                int i=0;
                if(Fiiile.open(QIODevice::ReadOnly))
                {
                    QTextStream stream(&Fiiile);
                    while ( stream.atEnd()==false)
                    {
                        S_SRNO_oD.push_back(stream.readLine());
                        FRoOM_D.push_back(stream.readLine());
                        TO_oD.push_back(stream.readLine());
                        STRT_TIME_oD.push_back(stream.readLine());
                        END_TIME_oD.push_back(stream.readLine());
                        S_DATE_oD.push_back(stream.readLine());
                        DAY.push_back(stream.readLine());
                    }
                }
                Fiiile.close();
                int inh = S_SRNO_oD.indexOf(Flight_choice);

                ui->SHEDULE_CHECK_13->setItem(0,0,new QTableWidgetItem(xy.at(81)));
                ui->SHEDULE_CHECK_13->setItem(1,0,new QTableWidgetItem("C6"));
                ui->Ticket_P->setText("C6");ui->CLASS_P->setText("Business class");BOOKKING=Flight_choice+"C6";
                ui->SHEDULE_CHECK_13->setItem(2,0,new QTableWidgetItem(FRoOM_D.at(inh)));
                ui->SHEDULE_CHECK_13->setItem(3,0,new QTableWidgetItem(TO_oD.at(inh)));
                ui->SHEDULE_CHECK_13->setItem(4,0,new QTableWidgetItem(xy.at(84)));
                ui->stackedWidget->setCurrentIndex(23);
            }
            else
            {
                QMessageBox :: warning(this,"Ticket","NOT AVAILABLE!");
            }
    }
    ree.close();
}


void MainWindow::on_D_1_clicked()
{
    QVector<QString>xy;
    QVector<QString>FRoOM_D,TO_oD,S_DATE_oD,S_SRNO_oD,STRT_TIME_oD,END_TIME_oD,DAY;

    QFile ree(Flight_choice);
    if(ree.open(QIODevice::ReadOnly))
    {
            QTextStream stream(&ree);
            while ( stream.atEnd()==false)
            {
                xy.push_back(stream.readLine());
            }
            if(xy.at(19)=="nonbooked")
            {

                QFile Fiiile("FLIGHT.txt");
                int i=0;
                if(Fiiile.open(QIODevice::ReadOnly))
                {
                    QTextStream stream(&Fiiile);
                    while ( stream.atEnd()==false)
                    {
                        S_SRNO_oD.push_back(stream.readLine());
                        FRoOM_D.push_back(stream.readLine());
                        TO_oD.push_back(stream.readLine());
                        STRT_TIME_oD.push_back(stream.readLine());
                        END_TIME_oD.push_back(stream.readLine());
                        S_DATE_oD.push_back(stream.readLine());
                        DAY.push_back(stream.readLine());
                    }
                }
                Fiiile.close();
                int inh = S_SRNO_oD.indexOf(Flight_choice);

                ui->SHEDULE_CHECK_13->setItem(0,0,new QTableWidgetItem(xy.at(81)));
                ui->SHEDULE_CHECK_13->setItem(1,0,new QTableWidgetItem("D1"));
                ui->Ticket_P->setText("D1");ui->CLASS_P->setText("Business class");BOOKKING=Flight_choice+"D1";
                ui->SHEDULE_CHECK_13->setItem(2,0,new QTableWidgetItem(FRoOM_D.at(inh)));
                ui->SHEDULE_CHECK_13->setItem(3,0,new QTableWidgetItem(TO_oD.at(inh)));
                ui->SHEDULE_CHECK_13->setItem(4,0,new QTableWidgetItem(xy.at(84)));
                ui->stackedWidget->setCurrentIndex(23);
            }
            else
            {
                QMessageBox :: warning(this,"Ticket","NOT AVAILABLE!");
            }
    }
    ree.close();
}


void MainWindow::on_D_2_clicked()
{
    QVector<QString>xy;
    QVector<QString>FRoOM_D,TO_oD,S_DATE_oD,S_SRNO_oD,STRT_TIME_oD,END_TIME_oD,DAY;

    QFile ree(Flight_choice);
    if(ree.open(QIODevice::ReadOnly))
    {
            QTextStream stream(&ree);
            while ( stream.atEnd()==false)
            {
                xy.push_back(stream.readLine());
            }
            if(xy.at(20)=="nonbooked")
            {

                QFile Fiiile("FLIGHT.txt");
                int i=0;
                if(Fiiile.open(QIODevice::ReadOnly))
                {
                    QTextStream stream(&Fiiile);
                    while ( stream.atEnd()==false)
                    {
                        S_SRNO_oD.push_back(stream.readLine());
                        FRoOM_D.push_back(stream.readLine());
                        TO_oD.push_back(stream.readLine());
                        STRT_TIME_oD.push_back(stream.readLine());
                        END_TIME_oD.push_back(stream.readLine());
                        S_DATE_oD.push_back(stream.readLine());
                        DAY.push_back(stream.readLine());
                    }
                }
                Fiiile.close();
                int inh = S_SRNO_oD.indexOf(Flight_choice);

                ui->SHEDULE_CHECK_13->setItem(0,0,new QTableWidgetItem(xy.at(81)));
                ui->SHEDULE_CHECK_13->setItem(1,0,new QTableWidgetItem("D2"));
                ui->Ticket_P->setText("D2");ui->CLASS_P->setText("Business class");BOOKKING=Flight_choice+"D2";
                ui->SHEDULE_CHECK_13->setItem(2,0,new QTableWidgetItem(FRoOM_D.at(inh)));
                ui->SHEDULE_CHECK_13->setItem(3,0,new QTableWidgetItem(TO_oD.at(inh)));
                ui->SHEDULE_CHECK_13->setItem(4,0,new QTableWidgetItem(xy.at(84)));
                ui->stackedWidget->setCurrentIndex(23);
            }
            else
            {
                QMessageBox :: warning(this,"Ticket","NOT AVAILABLE!");
            }
    }
    ree.close();
}


void MainWindow::on_D_3_clicked()
{
    QVector<QString>xy;
    QVector<QString>FRoOM_D,TO_oD,S_DATE_oD,S_SRNO_oD,STRT_TIME_oD,END_TIME_oD,DAY;

    QFile ree(Flight_choice);
    if(ree.open(QIODevice::ReadOnly))
    {
            QTextStream stream(&ree);
            while ( stream.atEnd()==false)
            {
                xy.push_back(stream.readLine());
            }
            if(xy.at(21)=="nonbooked")
            {

                QFile Fiiile("FLIGHT.txt");
                int i=0;
                if(Fiiile.open(QIODevice::ReadOnly))
                {
                    QTextStream stream(&Fiiile);
                    while ( stream.atEnd()==false)
                    {
                        S_SRNO_oD.push_back(stream.readLine());
                        FRoOM_D.push_back(stream.readLine());
                        TO_oD.push_back(stream.readLine());
                        STRT_TIME_oD.push_back(stream.readLine());
                        END_TIME_oD.push_back(stream.readLine());
                        S_DATE_oD.push_back(stream.readLine());
                        DAY.push_back(stream.readLine());
                    }
                }
                Fiiile.close();
                int inh = S_SRNO_oD.indexOf(Flight_choice);

                ui->SHEDULE_CHECK_13->setItem(0,0,new QTableWidgetItem(xy.at(81)));
                ui->SHEDULE_CHECK_13->setItem(1,0,new QTableWidgetItem("D3"));
                ui->Ticket_P->setText("D3");ui->CLASS_P->setText("Business class");BOOKKING=Flight_choice+"D3";
                ui->SHEDULE_CHECK_13->setItem(2,0,new QTableWidgetItem(FRoOM_D.at(inh)));
                ui->SHEDULE_CHECK_13->setItem(3,0,new QTableWidgetItem(TO_oD.at(inh)));
                ui->SHEDULE_CHECK_13->setItem(4,0,new QTableWidgetItem(xy.at(84)));
                ui->stackedWidget->setCurrentIndex(23);
            }
            else
            {
                QMessageBox :: warning(this,"Ticket","NOT AVAILABLE!");
            }
    }
    ree.close();
}


void MainWindow::on_D_4_clicked()
{
    QVector<QString>xy;
    QVector<QString>FRoOM_D,TO_oD,S_DATE_oD,S_SRNO_oD,STRT_TIME_oD,END_TIME_oD,DAY;

    QFile ree(Flight_choice);
    if(ree.open(QIODevice::ReadOnly))
    {
            QTextStream stream(&ree);
            while ( stream.atEnd()==false)
            {
                xy.push_back(stream.readLine());
            }
            if(xy.at(22)=="nonbooked")
            {

                QFile Fiiile("FLIGHT.txt");
                if(Fiiile.open(QIODevice::ReadOnly))
                {
                    QTextStream stream(&Fiiile);
                    while ( stream.atEnd()==false)
                    {
                        S_SRNO_oD.push_back(stream.readLine());
                        FRoOM_D.push_back(stream.readLine());
                        TO_oD.push_back(stream.readLine());
                        STRT_TIME_oD.push_back(stream.readLine());
                        END_TIME_oD.push_back(stream.readLine());
                        S_DATE_oD.push_back(stream.readLine());
                        DAY.push_back(stream.readLine());
                    }
                }
                Fiiile.close();
                int inh = S_SRNO_oD.indexOf(Flight_choice);

                ui->SHEDULE_CHECK_13->setItem(0,0,new QTableWidgetItem(xy.at(81)));
                ui->SHEDULE_CHECK_13->setItem(1,0,new QTableWidgetItem("D4"));
                ui->Ticket_P->setText("D4");ui->CLASS_P->setText("Business class");BOOKKING=Flight_choice+"D4";
                ui->SHEDULE_CHECK_13->setItem(2,0,new QTableWidgetItem(FRoOM_D.at(inh)));
                ui->SHEDULE_CHECK_13->setItem(3,0,new QTableWidgetItem(TO_oD.at(inh)));
                ui->SHEDULE_CHECK_13->setItem(4,0,new QTableWidgetItem(xy.at(84)));
                ui->stackedWidget->setCurrentIndex(23);
            }
            else
            {
                QMessageBox :: warning(this,"Ticket","NOT AVAILABLE!");
            }
    }
    ree.close();
}


void MainWindow::on_D_5_clicked()
{
    QVector<QString>xy;
    QVector<QString>FRoOM_D,TO_oD,S_DATE_oD,S_SRNO_oD,STRT_TIME_oD,END_TIME_oD,DAY;

    QFile ree(Flight_choice);
    if(ree.open(QIODevice::ReadOnly))
    {
            QTextStream stream(&ree);
            while ( stream.atEnd()==false)
            {
                xy.push_back(stream.readLine());
            }
            if(xy.at(23)=="nonbooked")
            {

                QFile Fiiile("FLIGHT.txt");
                if(Fiiile.open(QIODevice::ReadOnly))
                {
                    QTextStream stream(&Fiiile);
                    while ( stream.atEnd()==false)
                    {
                        S_SRNO_oD.push_back(stream.readLine());
                        FRoOM_D.push_back(stream.readLine());
                        TO_oD.push_back(stream.readLine());
                        STRT_TIME_oD.push_back(stream.readLine());
                        END_TIME_oD.push_back(stream.readLine());
                        S_DATE_oD.push_back(stream.readLine());
                        DAY.push_back(stream.readLine());
                    }
                }
                Fiiile.close();
                int inh = S_SRNO_oD.indexOf(Flight_choice);

                ui->SHEDULE_CHECK_13->setItem(0,0,new QTableWidgetItem(xy.at(81)));
                ui->SHEDULE_CHECK_13->setItem(1,0,new QTableWidgetItem("D5"));
                ui->Ticket_P->setText("D5");ui->CLASS_P->setText("Business class");BOOKKING=Flight_choice+"D5";
                ui->SHEDULE_CHECK_13->setItem(2,0,new QTableWidgetItem(FRoOM_D.at(inh)));
                ui->SHEDULE_CHECK_13->setItem(3,0,new QTableWidgetItem(TO_oD.at(inh)));
                ui->SHEDULE_CHECK_13->setItem(4,0,new QTableWidgetItem(xy.at(84)));
                ui->stackedWidget->setCurrentIndex(23);
            }
            else
            {
                QMessageBox :: warning(this,"Ticket","NOT AVAILABLE!");
            }
    }
    ree.close();
}


void MainWindow::on_D_6_clicked()
{
    QVector<QString>xy;
    QVector<QString>FRoOM_D,TO_oD,S_DATE_oD,S_SRNO_oD,STRT_TIME_oD,END_TIME_oD,DAY;

    QFile ree(Flight_choice);
    if(ree.open(QIODevice::ReadOnly))
    {
            QTextStream stream(&ree);
            while ( stream.atEnd()==false)
            {
                xy.push_back(stream.readLine());
            }
            if(xy.at(24)=="nonbooked")
            {

                QFile Fiiile("FLIGHT.txt");
                if(Fiiile.open(QIODevice::ReadOnly))
                {
                    QTextStream stream(&Fiiile);
                    while ( stream.atEnd()==false)
                    {
                        S_SRNO_oD.push_back(stream.readLine());
                        FRoOM_D.push_back(stream.readLine());
                        TO_oD.push_back(stream.readLine());
                        STRT_TIME_oD.push_back(stream.readLine());
                        END_TIME_oD.push_back(stream.readLine());
                        S_DATE_oD.push_back(stream.readLine());
                        DAY.push_back(stream.readLine());
                    }
                }
                Fiiile.close();
                int inh = S_SRNO_oD.indexOf(Flight_choice);

                ui->SHEDULE_CHECK_13->setItem(0,0,new QTableWidgetItem(xy.at(81)));
                ui->SHEDULE_CHECK_13->setItem(1,0,new QTableWidgetItem("D6"));
                ui->Ticket_P->setText("D6");ui->CLASS_P->setText("Business class");BOOKKING=Flight_choice+"D6";
                ui->SHEDULE_CHECK_13->setItem(2,0,new QTableWidgetItem(FRoOM_D.at(inh)));
                ui->SHEDULE_CHECK_13->setItem(3,0,new QTableWidgetItem(TO_oD.at(inh)));
                ui->SHEDULE_CHECK_13->setItem(4,0,new QTableWidgetItem(xy.at(84)));
                ui->stackedWidget->setCurrentIndex(23);
            }
            else
            {
                QMessageBox :: warning(this,"Ticket","NOT AVAILABLE!");
            }
    }
    ree.close();
}


void MainWindow::on_E_1_clicked()
{
    QVector<QString>xy;
    QVector<QString>FRoOM_D,TO_oD,S_DATE_oD,S_SRNO_oD,STRT_TIME_oD,END_TIME_oD,DAY;

    QFile ree(Flight_choice);
    if(ree.open(QIODevice::ReadOnly))
    {
            QTextStream stream(&ree);
            while ( stream.atEnd()==false)
            {
                xy.push_back(stream.readLine());
            }
            if(xy.at(25)=="nonbooked")
            {

                QFile Fiiile("FLIGHT.txt");
                int i=0;
                if(Fiiile.open(QIODevice::ReadOnly))
                {
                    QTextStream stream(&Fiiile);
                    while ( stream.atEnd()==false)
                    {
                        S_SRNO_oD.push_back(stream.readLine());
                        FRoOM_D.push_back(stream.readLine());
                        TO_oD.push_back(stream.readLine());
                        STRT_TIME_oD.push_back(stream.readLine());
                        END_TIME_oD.push_back(stream.readLine());
                        S_DATE_oD.push_back(stream.readLine());
                        DAY.push_back(stream.readLine());
                    }
                }
                Fiiile.close();
                int inh = S_SRNO_oD.indexOf(Flight_choice);

                ui->SHEDULE_CHECK_13->setItem(0,0,new QTableWidgetItem(xy.at(81)));
                ui->SHEDULE_CHECK_13->setItem(1,0,new QTableWidgetItem("E1"));
                ui->Ticket_P->setText("E1");ui->CLASS_P->setText("PREMIUM ECONOMY");BOOKKING=Flight_choice+"E1";
                ui->SHEDULE_CHECK_13->setItem(2,0,new QTableWidgetItem(FRoOM_D.at(inh)));
                ui->SHEDULE_CHECK_13->setItem(3,0,new QTableWidgetItem(TO_oD.at(inh)));
                ui->SHEDULE_CHECK_13->setItem(4,0,new QTableWidgetItem(xy.at(85)));
                ui->stackedWidget->setCurrentIndex(23);
            }
            else
            {
                QMessageBox :: warning(this,"Ticket","NOT AVAILABLE!");
            }
    }
    ree.close();
}


void MainWindow::on_E_2_clicked()
{
    QVector<QString>xy;
    QVector<QString>FRoOM_D,TO_oD,S_DATE_oD,S_SRNO_oD,STRT_TIME_oD,END_TIME_oD,DAY;

    QFile ree(Flight_choice);
    if(ree.open(QIODevice::ReadOnly))
    {
            QTextStream stream(&ree);
            while ( stream.atEnd()==false)
            {
                xy.push_back(stream.readLine());
            }
            if(xy.at(26)=="nonbooked")
            {

                QFile Fiiile("FLIGHT.txt");
                int i=0;
                if(Fiiile.open(QIODevice::ReadOnly))
                {
                    QTextStream stream(&Fiiile);
                    while ( stream.atEnd()==false)
                    {
                        S_SRNO_oD.push_back(stream.readLine());
                        FRoOM_D.push_back(stream.readLine());
                        TO_oD.push_back(stream.readLine());
                        STRT_TIME_oD.push_back(stream.readLine());
                        END_TIME_oD.push_back(stream.readLine());
                        S_DATE_oD.push_back(stream.readLine());DAY.push_back(stream.readLine());
                    }
                }
                Fiiile.close();
                int inh = S_SRNO_oD.indexOf(Flight_choice);

                ui->SHEDULE_CHECK_13->setItem(0,0,new QTableWidgetItem(xy.at(81)));
                ui->SHEDULE_CHECK_13->setItem(1,0,new QTableWidgetItem("E2"));
                ui->Ticket_P->setText("E2");ui->CLASS_P->setText("PREMIUM ECONOMY");BOOKKING=Flight_choice+"E2";
                ui->SHEDULE_CHECK_13->setItem(2,0,new QTableWidgetItem(FRoOM_D.at(inh)));
                ui->SHEDULE_CHECK_13->setItem(3,0,new QTableWidgetItem(TO_oD.at(inh)));
                ui->SHEDULE_CHECK_13->setItem(4,0,new QTableWidgetItem(xy.at(85)));
                ui->stackedWidget->setCurrentIndex(23);
            }
            else
            {
                QMessageBox :: warning(this,"Ticket","NOT AVAILABLE!");
            }
    }
    ree.close();
}


void MainWindow::on_E_3_clicked()
{
    QVector<QString>xy;
    QVector<QString>FRoOM_D,TO_oD,S_DATE_oD,S_SRNO_oD,STRT_TIME_oD,END_TIME_oD,DAY;

    QFile ree(Flight_choice);
    if(ree.open(QIODevice::ReadOnly))
    {
            QTextStream stream(&ree);
            while ( stream.atEnd()==false)
            {
                xy.push_back(stream.readLine());
            }
            if(xy.at(27)=="nonbooked")
            {

                QFile Fiiile("FLIGHT.txt");
                int i=0;
                if(Fiiile.open(QIODevice::ReadOnly))
                {
                    QTextStream stream(&Fiiile);
                    while ( stream.atEnd()==false)
                    {
                        S_SRNO_oD.push_back(stream.readLine());
                        FRoOM_D.push_back(stream.readLine());
                        TO_oD.push_back(stream.readLine());
                        STRT_TIME_oD.push_back(stream.readLine());
                        END_TIME_oD.push_back(stream.readLine());
                        S_DATE_oD.push_back(stream.readLine());DAY.push_back(stream.readLine());
                    }
                }
                Fiiile.close();
                int inh = S_SRNO_oD.indexOf(Flight_choice);

                ui->SHEDULE_CHECK_13->setItem(0,0,new QTableWidgetItem(xy.at(81)));
                ui->SHEDULE_CHECK_13->setItem(1,0,new QTableWidgetItem("E3"));
                ui->Ticket_P->setText("E3");ui->CLASS_P->setText("PREMIUM ECONOMY");BOOKKING=Flight_choice+"E3";
                ui->SHEDULE_CHECK_13->setItem(2,0,new QTableWidgetItem(FRoOM_D.at(inh)));
                ui->SHEDULE_CHECK_13->setItem(3,0,new QTableWidgetItem(TO_oD.at(inh)));
                ui->SHEDULE_CHECK_13->setItem(4,0,new QTableWidgetItem(xy.at(85)));
                ui->stackedWidget->setCurrentIndex(23);
            }
            else
            {
                QMessageBox :: warning(this,"Ticket","NOT AVAILABLE!");
            }
    }
    ree.close();
}


void MainWindow::on_E_4_clicked()
{
    QVector<QString>xy;
    QVector<QString>FRoOM_D,TO_oD,S_DATE_oD,S_SRNO_oD,STRT_TIME_oD,END_TIME_oD,DAY;

    QFile ree(Flight_choice);
    if(ree.open(QIODevice::ReadOnly))
    {
            QTextStream stream(&ree);
            while ( stream.atEnd()==false)
            {
                xy.push_back(stream.readLine());
            }
            if(xy.at(28)=="nonbooked")
            {

                QFile Fiiile("FLIGHT.txt");
                int i=0;
                if(Fiiile.open(QIODevice::ReadOnly))
                {
                    QTextStream stream(&Fiiile);
                    while ( stream.atEnd()==false)
                    {
                        S_SRNO_oD.push_back(stream.readLine());
                        FRoOM_D.push_back(stream.readLine());
                        TO_oD.push_back(stream.readLine());
                        STRT_TIME_oD.push_back(stream.readLine());
                        END_TIME_oD.push_back(stream.readLine());
                        S_DATE_oD.push_back(stream.readLine());DAY.push_back(stream.readLine());
                    }
                }
                Fiiile.close();
                int inh = S_SRNO_oD.indexOf(Flight_choice);

                ui->SHEDULE_CHECK_13->setItem(0,0,new QTableWidgetItem(xy.at(81)));
                ui->SHEDULE_CHECK_13->setItem(1,0,new QTableWidgetItem("E4"));
                ui->Ticket_P->setText("E4");ui->CLASS_P->setText("PREMIUM ECONOMY");BOOKKING=Flight_choice+"E4";
                ui->SHEDULE_CHECK_13->setItem(2,0,new QTableWidgetItem(FRoOM_D.at(inh)));
                ui->SHEDULE_CHECK_13->setItem(3,0,new QTableWidgetItem(TO_oD.at(inh)));
                ui->SHEDULE_CHECK_13->setItem(4,0,new QTableWidgetItem(xy.at(85)));
                ui->stackedWidget->setCurrentIndex(23);
            }
            else
            {
                QMessageBox :: warning(this,"Ticket","NOT AVAILABLE!");
            }
    }
    ree.close();
}


void MainWindow::on_E_5_clicked()
{
    QVector<QString>xy;
    QVector<QString>FRoOM_D,TO_oD,S_DATE_oD,S_SRNO_oD,STRT_TIME_oD,END_TIME_oD,DAY;

    QFile ree(Flight_choice);
    if(ree.open(QIODevice::ReadOnly))
    {
            QTextStream stream(&ree);
            while ( stream.atEnd()==false)
            {
                xy.push_back(stream.readLine());
            }
            if(xy.at(29)=="nonbooked")
            {

                QFile Fiiile("FLIGHT.txt");
                int i=0;
                if(Fiiile.open(QIODevice::ReadOnly))
                {
                    QTextStream stream(&Fiiile);
                    while ( stream.atEnd()==false)
                    {
                        S_SRNO_oD.push_back(stream.readLine());
                        FRoOM_D.push_back(stream.readLine());
                        TO_oD.push_back(stream.readLine());
                        STRT_TIME_oD.push_back(stream.readLine());
                        END_TIME_oD.push_back(stream.readLine());
                        S_DATE_oD.push_back(stream.readLine());
                        DAY.push_back(stream.readLine());
                    }
                }
                Fiiile.close();
                int inh = S_SRNO_oD.indexOf(Flight_choice);

                ui->SHEDULE_CHECK_13->setItem(0,0,new QTableWidgetItem(xy.at(81)));
                ui->SHEDULE_CHECK_13->setItem(1,0,new QTableWidgetItem("E5"));
                ui->Ticket_P->setText("E5");ui->CLASS_P->setText("PREMIUM ECONOMY");BOOKKING=Flight_choice+"E5";
                ui->SHEDULE_CHECK_13->setItem(2,0,new QTableWidgetItem(FRoOM_D.at(inh)));
                ui->SHEDULE_CHECK_13->setItem(3,0,new QTableWidgetItem(TO_oD.at(inh)));
                ui->SHEDULE_CHECK_13->setItem(4,0,new QTableWidgetItem(xy.at(85)));
                ui->stackedWidget->setCurrentIndex(23);
            }
            else
            {
                QMessageBox :: warning(this,"Ticket","NOT AVAILABLE!");
            }
    }
    ree.close();
}


void MainWindow::on_E_6_clicked()
{
    QVector<QString>xy;
    QVector<QString>FRoOM_D,TO_oD,S_DATE_oD,S_SRNO_oD,STRT_TIME_oD,END_TIME_oD,DAY;

    QFile ree(Flight_choice);
    if(ree.open(QIODevice::ReadOnly))
    {
            QTextStream stream(&ree);
            while ( stream.atEnd()==false)
            {
                xy.push_back(stream.readLine());
            }
            if(xy.at(30)=="nonbooked")
            {

                QFile Fiiile("FLIGHT.txt");
                int i=0;
                if(Fiiile.open(QIODevice::ReadOnly))
                {
                    QTextStream stream(&Fiiile);
                    while ( stream.atEnd()==false)
                    {
                        S_SRNO_oD.push_back(stream.readLine());
                        FRoOM_D.push_back(stream.readLine());
                        TO_oD.push_back(stream.readLine());
                        STRT_TIME_oD.push_back(stream.readLine());
                        END_TIME_oD.push_back(stream.readLine());
                        S_DATE_oD.push_back(stream.readLine());DAY.push_back(stream.readLine());
                    }
                }
                Fiiile.close();
                int inh = S_SRNO_oD.indexOf(Flight_choice);

                ui->SHEDULE_CHECK_13->setItem(0,0,new QTableWidgetItem(xy.at(81)));
                ui->SHEDULE_CHECK_13->setItem(1,0,new QTableWidgetItem("E6"));
                ui->Ticket_P->setText("E6");ui->CLASS_P->setText("PREMIUM ECONOMY");BOOKKING=Flight_choice+"E6";
                ui->SHEDULE_CHECK_13->setItem(2,0,new QTableWidgetItem(FRoOM_D.at(inh)));
                ui->SHEDULE_CHECK_13->setItem(3,0,new QTableWidgetItem(TO_oD.at(inh)));
                ui->SHEDULE_CHECK_13->setItem(4,0,new QTableWidgetItem(xy.at(85)));
                ui->stackedWidget->setCurrentIndex(23);
            }
            else
            {
                QMessageBox :: warning(this,"Ticket","NOT AVAILABLE!");
            }
    }
    ree.close();
}


void MainWindow::on_E_7_clicked()
{
    QVector<QString>xy;
    QVector<QString>FRoOM_D,TO_oD,S_DATE_oD,S_SRNO_oD,STRT_TIME_oD,END_TIME_oD,DAY;

    QFile ree(Flight_choice);
    if(ree.open(QIODevice::ReadOnly))
    {
            QTextStream stream(&ree);
            while ( stream.atEnd()==false)
            {
                xy.push_back(stream.readLine());
            }
            if(xy.at(31)=="nonbooked")
            {

                QFile Fiiile("FLIGHT.txt");
                if(Fiiile.open(QIODevice::ReadOnly))
                {
                    QTextStream stream(&Fiiile);
                    while ( stream.atEnd()==false)
                    {
                        S_SRNO_oD.push_back(stream.readLine());
                        FRoOM_D.push_back(stream.readLine());
                        TO_oD.push_back(stream.readLine());
                        STRT_TIME_oD.push_back(stream.readLine());
                        END_TIME_oD.push_back(stream.readLine());
                        S_DATE_oD.push_back(stream.readLine());DAY.push_back(stream.readLine());
                    }
                }
                Fiiile.close();
                int inh = S_SRNO_oD.indexOf(Flight_choice);

                ui->SHEDULE_CHECK_13->setItem(0,0,new QTableWidgetItem(xy.at(81)));
                ui->SHEDULE_CHECK_13->setItem(1,0,new QTableWidgetItem("E7"));
                ui->Ticket_P->setText("E7");ui->CLASS_P->setText("PREMIUM ECONOMY");BOOKKING=Flight_choice+"E7";
                ui->SHEDULE_CHECK_13->setItem(2,0,new QTableWidgetItem(FRoOM_D.at(inh)));
                ui->SHEDULE_CHECK_13->setItem(3,0,new QTableWidgetItem(TO_oD.at(inh)));
                ui->SHEDULE_CHECK_13->setItem(4,0,new QTableWidgetItem(xy.at(85)));
                ui->stackedWidget->setCurrentIndex(23);
            }
            else
            {
                QMessageBox :: warning(this,"Ticket","NOT AVAILABLE!");
            }
    }
    ree.close();
}


void MainWindow::on_E_8_clicked()
{
    QVector<QString>xy;
    QVector<QString>FRoOM_D,TO_oD,S_DATE_oD,S_SRNO_oD,STRT_TIME_oD,END_TIME_oD,DAY;

    QFile ree(Flight_choice);
    if(ree.open(QIODevice::ReadOnly))
    {
            QTextStream stream(&ree);
            while ( stream.atEnd()==false)
            {
                xy.push_back(stream.readLine());
            }
            if(xy.at(32)=="nonbooked")
            {

                QFile Fiiile("FLIGHT.txt");
                int i=0;
                if(Fiiile.open(QIODevice::ReadOnly))
                {
                    QTextStream stream(&Fiiile);
                    while ( stream.atEnd()==false)
                    {
                        S_SRNO_oD.push_back(stream.readLine());
                        FRoOM_D.push_back(stream.readLine());
                        TO_oD.push_back(stream.readLine());
                        STRT_TIME_oD.push_back(stream.readLine());
                        END_TIME_oD.push_back(stream.readLine());
                        S_DATE_oD.push_back(stream.readLine());DAY.push_back(stream.readLine());
                    }
                }
                Fiiile.close();
                int inh = S_SRNO_oD.indexOf(Flight_choice);

                ui->SHEDULE_CHECK_13->setItem(0,0,new QTableWidgetItem(xy.at(81)));
                ui->SHEDULE_CHECK_13->setItem(1,0,new QTableWidgetItem("E8"));
                ui->Ticket_P->setText("E8");ui->CLASS_P->setText("PREMIUM ECONOMY");BOOKKING=Flight_choice+"E8";
                ui->SHEDULE_CHECK_13->setItem(2,0,new QTableWidgetItem(FRoOM_D.at(inh)));
                ui->SHEDULE_CHECK_13->setItem(3,0,new QTableWidgetItem(TO_oD.at(inh)));
                ui->SHEDULE_CHECK_13->setItem(4,0,new QTableWidgetItem(xy.at(85)));
                ui->stackedWidget->setCurrentIndex(23);
            }
            else
            {
                QMessageBox :: warning(this,"Ticket","NOT AVAILABLE!");
            }
    }
    ree.close();
}


void MainWindow::on_F_1_clicked()
{
    QVector<QString>xy;
    QVector<QString>FRoOM_D,TO_oD,S_DATE_oD,S_SRNO_oD,STRT_TIME_oD,END_TIME_oD,DAY;

    QFile ree(Flight_choice);
    if(ree.open(QIODevice::ReadOnly))
    {
            QTextStream stream(&ree);
            while ( stream.atEnd()==false)
            {
                xy.push_back(stream.readLine());
            }
            if(xy.at(33)=="nonbooked")
            {

                QFile Fiiile("FLIGHT.txt");
                if(Fiiile.open(QIODevice::ReadOnly))
                {
                    QTextStream stream(&Fiiile);
                    while ( stream.atEnd()==false)
                    {
                        S_SRNO_oD.push_back(stream.readLine());
                        FRoOM_D.push_back(stream.readLine());
                        TO_oD.push_back(stream.readLine());
                        STRT_TIME_oD.push_back(stream.readLine());
                        END_TIME_oD.push_back(stream.readLine());
                        S_DATE_oD.push_back(stream.readLine());DAY.push_back(stream.readLine());
                    }
                }
                Fiiile.close();
                int inh = S_SRNO_oD.indexOf(Flight_choice);

                ui->SHEDULE_CHECK_13->setItem(0,0,new QTableWidgetItem(xy.at(81)));
                ui->SHEDULE_CHECK_13->setItem(1,0,new QTableWidgetItem("F1"));
                ui->Ticket_P->setText("F1");ui->CLASS_P->setText("PREMIUM ECONOMY");BOOKKING=Flight_choice+"F1";
                ui->SHEDULE_CHECK_13->setItem(2,0,new QTableWidgetItem(FRoOM_D.at(inh)));
                ui->SHEDULE_CHECK_13->setItem(3,0,new QTableWidgetItem(TO_oD.at(inh)));
                ui->SHEDULE_CHECK_13->setItem(4,0,new QTableWidgetItem(xy.at(85)));
                ui->stackedWidget->setCurrentIndex(23);
            }
            else
            {
                QMessageBox :: warning(this,"Ticket","NOT AVAILABLE!");
            }
    }
    ree.close();
}


void MainWindow::on_F_2_clicked()
{
    QVector<QString>xy;
    QVector<QString>FRoOM_D,TO_oD,S_DATE_oD,S_SRNO_oD,STRT_TIME_oD,END_TIME_oD,DAY;

    QFile ree(Flight_choice);
    if(ree.open(QIODevice::ReadOnly))
    {
            QTextStream stream(&ree);
            while ( stream.atEnd()==false)
            {
                xy.push_back(stream.readLine());
            }
            if(xy.at(34)=="nonbooked")
            {

                QFile Fiiile("FLIGHT.txt");
                int i=0;
                if(Fiiile.open(QIODevice::ReadOnly))
                {
                    QTextStream stream(&Fiiile);
                    while ( stream.atEnd()==false)
                    {
                        S_SRNO_oD.push_back(stream.readLine());
                        FRoOM_D.push_back(stream.readLine());
                        TO_oD.push_back(stream.readLine());
                        STRT_TIME_oD.push_back(stream.readLine());
                        END_TIME_oD.push_back(stream.readLine());
                        S_DATE_oD.push_back(stream.readLine());DAY.push_back(stream.readLine());
                    }
                }
                Fiiile.close();
                int inh = S_SRNO_oD.indexOf(Flight_choice);

                ui->SHEDULE_CHECK_13->setItem(0,0,new QTableWidgetItem(xy.at(81)));
                ui->SHEDULE_CHECK_13->setItem(1,0,new QTableWidgetItem("F2"));
                ui->Ticket_P->setText("F2");ui->CLASS_P->setText("PREMIUM ECONOMY");BOOKKING=Flight_choice+"F2";
                ui->SHEDULE_CHECK_13->setItem(2,0,new QTableWidgetItem(FRoOM_D.at(inh)));
                ui->SHEDULE_CHECK_13->setItem(3,0,new QTableWidgetItem(TO_oD.at(inh)));
                ui->SHEDULE_CHECK_13->setItem(4,0,new QTableWidgetItem(xy.at(85)));
                ui->stackedWidget->setCurrentIndex(23);
            }
            else
            {
                QMessageBox :: warning(this,"Ticket","NOT AVAILABLE!");
            }
    }
    ree.close();
}


void MainWindow::on_F_3_clicked()
{
    QVector<QString>xy;
    QVector<QString>FRoOM_D,TO_oD,S_DATE_oD,S_SRNO_oD,STRT_TIME_oD,END_TIME_oD,DAY;

    QFile ree(Flight_choice);
    if(ree.open(QIODevice::ReadOnly))
    {
            QTextStream stream(&ree);
            while ( stream.atEnd()==false)
            {
                xy.push_back(stream.readLine());
            }
            if(xy.at(35)=="nonbooked")
            {

                QFile Fiiile("FLIGHT.txt");
                int i=0;
                if(Fiiile.open(QIODevice::ReadOnly))
                {
                    QTextStream stream(&Fiiile);
                    while ( stream.atEnd()==false)
                    {
                        S_SRNO_oD.push_back(stream.readLine());
                        FRoOM_D.push_back(stream.readLine());
                        TO_oD.push_back(stream.readLine());
                        STRT_TIME_oD.push_back(stream.readLine());
                        END_TIME_oD.push_back(stream.readLine());
                        S_DATE_oD.push_back(stream.readLine());DAY.push_back(stream.readLine());
                    }
                }
                Fiiile.close();
                int inh = S_SRNO_oD.indexOf(Flight_choice);

                ui->SHEDULE_CHECK_13->setItem(0,0,new QTableWidgetItem(xy.at(81)));
                ui->SHEDULE_CHECK_13->setItem(1,0,new QTableWidgetItem("F3"));
                ui->Ticket_P->setText("F3");ui->CLASS_P->setText("PREMIUM ECONOMY");BOOKKING=Flight_choice+"F3";
                ui->SHEDULE_CHECK_13->setItem(2,0,new QTableWidgetItem(FRoOM_D.at(inh)));
                ui->SHEDULE_CHECK_13->setItem(3,0,new QTableWidgetItem(TO_oD.at(inh)));
                ui->SHEDULE_CHECK_13->setItem(4,0,new QTableWidgetItem(xy.at(85)));
                ui->stackedWidget->setCurrentIndex(23);
            }
            else
            {
                QMessageBox :: warning(this,"Ticket","NOT AVAILABLE!");
            }
    }
    ree.close();
}


void MainWindow::on_F_4_clicked()
{
    QVector<QString>xy;
    QVector<QString>FRoOM_D,TO_oD,S_DATE_oD,S_SRNO_oD,STRT_TIME_oD,END_TIME_oD,DAY;

    QFile ree(Flight_choice);
    if(ree.open(QIODevice::ReadOnly))
    {
            QTextStream stream(&ree);
            while ( stream.atEnd()==false)
            {
                xy.push_back(stream.readLine());
            }
            if(xy.at(36)=="nonbooked")
            {

                QFile Fiiile("FLIGHT.txt");
                int i=0;
                if(Fiiile.open(QIODevice::ReadOnly))
                {
                    QTextStream stream(&Fiiile);
                    while ( stream.atEnd()==false)
                    {
                        S_SRNO_oD.push_back(stream.readLine());
                        FRoOM_D.push_back(stream.readLine());
                        TO_oD.push_back(stream.readLine());
                        STRT_TIME_oD.push_back(stream.readLine());
                        END_TIME_oD.push_back(stream.readLine());
                        S_DATE_oD.push_back(stream.readLine());DAY.push_back(stream.readLine());
                    }
                }
                Fiiile.close();
                int inh = S_SRNO_oD.indexOf(Flight_choice);

                ui->SHEDULE_CHECK_13->setItem(0,0,new QTableWidgetItem(xy.at(81)));
                ui->SHEDULE_CHECK_13->setItem(1,0,new QTableWidgetItem("F4"));
                ui->Ticket_P->setText("F4");ui->CLASS_P->setText("PREMIUM ECONOMY");BOOKKING=Flight_choice+"F4";
                ui->SHEDULE_CHECK_13->setItem(2,0,new QTableWidgetItem(FRoOM_D.at(inh)));
                ui->SHEDULE_CHECK_13->setItem(3,0,new QTableWidgetItem(TO_oD.at(inh)));
                ui->SHEDULE_CHECK_13->setItem(4,0,new QTableWidgetItem(xy.at(85)));
                ui->stackedWidget->setCurrentIndex(23);
            }
            else
            {
                QMessageBox :: warning(this,"Ticket","NOT AVAILABLE!");
            }
    }
    ree.close();
}


void MainWindow::on_F_5_clicked()
{
    QVector<QString>xy;
    QVector<QString>FRoOM_D,TO_oD,S_DATE_oD,S_SRNO_oD,STRT_TIME_oD,END_TIME_oD,DAY;

    QFile ree(Flight_choice);
    if(ree.open(QIODevice::ReadOnly))
    {
            QTextStream stream(&ree);
            while ( stream.atEnd()==false)
            {
                xy.push_back(stream.readLine());
            }
            if(xy.at(37)=="nonbooked")
            {

                QFile Fiiile("FLIGHT.txt");
                if(Fiiile.open(QIODevice::ReadOnly))
                {
                    QTextStream stream(&Fiiile);
                    while ( stream.atEnd()==false)
                    {
                        S_SRNO_oD.push_back(stream.readLine());
                        FRoOM_D.push_back(stream.readLine());
                        TO_oD.push_back(stream.readLine());
                        STRT_TIME_oD.push_back(stream.readLine());
                        END_TIME_oD.push_back(stream.readLine());
                        S_DATE_oD.push_back(stream.readLine());DAY.push_back(stream.readLine());
                    }
                }
                Fiiile.close();
                int inh = S_SRNO_oD.indexOf(Flight_choice);

                ui->SHEDULE_CHECK_13->setItem(0,0,new QTableWidgetItem(xy.at(81)));
                ui->SHEDULE_CHECK_13->setItem(1,0,new QTableWidgetItem("F5"));
                ui->Ticket_P->setText("F5");ui->CLASS_P->setText("PREMIUM ECONOMY");BOOKKING=Flight_choice+"F5";
                ui->SHEDULE_CHECK_13->setItem(2,0,new QTableWidgetItem(FRoOM_D.at(inh)));
                ui->SHEDULE_CHECK_13->setItem(3,0,new QTableWidgetItem(TO_oD.at(inh)));
                ui->SHEDULE_CHECK_13->setItem(4,0,new QTableWidgetItem(xy.at(85)));
                ui->stackedWidget->setCurrentIndex(23);
            }
            else
            {
                QMessageBox :: warning(this,"Ticket","NOT AVAILABLE!");
            }
    }
    ree.close();
}


void MainWindow::on_F_6_clicked()
{
    QVector<QString>xy;
    QVector<QString>FRoOM_D,TO_oD,S_DATE_oD,S_SRNO_oD,STRT_TIME_oD,END_TIME_oD,DAY;

    QFile ree(Flight_choice);
    if(ree.open(QIODevice::ReadOnly))
    {
            QTextStream stream(&ree);
            while ( stream.atEnd()==false)
            {
                xy.push_back(stream.readLine());
            }
            if(xy.at(38)=="nonbooked")
            {

                QFile Fiiile("FLIGHT.txt");
                if(Fiiile.open(QIODevice::ReadOnly))
                {
                    QTextStream stream(&Fiiile);
                    while ( stream.atEnd()==false)
                    {
                        S_SRNO_oD.push_back(stream.readLine());
                        FRoOM_D.push_back(stream.readLine());
                        TO_oD.push_back(stream.readLine());
                        STRT_TIME_oD.push_back(stream.readLine());
                        END_TIME_oD.push_back(stream.readLine());
                        S_DATE_oD.push_back(stream.readLine());DAY.push_back(stream.readLine());
                    }
                }
                Fiiile.close();
                int inh = S_SRNO_oD.indexOf(Flight_choice);

                ui->SHEDULE_CHECK_13->setItem(0,0,new QTableWidgetItem(xy.at(81)));
                ui->SHEDULE_CHECK_13->setItem(1,0,new QTableWidgetItem("F6"));
                ui->Ticket_P->setText("F6");ui->CLASS_P->setText("PREMIUM ECONOMY");BOOKKING=Flight_choice+"F6";
                ui->SHEDULE_CHECK_13->setItem(2,0,new QTableWidgetItem(FRoOM_D.at(inh)));
                ui->SHEDULE_CHECK_13->setItem(3,0,new QTableWidgetItem(TO_oD.at(inh)));
                ui->SHEDULE_CHECK_13->setItem(4,0,new QTableWidgetItem(xy.at(85)));
                ui->stackedWidget->setCurrentIndex(23);
            }
            else
            {
                QMessageBox :: warning(this,"Ticket","NOT AVAILABLE!");
            }
    }
    ree.close();
}


void MainWindow::on_F_7_clicked()
{
    QVector<QString>xy;
    QVector<QString>FRoOM_D,TO_oD,S_DATE_oD,S_SRNO_oD,STRT_TIME_oD,END_TIME_oD,DAY;

    QFile ree(Flight_choice);
    if(ree.open(QIODevice::ReadOnly))
    {
            QTextStream stream(&ree);
            while ( stream.atEnd()==false)
            {
                xy.push_back(stream.readLine());
            }
            if(xy.at(39)=="nonbooked")
            {

                QFile Fiiile("FLIGHT.txt");
                int i=0;
                if(Fiiile.open(QIODevice::ReadOnly))
                {
                    QTextStream stream(&Fiiile);
                    while ( stream.atEnd()==false)
                    {
                        S_SRNO_oD.push_back(stream.readLine());
                        FRoOM_D.push_back(stream.readLine());
                        TO_oD.push_back(stream.readLine());
                        STRT_TIME_oD.push_back(stream.readLine());
                        END_TIME_oD.push_back(stream.readLine());
                        S_DATE_oD.push_back(stream.readLine());DAY.push_back(stream.readLine());
                    }
                }
                Fiiile.close();
                int inh = S_SRNO_oD.indexOf(Flight_choice);

                ui->SHEDULE_CHECK_13->setItem(0,0,new QTableWidgetItem(xy.at(81)));
                ui->SHEDULE_CHECK_13->setItem(1,0,new QTableWidgetItem("F7"));
                ui->Ticket_P->setText("F7");ui->CLASS_P->setText("PREMIUM ECONOMY");BOOKKING=Flight_choice+"F7";
                ui->SHEDULE_CHECK_13->setItem(2,0,new QTableWidgetItem(FRoOM_D.at(inh)));
                ui->SHEDULE_CHECK_13->setItem(3,0,new QTableWidgetItem(TO_oD.at(inh)));
                ui->SHEDULE_CHECK_13->setItem(4,0,new QTableWidgetItem(xy.at(85)));
                ui->stackedWidget->setCurrentIndex(23);
            }
            else
            {
                QMessageBox :: warning(this,"Ticket","NOT AVAILABLE!");
            }
    }
    ree.close();
}


void MainWindow::on_F_8_clicked()
{
    QVector<QString>xy;
    QVector<QString>FRoOM_D,TO_oD,S_DATE_oD,S_SRNO_oD,STRT_TIME_oD,END_TIME_oD,DAY;

    QFile ree(Flight_choice);
    if(ree.open(QIODevice::ReadOnly))
    {
            QTextStream stream(&ree);
            while ( stream.atEnd()==false)
            {
                xy.push_back(stream.readLine());
            }
            if(xy.at(40)=="nonbooked")
            {

                QFile Fiiile("FLIGHT.txt");
                int i=0;
                if(Fiiile.open(QIODevice::ReadOnly))
                {
                    QTextStream stream(&Fiiile);
                    while ( stream.atEnd()==false)
                    {
                        S_SRNO_oD.push_back(stream.readLine());
                        FRoOM_D.push_back(stream.readLine());
                        TO_oD.push_back(stream.readLine());
                        STRT_TIME_oD.push_back(stream.readLine());
                        END_TIME_oD.push_back(stream.readLine());
                        S_DATE_oD.push_back(stream.readLine());DAY.push_back(stream.readLine());
                    }
                }
                Fiiile.close();
                int inh = S_SRNO_oD.indexOf(Flight_choice);

                ui->SHEDULE_CHECK_13->setItem(0,0,new QTableWidgetItem(xy.at(81)));
                ui->SHEDULE_CHECK_13->setItem(1,0,new QTableWidgetItem("F8"));
                ui->Ticket_P->setText("F8");ui->CLASS_P->setText("PREMIUM ECONOMY");BOOKKING=Flight_choice+"F8";
                ui->SHEDULE_CHECK_13->setItem(2,0,new QTableWidgetItem(FRoOM_D.at(inh)));
                ui->SHEDULE_CHECK_13->setItem(3,0,new QTableWidgetItem(TO_oD.at(inh)));
                ui->SHEDULE_CHECK_13->setItem(4,0,new QTableWidgetItem(xy.at(85)));
                ui->stackedWidget->setCurrentIndex(23);
            }
            else
            {
                QMessageBox :: warning(this,"Ticket","NOT AVAILABLE!");
            }
    }
    ree.close();
}


void MainWindow::on_G_1_clicked()
{
    QVector<QString>xy;
    QVector<QString>FRoOM_D,TO_oD,S_DATE_oD,S_SRNO_oD,STRT_TIME_oD,END_TIME_oD,DAY;

    QFile ree(Flight_choice);
    if(ree.open(QIODevice::ReadOnly))
    {
            QTextStream stream(&ree);
            while ( stream.atEnd()==false)
            {
                xy.push_back(stream.readLine());
            }
            if(xy.at(41)=="nonbooked")
            {

                QFile Fiiile("FLIGHT.txt");
                int i=0;
                if(Fiiile.open(QIODevice::ReadOnly))
                {
                    QTextStream stream(&Fiiile);
                    while ( stream.atEnd()==false)
                    {
                        S_SRNO_oD.push_back(stream.readLine());
                        FRoOM_D.push_back(stream.readLine());
                        TO_oD.push_back(stream.readLine());
                        STRT_TIME_oD.push_back(stream.readLine());
                        END_TIME_oD.push_back(stream.readLine());
                        S_DATE_oD.push_back(stream.readLine());DAY.push_back(stream.readLine());
                    }
                }
                Fiiile.close();
                int inh = S_SRNO_oD.indexOf(Flight_choice);

                ui->SHEDULE_CHECK_13->setItem(0,0,new QTableWidgetItem(xy.at(81)));
                ui->SHEDULE_CHECK_13->setItem(1,0,new QTableWidgetItem("G1"));
                ui->Ticket_P->setText("G1");ui->CLASS_P->setText("PREMIUM ECONOMY");BOOKKING=Flight_choice+"G1";
                ui->SHEDULE_CHECK_13->setItem(2,0,new QTableWidgetItem(FRoOM_D.at(inh)));
                ui->SHEDULE_CHECK_13->setItem(3,0,new QTableWidgetItem(TO_oD.at(inh)));
                ui->SHEDULE_CHECK_13->setItem(4,0,new QTableWidgetItem(xy.at(85)));
                ui->stackedWidget->setCurrentIndex(23);
            }
            else
            {
                QMessageBox :: warning(this,"Ticket","NOT AVAILABLE!");
            }
    }
    ree.close();

}


void MainWindow::on_G_2_clicked()
{
    QVector<QString>xy;
    QVector<QString>FRoOM_D,TO_oD,S_DATE_oD,S_SRNO_oD,STRT_TIME_oD,END_TIME_oD,DAY;

    QFile ree(Flight_choice);
    if(ree.open(QIODevice::ReadOnly))
    {
            QTextStream stream(&ree);
            while ( stream.atEnd()==false)
            {
                xy.push_back(stream.readLine());
            }
            if(xy.at(42)=="nonbooked")
            {

                QFile Fiiile("FLIGHT.txt");
                int i=0;
                if(Fiiile.open(QIODevice::ReadOnly))
                {
                    QTextStream stream(&Fiiile);
                    while ( stream.atEnd()==false)
                    {
                        S_SRNO_oD.push_back(stream.readLine());
                        FRoOM_D.push_back(stream.readLine());
                        TO_oD.push_back(stream.readLine());
                        STRT_TIME_oD.push_back(stream.readLine());
                        END_TIME_oD.push_back(stream.readLine());
                        S_DATE_oD.push_back(stream.readLine());DAY.push_back(stream.readLine());
                    }
                }
                Fiiile.close();
                int inh = S_SRNO_oD.indexOf(Flight_choice);

                ui->SHEDULE_CHECK_13->setItem(0,0,new QTableWidgetItem(xy.at(81)));
                ui->SHEDULE_CHECK_13->setItem(1,0,new QTableWidgetItem("G2"));
                ui->Ticket_P->setText("G2");ui->CLASS_P->setText("PREMIUM ECONOMY");BOOKKING=Flight_choice+"G2";
                ui->SHEDULE_CHECK_13->setItem(2,0,new QTableWidgetItem(FRoOM_D.at(inh)));
                ui->SHEDULE_CHECK_13->setItem(3,0,new QTableWidgetItem(TO_oD.at(inh)));
                ui->SHEDULE_CHECK_13->setItem(4,0,new QTableWidgetItem(xy.at(85)));
                ui->stackedWidget->setCurrentIndex(23);
            }
            else
            {
                QMessageBox :: warning(this,"Ticket","NOT AVAILABLE!");
            }
    }
    ree.close();
}


void MainWindow::on_G_3_clicked()
{
    QVector<QString>xy;
    QVector<QString>FRoOM_D,TO_oD,S_DATE_oD,S_SRNO_oD,STRT_TIME_oD,END_TIME_oD,DAY;

    QFile ree(Flight_choice);
    if(ree.open(QIODevice::ReadOnly))
    {
            QTextStream stream(&ree);
            while ( stream.atEnd()==false)
            {
                xy.push_back(stream.readLine());
            }
            if(xy.at(43)=="nonbooked")
            {

                QFile Fiiile("FLIGHT.txt");
                int i=0;
                if(Fiiile.open(QIODevice::ReadOnly))
                {
                    QTextStream stream(&Fiiile);
                    while ( stream.atEnd()==false)
                    {
                        S_SRNO_oD.push_back(stream.readLine());
                        FRoOM_D.push_back(stream.readLine());
                        TO_oD.push_back(stream.readLine());
                        STRT_TIME_oD.push_back(stream.readLine());
                        END_TIME_oD.push_back(stream.readLine());
                        S_DATE_oD.push_back(stream.readLine());DAY.push_back(stream.readLine());
                    }
                }
                Fiiile.close();
                int inh = S_SRNO_oD.indexOf(Flight_choice);

                ui->SHEDULE_CHECK_13->setItem(0,0,new QTableWidgetItem(xy.at(81)));
                ui->SHEDULE_CHECK_13->setItem(1,0,new QTableWidgetItem("G3"));
                ui->Ticket_P->setText("G3");ui->CLASS_P->setText("PREMIUM ECONOMY");BOOKKING=Flight_choice+"G3";
                ui->SHEDULE_CHECK_13->setItem(2,0,new QTableWidgetItem(FRoOM_D.at(inh)));
                ui->SHEDULE_CHECK_13->setItem(3,0,new QTableWidgetItem(TO_oD.at(inh)));
                ui->SHEDULE_CHECK_13->setItem(4,0,new QTableWidgetItem(xy.at(85)));
                ui->stackedWidget->setCurrentIndex(23);
            }
            else
            {
                QMessageBox :: warning(this,"Ticket","NOT AVAILABLE!");
            }
    }
    ree.close();
}


void MainWindow::on_G_4_clicked()
{
    QVector<QString>xy;
    QVector<QString>FRoOM_D,TO_oD,S_DATE_oD,S_SRNO_oD,STRT_TIME_oD,END_TIME_oD,DAY;

    QFile ree(Flight_choice);
    if(ree.open(QIODevice::ReadOnly))
    {
            QTextStream stream(&ree);
            while ( stream.atEnd()==false)
            {
                xy.push_back(stream.readLine());
            }
            if(xy.at(44)=="nonbooked")
            {

                QFile Fiiile("FLIGHT.txt");
                int i=0;
                if(Fiiile.open(QIODevice::ReadOnly))
                {
                    QTextStream stream(&Fiiile);
                    while ( stream.atEnd()==false)
                    {
                        S_SRNO_oD.push_back(stream.readLine());
                        FRoOM_D.push_back(stream.readLine());
                        TO_oD.push_back(stream.readLine());
                        STRT_TIME_oD.push_back(stream.readLine());
                        END_TIME_oD.push_back(stream.readLine());
                        S_DATE_oD.push_back(stream.readLine());DAY.push_back(stream.readLine());
                    }
                }
                Fiiile.close();
                int inh = S_SRNO_oD.indexOf(Flight_choice);

                ui->SHEDULE_CHECK_13->setItem(0,0,new QTableWidgetItem(xy.at(81)));
                ui->SHEDULE_CHECK_13->setItem(1,0,new QTableWidgetItem("G4"));
                ui->Ticket_P->setText("G4");ui->CLASS_P->setText("PREMIUM ECONOMY");BOOKKING=Flight_choice+"G4";
                ui->SHEDULE_CHECK_13->setItem(2,0,new QTableWidgetItem(FRoOM_D.at(inh)));
                ui->SHEDULE_CHECK_13->setItem(3,0,new QTableWidgetItem(TO_oD.at(inh)));
                ui->SHEDULE_CHECK_13->setItem(4,0,new QTableWidgetItem(xy.at(85)));
                ui->stackedWidget->setCurrentIndex(23);
            }
            else
            {
                QMessageBox :: warning(this,"Ticket","NOT AVAILABLE!");
            }
    }
    ree.close();
}


void MainWindow::on_G_5_clicked()
{
    QVector<QString>xy;
    QVector<QString>FRoOM_D,TO_oD,S_DATE_oD,S_SRNO_oD,STRT_TIME_oD,END_TIME_oD,DAY;

    QFile ree(Flight_choice);
    if(ree.open(QIODevice::ReadOnly))
    {
            QTextStream stream(&ree);
            while ( stream.atEnd()==false)
            {
                xy.push_back(stream.readLine());
            }
            if(xy.at(45)=="nonbooked")
            {

                QFile Fiiile("FLIGHT.txt");
                if(Fiiile.open(QIODevice::ReadOnly))
                {
                    QTextStream stream(&Fiiile);
                    while ( stream.atEnd()==false)
                    {
                        S_SRNO_oD.push_back(stream.readLine());
                        FRoOM_D.push_back(stream.readLine());
                        TO_oD.push_back(stream.readLine());
                        STRT_TIME_oD.push_back(stream.readLine());
                        END_TIME_oD.push_back(stream.readLine());
                        S_DATE_oD.push_back(stream.readLine());DAY.push_back(stream.readLine());
                    }
                }
                Fiiile.close();
                int inh = S_SRNO_oD.indexOf(Flight_choice);

                ui->SHEDULE_CHECK_13->setItem(0,0,new QTableWidgetItem(xy.at(81)));
                ui->SHEDULE_CHECK_13->setItem(1,0,new QTableWidgetItem("G5"));
                ui->Ticket_P->setText("G5");ui->CLASS_P->setText("PREMIUM ECONOMY");BOOKKING=Flight_choice+"G5";
                ui->SHEDULE_CHECK_13->setItem(2,0,new QTableWidgetItem(FRoOM_D.at(inh)));
                ui->SHEDULE_CHECK_13->setItem(3,0,new QTableWidgetItem(TO_oD.at(inh)));
                ui->SHEDULE_CHECK_13->setItem(4,0,new QTableWidgetItem(xy.at(85)));
                ui->stackedWidget->setCurrentIndex(23);
            }
            else
            {
                QMessageBox :: warning(this,"Ticket","NOT AVAILABLE!");
            }
    }
    ree.close();
}


void MainWindow::on_G_6_clicked()
{
    QVector<QString>xy;
    QVector<QString>FRoOM_D,TO_oD,S_DATE_oD,S_SRNO_oD,STRT_TIME_oD,END_TIME_oD,DAY;

    QFile ree(Flight_choice);
    if(ree.open(QIODevice::ReadOnly))
    {
            QTextStream stream(&ree);
            while ( stream.atEnd()==false)
            {
                xy.push_back(stream.readLine());
            }
            if(xy.at(46)=="nonbooked")
            {

                QFile Fiiile("FLIGHT.txt");
                if(Fiiile.open(QIODevice::ReadOnly))
                {
                    QTextStream stream(&Fiiile);
                    while ( stream.atEnd()==false)
                    {
                        S_SRNO_oD.push_back(stream.readLine());
                        FRoOM_D.push_back(stream.readLine());
                        TO_oD.push_back(stream.readLine());
                        STRT_TIME_oD.push_back(stream.readLine());
                        END_TIME_oD.push_back(stream.readLine());
                        S_DATE_oD.push_back(stream.readLine());DAY.push_back(stream.readLine());
                    }
                }
                Fiiile.close();
                int inh = S_SRNO_oD.indexOf(Flight_choice);

                ui->SHEDULE_CHECK_13->setItem(0,0,new QTableWidgetItem(xy.at(81)));
                ui->SHEDULE_CHECK_13->setItem(1,0,new QTableWidgetItem("G6"));
                ui->Ticket_P->setText("G6");ui->CLASS_P->setText("PREMIUM ECONOMY");BOOKKING=Flight_choice+"G6";
                ui->SHEDULE_CHECK_13->setItem(2,0,new QTableWidgetItem(FRoOM_D.at(inh)));
                ui->SHEDULE_CHECK_13->setItem(3,0,new QTableWidgetItem(TO_oD.at(inh)));
                ui->SHEDULE_CHECK_13->setItem(4,0,new QTableWidgetItem(xy.at(85)));
                ui->stackedWidget->setCurrentIndex(23);
            }
            else
            {
                QMessageBox :: warning(this,"Ticket","NOT AVAILABLE!");
            }
    }
    ree.close();
}


void MainWindow::on_G_7_clicked()
{
    QVector<QString>xy;
    QVector<QString>FRoOM_D,TO_oD,S_DATE_oD,S_SRNO_oD,STRT_TIME_oD,END_TIME_oD,DAY;

    QFile ree(Flight_choice);
    if(ree.open(QIODevice::ReadOnly))
    {
            QTextStream stream(&ree);
            while ( stream.atEnd()==false)
            {
                xy.push_back(stream.readLine());
            }
            if(xy.at(47)=="nonbooked")
            {

                QFile Fiiile("FLIGHT.txt");
                int i=0;
                if(Fiiile.open(QIODevice::ReadOnly))
                {
                    QTextStream stream(&Fiiile);
                    while ( stream.atEnd()==false)
                    {
                        S_SRNO_oD.push_back(stream.readLine());
                        FRoOM_D.push_back(stream.readLine());
                        TO_oD.push_back(stream.readLine());
                        STRT_TIME_oD.push_back(stream.readLine());
                        END_TIME_oD.push_back(stream.readLine());
                        S_DATE_oD.push_back(stream.readLine());DAY.push_back(stream.readLine());
                    }
                }
                Fiiile.close();
                int inh = S_SRNO_oD.indexOf(Flight_choice);

                ui->SHEDULE_CHECK_13->setItem(0,0,new QTableWidgetItem(xy.at(81)));
                ui->SHEDULE_CHECK_13->setItem(1,0,new QTableWidgetItem("G7"));
                ui->Ticket_P->setText("G7");ui->CLASS_P->setText("PREMIUM ECONOMY");BOOKKING=Flight_choice+"G7";
                ui->SHEDULE_CHECK_13->setItem(2,0,new QTableWidgetItem(FRoOM_D.at(inh)));
                ui->SHEDULE_CHECK_13->setItem(3,0,new QTableWidgetItem(TO_oD.at(inh)));
                ui->SHEDULE_CHECK_13->setItem(4,0,new QTableWidgetItem(xy.at(85)));
                ui->stackedWidget->setCurrentIndex(23);
            }
            else
            {
                QMessageBox :: warning(this,"Ticket","NOT AVAILABLE!");
            }
    }
    ree.close();
}


void MainWindow::on_G_8_clicked()
{
    QVector<QString>xy;
    QVector<QString>FRoOM_D,TO_oD,S_DATE_oD,S_SRNO_oD,STRT_TIME_oD,END_TIME_oD,DAY;

    QFile ree(Flight_choice);
    if(ree.open(QIODevice::ReadOnly))
    {
            QTextStream stream(&ree);
            while ( stream.atEnd()==false)
            {
                xy.push_back(stream.readLine());
            }
            if(xy.at(48)=="nonbooked")
            {

                QFile Fiiile("FLIGHT.txt");
                if(Fiiile.open(QIODevice::ReadOnly))
                {
                    QTextStream stream(&Fiiile);
                    while ( stream.atEnd()==false)
                    {
                        S_SRNO_oD.push_back(stream.readLine());
                        FRoOM_D.push_back(stream.readLine());
                        TO_oD.push_back(stream.readLine());
                        STRT_TIME_oD.push_back(stream.readLine());
                        END_TIME_oD.push_back(stream.readLine());
                        S_DATE_oD.push_back(stream.readLine());DAY.push_back(stream.readLine());
                    }
                }
                Fiiile.close();
                int inh = S_SRNO_oD.indexOf(Flight_choice);

                ui->SHEDULE_CHECK_13->setItem(0,0,new QTableWidgetItem(xy.at(81)));
                ui->SHEDULE_CHECK_13->setItem(1,0,new QTableWidgetItem("G8"));
                ui->Ticket_P->setText("G8");ui->CLASS_P->setText("PREMIUM ECONOMY");BOOKKING=Flight_choice+"G8";
                ui->SHEDULE_CHECK_13->setItem(2,0,new QTableWidgetItem(FRoOM_D.at(inh)));
                ui->SHEDULE_CHECK_13->setItem(3,0,new QTableWidgetItem(TO_oD.at(inh)));
                ui->SHEDULE_CHECK_13->setItem(4,0,new QTableWidgetItem(xy.at(85)));
                ui->stackedWidget->setCurrentIndex(23);
            }
            else
            {
                QMessageBox :: warning(this,"Ticket","NOT AVAILABLE!");
            }
    }
    ree.close();
}


void MainWindow::on_H_1_clicked()
{
    QVector<QString>xy;
    QVector<QString>FRoOM_D,TO_oD,S_DATE_oD,S_SRNO_oD,STRT_TIME_oD,END_TIME_oD,DAY;

    QFile ree(Flight_choice);
    if(ree.open(QIODevice::ReadOnly))
    {
            QTextStream stream(&ree);
            while ( stream.atEnd()==false)
            {
                xy.push_back(stream.readLine());
            }
            if(xy.at(49)=="nonbooked")
            {

                QFile Fiiile("FLIGHT.txt");
                int i=0;
                if(Fiiile.open(QIODevice::ReadOnly))
                {
                    QTextStream stream(&Fiiile);
                    while ( stream.atEnd()==false)
                    {
                        S_SRNO_oD.push_back(stream.readLine());
                        FRoOM_D.push_back(stream.readLine());
                        TO_oD.push_back(stream.readLine());
                        STRT_TIME_oD.push_back(stream.readLine());
                        END_TIME_oD.push_back(stream.readLine());
                        S_DATE_oD.push_back(stream.readLine());DAY.push_back(stream.readLine());
                    }
                }
                Fiiile.close();
                int inh = S_SRNO_oD.indexOf(Flight_choice);

                ui->SHEDULE_CHECK_13->setItem(0,0,new QTableWidgetItem(xy.at(81)));
                ui->SHEDULE_CHECK_13->setItem(1,0,new QTableWidgetItem("H1"));
                ui->Ticket_P->setText("H1");ui->CLASS_P->setText("ECONOMY");BOOKKING=Flight_choice+"H1";
                ui->SHEDULE_CHECK_13->setItem(2,0,new QTableWidgetItem(FRoOM_D.at(inh)));
                ui->SHEDULE_CHECK_13->setItem(3,0,new QTableWidgetItem(TO_oD.at(inh)));
                ui->SHEDULE_CHECK_13->setItem(4,0,new QTableWidgetItem(xy.at(86)));
                ui->stackedWidget->setCurrentIndex(23);
            }
            else
            {
                QMessageBox :: warning(this,"Ticket","NOT AVAILABLE!");
            }
    }
    ree.close();
}


void MainWindow::on_H_2_clicked()
{
    QVector<QString>xy;
    QVector<QString>FRoOM_D,TO_oD,S_DATE_oD,S_SRNO_oD,STRT_TIME_oD,END_TIME_oD,DAY;

    QFile ree(Flight_choice);
    if(ree.open(QIODevice::ReadOnly))
    {
            QTextStream stream(&ree);
            while ( stream.atEnd()==false)
            {
                xy.push_back(stream.readLine());
            }
            if(xy.at(50)=="nonbooked")
            {

                QFile Fiiile("FLIGHT.txt");
                int i=0;
                if(Fiiile.open(QIODevice::ReadOnly))
                {
                    QTextStream stream(&Fiiile);
                    while ( stream.atEnd()==false)
                    {
                        S_SRNO_oD.push_back(stream.readLine());
                        FRoOM_D.push_back(stream.readLine());
                        TO_oD.push_back(stream.readLine());
                        STRT_TIME_oD.push_back(stream.readLine());
                        END_TIME_oD.push_back(stream.readLine());
                        S_DATE_oD.push_back(stream.readLine());DAY.push_back(stream.readLine());
                    }
                }
                Fiiile.close();
                int inh = S_SRNO_oD.indexOf(Flight_choice);

                ui->SHEDULE_CHECK_13->setItem(0,0,new QTableWidgetItem(xy.at(81)));
                ui->SHEDULE_CHECK_13->setItem(1,0,new QTableWidgetItem("H2"));
                ui->Ticket_P->setText("H2");ui->CLASS_P->setText("ECONOMY");BOOKKING=Flight_choice+"H2";
                ui->SHEDULE_CHECK_13->setItem(2,0,new QTableWidgetItem(FRoOM_D.at(inh)));
                ui->SHEDULE_CHECK_13->setItem(3,0,new QTableWidgetItem(TO_oD.at(inh)));
                ui->SHEDULE_CHECK_13->setItem(4,0,new QTableWidgetItem(xy.at(86)));
                ui->stackedWidget->setCurrentIndex(23);
            }
            else
            {
                QMessageBox :: warning(this,"Ticket","NOT AVAILABLE!");
            }
    }
    ree.close();
}


void MainWindow::on_H_3_clicked()
{
    QVector<QString>xy;
    QVector<QString>FRoOM_D,TO_oD,S_DATE_oD,S_SRNO_oD,STRT_TIME_oD,END_TIME_oD,DAY;

    QFile ree(Flight_choice);
    if(ree.open(QIODevice::ReadOnly))
    {
            QTextStream stream(&ree);
            while ( stream.atEnd()==false)
            {
                xy.push_back(stream.readLine());
            }
            if(xy.at(51)=="nonbooked")
            {

                QFile Fiiile("FLIGHT.txt");
                int i=0;
                if(Fiiile.open(QIODevice::ReadOnly))
                {
                    QTextStream stream(&Fiiile);
                    while ( stream.atEnd()==false)
                    {
                        S_SRNO_oD.push_back(stream.readLine());
                        FRoOM_D.push_back(stream.readLine());
                        TO_oD.push_back(stream.readLine());
                        STRT_TIME_oD.push_back(stream.readLine());
                        END_TIME_oD.push_back(stream.readLine());
                        S_DATE_oD.push_back(stream.readLine());DAY.push_back(stream.readLine());
                    }
                }
                Fiiile.close();
                int inh = S_SRNO_oD.indexOf(Flight_choice);

                ui->SHEDULE_CHECK_13->setItem(0,0,new QTableWidgetItem(xy.at(81)));
                ui->SHEDULE_CHECK_13->setItem(1,0,new QTableWidgetItem("H3"));
                ui->Ticket_P->setText("H3");ui->CLASS_P->setText("ECONOMY");BOOKKING=Flight_choice+"H3";
                ui->SHEDULE_CHECK_13->setItem(2,0,new QTableWidgetItem(FRoOM_D.at(inh)));
                ui->SHEDULE_CHECK_13->setItem(3,0,new QTableWidgetItem(TO_oD.at(inh)));
                ui->SHEDULE_CHECK_13->setItem(4,0,new QTableWidgetItem(xy.at(86)));
                ui->stackedWidget->setCurrentIndex(23);
            }
            else
            {
                QMessageBox :: warning(this,"Ticket","NOT AVAILABLE!");
            }
    }
    ree.close();
}


void MainWindow::on_H_4_clicked()
{
    QVector<QString>xy;
    QVector<QString>FRoOM_D,TO_oD,S_DATE_oD,S_SRNO_oD,STRT_TIME_oD,END_TIME_oD,DAY;

    QFile ree(Flight_choice);
    if(ree.open(QIODevice::ReadOnly))
    {
            QTextStream stream(&ree);
            while ( stream.atEnd()==false)
            {
                xy.push_back(stream.readLine());
            }
            if(xy.at(52)=="nonbooked")
            {

                QFile Fiiile("FLIGHT.txt");
                if(Fiiile.open(QIODevice::ReadOnly))
                {
                    QTextStream stream(&Fiiile);
                    while ( stream.atEnd()==false)
                    {
                        S_SRNO_oD.push_back(stream.readLine());
                        FRoOM_D.push_back(stream.readLine());
                        TO_oD.push_back(stream.readLine());
                        STRT_TIME_oD.push_back(stream.readLine());
                        END_TIME_oD.push_back(stream.readLine());
                        S_DATE_oD.push_back(stream.readLine());DAY.push_back(stream.readLine());
                    }
                }
                Fiiile.close();
                int inh = S_SRNO_oD.indexOf(Flight_choice);

                ui->SHEDULE_CHECK_13->setItem(0,0,new QTableWidgetItem(xy.at(81)));
                ui->SHEDULE_CHECK_13->setItem(1,0,new QTableWidgetItem("H4"));
                ui->Ticket_P->setText("H4");ui->CLASS_P->setText("ECONOMY");BOOKKING=Flight_choice+"H4";
                ui->SHEDULE_CHECK_13->setItem(2,0,new QTableWidgetItem(FRoOM_D.at(inh)));
                ui->SHEDULE_CHECK_13->setItem(3,0,new QTableWidgetItem(TO_oD.at(inh)));
                ui->SHEDULE_CHECK_13->setItem(4,0,new QTableWidgetItem(xy.at(86)));
                ui->stackedWidget->setCurrentIndex(23);
            }
            else
            {
                QMessageBox :: warning(this,"Ticket","NOT AVAILABLE!");
            }
    }
    ree.close();
}


void MainWindow::on_H_5_clicked()
{
    QVector<QString>xy;
    QVector<QString>FRoOM_D,TO_oD,S_DATE_oD,S_SRNO_oD,STRT_TIME_oD,END_TIME_oD,DAY;

    QFile ree(Flight_choice);
    if(ree.open(QIODevice::ReadOnly))
    {
            QTextStream stream(&ree);
            while ( stream.atEnd()==false)
            {
                xy.push_back(stream.readLine());
            }
            if(xy.at(53)=="nonbooked")
            {

                QFile Fiiile("FLIGHT.txt");
                if(Fiiile.open(QIODevice::ReadOnly))
                {
                    QTextStream stream(&Fiiile);
                    while ( stream.atEnd()==false)
                    {
                        S_SRNO_oD.push_back(stream.readLine());
                        FRoOM_D.push_back(stream.readLine());
                        TO_oD.push_back(stream.readLine());
                        STRT_TIME_oD.push_back(stream.readLine());
                        END_TIME_oD.push_back(stream.readLine());
                        S_DATE_oD.push_back(stream.readLine());DAY.push_back(stream.readLine());
                    }
                }
                Fiiile.close();
                int inh = S_SRNO_oD.indexOf(Flight_choice);

                ui->SHEDULE_CHECK_13->setItem(0,0,new QTableWidgetItem(xy.at(81)));
                ui->SHEDULE_CHECK_13->setItem(1,0,new QTableWidgetItem("H5"));
                ui->Ticket_P->setText("H5");ui->CLASS_P->setText("ECONOMY");BOOKKING=Flight_choice+"H5";
                ui->SHEDULE_CHECK_13->setItem(2,0,new QTableWidgetItem(FRoOM_D.at(inh)));
                ui->SHEDULE_CHECK_13->setItem(3,0,new QTableWidgetItem(TO_oD.at(inh)));
                ui->SHEDULE_CHECK_13->setItem(4,0,new QTableWidgetItem(xy.at(86)));
                ui->stackedWidget->setCurrentIndex(23);
            }
            else
            {
                QMessageBox :: warning(this,"Ticket","NOT AVAILABLE!");
            }
    }
    ree.close();
}


void MainWindow::on_H_6_clicked()
{
    QVector<QString>xy;
    QVector<QString>FRoOM_D,TO_oD,S_DATE_oD,S_SRNO_oD,STRT_TIME_oD,END_TIME_oD,DAY;

    QFile ree(Flight_choice);
    if(ree.open(QIODevice::ReadOnly))
    {
            QTextStream stream(&ree);
            while ( stream.atEnd()==false)
            {
                xy.push_back(stream.readLine());
            }
            if(xy.at(54)=="nonbooked")
            {

                QFile Fiiile("FLIGHT.txt");
                if(Fiiile.open(QIODevice::ReadOnly))
                {
                    QTextStream stream(&Fiiile);
                    while ( stream.atEnd()==false)
                    {
                        S_SRNO_oD.push_back(stream.readLine());
                        FRoOM_D.push_back(stream.readLine());
                        TO_oD.push_back(stream.readLine());
                        STRT_TIME_oD.push_back(stream.readLine());
                        END_TIME_oD.push_back(stream.readLine());
                        S_DATE_oD.push_back(stream.readLine());DAY.push_back(stream.readLine());
                    }
                }
                Fiiile.close();
                int inh = S_SRNO_oD.indexOf(Flight_choice);

                ui->SHEDULE_CHECK_13->setItem(0,0,new QTableWidgetItem(xy.at(81)));
                ui->SHEDULE_CHECK_13->setItem(1,0,new QTableWidgetItem("H6"));
                ui->Ticket_P->setText("H6");ui->CLASS_P->setText("ECONOMY");BOOKKING=Flight_choice+"H6";
                ui->SHEDULE_CHECK_13->setItem(2,0,new QTableWidgetItem(FRoOM_D.at(inh)));
                ui->SHEDULE_CHECK_13->setItem(3,0,new QTableWidgetItem(TO_oD.at(inh)));
                ui->SHEDULE_CHECK_13->setItem(4,0,new QTableWidgetItem(xy.at(86)));
                ui->stackedWidget->setCurrentIndex(23);
            }
            else
            {
                QMessageBox :: warning(this,"Ticket","NOT AVAILABLE!");
            }
    }
    ree.close();
}


void MainWindow::on_H_7_clicked()
{
    QVector<QString>xy;
    QVector<QString>FRoOM_D,TO_oD,S_DATE_oD,S_SRNO_oD,STRT_TIME_oD,END_TIME_oD,DAY;

    QFile ree(Flight_choice);
    if(ree.open(QIODevice::ReadOnly))
    {
            QTextStream stream(&ree);
            while ( stream.atEnd()==false)
            {
                xy.push_back(stream.readLine());
            }
            if(xy.at(55)=="nonbooked")
            {

                QFile Fiiile("FLIGHT.txt");
                if(Fiiile.open(QIODevice::ReadOnly))
                {
                    QTextStream stream(&Fiiile);
                    while ( stream.atEnd()==false)
                    {
                        S_SRNO_oD.push_back(stream.readLine());
                        FRoOM_D.push_back(stream.readLine());
                        TO_oD.push_back(stream.readLine());
                        STRT_TIME_oD.push_back(stream.readLine());
                        END_TIME_oD.push_back(stream.readLine());
                        S_DATE_oD.push_back(stream.readLine());DAY.push_back(stream.readLine());
                    }
                }
                Fiiile.close();
                int inh = S_SRNO_oD.indexOf(Flight_choice);

                ui->SHEDULE_CHECK_13->setItem(0,0,new QTableWidgetItem(xy.at(81)));
                ui->SHEDULE_CHECK_13->setItem(1,0,new QTableWidgetItem("H7"));
                ui->Ticket_P->setText("H7");ui->CLASS_P->setText("ECONOMY");BOOKKING=Flight_choice+"H7";
                ui->SHEDULE_CHECK_13->setItem(2,0,new QTableWidgetItem(FRoOM_D.at(inh)));
                ui->SHEDULE_CHECK_13->setItem(3,0,new QTableWidgetItem(TO_oD.at(inh)));
                ui->SHEDULE_CHECK_13->setItem(4,0,new QTableWidgetItem(xy.at(86)));
                ui->stackedWidget->setCurrentIndex(23);
            }
            else
            {
                QMessageBox :: warning(this,"Ticket","NOT AVAILABLE!");
            }
    }
    ree.close();
}


void MainWindow::on_H_8_clicked()
{
    QVector<QString>xy;
    QVector<QString>FRoOM_D,TO_oD,S_DATE_oD,S_SRNO_oD,STRT_TIME_oD,END_TIME_oD,DAY;

    QFile ree(Flight_choice);
    if(ree.open(QIODevice::ReadOnly))
    {
            QTextStream stream(&ree);
            while ( stream.atEnd()==false)
            {
                xy.push_back(stream.readLine());
            }
            if(xy.at(56)=="nonbooked")
            {

                QFile Fiiile("FLIGHT.txt");
                if(Fiiile.open(QIODevice::ReadOnly))
                {
                    QTextStream stream(&Fiiile);
                    while ( stream.atEnd()==false)
                    {
                        S_SRNO_oD.push_back(stream.readLine());
                        FRoOM_D.push_back(stream.readLine());
                        TO_oD.push_back(stream.readLine());
                        STRT_TIME_oD.push_back(stream.readLine());
                        END_TIME_oD.push_back(stream.readLine());
                        S_DATE_oD.push_back(stream.readLine());DAY.push_back(stream.readLine());
                    }
                }
                Fiiile.close();
                int inh = S_SRNO_oD.indexOf(Flight_choice);

                ui->SHEDULE_CHECK_13->setItem(0,0,new QTableWidgetItem(xy.at(81)));
                ui->SHEDULE_CHECK_13->setItem(1,0,new QTableWidgetItem("H8"));
                ui->Ticket_P->setText("H8");ui->CLASS_P->setText("ECONOMY");BOOKKING=Flight_choice+"H8";
                ui->SHEDULE_CHECK_13->setItem(2,0,new QTableWidgetItem(FRoOM_D.at(inh)));
                ui->SHEDULE_CHECK_13->setItem(3,0,new QTableWidgetItem(TO_oD.at(inh)));
                ui->SHEDULE_CHECK_13->setItem(4,0,new QTableWidgetItem(xy.at(86)));
                ui->stackedWidget->setCurrentIndex(23);
            }
            else
            {
                QMessageBox :: warning(this,"Ticket","NOT AVAILABLE!");
            }
    }
    ree.close();

}


void MainWindow::on_H_9_clicked()
{
    QVector<QString>xy;
    QVector<QString>FRoOM_D,TO_oD,S_DATE_oD,S_SRNO_oD,STRT_TIME_oD,END_TIME_oD,DAY;

    QFile ree(Flight_choice);
    if(ree.open(QIODevice::ReadOnly))
    {
            QTextStream stream(&ree);
            while ( stream.atEnd()==false)
            {
                xy.push_back(stream.readLine());
            }
            if(xy.at(57)=="nonbooked")
            {

                QFile Fiiile("FLIGHT.txt");
                if(Fiiile.open(QIODevice::ReadOnly))
                {
                    QTextStream stream(&Fiiile);
                    while ( stream.atEnd()==false)
                    {
                        S_SRNO_oD.push_back(stream.readLine());
                        FRoOM_D.push_back(stream.readLine());
                        TO_oD.push_back(stream.readLine());
                        STRT_TIME_oD.push_back(stream.readLine());
                        END_TIME_oD.push_back(stream.readLine());
                        S_DATE_oD.push_back(stream.readLine());DAY.push_back(stream.readLine());
                    }
                }
                Fiiile.close();
                int inh = S_SRNO_oD.indexOf(Flight_choice);

                ui->SHEDULE_CHECK_13->setItem(0,0,new QTableWidgetItem(xy.at(81)));
                ui->SHEDULE_CHECK_13->setItem(1,0,new QTableWidgetItem("H9"));
                ui->Ticket_P->setText("H9");ui->CLASS_P->setText("ECONOMY");BOOKKING=Flight_choice+"H9";
                ui->SHEDULE_CHECK_13->setItem(2,0,new QTableWidgetItem(FRoOM_D.at(inh)));
                ui->SHEDULE_CHECK_13->setItem(3,0,new QTableWidgetItem(TO_oD.at(inh)));
                ui->SHEDULE_CHECK_13->setItem(4,0,new QTableWidgetItem(xy.at(86)));
                ui->stackedWidget->setCurrentIndex(23);

            }
            else
            {
                QMessageBox :: warning(this,"Ticket","NOT AVAILABLE!");
            }
    }
    ree.close();
}


void MainWindow::on_I_1_clicked()
{
    QVector<QString>xy;
    QVector<QString>FRoOM_D,TO_oD,S_DATE_oD,S_SRNO_oD,STRT_TIME_oD,END_TIME_oD,DAY;

    QFile ree(Flight_choice);
    if(ree.open(QIODevice::ReadOnly))
    {
            QTextStream stream(&ree);
            while ( stream.atEnd()==false)
            {
                xy.push_back(stream.readLine());
            }
            if(xy.at(57)=="nonbooked")
            {

                QFile Fiiile("FLIGHT.txt");
                if(Fiiile.open(QIODevice::ReadOnly))
                {
                    QTextStream stream(&Fiiile);
                    while ( stream.atEnd()==false)
                    {
                        S_SRNO_oD.push_back(stream.readLine());
                        FRoOM_D.push_back(stream.readLine());
                        TO_oD.push_back(stream.readLine());
                        STRT_TIME_oD.push_back(stream.readLine());
                        END_TIME_oD.push_back(stream.readLine());
                        S_DATE_oD.push_back(stream.readLine());DAY.push_back(stream.readLine());
                    }
                }
                Fiiile.close();
                int inh = S_SRNO_oD.indexOf(Flight_choice);

                ui->SHEDULE_CHECK_13->setItem(0,0,new QTableWidgetItem(xy.at(81)));
                ui->SHEDULE_CHECK_13->setItem(1,0,new QTableWidgetItem("I1"));
                ui->Ticket_P->setText("I1");ui->CLASS_P->setText("ECONOMY");BOOKKING=Flight_choice+"I1";
                ui->SHEDULE_CHECK_13->setItem(2,0,new QTableWidgetItem(FRoOM_D.at(inh)));
                ui->SHEDULE_CHECK_13->setItem(3,0,new QTableWidgetItem(TO_oD.at(inh)));
                ui->SHEDULE_CHECK_13->setItem(4,0,new QTableWidgetItem(xy.at(86)));
                ui->stackedWidget->setCurrentIndex(23);
            }
            else
            {
                QMessageBox :: warning(this,"Ticket","NOT AVAILABLE!");
            }
    }
    ree.close();
}


void MainWindow::on_I_2_clicked()
{
    QVector<QString>xy;
    QVector<QString>FRoOM_D,TO_oD,S_DATE_oD,S_SRNO_oD,STRT_TIME_oD,END_TIME_oD,DAY;

    QFile ree(Flight_choice);
    if(ree.open(QIODevice::ReadOnly))
    {
            QTextStream stream(&ree);
            while ( stream.atEnd()==false)
            {
                xy.push_back(stream.readLine());
            }
            if(xy.at(58)=="nonbooked")
            {

                QFile Fiiile("FLIGHT.txt");
                if(Fiiile.open(QIODevice::ReadOnly))
                {
                    QTextStream stream(&Fiiile);
                    while ( stream.atEnd()==false)
                    {
                        S_SRNO_oD.push_back(stream.readLine());
                        FRoOM_D.push_back(stream.readLine());
                        TO_oD.push_back(stream.readLine());
                        STRT_TIME_oD.push_back(stream.readLine());
                        END_TIME_oD.push_back(stream.readLine());
                        S_DATE_oD.push_back(stream.readLine());DAY.push_back(stream.readLine());
                    }
                }
                Fiiile.close();
                int inh = S_SRNO_oD.indexOf(Flight_choice);

                ui->SHEDULE_CHECK_13->setItem(0,0,new QTableWidgetItem(xy.at(81)));
                ui->SHEDULE_CHECK_13->setItem(1,0,new QTableWidgetItem("I2"));
                ui->Ticket_P->setText("I2");ui->CLASS_P->setText("ECONOMY");BOOKKING=Flight_choice+"I2";
                ui->SHEDULE_CHECK_13->setItem(2,0,new QTableWidgetItem(FRoOM_D.at(inh)));
                ui->SHEDULE_CHECK_13->setItem(3,0,new QTableWidgetItem(TO_oD.at(inh)));
                ui->SHEDULE_CHECK_13->setItem(4,0,new QTableWidgetItem(xy.at(86)));
                ui->stackedWidget->setCurrentIndex(23);
            }
            else
            {
                QMessageBox :: warning(this,"Ticket","NOT AVAILABLE!");
            }
    }
    ree.close();
}


void MainWindow::on_I_3_clicked()
{
    QVector<QString>xy;
    QVector<QString>FRoOM_D,TO_oD,S_DATE_oD,S_SRNO_oD,STRT_TIME_oD,END_TIME_oD,DAY;

    QFile ree(Flight_choice);
    if(ree.open(QIODevice::ReadOnly))
    {
            QTextStream stream(&ree);
            while ( stream.atEnd()==false)
            {
                xy.push_back(stream.readLine());
            }
            if(xy.at(59)=="nonbooked")
            {

                QFile Fiiile("FLIGHT.txt");
                if(Fiiile.open(QIODevice::ReadOnly))
                {
                    QTextStream stream(&Fiiile);
                    while ( stream.atEnd()==false)
                    {
                        S_SRNO_oD.push_back(stream.readLine());
                        FRoOM_D.push_back(stream.readLine());
                        TO_oD.push_back(stream.readLine());
                        STRT_TIME_oD.push_back(stream.readLine());
                        END_TIME_oD.push_back(stream.readLine());
                        S_DATE_oD.push_back(stream.readLine());DAY.push_back(stream.readLine());
                    }
                }
                Fiiile.close();
                int inh = S_SRNO_oD.indexOf(Flight_choice);

                ui->SHEDULE_CHECK_13->setItem(0,0,new QTableWidgetItem(xy.at(81)));
                ui->SHEDULE_CHECK_13->setItem(1,0,new QTableWidgetItem("I3"));
                ui->Ticket_P->setText("I3");ui->CLASS_P->setText("ECONOMY");BOOKKING=Flight_choice+"I3";
                ui->SHEDULE_CHECK_13->setItem(2,0,new QTableWidgetItem(FRoOM_D.at(inh)));
                ui->SHEDULE_CHECK_13->setItem(3,0,new QTableWidgetItem(TO_oD.at(inh)));
                ui->SHEDULE_CHECK_13->setItem(4,0,new QTableWidgetItem(xy.at(86)));
                ui->stackedWidget->setCurrentIndex(23);
            }
            else
            {
                QMessageBox :: warning(this,"Ticket","NOT AVAILABLE!");
            }
    }
    ree.close();

}


void MainWindow::on_I_4_clicked()
{
    QVector<QString>xy;
    QVector<QString>FRoOM_D,TO_oD,S_DATE_oD,S_SRNO_oD,STRT_TIME_oD,END_TIME_oD,DAY;

    QFile ree(Flight_choice);
    if(ree.open(QIODevice::ReadOnly))
    {
            QTextStream stream(&ree);
            while ( stream.atEnd()==false)
            {
                xy.push_back(stream.readLine());
            }
            if(xy.at(60)=="nonbooked")
            {

                QFile Fiiile("FLIGHT.txt");
                if(Fiiile.open(QIODevice::ReadOnly))
                {
                    QTextStream stream(&Fiiile);
                    while ( stream.atEnd()==false)
                    {
                        S_SRNO_oD.push_back(stream.readLine());
                        FRoOM_D.push_back(stream.readLine());
                        TO_oD.push_back(stream.readLine());
                        STRT_TIME_oD.push_back(stream.readLine());
                        END_TIME_oD.push_back(stream.readLine());
                        S_DATE_oD.push_back(stream.readLine());DAY.push_back(stream.readLine());
                    }
                }
                Fiiile.close();
                int inh = S_SRNO_oD.indexOf(Flight_choice);

                ui->SHEDULE_CHECK_13->setItem(0,0,new QTableWidgetItem(xy.at(81)));
                ui->SHEDULE_CHECK_13->setItem(1,0,new QTableWidgetItem("I4"));
                ui->Ticket_P->setText("I4");ui->CLASS_P->setText("ECONOMY");BOOKKING=Flight_choice+"I4";
                ui->SHEDULE_CHECK_13->setItem(2,0,new QTableWidgetItem(FRoOM_D.at(inh)));
                ui->SHEDULE_CHECK_13->setItem(3,0,new QTableWidgetItem(TO_oD.at(inh)));
                ui->SHEDULE_CHECK_13->setItem(4,0,new QTableWidgetItem(xy.at(86)));
                ui->stackedWidget->setCurrentIndex(23);
            }
            else
            {
                QMessageBox :: warning(this,"Ticket","NOT AVAILABLE!");
            }
    }
    ree.close();

}


void MainWindow::on_I_5_clicked()
{
    QVector<QString>xy;
    QVector<QString>FRoOM_D,TO_oD,S_DATE_oD,S_SRNO_oD,STRT_TIME_oD,END_TIME_oD,DAY;

    QFile ree(Flight_choice);
    if(ree.open(QIODevice::ReadOnly))
    {
            QTextStream stream(&ree);
            while ( stream.atEnd()==false)
            {
                xy.push_back(stream.readLine());
            }
            if(xy.at(61)=="nonbooked")
            {

                QFile Fiiile("FLIGHT.txt");
                if(Fiiile.open(QIODevice::ReadOnly))
                {
                    QTextStream stream(&Fiiile);
                    while ( stream.atEnd()==false)
                    {
                        S_SRNO_oD.push_back(stream.readLine());
                        FRoOM_D.push_back(stream.readLine());
                        TO_oD.push_back(stream.readLine());
                        STRT_TIME_oD.push_back(stream.readLine());
                        END_TIME_oD.push_back(stream.readLine());
                        S_DATE_oD.push_back(stream.readLine());DAY.push_back(stream.readLine());
                    }
                }
                Fiiile.close();
                int inh = S_SRNO_oD.indexOf(Flight_choice);

                ui->SHEDULE_CHECK_13->setItem(0,0,new QTableWidgetItem(xy.at(81)));
                ui->SHEDULE_CHECK_13->setItem(1,0,new QTableWidgetItem("I5"));
                ui->Ticket_P->setText("I5");ui->CLASS_P->setText("ECONOMY");BOOKKING=Flight_choice+"I5";
                ui->SHEDULE_CHECK_13->setItem(2,0,new QTableWidgetItem(FRoOM_D.at(inh)));
                ui->SHEDULE_CHECK_13->setItem(3,0,new QTableWidgetItem(TO_oD.at(inh)));
                ui->SHEDULE_CHECK_13->setItem(4,0,new QTableWidgetItem(xy.at(86)));
                ui->stackedWidget->setCurrentIndex(23);
            }
            else
            {
                QMessageBox :: warning(this,"Ticket","NOT AVAILABLE!");
            }
    }
    ree.close();
}


void MainWindow::on_I_6_clicked()
{
    QVector<QString>xy;
    QVector<QString>FRoOM_D,TO_oD,S_DATE_oD,S_SRNO_oD,STRT_TIME_oD,END_TIME_oD,DAY;

    QFile ree(Flight_choice);
    if(ree.open(QIODevice::ReadOnly))
    {
            QTextStream stream(&ree);
            while ( stream.atEnd()==false)
            {
                xy.push_back(stream.readLine());
            }
            if(xy.at(62)=="nonbooked")
            {

                QFile Fiiile("FLIGHT.txt");
                if(Fiiile.open(QIODevice::ReadOnly))
                {
                    QTextStream stream(&Fiiile);
                    while ( stream.atEnd()==false)
                    {
                        S_SRNO_oD.push_back(stream.readLine());
                        FRoOM_D.push_back(stream.readLine());
                        TO_oD.push_back(stream.readLine());
                        STRT_TIME_oD.push_back(stream.readLine());
                        END_TIME_oD.push_back(stream.readLine());
                        S_DATE_oD.push_back(stream.readLine());DAY.push_back(stream.readLine());
                    }
                }
                Fiiile.close();
                int inh = S_SRNO_oD.indexOf(Flight_choice);

                ui->SHEDULE_CHECK_13->setItem(0,0,new QTableWidgetItem(xy.at(81)));
                ui->SHEDULE_CHECK_13->setItem(1,0,new QTableWidgetItem("I6"));
                ui->Ticket_P->setText("I6");ui->CLASS_P->setText("ECONOMY");BOOKKING=Flight_choice+"I6";
                ui->SHEDULE_CHECK_13->setItem(2,0,new QTableWidgetItem(FRoOM_D.at(inh)));
                ui->SHEDULE_CHECK_13->setItem(3,0,new QTableWidgetItem(TO_oD.at(inh)));
                ui->SHEDULE_CHECK_13->setItem(4,0,new QTableWidgetItem(xy.at(86)));
                ui->stackedWidget->setCurrentIndex(23);
            }
            else
            {
                QMessageBox :: warning(this,"Ticket","NOT AVAILABLE!");
            }
    }
    ree.close();
}


void MainWindow::on_I_7_clicked()
{
    QVector<QString>xy;
    QVector<QString>FRoOM_D,TO_oD,S_DATE_oD,S_SRNO_oD,STRT_TIME_oD,END_TIME_oD,DAY;

    QFile ree(Flight_choice);
    if(ree.open(QIODevice::ReadOnly))
    {
            QTextStream stream(&ree);
            while ( stream.atEnd()==false)
            {
                xy.push_back(stream.readLine());
            }
            if(xy.at(63)=="nonbooked")
            {

                QFile Fiiile("FLIGHT.txt");
                if(Fiiile.open(QIODevice::ReadOnly))
                {
                    QTextStream stream(&Fiiile);
                    while ( stream.atEnd()==false)
                    {
                        S_SRNO_oD.push_back(stream.readLine());
                        FRoOM_D.push_back(stream.readLine());
                        TO_oD.push_back(stream.readLine());
                        STRT_TIME_oD.push_back(stream.readLine());
                        END_TIME_oD.push_back(stream.readLine());
                        S_DATE_oD.push_back(stream.readLine());DAY.push_back(stream.readLine());
                    }
                }
                Fiiile.close();
                int inh = S_SRNO_oD.indexOf(Flight_choice);

                ui->SHEDULE_CHECK_13->setItem(0,0,new QTableWidgetItem(xy.at(81)));
                ui->SHEDULE_CHECK_13->setItem(1,0,new QTableWidgetItem("I7"));
                ui->Ticket_P->setText("I7");ui->CLASS_P->setText("ECONOMY");BOOKKING=Flight_choice+"I7";
                ui->SHEDULE_CHECK_13->setItem(2,0,new QTableWidgetItem(FRoOM_D.at(inh)));
                ui->SHEDULE_CHECK_13->setItem(3,0,new QTableWidgetItem(TO_oD.at(inh)));
                ui->SHEDULE_CHECK_13->setItem(4,0,new QTableWidgetItem(xy.at(86)));
                ui->stackedWidget->setCurrentIndex(23);
            }
            else
            {
                QMessageBox :: warning(this,"Ticket","NOT AVAILABLE!");
            }
    }
    ree.close();
}


void MainWindow::on_I_8_clicked()
{
    QVector<QString>xy;
    QVector<QString>FRoOM_D,TO_oD,S_DATE_oD,S_SRNO_oD,STRT_TIME_oD,END_TIME_oD,DAY;

    QFile ree(Flight_choice);
    if(ree.open(QIODevice::ReadOnly))
    {
            QTextStream stream(&ree);
            while ( stream.atEnd()==false)
            {
                xy.push_back(stream.readLine());
            }
            if(xy.at(64)=="nonbooked")
            {

                QFile Fiiile("FLIGHT.txt");
                if(Fiiile.open(QIODevice::ReadOnly))
                {
                    QTextStream stream(&Fiiile);
                    while ( stream.atEnd()==false)
                    {
                        S_SRNO_oD.push_back(stream.readLine());
                        FRoOM_D.push_back(stream.readLine());
                        TO_oD.push_back(stream.readLine());
                        STRT_TIME_oD.push_back(stream.readLine());
                        END_TIME_oD.push_back(stream.readLine());
                        S_DATE_oD.push_back(stream.readLine());DAY.push_back(stream.readLine());
                    }
                }
                Fiiile.close();
                int inh = S_SRNO_oD.indexOf(Flight_choice);

                ui->SHEDULE_CHECK_13->setItem(0,0,new QTableWidgetItem(xy.at(81)));
                ui->SHEDULE_CHECK_13->setItem(1,0,new QTableWidgetItem("I8"));
                ui->Ticket_P->setText("I8");ui->CLASS_P->setText("ECONOMY");BOOKKING=Flight_choice+"I8";
                ui->SHEDULE_CHECK_13->setItem(2,0,new QTableWidgetItem(FRoOM_D.at(inh)));
                ui->SHEDULE_CHECK_13->setItem(3,0,new QTableWidgetItem(TO_oD.at(inh)));
                ui->SHEDULE_CHECK_13->setItem(4,0,new QTableWidgetItem(xy.at(86)));
                ui->stackedWidget->setCurrentIndex(23);

            }
            else
            {
                QMessageBox :: warning(this,"Ticket","NOT AVAILABLE!");
            }
    }
    ree.close();

}


void MainWindow::on_I_9_clicked()
{
    QVector<QString>xy;
    QVector<QString>FRoOM_D,TO_oD,S_DATE_oD,S_SRNO_oD,STRT_TIME_oD,END_TIME_oD,DAY;

    QFile ree(Flight_choice);
    if(ree.open(QIODevice::ReadOnly))
    {
            QTextStream stream(&ree);
            while ( stream.atEnd()==false)
            {
                xy.push_back(stream.readLine());
            }
            if(xy.at(65)=="nonbooked")
            {

                QFile Fiiile("FLIGHT.txt");
                if(Fiiile.open(QIODevice::ReadOnly))
                {
                    QTextStream stream(&Fiiile);
                    while ( stream.atEnd()==false)
                    {
                        S_SRNO_oD.push_back(stream.readLine());
                        FRoOM_D.push_back(stream.readLine());
                        TO_oD.push_back(stream.readLine());
                        STRT_TIME_oD.push_back(stream.readLine());
                        END_TIME_oD.push_back(stream.readLine());
                        S_DATE_oD.push_back(stream.readLine());DAY.push_back(stream.readLine());
                    }
                }
                Fiiile.close();
                int inh = S_SRNO_oD.indexOf(Flight_choice);

                ui->SHEDULE_CHECK_13->setItem(0,0,new QTableWidgetItem(xy.at(81)));
                ui->SHEDULE_CHECK_13->setItem(1,0,new QTableWidgetItem("I9"));
                ui->Ticket_P->setText("I9");ui->CLASS_P->setText("ECONOMY");BOOKKING=Flight_choice+"I9";
                ui->SHEDULE_CHECK_13->setItem(2,0,new QTableWidgetItem(FRoOM_D.at(inh)));
                ui->SHEDULE_CHECK_13->setItem(3,0,new QTableWidgetItem(TO_oD.at(inh)));
                ui->SHEDULE_CHECK_13->setItem(4,0,new QTableWidgetItem(xy.at(86)));
                ui->stackedWidget->setCurrentIndex(23);

            }
            else
            {
                QMessageBox :: warning(this,"Ticket","NOT AVAILABLE!");
            }
    }
    ree.close();
}


void MainWindow::on_J_1_clicked()
{
    QVector<QString>xy;
    QVector<QString>FRoOM_D,TO_oD,S_DATE_oD,S_SRNO_oD,STRT_TIME_oD,END_TIME_oD,DAY;

    QFile ree(Flight_choice);
    if(ree.open(QIODevice::ReadOnly))
    {
            QTextStream stream(&ree);
            while ( stream.atEnd()==false)
            {
                xy.push_back(stream.readLine());
            }
            if(xy.at(66)=="nonbooked")
            {

                QFile Fiiile("FLIGHT.txt");
                if(Fiiile.open(QIODevice::ReadOnly))
                {
                    QTextStream stream(&Fiiile);
                    while ( stream.atEnd()==false)
                    {
                        S_SRNO_oD.push_back(stream.readLine());
                        FRoOM_D.push_back(stream.readLine());
                        TO_oD.push_back(stream.readLine());
                        STRT_TIME_oD.push_back(stream.readLine());
                        END_TIME_oD.push_back(stream.readLine());
                        S_DATE_oD.push_back(stream.readLine());DAY.push_back(stream.readLine());
                    }
                }
                Fiiile.close();
                int inh = S_SRNO_oD.indexOf(Flight_choice);

                ui->SHEDULE_CHECK_13->setItem(0,0,new QTableWidgetItem(xy.at(81)));
                ui->SHEDULE_CHECK_13->setItem(1,0,new QTableWidgetItem("J1"));
                ui->Ticket_P->setText("J1");ui->CLASS_P->setText("ECONOMY");BOOKKING=Flight_choice+"J1";
                ui->SHEDULE_CHECK_13->setItem(2,0,new QTableWidgetItem(FRoOM_D.at(inh)));
                ui->SHEDULE_CHECK_13->setItem(3,0,new QTableWidgetItem(TO_oD.at(inh)));
                ui->SHEDULE_CHECK_13->setItem(4,0,new QTableWidgetItem(xy.at(86)));
                ui->stackedWidget->setCurrentIndex(23);
            }
            else
            {
                QMessageBox :: warning(this,"Ticket","NOT AVAILABLE!");
            }
    }
    ree.close();
}


void MainWindow::on_J_2_clicked()
{
    QVector<QString>xy;
    QVector<QString>FRoOM_D,TO_oD,S_DATE_oD,S_SRNO_oD,STRT_TIME_oD,END_TIME_oD,DAY;

    QFile ree(Flight_choice);
    if(ree.open(QIODevice::ReadOnly))
    {
            QTextStream stream(&ree);
            while ( stream.atEnd()==false)
            {
                xy.push_back(stream.readLine());
            }
            if(xy.at(67)=="nonbooked")
            {

                QFile Fiiile("FLIGHT.txt");
                if(Fiiile.open(QIODevice::ReadOnly))
                {
                    QTextStream stream(&Fiiile);
                    while ( stream.atEnd()==false)
                    {
                        S_SRNO_oD.push_back(stream.readLine());
                        FRoOM_D.push_back(stream.readLine());
                        TO_oD.push_back(stream.readLine());
                        STRT_TIME_oD.push_back(stream.readLine());
                        END_TIME_oD.push_back(stream.readLine());
                        S_DATE_oD.push_back(stream.readLine());DAY.push_back(stream.readLine());
                    }
                }
                Fiiile.close();
                int inh = S_SRNO_oD.indexOf(Flight_choice);

                ui->SHEDULE_CHECK_13->setItem(0,0,new QTableWidgetItem(xy.at(81)));
                ui->SHEDULE_CHECK_13->setItem(1,0,new QTableWidgetItem("J2"));
                ui->Ticket_P->setText("J2");ui->CLASS_P->setText("ECONOMY");BOOKKING=Flight_choice+"J2";
                ui->SHEDULE_CHECK_13->setItem(2,0,new QTableWidgetItem(FRoOM_D.at(inh)));
                ui->SHEDULE_CHECK_13->setItem(3,0,new QTableWidgetItem(TO_oD.at(inh)));
                ui->SHEDULE_CHECK_13->setItem(4,0,new QTableWidgetItem(xy.at(86)));
                ui->stackedWidget->setCurrentIndex(23);
            }
            else
            {
                QMessageBox :: warning(this,"Ticket","NOT AVAILABLE!");
            }
    }
    ree.close();
}


void MainWindow::on_J_3_clicked()
{
    QVector<QString>xy;
    QVector<QString>FRoOM_D,TO_oD,S_DATE_oD,S_SRNO_oD,STRT_TIME_oD,END_TIME_oD,DAY;

    QFile ree(Flight_choice);
    if(ree.open(QIODevice::ReadOnly))
    {
            QTextStream stream(&ree);
            while ( stream.atEnd()==false)
            {
                xy.push_back(stream.readLine());
            }
            if(xy.at(68)=="nonbooked")
            {

                QFile Fiiile("FLIGHT.txt");
                if(Fiiile.open(QIODevice::ReadOnly))
                {
                    QTextStream stream(&Fiiile);
                    while ( stream.atEnd()==false)
                    {
                        S_SRNO_oD.push_back(stream.readLine());
                        FRoOM_D.push_back(stream.readLine());
                        TO_oD.push_back(stream.readLine());
                        STRT_TIME_oD.push_back(stream.readLine());
                        END_TIME_oD.push_back(stream.readLine());
                        S_DATE_oD.push_back(stream.readLine());DAY.push_back(stream.readLine());
                    }
                }
                Fiiile.close();
                int inh = S_SRNO_oD.indexOf(Flight_choice);

                ui->SHEDULE_CHECK_13->setItem(0,0,new QTableWidgetItem(xy.at(81)));
                ui->SHEDULE_CHECK_13->setItem(1,0,new QTableWidgetItem("J3"));
                ui->Ticket_P->setText("J3");ui->CLASS_P->setText("ECONOMY");BOOKKING=Flight_choice+"J3";
                ui->SHEDULE_CHECK_13->setItem(2,0,new QTableWidgetItem(FRoOM_D.at(inh)));
                ui->SHEDULE_CHECK_13->setItem(3,0,new QTableWidgetItem(TO_oD.at(inh)));
                ui->SHEDULE_CHECK_13->setItem(4,0,new QTableWidgetItem(xy.at(86)));
                ui->stackedWidget->setCurrentIndex(23);
            }
            else
            {
                QMessageBox :: warning(this,"Ticket","NOT AVAILABLE!");
            }
    }
    ree.close();
}


void MainWindow::on_J_4_clicked()
{
    QVector<QString>xy;
    QVector<QString>FRoOM_D,TO_oD,S_DATE_oD,S_SRNO_oD,STRT_TIME_oD,END_TIME_oD,DAY;

    QFile ree(Flight_choice);
    if(ree.open(QIODevice::ReadOnly))
    {
            QTextStream stream(&ree);
            while ( stream.atEnd()==false)
            {
                xy.push_back(stream.readLine());
            }
            if(xy.at(69)=="nonbooked")
            {

                QFile Fiiile("FLIGHT.txt");
                if(Fiiile.open(QIODevice::ReadOnly))
                {
                    QTextStream stream(&Fiiile);
                    while ( stream.atEnd()==false)
                    {
                        S_SRNO_oD.push_back(stream.readLine());
                        FRoOM_D.push_back(stream.readLine());
                        TO_oD.push_back(stream.readLine());
                        STRT_TIME_oD.push_back(stream.readLine());
                        END_TIME_oD.push_back(stream.readLine());
                        S_DATE_oD.push_back(stream.readLine());DAY.push_back(stream.readLine());
                    }
                }
                Fiiile.close();
                int inh = S_SRNO_oD.indexOf(Flight_choice);

                ui->SHEDULE_CHECK_13->setItem(0,0,new QTableWidgetItem(xy.at(81)));
                ui->SHEDULE_CHECK_13->setItem(1,0,new QTableWidgetItem("J4"));
                ui->Ticket_P->setText("J4");ui->CLASS_P->setText("ECONOMY");BOOKKING=Flight_choice+"J4";
                ui->SHEDULE_CHECK_13->setItem(2,0,new QTableWidgetItem(FRoOM_D.at(inh)));
                ui->SHEDULE_CHECK_13->setItem(3,0,new QTableWidgetItem(TO_oD.at(inh)));
                ui->SHEDULE_CHECK_13->setItem(4,0,new QTableWidgetItem(xy.at(86)));
                ui->stackedWidget->setCurrentIndex(23);
            }
            else
            {
                QMessageBox :: warning(this,"Ticket","NOT AVAILABLE!");
            }
    }
    ree.close();
}


void MainWindow::on_J_5_clicked()
{
    QVector<QString>xy;
    QVector<QString>FRoOM_D,TO_oD,S_DATE_oD,S_SRNO_oD,STRT_TIME_oD,END_TIME_oD,DAY;

    QFile ree(Flight_choice);
    if(ree.open(QIODevice::ReadOnly))
    {
            QTextStream stream(&ree);
            while ( stream.atEnd()==false)
            {
                xy.push_back(stream.readLine());
            }
            if(xy.at(70)=="nonbooked")
            {

                QFile Fiiile("FLIGHT.txt");
                if(Fiiile.open(QIODevice::ReadOnly))
                {
                    QTextStream stream(&Fiiile);
                    while ( stream.atEnd()==false)
                    {
                        S_SRNO_oD.push_back(stream.readLine());
                        FRoOM_D.push_back(stream.readLine());
                        TO_oD.push_back(stream.readLine());
                        STRT_TIME_oD.push_back(stream.readLine());
                        END_TIME_oD.push_back(stream.readLine());
                        S_DATE_oD.push_back(stream.readLine());DAY.push_back(stream.readLine());
                    }
                }
                Fiiile.close();
                int inh = S_SRNO_oD.indexOf(Flight_choice);

                ui->SHEDULE_CHECK_13->setItem(0,0,new QTableWidgetItem(xy.at(81)));
                ui->SHEDULE_CHECK_13->setItem(1,0,new QTableWidgetItem("J5"));
                ui->Ticket_P->setText("J5");ui->CLASS_P->setText("ECONOMY");BOOKKING=Flight_choice+"J5";
                ui->SHEDULE_CHECK_13->setItem(2,0,new QTableWidgetItem(FRoOM_D.at(inh)));
                ui->SHEDULE_CHECK_13->setItem(3,0,new QTableWidgetItem(TO_oD.at(inh)));
                ui->SHEDULE_CHECK_13->setItem(4,0,new QTableWidgetItem(xy.at(86)));
                ui->stackedWidget->setCurrentIndex(23);
            }
            else
            {
                QMessageBox :: warning(this,"Ticket","NOT AVAILABLE!");
            }
    }
    ree.close();
}


void MainWindow::on_J_6_clicked()
{
    QVector<QString>xy;
    QVector<QString>FRoOM_D,TO_oD,S_DATE_oD,S_SRNO_oD,STRT_TIME_oD,END_TIME_oD,DAY;

    QFile ree(Flight_choice);
    if(ree.open(QIODevice::ReadOnly))
    {
            QTextStream stream(&ree);
            while ( stream.atEnd()==false)
            {
                xy.push_back(stream.readLine());
            }
            if(xy.at(71)=="nonbooked")
            {

                QFile Fiiile("FLIGHT.txt");
                if(Fiiile.open(QIODevice::ReadOnly))
                {
                    QTextStream stream(&Fiiile);
                    while ( stream.atEnd()==false)
                    {
                        S_SRNO_oD.push_back(stream.readLine());
                        FRoOM_D.push_back(stream.readLine());
                        TO_oD.push_back(stream.readLine());
                        STRT_TIME_oD.push_back(stream.readLine());
                        END_TIME_oD.push_back(stream.readLine());
                        S_DATE_oD.push_back(stream.readLine());DAY.push_back(stream.readLine());
                    }
                }
                Fiiile.close();
                int inh = S_SRNO_oD.indexOf(Flight_choice);

                ui->SHEDULE_CHECK_13->setItem(0,0,new QTableWidgetItem(xy.at(81)));
                ui->SHEDULE_CHECK_13->setItem(1,0,new QTableWidgetItem("J6"));
                ui->Ticket_P->setText("J6");ui->CLASS_P->setText("ECONOMY");BOOKKING=Flight_choice+"J6";
                ui->SHEDULE_CHECK_13->setItem(2,0,new QTableWidgetItem(FRoOM_D.at(inh)));
                ui->SHEDULE_CHECK_13->setItem(3,0,new QTableWidgetItem(TO_oD.at(inh)));
                ui->SHEDULE_CHECK_13->setItem(4,0,new QTableWidgetItem(xy.at(86)));
                ui->stackedWidget->setCurrentIndex(23);
            }
            else
            {
                QMessageBox :: warning(this,"Ticket","NOT AVAILABLE!");
            }
    }
    ree.close();
}


void MainWindow::on_J_7_clicked()
{
    QVector<QString>xy;
    QVector<QString>FRoOM_D,TO_oD,S_DATE_oD,S_SRNO_oD,STRT_TIME_oD,END_TIME_oD,DAY;

    QFile ree(Flight_choice);
    if(ree.open(QIODevice::ReadOnly))
    {
            QTextStream stream(&ree);
            while ( stream.atEnd()==false)
            {
                xy.push_back(stream.readLine());
            }
            if(xy.at(72)=="nonbooked")
            {

                QFile Fiiile("FLIGHT.txt");
                if(Fiiile.open(QIODevice::ReadOnly))
                {
                    QTextStream stream(&Fiiile);
                    while ( stream.atEnd()==false)
                    {
                        S_SRNO_oD.push_back(stream.readLine());
                        FRoOM_D.push_back(stream.readLine());
                        TO_oD.push_back(stream.readLine());
                        STRT_TIME_oD.push_back(stream.readLine());
                        END_TIME_oD.push_back(stream.readLine());
                        S_DATE_oD.push_back(stream.readLine());DAY.push_back(stream.readLine());
                    }
                }
                Fiiile.close();
                int inh = S_SRNO_oD.indexOf(Flight_choice);

                ui->SHEDULE_CHECK_13->setItem(0,0,new QTableWidgetItem(xy.at(81)));
                ui->SHEDULE_CHECK_13->setItem(1,0,new QTableWidgetItem("J7"));
                ui->Ticket_P->setText("J7");ui->CLASS_P->setText("ECONOMY");BOOKKING=Flight_choice+"J7";
                ui->SHEDULE_CHECK_13->setItem(2,0,new QTableWidgetItem(FRoOM_D.at(inh)));
                ui->SHEDULE_CHECK_13->setItem(3,0,new QTableWidgetItem(TO_oD.at(inh)));
                ui->SHEDULE_CHECK_13->setItem(4,0,new QTableWidgetItem(xy.at(86)));
                ui->stackedWidget->setCurrentIndex(23);
            }
            else
            {
                QMessageBox :: warning(this,"Ticket","NOT AVAILABLE!");
            }
    }
    ree.close();
}


void MainWindow::on_J_8_clicked()
{
    QVector<QString>xy;
    QVector<QString>FRoOM_D,TO_oD,S_DATE_oD,S_SRNO_oD,STRT_TIME_oD,END_TIME_oD,DAY;

    QFile ree(Flight_choice);
    if(ree.open(QIODevice::ReadOnly))
    {
            QTextStream stream(&ree);
            while ( stream.atEnd()==false)
            {
                xy.push_back(stream.readLine());
            }
            if(xy.at(73)=="nonbooked")
            {

                QFile Fiiile("FLIGHT.txt");
                if(Fiiile.open(QIODevice::ReadOnly))
                {
                    QTextStream stream(&Fiiile);
                    while ( stream.atEnd()==false)
                    {
                        S_SRNO_oD.push_back(stream.readLine());
                        FRoOM_D.push_back(stream.readLine());
                        TO_oD.push_back(stream.readLine());
                        STRT_TIME_oD.push_back(stream.readLine());
                        END_TIME_oD.push_back(stream.readLine());
                        S_DATE_oD.push_back(stream.readLine());DAY.push_back(stream.readLine());
                    }
                }
                Fiiile.close();
                int inh = S_SRNO_oD.indexOf(Flight_choice);

                ui->SHEDULE_CHECK_13->setItem(0,0,new QTableWidgetItem(xy.at(81)));
                ui->SHEDULE_CHECK_13->setItem(1,0,new QTableWidgetItem("J8"));
                ui->Ticket_P->setText("J8");ui->CLASS_P->setText("ECONOMY");BOOKKING=Flight_choice+"J8";
                ui->SHEDULE_CHECK_13->setItem(2,0,new QTableWidgetItem(FRoOM_D.at(inh)));
                ui->SHEDULE_CHECK_13->setItem(3,0,new QTableWidgetItem(TO_oD.at(inh)));
                ui->SHEDULE_CHECK_13->setItem(4,0,new QTableWidgetItem(xy.at(86)));
                ui->stackedWidget->setCurrentIndex(23);
            }
            else
            {
                QMessageBox :: warning(this,"Ticket","NOT AVAILABLE!");
            }
    }
    ree.close();
}


void MainWindow::on_J_9_clicked()
{
    QVector<QString>xy;
    QVector<QString>FRoOM_D,TO_oD,S_DATE_oD,S_SRNO_oD,STRT_TIME_oD,END_TIME_oD,DAY;

    QFile ree(Flight_choice);
    if(ree.open(QIODevice::ReadOnly))
    {
            QTextStream stream(&ree);
            while ( stream.atEnd()==false)
            {
                xy.push_back(stream.readLine());
            }
            if(xy.at(74)=="nonbooked")
            {

                QFile Fiiile("FLIGHT.txt");
                if(Fiiile.open(QIODevice::ReadOnly))
                {
                    QTextStream stream(&Fiiile);
                    while ( stream.atEnd()==false)
                    {
                        S_SRNO_oD.push_back(stream.readLine());
                        FRoOM_D.push_back(stream.readLine());
                        TO_oD.push_back(stream.readLine());
                        STRT_TIME_oD.push_back(stream.readLine());
                        END_TIME_oD.push_back(stream.readLine());
                        S_DATE_oD.push_back(stream.readLine());DAY.push_back(stream.readLine());
                    }
                }
                Fiiile.close();
                int inh = S_SRNO_oD.indexOf(Flight_choice);

                ui->SHEDULE_CHECK_13->setItem(0,0,new QTableWidgetItem(xy.at(81)));
                ui->SHEDULE_CHECK_13->setItem(1,0,new QTableWidgetItem("J9"));
                ui->Ticket_P->setText("J9");ui->CLASS_P->setText("ECONOMY");BOOKKING=Flight_choice+"J9";
                ui->SHEDULE_CHECK_13->setItem(2,0,new QTableWidgetItem(FRoOM_D.at(inh)));
                ui->SHEDULE_CHECK_13->setItem(3,0,new QTableWidgetItem(TO_oD.at(inh)));
                ui->SHEDULE_CHECK_13->setItem(4,0,new QTableWidgetItem(xy.at(86)));
                ui->stackedWidget->setCurrentIndex(23);
            }
            else
            {
                QMessageBox :: warning(this,"Ticket","NOT AVAILABLE!");
            }
    }
    ree.close();
}


void MainWindow::on_BKASH_2_clicked()
{
    QMessageBox :: warning(this,"ROCKET","TEMPORARY UNAVAILABLE! USE BKASH.");
}


void MainWindow::on_pushButton_64_clicked()
{

    QMessageBox :: warning(this,"NOGOD","TEMPORARY UNAVAILABLE! USE BKASH.");
}


void MainWindow::on_a1_clicked()
{

}

void MainWindow::on_pushButton_72_clicked()
{
    QString ADD_EM;
    ADD_EM= ui->comboBox_2->currentText();
    if(ADD_EM=="FLIGHT MODEL"){ui->textBrowser_167->setText("ENTER NEW FLIGHT MODEL");opener="MODEL";}
    else if(ADD_EM=="PAILOT"){ui->textBrowser_167->setText("ENTER PAILOT NAME");opener="PAILOT";}
    else if(ADD_EM=="EMPLY0EE"){ui->textBrowser_167->setText("ENTER NEW EMPLOYEE NAME");opener="WORKER";}
    else if(ADD_EM=="BOOTH"){ui->textBrowser_167->setText("ENTER NEW BOOTH NAME");opener="BOOTH";}

    ui->stackedWidget->setCurrentIndex(28);
}


void MainWindow::on_pushButton_29_clicked()
{
    ui->stackedWidget->setCurrentIndex(27);
}


void MainWindow::on_pushButton_73_clicked()
{

    if(ui->lineEdit_4-> text()=='\0')
    {
            QMessageBox :: warning(this,"NAME","NAME IS BLANK!");
    }
    else if(ui->lineEdit_5-> text()=='\0' && opener!="MODEL")
    {
            QMessageBox :: warning(this,"PASSWORD","PASSWORD IS BLANK!");
    }
    else
    {
            QFile Ffile(opener);
            if(Ffile.open(QIODevice::Append | QIODevice::ReadWrite))
            {
                QTextStream stream(&Ffile);
                stream<< ui->lineEdit_4-> text() + "\n";
                if(opener!="MODEL"){
                    stream<< ui->lineEdit_5-> text() + "\n";
                }
            }
            Ffile.close();
            ui->stackedWidget->setCurrentIndex(9);
    }
    ui->lineEdit_4-> clear();
    ui->lineEdit_5->clear();


}



void MainWindow::on_pushButton_74_clicked()
{
    ui->stackedWidget->setCurrentIndex(9);
}


void MainWindow::on_pushButton_75_clicked()
{
    QString WORKER_ID,WORKER_PASS,WORKER_TYPE;int milce;
    QVector<QString> pass,pass_id;
    if(ui->ID_WORKER->text()!='\0')
    {
            if(ui->PASS_WORKER->text()!='\0')
            {
                //QString WORKER_ID,WORKER_PASS,WORKER_TYPE;
                WORKER_TYPE=ui->comboBox_3->currentText();
                WORKER_ID=ui->ID_WORKER->text();
                WORKER_PASS=ui->PASS_WORKER->text();

                QFile Ffoile(WORKER_TYPE);
                if(Ffoile.open(QIODevice::ReadOnly))
                {
                    QTextStream stream(&Ffoile);
                    while ( stream.atEnd()==false)
                    {
                        pass_id.push_back(stream.readLine());
                        pass.push_back(stream.readLine());
                    }

                }
                Ffoile.close();
                milce = pass_id.indexOf(WORKER_ID);
                if(milce!= -1 )
                {
                    if(WORKER_PASS==pass.at(milce))
                    {
                        if(WORKER_TYPE=="BOOTH")
                        {


                            ui->stackedWidget->setCurrentIndex(32);



                        }

                    }

                }
                else
                {
                    QMessageBox :: warning(this,"File","ID NOT FOUND,CONTACT ADMIN!");
                }

            }
            else
            {
                QMessageBox :: warning(this,"PASSWORD","PASSWORD IS BLANK!");
            }
    }
    else
    {
            QMessageBox :: warning(this,"ID","ID IS BLANK!");
    }
    ui->ID_WORKER->clear();
    ui->PASS_WORKER->clear();

}


void MainWindow::on_pushButton_76_clicked()
{
    QFile details(ui->BOOKING_ID->text());
    if(details.open(QIODevice::WriteOnly))
    {
            QTextStream stream(&details);
            stream<<ui->NAME_P->text()+"\n";
            stream<<ui->Ticket_P->text()+"\n";
            stream<<ui->FROM_T->text()+"\n";
            stream<<ui->TO_T->text()+"\n";
            stream<<ui->FLIGHT_NO_P->text()+"\n";
            stream<<ui->DATE_P->text()+"\n";
            stream<<ui->CLASS_P->text()+"\n";
            stream<<ui->DEPART_TIME->text()+"\n";
            stream<<ui->BOOKING_ID->text()+"\n";
    }
    details.close();
    ui->stackedWidget->setCurrentIndex(6);
}


void MainWindow::on_pushButton_77_clicked()
{
    int p=1;
    QString ID_DONE,offline_name,offline_seat,offline_from,offline_to,offline_flight;
    QString offline_date,offline_class,offline_time,offline_booking;
    ID_DONE=ui->BOOKING_ID_S->text();
    if(ID_DONE!='\0')
    {

            QFile TICKET_OFFLINE(ID_DONE);
            if(TICKET_OFFLINE.open(QIODevice:: ReadOnly))
            {
                QTextStream stream(&TICKET_OFFLINE);

                while(stream.atEnd()==false)
                {
                    offline_name=stream.readLine();
                    offline_seat=stream.readLine();
                    offline_from=stream.readLine();
                    offline_to=stream.readLine();
                    offline_flight=stream.readLine();
                    offline_date=stream.readLine();
                    offline_class=stream.readLine();
                    offline_time=stream.readLine();
                    offline_booking=stream.readLine();
                }

            }
            else p=0;

            TICKET_OFFLINE.close();
            if(p==1){
            ui->NAME_CUSTOMER->setText(offline_name);
            ui->NAME_CUSTOMER_2->setText(offline_name);
            ui->SEAT_CUSTOMER->setText(offline_seat);
            ui->SEAT_CUSTOMER_2->setText(offline_seat);
            ui->FROM_CUSTOMER->setText(offline_from);
            ui->FROM_CUSTOMER_2->setText(offline_from);
            ui->TO_CUSTOMER->setText(offline_to);
            ui->TO_CUSTOMER_2->setText(offline_to);
            ui->FLIGHT_CUSTOMER->setText(offline_flight);
            ui->FLIGHT_CUSTOMER_2->setText(offline_flight);
            ui->DATE_CUSTOMER->setText(offline_date);
            ui->DATE_CUSTOMER_2->setText(offline_date);
            ui->CLASS_CUSTOMER_3->setText(offline_class);
            ui->CLASS_CUSTOMER_2->setText(offline_class);
            ui->BOARDING_CUSTOMER->setText(offline_time);
            //ui->NAME_CUSTOMER_2->setText(offline_name);
            ui->BOKKING_CUSTOMER->setText(offline_booking);
            ui->BOKKING_CUSTOMER_2->setText(offline_booking);
            ui->stackedWidget->setCurrentIndex(31);}
            else  QMessageBox :: warning(this,"ID","ID IS NOT FOUND!");

    }
    else
    {
            QMessageBox :: warning(this,"ID","ID IS BLANK!");
    }
}


void MainWindow::on_pushButton_79_clicked()
{
    ui->stackedWidget->setCurrentIndex(6);
}


void MainWindow::on_pushButton_78_clicked()
{
    QPrinter printer;
    QPrintDialog dialog(&printer,this);
    dialog.setWindowTitle("Print Ticket");
    //dialog.addEnabledOption()
    //if(ui->page_56->)
    if(dialog.exec() != QDialog::Accepted)
    {
            return;
    }
    //ui->page_56->setCursor(QItemSelection::select(QPageLayout))->print();
}


void MainWindow::on_pushButton_80_clicked()
{
    QVector<QString >offline_flight,offline_booking_id;
    QFile TICKET_O(login_user_id);
    int i=0;
    if(TICKET_O.open(QIODevice:: ReadOnly))
    {
            QTextStream stream(&TICKET_O);

            while(stream.atEnd()==false)
            {
                offline_flight.push_back(stream.readLine());
                offline_booking_id.push_back(stream.readLine());
                i++;
            }

    }

    TICKET_O.close();
    ui->SHEDULE_CHECK_15->setRowCount(i);
    for(int j=0;j<i;j++)
    {
            ui->SHEDULE_CHECK_15->setItem(j,0,new QTableWidgetItem(offline_booking_id.at(j)));
            ui->SHEDULE_CHECK_16->addItem(offline_booking_id.at(j));
    }
    ui->stackedWidget->setCurrentIndex(33);

}


void MainWindow::on_pushButton_81_clicked()
{
    QString Target_worker,changed_worker;
    Target_worker=ui->comboBox_5->currentText();
    changed_worker=ui->comboBox_7->currentText();
    QVector<QString>set_new;
    QString flight_er;
    flight_er= ui->comboBox_6->currentText();
    QFile PORED(flight_er);
    if(PORED.open(QIODevice::ReadOnly))
    {
            QTextStream stream(&PORED);
            while(stream.atEnd()==false)
            {
                set_new.push_back(stream.readLine());
            }
    }
    PORED.close();
    int jh;
    jh=set_new.indexOf(changed_worker);
    //set_new.at(jh)=Target_worker;
    QFile PRED(flight_er);
    if(PRED.open(QIODevice::WriteOnly))
    {
            QTextStream stream(&PRED);
            for(int x=0;x<set_new.size();x++)
            {
                if(x==jh)
                {
                    stream<<Target_worker+"\n";
                }
                else{
                    stream<<set_new.at(x)+"\n";}
            }
    }
    PRED.close();
    ui->stackedWidget->setCurrentIndex(4);




}


void MainWindow::on_pushButton_82_clicked()
{
    QVector<QString >_booking_id,bookin;

    QString TARGET;
    TARGET=ui->SHEDULE_CHECK_16->currentText();
    QFile TICKT_O(TARGET);
    if(TICKT_O.open(QIODevice:: ReadOnly))
    {
            QTextStream stream(&TICKT_O);

            while(stream.atEnd()==false)
            {
                _booking_id.push_back(stream.readLine());
            }

    }
    TICKT_O.close();
    ui->SHEDULE_CHECK_17->setItem(0,0,new QTableWidgetItem(_booking_id.at(8)));
    ui->SHEDULE_CHECK_17->setItem(1,0,new QTableWidgetItem(_booking_id.at(0)));
    ui->SHEDULE_CHECK_17->setItem(2,0,new QTableWidgetItem(_booking_id.at(4)));
    ui->SHEDULE_CHECK_17->setItem(3,0,new QTableWidgetItem(_booking_id.at(2)));
    ui->SHEDULE_CHECK_17->setItem(4,0,new QTableWidgetItem(_booking_id.at(3)));
    ui->SHEDULE_CHECK_17->setItem(5,0,new QTableWidgetItem(_booking_id.at(1)));
    ui->SHEDULE_CHECK_17->setItem(6,0,new QTableWidgetItem(_booking_id.at(6)));
    ui->SHEDULE_CHECK_17->setItem(7,0,new QTableWidgetItem(_booking_id.at(5)));
    ui->SHEDULE_CHECK_17->setItem(8,0,new QTableWidgetItem(_booking_id.at(7)));

    QFile TICK_O(_booking_id.at(4));
    if(TICK_O.open(QIODevice:: ReadOnly))
    {
            QTextStream stream(&TICK_O);
                bookin.push_back(stream.readLine());

    }
    TICK_O.close();

    ui->SHEDULE_CHECK_17->setItem(9,0,new QTableWidgetItem(bookin.at(0)));


    ui->stackedWidget->setCurrentIndex(34);
}


void MainWindow::on_FLIGHT_SETTINGS_5_clicked()
{
    ui->stackedWidget->setCurrentIndex(3);
}


void MainWindow::on_comboBox_4_currentIndexChanged(int index)
{
    ui->comboBox_5->clear();
    ui->comboBox_7->clear();


    QVector <QString> main_lis,side_lis;
    QString change;
    change = ui->comboBox_4->currentText();
    if(change=="PAILOT" | change=="WORKER"){
    int o=0;
    QFile PORTed(change);
    if(PORTed.open(QIODevice::ReadOnly))
    {
                QTextStream stream(&PORTed);
                while(stream.atEnd()==false)
                {
                main_lis.push_back(stream.readLine());
                side_lis.push_back(stream.readLine());
                o++;
                }
    }
    PORTed.close();
    for(int kj=0;kj<o;kj++)
    {
                ui->comboBox_5->addItem(main_lis.at(kj));
    }
    if(change=="PAILOT"){
                ui->comboBox_7->addItem(mai_is.at(82));
                ui->comboBox_7->addItem(mai_is.at(83));
    }
    else
    {
                ui->comboBox_7->addItem(mai_is.at(77));
                ui->comboBox_7->addItem(mai_is.at(78));
                ui->comboBox_7->addItem(mai_is.at(79));
                ui->comboBox_7->addItem(mai_is.at(80));
    }
    }

    else {
    int o=0;
    QFile PORTEd(change);
    if(PORTEd.open(QIODevice::ReadOnly))
    {
                QTextStream stream(&PORTEd);
                while(stream.atEnd()==false)
                {
                main_lis.push_back(stream.readLine());
                //side_list.push_back(stream.readLine());
                o++;
                }
    }
    PORTEd.close();
    for(int kj=0;kj<o;kj++)
    {
                ui->comboBox_5->addItem(main_lis.at(kj));
    }

    ui->comboBox_7->addItem(mai_is.at(81));

    }


}


void MainWindow::on_pushButton_30_clicked()
{
    ui->stackedWidget->setCurrentIndex(4);
}


void MainWindow::on_DONE_SET_PAS_BTN_5_clicked()
{
    ui->comboBox_6->clear();
    QVector<QString> mai_lis;


        int o=0;
    QFile PORTEd("flight_id.txt");
    if(PORTEd.open(QIODevice::ReadOnly))
    {
    QTextStream stream(&PORTEd);
    while(stream.atEnd()==false)
    {
                mai_lis.push_back(stream.readLine());
                //side_list.push_back(stream.readLine());
                o++;
    }
    }
    PORTEd.close();
    for(int kj=0;kj<o;kj++)
    {
    ui->comboBox_6->addItem(mai_lis.at(kj));
    }
    ui->stackedWidget->setCurrentIndex(35);

}


void MainWindow::on_comboBox_6_currentIndexChanged(int index)
{
    ui->comboBox_7->clear();
    mai_is.clear();
    QString flight_er;
    flight_er= ui->comboBox_6->currentText();
    QFile PORTED(flight_er);
    if(PORTED.open(QIODevice::ReadOnly))
    {
    QTextStream stream(&PORTED);
    while(stream.atEnd()==false)
    {
                mai_is.push_back(stream.readLine());
    }
    }
    PORTED.close();

}


void MainWindow::on_DONE_SET_PAS_BTN_8_clicked()
{
    ui->comboBox_8->clear();
    QVector<QString> mai_lis;


    int o=0;
    QFile PORTEd("flight_id.txt");
    if(PORTEd.open(QIODevice::ReadOnly))
    {
    QTextStream stream(&PORTEd);
    while(stream.atEnd()==false)
    {
                mai_lis.push_back(stream.readLine());
                //side_list.push_back(stream.readLine());
                o++;
    }
    }
    PORTEd.close();
    for(int kj=0;kj<o;kj++)
    {
    ui->comboBox_8->addItem(mai_lis.at(kj));
    }
    ui->stackedWidget->setCurrentIndex(36);
}


void MainWindow::on_comboBox_8_currentIndexChanged(int index)
{
    //ui->comboBox_8->clear();
    //mai_is.clear();
    QVector<QString> mai_i;
    QString flight_er;
    flight_er= ui->comboBox_8->currentText();
    QFile PORTED(flight_er);
    if(PORTED.open(QIODevice::ReadOnly))
    {
    QTextStream stream(&PORTED);
    while(stream.atEnd()==false)
    {
                mai_i.push_back(stream.readLine());
    }
    }
    PORTED.close();
    ui->textBrowser_180->setText(mai_i.at(0));
}


void MainWindow::on_pushButton_83_clicked()
{
    QVector<QString> mai_i;
    QString flight_er;
    flight_er= ui->comboBox_8->currentText();
    QFile PORTED(flight_er);
    if(PORTED.open(QIODevice::ReadOnly))
    {
    QTextStream stream(&PORTED);
    while(stream.atEnd()==false)
    {
                mai_i.push_back(stream.readLine());
    }
    }
    PORTED.close();
    QFile POTED(flight_er);
    if(POTED.open(QIODevice::WriteOnly))
    {
    QTextStream stream(&POTED);
    if(mai_i.at(0)=="OPENED"){stream<<"CLOSED\n";ui->textBrowser_180->setText("CLOSED");}
    else {stream<<"OPENED\n";ui->textBrowser_180->setText("OPENED");}
    for(int o=1;o<mai_i.size();o++)
    {
                stream<<mai_i.at(o)+"\n";
    }
    }
    POTED.close();


}


void MainWindow::on_pushButton_84_clicked()
{
    ui->stackedWidget->setCurrentIndex(20);
}


void MainWindow::on_pushButton_85_clicked()
{
    ui->stackedWidget->setCurrentIndex(6);
}


void MainWindow::on_pushButton_87_clicked()
{
    ui->stackedWidget->setCurrentIndex(6);
}


void MainWindow::on_pushButton_86_clicked()
{
    ui->stackedWidget->setCurrentIndex(27);
}


void MainWindow::on_pushButton_88_clicked()
{
       ui->stackedWidget->setCurrentIndex(6);
}


void MainWindow::on_pushButton_89_clicked()
{
    ui->SHEDULE_CHECK_16->clear();
    ui->stackedWidget->setCurrentIndex(5);
}


void MainWindow::on_pushButton_90_clicked()
{
     ui->stackedWidget->setCurrentIndex(33);
}


void MainWindow::on_pushButton_91_clicked()
{
    ui->stackedWidget->setCurrentIndex(4);
}


void MainWindow::on_pushButton_93_clicked()
{
    ui->stackedWidget->setCurrentIndex(4);
}


void MainWindow::on_comboBox_9_currentIndexChanged(int index)
{
    QVector<QString> mai_i;
    QString flight_er;
    flight_er= ui->comboBox_9->currentText();
    QFile PORTED("FLIGHT.txt");
    if(PORTED.open(QIODevice::ReadOnly))
    {
    QTextStream stream(&PORTED);
    while(stream.atEnd()==false)
    {
                mai_i.push_back(stream.readLine());
    }
    }
    PORTED.close();
    int k=mai_i.indexOf(flight_er);
    ui->textBrowser_183->setText(mai_i.at(k+5));
}


void MainWindow::on_pushButton_92_clicked()
{
    QString l;
    l=ui->dateEdit_2->text();
    QVector<QString> maii;
    QString flight_er;
    flight_er= ui->comboBox_9->currentText();
    QFile PORTED("FLIGHT.txt");
    if(PORTED.open(QIODevice::ReadOnly))
    {
    QTextStream stream(&PORTED);
    while(stream.atEnd()==false)
    {
                maii.push_back(stream.readLine());

    }
    }
    PORTED.close();
    int k=maii.indexOf(flight_er);
    k=k+5;

    QFile PORED("FLIGHT.txt");
    if(PORED.open(QIODevice::WriteOnly))
    {
    QTextStream stream(&PORED);
    for(int h=0;h<maii.size();h++)
    {
                if(h==k){stream<<l+"\n";}
                else { stream<<maii.at(h)+"\n";}
    }
    }

    PORED.close();
    ui->stackedWidget->setCurrentIndex(4);
}


void MainWindow::on_pushButton_95_clicked()
{
    QString comment_flight,comment_worker_type,comment_worker,comment;
    comment_flight=ui->SHEDULE_CHECK_19->currentText();
    comment_worker_type=ui->SHEDULE_CHECK_20->currentText();
    comment_worker=ui->SHEDULE_CHECK_21->currentText();
    comment=ui->lineEdit_6->text();
    QFile PORED("COMMENT.txt");
    if(PORED.open(QIODevice::Append | QIODevice::WriteOnly))
    {
    QTextStream stream(&PORED);
    stream<< comment_flight+"\n";
    stream << comment_worker_type+"\n";
    stream << comment_worker+"\n";
    stream << comment+"\n";
    stream << "uncheaked!\n";
    }

    PORED.close();

    ui->stackedWidget->setCurrentIndex(5);
}


void MainWindow::on_pushButton_94_clicked()
{

    QFile TICKET_O(login_user_id);
    int i=0;
    if(TICKET_O.open(QIODevice:: ReadOnly))
    {
    QTextStream stream(&TICKET_O);

    while(stream.atEnd()==false)
    {
                line_flight.push_back(stream.readLine());
                line_booking_id.push_back(stream.readLine());
                i++;
    }

    }

    TICKET_O.close();
    for(int j=0;j<i;j++)
    {
    ui->SHEDULE_CHECK_19->addItem(line_booking_id.at(j));
    }
    ui->stackedWidget->setCurrentIndex(38);
}



void MainWindow::on_SHEDULE_CHECK_20_currentIndexChanged(int index)
{
    int jh=line_booking_id.indexOf(ui->SHEDULE_CHECK_19->currentText());
    QVector<QString>asad;
    QFile TICKET_O(line_flight.at(jh));
    if(TICKET_O.open(QIODevice:: ReadOnly))
    {
    QTextStream stream(&TICKET_O);

    while(stream.atEnd()==false)
    {
                asad.push_back(stream.readLine());
    }

    }

    TICKET_O.close();

    QVector<QString>asadad;
    QFile TICET_O(asad.at(4));
    if(TICET_O.open(QIODevice:: ReadOnly))
    {
    QTextStream stream(&TICET_O);

    while(stream.atEnd()==false)
    {
                asadad.push_back(stream.readLine());
    }

    }

    TICET_O.close();



    if(index==0){
    ui->SHEDULE_CHECK_21->clear();
    ui->SHEDULE_CHECK_21->addItem(asad.at(4));

    }
    else if(index==1){
    ui->SHEDULE_CHECK_21->clear();
    ui->SHEDULE_CHECK_21->addItem(asad.at(81));

    }
    else if(index==2){
    ui->SHEDULE_CHECK_21->clear();
    ui->SHEDULE_CHECK_21->addItem(asad.at(82));
    ui->SHEDULE_CHECK_21->addItem(asad.at(83));

    }
    else if(index==3){
    ui->SHEDULE_CHECK_21->clear();
    ui->SHEDULE_CHECK_21->addItem(asad.at(77));
    ui->SHEDULE_CHECK_21->addItem(asad.at(78));
    ui->SHEDULE_CHECK_21->addItem(asad.at(79));
    ui->SHEDULE_CHECK_21->addItem(asad.at(80));

    }
}


void MainWindow::on_pushButton_104_clicked()
{
    ui->stackedWidget->setCurrentIndex(29);
}


void MainWindow::on_pushButton_103_clicked()
{

    ui->stackedWidget->setCurrentIndex(41);
}


void MainWindow::on_pushButton_102_clicked()
{
    ui->stackedWidget->setCurrentIndex(40);
}


void MainWindow::on_pushButton_100_clicked()
{
    QString WORKER_ID,WORKER_pass;
    QVector<QString> data__of__worker;

    QVector<QString>worker,worker_pass;

    QString file="WORKER";

    WORKER_ID= ui->lineEdit_9->text();
    WORKER_pass=ui->lineEdit_10->text();

    QFile manage_ker(file);
    if(manage_ker.open(QIODevice:: ReadOnly))
    {
    QTextStream stream(&manage_ker);

    while(stream.atEnd()==false)
    {
                worker.push_back(stream.readLine());
                worker_pass.push_back(stream.readLine());
    }

    }

    manage_ker.close();
    int target =worker.indexOf(WORKER_ID);
    if(target != -1){
    if(WORKER_ID==worker.at(target))
    {

                if(WORKER_pass==worker_pass.at(target))
                {

                LOCAL=WORKER_ID;

                QFile data_of_worker(WORKER_ID);
                if(data_of_worker.open(QIODevice:: ReadOnly))
                {
                        QTextStream stream(&data_of_worker);

                        while(stream.atEnd()==false)
                        {
                            data__of__worker.push_back(stream.readLine());
                        }

                }

                data_of_worker.close();

                QVector<QString>name,frm,to,s_time,e_time,day,date;

                QFile data_of("FLIGHT.txt");
                if(data_of.open(QIODevice:: ReadOnly))
                {
                        QTextStream stream(&data_of);

                        while(stream.atEnd()==false)
                        {
                            name.push_back(stream.readLine());
                            frm.push_back(stream.readLine());
                            to.push_back(stream.readLine());
                            s_time.push_back(stream.readLine());
                            e_time.push_back(stream.readLine());
                            date.push_back(stream.readLine());
                            day.push_back(stream.readLine());
                        }

                }

                data_of.close();

                int kl=data__of__worker.size();
                ui->SHEDULE_CHECK_14->setRowCount(kl);




                for(int im=0;im<kl;im++)
                {
                        int h=name.indexOf(data__of__worker.at(im));
                        ui->SHEDULE_CHECK_14->setItem(im,0,new QTableWidgetItem(name.at(h)));
                        ui->SHEDULE_CHECK_14->setItem(im,1,new QTableWidgetItem(frm.at(h)));
                        ui->SHEDULE_CHECK_14->setItem(im,2,new QTableWidgetItem(to.at(h)));
                        ui->SHEDULE_CHECK_14->setItem(im,3,new QTableWidgetItem(s_time.at(h)));
                        ui->SHEDULE_CHECK_14->setItem(im,4,new QTableWidgetItem(e_time.at(h)));
                        ui->SHEDULE_CHECK_14->setItem(im,5,new QTableWidgetItem(date.at(h)));
                        ui->SHEDULE_CHECK_14->setItem(im,6,new QTableWidgetItem(day.at(h)));

                }





                ui->stackedWidget->setCurrentIndex(30);
                }
    }
    }
 }



void MainWindow::on_pushButton_101_clicked()
{
    QString WORKER_ID,WORKER_pass;
    QVector<QString> data__of__worker;

    QVector<QString>worker,worker_pass;

    QString file="PAILOT";

    WORKER_ID= ui->lineEdit_7->text();
    WORKER_pass=ui->lineEdit_8->text();

    QFile manage_ker(file);
    if(manage_ker.open(QIODevice:: ReadOnly))
    {
    QTextStream stream(&manage_ker);

    while(stream.atEnd()==false)
    {
                worker.push_back(stream.readLine());
                worker_pass.push_back(stream.readLine());
    }

    }

    manage_ker.close();
    int target =worker.indexOf(WORKER_ID);
    if(target != -1){
    if(WORKER_ID==worker.at(target))
    {

                if(WORKER_pass==worker_pass.at(target))
                {
                LOCAL=WORKER_ID;

                QFile data_of_worker(WORKER_ID);
                if(data_of_worker.open(QIODevice:: ReadOnly))
                {
                        QTextStream stream(&data_of_worker);

                        while(stream.atEnd()==false)
                        {
                            data__of__worker.push_back(stream.readLine());
                        }

                }

                data_of_worker.close();

                QVector<QString>name,frm,to,s_time,e_time,day,date;

                QFile data_of("FLIGHT.txt");
                if(data_of.open(QIODevice:: ReadOnly))
                {
                        QTextStream stream(&data_of);

                        while(stream.atEnd()==false)
                        {
                            name.push_back(stream.readLine());
                            frm.push_back(stream.readLine());
                            to.push_back(stream.readLine());
                            s_time.push_back(stream.readLine());
                            e_time.push_back(stream.readLine());
                            date.push_back(stream.readLine());
                            day.push_back(stream.readLine());
                        }

                }

                data_of.close();

                int kl=data__of__worker.size();
                ui->SHEDULE_CHECK_14->setRowCount(kl);




                for(int im=0;im<kl;im++)
                {
                        int h=name.indexOf(data__of__worker.at(im));
                        ui->SHEDULE_CHECK_14->setItem(im,0,new QTableWidgetItem(name.at(h)));
                        ui->SHEDULE_CHECK_14->setItem(im,1,new QTableWidgetItem(frm.at(h)));
                        ui->SHEDULE_CHECK_14->setItem(im,2,new QTableWidgetItem(to.at(h)));
                        ui->SHEDULE_CHECK_14->setItem(im,3,new QTableWidgetItem(s_time.at(h)));
                        ui->SHEDULE_CHECK_14->setItem(im,4,new QTableWidgetItem(e_time.at(h)));
                        ui->SHEDULE_CHECK_14->setItem(im,5,new QTableWidgetItem(date.at(h)));
                        ui->SHEDULE_CHECK_14->setItem(im,6,new QTableWidgetItem(day.at(h)));

                }





                ui->stackedWidget->setCurrentIndex(30);
                }
    }
    }
}


void MainWindow::on_pushButton_96_clicked()
{
    QVector<QString>name,frm,to,s_time,e_time;
    QString DATA;
    int nk=0,l=0;
    QFile data_of("COMMENT.txt");
    if(data_of.open(QIODevice:: ReadOnly))
    {
    QTextStream stream(&data_of);

    while(stream.atEnd()==false)
    {
                name.push_back(stream.readLine());
                frm.push_back(stream.readLine());
                DATA=stream.readLine();
                if(DATA==LOCAL){nk++;}
                to.push_back(DATA);
                s_time.push_back(stream.readLine());
                e_time.push_back(stream.readLine());
                l++;
    }

    }

    data_of.close();


    ui->SHEDULE_CHECK_18->setRowCount(nk);

    int u=0;


    for(int im=0;im<l;im++)
    {

    if(LOCAL==to.at(im)){

    ui->SHEDULE_CHECK_18->setItem(u,0,new QTableWidgetItem(name.at(im)));
    ui->SHEDULE_CHECK_18->setItem(u,1,new QTableWidgetItem(frm.at(im)));
    ui->SHEDULE_CHECK_18->setItem(u,2,new QTableWidgetItem(to.at(im)));
    ui->SHEDULE_CHECK_18->setItem(u,4,new QTableWidgetItem(s_time.at(im)));
    ui->SHEDULE_CHECK_18->setItem(u,3,new QTableWidgetItem(e_time.at(im)));u++;
    }

    }


    back="WORKER";
    ui->stackedWidget->setCurrentIndex(39);
}


void MainWindow::on_pushButton_98_clicked()
{
    QVector<QString>name,frm,to,s_time,e_time;
    QString DATA;
    QFile data_of("COMMENT.txt");
    if(data_of.open(QIODevice:: ReadOnly))
    {
    QTextStream stream(&data_of);

    while(stream.atEnd()==false)
    {
    name.push_back(stream.readLine());
    frm.push_back(stream.readLine());
    DATA=stream.readLine();
    to.push_back(DATA);

    s_time.push_back(stream.readLine());
    e_time.push_back(stream.readLine());
    }

    }

    data_of.close();


    ui->SHEDULE_CHECK_18->setRowCount(to.size());




    for(int im=0;im<to.size();im++)
    {
    ui->SHEDULE_CHECK_18->setItem(im,0,new QTableWidgetItem(name.at(im)));
    ui->SHEDULE_CHECK_18->setItem(im,1,new QTableWidgetItem(frm.at(im)));
    ui->SHEDULE_CHECK_18->setItem(im,2,new QTableWidgetItem(to.at(im)));
    ui->SHEDULE_CHECK_18->setItem(im,4,new QTableWidgetItem(s_time.at(im)));
    ui->SHEDULE_CHECK_18->setItem(im,3,new QTableWidgetItem(e_time.at(im)));

    }


    ui->stackedWidget->setCurrentIndex(39);
    back="ADMIN";
}


void MainWindow::on_pushButton_106_clicked()
{
    ui->stackedWidget->setCurrentIndex(42);
}


void MainWindow::on_pushButton_105_clicked()
{
    ui->stackedWidget->setCurrentIndex(42);
}


void MainWindow::on_pushButton_107_clicked()
{
    ui->stackedWidget->setCurrentIndex(6);
}


void MainWindow::on_pushButton_108_clicked()
{
    QVector<QString>name,frm,to,s_time,e_time;
    QString DATA;int mk=0;
    QFile data_of("COMMENT.txt");
    if(data_of.open(QIODevice:: ReadOnly))
    {
    QTextStream stream(&data_of);

    while(stream.atEnd()==false)
    {
    name.push_back(stream.readLine());
    frm.push_back(stream.readLine());
    to.push_back(stream.readLine());
    s_time.push_back(stream.readLine());
    DATA=stream.readLine();
    if(DATA=="uncheaked!"){mk++;}
    e_time.push_back(DATA);
    }

    }

    data_of.close();


    ui->SHEDULE_CHECK_18->setRowCount(mk);


    int l=0;

    for(int im=0;im<to.size();im++)
    {
    if(e_time.at(im)=="uncheaked!"){
    ui->SHEDULE_CHECK_18->setItem(l,0,new QTableWidgetItem(name.at(im)));
    ui->SHEDULE_CHECK_18->setItem(l,1,new QTableWidgetItem(frm.at(im)));
    ui->SHEDULE_CHECK_18->setItem(l,2,new QTableWidgetItem(to.at(im)));
    ui->SHEDULE_CHECK_18->setItem(l,4,new QTableWidgetItem(s_time.at(im)));
    ui->SHEDULE_CHECK_18->setItem(l,3,new QTableWidgetItem(e_time.at(im)));l++;
    }

    }

    back="ADMIN";
    ui->stackedWidget->setCurrentIndex(39);
}


void MainWindow::on_pushButton_97_clicked()
{
    if(back=="ADMIN"){ui->stackedWidget->setCurrentIndex(9);}
    else if(back=="WORKER"){

    QVector<QString>name,frm,to,s_time,e_time;
    QString DATA;
    int nk=0,l=0;
    QFile data_of("COMMENT.txt");
    if(data_of.open(QIODevice:: ReadOnly))
    {
    QTextStream stream(&data_of);

    while(stream.atEnd()==false)
    {
                name.push_back(stream.readLine());
                frm.push_back(stream.readLine());
                to.push_back(stream.readLine());
                s_time.push_back(stream.readLine());
                e_time.push_back(stream.readLine());
                l++;
    }

    }

    data_of.close();
    QFile dataof("COMMENT.txt");
    if(dataof.open(QIODevice:: WriteOnly))
    {
    QTextStream stream(&dataof);

    for(int k=0;k<l;k++)
    {
                stream<<name.at(k)+"\n";
                stream<<frm.at(k)+"\n";
                stream<<to.at(k)+"\n";
                stream<<s_time.at(k)+"\n";
                if(to.at(k)==LOCAL){stream<<"cheacked!\n";}
                else{
                     stream<<e_time.at(k)+"\n";
                }

    }

    }

    dataof.close();



    if(DATA==LOCAL){nk++;}
    ui->stackedWidget->setCurrentIndex(30);}
}


void MainWindow::on_pushButton_99_clicked()
{
    QVector<QString>name,frm,to,s_time,e_time;
    QString DATA,DATA1;
    int mk=0,l=0;
    QFile data_of("COMMENT.txt");
    if(data_of.open(QIODevice:: ReadOnly))
    {
    QTextStream stream(&data_of);

    while(stream.atEnd()==false)
    {
    name.push_back(stream.readLine());
    frm.push_back(stream.readLine());
    DATA=stream.readLine();

    to.push_back(DATA);

    s_time.push_back(stream.readLine());
    DATA1=stream.readLine();
    e_time.push_back(DATA1);

    if(DATA==LOCAL){
                if(DATA1=="uncheaked!")
                {
                        mk++;
                        }
    }

    }
    }

    data_of.close();


    ui->SHEDULE_CHECK_18->setRowCount(mk);




    for(int im=0;im<to.size();im++)
    {
    if(to.at(im)==LOCAL){
    if(e_time.at(im)=="uncheaked!")
    {
                        ui->SHEDULE_CHECK_18->setItem(l,0,new QTableWidgetItem(name.at(im)));
                        ui->SHEDULE_CHECK_18->setItem(l,1,new QTableWidgetItem(frm.at(im)));
                        ui->SHEDULE_CHECK_18->setItem(l,2,new QTableWidgetItem(to.at(im)));
                        ui->SHEDULE_CHECK_18->setItem(l,4,new QTableWidgetItem(s_time.at(im)));
                        ui->SHEDULE_CHECK_18->setItem(l,3,new QTableWidgetItem(e_time.at(im)));l++;
    }
    }


    }


    ui->stackedWidget->setCurrentIndex(39);
    back="WORKER";
}



void MainWindow::on_pushButton_109_clicked()
{
    ui->stackedWidget->setCurrentIndex(5);
}

