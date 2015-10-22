#include "window.h"

#include <ompl/base/spaces/RealVectorStateSpace.h>

#include <QtWidgets>
#include <QPainter>
#include <QPen>

Window::Window(QWidget *parent)
    : QWidget(parent)
{
    setBackgroundRole(QPalette::Base);
    setAutoFillBackground(true);

    QTimer *timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(update()));
    timer->start(50);
    update();
}

QSize Window::minimumSizeHint() const
{
    return QSize(200, 200);
}

QSize Window::sizeHint() const
{
    return QSize(1000, 1000);
}

Window::~Window()
{
    
}

void Window::paintEvent(QPaintEvent * /* event */){
    QPen blackpen(Qt::black, 1);
    QPen redpen(Qt::red, 1);
    QPen greenpen(Qt::green, 1);
    QBrush redbrush(Qt::red);
    QBrush greenbrush(Qt::green);

    QPainter painter(this);
    painter.setPen(blackpen);
    painter.setRenderHint(QPainter::Antialiasing, true);
//    painter.translate(this->width()/2,this->height()/2);
//    painter.scale(100,1);

    QPainterPath path;
//    path.moveTo(20, 80);
//    path.lineTo(20, 30);
//    path.cubicTo(80, 0, 50, 50, 80, 80);
    ompl::base::PlannerData data(planner->getSpaceInformation());
    planner->getPlannerData(data);

    for (unsigned int i=0;i<data.numVertices();i++){
        auto s = data.getVertex(i).getState()->as<ompl::base::RealVectorStateSpace::StateType>();
        if (data.getVertex(i).getTag()==1){
            painter.setBrush(greenbrush);
            painter.setPen(greenpen);
        }
        else if (data.getVertex(i).getTag()==2){
            painter.setBrush(redbrush);
            painter.setPen(redpen);
        }
        else{
            painter.setBrush(Qt::NoBrush);
            painter.setPen(blackpen);
        }

        painter.setPen(blackpen);
        painter.drawEllipse(QPointF(s->values[0]*this->width(),s->values[1]*this->height()),4,4);
//        std::cout << s->values[0] << ", " << s->values[1] << "\n";

        std::vector<unsigned int> edgeList;
        data.getEdges(i,edgeList);
        painter.setBrush(Qt::NoBrush);
        painter.setPen(blackpen);
        for (unsigned int j=0; j<edgeList.size(); j++){
            auto s2 = data.getVertex(edgeList[j]).getState()->as<ompl::base::RealVectorStateSpace::StateType>();
            path.moveTo(QPointF(s->values[0]*this->width(),s->values[1]*this->height()));
            path.lineTo(QPointF(s2->values[0]*this->width(),s2->values[1]*this->height()));
        }
    }



    painter.drawPath(path);

//    painter.setBrush(brush);
//    painter.setPen(redpen);
//    painter.drawEllipse(QPointF(20,30),10,10);

//    path.moveTo(40, 80);
//    path.lineTo(40, 30);
//    path.cubicTo(80, 0, 50, 50, 80, 80);
//    painter.setPen(blackpen);
//    painter.setBrush(Qt::NoBrush);

//    painter.setRenderHint(QPainter::Antialiasing, false);
//    painter.setPen(palette().dark().color());
//    painter.setBrush(Qt::NoBrush);
//    painter.drawRect(QRect(0, 0, width() - 1, height() - 1));

}
