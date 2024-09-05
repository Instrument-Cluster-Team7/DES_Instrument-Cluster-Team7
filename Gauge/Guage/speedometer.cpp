#include "speedometer.h"

#include <QPainter>

speedometer::speedometer(QQuickItem *parent)
    :QQuickPaintedItem(parent),
      m_SpeedometerSize(400), // touch screen is 800 x 480
      m_StartAngle(50),
      m_AlignAngle(260), // it should be 360 - m_StartAngle*3 for good looking
      m_LowestRange(0),
      m_HighestRange(4000),
      m_Speed(2430), // 1230
      m_ArcWidth(10),
      m_OuterColor(QColor(12,16,247)),
      m_InnerColor(QColor(51,88,255,80)),
      m_TextColor(QColor(255,255,255)),
      m_BackgroundColor(Qt::transparent)
{

}

void speedometer::paint(QPainter *painter){
    QRectF rect = this->boundingRect();
    painter->setRenderHint(QPainter::Antialiasing);
    QPen pen = painter->pen();
    pen.setCapStyle(Qt::FlatCap);

    double startAngle;
    double spanAngle;

    startAngle = m_StartAngle - 40;
    spanAngle = 0 - m_AlignAngle;

    // outer pie
    painter->save();
    pen.setWidth(m_ArcWidth);
    pen.setColor(m_InnerColor);
    painter->setPen(pen);
//    painter->drawRect(rect);
    painter->drawArc(rect.adjusted(m_ArcWidth, m_ArcWidth, -m_ArcWidth, -m_ArcWidth), startAngle * 16, spanAngle * 16);
    painter->restore();

    // inner pie
    int pieSize = m_SpeedometerSize/5;
    painter->save();
    pen.setColor(m_OuterColor);
    painter->setBrush(m_InnerColor);
    painter->drawPie(rect.adjusted(pieSize, pieSize, -pieSize, -pieSize), startAngle * 16, spanAngle * 16);
    painter->restore();

    // text that shows the value
    painter->save();
    QFont font("Halvetica", 52, QFont::Bold);
    painter->setFont(font);
    pen.setColor(m_TextColor);
    painter->setPen(pen);
    painter->drawText(rect.adjusted(m_SpeedometerSize/30, m_SpeedometerSize/30, -m_SpeedometerSize/30, -m_SpeedometerSize/5),
                      Qt::AlignCenter, QString::number((m_Speed/40), 'f', 1));
    painter->restore();

    // current progress
    painter->save();
    pen.setWidth(m_ArcWidth);
    pen.setColor(m_OuterColor);
    qreal valueToAngle = ((m_Speed - m_LowestRange)/(m_HighestRange - m_LowestRange)) * spanAngle;
    painter->setPen(pen);
    painter->drawArc(rect.adjusted(m_ArcWidth, m_ArcWidth, -m_ArcWidth, -m_ArcWidth), startAngle * 16, valueToAngle * 16);
    painter->restore();
}

qreal speedometer::getspeedometerSize()
{
    return m_SpeedometerSize;
}

qreal speedometer::getStartAngle()
{
    return m_StartAngle;
}


qreal speedometer::getAlignAngle()
{
    return m_AlignAngle;
}


qreal speedometer::getLowestRange()
{
    return m_LowestRange;
}

qreal speedometer::getHighestRange()
{
    return m_HighestRange;
}

qreal speedometer::getSpeed()
{
    return m_Speed;
}

int speedometer::getArcWidth()
{
    return m_ArcWidth;
}

QColor speedometer::getOuterColor()
{
    return m_OuterColor;
}

QColor speedometer::getInnerColor()
{
    return m_InnerColor;
}

QColor speedometer::getTextColor()
{
    return m_TextColor;
}

QColor speedometer::getBackgroundColor()
{
    return m_BackgroundColor;
}



void speedometer::setSpeedometerSize(qreal size)
{
    if(m_SpeedometerSize == size)
        return;
    m_SpeedometerSize = size;

    emit speedometerSizeChanged();
}

void speedometer::setStartAngle(qreal startAngle)
{
    if(m_StartAngle == startAngle)
        return;

    m_StartAngle = startAngle;

    emit startAngleChanged();
}

void speedometer::setAlignAngle(qreal angle)
{
    if(m_StartAngle == angle)
        return;

    m_StartAngle = angle;

    emit alignAngleChanged();
}

void speedometer::setLowestRange(qreal lowestRange)
{
    if(m_LowestRange == lowestRange)
        return;

    m_LowestRange = lowestRange;

    emit lowestRangeChanged();
}

void speedometer::setHighestRange(qreal highestRange)
{
    if(m_HighestRange == highestRange)
        return;

    m_HighestRange = highestRange;

    emit highestRangeChanged();
}

void speedometer::setSpeed(qreal speed)
{
    if(m_Speed == speed)
        return;

    m_Speed = speed;
    update();
    emit speedChanged();
}

void speedometer::setArcWidth(int arcWidth)
{
    if(m_ArcWidth == arcWidth)
        return;

    m_ArcWidth = arcWidth;

    emit arcWidthChanged();
}

void speedometer::setOuterColor(QColor outerColor)
{
    if(m_OuterColor == outerColor)
        return;

    m_OuterColor = outerColor;

    emit outerColorChanged();
}

void speedometer::setInnerColor(QColor innerColor)
{
    if(m_InnerColor == innerColor)
        return;

    m_InnerColor = innerColor;

    emit innerColorChanged();
}

void speedometer::setTextColor(QColor textColor)
{
    if(m_TextColor == textColor)
        return;

    m_TextColor = textColor;

    emit textColorChanged();
}

void speedometer::setBackgroundColor(QColor backgroundColor)
{
    if(m_BackgroundColor == backgroundColor)
        return;

    m_BackgroundColor = backgroundColor;

    emit backgroundColorChanged();
}
