#include "include/perlingenerator.h"

PerlinGenerator::PerlinGenerator()
{
    focused = false;
    setFlag(ItemIsSelectable,true);
    setFlag(ItemIsFocusable,true);
}

QRectF PerlinGenerator::boundingRect() const
{
    return QRectF(0,0,100,200);
}

void PerlinGenerator::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    if(focused){
        painter->setPen(Qt::green);
        painter->drawRect(0,0,100,200);
        QBrush brush(QColor(255,0,0,100));
        painter->fillRect(QRect(0,0,100,200),brush);
    }
    else
    {
        QRectF rec1(0,0,100,50);
        QImage image(":/image/resource/image/item/perlin.jpg");
        painter->drawImage(rec1,image);

        QRectF rec2(0,50,100,150);
        QBrush brush(QColor(30,40,50,50));
        painter->fillRect(rec2,brush);

        painter->setPen(Qt::green);
        painter->drawEllipse(2,68,5,5);

        painter->drawText(10,70,"hello");
    }
}

void PerlinGenerator::mouseDoubleClickEvent(QGraphicsSceneMouseEvent *event)
{
    QGraphicsItem::mouseDoubleClickEvent(event);
    PerlinWidget *perlin = new PerlinWidget;
    perlin->show();
}

void PerlinGenerator::focusInEvent(QFocusEvent *event)
{
    focused = true;
    update();
    QGraphicsItem::focusInEvent(event);
}

void PerlinGenerator::focusOutEvent(QFocusEvent *event)
{
    focused = false;
    update();
    QGraphicsItem::focusOutEvent(event);
}

