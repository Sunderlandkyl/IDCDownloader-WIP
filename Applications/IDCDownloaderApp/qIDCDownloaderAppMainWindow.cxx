/*==============================================================================

  Copyright (c) Kitware, Inc.

  See http://www.slicer.org/copyright/copyright.txt for details.

  Unless required by applicable law or agreed to in writing, software
  distributed under the License is distributed on an "AS IS" BASIS,
  WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
  See the License for the specific language governing permissions and
  limitations under the License.

  This file was originally developed by Julien Finet, Kitware, Inc.
  and was partially funded by NIH grant 3P41RR013218-12S1

==============================================================================*/

// IDCDownloader includes
#include "qIDCDownloaderAppMainWindow.h"
#include "qIDCDownloaderAppMainWindow_p.h"

// Qt includes
#include <QDesktopWidget>
#include <QLabel>

// Slicer includes
#include "qSlicerApplication.h"
#include "qSlicerAboutDialog.h"
#include "qSlicerMainWindow_p.h"
#include "qSlicerModuleSelectorToolBar.h"

// MRMLWidgets includes
#include "qMRMLWidget.h"

//-----------------------------------------------------------------------------
// qIDCDownloaderAppMainWindowPrivate methods

qIDCDownloaderAppMainWindowPrivate::qIDCDownloaderAppMainWindowPrivate(qIDCDownloaderAppMainWindow& object)
  : Superclass(object)
{
}

//-----------------------------------------------------------------------------
qIDCDownloaderAppMainWindowPrivate::~qIDCDownloaderAppMainWindowPrivate()
{
}

//-----------------------------------------------------------------------------
void qIDCDownloaderAppMainWindowPrivate::init()
{
#if (QT_VERSION >= QT_VERSION_CHECK(5, 7, 0))
  QApplication::setAttribute(Qt::AA_UseHighDpiPixmaps);
#endif
  Q_Q(qIDCDownloaderAppMainWindow);
  this->Superclass::init();
}

//-----------------------------------------------------------------------------
void qIDCDownloaderAppMainWindowPrivate::setupUi(QMainWindow * mainWindow)
{
  qSlicerApplication * app = qSlicerApplication::application();

  //----------------------------------------------------------------------------
  // Add actions
  //----------------------------------------------------------------------------
  QAction* helpAboutSlicerAppAction = new QAction(mainWindow);
  helpAboutSlicerAppAction->setObjectName("HelpAboutIDCDownloaderAppAction");
  helpAboutSlicerAppAction->setText("About " + app->applicationName());

  //----------------------------------------------------------------------------
  // Calling "setupUi()" after adding the actions above allows the call
  // to "QMetaObject::connectSlotsByName()" done in "setupUi()" to
  // successfully connect each slot with its corresponding action.
  this->Superclass::setupUi(mainWindow);

  // Add Help Menu Action
  this->HelpMenu->addAction(helpAboutSlicerAppAction);

  //----------------------------------------------------------------------------
  // Configure
  //----------------------------------------------------------------------------
  mainWindow->setWindowIcon(QIcon(":/Icons/Medium/DesktopIcon.png"));

  QLabel* logoLabel = new QLabel();
  logoLabel->setObjectName("LogoLabel");
  logoLabel->setPixmap(qMRMLWidget::pixmapFromIcon(QIcon(":/LogoFull.png")));
  this->PanelDockWidget->setTitleBarWidget(logoLabel);

  // Hide the menus
  //this->menubar->setVisible(false);
  //this->FileMenu->setVisible(false);
  //this->EditMenu->setVisible(false);
  //this->ViewMenu->setVisible(false);
  //this->LayoutMenu->setVisible(false);
  //this->HelpMenu->setVisible(false);
}

//-----------------------------------------------------------------------------
// qIDCDownloaderAppMainWindow methods

//-----------------------------------------------------------------------------
qIDCDownloaderAppMainWindow::qIDCDownloaderAppMainWindow(QWidget* windowParent)
  : Superclass(new qIDCDownloaderAppMainWindowPrivate(*this), windowParent)
{
  Q_D(qIDCDownloaderAppMainWindow);
  d->init();
}

//-----------------------------------------------------------------------------
qIDCDownloaderAppMainWindow::qIDCDownloaderAppMainWindow(
  qIDCDownloaderAppMainWindowPrivate* pimpl, QWidget* windowParent)
  : Superclass(pimpl, windowParent)
{
  // init() is called by derived class.
}

//-----------------------------------------------------------------------------
qIDCDownloaderAppMainWindow::~qIDCDownloaderAppMainWindow()
{
}

//-----------------------------------------------------------------------------
void qIDCDownloaderAppMainWindow::on_HelpAboutIDCDownloaderAppAction_triggered()
{
  qSlicerAboutDialog about(this);
  about.setLogo(QPixmap(":/Logo.png"));
  about.exec();
}
