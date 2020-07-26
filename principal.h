#ifndef PRINCIPAL_H
#define PRINCIPAL_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class Principal; }
QT_END_NAMESPACE

class Principal : public QMainWindow
{
    Q_OBJECT

public:
    Principal(QWidget *parent = nullptr);
    ~Principal();

private slots:
    void on_actionGuardar_triggered();

    //void on_cmdPromediar_clicked();

    void on_actionSalir_triggered();

private:
    Ui::Principal *ui;
    QPixmap lienzo;
    QPainter *mPainter;
    QImage *mImagen;

    void dibujar();
};
#endif // PRINCIPAL_H
