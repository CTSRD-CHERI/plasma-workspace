/*
    SPDX-FileCopyrightText: 2007 Barış Metin <baris@pardus.org.tr>
    SPDX-FileCopyrightText: 2010 Matteo Agostinelli <agostinelli@gmail.com>
    SPDX-FileCopyrightText: 2021 Alexander Lohnau <alexander.lohnau@gmx.de>

    SPDX-License-Identifier: LGPL-2.0-only
*/

#pragma once

#include <QAction>
#include <QMimeData>

class QalculateEngine;

#include <krunner/abstractrunner.h>

/**
 * This class evaluates the basic expressions given in the interface.
 */
class CalculatorRunner : public AbstractRunner
{
    Q_OBJECT

public:
    CalculatorRunner(QObject *parent, const KPluginMetaData &metaData, const QVariantList &args);
    ~CalculatorRunner() override;

    void match(RunnerContext &context) override;

protected Q_SLOTS:
    void run(const RunnerContext &context, const QueryMatch &match) override;
    QMimeData *mimeDataForMatch(const QueryMatch &match) override;

private:
    QString calculate(const QString &term, bool *isApproximate);
    void userFriendlyMultiplication(QString &cmd);
    void userFriendlySubstitutions(QString &cmd);

    QalculateEngine *m_engine;
    QList<QAction *> m_actions;
};
