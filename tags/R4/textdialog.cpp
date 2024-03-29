#include "textdialog.h"
#include "ui_textdialog.h"

TextDialog::TextDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::TextDialog)
{
    ui->setupUi(this);
    Qt::WindowFlags flags = windowFlags();
    flags |= Qt::WindowMaximizeButtonHint;
    setWindowFlags(flags);
}

TextDialog::~TextDialog()
{
    delete ui;
}

void TextDialog::setMode(bool send)
{

    if (send)
    {
        ui->buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
        ui->textBox->setReadOnly(false);
    }
    else
    {
        ui->buttonBox->setStandardButtons(QDialogButtonBox::Close);
        ui->textBox->setReadOnly(true);
    }

}

QString TextDialog::contents()
{
    return ui->textBox->toPlainText();
}

void TextDialog::setContents(QString c)
{
    ui->textBox->setPlainText(c);
}

void TextDialog::closeEvent(QCloseEvent *event)
{
    this->deleteLater();
}
