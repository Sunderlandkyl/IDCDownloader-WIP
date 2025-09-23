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

#ifndef __qIDCDownloaderAppMainWindow_h
#define __qIDCDownloaderAppMainWindow_h

// IDCDownloader includes
#include "qIDCDownloaderAppExport.h"
class qIDCDownloaderAppMainWindowPrivate;

// Slicer includes
#include "qSlicerMainWindow.h"

class Q_IDCDOWNLOADER_APP_EXPORT qIDCDownloaderAppMainWindow : public qSlicerMainWindow
{
  Q_OBJECT
public:
  typedef qSlicerMainWindow Superclass;

  qIDCDownloaderAppMainWindow(QWidget *parent=0);
  virtual ~qIDCDownloaderAppMainWindow();

public slots:
  void on_HelpAboutIDCDownloaderAppAction_triggered();

protected:
  qIDCDownloaderAppMainWindow(qIDCDownloaderAppMainWindowPrivate* pimpl, QWidget* parent);

private:
  Q_DECLARE_PRIVATE(qIDCDownloaderAppMainWindow);
  Q_DISABLE_COPY(qIDCDownloaderAppMainWindow);
};

#endif
