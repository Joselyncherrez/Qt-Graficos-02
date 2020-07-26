/*Autor: Joselyn Chérrez
 *
 *PROGRAMACION ORIENTADA A OBJETOS
 *
 */

#include "principal.h"
#include "ui_principal.h"

#include <QPainter>
#include <QFileDialog>
#include <QMessageBox>
#include <QDebug>

Principal::Principal(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Principal)
{
    ui->setupUi(this);
    lienzo = QPixmap(500,500);
    this->dibujar();

    ui->outCuadro->setPixmap(lienzo);
}

Principal::~Principal()
{
    delete ui;

}

void Principal::dibujar()
{
    lienzo.fill(Qt::white);

    QPainter painter(&lienzo);
    mPainter = new QPainter(&lienzo);

    int x = 0;
    int y = 0;

    //Crear un pincel para los bordes
    QPen pincel;
    pincel.setWidth(5);
    pincel.setColor(Qt::blue);
    pincel.setJoinStyle(Qt::MiterJoin);

    // Establecer el pincel al "pintor"
    painter.setPen(pincel);

    //Dibujar primera barra
    painter.drawRect(x+50,y+50, 100,400);

    //Crear un objeto colorRelleno
    QColor colorRelleno(190,120,162);
    //Crear un objeto colorBorde
    QColor colorBorde(78,3,48);

    //Cambiar el color del pincel
    pincel.setColor(colorBorde);

    //Volver a establecer el pincel al"pintor"
    painter.setPen(pincel);
    //Establecer el colorRelleno al brush
    painter.setBrush(colorRelleno);

    //Dibujar segunda barra
    painter.drawRect(x+170,y+200,100,250);

    //Creando los color de la tercer barra
    QColor cRellenoBarra3(253,253,115);
    QColor cBordeBarra3(174,174,51);

    pincel.setColor(cBordeBarra3);
    painter.setPen(pincel);
    painter.setBrush(cRellenoBarra3);

    //Dibujar tercera barra
    painter.drawRect(x+290,y+350,100,100);

    //Creando color a la linea de coordenada
    QColor lineaCoordenada(255,112,102);
    pincel.setColor(lineaCoordenada);
    painter.setPen(pincel);

    y=0;
    x=30;

    //QPainter p;
    int num =100;


    for(int i =y;i<450;i +=50 ){

        painter.drawLine(x-5,i,x+5,i);
        QString linea=
        QString::number(num);
        num-=25;
        painter.drawText(x-20,i,linea);


    }
    //Dibuja linea vertical
    painter.drawLine(x,y-10,x,y+456);
    //Dibuja linea horizontal
    painter.drawLine(x+5,y+456,x+500,y+456);


}


void Principal::on_actionGuardar_triggered()
{
    QString nombreArchivo = QFileDialog::getSaveFileName(
                this,"Guardar Imagen", QString(),"Imagenes (*.png)");
    if(!nombreArchivo.isEmpty()){
        if(lienzo.save(nombreArchivo))
            QMessageBox::information(this,"Guardar Imagen", "Archivo Guardado en: ", nombreArchivo);
        else
            QMessageBox::warning(this,"Guardar Imagen", "No se pudo guardar el archivo");
    }

}

/*void Principal::on_cmdPromediar_clicked()
{
    int x=ui->inNota1->value();
    int y=ui->inNota1->value();

    //mPainter->drawRect(x+290,y+350,x,100);

}*/

void Principal::on_actionSalir_triggered()
{
    this->close();
}
