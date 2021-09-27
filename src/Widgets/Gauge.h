/*
 * Copyright (c) 2020-2021 Alex Spataru <https://github.com/alex-spataru>
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 * THE SOFTWARE.
 */

#ifndef WIDGETS_GAUGE_H
#define WIDGETS_GAUGE_H

#include <QWidget>
#include <QwtDial>
#include <QwtDialNeedle>
#include <QVBoxLayout>

namespace Widgets
{
class GaugeObject : public QwtDial
{
public:
    GaugeObject(QWidget *parent = nullptr);

    QString label() const;
    void setLabel(const QString &label);

protected:
    virtual void drawScaleContents(QPainter *painter, const QPointF &center,
                                   double radius) const QWT_OVERRIDE;

private:
    QString m_label;
};

class Gauge : public QWidget
{
    Q_OBJECT

public:
    Gauge(const int index = -1);

private slots:
    void update();

private:
    void resizeEvent(QResizeEvent *event);

private:
    int m_index;
    GaugeObject m_gauge;
    QVBoxLayout m_layout;
};
}

#endif