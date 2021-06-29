/* Colorset Preview widget for KDE Display color scheme setup module
    SPDX-FileCopyrightText: 2008 Matthew Woehlke <mw_triad@users.sourceforge.net>

    SPDX-License-Identifier: GPL-2.0-or-later

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program; see the file COPYING.  If not, write to
    the Free Software Foundation, Inc., 51 Franklin Street, Fifth Floor,
    Boston, MA 02110-1301, USA.
*/

#pragma once

#include <QFrame>
#include <QPalette>

#include <KColorScheme>
#include <KSharedConfig>

#include "ui_setpreview.h"

/**
 * The Desktop/Colors tab in kcontrol.
 */
class SetPreviewWidget : public QFrame, Ui::setpreview
{
    Q_OBJECT

public:
    explicit SetPreviewWidget(QWidget *parent);
    ~SetPreviewWidget() override;

    void setPalette(const KSharedConfigPtr &config, KColorScheme::ColorSet);

protected:
    void setPaletteRecursive(QWidget *, const QPalette &);
    bool eventFilter(QObject *, QEvent *) override;
};
