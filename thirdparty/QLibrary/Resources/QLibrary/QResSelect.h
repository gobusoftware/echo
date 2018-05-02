#pragma once

#include <QHBoxLayout>
#include <QLineEdit>
#include <QToolButton>
#include <QWidget>
#include <QPainter>
#include <functional>
#include "engine/core/util/StringUtil.h"

namespace QT_UI
{
	//-------------------------------------------
	// AssetsSelect �ļ�ѡ��ؼ� 2013-1-22 ����
	//-------------------------------------------
	class QResSelect : public QWidget
	{
		Q_OBJECT

	public:
		using OpenFileDialogFunction = std::function < Echo::String(QWidget*, const char*, const char*, const char*) >;

	public:
		QResSelect(class QPropertyModel* model, QString propertyName, const char* exts, const char* files, QWidget* parent = 0);

		// ����·��
		void SetPath( QString text) { m_lineEdit->setText( text);  }

		// ��ȡ·��
		QString GetPath() { return m_lineEdit->text(); }

		// set open operation
		static void setOpenFileDialogFunction(const OpenFileDialogFunction& func) { m_openFileFunction = func; }

		// MVC��Ⱦ
		static void ItemDelegatePaint(QPainter *painter, const QRect& rect, const Echo::String& val);

	protected:
		// redefine paintEvent
		void paintEvent(QPaintEvent* event);

		// is texture res
		bool isTextureRes();

		// correct size
		void adjustHeightSize();

	private slots:
		// ѡ��·��
		void OnSelectPath();

		// edit finished
		void onEditFinished();

	private:
		Echo::String	m_exts;
		QString			m_files;
		QHBoxLayout*	m_horizonLayout;
		QLineEdit*		m_lineEdit;
		QToolButton*	m_toolButton;
		static OpenFileDialogFunction m_openFileFunction;
		QPropertyModel* m_propertyModel;
		QString			m_propertyName;
	};
}