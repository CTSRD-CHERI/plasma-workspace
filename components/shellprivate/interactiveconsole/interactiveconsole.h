/*
    SPDX-FileCopyrightText: 2009 Aaron Seigo <aseigo@kde.org>
    SPDX-FileCopyrightText: 2014 Marco Martin <mart@kde.org>

    SPDX-License-Identifier: LGPL-2.0-or-later
*/

#pragma once

#include <QDialog>
#include <QPointer>

#include <KIO/Job>

class QSplitter;

class QAction;
class QFileDialog;
class QMenu;
class KTextEdit;
class QTextBrowser;

class ShellCorona;

namespace KTextEditor
{
class Document;
} // namespace KParts

namespace Plasma
{
class Corona;
} // namespace Plasma

class InteractiveConsole : public QDialog
{
    Q_OBJECT

public:
    explicit InteractiveConsole(QWidget *parent = nullptr);
    ~InteractiveConsole() override;

    enum ConsoleMode {
        PlasmaConsole,
        KWinConsole,
    };

    void setMode(const QString &mode);
    QString mode() const;

    void setScriptInterface(QObject *obj);
    QObject *scriptEngine() const;

    void loadScript(const QString &path);

Q_SIGNALS:
    void scriptEngineChanged();
    void modeChanged();
    void visibleChanged(bool);

protected:
    void showEvent(QShowEvent *) override;
    void closeEvent(QCloseEvent *event) override;

protected Q_SLOTS:
    void print(const QString &string);
    void reject() override;

private Q_SLOTS:
    void openScriptFile();
    void saveScript();
    void scriptTextChanged();
    void evaluateScript();
    void clearEditor();
    void clearOutput();
    void scriptFileDataRecvd(KIO::Job *job, const QByteArray &data);
    void scriptFileDataReq(KIO::Job *job, QByteArray &data);
    void reenableEditor(KJob *job);
    void saveScriptUrlSelected(int result);
    void openScriptUrlSelected(int result);
    void loadScriptFromUrl(const QUrl &url);
    void populateTemplatesMenu();
    void loadTemplate(QAction *);
    void useTemplate(QAction *);
    void modeSelectionChanged();

private:
    void saveScript(const QUrl &url);

    ShellCorona *m_corona;
    QSplitter *m_splitter;
    KTextEditor::Document *m_editorPart;
    KTextEdit *m_editor;
    QTextBrowser *m_output;
    QAction *m_loadAction;
    QAction *m_saveAction;
    QAction *m_clearAction;
    QAction *m_executeAction;
    QAction *m_plasmaAction;
    QAction *m_kwinAction;
    QMenu *m_snippetsMenu;

    QFileDialog *m_fileDialog;
    QPointer<KIO::Job> m_job;
    bool m_closeWhenCompleted;
    ConsoleMode m_mode;
    QPointer<QObject> m_scriptEngine;
};

class InteractiveConsoleItem : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QObject *scriptEngine READ scriptEngine WRITE setScriptInterface NOTIFY scriptEngineChanged)
    Q_PROPERTY(QString mode READ mode WRITE setMode NOTIFY modeChanged)
    Q_PROPERTY(bool visible READ isVisible WRITE setVisible NOTIFY visibleChanged)

public:
    InteractiveConsoleItem()
        : QObject(nullptr)
        , m_dialog(new InteractiveConsole(nullptr))
    {
        connect(m_dialog, &InteractiveConsole::scriptEngineChanged, this, &InteractiveConsoleItem::scriptEngineChanged);
        connect(m_dialog, &InteractiveConsole::modeChanged, this, &InteractiveConsoleItem::modeChanged);
        connect(m_dialog, &InteractiveConsole::visibleChanged, this, &InteractiveConsoleItem::visibleChanged);
    }

    ~InteractiveConsoleItem() override
    {
        m_dialog->deleteLater();
    }

    void setMode(const QString &mode)
    {
        m_dialog->setMode(mode);
    }
    QString mode() const
    {
        return m_dialog->mode();
    }

    void setScriptInterface(QObject *obj)
    {
        m_dialog->setScriptInterface(obj);
    }
    QObject *scriptEngine() const
    {
        return m_dialog->scriptEngine();
    }

    void setVisible(bool visible) const
    {
        visible ? m_dialog->show() : m_dialog->hide();
    }
    bool isVisible() const
    {
        return m_dialog->isVisible();
    }

public Q_SLOTS:
    void loadScript(const QString &path)
    {
        m_dialog->loadScript(path);
    }

Q_SIGNALS:
    void scriptEngineChanged();
    void modeChanged();
    void visibleChanged(bool);

private:
    InteractiveConsole *m_dialog;
};
