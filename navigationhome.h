#ifndef NAVIGATIONHOME_H
#define NAVIGATIONHOME_H

#include <QWidget>

namespace Ui {
class NavigationHome;
}

class NavigationHome : public QWidget
{
    Q_OBJECT

public:
    explicit NavigationHome(QWidget *parent = 0);
    ~NavigationHome();

    bool IsDownloadChecked();
    bool IsUploadChecked();
    bool IsUploadDiscDriveChecked();
    bool isUploadFolderChecked();


private:
    Ui::NavigationHome *ui;
};

#endif // NAVIGATIONHOME_H
